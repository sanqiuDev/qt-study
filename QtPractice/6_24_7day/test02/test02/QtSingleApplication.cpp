#include "QtSingleApplication.h"

namespace SharedTools {

QtSingleApplication::QtSingleApplication(int& argc, char** argv, bool GUIenabled)
    : QApplication(argc, argv, GUIenabled)
    , m_sharedMemory(nullptr)
    , m_localServer(nullptr)
    , m_running(false)
{
    init(QCoreApplication::applicationName());
}

QtSingleApplication::QtSingleApplication(const QString& id, int& argc, char** argv, bool GUIenabled)
    : QApplication(argc, argv, GUIenabled)
    , m_sharedMemory(nullptr)
    , m_localServer(nullptr)
    , m_running(false)
{
    init(id);
}

QtSingleApplication::~QtSingleApplication()
{
    delete m_sharedMemory;
    delete m_localServer;
}

bool QtSingleApplication::init(const QString& id)
{
    m_id = id;

    m_sharedMemory = new QSharedMemory(m_id);

    if (m_sharedMemory->attach()) {
        m_running = true;
        return true;
    }

    if (!m_sharedMemory->create(1)) {
        qWarning() << "Failed to create shared memory:" << m_sharedMemory->errorString();
        return false;
    }

    m_running = false;
    setupLocalServer();
    return true;
}

void QtSingleApplication::setupLocalServer()
{
    m_localServer = new QLocalServer(this);
    connect(m_localServer, &QLocalServer::newConnection,
            this, &QtSingleApplication::onNewConnection);

    QString serverName = m_id + "_server";
    if (!m_localServer->listen(serverName)) {
        QLocalServer::removeServer(serverName);
        if (!m_localServer->listen(serverName)) {
            qWarning() << "Failed to start local server:" << m_localServer->errorString();
        }
    }
}

void QtSingleApplication::onNewConnection()
{
    QLocalSocket* socket = m_localServer->nextPendingConnection();
    if (socket) {
        connect(socket, &QLocalSocket::readyRead,
                this, &QtSingleApplication::onDataReady);
    }
}

void QtSingleApplication::onDataReady()
{
    QLocalSocket* socket = qobject_cast<QLocalSocket*>(sender());
    if (!socket) return;

    QString message = QString::fromUtf8(socket->readAll());
    emit messageReceived(message);

    socket->deleteLater();
}

bool QtSingleApplication::sendMessage(const QString& message, int timeout)
{
    if (!m_running) {
        qWarning() << "This is the first instance, cannot send message to self";
        return false;
    }

    QString serverName = m_id + "_server";
    QLocalSocket socket;
    socket.connectToServer(serverName);

    if (!socket.waitForConnected(timeout)) {
        qWarning() << "Failed to connect to server:" << socket.errorString();
        return false;
    }

    socket.write(message.toUtf8());
    if (!socket.waitForBytesWritten(timeout)) {
        qWarning() << "Failed to write message:" << socket.errorString();
        return false;
    }

    socket.disconnectFromServer();
    return true;
}

} // namespace SharedTools
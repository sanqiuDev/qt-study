#ifndef QTSINGLEAPPLICATION_H
#define QTSINGLEAPPLICATION_H

#include <QApplication>
#include <QLocalServer>
#include <QLocalSocket>
#include <QSharedMemory>
#include <QDebug>

namespace SharedTools {

class QtSingleApplication : public QApplication
{
    Q_OBJECT

public:
    QtSingleApplication(int& argc, char** argv, bool GUIenabled = true);
    QtSingleApplication(const QString& id, int& argc, char** argv, bool GUIenabled = true);
    ~QtSingleApplication();

    bool isRunning() const { return m_running; }
    bool sendMessage(const QString& message, int timeout = 5000);

signals:
    void messageReceived(const QString& message);

private slots:
    void onNewConnection();
    void onDataReady();

private:
    bool init(const QString& id);
    void setupLocalServer();

    QString m_id;
    QSharedMemory* m_sharedMemory;
    QLocalServer* m_localServer;
    bool m_running;
};

} // namespace SharedTools

#endif // QTSINGLEAPPLICATION_H
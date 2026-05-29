#include "widget.h"
#include "ui_widget.h"
#include <QGridLayout>
#include <QRandomGenerator>
#include <QSettings>
#include <QMessageBox>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
    , m_score(0)
    , m_combo(0)
    , m_timeRemaining(0)
    , m_highestScore(0)
    , m_gameRunning(false)
{
    ui->setupUi(this);

    // 初始化定时器
    m_gameTimer = new QTimer(this);
    m_spawnTimer = new QTimer(this);
    connect(m_gameTimer, &QTimer::timeout, this, &Widget::onGameTick);
    connect(m_spawnTimer, &QTimer::timeout, this, &Widget::onSpawnTimer);

    // 创建 3x3 地鼠网格
    setupHoleGrid();

    // 加载最高分
    loadHighestScore();

    // 全局字体
    setStyleSheet("QWidget { font-family: 'Microsoft YaHei'; }");

    // 开始按钮样式
    ui->startStopBtn->setStyleSheet(
        "QPushButton {"
        "  background-color: #4CAF50;"
        "  color: white;"
        "  border-radius: 8px;"
        "}"
        "QPushButton:hover {"
        "  background-color: #45a049;"
        "}"
        "QPushButton:pressed {"
        "  background-color: #3d8b40;"
        "}"
    );

    // 重置最高分按钮样式
    ui->resetHighScoreBtn->setStyleSheet(
        "QPushButton {"
        "  background-color: #f44336;"
        "  color: white;"
        "  border-radius: 5px;"
        "  padding: 5px;"
        "}"
        "QPushButton:hover {"
        "  background-color: #da190b;"
        "}"
    );

    // 游戏区域样式
    ui->groupBox_game->setStyleSheet(
        "QGroupBox {"
        "  font-size: 16px;"
        "  font-weight: bold;"
        "  border: 2px solid #cccccc;"
        "  border-radius: 8px;"
        "  margin-top: 10px;"
        "  padding-top: 20px;"
        "}"
        "QGroupBox::title {"
        "  subcontrol-origin: margin;"
        "  left: 10px;"
        "  padding: 0 5px;"
        "}"
    );

    // 设置区域样式
    ui->groupBox_settings->setStyleSheet(
        "QGroupBox {"
        "  font-size: 14px;"
        "  font-weight: bold;"
        "  border: 2px solid #cccccc;"
        "  border-radius: 8px;"
        "  margin-top: 10px;"
        "  padding-top: 20px;"
        "}"
        "QGroupBox::title {"
        "  subcontrol-origin: margin;"
        "  left: 10px;"
        "  padding: 0 5px;"
        "}"
    );

    // 进度条样式
    ui->timeProgress->setStyleSheet(
        "QProgressBar {"
        "  border: 1px solid #cccccc;"
        "  border-radius: 5px;"
        "  text-align: center;"
        "  height: 25px;"
        "}"
        "QProgressBar::chunk {"
        "  background-color: #4CAF50;"
        "  border-radius: 5px;"
        "}"
    );
}

Widget::~Widget()
{
    delete ui;
}

void Widget::setupHoleGrid()
{
    QGridLayout *grid = new QGridLayout(ui->holeContainer);
    grid->setSpacing(10);
    grid->setContentsMargins(0, 0, 0, 0);

    for (int i = 0; i < 9; ++i) {
        QPushButton *btn = new QPushButton(this);
        btn->setMinimumSize(80, 80);
        btn->setMaximumSize(80, 80);
        btn->setCursor(Qt::PointingHandCursor);

        connect(btn, &QPushButton::clicked, this, [this, i]() {
            onHoleClicked(i);
        });

        grid->addWidget(btn, i / 3, i % 3, Qt::AlignCenter);
        m_holes.append(btn);
        m_moleStates.append(false);

        hideMole(i);
    }
}

void Widget::on_startStopBtn_clicked()
{
    if (m_gameRunning) {
        stopGame();
    } else {
        startGame();
    }
}

void Widget::on_resetHighScoreBtn_clicked()
{
    QMessageBox::StandardButton reply = QMessageBox::question(
        this, "确认重置", "确定要重置最高分记录吗？",
        QMessageBox::Yes | QMessageBox::No
    );

    if (reply == QMessageBox::Yes) {
        m_highestScore = 0;
        saveHighestScore();
        updateHighestScoreDisplay();
        ui->statusLabel->setText("💡 最高分已重置");
    }
}

void Widget::startGame()
{
    m_score = 0;
    m_combo = 0;
    m_timeRemaining = ui->durationSpinBox->value();
    m_gameRunning = true;

    for (int i = 0; i < 9; ++i) {
        hideMole(i);
    }

    m_gameTimer->start(1000);
    m_spawnTimer->start(getSpawnInterval());

    ui->scoreLCD->display(0);
    ui->timeProgress->setMaximum(ui->durationSpinBox->value());
    ui->timeProgress->setValue(m_timeRemaining);
    ui->startStopBtn->setText("■ 停止");
    ui->statusLabel->setText("游戏进行中... 点击地鼠得分!");

    setControlsEnabled(false);
}

void Widget::stopGame()
{
    m_gameRunning = false;
    m_gameTimer->stop();
    m_spawnTimer->stop();

    for (int i = 0; i < 9; ++i) {
        hideMole(i);
    }

    if (m_score > m_highestScore) {
        m_highestScore = m_score;
        saveHighestScore();
        updateHighestScoreDisplay();
        ui->statusLabel->setText("🎉 新纪录! 得分: " + QString::number(m_score));
    } else if (m_timeRemaining <= 0) {
        ui->statusLabel->setText("⏰ 时间到! 最终得分: " + QString::number(m_score));
    } else {
        ui->statusLabel->setText("💡 游戏已停止, 得分: " + QString::number(m_score));
    }

    ui->startStopBtn->setText("▶ 开始游戏");
    setControlsEnabled(true);
}

void Widget::onGameTick()
{
    m_timeRemaining--;
    if (m_timeRemaining <= 0) {
        m_timeRemaining = 0;
        ui->timeProgress->setValue(0);
        stopGame();
        return;
    }

    ui->timeProgress->setValue(m_timeRemaining);
}

void Widget::onSpawnTimer()
{
    spawnMole();
}

void Widget::onHoleClicked(int index)
{
    if (!m_gameRunning) return;
    if (index < 0 || index >= m_holes.size()) return;

    if (m_moleStates[index]) {
        int addScore = 1;
        if (ui->comboMode->isChecked()) {
            m_combo++;
            addScore = m_combo;
        }
        m_score += addScore;

        m_holes[index]->setStyleSheet(
            "QPushButton {"
            "  background-color: #FFD700;"
            "  border-radius: 40px;"
            "  border: 3px solid #DAA520;"
            "  font-size: 24px;"
            "  font-weight: bold;"
            "  color: black;"
            "}"
        );
        m_holes[index]->setText(QString::number(addScore));
        m_moleStates[index] = false;

        QTimer::singleShot(200, this, [this, index]() {
            hideMole(index);
        });
    } else {
        if (ui->comboMode->isChecked()) {
            m_combo = 0;
        }
        if (ui->punishmentCheckBox->isChecked()) {
            m_score = qMax(0, m_score - 1);
        }
    }

    ui->scoreLCD->display(m_score);
}

void Widget::spawnMole()
{
    if (!m_gameRunning) return;

    int activeCount = 0;
    for (bool state : m_moleStates) {
        if (state) activeCount++;
    }

    if (activeCount >= getMaxMoles()) return;

    QVector<int> available;
    for (int i = 0; i < 9; ++i) {
        if (!m_moleStates[i]) available.append(i);
    }

    if (available.isEmpty()) return;

    int holeIndex = available[QRandomGenerator::global()->bounded(available.size())];
    showMole(holeIndex);

    QTimer::singleShot(getHideDelay(), this, [this, holeIndex]() {
        if (m_gameRunning && holeIndex < m_holes.size() && m_moleStates[holeIndex]) {
            hideMole(holeIndex);
        }
    });
}

void Widget::showMole(int index)
{
    m_holes[index]->setStyleSheet(
        "QPushButton {"
        "  background-color: #8B4513;"
        "  border-radius: 40px;"
        "  border: 3px solid #6B3513;"
        "  color: white;"
        "  font-size: 28px;"
        "  font-weight: bold;"
        "}"
        "QPushButton:hover {"
        "  background-color: #A0522D;"
        "}"
    );
    m_holes[index]->setText("M");
    m_moleStates[index] = true;
}

void Widget::hideMole(int index)
{
    m_holes[index]->setStyleSheet(
        "QPushButton {"
        "  background-color: #4a7c3f;"
        "  border-radius: 40px;"
        "  border: 3px solid #3a6c2f;"
        "  font-size: 28px;"
        "}"
        "QPushButton:hover {"
        "  background-color: #5a8c4f;"
        "}"
    );
    m_holes[index]->setText("");
    m_moleStates[index] = false;
}

int Widget::getHideDelay()
{
    int speed = ui->speedSlider->value();
    return 1500 - (speed - 1) * 120;
}

int Widget::getSpawnInterval()
{
    switch (ui->difficultyCombo->currentIndex()) {
        case 0:  return 2000;
        case 1:  return 1500;
        case 2:  return 1000;
        default: return 1500;
    }
}

int Widget::getMaxMoles()
{
    return ui->difficultyCombo->currentIndex() + 1;
}

void Widget::setControlsEnabled(bool enabled)
{
    ui->difficultyCombo->setEnabled(enabled);
    ui->durationSpinBox->setEnabled(enabled);
    ui->speedSlider->setEnabled(enabled);
    ui->normalMode->setEnabled(enabled);
    ui->comboMode->setEnabled(enabled);
    ui->punishmentCheckBox->setEnabled(enabled);
}

void Widget::updateHighestScoreDisplay()
{
    ui->highestScoreLabel->setText("🏆 最高分: " + QString::number(m_highestScore));
}

void Widget::loadHighestScore()
{
    QSettings settings("QtMoleGame", "MoleGame");
    m_highestScore = settings.value("highestScore", 0).toInt();
    updateHighestScoreDisplay();
}

void Widget::saveHighestScore()
{
    QSettings settings("QtMoleGame", "MoleGame");
    settings.setValue("highestScore", m_highestScore);
}

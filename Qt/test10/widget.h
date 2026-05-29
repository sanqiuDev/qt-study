#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QVector>
#include <QTimer>
#include <QPushButton>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_startStopBtn_clicked();
    void on_resetHighScoreBtn_clicked();
    void onHoleClicked(int index);
    void onGameTick();
    void onSpawnTimer();

private:
    Ui::Widget *ui;

    // 控件数组
    QVector<QPushButton*> m_holes;
    QVector<bool> m_moleStates;

    // 定时器
    QTimer *m_gameTimer;
    QTimer *m_spawnTimer;

    // 游戏状态
    int m_score;
    int m_combo;
    int m_timeRemaining;
    int m_highestScore;
    bool m_gameRunning;

    void setupHoleGrid();
    void startGame();
    void stopGame();
    void showMole(int index);
    void hideMole(int index);
    void spawnMole();
    int getHideDelay();
    int getSpawnInterval();
    int getMaxMoles();
    void setControlsEnabled(bool enabled);
    void updateHighestScoreDisplay();
    void loadHighestScore();
    void saveHighestScore();
};

#endif // WIDGET_H

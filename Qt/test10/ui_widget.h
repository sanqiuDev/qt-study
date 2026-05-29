/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QHBoxLayout *horizontalLayout_main;
    QGroupBox *groupBox_game;
    QVBoxLayout *verticalLayout_game;
    QWidget *holeContainer;
    QSpacerItem *verticalSpacer;
    QLabel *statusLabel;
    QFrame *separator;
    QVBoxLayout *verticalLayout_right;
    QProgressBar *timeProgress;
    QLabel *label_score;
    QLCDNumber *scoreLCD;
    QLabel *highestScoreLabel;
    QPushButton *resetHighScoreBtn;
    QGroupBox *groupBox_settings;
    QVBoxLayout *verticalLayout_settings;
    QHBoxLayout *layout_difficulty;
    QLabel *label_difficulty;
    QComboBox *difficultyCombo;
    QHBoxLayout *layout_duration;
    QLabel *label_duration;
    QSpinBox *durationSpinBox;
    QHBoxLayout *layout_speed;
    QLabel *label_speed;
    QSlider *speedSlider;
    QHBoxLayout *layout_mode;
    QRadioButton *normalMode;
    QRadioButton *comboMode;
    QCheckBox *punishmentCheckBox;
    QSpacerItem *verticalSpacer_2;
    QPushButton *startStopBtn;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(800, 550);
        Widget->setMinimumSize(QSize(800, 550));
        horizontalLayout_main = new QHBoxLayout(Widget);
        horizontalLayout_main->setObjectName(QString::fromUtf8("horizontalLayout_main"));
        groupBox_game = new QGroupBox(Widget);
        groupBox_game->setObjectName(QString::fromUtf8("groupBox_game"));
        verticalLayout_game = new QVBoxLayout(groupBox_game);
        verticalLayout_game->setObjectName(QString::fromUtf8("verticalLayout_game"));
        holeContainer = new QWidget(groupBox_game);
        holeContainer->setObjectName(QString::fromUtf8("holeContainer"));
        holeContainer->setMinimumSize(QSize(280, 280));
        holeContainer->setMaximumSize(QSize(280, 280));

        verticalLayout_game->addWidget(holeContainer);

        verticalSpacer = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_game->addItem(verticalSpacer);

        statusLabel = new QLabel(groupBox_game);
        statusLabel->setObjectName(QString::fromUtf8("statusLabel"));
        statusLabel->setMinimumSize(QSize(0, 30));
        QFont font;
        font.setPointSize(11);
        statusLabel->setFont(font);
        statusLabel->setAlignment(Qt::AlignCenter);

        verticalLayout_game->addWidget(statusLabel);


        horizontalLayout_main->addWidget(groupBox_game);

        separator = new QFrame(Widget);
        separator->setObjectName(QString::fromUtf8("separator"));
        separator->setFrameShape(QFrame::VLine);
        separator->setFrameShadow(QFrame::Sunken);

        horizontalLayout_main->addWidget(separator);

        verticalLayout_right = new QVBoxLayout();
        verticalLayout_right->setObjectName(QString::fromUtf8("verticalLayout_right"));
        timeProgress = new QProgressBar(Widget);
        timeProgress->setObjectName(QString::fromUtf8("timeProgress"));
        timeProgress->setValue(100);

        verticalLayout_right->addWidget(timeProgress);

        label_score = new QLabel(Widget);
        label_score->setObjectName(QString::fromUtf8("label_score"));
        QFont font1;
        font1.setPointSize(12);
        label_score->setFont(font1);
        label_score->setAlignment(Qt::AlignCenter);

        verticalLayout_right->addWidget(label_score);

        scoreLCD = new QLCDNumber(Widget);
        scoreLCD->setObjectName(QString::fromUtf8("scoreLCD"));
        scoreLCD->setMinimumSize(QSize(0, 60));
        scoreLCD->setDigitCount(4);
        scoreLCD->setMode(QLCDNumber::Dec);

        verticalLayout_right->addWidget(scoreLCD);

        highestScoreLabel = new QLabel(Widget);
        highestScoreLabel->setObjectName(QString::fromUtf8("highestScoreLabel"));
        highestScoreLabel->setFont(font1);
        highestScoreLabel->setAlignment(Qt::AlignCenter);

        verticalLayout_right->addWidget(highestScoreLabel);

        resetHighScoreBtn = new QPushButton(Widget);
        resetHighScoreBtn->setObjectName(QString::fromUtf8("resetHighScoreBtn"));

        verticalLayout_right->addWidget(resetHighScoreBtn);

        groupBox_settings = new QGroupBox(Widget);
        groupBox_settings->setObjectName(QString::fromUtf8("groupBox_settings"));
        verticalLayout_settings = new QVBoxLayout(groupBox_settings);
        verticalLayout_settings->setObjectName(QString::fromUtf8("verticalLayout_settings"));
        layout_difficulty = new QHBoxLayout();
        layout_difficulty->setObjectName(QString::fromUtf8("layout_difficulty"));
        label_difficulty = new QLabel(groupBox_settings);
        label_difficulty->setObjectName(QString::fromUtf8("label_difficulty"));

        layout_difficulty->addWidget(label_difficulty);

        difficultyCombo = new QComboBox(groupBox_settings);
        difficultyCombo->addItem(QString());
        difficultyCombo->addItem(QString());
        difficultyCombo->addItem(QString());
        difficultyCombo->setObjectName(QString::fromUtf8("difficultyCombo"));

        layout_difficulty->addWidget(difficultyCombo);


        verticalLayout_settings->addLayout(layout_difficulty);

        layout_duration = new QHBoxLayout();
        layout_duration->setObjectName(QString::fromUtf8("layout_duration"));
        label_duration = new QLabel(groupBox_settings);
        label_duration->setObjectName(QString::fromUtf8("label_duration"));

        layout_duration->addWidget(label_duration);

        durationSpinBox = new QSpinBox(groupBox_settings);
        durationSpinBox->setObjectName(QString::fromUtf8("durationSpinBox"));
        durationSpinBox->setMinimum(10);
        durationSpinBox->setMaximum(120);
        durationSpinBox->setValue(60);

        layout_duration->addWidget(durationSpinBox);


        verticalLayout_settings->addLayout(layout_duration);

        layout_speed = new QHBoxLayout();
        layout_speed->setObjectName(QString::fromUtf8("layout_speed"));
        label_speed = new QLabel(groupBox_settings);
        label_speed->setObjectName(QString::fromUtf8("label_speed"));

        layout_speed->addWidget(label_speed);

        speedSlider = new QSlider(groupBox_settings);
        speedSlider->setObjectName(QString::fromUtf8("speedSlider"));
        speedSlider->setMinimum(1);
        speedSlider->setMaximum(10);
        speedSlider->setValue(5);
        speedSlider->setOrientation(Qt::Horizontal);
        speedSlider->setTickPosition(QSlider::TicksBelow);

        layout_speed->addWidget(speedSlider);


        verticalLayout_settings->addLayout(layout_speed);

        layout_mode = new QHBoxLayout();
        layout_mode->setObjectName(QString::fromUtf8("layout_mode"));
        normalMode = new QRadioButton(groupBox_settings);
        normalMode->setObjectName(QString::fromUtf8("normalMode"));
        normalMode->setChecked(true);

        layout_mode->addWidget(normalMode);

        comboMode = new QRadioButton(groupBox_settings);
        comboMode->setObjectName(QString::fromUtf8("comboMode"));

        layout_mode->addWidget(comboMode);


        verticalLayout_settings->addLayout(layout_mode);

        punishmentCheckBox = new QCheckBox(groupBox_settings);
        punishmentCheckBox->setObjectName(QString::fromUtf8("punishmentCheckBox"));

        verticalLayout_settings->addWidget(punishmentCheckBox);


        verticalLayout_right->addWidget(groupBox_settings);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_right->addItem(verticalSpacer_2);

        startStopBtn = new QPushButton(Widget);
        startStopBtn->setObjectName(QString::fromUtf8("startStopBtn"));
        startStopBtn->setMinimumSize(QSize(0, 45));
        QFont font2;
        font2.setPointSize(14);
        font2.setBold(true);
        font2.setWeight(75);
        startStopBtn->setFont(font2);

        verticalLayout_right->addWidget(startStopBtn);


        horizontalLayout_main->addLayout(verticalLayout_right);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "\360\237\216\257 \346\211\223\345\234\260\351\274\240\345\244\247\344\275\234\346\210\230", nullptr));
        groupBox_game->setTitle(QCoreApplication::translate("Widget", "\360\237\216\257 \346\211\223\345\234\260\351\274\240", nullptr));
        statusLabel->setText(QCoreApplication::translate("Widget", "\360\237\222\241 \347\202\271\345\207\273 [\345\274\200\345\247\213\346\270\270\346\210\217] \345\274\200\345\247\213!", nullptr));
        timeProgress->setFormat(QCoreApplication::translate("Widget", "\345\211\251\344\275\231 %v \347\247\222", nullptr));
        label_score->setText(QCoreApplication::translate("Widget", "\342\255\220 \345\276\227\345\210\206", nullptr));
        highestScoreLabel->setText(QCoreApplication::translate("Widget", "\360\237\217\206 \346\234\200\351\253\230\345\210\206: 0", nullptr));
        resetHighScoreBtn->setText(QCoreApplication::translate("Widget", "\351\207\215\347\275\256\346\234\200\351\253\230\345\210\206", nullptr));
        groupBox_settings->setTitle(QCoreApplication::translate("Widget", "\350\256\276\347\275\256", nullptr));
        label_difficulty->setText(QCoreApplication::translate("Widget", "\351\232\276\345\272\246:", nullptr));
        difficultyCombo->setItemText(0, QCoreApplication::translate("Widget", "\347\256\200\345\215\225", nullptr));
        difficultyCombo->setItemText(1, QCoreApplication::translate("Widget", "\344\270\255\347\255\211", nullptr));
        difficultyCombo->setItemText(2, QCoreApplication::translate("Widget", "\345\233\260\351\232\276", nullptr));

        label_duration->setText(QCoreApplication::translate("Widget", "\346\227\266\351\225\277(\347\247\222):", nullptr));
        label_speed->setText(QCoreApplication::translate("Widget", "\351\200\237\345\272\246:", nullptr));
        normalMode->setText(QCoreApplication::translate("Widget", "\346\231\256\351\200\232\346\250\241\345\274\217", nullptr));
        comboMode->setText(QCoreApplication::translate("Widget", "\350\277\236\345\207\273\346\250\241\345\274\217", nullptr));
        punishmentCheckBox->setText(QCoreApplication::translate("Widget", "\346\203\251\347\275\232\346\250\241\345\274\217 (\347\202\271\347\251\272\346\211\243\345\210\206)", nullptr));
        startStopBtn->setText(QCoreApplication::translate("Widget", "\342\226\266 \345\274\200\345\247\213\346\270\270\346\210\217", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H

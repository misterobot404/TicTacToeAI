#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QSoundEffect>
#include <QMessageBox>
#include <QFontDatabase>
#include <QFile>
#include <QGraphicsEffect>
#include <QComboBox>
#include <QDesktopWidget>
#include <QSlider>
#include <algorithm>
#include <random>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots: 
    //Main Menu
    void on_pushButton_Exit_clicked();
    void on_pushButton_Setting_clicked();
    void on_pushButton_Play_clicked();   
    //Setting
    void on_pushButton_SettingBack_clicked();
    void on_comboBox_currentIndexChanged(const QString &arg1);
    void on_comboBox_2_currentTextChanged(const QString &arg1);
    void on_horizontalSlider_sliderMoved(int position);    
    void on_horizontalSlider_2_sliderMoved(int position);
    // Preset
    void on_pushButton_PresetBack_clicked();
    void on_pushButton_PresetStart_clicked();   
    // Game
    void on_pushButton_GameBack_clicked();
    void on_pushButton_GameContinue_clicked();
    void on_pushButton_1_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_6_clicked();
    void on_pushButton_7_clicked();
    void on_pushButton_8_clicked();
    void on_pushButton_9_clicked();
    void on_pushButton_10_clicked();
    void on_pushButton_11_clicked();
    void on_pushButton_12_clicked();
    void on_pushButton_13_clicked();
    void on_pushButton_14_clicked();
    void on_pushButton_15_clicked();
    void on_pushButton_16_clicked();
    void on_pushButton_17_clicked();
    void on_pushButton_18_clicked();
    void on_pushButton_19_clicked();
    void on_pushButton_20_clicked();
    void on_pushButton_21_clicked();
    void on_pushButton_22_clicked();
    void on_pushButton_23_clicked();
    void on_pushButton_24_clicked();
    void on_pushButton_25_clicked();   

    void on_pushButton_GameRestart_clicked();

private:
    // Game
    QVector<QVector<int>> field;
    void moveZero();
    bool checkWin(int symb);
    bool checkLanes(int symb, int offsetX, int offsetY);
    bool checkDiagonal(int symb, int offsetX, int offsetY);
    int getRandomInt(int start, int end);
    void turnOnLighting(int nubmerBtnX,int nubmerBtnY);
    void turnOffLighting();
    void clearField();
    // Music
    QMediaPlaylist playlist;
    QMediaPlayer music;
    QSoundEffect songClick;
    Ui::MainWindow *ui;
    // Other
    void setWidgetCenter();
};

#endif // MAINWINDOW_H

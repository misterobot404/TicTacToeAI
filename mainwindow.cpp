#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{    
    ui->setupUi(this);

    //  Disable resize wnd | disable border wnd
    setWindowFlags(Qt::MSWindowsFixedSizeDialogHint | Qt::FramelessWindowHint);

    // Music player
    playlist.addMedia(QUrl::fromLocalFile("song/Op3.mp3"));
    playlist.addMedia(QUrl::fromLocalFile("song/Op2.mp3"));
    playlist.setPlaybackMode(QMediaPlaylist::Loop);

    music.setPlaylist(&playlist);
    music.setVolume(3);
    ui->horizontalSlider->setValue(15);
    music.play();

    // Song Click
    songClick.setSource(QUrl::fromLocalFile(":/resources/song/Click.wav"));
    songClick.setVolume(qreal(0.5));
    ui->horizontalSlider_2->setValue(50);
    connect(ui->pushButton_Play, &QPushButton::clicked, &songClick, &QSoundEffect::play);
    connect(ui->pushButton_Setting, &QPushButton::clicked, &songClick, &QSoundEffect::play);
    connect(ui->pushButton_Exit, &QPushButton::clicked, &songClick, &QSoundEffect::play);
    connect(ui->pushButton_SettingBack, &QPushButton::clicked, &songClick, &QSoundEffect::play);
    connect(ui->pushButton_PresetBack, &QPushButton::clicked, &songClick, &QSoundEffect::play);
    connect(ui->pushButton_PresetStart, &QPushButton::clicked, &songClick, &QSoundEffect::play);
    connect(ui->pushButton_GameBack, &QPushButton::clicked, &songClick, &QSoundEffect::play);
    connect(ui->pushButton_GameContinue, &QPushButton::clicked, &songClick, &QSoundEffect::play);
    connect(ui->pushButton_GameRestart, &QPushButton::clicked, &songClick, &QSoundEffect::play);
    connect(ui->pushButton_Leaderboard, &QPushButton::clicked, &songClick, &QSoundEffect::play);

    // Font
    QFontDatabase::addApplicationFont(":/resources/HACKED.ttf");

    // Set height of the tabs on a QToolBox widget
    for (int i = 0; i < ui->toolBox->count(); i++){
        ui->toolBox->setItemIcon( i, QIcon(":/shared/empty"));
    }

    // Fill collection
    field.resize(5);
    for (int i=0, size=field.size(); i<size; i++)
    {
        field[i].resize(5);
        std::fill(field[i].begin(), field[i].end(), 0);
    }
}

// Main Menu
void MainWindow::on_pushButton_Play_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}
void MainWindow::on_pushButton_Setting_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}
void MainWindow::on_pushButton_Exit_clicked()
{
    songClick.play();

    // Create message box
    QMessageBox msgBox;
    msgBox.setText("<p align='center' style='font-size:36px;'>Confirm Quite</p><p align='center'>Are you sure you want to leave?</p>");
    msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    msgBox.setDefaultButton(QMessageBox::No);
    msgBox.setWindowFlags( Qt::FramelessWindowHint );

    QFile File(":/resources/css/styleSheetMessageBox.qss");
    File.open(QFile::ReadOnly);
    QString StyleSheet = QLatin1String(File.readAll());
    msgBox.setStyleSheet(StyleSheet);

    QGraphicsBlurEffect *effect = new QGraphicsBlurEffect;
    this->setGraphicsEffect(effect);

    if(msgBox.exec() == QMessageBox::Yes)
        MainWindow::close();
    effect->setEnabled(false);
}

// Preset
void MainWindow::on_pushButton_PresetBack_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}
void MainWindow::on_pushButton_PresetStart_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

// Game
void MainWindow::on_pushButton_GameContinue_clicked()
{
    MainWindow::clearField();
    MainWindow::turnOffLighting();
    ui->pushButton_GameContinue->setEnabled(false);
}
void MainWindow::on_pushButton_GameRestart_clicked()
{
    MainWindow::clearField();
    MainWindow::turnOffLighting();
    ui->pushButton_GameRestart->setEnabled(false);
    ui->pushButton_GameContinue->setEnabled(false);
}
void MainWindow::on_pushButton_GameBack_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}
void MainWindow::on_pushButton_1_clicked()
{
    if(ui->pushButton_1->text() == "")
    {
        ui->pushButton_1->setText("ㄨ");
        field[0][0]=1;
        MainWindow::checkWin(1);
        MainWindow::moveZero();
        MainWindow::checkWin(2);
    }
}
void MainWindow::on_pushButton_2_clicked()
{
    if(ui->pushButton_2->text() == "")
    {
        ui->pushButton_2->setText("ㄨ");
        field[0][1]=1;
        MainWindow::checkWin(1);
        MainWindow::moveZero();
        MainWindow::checkWin(2);
    }
}
void MainWindow::on_pushButton_3_clicked()
{
    if(ui->pushButton_3->text() == "")
    {
        ui->pushButton_3->setText("ㄨ");
        field[0][2]=1;
        MainWindow::checkWin(1);
        MainWindow::moveZero();
        MainWindow::checkWin(2);
    }
}
void MainWindow::on_pushButton_4_clicked()
{
    if(ui->pushButton_4->text() == "")
    {
        ui->pushButton_4->setText("ㄨ");
        field[0][3]=1;
        MainWindow::checkWin(1);
        MainWindow::moveZero();
        MainWindow::checkWin(2);
    }
}
void MainWindow::on_pushButton_5_clicked()
{
    if(ui->pushButton_5->text() == "")
    {
        ui->pushButton_5->setText("ㄨ");
        field[0][4]=1;
        MainWindow::checkWin(1);
        MainWindow::moveZero();
        MainWindow::checkWin(2);
    }
}
void MainWindow::on_pushButton_6_clicked()
{
    if(ui->pushButton_6->text() == "")
    {
        ui->pushButton_6->setText("ㄨ");
        field[1][0]=1;
        MainWindow::checkWin(1);
        MainWindow::moveZero();
        MainWindow::checkWin(2);
    }
}
void MainWindow::on_pushButton_7_clicked()
{
    if(ui->pushButton_7->text() == "")
    {
        ui->pushButton_7->setText("ㄨ");
        field[1][1]=1;
        MainWindow::checkWin(1);
        MainWindow::moveZero();
        MainWindow::checkWin(2);
    }
}
void MainWindow::on_pushButton_8_clicked()
{
    if(ui->pushButton_8->text() == "")
    {
        ui->pushButton_8->setText("ㄨ");
        field[1][2]=1;
        MainWindow::checkWin(1);
        MainWindow::moveZero();
        MainWindow::checkWin(2);
    }
}
void MainWindow::on_pushButton_9_clicked()
{
    if(ui->pushButton_9->text() == "")
    {
        ui->pushButton_9->setText("ㄨ");
        field[1][3]=1;
        MainWindow::checkWin(1);
        MainWindow::moveZero();
        MainWindow::checkWin(2);
    }
}
void MainWindow::on_pushButton_10_clicked()
{
    if(ui->pushButton_10->text() == "")
    {
        ui->pushButton_10->setText("ㄨ");
        field[1][4]=1;
        MainWindow::checkWin(1);
        MainWindow::moveZero();
        MainWindow::checkWin(2);
    }
}
void MainWindow::on_pushButton_11_clicked()
{
    if(ui->pushButton_11->text() == "")
    {
        ui->pushButton_11->setText("ㄨ");
        field[2][0]=1;
        MainWindow::checkWin(1);
        MainWindow::moveZero();
        MainWindow::checkWin(2);
    }
}
void MainWindow::on_pushButton_12_clicked()
{
    if(ui->pushButton_12->text() == "")
    {
        ui->pushButton_12->setText("ㄨ");
        field[2][1]=1;
        MainWindow::checkWin(1);
        MainWindow::moveZero();
        MainWindow::checkWin(2);
    }
}
void MainWindow::on_pushButton_13_clicked()
{
    if(ui->pushButton_13->text() == "")
    {
        ui->pushButton_13->setText("ㄨ");
        field[2][2]=1;
        MainWindow::checkWin(1);
        MainWindow::moveZero();
        MainWindow::checkWin(2);
    }
}
void MainWindow::on_pushButton_14_clicked()
{
    if(ui->pushButton_14->text() == "")
    {
        ui->pushButton_14->setText("ㄨ");
        field[2][3]=1;
        MainWindow::checkWin(1);
        MainWindow::moveZero();
        MainWindow::checkWin(2);
    }
}
void MainWindow::on_pushButton_15_clicked()
{
    if(ui->pushButton_15->text() == "")
    {
        ui->pushButton_15->setText("ㄨ");
        field[2][4]=1;
        MainWindow::checkWin(1);
        MainWindow::moveZero();
        MainWindow::checkWin(2);
    }
}
void MainWindow::on_pushButton_16_clicked()
{
    if(ui->pushButton_16->text() == "")
    {
        ui->pushButton_16->setText("ㄨ");
        field[3][0]=1;
        MainWindow::checkWin(1);
        MainWindow::moveZero();
        MainWindow::checkWin(2);
    }
}
void MainWindow::on_pushButton_17_clicked()
{
    if(ui->pushButton_17->text() == "")
    {
        ui->pushButton_17->setText("ㄨ");
        field[3][1]=1;
        MainWindow::checkWin(1);
        MainWindow::moveZero();
        MainWindow::checkWin(2);
    }
}
void MainWindow::on_pushButton_18_clicked()
{
    if(ui->pushButton_18->text() == "")
    {
        ui->pushButton_18->setText("ㄨ");
        field[3][2]=1;
        MainWindow::checkWin(1);
        MainWindow::moveZero();
        MainWindow::checkWin(2);
    }
}
void MainWindow::on_pushButton_19_clicked()
{
    if(ui->pushButton_19->text() == "")
    {
        ui->pushButton_19->setText("ㄨ");
        field[3][3]=1;
        MainWindow::checkWin(1);
        MainWindow::moveZero();
        MainWindow::checkWin(2);
    }
}
void MainWindow::on_pushButton_20_clicked()
{
    if(ui->pushButton_20->text() == "")
    {
        ui->pushButton_20->setText("ㄨ");
        field[3][4]=1;
        MainWindow::checkWin(1);
        MainWindow::moveZero();
        MainWindow::checkWin(2);
    }
}
void MainWindow::on_pushButton_21_clicked()
{
    if(ui->pushButton_21->text() == "")
    {
        ui->pushButton_21->setText("ㄨ");
        field[4][0]=1;
        MainWindow::checkWin(1);
        MainWindow::moveZero();
        MainWindow::checkWin(2);
    }
}
void MainWindow::on_pushButton_22_clicked()
{
    if(ui->pushButton_22->text() == "")
    {
        ui->pushButton_22->setText("ㄨ");
        field[4][1]=1;
        MainWindow::checkWin(1);
        MainWindow::moveZero();
        MainWindow::checkWin(2);
    }
}
void MainWindow::on_pushButton_23_clicked()
{
    if(ui->pushButton_23->text() == "")
    {
        ui->pushButton_23->setText("ㄨ");
        field[4][2]=1;
        MainWindow::checkWin(1);
        MainWindow::moveZero();
        MainWindow::checkWin(2);
    }
}
void MainWindow::on_pushButton_24_clicked()
{
    if(ui->pushButton_24->text() == "")
    {
        ui->pushButton_24->setText("ㄨ");
        field[4][3]=1;
        MainWindow::checkWin(1);
        MainWindow::moveZero();
        MainWindow::checkWin(2);
    }
}
void MainWindow::on_pushButton_25_clicked()
{
    if(ui->pushButton_25->text() == "")
    {
        ui->pushButton_25->setText("ㄨ");
        field[4][4]=1;
        MainWindow::checkWin(1);
        MainWindow::moveZero();
        MainWindow::checkWin(2);
    }
}

// Setting
void MainWindow::on_pushButton_SettingBack_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}
void MainWindow::on_comboBox_currentIndexChanged(const QString &arg1)
{
    if (arg1 == "1920x1080")
    {
        setFixedSize(1920,1080);
        setWidgetCenter();
    }
    else if (arg1 == "1366x768")
    {
        setFixedSize(1366,768);
        setWidgetCenter();
    }
    else if (arg1 == "1024x768")
    {
        setFixedSize(1024,768);
        setWidgetCenter();
    }
}
void MainWindow::on_comboBox_2_currentTextChanged(const QString &arg1)
{
    if(arg1 == "Full Screen")
    {
        this->showFullScreen();
        ui->comboBox->setCurrentIndex(0);
        ui->comboBox->setEnabled(false);
    }
    else if(arg1 == "Hide Border")
    {
        ui->comboBox->setEnabled(true);
        setWindowFlags(Qt::FramelessWindowHint);
        this->show();
    }
    else if (arg1 == "Show Border")
    {
        ui->comboBox->setEnabled(true);
        Qt::WindowFlags flags = windowFlags();
        flags &= ~Qt::FramelessWindowHint;
        setWindowFlags(flags);
        this->show();
    }
}
void MainWindow::on_horizontalSlider_sliderMoved(int position)
{
    music.setVolume(position);
}
void MainWindow::on_horizontalSlider_2_sliderMoved(int position)
{
    songClick.setVolume(QAudio::convertVolume(position / qreal(100.0),
                                              QAudio::LogarithmicVolumeScale,
                                              QAudio::LinearVolumeScale));
}

// Own method
void MainWindow::setWidgetCenter()
{
    this->setGeometry(
                QStyle::alignedRect(
                    Qt::LeftToRight,
                    Qt::AlignCenter,
                    this->size(),
                    qApp->desktop()->availableGeometry()
                    ));
}

//Game AI
void MainWindow::moveZero()
{
    int count = 0;
    for (int i=0, size=field.size(); i<size; ++i)
        count += std::count(field[i].begin(), field[i].end(), 0);

    if(count)
    {
        int row = 0;
        int column = 0;

        int randBtn = getRandomInt(1,count);

        for (int numberBtn = 0; numberBtn < randBtn; row++)
            for (column = 0; column < 5 && numberBtn < randBtn; column++)
                if(field[row][column] == 0) numberBtn++;

        int searchBtn = row * 5 - 4 + --column;
        switch (searchBtn)
        {
        case 1:
            ui->pushButton_1->setText("〇");
            field[row-1][column]=2;
            break;
        case 2:
            ui->pushButton_2->setText("〇");
            field[row-1][column]=2;
            break;
        case 3:
            ui->pushButton_3->setText("〇");
            field[row-1][column]=2;
            break;
        case 4:
            ui->pushButton_4->setText("〇");
            field[row-1][column]=2;
            break;
        case 5:
            ui->pushButton_5->setText("〇");
            field[row-1][column]=2;
            break;
        case 6:
            ui->pushButton_6->setText("〇");
            field[row-1][column]=2;
            break;
        case 7:
            ui->pushButton_7->setText("〇");
            field[row-1][column]=2;
            break;
        case 8:
            ui->pushButton_8->setText("〇");
            field[row-1][column]=2;
            break;
        case 9:
            ui->pushButton_9->setText("〇");
            field[row-1][column]=2;
            break;
        case 10:
            ui->pushButton_10->setText("〇");
            field[row-1][column]=2;
            break;
        case 11:
            ui->pushButton_11->setText("〇");
            field[row-1][column]=2;
            break;
        case 12:
            ui->pushButton_12->setText("〇");
            field[row-1][column]=2;
            break;
        case 13:
            ui->pushButton_13->setText("〇");
            field[row-1][column]=2;
            break;
        case 14:
            ui->pushButton_14->setText("〇");
            field[row-1][column]=2;
            break;
        case 15:
            ui->pushButton_15->setText("〇");
            field[row-1][column]=2;
            break;
        case 16:
            ui->pushButton_16->setText("〇");
            field[row-1][column]=2;
            break;
        case 17:
            ui->pushButton_17->setText("〇");
            field[row-1][column]=2;
            break;
        case 18:
            ui->pushButton_18->setText("〇");
            field[row-1][column]=2;
            break;
        case 19:
            ui->pushButton_19->setText("〇");
            field[row-1][column]=2;
            break;
        case 20:
            ui->pushButton_20->setText("〇");
            field[row-1][column]=2;
            break;
        case 21:
            ui->pushButton_21->setText("〇");
            field[row-1][column]=2;
            break;
        case 22:
            ui->pushButton_22->setText("〇");
            field[row-1][column]=2;
            break;
        case 23:
            ui->pushButton_23->setText("〇");
            field[row-1][column]=2;
            break;
        case 24:
            ui->pushButton_24->setText("〇");
            field[row-1][column]=2;
            break;
        case 25:
            ui->pushButton_25->setText("〇");
            field[row-1][column]=2;
            break;
        }

    }

}
bool MainWindow::checkWin(int symb)
{
    for (int col=0; col<5; col++) {
        for (int row=0; row<5; row++) {
            // Вызываем методы проверки и если хоть один блок заполнен,
            // то игрок, который проставляет это символ, выиграл
            // иначе продолжаем для другого смещения
            if (checkLanes(symb, col, row) || checkDiagonal(symb, col, row))
            {
                if(symb == 1) ui->pushButton_GameContinue->setEnabled(true);
                if(symb == 2) ui->pushButton_GameRestart->setEnabled(true);
                return true;
            }
        }
    }
    return false;
}
bool MainWindow::checkLanes(int symb, int offsetX, int offsetY)
{
    int block = 3; // размер блока

    if ((block + offsetX > 5) || (block + offsetY > 5)) return false;

    bool cols, rows;

    for (int X=offsetX, Y; X<block+offsetX; X++)
    {
        cols = true;
        rows = true;
        for ( Y=offsetY; Y<block+offsetY; Y++)
        {
            cols &= (field[X][Y] == symb);
            rows &= (field[Y][X] == symb);
        }
        if (cols)
        {
            Y--;
            for (int i = 0; i<block ; i++) turnOnLighting(Y-i,X);
            return true;
        }
        if (rows)
        {
            Y--;
            for (int i = 0; i<block ; i++) turnOnLighting(X,Y-i);
            return true;
        }
    }
    return false;
}
bool MainWindow::checkDiagonal(int symb, int offsetX, int offsetY)
{
    int block = 3; // размер блока

    if ((block + offsetX > 5) || (block + offsetY > 5)) return false;

    bool toright, toleft;
    toright = true;
    toleft = true;
    int X,Y;
    for (X=offsetX, Y=offsetY; X<block+offsetX; X++, Y++)
    {
        toright &= (field[X][Y] == symb);
        toleft &= (field[offsetX+(block+offsetX-X-1)][Y] == symb);
    }

    if (toright)
    {       
        for (X=offsetX, Y=offsetY; X<block+offsetX; X++, Y++)
            turnOnLighting(Y,X);
        return true;
    }
    if (toleft)
    {       
        for (X=offsetX, Y=offsetY; X<block+offsetX; X++, Y++)
            turnOnLighting(Y,offsetX+(block+offsetX-X-1));
        return true;
    }

    return false;
}
int MainWindow::getRandomInt(int start, int end)
{
    std::default_random_engine g(std::chrono::system_clock::now().time_since_epoch().count());
    std::uniform_int_distribution<int> distribution(start, end);
    return  distribution(g);
}
void MainWindow::turnOnLighting(int nubmerBtnX,int nubmerBtnY)
{
    int nubmerBtn = nubmerBtnX + ((nubmerBtnY+1) * 5 - 4);
    switch (nubmerBtn) {
    case 1:
        ui->pushButton_1->setStyleSheet("color: #148CD2;");
        break;
    case 2:
        ui->pushButton_2->setStyleSheet("color: #148CD2;");
        break;
    case 3:
        ui->pushButton_3->setStyleSheet("color: #148CD2;");
        break;
    case 4:
        ui->pushButton_4->setStyleSheet("color: #148CD2;");
        break;
    case 5:
        ui->pushButton_5->setStyleSheet("color: #148CD2;");
        break;
    case 6:
        ui->pushButton_6->setStyleSheet("color: #148CD2;");
        break;
    case 7:
        ui->pushButton_7->setStyleSheet("color: #148CD2;");
        break;
    case 8:
        ui->pushButton_8->setStyleSheet("color: #148CD2;");
        break;
    case 9:
        ui->pushButton_9->setStyleSheet("color: #148CD2;");
        break;
    case 10:
        ui->pushButton_10->setStyleSheet("color: #148CD2;");
        break;
    case 11:
        ui->pushButton_11->setStyleSheet("color: #148CD2;");
        break;
    case 12:
        ui->pushButton_12->setStyleSheet("color: #148CD2;");
        break;
    case 13:
        ui->pushButton_13->setStyleSheet("color: #148CD2;");
        break;
    case 14:
        ui->pushButton_14->setStyleSheet("color: #148CD2;");
        break;
    case 15:
        ui->pushButton_15->setStyleSheet("color: #148CD2;");
        break;
    case 16:
        ui->pushButton_16->setStyleSheet("color: #148CD2;");
        break;
    case 17:
        ui->pushButton_17->setStyleSheet("color: #148CD2;");
        break;
    case 18:
        ui->pushButton_18->setStyleSheet("color: #148CD2;");
        break;
    case 19:
        ui->pushButton_19->setStyleSheet("color: #148CD2;");
        break;
    case 20:
        ui->pushButton_20->setStyleSheet("color: #148CD2;");
        break;
    case 21:
        ui->pushButton_21->setStyleSheet("color: #148CD2;");
        break;
    case 22:
        ui->pushButton_22->setStyleSheet("color: #148CD2;");
        break;
    case 23:
        ui->pushButton_23->setStyleSheet("color: #148CD2;");
        break;
    case 24:
        ui->pushButton_24->setStyleSheet("color: #148CD2;");
        break;
    case 25:
        ui->pushButton_25->setStyleSheet("color: #148CD2;");
        break;
    }
}
void MainWindow::turnOffLighting()
{
    ui->pushButton_1->setStyleSheet("color: #F0F0F0;");
    ui->pushButton_2->setStyleSheet("color: #F0F0F0;");
    ui->pushButton_3->setStyleSheet("color: #F0F0F0;");
    ui->pushButton_4->setStyleSheet("color: #F0F0F0;");
    ui->pushButton_5->setStyleSheet("color: #F0F0F0;");
    ui->pushButton_6->setStyleSheet("color: #F0F0F0;");
    ui->pushButton_7->setStyleSheet("color: #F0F0F0;");
    ui->pushButton_8->setStyleSheet("color: #F0F0F0;");
    ui->pushButton_9->setStyleSheet("color: #F0F0F0;");
    ui->pushButton_10->setStyleSheet("color: #F0F0F0;");
    ui->pushButton_11->setStyleSheet("color: #F0F0F0;");
    ui->pushButton_12->setStyleSheet("color: #F0F0F0;");
    ui->pushButton_13->setStyleSheet("color: #F0F0F0;");
    ui->pushButton_14->setStyleSheet("color: #F0F0F0;");
    ui->pushButton_15->setStyleSheet("color: #F0F0F0;");
    ui->pushButton_16->setStyleSheet("color: #F0F0F0;");
    ui->pushButton_17->setStyleSheet("color: #F0F0F0;");
    ui->pushButton_18->setStyleSheet("color: #F0F0F0;");
    ui->pushButton_19->setStyleSheet("color: #F0F0F0;");
    ui->pushButton_20->setStyleSheet("color: #F0F0F0;");
    ui->pushButton_21->setStyleSheet("color: #F0F0F0;");
    ui->pushButton_22->setStyleSheet("color: #F0F0F0;");
    ui->pushButton_23->setStyleSheet("color: #F0F0F0;");
    ui->pushButton_24->setStyleSheet("color: #F0F0F0;");
    ui->pushButton_25->setStyleSheet("color: #F0F0F0;");

}
void MainWindow::clearField()
{
    for (int i=0, size=field.size(); i<size; i++)
    {
        std::fill(field[i].begin(), field[i].end(), 0);
    }

    ui->pushButton_1->setText("");
    ui->pushButton_2->setText("");
    ui->pushButton_3->setText("");
    ui->pushButton_4->setText("");
    ui->pushButton_5->setText("");
    ui->pushButton_6->setText("");
    ui->pushButton_7->setText("");
    ui->pushButton_8->setText("");
    ui->pushButton_9->setText("");
    ui->pushButton_10->setText("");
    ui->pushButton_11->setText("");
    ui->pushButton_12->setText("");
    ui->pushButton_13->setText("");
    ui->pushButton_14->setText("");
    ui->pushButton_15->setText("");
    ui->pushButton_16->setText("");
    ui->pushButton_17->setText("");
    ui->pushButton_18->setText("");
    ui->pushButton_19->setText("");
    ui->pushButton_20->setText("");
    ui->pushButton_21->setText("");
    ui->pushButton_22->setText("");
    ui->pushButton_23->setText("");
    ui->pushButton_24->setText("");
    ui->pushButton_25->setText("");
}

MainWindow::~MainWindow()
{
    delete ui;
}

// Repaint
/*
#include <QPixmap>
#include <QPainter>

void paintEvent(QPaintEvent *e);

void MainWindow::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);
    // painter.drawPixmap(0, 0, QPixmap(":/img/resources/neko.jpg").scaled(size()));
    QWidget::paintEvent(e);
}
*/


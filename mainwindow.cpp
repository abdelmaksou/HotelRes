#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPicture>
#include <QPixmap>
#include <promo.h>
#include <QMediaPlayer>
#include <QVideoWidget>

QMediaPlayer *MainWindow::backgroundmusic = new QMediaPlayer();

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
     //backgroundmusic = new QMediaPlayer();
    MainWindow::video =  new QVideoWidget();
    MainWindow::player = new QMediaPlayer();
    QPixmap pic ("C:/Users/Ghada/Desktop/CsProj/hmmmmm/Meme/imgs/images.png");
    ui->label_2->setPixmap(pic.scaled(ui->label_2->width(),ui->label_2->height(),Qt::KeepAspectRatio));
    player->setVideoOutput(video);
    player->setMedia(QUrl::fromLocalFile("C:/Users/Ghada/Downloads/ff.mpg"));
    backgroundmusic->setVolume(1000);
    player->setVolume(0);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    newUser *newuser= new newUser ();
    this->close();
    newuser->exec();
}

void MainWindow::on_pushButton_2_clicked()
{
    existingUser *existing = new existingUser();
    this->close();
    existing->exec();
}

void MainWindow::on_pushButton_3_clicked()
{
    QMessageBox msgBox;
    msgBox.setText("Are you sure you want to quit?");
    msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No );
    int ret = msgBox.exec();
    switch (ret) {
      case QMessageBox::Yes:
        this->close();
          break;
      case QMessageBox::No:
       {
        MainWindow *mmain = new MainWindow();
        this->close();
        mmain->show();
       }
        break;
    }
}




void MainWindow::on_pushButton_4_clicked()
{
    video->setGeometry(100,100, 1080, 720);
    video->show();
    player->setVolume(0);
    player->play();
}

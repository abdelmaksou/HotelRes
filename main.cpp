#include "mainwindow.h"
#include <QApplication>
#include <QTimer>
#include <QMediaPlayer>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QSplashScreen *splash= new QSplashScreen();
    splash->setPixmap(QPixmap("C:/Users/Ghada/Downloads/hmmmmm/Meme/imgs/horse.jpg"));
        MainWindow::backgroundmusic->setMedia(QUrl("C:/Users/Ghada/Downloads/hmmmmm/Meme/music/music.mpeg"));
        MainWindow::backgroundmusic->setVolume(1000000);
        MainWindow::backgroundmusic->play();
    splash->show();
    MainWindow w;
    w.show();
    QTimer::singleShot(500,splash,SLOT(close()));
    QTimer::singleShot(500,&w,SLOT(show()));
    return app.exec();

}

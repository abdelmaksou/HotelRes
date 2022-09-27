#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QSplashScreen>
#include <QMessageBox>
#include <QMainWindow>
#include "newuser.h"
#include "existinguser.h"
#include "edituser.h"
#include "availablecruise.h"
#include <QMediaPlayer>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    static QMediaPlayer* backgroundmusic;
    QMediaPlayer *player;
    QVideoWidget *video;

    static list <availableCruise*> trips;
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();


    void on_pushButton_4_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H

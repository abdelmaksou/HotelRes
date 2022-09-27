#include "promo.h"
#include "ui_promo.h"
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QDebug>
//#include "main.cpp"

promo::promo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::promo)
{
    ui->setupUi(this);


}

promo::~promo()
{
    delete ui;
}

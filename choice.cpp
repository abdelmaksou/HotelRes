#include "choice.h"
#include "ui_choice.h"
#include <QPixmap>
choice::choice(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::choice)
{
    ui->setupUi(this);
    Reservation::cruise=false;
    QPixmap pic ("C:/Users/Ghada/Desktop/CsProj/hmmmmm/Meme/imgs/active.png");
    ui->label->setPixmap(pic.scaled(ui->label->width(),ui->label->height(),Qt::KeepAspectRatio));
    ui->lineEdit->setText("Active: "+ existingUser::user);
}

choice::~choice()
{
    delete ui;
}

void choice::on_pushButton_2_clicked()
{
    Hotels *hotel = new Hotels();
    this->close();
    hotel->exec();
}

void choice::on_pushButton_4_clicked()
{
    MainWindow *mainn = new MainWindow();
    this->close();
    mainn->show();
}

void choice::on_pushButton_clicked()
{
    flights *flight = new flights ();
    this->close();
    flight->exec();
}

void choice::on_pushButton_3_clicked()
{
    Reservation::cruise=true;
    cruiseSearch *cr = new cruiseSearch();
    this->close();
    cr->exec();
}

void choice::on_pushButton_5_clicked()
{
    CustomerProfile *cus = new CustomerProfile();
    this->close();
    cus->exec();
}

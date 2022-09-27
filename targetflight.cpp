#include "targetflight.h"
#include "ui_targetflight.h"

targetFlight::targetFlight(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::targetFlight)
{
    ui->setupUi(this);
    ui->lineEdit_2->setText(Reservation::from);
    ui->lineEdit_5->setText(Reservation::to);
    ui->label_7->setText(Reservation::details);
    ui->lineEdit_6->setText(QString::number(Reservation::singleNO));
    ui->lineEdit_4->setText(QString::number(Reservation::doubleNo));
    ui->lineEdit_7->setText(QString::number(Reservation::tripleNO));

}

targetFlight::~targetFlight()
{
    delete ui;
}

void targetFlight::on_pushButton_clicked()
{   Reservation::isFlight=true;
    Reservation::flight = ui->dateTimeEdit->dateTime();
    Payment *pa = new Payment();
    this->close();
    pa->exec();
}

void targetFlight::on_comboBox_currentIndexChanged(int index)
{
    QComboBox *c = ui->comboBox;
    int x= c->currentIndex();
    if (x==0)
    {
         ui->lcdNumber->display(ui->lineEdit_6->text());
         Reservation::price = ui->lineEdit_6->text().toDouble();
    }
    if (x==1)
    {
        ui->lcdNumber->display(ui->lineEdit_4->text());
        Reservation::price = ui->lineEdit_4->text().toDouble();
    }
    if (x==2)
    {
        ui->lcdNumber->display(ui->lineEdit_7->text());
        Reservation::price = ui->lineEdit_7->text().toDouble();
    }



}



#include "reservation.h"
#include "ui_reservation.h"
#include <QRandomGenerator>
#include <time.h>
#include "cruisesearch.h"
//qsrand(QDateTime::currentMSecsSinceEpoch() / 1000);

int Reservation::choice;
int Reservation::count;
int Reservation::roomType;
int Reservation::singleNO=0;
int Reservation::doubleNo=0;
int Reservation::tripleNO=0;
int Reservation::price;
int Reservation::reward;
int Reservation::points;
bool Reservation::cruise;
bool Reservation::discount=false;
bool Reservation::isFlight=false;
string* Reservation::tripNames = new string();
int Reservation::id = QRandomGenerator::system()->generate();
QString Reservation::from;
QString Reservation::to;
QString Reservation::details;
QDate Reservation::in;
QDate Reservation::out;
QString* Reservation::s1[]= {new QString(),new QString(),new QString(),new QString(),new QString(),new QString(),new QString(),new QString(),new QString(),new QString(),new QString(),new QString(),new QString(),new QString(),new QString(),new QString(),new QString(),new QString()};



 QDateTime Reservation::flight;
Reservation::Reservation (vector<availableCruise*> trips, QWidget *parent)

   : QDialog(parent),
    ui(new Ui::Reservation)
{
    ui->setupUi(this);
    //for (int i=0; i<18; i++) tripNames[i]="";
    QGroupBox *groupBoxes [] = {this->ui->groupBox,this->ui->groupBox_2,this->ui->groupBox_3,this->ui->groupBox_6,this->ui->groupBox_4,this->ui->groupBox_5,this->ui->groupBox_9,this->ui->groupBox_7,this->ui->groupBox_8,this->ui->groupBox_12,this->ui->groupBox_10,this->ui->groupBox_11,this->ui->groupBox_15,this->ui->groupBox_13,this->ui->groupBox_14,this->ui->groupBox_18,this->ui->groupBox_16,this->ui->groupBox_17};
   QLabel *nameLabels [] = {this->ui->label_205,this->ui->label_209,this->ui->label_217,this->ui->label_429,this->ui->label_225,this->ui->label_233,this->ui->label_453,this->ui->label_433,this->ui->label_441,this->ui->label_477,this->ui->label_457,this->ui->label_465,this->ui->label_501,this->ui->label_481,this->ui->label_489,this->ui->label_525,this->ui->label_505, this->ui->label_513};
    QLabel *addressLabels [] = {this->ui->label_206,this->ui->label_210,this->ui->label_218,this->ui->label_430,this->ui->label_226,this->ui->label_234,this->ui->label_454,this->ui->label_434,this->ui->label_442,this->ui->label_478,this->ui->label_458,this->ui->label_466,this->ui->label_502,this->ui->label_482,this->ui->label_490,this->ui->label_526,this->ui->label_506, this->ui->label_514};
    QLabel *phoneLabels [] = {this->ui->label_208,this->ui->label_212,this->ui->label_220,this->ui->label_432,this->ui->label_228,this->ui->label_236,this->ui->label_456,this->ui->label_436,this->ui->label_444,this->ui->label_480,this->ui->label_460,this->ui->label_468,this->ui->label_504,this->ui->label_484,this->ui->label_492,this->ui->label_528,this->ui->label_508, this->ui->label_516};
    QLabel *emailLabels [] = {this->ui->label_207,  this ->ui-> label_211, this ->ui-> label_219, this ->ui-> label_431, this ->ui-> label_227, this ->ui-> label_235, this ->ui-> label_455, this ->ui-> label_435, this ->ui-> label_443, this ->ui-> label_479, this ->ui-> label_459 , this ->ui-> label_467, this ->ui-> label_503, this ->ui-> label_483, this ->ui-> label_491, this ->ui-> label_527, this ->ui-> label_507, this ->ui-> label_515};
    for (int i=0; i<18; i++)
       groupBoxes[i]->setVisible(false);
    //for (int i=0 ; i <4; i++)
        //tabs[i]->setVisible(false);
    for (int i=0; i<trips.size(); i++)
        {
            nameLabels[i]->setText(trips[i]->getName());
            addressLabels[i]->setText(trips[i]->getAddress());
            phoneLabels[i]->setText(trips[i]->getPhone());
            emailLabels[i]->setText(trips[i]->getEmail());
            groupBoxes[i]->setVisible(true);
           // tripNames[i]=trips[i]->name;
    *s1[i]= trips[i]->getName();
        }






}

Reservation::Reservation(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Reservation)
{
    ui->setupUi(this);
    QGroupBox *groupBoxes [] = {this->ui->groupBox,this->ui->groupBox_2,this->ui->groupBox_3,this->ui->groupBox_6,this->ui->groupBox_4,this->ui->groupBox_5,this->ui->groupBox_9,this->ui->groupBox_7,this->ui->groupBox_8,this->ui->groupBox_12,this->ui->groupBox_10,this->ui->groupBox_11,this->ui->groupBox_15,this->ui->groupBox_13,this->ui->groupBox_14,this->ui->groupBox_18,this->ui->groupBox_16,this->ui->groupBox_17};
   QLabel *nameLabels [] = {this->ui->label_205,this->ui->label_209,this->ui->label_217,this->ui->label_429,this->ui->label_225,this->ui->label_233,this->ui->label_453,this->ui->label_433,this->ui->label_441,this->ui->label_477,this->ui->label_457,this->ui->label_465,this->ui->label_501,this->ui->label_481,this->ui->label_489,this->ui->label_525,this->ui->label_505, this->ui->label_513};
    QLabel *addressLabels [] = {this->ui->label_206,this->ui->label_210,this->ui->label_218,this->ui->label_430,this->ui->label_226,this->ui->label_234,this->ui->label_454,this->ui->label_434,this->ui->label_442,this->ui->label_478,this->ui->label_458,this->ui->label_466,this->ui->label_502,this->ui->label_482,this->ui->label_490,this->ui->label_526,this->ui->label_506, this->ui->label_514};
    QLabel *phoneLabels [] = {this->ui->label_208,this->ui->label_212,this->ui->label_220,this->ui->label_432,this->ui->label_228,this->ui->label_236,this->ui->label_456,this->ui->label_436,this->ui->label_444,this->ui->label_480,this->ui->label_460,this->ui->label_468,this->ui->label_504,this->ui->label_484,this->ui->label_492,this->ui->label_528,this->ui->label_508, this->ui->label_516};
    QLabel *emailLabels [] = {this->ui->label_207,  this ->ui-> label_211, this ->ui-> label_219, this ->ui-> label_431, this ->ui-> label_227, this ->ui-> label_235, this ->ui-> label_455, this ->ui-> label_435, this ->ui-> label_443, this ->ui-> label_479, this ->ui-> label_459 , this ->ui-> label_467, this ->ui-> label_503, this ->ui-> label_483, this ->ui-> label_491, this ->ui-> label_527, this ->ui-> label_507, this ->ui-> label_515};
    for (int i=0; i<18; i++)
       groupBoxes[i]->setVisible(false);
    //for (int i=0 ; i <4; i++)
        //tabs[i]->setVisible(false);
    for (int i=0; i<Hotels::hotels.size(); i++)
        {
            nameLabels[i]->setText(Hotels::hotels[i]->getName());
            this->ui->label_205->setText(Hotels::hotels[i]->getName());
            addressLabels[i]->setText(Hotels::hotels[i]->getAddress());
            phoneLabels[i]->setText(Hotels::hotels[i]->getPhone());
            emailLabels[i]->setText(Hotels::hotels[i]->getEmail());
            groupBoxes[i]->setVisible(true);
        }


}

Reservation::~Reservation()
{
    delete ui;
}



void Reservation::on_pushButton_clicked()
{
    if(Reservation::cruise)
    {
        targetHotel* target = new targetHotel(s1[0]);
        this->close();
        target->exec();

    }
    else
    {
        choice = 0;
       targetHotel* target = new targetHotel();
       this->close();
       target->exec();
    }

}



void Reservation::on_pushButton_2_clicked()
{
    if(Reservation::cruise)
    {
        targetHotel* target = new targetHotel(s1[1]);
        this->close();
        target->exec();

    }
    else
    {
        choice = 1;
       targetHotel* target = new targetHotel();
       this->close();
       target->exec();
    }
}

void Reservation::on_pushButton_3_clicked()
{
    if(Reservation::cruise)
    {
        targetHotel* target = new targetHotel(s1[2]);
        this->close();
        target->exec();

    }
    else
    {
        choice = 2;
       targetHotel* target = new targetHotel();
       this->close();
       target->exec();
    }

}
void Reservation::on_pushButton_6_clicked()
{
    if(Reservation::cruise)
    {
        targetHotel* target = new targetHotel(s1[3]);
        this->close();
        target->exec();

    }
    else
    {
        choice = 3;
       targetHotel* target = new targetHotel();
       this->close();
       target->exec();
    }


}

void Reservation::on_pushButton_4_clicked()
{
    if(Reservation::cruise)
    {
        targetHotel* target = new targetHotel(s1[4]);
        this->close();
        target->exec();

    }
    else
    {
        choice = 4;
       targetHotel* target = new targetHotel();
       this->close();
       target->exec();
    }


}

void Reservation::on_pushButton_5_clicked()
{
    if(Reservation::cruise)
    {
        targetHotel* target = new targetHotel(s1[5]);
        this->close();
        target->exec();

    }
    else
    {
        choice = 5;
       targetHotel* target = new targetHotel();
       this->close();
       target->exec();
    }


}

void Reservation::on_pushButton_32_clicked()
{
    if(Reservation::cruise)
    {
        targetHotel* target = new targetHotel(s1[6]);
        this->close();
        target->exec();

    }
    else
    {
        choice = 6;
       targetHotel* target = new targetHotel();
       this->close();
       target->exec();
    }


}

void Reservation::on_pushButton_7_clicked()
{
    if(Reservation::cruise)
    {
        targetHotel* target = new targetHotel(s1[7]);
        this->close();
        target->exec();

    }
    else
    {
        choice = 7;
       targetHotel* target = new targetHotel();
       this->close();
       target->exec();
    }


}

void Reservation::on_pushButton_8_clicked()
{
    if(Reservation::cruise)
    {
        targetHotel* target = new targetHotel(s1[8]);
        this->close();
        target->exec();

    }
    else
    {
        choice = 8;
       targetHotel* target = new targetHotel();
       this->close();
       target->exec();
    }


}

void Reservation::on_pushButton_35_clicked()
{
    if(Reservation::cruise)
    {
        targetHotel* target = new targetHotel(s1[9]);
        this->close();
        target->exec();

    }
    else
    {
        choice = 9;
       targetHotel* target = new targetHotel();
       this->close();
       target->exec();
    }


}

void Reservation::on_pushButton_33_clicked()
{
    if(Reservation::cruise)
    {
        targetHotel* target = new targetHotel(s1[10]);
        this->close();
        target->exec();

    }
    else
    {
        choice = 10;
       targetHotel* target = new targetHotel();
       this->close();
       target->exec();
    }


}

void Reservation::on_pushButton_34_clicked()
{
    if(Reservation::cruise)
    {
        targetHotel* target = new targetHotel(s1[11]);
        this->close();
        target->exec();

    }
    else
    {
        choice = 11;
       targetHotel* target = new targetHotel();
       this->close();
       target->exec();
    }


}

void Reservation::on_pushButton_38_clicked()
{
    if(Reservation::cruise)
    {
        targetHotel* target = new targetHotel(s1[12]);
        this->close();
        target->exec();

    }
    else
    {
        choice = 12;
       targetHotel* target = new targetHotel();
       this->close();
       target->exec();
    }


}

void Reservation::on_pushButton_36_clicked()
{
    if(Reservation::cruise)
    {
        targetHotel* target = new targetHotel(s1[13]);
        this->close();
        target->exec();

    }
    else
    {
        choice = 13;
       targetHotel* target = new targetHotel();
       this->close();
       target->exec();
    }


}

void Reservation::on_pushButton_37_clicked()
{
    if(Reservation::cruise)
    {
        targetHotel* target = new targetHotel(s1[14]);
        this->close();
        target->exec();

    }
    else
    {
        choice = 14;
       targetHotel* target = new targetHotel();
       this->close();
       target->exec();
    }


}

void Reservation::on_pushButton_41_clicked()
{
    if(Reservation::cruise)
    {
        targetHotel* target = new targetHotel(s1[15]);
        this->close();
        target->exec();

    }
    else
    {
        choice = 15;
       targetHotel* target = new targetHotel();
       this->close();
       target->exec();
    }

}


void Reservation::on_pushButton_39_clicked()
{
    if(Reservation::cruise)
    {
        targetHotel* target = new targetHotel(s1[16]);
        this->close();
        target->exec();

    }
    else
    {
        choice = 16;
       targetHotel* target = new targetHotel();
       this->close();
       target->exec();
    }


}

void Reservation::on_pushButton_40_clicked()
{
    if(Reservation::cruise)
    {
        targetHotel* target = new targetHotel(s1[17]);
        this->close();
        target->exec();

    }
    else
    {
        choice = 17;
       targetHotel* target = new targetHotel();
       this->close();
       target->exec();
    }


}


void Reservation::on_pushButton_42_clicked()
{   //E#ML EL BAACKC
//    choice* cch = new choice();
  //  this->close();
    //ch-exec();
}


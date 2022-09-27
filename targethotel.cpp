#include "targethotel.h"
#include "ui_targethotel.h"

int p1, p2, p3;

targetHotel::targetHotel(QString* tripName,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::targetHotel)
{     ui->setupUi(this);

    QString path ;
        path="C:/Users/Ghada/Downloads/hmmmmm/Meme/cruises.db";

        // open locally stored db file
       if(!createDB(path))
        {
            QMessageBox::critical(this,
                                  tr("Database not found"),
                                  tr("Database not found. The application will be closed."),
                                  QMessageBox::Ok);
            qApp->exit();
        }

      QString hotel = "name LIKE '%" +*tripName+ "%'";
       model->setFilter(hotel);
         availableCruise *av = new availableCruise (model->index(0,0).data().toString(),model->index(0,1).data().toString(),model->index(0,2).data().toString(),model->index(0,3).data().toString(),model->index(0,4).data().toString(),model->index(0,5).data().toString(),model->index(0,6).data().toDouble(),model->index(0,7).data().toInt(),model->index(0,20).data().toString(),model->index(0,21).data().toDouble(),model->index(0,22).data().toDouble(),model->index(0,23).data().toDouble(),model->index(0,24).data().toInt(),model->index(0,25).data().toInt(),model->index(0,26).data().toInt());
           av->setAminities(model->index(0,8).data().toInt(),model->index(0,9).data().toInt(),model->index(0,10).data().toInt(),model->index(0,11).data().toInt(),model->index(0,12).data().toInt(),model->index(0,13).data().toInt(),model->index(0,14).data().toInt(),model->index(0,15).data().toInt(),model->index(0,16).data().toInt(),model->index(0,17).data().toInt(),model->index(0,18).data().toInt(),model->index(0,19).data().toInt());
           av->setSingleRooms(30);
           av->setDoubleRooms(20);
           av->setTripleRooms(10);
    p1=av->singleP; p2=av->doubleP; p3=av->tripleP;
    ui->lineEdit->setText(*tripName);
    ui->lineEdit_2->setText(av->getAddress());
    ui->lineEdit_5->setText(av->getPhone());
    ui->lineEdit_6->setText(av->getEmail());
    ui->lineEdit_4->setText(QString::number(av->getStarRating()));
    ui->lineEdit_7->setText(QString::number(av->getRatersNum()));
    ui->lineEdit_3->setText(av->getCity());

    ui->lineEdit->setReadOnly(true);
    ui->lineEdit_2->setReadOnly(true);
    ui->lineEdit_5->setReadOnly(true);
    ui->lineEdit_6->setReadOnly(true);
    ui->lineEdit_4->setReadOnly(true);
    ui->lineEdit_7->setReadOnly(true);
    ui->lineEdit_3->setReadOnly(true);

    if(av->getAminities()->pool) ui->checkBox->setChecked(true);
    if(av->getAminities()->gym ) ui->checkBox_2->setChecked(true);
    if(av->getAminities()->Breakfast) ui->checkBox_3->setChecked(true);
    if(av->getAminities()->Lunch) ui->checkBox_4->setChecked(true);
    if(av->getAminities()->Dinner) ui->checkBox_5->setChecked(true);
    if(av->getAminities()->Parking) ui->checkBox_6->setChecked(true);
    if(av->getAminities()->WiFi) ui->checkBox_7->setChecked(true);
    if(av->getAminities()->GardenView) ui->checkBox_8->setChecked(true);
    if(av->getAminities()->PoolView) ui->checkBox_9->setChecked(true);
    if(av->getAminities()->Parking) ui->checkBox_10->setChecked(true);
    if(av->getAminities()->Restaurant) ui->checkBox_11->setChecked(true);
    if(av->getAminities()->SPA) ui->checkBox_12->setChecked(true);

    ui->checkBox->setEnabled(false);
    ui->checkBox_2->setEnabled(false);
    ui->checkBox_3->setEnabled(false);
    ui->checkBox_4->setEnabled(false);
    ui->checkBox_5->setEnabled(false);
    ui->checkBox_6->setEnabled(false);
    ui->checkBox_7->setEnabled(false);
    ui->checkBox_8->setEnabled(false);
    ui->checkBox_9->setEnabled(false);
    ui->checkBox_10->setEnabled(false);
    ui->checkBox_11->setEnabled(false);
    ui->checkBox_12->setEnabled(false);


    ui->lineEdit_8->setText(QString::number(av->singleP));
    ui->lineEdit_9->setText(QString::number(av->doubleP));
    ui->lineEdit_10->setText(QString::number(av->tripleP));


}

targetHotel::targetHotel(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::targetHotel)
{
    ui->setupUi(this);
    AVAhotels *target = Hotels::hotels[Reservation::choice];
    p1=target->singleP; p2=target->doubleP; p3=target->tripleP;
    ui->lineEdit->setText(target->getName());
    ui->lineEdit_2->setText(target->getAddress());
    ui->lineEdit_5->setText(target->getPhone());
    ui->lineEdit_6->setText(target->getEmail());
    ui->lineEdit_4->setText(QString::number(target->getStarRating()));
    ui->lineEdit_7->setText(QString::number(target->getRatersNum()));
    ui->lineEdit_3->setText(target->getCity());

    ui->lineEdit->setReadOnly(true);
    ui->lineEdit_2->setReadOnly(true);
    ui->lineEdit_5->setReadOnly(true);
    ui->lineEdit_6->setReadOnly(true);
    ui->lineEdit_4->setReadOnly(true);
    ui->lineEdit_7->setReadOnly(true);
    ui->lineEdit_3->setReadOnly(true);

    if(target->getAminities()->pool) ui->checkBox->setChecked(true);
    if(target->getAminities()->gym ) ui->checkBox_2->setChecked(true);
    if(target->getAminities()->Breakfast) ui->checkBox_3->setChecked(true);
    if(target->getAminities()->Lunch) ui->checkBox_4->setChecked(true);
    if(target->getAminities()->Dinner) ui->checkBox_5->setChecked(true);
    if(target->getAminities()->Parking) ui->checkBox_6->setChecked(true);
    if(target->getAminities()->WiFi) ui->checkBox_7->setChecked(true);
    if(target->getAminities()->GardenView) ui->checkBox_8->setChecked(true);
    if(target->getAminities()->PoolView) ui->checkBox_9->setChecked(true);
    if(target->getAminities()->Parking) ui->checkBox_10->setChecked(true);
    if(target->getAminities()->Restaurant) ui->checkBox_11->setChecked(true);
    if(target->getAminities()->SPA) ui->checkBox_12->setChecked(true);

    ui->checkBox->setEnabled(false);
    ui->checkBox_2->setEnabled(false);
    ui->checkBox_3->setEnabled(false);
    ui->checkBox_4->setEnabled(false);
    ui->checkBox_5->setEnabled(false);
    ui->checkBox_6->setEnabled(false);
    ui->checkBox_7->setEnabled(false);
    ui->checkBox_8->setEnabled(false);
    ui->checkBox_9->setEnabled(false);
    ui->checkBox_10->setEnabled(false);
    ui->checkBox_11->setEnabled(false);
    ui->checkBox_12->setEnabled(false);


    ui->lineEdit_8->setText(QString::number(target->singleP));
    ui->lineEdit_9->setText(QString::number(target->doubleP));
    ui->lineEdit_10->setText(QString::number(target->tripleP));







}


targetHotel::~targetHotel()
{
    delete ui;
}

void targetHotel::on_dateEdit_userDateChanged(const QDate &date)
{   if(Reservation::cruise)
    {
        QString hotel = "name LIKE '%" +ui->lineEdit->text()+ "%'";
         model->setFilter(hotel);
           availableCruise *av = new availableCruise (model->index(0,0).data().toString(),model->index(0,1).data().toString(),model->index(0,2).data().toString(),model->index(0,3).data().toString(),model->index(0,4).data().toString(),model->index(0,5).data().toString(),model->index(0,6).data().toDouble(),model->index(0,7).data().toInt(),model->index(0,20).data().toString(),model->index(0,21).data().toDouble(),model->index(0,22).data().toDouble(),model->index(0,23).data().toDouble(),model->index(0,24).data().toInt(),model->index(0,25).data().toInt(),model->index(0,26).data().toInt());
             av->setAminities(model->index(0,8).data().toInt(),model->index(0,9).data().toInt(),model->index(0,10).data().toInt(),model->index(0,11).data().toInt(),model->index(0,12).data().toInt(),model->index(0,13).data().toInt(),model->index(0,14).data().toInt(),model->index(0,15).data().toInt(),model->index(0,16).data().toInt(),model->index(0,17).data().toInt(),model->index(0,18).data().toInt(),model->index(0,19).data().toInt());
             av->setSingleRooms(30);
             av->setDoubleRooms(20);
             av->setTripleRooms(10);
        int roomType= ui->spinBox->value();
       // int days = ui->dateEdit_2->date().day()- ui->dateEdit->date().day();
        //int months = ui->dateEdit_2->date().month()- ui->dateEdit->date().month();
        int dd = ui->dateEdit->date().daysTo(ui->dateEdit_2->date());

        //AVAhotels *target = Hotels::hotels[Reservation::choice];
        p1=av->singleP; p2=av->doubleP; p3=av->tripleP;
        if (dd<0){
            QMessageBox msgBox;
            msgBox.setStyleSheet("color:white; background-color:black;");
            msgBox.setText("Check in date must be before the check out date.");
            msgBox.exec();
            dd=0;

        }
        ui->dateEdit_2->date()=ui->dateEdit->date();
        double price;
        if (roomType==1) price= av->singleP;
        else if (roomType==2) price=av->doubleP;
        else if (roomType==3) price = av->tripleP;
        ui->lcdNumber->display(dd*price);
    }
    else
    {
        int roomType= ui->spinBox->value();
       // int days = ui->dateEdit_2->date().day()- ui->dateEdit->date().day();
        //int months = ui->dateEdit_2->date().month()- ui->dateEdit->date().month();
        int dd = ui->dateEdit->date().daysTo(ui->dateEdit_2->date());
        ui->lineEdit->setText(QString::number(dd));

        AVAhotels *target = Hotels::hotels[Reservation::choice];
        p1=target->singleP; p2=target->doubleP; p3=target->tripleP;
        if (dd<0){
            QMessageBox msgBox;
            msgBox.setStyleSheet("color:white; background-color:black;");
            msgBox.setText("Check in date must be before the check out date.");
            msgBox.exec();

        }
            ui->dateEdit_2->date()=ui->dateEdit->date();
        double price;
        if (roomType==1) price= target->singleP;
        else if (roomType==2) price=target->doubleP;
        else if (roomType==3) price = target->tripleP;
        ui->lcdNumber->display(dd*price);

    }
}

void targetHotel::on_dateEdit_2_userDateChanged(const QDate &date)
{
    if(Reservation::cruise)
       {
           QString hotel = "name LIKE '%" +ui->lineEdit->text()+ "%'";
            model->setFilter(hotel);
              availableCruise *av = new availableCruise (model->index(0,0).data().toString(),model->index(0,1).data().toString(),model->index(0,2).data().toString(),model->index(0,3).data().toString(),model->index(0,4).data().toString(),model->index(0,5).data().toString(),model->index(0,6).data().toDouble(),model->index(0,7).data().toInt(),model->index(0,20).data().toString(),model->index(0,21).data().toDouble(),model->index(0,22).data().toDouble(),model->index(0,23).data().toDouble(),model->index(0,24).data().toInt(),model->index(0,25).data().toInt(),model->index(0,26).data().toInt());
                av->setAminities(model->index(0,8).data().toInt(),model->index(0,9).data().toInt(),model->index(0,10).data().toInt(),model->index(0,11).data().toInt(),model->index(0,12).data().toInt(),model->index(0,13).data().toInt(),model->index(0,14).data().toInt(),model->index(0,15).data().toInt(),model->index(0,16).data().toInt(),model->index(0,17).data().toInt(),model->index(0,18).data().toInt(),model->index(0,19).data().toInt());
                av->setSingleRooms(30);
                av->setDoubleRooms(20);
                av->setTripleRooms(10);
           int roomType= ui->spinBox->value();
          // int days = ui->dateEdit_2->date().day()- ui->dateEdit->date().day();
           //int months = ui->dateEdit_2->date().month()- ui->dateEdit->date().month();
           int dd = ui->dateEdit->date().daysTo(ui->dateEdit_2->date());

           //AVAhotels *target = Hotels::hotels[Reservation::choice];
           p1=av->singleP; p2=av->doubleP; p3=av->tripleP;
           if (dd<0){
               QMessageBox msgBox;
               msgBox.setStyleSheet("color:white; background-color:black;");
               msgBox.setText("Check in date must be before the check out date.");
               msgBox.exec();

           }
           ui->dateEdit_2->date()=ui->dateEdit->date();
           double price;
           if (roomType==1) price= av->singleP;
           else if (roomType==2) price=av->doubleP;
           else if (roomType==3) price = av->tripleP;
           ui->lcdNumber->display(dd*price);
       }
       else
       {
           int roomType= ui->spinBox->value();
          // int days = ui->dateEdit_2->date().day()- ui->dateEdit->date().day();
           //int months = ui->dateEdit_2->date().month()- ui->dateEdit->date().month();
           int dd = ui->dateEdit->date().daysTo(ui->dateEdit_2->date());
           ui->lineEdit->setText(QString::number(dd));

           AVAhotels *target = Hotels::hotels[Reservation::choice];
           p1=target->singleP; p2=target->doubleP; p3=target->tripleP;
           if (dd<0){
               QMessageBox msgBox;
               msgBox.setStyleSheet("color:white; background-color:black;");
               msgBox.setText("Check in date must be before the check out date.");
               msgBox.exec();

           }
               ui->dateEdit_2->date()=ui->dateEdit->date();
           double price;
           if (roomType==1) price= target->singleP;
           else if (roomType==2) price=target->doubleP;
           else if (roomType==3) price = target->tripleP;
           ui->lcdNumber->display(dd*price);

       }
}

void targetHotel::on_pushButton_clicked()
{
    Payment *p = new Payment();
    Reservation::roomType = ui->spinBox->value();
    Reservation::in = ui->dateEdit->date();
    Reservation::out=ui->dateEdit_2->date();
    Reservation::price= ui->lcdNumber->value();
    if(ui->checkBox_13->isChecked()) Reservation::points=0;
    this->close();
    p->exec();

}

void targetHotel::on_checkBox_13_stateChanged(int arg1)
{    int dd = ui->dateEdit->date().daysTo(ui->dateEdit_2->date());
     if (dd<0){
         QMessageBox msgBox;
         msgBox.setStyleSheet("color:white; background-color:black;");
         msgBox.setText("Check in date must be before the check out date.");
         msgBox.exec();
         dd=0;

     }
     ui->dateEdit_2->date()=ui->dateEdit->date();
    if(Reservation::cruise)
    {
        Reservation::roomType= ui->spinBox->value();
        QString hotel = "name LIKE '%" +ui->lineEdit->text()+ "%'";
         model->setFilter(hotel);
           availableCruise *av = new availableCruise (model->index(0,0).data().toString(),model->index(0,1).data().toString(),model->index(0,2).data().toString(),model->index(0,3).data().toString(),model->index(0,4).data().toString(),model->index(0,5).data().toString(),model->index(0,6).data().toDouble(),model->index(0,7).data().toInt(),model->index(0,20).data().toString(),model->index(0,21).data().toDouble(),model->index(0,22).data().toDouble(),model->index(0,23).data().toDouble(),model->index(0,24).data().toInt(),model->index(0,25).data().toInt(),model->index(0,26).data().toInt());
             av->setAminities(model->index(0,8).data().toInt(),model->index(0,9).data().toInt(),model->index(0,10).data().toInt(),model->index(0,11).data().toInt(),model->index(0,12).data().toInt(),model->index(0,13).data().toInt(),model->index(0,14).data().toInt(),model->index(0,15).data().toInt(),model->index(0,16).data().toInt(),model->index(0,17).data().toInt(),model->index(0,18).data().toInt(),model->index(0,19).data().toInt());
             av->setSingleRooms(30);
             av->setDoubleRooms(20);
             av->setTripleRooms(10);
             if(ui->lcdNumber->value()>0)
             {
                 if (ui->checkBox_13->isChecked())
                 {
                     Reservation::reward= Reservation::points/2+3;
                     if (Reservation::roomType==1) ui->lcdNumber->display((av->singleP-Reservation::reward)*dd);
                     else if (Reservation::roomType==2) ui->lcdNumber->display((av->doubleP-Reservation::reward)*dd);
                     else if (Reservation::roomType==3)  ui->lcdNumber->display((av->tripleP-Reservation::reward)*dd);
                 }
                 else if (!ui->checkBox_13->isChecked())
                 {
                     if (Reservation::roomType==1) ui->lcdNumber->display(av->singleP*dd);
                     else if (Reservation::roomType==2) ui->lcdNumber->display(av->doubleP*dd);
                     else if (Reservation::roomType==3)  ui->lcdNumber->display(av->tripleP*dd);
                 }
             }


    }
    else
    {
        Reservation::roomType= ui->spinBox->value();
        AVAhotels *target = Hotels::hotels[Reservation::choice];
        if(ui->lcdNumber->value()>0)
        {
            if (ui->checkBox_13->isChecked())
            {
                Reservation::reward= Reservation::points/2+3;
                if (Reservation::roomType==1) ui->lcdNumber->display((target->singleP-Reservation::reward)*dd);
                else if (Reservation::roomType==2) ui->lcdNumber->display((target->doubleP-Reservation::reward)*dd);
                else if (Reservation::roomType==3)  ui->lcdNumber->display((target->tripleP-Reservation::reward)*dd);
            }
            else if (!ui->checkBox_13->isChecked())
            {
                if (Reservation::roomType==1) ui->lcdNumber->display(target->singleP*dd);
                else if (Reservation::roomType==2) ui->lcdNumber->display(target->doubleP*dd);
                else if (Reservation::roomType==3)  ui->lcdNumber->display(target->tripleP*dd);
            }
        }
    }

}

void targetHotel::on_pushButton_3_clicked()
{
    Hotels* ho = new Hotels ();
    this->close();
    ho->exec();

}

bool targetHotel::createDB(QString dbname)
{
db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(dbname);

    if(db.open())
    {

        bool found = false;
        foreach (QString table, db.tables())
        {
            if(table == "CruiseANDRooms")
            {
                found = true;
                break;
            }
        }
        if(!found)
        {
            QMessageBox::critical(this,
                                  tr("Not Found"),
                                  tr("Not Found. The application will be closed."),
                                  QMessageBox::Ok);
            qApp->exit();

        }

        model = new QSqlTableModel(this,db);
        model->setTable("CruiseANDRooms");
        model->setEditStrategy(QSqlTableModel::OnFieldChange);

        model->select();


    }
    else
    {
        return false;
    }

    return true;
}



void targetHotel::on_spinBox_valueChanged(int arg1)
{
    int dd = ui->dateEdit->date().daysTo(ui->dateEdit_2->date());
    if (dd<0){
        QMessageBox msgBox;
        msgBox.setStyleSheet("color:white; background-color:black;");
        msgBox.setText("Check in date must be before the check out date.");
        msgBox.exec();
        dd=0;

    }
    ui->dateEdit_2->date()=ui->dateEdit->date();
    Reservation::roomType= ui->spinBox->value();
    QString hotel = "name LIKE '%" +ui->lineEdit->text()+ "%'";
     model->setFilter(hotel);
       availableCruise *av = new availableCruise (model->index(0,0).data().toString(),model->index(0,1).data().toString(),model->index(0,2).data().toString(),model->index(0,3).data().toString(),model->index(0,4).data().toString(),model->index(0,5).data().toString(),model->index(0,6).data().toDouble(),model->index(0,7).data().toInt(),model->index(0,20).data().toString(),model->index(0,21).data().toDouble(),model->index(0,22).data().toDouble(),model->index(0,23).data().toDouble(),model->index(0,24).data().toInt(),model->index(0,25).data().toInt(),model->index(0,26).data().toInt());
         av->setAminities(model->index(0,8).data().toInt(),model->index(0,9).data().toInt(),model->index(0,10).data().toInt(),model->index(0,11).data().toInt(),model->index(0,12).data().toInt(),model->index(0,13).data().toInt(),model->index(0,14).data().toInt(),model->index(0,15).data().toInt(),model->index(0,16).data().toInt(),model->index(0,17).data().toInt(),model->index(0,18).data().toInt(),model->index(0,19).data().toInt());
         av->setSingleRooms(30);
         av->setDoubleRooms(20);
         av->setTripleRooms(10);
    if(Reservation::cruise)
    {

             if(ui->lcdNumber->value()>0)
             {
                 if (ui->checkBox_13->isChecked())
                 {
                     Reservation::reward= Reservation::points/2+3;
                     if (Reservation::roomType==1) ui->lcdNumber->display((av->singleP-Reservation::reward)*dd);
                     else if (Reservation::roomType==2) ui->lcdNumber->display((av->doubleP-Reservation::reward)*dd);
                     else if (Reservation::roomType==3)  ui->lcdNumber->display((av->tripleP-Reservation::reward)*dd);
                 }
                 else if (!ui->checkBox_13->isChecked())
                 {
                     if (Reservation::roomType==1) ui->lcdNumber->display(av->singleP*dd);
                     else if (Reservation::roomType==2) ui->lcdNumber->display(av->doubleP*dd);
                     else if (Reservation::roomType==3)  ui->lcdNumber->display(av->tripleP*dd);
                 }
             }

    }
    else
    {
        Reservation::roomType= ui->spinBox->value();
        AVAhotels *target = Hotels::hotels[Reservation::choice];
        if(ui->lcdNumber->value()>0)
        {
            if (ui->checkBox_13->isChecked())
            {
                Reservation::reward= Reservation::points/2+3;
                if (Reservation::roomType==1) ui->lcdNumber->display((av->singleP-Reservation::reward)*dd);
                else if (Reservation::roomType==2) ui->lcdNumber->display((av->doubleP-Reservation::reward)*dd);
                else if (Reservation::roomType==3)  ui->lcdNumber->display((av->tripleP-Reservation::reward)*dd);
            }
            else if (!ui->checkBox_13->isChecked())
            {
                if (Reservation::roomType==1) ui->lcdNumber->display(target->singleP*dd);
                else if (Reservation::roomType==2) ui->lcdNumber->display(target->doubleP*dd);
                else if (Reservation::roomType==3)  ui->lcdNumber->display(target->tripleP*dd);
            }
        }

    }
}

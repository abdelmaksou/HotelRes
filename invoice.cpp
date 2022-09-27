#include "invoice.h"
#include "ui_invoice.h"


Invoice::Invoice(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Invoice)
{
    if(Reservation::cruise)
    {
        ui->label->setText("Cruise Name");
        ui->label_3->setText("Address");
        ui->label_4->setText("Room Type");
        ui->label_5->setText("Room Number");
        ui->label_6->setHidden(true);
        ui->label_2->setHidden(true);
        ui->label_11->setHidden(true);
        ui->label_12->setHidden(true);
        ui->label_7->setText(Payment::av->name);
        ui->label_8->setText(Payment::av->address);
       // ui->label_9->setText(av->);                         ROOM TYPE NOT FOUND
        //ui->label_15->setText("CR-" + QString::number(id));        ID NOT FOUND
        ui->label_10->setText(Reservation::flight.toString());
        ui->lcdNumber->display(Reservation::price);
        QSqlQuery query;
           // QString q = "INSERT INTO filghts(id , type , f , t , details , price , date , user ) VALUES ('FL-" + QString::number(id) + "', 'Flight', '" + Reservation::from + "', '" + Reservation::to + "', '" + Reservation::details + "', '" + Reservation::price + "', '" + Reservation::flight.toString() + "', '" + existingUser::user + "');";
            //query.exec(q);
}
    ui->setupUi(this);
    ui->label->setText("Hotel Name");
    ui->label_3->setText("Hotel Address");
    ui->label_4->setText("Room Type");
    ui->label_5->setText("Room Number");
    ui->label_6->setHidden(false);
    ui->label_2->setHidden(false);
    ui->label_11->setHidden(false);
    ui->label_12->setHidden(false);
    int id = Reservation::id;

    QString path ;
    path="C:/Users/Ghada/Downloads/hmmmmm/Meme/reservations.db";

    //connect to db
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(path);
    db.open();

    // open locally stored db file
   if(!checkDB(db, "filghts", "hotels"))
    {
        QMessageBox::critical(this,
                              tr("Database not found"),
                              tr("Database not found. The application will be closed."),
                              QMessageBox::Ok);
        qApp->exit();
    }
/*
    // create and store db files
    QSqlQuery query;
    query.exec("CREATE TABLE filghts(id text, type text, f text, t text, details text, price text, date text, user text);");
    query.exec("CREATE TABLE hotels(id text, type text, name text, address text, roomType text, roomNumber text, i text, o text, user text);");

    if(!checkDB(db, "flights", "hotels"))
    {
        QMessageBox::critical(this,
                              tr("Database not found"),
                              tr("Database not found. The application will be closed."),
                              QMessageBox::Ok);
        qApp->exit();
    }
*/
    if(!Reservation::cruise)
    {
        if(!Reservation::isFlight)
        {
            AVAhotels *targetH = Hotels::hotels[Reservation::choice];
            Rooms *targetR ;
            if (Reservation::roomType==1) targetR= targetH->Single[Reservation::singleNO-1];
            else if (Reservation::roomType==2) targetR= targetH->Double[Reservation::doubleNo-1];
            else if (Reservation::roomType==3) targetR= targetH->Triple[Reservation::tripleNO-1];
            ui->label_7->setText(targetH->getName());
            ui->label_8->setText(targetH->getAddress());
            ui->label_9->setText(targetR->getType());
            ui->label_10->setText(QString::number(targetR->getNumber()));
            ui->label_11->setText(Reservation::in.toString());
            ui->label_12->setText(Reservation::out.toString());
            ui->label_15->setText("HO-" + QString::number(id));
            ui->lcdNumber->display(Reservation::price);
            QSqlQuery query;
                QString q = "INSERT INTO hotels(id, type, name, address, roomType, roomNumber, i, o, user) VALUES ('HO-" + QString::number(id) + "', 'Hotel', '" + targetH->getName() + "', '" + targetH->getAddress() + "', '" + targetR->getType() + "', '" + QString::number(targetR->getNumber()) + "', '" + Reservation::in.toString() + "', '" + Reservation::out.toString() + "', '" + existingUser::user + "');";
                query.exec(q);
        }
        else
        {
            ui->label->setText("From");
            ui->label_3->setText("To");
            ui->label_4->setText("Details");
            ui->label_5->setText("Date and Time");
            ui->label_6->setHidden(true);
            ui->label_2->setHidden(true);
            ui->label_11->setHidden(true);
            ui->label_12->setHidden(true);
            ui->label_7->setText(Reservation::from);
            ui->label_8->setText(Reservation::to);
            ui->label_9->setText(Reservation::details);
            ui->label_15->setText("FL-" + QString::number(id));
            ui->label_10->setText(Reservation::flight.toString());
            ui->lcdNumber->display(Reservation::price);
            QSqlQuery query;
                QString q = "INSERT INTO filghts(id , type , f , t , details , price , date , user ) VALUES ('FL-" + QString::number(id) + "', 'Flight', '" + Reservation::from + "', '" + Reservation::to + "', '" + Reservation::details + "', '" + Reservation::price + "', '" + Reservation::flight.toString() + "', '" + existingUser::user + "');";
                query.exec(q);
        }
    }


   }


bool Invoice::checkDB(QSqlDatabase db, QString db1, QString db2)
{

    if(db.open())
    {

        bool db1_found = false;
        bool db2_found = false;
        foreach (QString table, db.tables())
        {

            if(table == db1)
            {
                db1_found = true;
            }
            if(table == db2)
            {
                db2_found = true;
            }

        }
        if(!db1_found)
        {
            QMessageBox::critical(this,
                                  tr("Flights Not Found"),
                                  tr("Flights Not Found. The application will be closed."),
                                  QMessageBox::Ok);
            qApp->exit();
        }
        if(!db2_found)
        {
            QMessageBox::critical(this,
                                  tr("Hotels Not Found"),
                                  tr("Hotels Not Found. The application will be closed."),
                                  QMessageBox::Ok);
            qApp->exit();
        }

    }
    else
    {
        return false;
    }


return true;

}

Invoice::~Invoice()
{
    delete ui;
}

void Invoice::on_pushButton_clicked()
{
    choice *ch = new choice();
    this->close();
    ch->show();
}

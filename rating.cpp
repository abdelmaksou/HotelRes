#include "rating.h"
#include "ui_rating.h"
#include <QMessageBox>
#include "choice.h"
#include "reservation.h"

Rating::Rating(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Rating)
{
    ui->setupUi(this);

    QString path ;
    path="C:/Users/Ghada/Downloads/hmmmmm/Meme/citiesAndHotels.db";

    //connect to db
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(path);
    db.open();

    // open locally stored db file
   if(!checkDB(db))
    {
        QMessageBox::critical(this,
                              tr("Database not found"),
                              tr("Database not found. The application will be closed."),
                              QMessageBox::Ok);
        qApp->exit();
    }
}

bool Rating::checkDB(QSqlDatabase db)
{

    if(db.open())
    {

        bool found = false;
        foreach (QString table, db.tables())
        {
            if(table == "hotelsAndRooms")
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
    }
    else
    {
        return false;
    }

    return true;
}

Rating::~Rating()
{
    delete ui;
}

void Rating::on_pushButton_2_clicked()
{
    AVAhotels *target = Hotels::hotels[Reservation::choice];
    QSqlQuery query;
    QString q = "SELECT * FROM hotelsAndRooms WHERE name ='" + target->name + "';";
    double newRating = ((target->getStarRating()*target->getRatersNum()+ui->horizontalSlider->value())/((target->getRatersNum()+1)*5))*5;
    target->setStarRating(newRating);
    if(query.exec(q))
    {
        if(query.next())
        {
            QMessageBox msgBox;
            msgBox.setText("Are you sure?");
            msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
            int ret = msgBox.exec();
            switch (ret) {
              case QMessageBox::Yes:
                {
                msgBox.close();
                q = "UPDATE hotelsAndRooms SET starRating = '" + QString::number(newRating) + "' AND raterNum = '" + target->getRatersNum()+1 + "' WHERE name ='" + target->getName() + "';";
                query.exec(q);
                CustomerProfile *profile = new CustomerProfile();
                QMessageBox::information(this,
                                      tr("Done"),
                                      tr("Rating is successful."),
                                      QMessageBox::Ok);
                this->close();
                profile->exec();
                break;
                }
              case QMessageBox::No:
               {
                msgBox.close();
                break;
               }
            }
        }
        else
        {
            QMessageBox::critical(this,
                                  tr("Not Found"),
                                  tr("Not found. Try again."),
                                  QMessageBox::Ok);
        }
    }

}

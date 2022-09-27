#include "payment.h"
#include "ui_payment.h"
availableCruise* Payment::av = new availableCruise();

Payment::Payment(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Payment)
{
    ui->setupUi(this);
    QString user = existingUser::user;
    QString path ;
    path="C:/Users/Ghada/Downloads/hmmmmm/Meme/users.db";

    //connect to db
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(path);
    db.open();
    QSqlTableModel *model = new QSqlTableModel(this,db);
    model->setTable("users");
    model->select();
    model->setFilter("username = '" + user + "';");


}

Payment::~Payment()
{
    delete ui;
}

void Payment::on_pushButton_clicked()
{
    Reservation::count+=527520;
    Reservation::id+=Reservation::count;
    Reservation::points +=253;
    QSqlQuery query;
    QString q;
    q = "UPDATE users SET points = '" + QString::number(Reservation::points) + "' WHERE username ='" + existingUser::user + "';";
    query.exec(q);
    if(Reservation::cruise)
    {
        QString hotel = "name LIKE '%" +ui->lineEdit->text()+ "%'";
         model->setFilter(hotel);
           availableCruise *av = new availableCruise (model->index(0,0).data().toString(),model->index(0,1).data().toString(),model->index(0,2).data().toString(),model->index(0,3).data().toString(),model->index(0,4).data().toString(),model->index(0,5).data().toString(),model->index(0,6).data().toDouble(),model->index(0,7).data().toInt(),model->index(0,20).data().toString(),model->index(0,21).data().toDouble(),model->index(0,22).data().toDouble(),model->index(0,23).data().toDouble(),model->index(0,24).data().toInt(),model->index(0,25).data().toInt(),model->index(0,26).data().toInt());
             av->setAminities(model->index(0,8).data().toInt(),model->index(0,9).data().toInt(),model->index(0,10).data().toInt(),model->index(0,11).data().toInt(),model->index(0,12).data().toInt(),model->index(0,13).data().toInt(),model->index(0,14).data().toInt(),model->index(0,15).data().toInt(),model->index(0,16).data().toInt(),model->index(0,17).data().toInt(),model->index(0,18).data().toInt(),model->index(0,19).data().toInt());
             av->setSingleRooms(30);
             av->setDoubleRooms(20);
             av->setTripleRooms(10);
             Payment::av = av;
             if (Reservation::roomType==1)
             {
                 Reservation::singleNO++;
                 av->Single[Reservation::singleNO-1]->setAvailable(false);
                 av->singleA--;
                 //GOHAR WILL UPDATE THE DATABASEEEEE
             }
             else if (Reservation::roomType==2)
             {
                 Reservation::doubleNo++;
                 av->Double[Reservation::doubleNo-1]->setAvailable(false);
                 av->doubleP--;
                 //GOHAR WILL UPDATE THE DATABASEEEEE

             }
             else if (Reservation::roomType==3)
             {
                 Reservation::tripleNO++;
                 av->Triple[Reservation::tripleNO-1]->setAvailable(false);
                av->tripleP--;
                 //GOHAR WILL UPDATE THE DATABASEEEEE
             }
            if (Reservation::discount)
            {
                QMessageBox msgBox;
                 msgBox.setText("Congratulations! You got a 6.5% discount on your second reservation!");
                 QPushButton* horaay =new QPushButton("Click ME!");
                 msgBox.addButton(horaay ,QMessageBox::AcceptRole);
                 QObject::connect(horaay,&QPushButton::pressed,[](){qDebug("They pressed me!");});
                 Reservation::price=Reservation::price-0.065*Reservation::price;
                 Invoice *in = new Invoice();
                 this->close();
                 in->exec();

            }
            else{
                QMessageBox msgBox;
                 msgBox.setText("Do you want to reserve again?");
                 msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No );
                 int ret = msgBox.exec();
                 switch (ret) {
                   case QMessageBox::Yes:
                 {
                     Reservation::discount=true;
                     choice *ch = new choice();
                     Payment::av = av;
                     Invoice *in = new Invoice();
                     this->close();

                      in->exec();
                      ch->exec();

                     break;
                 }

                   case QMessageBox::No:
                 {
                     Invoice *in = new Invoice();
                     this->close();
                     in->exec();

                 }
             }
         }
      }
   /*      else
         {
             QMessageBox msgBox;
              msgBox.setText("Do you want to reserve again?");
              msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No );
              int ret = msgBox.exec();
              switch (ret) {
                case QMessageBox::Yes:
              {
                  Reservation::discount=true;
                  choice *ch = new choice();
                  Invoice *in = new Invoice();
                  this->close();

                   in->exec();
                   ch->exec();

                  break;
              }

                case QMessageBox::No:
              {
                  Invoice *in = new Invoice();
                  this->close();
                  in->exec();
                  break;

              }
          }



    }*/

    else
    {


        if(!Reservation::isFlight)
        {

            if (Reservation::roomType==1)
            {
                Reservation::singleNO++;
                Hotels::hotels[Reservation::choice]->Single[Reservation::singleNO-1]->setAvailable(false);
                Hotels::hotels[Reservation::choice]->singleA--;
                //GOHAR WILL UPDATE THE DATABASEEEEE
            }
            else if (Reservation::roomType==2)
            {
                Reservation::doubleNo++;
                Hotels::hotels[Reservation::choice]->Double[Reservation::doubleNo-1]->setAvailable(false);
                Hotels::hotels[Reservation::choice]->doubleP--;
                //GOHAR WILL UPDATE THE DATABASEEEEE

            }
            else if (Reservation::roomType==3)
            {
                Reservation::tripleNO++;
                Hotels::hotels[Reservation::choice]->Triple[Reservation::tripleNO-1]->setAvailable(false);
                Hotels::hotels[Reservation::choice]->tripleP--;
                //GOHAR WILL UPDATE THE DATABASEEEEE
            }
           if (Reservation::discount)
           {
               QMessageBox msgBox;
                msgBox.setText("Congratulations! You got a 6.5% discount on your second reservation!");
                QPushButton* horaay =new QPushButton("Click ME!");
                msgBox.addButton(horaay ,QMessageBox::AcceptRole);
                QObject::connect(horaay,&QPushButton::pressed,[](){qDebug("They pressed me!");});
                Reservation::price=Reservation::price-0.065*Reservation::price;
                Invoice *in = new Invoice();
                this->close();
                in->exec();

           }
           else{
               QMessageBox msgBox;
                msgBox.setText("Do you want to reserve again?");
                msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No );
                int ret = msgBox.exec();
                switch (ret) {
                  case QMessageBox::Yes:
                {
                    Reservation::discount=true;
                    choice *ch = new choice();
                    Invoice *in = new Invoice();
                    this->close();

                     in->exec();
                     ch->exec();

                    break;
                }

                  case QMessageBox::No:
                {
                    Invoice *in = new Invoice();
                    this->close();
                    in->exec();
                    break;

                }
            }
        }
     }
        else
        {
            QMessageBox msgBox;
             msgBox.setText("Do you want to reserve again?");
             msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No );
             int ret = msgBox.exec();
             switch (ret) {
               case QMessageBox::Yes:
             {
                 Reservation::discount=true;
                 choice *ch = new choice();
                 Invoice *in = new Invoice();
                 this->close();

                  in->exec();
                  ch->exec();

                 break;
             }

               case QMessageBox::No:
             {
                 Invoice *in = new Invoice();
                 this->close();
                 in->exec();
                 break;

             }
         }

        }

     }
}

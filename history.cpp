#include "history.h"
#include "ui_history.h"
#include "rating.h"
#include <QVBoxLayout>
#include <QSlider>

History::History(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::History)
{
    ui->setupUi(this);
    QString path ;
            path="C:/Users/Ghada/Downloads/hmmmmm/Meme/reservations.db";

            QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
            db.setDatabaseName(path);
            db.open();

            // open locally stored db file
          /* if(!createDB(path))
            {
                QMessageBox::critical(this,
                                      tr("Database not found"),
                                      tr("Database not found. The application will be closed."),
                                      QMessageBox::Ok);
                qApp->exit();
            }*/

            QTableView *viewHotels=ui->tableView;
            QTableView *viewFlights=ui->tableView_2;
            QString user = existingUser::user;
            QSqlTableModel *model = new QSqlTableModel(this,db);
            QSqlTableModel *model2 = new QSqlTableModel(this,db);
            model->setTable("hotels");
            model->select();
            model->setFilter("user = '" + user + "';");
            viewHotels->setModel(model);
            model2->setTable("filghts");
            model2->select();
            model2->setFilter("user = '" + user + "';");
            viewFlights->setModel(model2);

}


void History::findUser()
{
    QSqlTableModel *model= new QSqlTableModel();
    QTableView *view=ui->tableView;
    QString user = existingUser::user;
    model->setFilter("user = '" + user + "';");
    view->setModel(model);

}
History::~History()
{
    delete ui;
}



void History::on_tableView_doubleClicked(const QModelIndex &index)
{
    QTableView *view=ui->tableView;
    QString id = index.data().toString();
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    QSqlTableModel *model = new QSqlTableModel(this,db);
    model->setTable("hotels");
    model->select();
    model->setFilter("user = '" + existingUser::user + "';");
    view->setModel(model);
    QString path ;
            path="C:/Users/Ghada/Downloads/hmmmmm/Meme/reservations.db";
     db.setDatabaseName(path);
     db.open();
     if(ui->radioButton->isChecked())
     {
         Rating *rating = new Rating();
         this->close();
         rating->exec();
     }
     if (ui->radioButton_2->isChecked())
     {
         QSqlQuery query;
         query.exec("DELETE FROM hotels WHERE id ='"+ id+ "';");
         QMessageBox::information(this,
                               tr("Done"),
                               tr("Reservation successfully deleted from the database."),
                               QMessageBox::Ok);

     }

     model->setTable("hotels");
     model->select();
     model->setFilter("user = '" + existingUser::user + "';");
     view->setModel(model);

}

void History::on_tableView_2_doubleClicked(const QModelIndex &index)
{
    QTableView *view=ui->tableView_2;
    QString id = index.data().toString();
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    QSqlTableModel *model = new QSqlTableModel(this,db);
    model->setTable("filghts");
    model->select();
    model->setFilter("user = '" + existingUser::user + "';");
    view->setModel(model);
    QString path ;
            path="C:/Users/Ghada/Downloads/hmmmmm/Meme/reservations.db";
     db.setDatabaseName(path);
     db.open();
     if(ui->radioButton->isChecked())
     {
         Rating *rating = new Rating();
         this->close();
         rating->exec();
     }
     if (ui->radioButton_2->isChecked())
     {
         QSqlQuery query;
         query.exec("DELETE FROM filghts WHERE id ='"+ id+ "';");
         QMessageBox::information(this,
                               tr("Done"),
                               tr("Reservation successfully deleted from the database."),
                               QMessageBox::Ok);

     }

     model->setTable("filghts");
     model->select();
     model->setFilter("user = '" + existingUser::user + "';");
     view->setModel(model);

}

void History::on_pushButton_clicked()
{
    CustomerProfile * cus = new CustomerProfile();
    this->close();
    cus->exec();
}

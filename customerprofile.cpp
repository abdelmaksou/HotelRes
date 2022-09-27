#include "customerprofile.h"
#include "ui_customerprofile.h"
#include "mainwindow.h"
#include "choice.h"
#include "existinguser.h"
#include "edituser.h"
#include <QSqlTableModel>
#include <QTableView>

CustomerProfile::CustomerProfile(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CustomerProfile)
{
    ui->setupUi(this);

    QString path ;
    path="C:/Users/Ghada/Downloads/hmmmmm/Meme/users.db";

    //connect to db
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(path);
    db.open();

    // open locally stored db file
   if(!checkDB(db))
    {
        QMessageBox::critical(this,
                              tr("User not found"),
                              tr("User not found. The application will be closed."),
                              QMessageBox::Ok);
        qApp->exit();
    }

   QSqlTableModel *model = new QSqlTableModel(this,db);
   model->setTable("users");
   model->setEditStrategy(QSqlTableModel::OnFieldChange);

   model->select();
   model->setFilter("username = '" + existingUser::user + "';");

   QLineEdit *name = ui->lineEdit;
   QLineEdit *username = ui->lineEdit_2;
   QLineEdit *password = ui->lineEdit_3;
   QLineEdit *points = ui->lineEdit_8;
   QLineEdit *age = ui->lineEdit_4;
   QLineEdit *email = ui->lineEdit_6;
   QLineEdit *phone = ui->lineEdit_5;
   QLineEdit *country = ui->lineEdit_9;
   QLineEdit *passportN = ui->lineEdit_7;

   name->setText(model->index(0, 0).data().toString());
   username->setText(model->index(0, 1).data().toString());
   password->setText(model->index(0, 2).data().toString());
   points->setText(model->index(0, 8).data().toString());
   age->setText(model->index(0, 3).data().toString());
   email->setText(model->index(0, 4).data().toString());
   phone->setText(model->index(0, 5).data().toString());
   country->setText(model->index(0, 6).data().toString());
   passportN->setText(model->index(0, 7).data().toString());

}

bool CustomerProfile::checkDB(QSqlDatabase db)
{

    if(db.open())
    {

        bool found = false;
        foreach (QString table, db.tables())
        {
            if(table == "users")
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

CustomerProfile::~CustomerProfile()
{
    delete ui;
}

void CustomerProfile::on_pushButton_clicked()
{
    edituser *edu = new edituser();
    this->close();
    edu->exec();
}

void CustomerProfile::on_pushButton_2_clicked()
{
    QMessageBox msgBox;
    msgBox.setText("Are you sure you want to delete it?");
    msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    int ret = msgBox.exec();
    switch (ret) {
      case QMessageBox::Yes:
        {
        msgBox.close();
        QSqlQuery query;
        query.exec("DELETE FROM users WHERE username = '" + existingUser::user + "';");
        MainWindow *main = new MainWindow();
        this->close();
        main->show();
        break;
        }
      case QMessageBox::No:
       {
        msgBox.close();
        break;
       }
    }
}

void CustomerProfile::on_pushButton_3_clicked()
{
    choice *ch = new choice();
    this->close();
    ch->exec();
}

void CustomerProfile::on_pushButton_4_clicked()
{
    History *his = new History();
    this->close();
    his->exec();
}

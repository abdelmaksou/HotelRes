#include "edituser.h"
#include "ui_edituser.h"
#include "customerprofile.h"

edituser::edituser(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::edituser)
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
                              tr("Database not found"),
                              tr("Database not found. The application will be closed."),
                              QMessageBox::Ok);
        qApp->exit();
    }
}

edituser::~edituser()
{
    delete ui;
}

bool edituser::checkDB(QSqlDatabase db)
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


void edituser::on_change_clicked()
{
    QLineEdit *username = ui->lineEdit;
    QLineEdit *password = ui->lineEdit_2;
    QLineEdit *mixed = ui->lineEdit_3;
    QComboBox *combobox = ui->comboBox;

    //check if the lines are empty or not

    QSqlQuery query;
    QString q = "SELECT username, password FROM users WHERE username ='" + username->text() + "' AND password = '" + password->text() + "';";
    if(query.exec(q))
    {
        if(query.next())
        {
            QMessageBox msgBox;
            msgBox.setText("Are you sure you want to change?");
            msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
            int ret = msgBox.exec();
            switch (ret) {
              case QMessageBox::Yes:
                {
                msgBox.close();
                q = "UPDATE users SET " + combobox->currentText() + " = '" + mixed->text() + "' WHERE username ='" + username->text() + "' AND password = '" + password->text() + "';";
                query.exec(q);
                CustomerProfile *profile = new CustomerProfile();
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
                                  tr("You have entered wrong username or password. Try again."),
                                  QMessageBox::Ok);
        }
    }
}

void edituser::on_comboBox_currentIndexChanged(int index)
{
    QLineEdit *mixed = ui->lineEdit_3;
    QComboBox *combobox = ui->comboBox;
    mixed->setPlaceholderText(combobox->currentText());
}

#include "newuser.h"
#include "ui_newuser.h"

newUser::newUser(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::newUser)
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
/*
    // create and store db files
    QSqlQuery query;
    query.exec("CREATE TABLE users(name text, username text, password text, age int, email text, phone text, country text, passportN text);");

    if(!checkDB(db))
    {
        QMessageBox::critical(this,
                              tr("Database not found"),
                              tr("Database not found. The application will be closed."),
                              QMessageBox::Ok);
        qApp->exit();
    }
*/
}

bool newUser::checkDB(QSqlDatabase db)
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

newUser::~newUser()
{
    delete ui;
}

void newUser::on_pushButton_clicked()
{
    MainWindow *main = new MainWindow();
    main->show();
    this->close();

}

void newUser::on_pushButton_2_clicked()
{
    if (ui->lineEdit->text()=="" ||ui->lineEdit_2->text()==""||ui->lineEdit_3->text()==""||ui->lineEdit_4->text()=="" ||ui->lineEdit_5->text()==""||ui->lineEdit_6->text()==""||ui->lineEdit_7->text()==""||ui->lineEdit_8->text()=="")
    {
        QMessageBox *msgBox = new QMessageBox();//
        msgBox->setText("Error. Some information are missing.");
        msgBox->setStyleSheet("color:white;background-color:black;");
        msgBox->addButton(QMessageBox::Ok);
        msgBox->exec();
    }
    else
    {
        if(!(ui->lineEdit_6->text().contains("@")&&ui->lineEdit_6->text().contains(".com")))
        {
            QMessageBox *msgBox = new QMessageBox();//
            msgBox->setText("Error. Please enter a valid email address.");
            msgBox->setStyleSheet("color:white;background-color:black;");
            msgBox->addButton(QMessageBox::Ok);
            msgBox->exec();
        }
        else
        {
            QLineEdit *name = ui->lineEdit;
            QLineEdit *username = ui->lineEdit_2;
            QLineEdit *password = ui->lineEdit_3;
            QLineEdit *passwordAgain = ui->lineEdit_8;
            QLineEdit *age = ui->lineEdit_4;
            QLineEdit *email = ui->lineEdit_6;
            QLineEdit *phone = ui->lineEdit_5;
            QComboBox *country = ui->comboBox;
            QLineEdit *passportN = ui->lineEdit_7;
            QCheckBox *robot = ui->checkBox;

            // **** check the validity of the input

            if (robot->isChecked() == true)
            {
            QSqlQuery query;
                QString q = "INSERT INTO users(name, username, password, age, email, phone, country, passportN, points) VALUES ('" + name->text() + "', '" + username->text() + "', '" + password->text() + "', '" + age->text() + "', '" + email->text() + "', '" + phone->text() + "', '" + country->currentText() + "', '" + passportN->text() + "', '0');";
                query.exec(q);

                QMessageBox *msgBox = new QMessageBox();//
                msgBox->setText("Your account is created. Moving to the login page.");
                msgBox->setStyleSheet("color:white;background-color:black;");
                msgBox->addButton(QMessageBox::Ok);
                msgBox->exec();
                existingUser *existingUser = new class existingUser();
                existingUser->show();
                this->close();
            }
            else
            {
                QMessageBox *msgBox = new QMessageBox();//
                msgBox->setText("Missing info. Please confirm that you are not a robot.");
                msgBox->setStyleSheet("color:white;background-color:black;");
                msgBox->addButton(QMessageBox::Ok);
                msgBox->exec();
            }
        }
    }
}

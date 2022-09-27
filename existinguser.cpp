#include "existinguser.h"
#include "ui_existinguser.h"

QString existingUser::user;

existingUser::existingUser(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::existingUser)
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

bool existingUser::checkDB(QSqlDatabase db)
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

existingUser::~existingUser()
{
    delete ui;
}

void existingUser::on_pushButton_clicked()
{
    MainWindow *main = new MainWindow();
    main->show();
    this->close();
}

void existingUser::on_pushButton_2_clicked()
{
    //choice *chooice = new choice();
    //chooice->exec();
    QLineEdit *username = ui->lineEdit_2;
    QLineEdit *password = ui->lineEdit_3;

    //check if the lines are empty or not

    QSqlQuery query;
    user = username->text();
    QString q = "SELECT username, password FROM users WHERE username ='" + username->text() + "' AND password = '" + password->text() + "';";
    QSqlTableModel *model = new QSqlTableModel(this,db);
    model->setTable("users");
    model->select();
    model->setFilter("username = '" + user + "';");
    if(query.exec(q))
    {
        if(query.next())
        {
            Reservation::points = model->index(0, 8).data().toInt();
            choice *chooice = new choice();
            chooice->show();
            this->close();
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

void existingUser::on_pushButton_4_clicked()
{
    edituser * edu = new edituser();
    this->close();
    edu->exec();
}


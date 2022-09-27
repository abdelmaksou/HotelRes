#include "flights.h"
#include "ui_flights.h"
#include "graph.h"

flights::flights(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::flights)
{
    ui->setupUi(this);
    QString path ;
     path="C:/Users/Ghada/Desktop/CsProj/hmmmmm/Meme/flights.db";

     //connect to db
     QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
     db.setDatabaseName(path);
     db.open();

     model = new QSqlTableModel(this,db);
     model->setTable("flights");
     model->setEditStrategy(QSqlTableModel::OnFieldChange);
     model->select();
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

    bool flights::checkDB(QSqlDatabase db)
    {

        if(db.open())
        {

            bool found = false;
            foreach (QString table, db.tables())
            {
                if(table == "flights")
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



flights::~flights()
{
    delete ui;
}

void flights::on_pushButton_clicked()
{
    choice *choicee = new choice();
    this->close();
    choicee->exec();
}

void flights::on_pushButton_2_clicked()
{
    QLabel *label = ui->label;
        QTableView *table = ui->tableView;
        graph g;
        QLineEdit *from = ui->from;
        QLineEdit *to = ui->to;


        if(sh == true && ch == false)
        {
            int f, t;
            for (int i =0; i < 5; i++)
            {
                if (from->text().toCaseFolded() == QString::fromStdString(g.cities[i]).toCaseFolded())
                {
                    f = i;
                }
                if (to->text().toCaseFolded() == QString::fromStdString(g.cities[i]).toCaseFolded())
                {
                    t = i;
                }
            }
            g.dijkstra(f, t);
            label->setText(QString::fromStdString(g.result));
        }
        else if (sh == false && ch == true)
        {
            label->setText("");
            QString q = "src LIKE '%" + from->text() + "%' AND dst LIKE '%" + to->text() + "%' LIMIT 1;";
            model->setFilter(q);
            model->setSort(3, Qt::AscendingOrder);
            table->setModel(model);
        }
        else if (sh == false && ch == false)
        {
            label->setText("Choose a method.");
            QString q = "src LIKE '%" + from->text() + "%' AND dst LIKE '%" + to->text() + "%' LIMIT 0;";
            model->setFilter(q);
            table->setModel(model);

        }
        else
        {
            int f, t;
            for (int i =0; i < 5; i++)
            {
                if (from->text().toCaseFolded() == QString::fromStdString(g.cities[i]).toCaseFolded())
                {
                    f = i;
                }
                if (to->text().toCaseFolded() == QString::fromStdString(g.cities[i]).toCaseFolded())
                {
                    t = i;
                }
            }
            g.dijkstra(f, t);
            label->setText(QString::fromStdString(g.result));
        }
    if(ui->checkBox->isChecked())
    {
        Reservation::from = model->index(0,0).data().toString();
        Reservation::to = model->index(0,1).data().toString();
        Reservation::details = model->index(0,2).data().toString();
        Reservation::singleNO = model->index(0,3).data().toInt();
        Reservation::doubleNo = model->index(0,4).data().toInt();
        Reservation::tripleNO = model->index(0,5).data().toInt();
    }
    if(sh==false && ch==false)
    {
        QMessageBox::information(this,
                              tr(""),
                              tr("Please choose at least one search method."),
                              QMessageBox::Ok);
    }
    else
    {
        targetFlight *tar = new targetFlight ();
        this->close();
        tar->exec();
    }

}

void flights::on_checkBox_2_clicked()
{
    QCheckBox *shortest = ui->checkBox_2;
    if(shortest->isChecked())
    {
        sh = true;
    }
    else
    {
        sh = false;
    }
}

void flights::on_checkBox_clicked()
{
    QCheckBox *cheapest = ui->checkBox;
    if(cheapest->isChecked())
    {
        ch = true;
    }
    else
    {
        ch = false;
    }
}

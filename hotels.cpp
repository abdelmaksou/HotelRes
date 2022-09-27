#include "hotels.h"
#include "ui_hotels.h"
#include <QVector>
#include <QTableView>
vector <AVAhotels*> Hotels:: hotels;
Hotels::Hotels(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Hotels)
{
    ui->setupUi(this);
    ui->label_3->setVisible(false);
    ui->label_4->setVisible(false);
    ui->lineEdit_2->setVisible(false);


    QString path ;
            path="C:/Users/Ghada/Downloads/hmmmmm/Meme/citiesAndHotels.db";

            // open locally stored db file
           if(!createDB(path))
            {
                QMessageBox::critical(this,
                                      tr("Database not found"),
                                      tr("Database not found. The application will be closed."),
                                      QMessageBox::Ok);
                qApp->exit();
            }



/*
            // create and store db files
            QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE"); //not dbConnection
            db.setDatabaseName("citiesAndHotels");
            db.open();
            QSqlQuery query;
            query.exec("CREATE TABLE hotelsAndRooms (name varchar(255), address text, phone varchar(255), email text, checkIn real, checkOut real, starRating real, raterNum real, pool varchar(30), gym varchar(30), breakfast varchar(30), lunch varchar(30), dinner varchar(30), parking varchar(30), wifi varchar(30), gardenView varchar(30), poolView varchar(30), bar varchar(30), restaurant varchar(30), spa varchar(30), city varchar(255), singleP text, doubleP text, tripleP text, singleA text, doubleA text, tripleA text);");
            query.exec("INSERT INTO hotelsAndRooms (name, address, phone, email, checkIn, checkOut, starRating, raterNum,pool, gym, breakfast, lunch, dinner, parking, wifi, gardenView, poolView, bar, restaurant, spa, city, singleP, doubleP, tripleP, singleA, doubleA, tripleA) VALUES (\"Hôtel Elysées Union\",\"44 Rue de l'Amiral Hamelin, 75116, Paris, France\",\"33144341400\",\"info@elysees-union.com\",'15','0','4.7',' 16855', '0','0','1','0','0','0','1','1','0','1','1','0','Paris', '1546', '2598', '3164', '30', '20', '10');");
            query.exec("INSERT INTO hotelsAndRooms (name, address, phone, email, checkIn, checkOut, starRating, raterNum,pool, gym, breakfast, lunch, dinner, parking, wifi, gardenView, poolView, bar, restaurant, spa, city, singleP, doubleP, tripleP, singleA, doubleA, tripleA) VALUES (\"Hôtel Villa d'Estrées\",\"17 Rue Gît-le-Cœur, 75006, Paris, France\",\"33155427111\",\"RESA@VILLADESTREES.COM\",'14','11','4.8','4264', '0','0','1','0','0','0','1','1','0','1','1','0','Paris', '2585', '5436', '0', '30', '20', '10');");
            query.exec("INSERT INTO hotelsAndRooms (name, address, phone, email, checkIn, checkOut, starRating, raterNum,pool, gym, breakfast, lunch, dinner, parking, wifi, gardenView, poolView, bar, restaurant, spa, city, singleP, doubleP, tripleP, singleA, doubleA, tripleA) VALUES (\"Four Seasons Hotel George V\",\"31 Avenue George V, 75008 Paris, France\",'33149517000',\"reservation.paris@fourseasons.com\",'15','0','4.7','3293', '1','1','1','0','1','1','1','1','0','1','1','1','Paris', '16657', '19672', '25354', '30', '20', '10');");
            query.exec("INSERT INTO hotelsAndRooms (name, address, phone, email, checkIn, checkOut, starRating, raterNum,pool, gym, breakfast, lunch, dinner, parking, wifi, gardenView, poolView, bar, restaurant, spa, city, singleP, doubleP, tripleP, singleA, doubleA, tripleA) VALUES (\"ibis Berlin Kurfürstendamm\",\"Bayreuther Str. 39, 10787, Berlin, Germany\",\"49302888670\",\"H7961@ACCOR.COM\",'15','12','4.4','647', '0','0','1','1','0','1','1','0','0','1','1','0','Berlin', '855', '1250', '2500', '30', '20', '10');");
            query.exec("INSERT INTO hotelsAndRooms (name, address, phone, email, checkIn, checkOut, starRating, raterNum,pool, gym, breakfast, lunch, dinner, parking, wifi, gardenView, poolView, bar, restaurant, spa, city, singleP, doubleP, tripleP, singleA, doubleA, tripleA) VALUES (\"Occidental Atenea Mar\",\"Passeig García i Faria, 37-47, 08019, Barcelona, B, Spain\",\"34935316040\",\"ateneamar@barcelo.com\",'14','0','4.2','1375', '1','1','1','1','1','1','1','1','1','1','1','1','Barcelona', '1375', '1500', '1979', '30', '20', '10');");
            query.exec("INSERT INTO hotelsAndRooms (name, address, phone, email, checkIn, checkOut, starRating, raterNum,pool, gym, breakfast, lunch, dinner, parking, wifi, gardenView, poolView, bar, restaurant, spa, city, singleP, doubleP, tripleP, singleA, doubleA, tripleA) VALUES (\"H10 Cubik\",\"Via Laietana, 69, 08003, Barcelona, Spain\",\"34933202200\",\"reseravations@h10hotels.com\",'15','0','4.6','909', '1','0','1','1','1','0','1','0','1','1','1','0','Barcelona', '1500', '2065', '2683', '30', '20', '10');");
            query.exec("INSERT INTO hotelsAndRooms (name, address, phone, email, checkIn, checkOut, starRating, raterNum,pool, gym, breakfast, lunch, dinner, parking, wifi, gardenView, poolView, bar, restaurant, spa, city, singleP, doubleP, tripleP, singleA, doubleA, tripleA) VALUES (\"Hotel Nuevo Turinfo\",\"Carrer de Cabanes, 34, 08004, Barcelona, Spain\",\"34934432110\",\"info@hotelnuevotriunfo.com\",'14','0','3.9','385', '0','0','0','0','0','0','1','0','0','0','0','0','Barcelona', '774', '1016', '1599', '30', '20', '10');");
            query.exec("INSERT INTO hotelsAndRooms (name, address, phone, email, checkIn, checkOut, starRating, raterNum,pool, gym, breakfast, lunch, dinner, parking, wifi, gardenView, poolView, bar, restaurant, spa, city, singleP, doubleP, tripleP, singleA, doubleA, tripleA) VALUES (\"H10 Port Vell\",\"Pas de Sota Muralla, 9, 08003, Barcelona, Spain\",\"34933103065\",\"reseravations@h10hotels.com\",'15','0','4.5','531', '1','1','1','1','1','1','1','1','0','1','1','0','Barcelona', '2222', '2666', '2999', '30', '20', '10');");
            query.exec("INSERT INTO hotelsAndRooms (name, address, phone, email, checkIn, checkOut, starRating, raterNum,pool, gym, breakfast, lunch, dinner, parking, wifi, gardenView, poolView, bar, restaurant, spa, city, singleP, doubleP, tripleP, singleA, doubleA, tripleA) VALUES (\"Steigenberger Hotel Berlin\",\" Los-Angeles-Platz 1, 10789 Berlin, Germany\",\" 49 30 21270\",\" info@steigenberger.com\",'13','0','4.1','2077', '0','1','1','1','1','0','1','1','0','1','1','0','Berlin', '1500', '2456', '4360', '30', '20', '10');");
            query.exec("INSERT INTO hotelsAndRooms (name, address, phone, email, checkIn, checkOut, starRating, raterNum,pool, gym, breakfast, lunch, dinner, parking, wifi, gardenView, poolView, bar, restaurant, spa, city, singleP, doubleP, tripleP, singleA, doubleA, tripleA) VALUES (\"Mercure Hotel Berlin Wittenbergplatz\",\"Wittenbergpl. 3, 10789 Berlin, Germany\",\"49 30 2593550\",\"H9147@accor.com\",'11','0','4.7','14759', '1','1','1','0','1','0','1','1','1','1','0','1','Berlin', '12150', '20100', '35800', '30', '20', '10');");
            query.exec("INSERT INTO hotelsAndRooms (name, address, phone, email, checkIn, checkOut, starRating, raterNum,pool, gym, breakfast, lunch, dinner, parking, wifi, gardenView, poolView, bar, restaurant, spa, city, singleP, doubleP, tripleP, singleA, doubleA, tripleA) VALUES \"Deluxe Australian Hotel\",\" 23 Abd El-Khalik Tharwat, Bab Al Louq, Abdeen, Cairo 11111\",\"02 23958892\",\"info@deluxe.com\",'13','0','4.2',' 98', '0','0','1','0','1','0','1','1','0','0','1','0','Cairo', '150', '350', '500', '30', '20', '10');");
            query.exec("INSERT INTO hotelsAndRooms (name, address, phone, email, checkIn, checkOut, starRating, raterNum, pool, gym, breakfast, lunch, dinner, parking, wifi, gardenView, poolView, bar, restaurant, spa, city, singleP, doubleP, tripleP, singleA, doubleA, tripleA) VALUES (\"The Connaught\",\"Carlos Pl, London W1K 2AL, United Kingdom\",\" (44)20 7499 7070\",\"info@connaught.com\",'15','0','4.7','1654', '1','1','1','1','1','1','1','1','1','1','1','1','London', '12546','13498','15422' , '30', '20', '10');");
            query.exec("INSERT INTO hotelsAndRooms (name, address, phone, email, checkIn, checkOut, starRating, raterNum, pool, gym, breakfast, lunch, dinner, parking, wifi, gardenView, poolView, bar, restaurant, spa, city, singleP, doubleP, tripleP, singleA, doubleA, tripleA) VALUES (\"Fairmont Nile City Hotel\",\"Nile City Towers 2005 B Corniche El Nil، Cairo Gover0rate 11311\", \"02 24619494\",\" info@hotels.com\",'15','0','4.6',' 9779', '1','1','1','1','1','1','1','1','1','1','1','0','Cairo','1456','1954','2254','30', '20', '10');");
            query.exec("INSERT INTO hotelsAndRooms (name, address, phone, email, checkIn, checkOut, starRating, raterNum, pool, gym, breakfast, lunch, dinner, parking, wifi, gardenView, poolView, bar, restaurant, spa, city, singleP, doubleP, tripleP, singleA, doubleA, tripleA) VALUES (\"Sofitel Cairo Nile El Gezirah\",\"3 El Thawra Council St Zamalek Downtown, El Orman Giza,Cairo Governrate 11518\", \"02 27373737\",\" info@hotels.com\",'15','0','4.7',' 16855', '0','1','1','1','1','1','1','1','0','1','1','0','Cairo', '1456', '1954', '2254', '30', '20', '10');");
            query.exec("INSERT INTO hotelsAndRooms (name, address, phone, email, checkIn, checkOut, starRating, raterNum, pool, gym, breakfast, lunch, dinner, parking, wifi, gardenView, poolView, bar, restaurant, spa, city, singleP, doubleP, tripleP, singleA, doubleA, tripleA) VALUES (\"The Royal Horseguards\",\" 2 Whitehall Ct, London SW1A 2EJ, United Kingdom\",\"44 207523 5062\",\"reservationsadmin.royalhorseguards@guoman.co.uk\",'15','0','4.5',' 1987', '0','1','1','0','0','0','1','0','1','1','1','0','London', '4672' ,'6874', '9128',  '30', '20', '10');");
            query.exec("INSERT INTO hotelsAndRooms (name, address, phone, email, checkIn, checkOut, starRating, raterNum, pool, gym, breakfast, lunch, dinner, parking, wifi, gardenView, poolView, bar, restaurant, spa, city, singleP, doubleP, tripleP, singleA, doubleA, tripleA) VALUES (\"Nile Meridien Hotel\",\"20 Aisha Taimoria Cairo, 11511\",\" 02 27955942\",\" info@meridien.com\",'13','0','3',' 2645','0','0','0','0','0','0','1','1','0','0','0','0','Cairo', '900' , '1564' ,'2700', '30', '20', '10');");
            query.exec("INSERT INTO hotelsAndRooms (name, address, phone, email, checkIn, checkOut, starRating, raterNum, pool, gym, breakfast, lunch, dinner, parking, wifi, gardenView, poolView, bar, restaurant, spa, city, singleP, doubleP, tripleP, singleA, doubleA, tripleA) VALUES (\"TITANIC Comfort Berlin Mitte\",\"Elisabeth-Mara-Straße 4, 10117 Berlin, Germany\",\"49 30 76771870\",\"taitanic.info@comfort.com\",'15','0',' 3.8','1205', '1','0','1','0','1','0','1','0','1','1','0','1','London', '15500' , '17500' , '20000', '30', '20', '10');");
            query.exec("INSERT INTO hotelsAndRooms (name, address, phone, email, checkIn, checkOut, starRating, raterNum, pool, gym, breakfast, lunch, dinner, parking, wifi, gardenView, poolView, bar, restaurant, spa, city, singleP, doubleP, tripleP, singleA, doubleA, tripleA) VALUES (\"Ramses Hilton\",\"1115 Nile Corniche, Sharkas, Bulaq, Cairo Gover0rate\",\" 02 25777444\",\"info@ramses.com\",'15','0','4.3',' 98', '0','1','1','1','1','1','1','1','1','1','1','0','Cairo', '700' , '2854' , '4000','30', '20', '10');");
            query.exec("INSERT INTO hotelsAndRooms (name, address, phone, email, checkIn, checkOut, starRating, raterNum, pool, gym, breakfast, lunch, dinner, parking, wifi, gardenView, poolView, bar, restaurant, spa, city, singleP, doubleP, tripleP, singleA, doubleA, tripleA) VALUES (\"Hôtel de Paris Opéra\",\"37 Rue de Maubeuge, 75009 Paris, France\", \"33 1 48 78 62 68\",\"reservation@parishoteldeparis.com\",'13','0','3.2',' 206', '0','0','1','0','0','0','0','0','0','0','0','0','Paris','855', '1576', '2535', '30', '20', '10');");
            query.exec("INSERT INTO hotelsAndRooms (name, address, phone, email, checkIn, checkOut, starRating, raterNum, pool, gym, breakfast, lunch, dinner, parking, wifi, gardenView, poolView, bar, restaurant, spa, city, singleP, doubleP, tripleP, singleA, doubleA, tripleA) VALUES (\"Sofitel London St James\",\"6 Waterloo Pl, St. James's, London SW1Y 4AN, United Kingdom\", \"44 20 7747 2200\",\"h3144@sofitel.com\",'13','15','4.6','1591', '0','1','1','0','0','1','1','0','0','1','1','1','London', '7536', '8763', '10674', '30', '20', '10');");
            query.exec("INSERT INTO hotelsAndRooms (name, address, phone, email, checkIn, checkOut, starRating, raterNum, pool, gym, breakfast, lunch, dinner, parking, wifi, gardenView, poolView, bar, restaurant, spa, city, singleP, doubleP, tripleP, singleA, doubleA, tripleA) VALUES (\"Hotel Riu Plaza Berlin\",\"Wittenbergpl. 3, 10789 Berlin, Germany\", \"49 30 2809000\",\"hotel.plazaberlin@riu.com\",'14','0','4.7','18000', '1','1','1','0','1','0','0','1','0','1','1','1','Berlin', '15000', '17500', '20000', '30', '20', '10');");
            query.exec("INSERT INTO hotelsAndRooms (name, address, phone, email, checkIn, checkOut, starRating, raterNum, pool, gym, breakfast, lunch, dinner, parking, wifi, gardenView, poolView, bar, restaurant, spa, city, singleP, doubleP, tripleP, singleA, doubleA, tripleA) VALUES (\"Thistle Piccadilly\",\"Coventry St, London W1D 6BZ, United Kingdom\", \"(44)20 7523 5061\",\"info@hotels.com\",'14','11','4.4','500', '0','0','1','1','1','1','1','1','1','1','1','0','London', '1987', '2987', '4679', '30', '20', '10');");
            query.exec("INSERT INTO hotelsAndRooms (name, address, phone, email, checkIn, checkOut, starRating, raterNum, pool, gym, breakfast, lunch, dinner, parking, wifi, gardenView, poolView, bar, restaurant, spa, city, singleP, doubleP, tripleP, singleA, doubleA, tripleA) VALUES (\"Hôtel Ritz Paris\",\"15 Place Vendôme, 75001 Paris, France\",\"33143163030\",\"info@ritzparis.com\",'15','0','4.7','1449','0','1','1','0','0','1','1','1','0','1','1','0','Paris','18479', '20356', '21763', '30', '20', '10');");
            query.exec("INSERT INTO hotelsAndRooms (name, address, phone, email, checkIn, checkOut, starRating, raterNum, pool, gym, breakfast, lunch, dinner, parking, wifi, gardenView, poolView, bar, restaurant, spa, city, singleP, doubleP, tripleP, singleA, doubleA, tripleA) VALUES (\"Rosewood London\",\" 252 High Holborn, London WC1V 7EN, United Kingdom\",\"(44)20 7781 8888\",\"info@rosewood.com\",'15','0','4.7','2365', '1','1','1','1','1','1','1','1','1','1','1','1','London', '9989', '12456', '13215', '30', '20', '10');");
            query.exec("CREATE TABLE cities (city varchar(255), banned varchar(255), x real, y real, hotels text, country varchar(255), port text, airport text);");
            query.exec("INSERT INTO cities (city, banned, x, y, hotels, country, port, airport) VALUES ('Paris', 'London', '49', '2', \"Four Seasons Hotel George V-Hôtel Villa d'Estrées-Hôtel Elysées Union-Hôtel Ritz Paris-Hôtel de Paris Opéra\", 'France', \"Le Havre\" , \"Charles de Gaulle\"), ('Barcelona', '', '41', '2', \"H10 Port Vell-Hotel Nuevo Turinfo-H10 Cubik-Occidental Atenea Mar\", 'Spain', 'Tarifa' , 'Reus' ), ('Cairo', 'Berlin', '30', '31', \"Deluxe Australian Hotel Cairo-Ramses Hilton-Nile Meridien Hotel-Sofitel Cairo Nile El Gezirah-Fairmont Nile City Hotel\", 'Egypt' ,  \"Port Said East\" , \"Cairo International Airport\"), ('Berlin', '', '53', '13', \"ibis Berlin Kurfürstendamm-Steigenberger Hotel Berlin-Mercure Hotel Berlin Wittenbergplatz-Hotel Riu Plaza Berlin-TITANIC Comfort Berlin Mitte\", 'Germany' , \"EB SEELOEWE\" , \"Berlin Schönefeld\" ), ('London', '', '52', '0', \"Sofitel London St James-The Royal Horseguards-The Connaught-Rosewood London-Thistle Piccadilly\", 'England' , 'Felixstowe' , 'Heathrow');");

                        if(!createDB(path))
            {
                QMessageBox::critical(this,
                                      tr("Database not found"),
                                      tr("Database not found. The application will be closed."),
                                      QMessageBox::Ok);
                qApp->exit();
            }
*/
}


Hotels::~Hotels()
{
    delete ui;
}

bool Hotels::createDB(QString dbname)
{
    db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName(dbname);

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

            model = new QSqlTableModel(this,db);
            model->setTable("hotelsAndRooms");
            model->setEditStrategy(QSqlTableModel::OnFieldChange);

            model->select();


        }
        else
        {
            return false;
        }

        return true;
}

void Hotels::on_comboBox_currentIndexChanged(const QString &arg1)
{
    ui->label_2->setText(arg1);
    if (arg1=="Price Range")
    {
        ui->label_3->setVisible(true);
        ui->label_4->setVisible(true);
        ui->lineEdit_2->setVisible(true);
    }
    else
    {
        ui->label_3->setVisible(false);
        ui->label_4->setVisible(false);
        ui->lineEdit_2->setVisible(false);
    }

}

void Hotels::on_pushButton_clicked()
{
    choice *ch = new choice ();
    this->close();
    ch->exec();
}

void Hotels::searchCity(QString s)
{
       QString city = "city LIKE '%" + s + "%' OR city LIKE '%" + s + "' OR city LIKE '" + s + "%'";
       model->setFilter(city);

}

void Hotels::searchHotel(QString s)
{
       QString hotel = "name LIKE '%" + s + "%'";
       model->setFilter(hotel);
}
void Hotels::searchPriceRange(double s, double t)
{
    QString priceL = QString{ "singleP <= %1" }.arg(s-2) + QString{ " AND singleP >= %1" }.arg(t+2);
    QString priceH = QString{ " AND tripleP <= %1" }.arg(s-2) + QString{ " AND tripleP >= %1" }.arg(t+2);

       model->setFilter(priceL+priceH);
}
void Hotels::searchStarRating(double s)
{
       QString star = QString{ "starRating <= %1" }.arg(s+0.2) + QString{ " AND starRating >= %1" }.arg(s-0.2);
         //QString star = QString{"starRating < %1"}.arg(s);
       model->setFilter(star);
}

void Hotels::ViewDetails()
{
    QTableView *view=ui->tableView;
    view->setModel(model);
    //setHidden(view);

    if(ui->lineEdit->text()!="")
    {
        for (int i=0; i< model->rowCount(); i++)
        {
            //QString content=model->index(i,0).data().toString();
           //
            AVAhotels* av = new AVAhotels(model->index(i,0).data().toString(),model->index(i,1).data().toString(),model->index(i,2).data().toString(),model->index(i,3).data().toString(),model->index(i,4).data().toString(),model->index(i,5).data().toString(),model->index(i,6).data().toDouble(),model->index(i,7).data().toInt(),model->index(i,20).data().toString(),model->index(i,21).data().toDouble(),model->index(i,22).data().toDouble(),model->index(i,23).data().toDouble(),model->index(i,24).data().toInt(),model->index(i,25).data().toInt(),model->index(i,26).data().toInt());
            av->setAminities(model->index(i,8).data().toInt(),model->index(i,9).data().toInt(),model->index(i,10).data().toInt(),model->index(i,11).data().toInt(),model->index(i,12).data().toInt(),model->index(i,13).data().toInt(),model->index(i,14).data().toInt(),model->index(i,15).data().toInt(),model->index(i,16).data().toInt(),model->index(i,17).data().toInt(),model->index(i,18).data().toInt(),model->index(i,19).data().toInt());
            av->setSingleRooms(30);
            av->setDoubleRooms(20);
            av->setTripleRooms(10);
            Hotels::hotels.push_back(av);

         /*   QString name=  Hotels::hotels.back()->getName();
            QString text = ui->label_5->text();
            ui->label_5->setText(text+name);*/

        }

    }


    Reservation *reservation= new Reservation();
    this->close();
   reservation->exec();

}

void Hotels::on_pushButton_2_clicked()
{
    QLineEdit *from = ui->lineEdit;
    QLineEdit *to = ui->lineEdit_2;
    QComboBox *combo = ui->comboBox;
    switch (combo->currentIndex()) {
    case 0:
        searchHotel(from->text());
        break;
    case 1:
        searchCity(from->text());
        break;
    case 2:
        searchPriceRange(from->text().toDouble(), to->text().toDouble());
        break;
    case 3:
        searchStarRating(from->text().toDouble());
        break;
    default:
        searchHotel(from->text());
        break;
    }
    ViewDetails();
 }

/*void Hotels::on_treeView_clicked(const QModelIndex &index)
{
    QMessageBox msgBox;
    msgBox.setText("Hotel reservation.");
    msgBox.setInformativeText("Do you want to save your changes?");
    msgBox.setStandardButtons(QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
    msgBox.setDefaultButton(QMessageBox::Save);
    int ret = msgBox.exec();
}

*/

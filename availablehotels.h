#ifndef AVAILABLEHOTELS_H
#define AVAILABLEHOTELS_H
#include "aminities.h"
#include "rooms.h"
#include <QString>
#include <QWidget>
#include <vector>
#include <QList>

using namespace std;

class AVAhotels : public QWidget
{
    Q_OBJECT
public:
    double singleP;
    double doubleP;
    double tripleP;
    explicit AVAhotels(QWidget *parent = nullptr);
    void setAddress ( QString Add);
        QString getAddress();
        void setEmail ( QString email);
        QString getEmail ();
        void setInDate( QString InD);
        QString getInDate();
        void setOutDate ( QString OutD);
        QString getOutDate();
        void setName (QString N);
        QString getName ();
        void setPhone ( QString ph);
        QString getPhone ();
        QString getCity ();
        void setRatersNum( int RN);
        int getRatersNum();
        void setPriceRange ( double PR);
        double getPriceRange ();
        void setStarRating ( double SR);
        double getStarRating();
        void setSingleRooms(int numavailable );
        void setDoubleRooms(int numavailable  );
        void setTripleRooms(int numavailable  );
        Rooms* getRooms (int num);
        void setAminities (int,int,int,int,int,int,int,int,int,int,int,int);
        Aminities* getAminities();
        vector <Rooms*> Single ;
        vector <Rooms*> Double;
        vector <Rooms*> Triple;
        double singleA;
        int doubleA;
        int tripleA;
        Aminities aminities;
        QString name;
        QString address;
        QString phone;
        QString Email;
        QString inDate;
        QString outDate;
        QString city;

        AVAhotels(QString,QString,QString,QString,QString,QString, double, int, QString, double,double,double,int,int,int);

signals:
private:


        double starRating;
        int ratersNum;
        int i=101;
};

#endif // HOTELS_H

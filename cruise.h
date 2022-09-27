#ifndef CRUISE_H
#define CRUISE_H
#include "aminities.h"
#include "rooms.h"
#include <vector>
#include <QWidget>

using namespace std;

class AVACruise : public QWidget
{
    Q_OBJECT
public:
    explicit AVACruise(QWidget *parent = nullptr);
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
        void setRatersNum( int RN);
        int getRatersNum();
        void setPriceRange ( double PR);
        double getPriceRange ();
        void setStarRating ( double SR);
        double getStarRating();
        void setSingleRooms(int numavailable );
        void setDoubleRooms(int numavailable );
        void setTripleRooms(int numavailable );
        Rooms* getRooms (int num);
        void setAminities ( bool p, bool g, bool BF, bool L, bool D, bool Pk, bool wifi, bool GV, bool PV, bool b, bool R, bool s);
        Aminities* getAminities();
        vector <Rooms*> Single ;
        vector <Rooms*> Double;
        vector <Rooms*> Triple;
        AVACruise(QString,QString,QString,QString,QString,QString, double, int, QString, double,double,double,int,int,int);
        double singleP;
        double doubleP;
        double tripleP;
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
        double starRating;
        double priceRange;
        int ratersNum;




signals:
private:

        int i=200;

};

#endif // CRUISE_H

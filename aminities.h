#ifndef AMINITIES_HPP
#define AMINITIES_HPP

#include <QObject>
#include <QWidget>

class Aminities : public QWidget
{
    Q_OBJECT
public:
    explicit Aminities(QWidget *parent = nullptr);
    Aminities( bool p, bool g, bool BF, bool L, bool D, bool Pk, bool wifi, bool GV, bool PV, bool b, bool R, bool s);
//    Aminities ( const Aminities &) = default;
//    Aminities (const  Aminities &temp);
    void setaminities(int,int,int,int,int,int,int,int,int,int,int,int);
        bool getPool();
        bool getGym();
        bool getBreakfast();
        bool getLunch();
        bool getDinner();
        bool getParking();
        bool getWiFi();
        bool getGardenView();
        bool getPoolView();
        bool getBar();
        bool getRestaurant();
        bool getSPA();
        bool pool;
            bool gym;
            bool Breakfast;
            bool Lunch;
            bool Dinner;
            bool Parking;
            bool WiFi;
            bool GardenView;
            bool PoolView;
            bool bar;
            bool Restaurant;
            bool SPA;

signals:

public:


};

#endif // AMINITIES_HPP

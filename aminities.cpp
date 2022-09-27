#include "aminities.h"

Aminities::Aminities(QWidget *parent) : QWidget(parent)
{
}

using namespace std;

Aminities :: Aminities (bool p, bool g, bool BF, bool L, bool D, bool Pk, bool wifi, bool GV, bool PV, bool b, bool R, bool s)
{
    pool = p;
    gym = g;
    Breakfast = BF;
    Lunch = L;
    Dinner = D;
    Parking = Pk;
    WiFi = wifi;
    GardenView = GV;
    PoolView = PV;
    bar = b;
    Restaurant = R;
    SPA = s;
}

void Aminities :: setaminities (int p, int g, int BF, int L, int D, int Pk, int wifi, int GV, int PV, int b, int R, int s)
{
    pool = p;
    gym = g;
    Breakfast = BF;
    Lunch = L;
    Dinner = D;
    Parking = Pk;
    WiFi = wifi;
    GardenView = GV;
    PoolView = PV;
    bar = b;
    Restaurant = R;
    SPA = s;
}
/*Aminities :: Aminities (const  Aminities &temp)
{
    pool = temp.pool;
    gym = temp.gym;
    Breakfast = temp.Breakfast;
    Lunch = temp.Lunch;
    Dinner = temp.Dinner;
    Parking = temp.Parking;
    WiFi = temp.WiFi;
    GardenView = temp.GardenView;
    PoolView = temp.PoolView;
    bar = temp.bar;
    Restaurant = temp.Restaurant;
    SPA = temp.SPA;
}
*/
bool Aminities::getPool() { return pool; }
bool Aminities::getGym() { return gym; }
bool Aminities::getBreakfast() { return Breakfast; }
bool Aminities::getLunch() { return Lunch; }
bool Aminities::getDinner() { return Dinner; }
bool Aminities::getParking() { return Parking; }
bool Aminities::getWiFi() { return WiFi; }
bool Aminities::getGardenView() { return GardenView; }
bool Aminities::getPoolView() { return PoolView; }
bool Aminities::getBar() { return bar; }
bool Aminities::getRestaurant() { return Restaurant; }
bool Aminities::getSPA() { return SPA; }

#include "rooms.h"
#include <QString>
Rooms::Rooms(QWidget *parent) : QWidget(parent)
{

}


using namespace std;

Rooms :: Rooms (int ad, int ch, bool ava, double p , QString t, int n)
{
    adults = ad;
    children = ch;
    available = ava;
    price = p;
    type = t;
    number = n;
}

void Rooms :: setrooms(int ad, int ch, bool ava, double p, QString t, int n)
{
    adults = ad;
    children = ch;
    available = ava;
    price = p;
    type = t;
    number = n;
}
void Rooms::setType(QString t) { type = t; }
QString Rooms::getType() { return type;}
void Rooms::setNumber( int N) { number = N;}
int Rooms:: getNumber() { return number; }
void Rooms:: setAdults( int ad ) { adults = ad; }
int Rooms:: getAdults() { return adults; }
void Rooms:: setChildren( int ch) { children = ch; }
int Rooms:: getChildren() { return children;}
void Rooms::setPrice(double p) { price = p; }
double Rooms:: getPrice() { return price; }
void Rooms:: setAvailable( bool ava) { available = ava; }
bool Rooms:: getAvailable() { return available; }

#ifndef ROOMS_H
#define ROOMS_H

#include <QObject>
#include <QWidget>
#include <QString>

class Rooms :  public QWidget
{
    Q_OBJECT
public:
    explicit Rooms(QWidget *parent = nullptr);
    Rooms (int ad, int ch, bool ava, double p , QString t, int n );
       void setrooms(int ad, int ch, bool ava, double p , QString t, int n);
       QString getType();
       void setType( QString t );
       int getNumber();
       void setNumber( int N);
       int getAdults();
       void setAdults( int ad);
       int getChildren();
       void setChildren( int ch);
       double getPrice ();
       void setPrice( double p);
       bool getAvailable();
       void setAvailable( bool ava);

signals:

private:
    int adults;
    int children;
    bool available;
    double price;
    QString type;
    int number;
};

#endif // ROOMS_HPP

/*room(int , int , QString , QString );
int adults,children;
bool available;
double price;
QString type,number;
*/

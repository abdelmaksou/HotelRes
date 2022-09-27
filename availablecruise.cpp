#include "availablecruise.h"
#include "ui_availablecruise.h"
#include "availablehotels.h"
#include "rooms.h"
#include "aminities.h"

availableCruise::availableCruise(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::availableCruise)
{
    ui->setupUi(this);
}

availableCruise::~availableCruise()
{
    delete ui;
}


#include "availablehotels.h"
#include "rooms.h"
#include "aminities.h"

void availableCruise:: setAddress(QString Add) {address = Add;}
QString availableCruise::getAddress() { return address;}
void availableCruise:: setEmail(QString email) { Email = email; }
QString availableCruise:: getEmail() { return Email; }
void availableCruise::setInDate(QString InD) { inDate = InD; }
QString availableCruise:: getInDate() { return inDate;}
void availableCruise::setOutDate(QString OutD) { outDate = OutD; }
QString availableCruise:: getOutDate() { return outDate; }
void availableCruise:: setName(QString N) { name = N; }
QString availableCruise:: getName() { return name;}
void availableCruise:: setPhone( QString ph) { phone = ph;}
QString availableCruise:: getPhone() { return phone;}
void availableCruise:: setRatersNum( int RN) { ratersNum = RN; }
int availableCruise:: getRatersNum() { return ratersNum; }
QString availableCruise::getCity() {return city;}

void availableCruise:: setStarRating (double SR) { starRating = SR; }
double availableCruise:: getStarRating() { return starRating; }

availableCruise::availableCruise(QString name,QString address,QString phone,QString email,QString inTime,QString outTime,double rating, int rateNum, QString city,  double singleP,double doubleP,double tripleP,int singleA,int doubleA,int tripleA){
    this->name=name;    this->address=address;  this->phone=phone;  this->Email=email;  this->inDate=inTime;    this->outDate=outTime; this->ratersNum=rateNum;
    this->starRating= rating; this->city=city;    this->singleP=singleP;  this->doubleP=doubleP;  this->tripleP=tripleP;  this->singleA=singleA;  this->doubleA= doubleA; this->tripleA=tripleA;
}



void availableCruise:: setSingleRooms(int numavailable)
{

    //it= Single.begin();
    Rooms *rY= new Rooms(1,1,true,singleP,"Single",i);
    Rooms *rN= new Rooms(1,1,false,singleP,"Single",i);
    int j =1; int z=0;
              do{

                if (j <= numavailable)
                {

                Single.push_back(rY);
                j++;
                }
                else
                {
                 Single.push_back(rN);
                }
                ++i;
                ++z;
        } while (z<30);

}

void availableCruise :: setDoubleRooms(int numavailable)
{
    Rooms *rY= new Rooms(1,1,true,singleP,"Double",i);
    Rooms *rN= new Rooms(1,1,false,singleP,"Double",i);
    int j =1; int z=0;
              do{
        if (j <= numavailable)
        {

        Double.push_back(rY);
        j++;
        }
        else
        {
         Double.push_back(rN);
        }
        ++i;
        ++z;
        } while (z<20);
}

void availableCruise :: setTripleRooms(int numavailable )
{
    Rooms *rY= new Rooms(1,1,true,singleP,"Triple",i);
    Rooms *rN= new Rooms(1,1,false,singleP,"Triple",i);
    int j =1;  int z=0;
              do{
        if (j <= numavailable)
        {

        Double.push_back(rY);
        j++;
        }
        else
        {
         Double.push_back(rN);
        }
        ++i;
        ++z;
        } while (z<10);
}

 Rooms* availableCruise :: getRooms( int num )
{
   if (num>=100 && num<130)
       for (int i=0; i<30; i++)  if (Single[i]->getNumber()==num) return Single[i];
   if (num>=130 && num<150)
       for (int i=0; i<20; i++)  if (Double[i]->getNumber()==num) return Double[i];
   if (num>=150 && num<160)
       for (int i=0; i<10; i++)  if (Triple[i]->getNumber()==num) return Triple[i];
   return NULL;

}


void availableCruise:: setAminities(int p, int g, int BF, int L, int D, int PK, int wifi, int GV, int PV, int P, int R, int s)
{
    aminities.setaminities(p, g,BF, L ,D , PK , wifi, GV, PV, P , R ,s);
}


Aminities* availableCruise :: getAminities()
{
    Aminities *am = &aminities;
    return am;
}

/////////////////////////////////////////////////////////////////*************************///////////////////////

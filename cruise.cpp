#include "cruise.h"
#include "aminities.h"
#include "rooms.h"

AVACruise::AVACruise(QWidget *parent) : QWidget(parent)
{
}

void AVACruise:: setAddress(QString Add) {address = Add;}
QString AVACruise::getAddress() { return address;}
void AVACruise:: setEmail(QString email) { Email = email; }
QString AVACruise:: getEmail() { return Email; }
void AVACruise::setInDate(QString InD) { inDate = InD; }
QString AVACruise:: getInDate() { return inDate;}
void AVACruise::setOutDate(QString OutD) { outDate = OutD; }
QString AVACruise:: getOutDate() { return outDate; }
void AVACruise:: setName(QString N) { name = N; }
QString AVACruise:: getName() { return name;}
void AVACruise:: setPhone( QString ph) { phone = ph;}
QString AVACruise:: getPhone() { return phone;}
void AVACruise:: setRatersNum( int RN) { ratersNum = RN; }
int AVACruise:: getRatersNum() { return ratersNum; }
void AVACruise:: setPriceRange(double PR) { priceRange = PR; }
double AVACruise:: getPriceRange() { return priceRange; }
void AVACruise:: setStarRating (double SR) { starRating = SR; }
double AVACruise:: getStarRating() { return starRating; }


AVACruise::AVACruise(QString name,QString address,QString phone,QString email,QString inTime,QString outTime,double rating, int rateNum, QString city,  double singleP,double doubleP,double tripleP,int singleA,int doubleA,int tripleA){
    this->name=name;    this->address=address;  this->phone=phone;  this->Email=email;  this->inDate=inTime;    this->outDate=outTime; this->ratersNum=rateNum;
    this->starRating= rating; this->city=city;    this->singleP=singleP;  this->doubleP=doubleP;  this->tripleP=tripleP;  this->singleA=singleA;  this->doubleA= doubleA; this->tripleA=tripleA;
}

void AVACruise:: setSingleRooms(int numavailable)
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

void AVACruise :: setDoubleRooms(int numavailable)
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

void AVACruise :: setTripleRooms(int numavailable )
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

 Rooms* AVACruise :: getRooms( int num )
{
   if (num>=200 && num<230)
       for (int i=0; i<30; i++)  if (Single[i]->getNumber()==num) return Single[i];
   if (num>=230 && num<250)
       for (int i=0; i<20; i++)  if (Double[i]->getNumber()==num) return Double[i];
   if (num>=250 && num<260)
       for (int i=0; i<10; i++)  if (Triple[i]->getNumber()==num) return Triple[i];
   return NULL;

}


void AVACruise:: setAminities(bool p, bool g, bool BF, bool L, bool D, bool PK, bool wifi, bool GV, bool PV, bool P, bool R, bool s)
{
    aminities.setaminities(p, g,BF, L ,D , PK , wifi, GV, PV, P , R ,s);
}


Aminities* AVACruise :: getAminities()
{
    return &aminities;
}

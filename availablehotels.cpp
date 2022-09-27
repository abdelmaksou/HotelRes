#include "availablehotels.h"
#include "rooms.h"
#include "aminities.h"
AVAhotels::AVAhotels(QWidget *parent) : QWidget(parent)
{

}

void AVAhotels:: setAddress(QString Add) {address = Add;}
QString AVAhotels::getAddress() { return address;}
void AVAhotels:: setEmail(QString email) { Email = email; }
QString AVAhotels:: getEmail() { return Email; }
void AVAhotels::setInDate(QString InD) { inDate = InD; }
QString AVAhotels:: getInDate() { return inDate;}
void AVAhotels::setOutDate(QString OutD) { outDate = OutD; }
QString AVAhotels:: getOutDate() { return outDate; }
void AVAhotels:: setName(QString N) { name = N; }
QString AVAhotels:: getName() { return name;}
void AVAhotels:: setPhone( QString ph) { phone = ph;}
QString AVAhotels:: getPhone() { return phone;}
void AVAhotels:: setRatersNum( int RN) { ratersNum = RN; }
int AVAhotels:: getRatersNum() { return ratersNum; }
QString AVAhotels::getCity() {return city;}

void AVAhotels:: setStarRating (double SR) { starRating = SR; }
double AVAhotels:: getStarRating() { return starRating; }

AVAhotels::AVAhotels(QString name,QString address,QString phone,QString email,QString inTime,QString outTime,double rating, int rateNum, QString city,  double singleP,double doubleP,double tripleP,int singleA,int doubleA,int tripleA){
    this->name=name;    this->address=address;  this->phone=phone;  this->Email=email;  this->inDate=inTime;    this->outDate=outTime; this->ratersNum=rateNum;
    this->starRating= rating; this->city=city;    this->singleP=singleP;  this->doubleP=doubleP;  this->tripleP=tripleP;  this->singleA=singleA;  this->doubleA= doubleA; this->tripleA=tripleA;
}



void AVAhotels:: setSingleRooms(int numavailable)
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

void AVAhotels :: setDoubleRooms(int numavailable)
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

void AVAhotels :: setTripleRooms(int numavailable )
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

 Rooms* AVAhotels :: getRooms( int num )
{
   if (num>=100 && num<130)
       for (int i=0; i<30; i++)  if (Single[i]->getNumber()==num) return Single[i];
   if (num>=130 && num<150)
       for (int i=0; i<20; i++)  if (Double[i]->getNumber()==num) return Double[i];
   if (num>=150 && num<160)
       for (int i=0; i<10; i++)  if (Triple[i]->getNumber()==num) return Triple[i];
   return NULL;

}


void AVAhotels:: setAminities(int p, int g, int BF, int L, int D, int PK, int wifi, int GV, int PV, int P, int R, int s)
{
    aminities.setaminities(p, g,BF, L ,D , PK , wifi, GV, PV, P , R ,s);
}


Aminities* AVAhotels :: getAminities()
{
    Aminities *am = &aminities;
    return am;
}

#ifndef RESERVATION_H
#define RESERVATION_H
#include "targethotel.h"
#include <QDialog>
#include <QDate>
#include "hotels.h"
#include "availablecruise.h"
namespace Ui {
class Reservation;
}

class Reservation : public QDialog
{
    Q_OBJECT

public:
    static string* tripNames;
    static QString* s1[];


    static int count;
    static int choice;
    static int roomType;
    static int singleNO;
    static int doubleNo;
    static int tripleNO;
    static QString from;
    static QString to;
    static QString details;
    static QDate in;
    static QDate out;
    static QDateTime flight;
    static int price;
    static bool discount;
    static bool isFlight;
    static int id;
    static int points;
    static int reward;
    static bool cruise;
    Reservation (vector<availableCruise*>,QWidget *parent = nullptr);
    explicit Reservation(QWidget *parent = nullptr);
    ~Reservation();

private slots:

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();
    void on_pushButton_6_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_32_clicked();
    void on_pushButton_7_clicked();
    void on_pushButton_8_clicked();
    void on_pushButton_35_clicked();
    void on_pushButton_33_clicked();
    void on_pushButton_34_clicked();
    void on_pushButton_38_clicked();
    void on_pushButton_36_clicked();
    void on_pushButton_37_clicked();
    void on_pushButton_41_clicked();
    void on_pushButton_39_clicked();
    void on_pushButton_40_clicked();


    void on_pushButton_42_clicked();

private:
    Ui::Reservation *ui;
};

#endif // RESERVATION_H

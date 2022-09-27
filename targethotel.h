#ifndef TARGETHOTEL_H
#define TARGETHOTEL_H

#include <QDialog>
#include "hotels.h"
#include "reservation.h"
#include "payment.h"
#include "choice.h"
#include "invoice.h"
#include "availablecruise.h"
namespace Ui {
class targetHotel;
}

class targetHotel : public QDialog
{
    Q_OBJECT

public:
    QSqlTableModel *model;
    QSqlDatabase db;
    bool createDB(QString dbname);

    int x;
    targetHotel (QString*,QWidget *parent = nullptr);
    explicit targetHotel(QWidget *parent = nullptr);
    ~targetHotel();

private slots:
    void on_dateEdit_userDateChanged(const QDate &date);

    void on_dateEdit_2_userDateChanged(const QDate &date);


    void on_pushButton_clicked();

    void on_checkBox_13_stateChanged(int arg1);

    void on_pushButton_3_clicked();

    void on_spinBox_valueChanged(const QString &arg1);

    void on_spinBox_valueChanged(int arg1);

private:
    Ui::targetHotel *ui;
};

#endif // TARGETHOTEL_H

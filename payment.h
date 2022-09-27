#ifndef PAYMENT_H
#define PAYMENT_H

#include <QDialog>
#include "hotels.h"
#include "availablehotels.h"
#include "hotels.h"
#include "choice.h"
#include "invoice.h"
#include "availablecruise.h"
namespace Ui {
class Payment;
}

class Payment : public QDialog
{
    Q_OBJECT

public:
    QSqlDatabase db;
    static availableCruise* av;
    QSqlTableModel* model;
    explicit Payment(QWidget *parent = nullptr);
    ~Payment();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Payment *ui;
};

#endif // PAYMENT_H

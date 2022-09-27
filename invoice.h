#ifndef INVOICE_H
#define INVOICE_H

#include <QDialog>
#include "availablehotels.h"
#include "reservation.h"

namespace Ui {
class Invoice;
}

class Invoice : public QDialog
{
    Q_OBJECT

public:
    QSqlTableModel* model;
   // Invoice (availableCruise* av ,QWidget *parent = nullptr);
    explicit Invoice(QWidget *parent = nullptr);
    ~Invoice();

private slots:
    void on_pushButton_clicked();
    bool checkDB(QSqlDatabase db, QString db1, QString db2);

private:
    Ui::Invoice *ui;
};

#endif // INVOICE_H

#ifndef CHOICE_H
#define CHOICE_H

#include <QDialog>
#include "hotels.h"
#include "mainwindow.h"
#include "flights.h"
#include "customerprofile.h"
#include "cruisesearch.h"
namespace Ui {
class choice;
}

class choice : public QDialog
{
    Q_OBJECT

public:
    explicit choice(QWidget *parent = nullptr);
    ~choice();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::choice *ui;
};

#endif // CHOICE_H

#ifndef CRUISESEARCH_H
#define CRUISESEARCH_H

#include <QDialog>
#include <QSqlTableModel>
#include <QSqlDatabase>
#include <QSqlQuery>
#include "choice.h"
#include <cruise.h>
namespace Ui {
class cruiseSearch;
}

class cruiseSearch : public QDialog
{
    Q_OBJECT

public:
    QSqlTableModel *model;
    QSqlDatabase db;
    void ViewDetails();
    void searchCity(QString s);
    void searchHotel(QString s);
    void searchPriceRange(double s, double d);
    void searchStarRating(double s);
    bool createDB(QString dbname);







    explicit cruiseSearch(QWidget *parent = nullptr);
    ~cruiseSearch();

private slots:
    void on_comboBox_currentIndexChanged(const QString &arg1);

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::cruiseSearch *ui;
};

#endif // CRUISESEARCH_H

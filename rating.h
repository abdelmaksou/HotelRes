#ifndef RATING_H
#define RATING_H

#include <QDialog>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlDriver>
#include <QSqlTableModel>
#include <QVariant>

namespace Ui {
class Rating;
}

class Rating : public QDialog
{
    Q_OBJECT

public:
    explicit Rating(QWidget *parent = nullptr);
    ~Rating();
    bool checkDB(QSqlDatabase db);

private slots:
    void on_pushButton_2_clicked();

private:
    Ui::Rating *ui;
};

#endif // RATING_H

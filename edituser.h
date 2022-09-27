#ifndef EDITUSER_H
#define EDITUSER_H

#include <QDialog>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlDriver>
#include <QSqlTableModel>
#include <QVariant>
#include <QMessageBox>

namespace Ui {
class edituser;
}

class edituser : public QDialog
{
    Q_OBJECT

public:
    explicit edituser(QWidget *parent = nullptr);
    ~edituser();
    QSqlDatabase db;
    bool checkDB(QSqlDatabase db);


private slots:
    void on_change_clicked();

    void on_comboBox_currentIndexChanged(int index);

private:
    Ui::edituser *ui;
};

#endif // EDITUSER_H

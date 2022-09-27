#ifndef HISTORY_H
#define HISTORY_H

#include "existinguser.h"
#include <QDialog>
#include <QPushButton>


namespace Ui {
class History;
}

class History : public QDialog
{
    Q_OBJECT

public:
    explicit History(QWidget *parent = nullptr);
    void findUser();
    ~History();

private slots:

    void on_tableView_doubleClicked(const QModelIndex &index);
    void on_tableView_2_doubleClicked(const QModelIndex &index);

    void on_pushButton_clicked();

private:
    Ui::History *ui;
};

#endif // HISTORY_H

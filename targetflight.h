#ifndef TARGETFLIGHT_H
#define TARGETFLIGHT_H

#include <QDialog>
#include "payment.h"


namespace Ui {
class targetFlight;
}

class targetFlight : public QDialog
{
    Q_OBJECT

public:
    explicit targetFlight(QWidget *parent = nullptr);
    ~targetFlight();

private slots:
    void on_pushButton_clicked();

    void on_comboBox_currentIndexChanged(int index);


private:
    Ui::targetFlight *ui;
};

#endif // TARGETFLIGHT_H

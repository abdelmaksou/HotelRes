#ifndef PROMO_H
#define PROMO_H

#include <QDialog>

namespace Ui {
class promo;
}

class promo : public QDialog
{
    Q_OBJECT

public:
    explicit promo(QWidget *parent = nullptr);
    ~promo();

private:
    Ui::promo *ui;
};

#endif // PROMO_H

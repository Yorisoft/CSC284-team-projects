#ifndef UPDATECREDITOR_H
#define UPDATECREDITOR_H
#include "transactionpage.h"

#include <QDialog>

namespace Ui {
class Updatecreditor;
}

class Updatecreditor : public QDialog
{
    Q_OBJECT

public:
    explicit Updatecreditor(QWidget *parent = nullptr);
    ~Updatecreditor();

private slots:
    void on_pushButton_BackToTransaction_clicked();

private:
    Ui::Updatecreditor *ui;
    Updatecreditor *updatecreditos;
    TransactionPage  *transactionpage;
};

#endif // UPDATECREDITOR_H

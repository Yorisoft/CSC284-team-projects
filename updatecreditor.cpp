#include "updatecreditor.h"
#include "ui_updatecreditor.h"

Updatecreditor::Updatecreditor(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Updatecreditor)
{
    ui->setupUi(this);
}

Updatecreditor::~Updatecreditor()
{
    delete ui;
}

void Updatecreditor::on_pushButton_BackToTransaction_clicked()
{
    hide();
    transactionpage = new TransactionPage(this);
    transactionpage ->show();


}

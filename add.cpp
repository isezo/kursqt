#include "add.h"
#include "ui_add.h"

Add::Add(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Add)
{
    ui->setupUi(this);
    ui->lineEdit->setPlaceholderText("Номер постановления");
    ui->lineEdit_2->setPlaceholderText("Номер авто");
    ui->lineEdit_4->setPlaceholderText("Пункт нарушения");
}

Add::~Add()
{
    delete ui;
}

QString Add::post()
{
    return ui->lineEdit->text();
}

QString Add::n_avto()
{
    return ui->lineEdit_2->text();
}

QString Add::foul()
{
    return ui->lineEdit_4->text();
}

void Add::on_pushButton_2_clicked()
{
    this->close();
    emit firstWindow();
}

void Add::on_pushButton_clicked()
{
    ui->lineEdit->setText(NULL);
    ui->lineEdit_2->setText(NULL);
    ui->lineEdit_4->setText(NULL);
    this->close();
    emit firstWindow();
}

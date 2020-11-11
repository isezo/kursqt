#include "addtc.h"
#include "ui_addtc.h"

Addtc::Addtc(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Addtc)
{
    ui->setupUi(this);
    ui->frame_2->hide();
    ui->lineEdit_6->setPlaceholderText("Марка авто");
    ui->lineEdit_7->setPlaceholderText("Номер авто");
    ui->lineEdit_2->setPlaceholderText("ФИО");
    ui->lineEdit->setPlaceholderText("Серия и номер паспорта");
    ui->lineEdit_4->setPlaceholderText("Номер телефона");
    ui->lineEdit_5->setPlaceholderText("Адрес");
}

Addtc::~Addtc()
{
    delete ui;
}

void Addtc::on_checkBox_clicked()
{
    if(ui->checkBox->isChecked())
    ui->frame_2->show();

    if(!ui->checkBox->isChecked())
    ui->frame_2->hide();
}

QString Addtc::num()
{
    if(ui->lineEdit_7->text()!="NULL")
    return ui->lineEdit_7->text();
}

QString Addtc::name()
{
    if(ui->lineEdit_2->text()!="NULL")
    return ui->lineEdit_2->text();
}

QString Addtc::avto()
{
    if(ui->lineEdit_6->text()!="NULL")
    return ui->lineEdit_6->text();
}

QString Addtc::pas()
{
    if(ui->lineEdit->text()!="NULL")
    return ui->lineEdit->text();
}
QString Addtc::phone()
{
    if(ui->lineEdit_4->text()!="NULL")
    return ui->lineEdit_4->text();
}

QString Addtc::adres()
{
    if(ui->lineEdit_5->text()!="NULL")
    return ui->lineEdit_5->text();
}

void Addtc::on_pushButton_clicked()
{
    this->close();
    emit firstWindow();
}

void Addtc::on_pushButton_2_clicked()
{
    ui->lineEdit->setText(NULL);
    ui->lineEdit_2->setText(NULL);
    ui->lineEdit_4->setText(NULL);
    ui->lineEdit_5->setText(NULL);
    ui->lineEdit_6->setText(NULL);
    ui->lineEdit_7->setText(NULL);
    this->close();
    emit firstWindow();
}

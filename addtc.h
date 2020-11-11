#ifndef ADDTC_H
#define ADDTC_H

#include <QDialog>

namespace Ui {
class Addtc;
}

class Addtc : public QDialog
{
    Q_OBJECT

public:
    explicit Addtc(QWidget *parent = 0);
    ~Addtc();
    QString num();
    QString name();
    QString avto();
    QString pas();
    QString phone();
    QString adres();

signals:
    void firstWindow();

private slots:
    void on_checkBox_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Addtc *ui;
};

#endif // ADDTC_H

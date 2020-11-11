#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "databaseconection.h"
#include "add.h"
#include "addtc.h"
#include <QSqlQuery>
#include <QDate>
#include<QTextBrowser>
#include<QtPrintSupport/QPrinter>
#include<QtPrintSupport/QPrintDialog>
#include<QTextStream>
#include<QTextDocument>

namespace Ui {
class MainWindow;
}

class QSqlQueryModel;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_action_2_triggered();

    void on_action_3_triggered();

    void on_radioButton_2_clicked();

    void on_radioButton_clicked();

    void on_radioButton_3_clicked();

    void on_radioButton_4_clicked();

    void on_radioButton_5_clicked();

    void on_radioButton_6_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_12_clicked();

    void on_action_triggered();

private:
    QString post;
    QString foul;
    QString n_avto;
    QString num;
    QString name;
    QString avto;
    QString pas;
    QString phone;
    QString adres;
    const QString indif;
    int nom=0;
    Addtc *tc;
    Add *add;
    DatabaseConection mDbConnection;
    Ui::MainWindow *ui;
    QSqlQueryModel *fModel;
    QSqlQuery query;
};

#endif // MAINWINDOW_H

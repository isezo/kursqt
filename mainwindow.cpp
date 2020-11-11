#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QMessageBox>
#include <QSqlQueryModel>
#include<QSqlQuery>
#include <QDate>
#include <QTableWidget>
#include<QTableWidgetItem>
#include<QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    mDbConnection("MySQLServer","SQL SERVER","KURSAVAYA",true)
{
    QString error;
    if (!mDbConnection.openDatabase(&error))
    {
        QMessageBox::critical(this, "Error", error);
        return;
    }
    ui->setupUi(this);

    fModel = new QSqlQueryModel(this);
    fModel->setQuery("Select* FROM enchiridion");
    ui->tableView->setModel(fModel);

    ui->pushButton_3->hide();
    ui->pushButton_5->hide();
    ui->pushButton_6->hide();
    ui->pushButton_4->hide();
    ui->pushButton_7->hide();
    ui->pushButton_10->hide();
    ui->pushButton_11->hide();
    ui->pushButton_12->hide();
    ui->lineEdit_3->hide();
    ui->lineEdit_5->hide();
    ui->lineEdit->hide();
    ui->lineEdit_2->hide();
    ui->lineEdit_5->setPlaceholderText("Адрес");
    ui->lineEdit_3->setPlaceholderText("Номер_телефона");

    add = new Add();
    connect(add, &Add::firstWindow, this, &MainWindow::show);
    tc = new Addtc();
    connect(tc, &Addtc::firstWindow, this, &MainWindow::show);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    add->exec();
    post=add->post();
    n_avto=add->n_avto();
    foul=add->foul();
    if(post!=NULL&&foul!=NULL&&n_avto!=NULL){
        query.exec( QString::fromUtf8("SELECT TOP 1 Рег_знак FROM TC WHERE Рег_знак LIKE '%1'").arg(n_avto));
        query.next();
        QString qwerty = query.value(0).toString();
        if(n_avto == qwerty){
           query.exec(QString::fromUtf8("INSERT INTO foul VALUES ('%1', '%2', '%3')").arg(post.toInt()).arg(n_avto).arg(foul));

        } else {
            QMessageBox::information(this,"Ошибка добавление","Авто с указанным номером не существует. Необходимо сначала добавить информациию о нем.");
            on_pushButton_2_clicked();
        }
    }
}

void MainWindow::on_action_2_triggered()
{
    QMessageBox::information(this,"О программе","Программа АСК Штрафы ГИБДД предназначена для автоматизированного управления /где то/ в /предметной области/");
}

void MainWindow::on_action_3_triggered()
{
    QMessageBox::information(this,"Об авторе"," Программу АСК Штрафы ГИБДД разработал Обогрелов Вячеслав Владимирович в качестве курсового проекта по предмету 'Системы управления базами данных'\n Дата создания 28.01.2019");
}

void MainWindow::on_radioButton_clicked()
{
    fModel->setQuery("SELECT foul.Регистрационный_знак,foul.Номер_постановления,enchiridion.Наименование_нарушения,enchiridion.Сумма_штрафа FROM foul,enchiridion WHERE foul.Пункт_нарушения LIKE enchiridion.Пункт_нарушения");
    ui->tableView->setModel(fModel);
    ui->tableView->horizontalHeader()->setSectionResizeMode(1,QHeaderView::Stretch);
    ui->pushButton_3->hide();
    ui->pushButton_5->hide();
    ui->pushButton_6->hide();
    ui->pushButton_4->hide();
    ui->pushButton_7->hide();
    ui->pushButton_10->hide();
    ui->pushButton_11->hide();
    ui->pushButton_12->hide();
    ui->lineEdit_3->hide();
    ui->lineEdit_5->hide();
    ui->lineEdit->hide();
    ui->lineEdit_2->hide();
}

void MainWindow::on_radioButton_2_clicked()
{
    fModel->setQuery("Select* FROM enchiridion");
    ui->tableView->setModel(fModel);
    ui->tableView->horizontalHeader()->setSectionResizeMode(1,QHeaderView::Stretch);
    ui->lineEdit->setPlaceholderText("Сумма");
    ui->lineEdit->show();
    ui->lineEdit_2->hide();
    ui->lineEdit_3->hide();
    ui->lineEdit_5->hide();
    ui->pushButton_4->hide();
    ui->pushButton_7->hide();
    ui->pushButton_10->show();
    ui->pushButton_11->hide();
    ui->pushButton_12->hide();
}

void MainWindow::on_radioButton_3_clicked()
{   
    fModel->setQuery("Select* FROM TC");
    ui->tableView->setModel(fModel);
    ui->tableView->horizontalHeader()->setSectionResizeMode(1,QHeaderView::Stretch);
    ui->pushButton_3->hide();
    ui->pushButton_5->show();
    ui->pushButton_6->hide();
    ui->pushButton_4->hide();
    ui->pushButton_7->show();
    ui->pushButton_10->hide();
    ui->pushButton_11->show();
    ui->pushButton_12->hide();
    ui->lineEdit_3->hide();
    ui->lineEdit_5->hide();
    ui->lineEdit->show();
    ui->lineEdit_2->show();
    ui->lineEdit_2->setPlaceholderText("Марка авто");
    ui->lineEdit->setPlaceholderText("Номер авто*");
}

void MainWindow::on_radioButton_4_clicked()
{
    fModel->setQuery("Select* FROM owner");
    ui->tableView->setModel(fModel);
    ui->tableView->horizontalHeader()->setSectionResizeMode(1,QHeaderView::Stretch);
    ui->pushButton_3->hide();
    ui->pushButton_5->hide();
    ui->pushButton_6->show();
    ui->pushButton_7->hide();
    ui->pushButton_4->show();
    ui->pushButton_10->hide();
    ui->pushButton_11->hide();
    ui->pushButton_12->show();
    ui->lineEdit_3->show();
    ui->lineEdit_5->show();
    ui->lineEdit->show();
    ui->lineEdit_2->show();
    ui->lineEdit->setPlaceholderText("Номер_паспорта");
    ui->lineEdit_2->setPlaceholderText("ФИО");
}

void MainWindow::on_radioButton_5_clicked()
{
    fModel->setQuery("Select* FROM foul");
    ui->tableView->setModel(fModel);
    ui->tableView->horizontalHeader()->setSectionResizeMode(1,QHeaderView::Stretch);
    ui->pushButton_3->show();
    ui->pushButton_5->hide();
    ui->pushButton_6->hide();
    ui->pushButton_10->hide();
    ui->pushButton_11->hide();
    ui->pushButton_12->hide();
}

void MainWindow::on_radioButton_6_clicked()
{
    fModel->setQuery("Select* FROM ruling");
    ui->tableView->setModel(fModel);
    ui->tableView->horizontalHeader()->setSectionResizeMode(1,QHeaderView::Stretch);
    ui->pushButton_3->hide();
    ui->pushButton_5->hide();
    ui->pushButton_6->hide();
    ui->pushButton_4->hide();
    ui->pushButton_7->hide();
    ui->pushButton_10->hide();
    ui->pushButton_11->hide();
    ui->pushButton_12->hide();
    ui->lineEdit_3->hide();
    ui->lineEdit_5->hide();
    ui->lineEdit->hide();
    ui->lineEdit_2->hide();
}

void MainWindow::on_pushButton_2_clicked()
{
    tc->exec();
    num=tc->num();
    name=tc->name();
    avto=tc->avto();
    pas=tc->pas();
    phone=tc->phone();
    adres=tc->adres();    
    if(pas!=NULL&&name!=NULL){
        query.exec( QString::fromUtf8("BEGIN TRAN SELECT TOP 1 ind FROM idex DELETE TOP (1) FROM idex COMMIT"));
        query.next();
        nom = query.value(0).toInt();
        query.exec(QString::fromUtf8("INSERT INTO owner VALUES ('%1','%2','%3','%4','%5')").arg(nom).arg(pas).arg(name).arg(phone).arg(adres));
        if (num!=NULL&&avto!=NULL){
            query.exec(QString::fromUtf8("INSERT INTO TC VALUES ('%1', '%2', '%3')").arg(num.toInt()).arg(avto).arg(nom));
        }
    } else if (num!=NULL&&avto!=NULL){
        query.exec( QString::fromUtf8("SELECT TOP 1 Инд_ном FROM owner WHERE ФИО LIKE '%1'").arg(name));
        query.next();
        int id = query.value(0).toInt();
        if(id>1000&&id<9998){
            query.exec(QString::fromUtf8("INSERT INTO TC VALUES ('%1', '%2', '%3')").arg(num.toInt()).arg(avto).arg(id));
        } else {
            QMessageBox::information(this,"Ошибка добавление","Данных о владельце не существует. Необходимо сначала добавить информациию о нем.");
            on_pushButton_2_clicked();
        }
    }
}

void MainWindow::on_pushButton_3_clicked()
{
    QString strok = ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->currentIndex().row(), 0)).toString();
    qDebug()<<query.exec( QString::fromUtf8 ("DELETE FROM foul WHERE Номер_постановления LIKE '%3'").arg(strok));
}

void MainWindow::on_pushButton_4_clicked()
{
    if(ui->lineEdit->text()!=NULL){
        QString strok = ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->currentIndex().row(), 1)).toString();
        query.exec( QString::fromUtf8 ("UPDATE owner SET Номер_паспорта = '%1' Where Номер_паспорта like '%2' ").arg(ui->lineEdit->text()).arg(strok));
    }

    if(ui->lineEdit_2->text()!=NULL){
         QString strok1 = ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->currentIndex().row(), 2)).toString();
         query.exec( QString::fromUtf8 ("UPDATE owner SET ФИО = '%1' where ФИО like '%2'").arg(ui->lineEdit_2->text()).arg(strok1));
    }

    if(ui->lineEdit_3->text()!=NULL){
        QString strok2 = ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->currentIndex().row(), 3)).toString();
        query.exec( QString::fromUtf8 ("UPDATE owner SET Номер_телефона = '%1' where Номер_телефона like '%2'").arg(ui->lineEdit_3->text()).arg(strok2));
    }

    if(ui->lineEdit_5->text()!=NULL){
         QString strok3 = ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->currentIndex().row(), 4)).toString();
         query.exec( QString::fromUtf8 ("UPDATE owner SET Адрес = '%1' where Адрес like '%2'").arg(ui->lineEdit_5->text()).arg(strok3));
    }
}

void MainWindow::on_pushButton_5_clicked()
{
    QString strok = ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->currentIndex().row(), 0)).toString();
    query.exec( QString::fromUtf8 ("DELETE FROM TC WHERE Рег_знак LIKE '%3'").arg(strok));
}

void MainWindow::on_pushButton_6_clicked()
{
    QString strok = ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->currentIndex().row(), 0)).toString();
    query.exec( QString::fromUtf8 ("DELETE FROM owner WHERE Инд_ном LIKE '%3'").arg(strok));
}

void MainWindow::on_pushButton_7_clicked()
{
    if(ui->lineEdit->text()!=NULL){
        QString strok = ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->currentIndex().row(), 0)).toString();
        query.exec( QString::fromUtf8 ("UPDATE TC SET Рег_знак = '%1' where Рег_знак like '%2'").arg(ui->lineEdit->text()).arg(strok));
    }

    if(ui->lineEdit_2->text()!=NULL){
        QString strok2 = ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->currentIndex().row(), 0)).toString();
         query.exec( QString::fromUtf8 ("UPDATE TC SET Марка_авто = '%1' where Марка_авто like '%2'").arg(ui->lineEdit_2->text()).arg(strok2));
        ui->tableView->setModel(fModel);
    }
}

void MainWindow::on_pushButton_10_clicked()
{
    if(ui->lineEdit->text()!=NULL)
    fModel->setQuery( QString::fromUtf8 ("select * from enchiridion where Сумма_штрафа like '%1'").arg((ui->lineEdit->text()).toInt()));
    ui->tableView->setModel(fModel);
}

void MainWindow::on_pushButton_11_clicked()
{
    if(ui->lineEdit->text()!=NULL)
    fModel->setQuery( QString::fromUtf8 ("select * from TC where Рег_знак like '%1'").arg(ui->lineEdit->text()));
    ui->tableView->setModel(fModel);
}

void MainWindow::on_pushButton_12_clicked()
{
    if(ui->lineEdit_2->text()!=NULL)
    fModel->setQuery( QString::fromUtf8 ("select * from owner where ФИО like '%1'").arg(ui->lineEdit_2->text()));
    ui->tableView->setModel(fModel);
}

void MainWindow::on_action_triggered()
{
    int rowCount = ui->tableView->model()->rowCount();
    int columnCount = ui->tableView->model()->columnCount();
    QString strStream;
    QTextStream out(&strStream);
    out << "<html>\n" << "<head>\n" << "meta Content=\"Text/html;charset=Windows-1251\">\n" <<
        QString ("<title>%1</title>\n").arg("Report") <<
        "</head>/n"
        "<body bgcolor = #ffffff link=#5000A0>\n"
        "<table border = 1 cellspacing=0 cellpadding=2>\n";
     out << "<thead><tr bgcolor=#f0f0f0>";
     for (int column = 0; column < columnCount; column++){
        out<<QString("<th>%1</th>").arg(ui->tableView->model()->headerData(column,Qt::Horizontal).toString());
     }
        out<<"</tr></thead>\n";

     for (int row = 0; row < rowCount; row++){
         out<< "<tr>";
         for (int column=0;column<columnCount;column++) {
             if(!ui->tableView->isColumnHidden(column)){
                 QString data = ui-> tableView->model()->data(ui->tableView->model()->index(row,column)).toString().simplified();
                 out<<QString ("<td bgcolor=#f0f0f0>%1</td>").arg((!data.isEmpty())?data:QString(" "));

             }
         }
            out <<"</tr>\n";
     }
     out << "</table>\n" "</body>\n""</html>\n";
     QTextDocument *document = new QTextDocument();
     document->setHtml(strStream);

     QPrinter printer;
     QPrintDialog *dialog = new QPrintDialog(&printer,0);
     if(dialog->exec() == QDialog::Accepted){
        document->print(&printer);
     }
     delete document;
}

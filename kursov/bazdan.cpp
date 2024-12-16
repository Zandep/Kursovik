#include "bazdan.h"
#include "ui_bazdan.h"
#include "QMainWindow"
#include <QSqlTableModel>
#include <QMessageBox>
#include <QtSql>
#include <QtGui>
#include <QSqlDatabase>
#include <QString>
#include <QStringList>


BazDan::BazDan(QWidget*):
    ui(new Ui::BazDan)
{
   MainWindow conn;
            if (conn.connOpen()){
        qDebug() << "Удалось открыть базу данных";
    }
    else{
        qDebug() << "Не удалось";
    }
}


BazDan::~BazDan()
{
    delete ui;
}

void BazDan::on_BaltFlot_clicked()
{

//        QSqlTableModel *model = new QSqlTableModel();
//        model->setTable("BaltFlot"); //имя таблицы

//        //model->setEditStrategy(QSqlTableModel::OnFieldChange);//тип обновления

//        model->select();//обозначение колонок
//        model->setHeaderData(0, Qt::Horizontal,QObject::tr("Class"));
//        model->setHeaderData(1, Qt::Horizontal,QObject::tr("Name"));
//        model->setHeaderData(2, Qt::Horizontal,QObject::tr("Project"));
//        model->setHeaderData(3, Qt::Horizontal,QObject::tr("Time"));
//        QTableView *view = new QTableView;
//        view->setModel(model);
//        view->show();
    //return app.exec();
}
void BazDan::on_VMF_Rus_clicked()
{
    QSqlTableModel model;
    model.setTable("VMF_Rus");
    QTableView *view = new QTableView;
    view->setModel(&model);
    view->show();
}
void BazDan::on_KaspFlot_clicked()
{
    QSqlTableModel model;
    model.setTable("KaspFlot");
    model.select();
    QTableView view;
    view.setModel(&model);
    view.show();
    ui->setupUi(this);
}
void BazDan::on_TihoFlot_clicked()
{
    QSqlTableModel model;
    model.setTable("TihoFlot");
    model.select();
    QTableView view;
    view.setModel(&model);
    view.show();
    ui->setupUi(this);
}

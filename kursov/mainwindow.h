#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "bazdan.h"
#include "registr.h"

#include <QMainWindow>
#include <QtDebug>
#include <QString>
#include <QSqlTableModel>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    void connClose(){
        db.close();
        db.removeDatabase(QSqlDatabase::defaultConnection);
    }
    bool connOpen(){
        db = QSqlDatabase::addDatabase("QPSQL");
        db.setHostName("localhost");
        db.setDatabaseName("tsn_demo");
        db.setUserName("postgres");
        db.setPassword("Zahar3457");
        if(db.open()){
            qDebug() << "Удалось открыть базу данных";
            return true;
        }
        else{
            qDebug() << "Не удалось 11111";
            return false;
        }

    }

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_VhodButton_clicked();

    void on_RegisButton_clicked();

private:
    QSqlDatabase db;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H

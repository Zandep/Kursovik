#ifndef BAZDAN_H
#define BAZDAN_H

#include <QDialog>
#include <QMessageBox>
#include <QtSql>
#include <QSqlDatabase>
#include <QString>
#include <QStringList>

#include "mainwindow.h"

namespace Ui {
class BazDan;
}

class BazDan : public QDialog
{
    Q_OBJECT

public:
    explicit BazDan(QWidget *parent = 0);
    ~BazDan();
    void connOpen();
    bool inserIntoTable(const QVariantList &data);

private slots:
    void on_BaltFlot_clicked();

    void on_KaspFlot_clicked();

    void on_TihoFlot_clicked();

    void on_VMF_Rus_clicked();

private:
    QSqlTableModel model;

    QSqlDatabase db;
    Ui::BazDan *ui;
};

#endif // BAZDAN_H

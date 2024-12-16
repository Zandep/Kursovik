#include "mainwindow.h"
#include "ui_bazdan.h"
#include "ui_mainwindow.h"
#include "registr.h"

MainWindow::MainWindow(QWidget *parent):
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_VhodButton_clicked()
{
    QFile file("Pol.txt");
    if (file.open(QIODevice::ReadOnly))
    {
        QString name = ui -> loginEdit -> text();
        QString parol = ui -> ParoEdit -> text();
        QString str;
        QStringList List;
        while(!file.atEnd())
        {
            str = file.readLine();
            List = str.split(" ");
            if(List.at(0) == name && List.at(1) == parol)
            {
                connClose();
                QMainWindow::close();
                BazDan bd;
                bd.setModal(true);
                bd.exec();
            }
        }
        file.close();
    }

    else
    {
        QMessageBox messageBox;
        messageBox.critical(0,"Error","Зарегистрируйтесь, пожалуйста!");
        messageBox.setFixedSize(500,200);
        return;
    }
    if (!db.open()){
        qDebug() << "Не удалось 000";
        return;
    }
    connOpen();
    QSqlQuery gry;
}


void MainWindow::on_RegisButton_clicked()
{
    Registr reg;
    reg.setModal(true);
    reg.exec();
}

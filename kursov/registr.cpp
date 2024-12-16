#include "registr.h"
#include "ui_registr.h"
#include <QFile>
#include <QTextStream>

Registr::Registr(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Registr)
{
    ui->setupUi(this);
}

Registr::~Registr()
{
    delete ui;
}

void Registr::on_ZaregButton_clicked()
{
    QFile file("Pol.txt");
    if (file.open(QIODevice::Append | QIODevice::Text))
    {
        QTextStream stream(&file);
        QString name = ui -> loginEdit -> text();
        QString parol = ui -> ParoEdit -> text();
        QString telef = ui -> TelefonEdit -> text();
        QString pochta = ui -> PochtaEdit -> text();
        QString prava, JButton, MButton;
        if(ui -> AdminBox -> isChecked())
        {
            prava = "true";
        }
        if(!ui -> AdminBox -> isChecked())
        {
            prava = "false";
        }
        if(ui -> JButton -> isChecked())
        {
            JButton = "Ж";
        }
        if(ui ->MButton -> isChecked())
        {
            MButton = "М";
        }

        stream << name << " " << parol << " " << prava << " " << pochta << " " << telef << " " << JButton << " " << MButton << endl;
    }
    close();
}

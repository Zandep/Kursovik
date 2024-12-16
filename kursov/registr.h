#ifndef REGISTR_H
#define REGISTR_H

#include <QDialog>

namespace Ui {
class Registr;
}

class Registr : public QDialog
{
    Q_OBJECT

public:
    explicit Registr(QWidget *parent = nullptr);
    ~Registr();

private slots:
    void on_ZaregButton_clicked();

private:
    Ui::Registr *ui;
};

#endif // REGISTR_H

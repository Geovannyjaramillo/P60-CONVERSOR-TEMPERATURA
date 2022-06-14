#include "conversor.h"
#include "ui_conversor.h"

Conversor::Conversor(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Conversor)
{
    ui->setupUi(this);
    // Conectarel dial de Centigrados con el slot de ESTA clase
    connect(ui->inCent, SIGNAL(valueChanged(int)),
            this, SLOT(cent2fahr2kelv(int)));
    connect(ui->inFahr, SIGNAL(valueChanged(int)),
            this, SLOT (fahr2cent2kelv(int)));
    connect(ui->inKel, SIGNAL(valueChanged(int)),
            this, SLOT (kelv2cent2fahr(int)));
}

Conversor::~Conversor()
{
    delete ui;
}

void Conversor::cent2fahr2kelv(int grados)
{
    if (ui->inCent->hasFocus()){
        int f = (grados * 9.0/5) + 32;
        int k = (grados + 273.15);
        ui->inFahr->setValue(f);
        ui->inKel->setValue(k);}

}

void Conversor::fahr2cent2kelv(int grados)
{
    if (ui->inFahr->hasFocus()){
        int c = (grados - 32) * 5.0/9;
        int ke = (grados - 32) * 5.0/9 + 273.15;
        ui->inCent->setValue(c);
        ui->inKel->setValue(ke);
    }
}

void Conversor::kelv2cent2fahr(int grados)
{
    if(ui->inKel->hasFocus()){
        int ce = (grados - 273.15);
        int fa = (grados - 273.15) * 9.0/5 + 32;
        ui->inCent->setValue(ce);
        ui->inFahr->setValue(fa);
    }
}


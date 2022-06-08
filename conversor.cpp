#include "conversor.h"
#include "ui_conversor.h"

Conversor::Conversor(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Conversor)
{
    ui->setupUi(this);

    //conectar el dial de centigrados con el slot de esta clase
    connect(ui->inCent, SIGNAL(valueChanged(int)),
            this,SLOT(cent2fahr(int)));

    connect() connect(ui->inFahr, SIGNAL(valueChanged(int)),
                      this,SLOT(fareh2cent(int)));

Conversor::~Conversor()
{
    delete ui;
}

void Conversor::cent2fahr(int grados)
{
    int f = (grados * 9.0/5) + 32;
    // iu->outFahr->display(f);  ############esto si quieres mover solo el display LCD
    ui->inFahr->setValue(f); // esto mueve las dos perillas
}

void Conversor::fareh2cent(int grados)
{
    int c = (grados - 32) * 5.0/9;
    ui->inCent->setValue(c);
}


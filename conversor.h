#ifndef CONVERSOR_H
#define CONVERSOR_H

#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class Conversor; }
QT_END_NAMESPACE

class Conversor : public QDialog
{
    Q_OBJECT

public:
    Conversor(QWidget *parent = nullptr);
    ~Conversor();
public slots:
    void cent2fahr(int grados); //de centigrados a fare (centigrados 2=to fareh)
    void fareh2cent(int grados); // de fareh a centigrados
private:
    Ui::Conversor *ui;
};
#endif // CONVERSOR_H

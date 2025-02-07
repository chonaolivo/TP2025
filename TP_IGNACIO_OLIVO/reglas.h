#ifndef REGLAS_H
#define REGLAS_H

#include <QWidget>

namespace Ui {
class Reglas;
}

class Reglas : public QWidget
{
    Q_OBJECT

public:
    explicit Reglas(QWidget *parent = nullptr);
    ~Reglas();

private slots:

    void on_DNI_Button_clicked();

    void on_TICKET_Button_clicked();

    void on_TRABAJO_Button_clicked();

    void on_VISA_Button_clicked();

private:
    Ui::Reglas *ui;
};

#endif // REGLAS_H

#include "visa.h"
#include "ui_visa.h"
#include "cargararchivos.h"

//Clase exclusiva para la mostrar los datos de la visa

visa::visa(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::visa)
{
    ui->setupUi(this);
    setWindowTitle("VISA");
    ui->VISA_QPlainTextEdit->setReadOnly(true);
    CargarArchivos cargarArchivos;
    cargarArchivos.Visa(this);
}

visa::~visa()
{
    delete ui;
}

// Carga el QPlainText con los datos de la visa
void visa::cargarTexto(const QString &texto) {
    ui->VISA_QPlainTextEdit->clear();
    ui->VISA_QPlainTextEdit->insertPlainText(texto);
}

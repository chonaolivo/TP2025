#include "trabajo.h"
#include "ui_trabajo.h"
#include "cargararchivos.h"

//Clase exclusiva para el permiso de trabajo

trabajo::trabajo(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::trabajo)
{
    ui->setupUi(this);
    setWindowTitle("Permiso de Trabajo");
    ui->TRABAJO_QPlainTextEdit->setReadOnly(true);
    CargarArchivos cargarArchivos;
    cargarArchivos.Trabajo(this);
}

trabajo::~trabajo()
{
    delete ui;
}

// Carga el QPlainText con los datos del permiso de trabajo
void trabajo::cargarTexto(const QString &texto) {
    ui->TRABAJO_QPlainTextEdit->clear();
    ui->TRABAJO_QPlainTextEdit->insertPlainText(texto);
}

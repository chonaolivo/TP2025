#include "ticket_de_entrada.h"
#include "ui_ticket_de_entrada.h"
#include "creardocumentos.h"
#include "cargararchivos.h"


//Clase exclusiva para mostrar los datos del ticket de entrada

ticket_de_entrada::ticket_de_entrada(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ticket_de_entrada)
{
    ui->setupUi(this);
    setWindowTitle("TICKET DE ENTRADA");
    ui->TICKET_QPlainTextEdit->setReadOnly(true);
    CargarArchivos cargarArchivos;  // Crear el objeto de la clase CargarArchivos
    cargarArchivos.ticket(this);  // Cargar el archivo en el QPlainTextEdit de DNI

}

ticket_de_entrada::~ticket_de_entrada()
{
    delete ui;
}

// Carga el QPlainText con los datos del ticket de entrada
void ticket_de_entrada::cargarTexto(const QString &texto) {
    ui->TICKET_QPlainTextEdit->clear();  // Limpiar el contenido previo
    ui->TICKET_QPlainTextEdit->insertPlainText(texto);  // Insertar el nuevo texto
}

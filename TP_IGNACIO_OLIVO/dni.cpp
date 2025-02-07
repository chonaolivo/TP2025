#include "dni.h"
#include "ui_dni.h"
#include "cargararchivos.h"
#include "creardocumentos.h"

#include <QMessageBox>
#include <fstream>

DNI::DNI(QWidget *parent)
    : QWidget(parent), ui(new Ui::DNI)
{
    ui->setupUi(this);
    configurarInterfaz();
    inicializarDNI();
}

DNI::~DNI()
{
    delete ui;
}

// Configura el editor de texto y otras propiedades
void DNI::configurarInterfaz()
{
    setWindowTitle("DNI");
    ui->DNI_QPlainTextEdit->setReadOnly(true);
}

// Crea y carga los datos para el DNI
void DNI::inicializarDNI()
{
    try {
        // Crea el documento
        creardocumentos creador;
        creador.Crear_Archivos("C:\\Users\\olign\\OneDrive\\Escritorio\\TP2025\\base de datos\\DNI.txt", "DNI");

        // Carga el archivo en el editor de texto
        CargarArchivos cargador;
        cargador.dni(this);
    } catch (const std::exception &e) {
        QMessageBox::critical(this, "Error", QString("Ocurrió un problema al inicializar el DNI: %1").arg(e.what()));
    }
}

// Carga el texto en el QPlainTextEdit
void DNI::cargarTexto(const QString &texto)
{
    ui->DNI_QPlainTextEdit->clear();
    ui->DNI_QPlainTextEdit->insertPlainText(texto);
}

void DNI::limpiar() {
    ui->DNI_QPlainTextEdit->clear();
}

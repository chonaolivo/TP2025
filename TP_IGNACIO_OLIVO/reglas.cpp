#include "reglas.h"
#include "ui_reglas.h"
#include <QMessageBox>
Reglas::Reglas(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Reglas)
{
    ui->setupUi(this);
    setWindowTitle("Reglas");
}

Reglas::~Reglas()
{
    delete ui;
}

/*
Esta clase esta puramente dedicada a inicializar el ui de la ventana de información del juego y
mostrar las distintas funcionalidades y reglas del juego.
*/


void Reglas::on_DNI_Button_clicked()
{
    // Crear el mensaje con formato
    QString mensaje = "Este es un ejemplo de DNI válido:\n"
                      "--------------------------------------------------\n"
                      "Camila Silva -->Nombre\n"
                      "08/07/1958 -->Fecha de nacimiento\n"
                      "Córdoba -->Ciudad\n"
                      "23/05/2025 -->Fecha de vencimiento\n"
                      "Verde -->Sello\n"
                      "--------------------------------------------------\n"
                      "Se debe controlar que el documento no esté expirado y que el sello sea el correspondiente (Verde para los DNI).";

    // Crear y configurar el QMessageBox
    QMessageBox msgBox;
    msgBox.setWindowTitle("Ejemplo de DNI");
    msgBox.setText(mensaje);
    msgBox.setStandardButtons(QMessageBox::Ok);
    msgBox.setDefaultButton(QMessageBox::Ok);

    // Establecer un ancho mínimo para la ventana
    msgBox.setMinimumWidth(400);

    // Mostrar la ventana
    msgBox.exec();
}


void Reglas::on_TICKET_Button_clicked()
{
    // Crear el mensaje con formato
    QString mensaje = "Este es un ejemplo de Ticket de entrada válido:\n"
                      "--------------------------------------------------\n"
                      "Camila Silva -->Nombre\n"
                      "Córdoba -->Ciudad\n"
                      "23/05/2025 -->Fecha de vencimiento\n"
                      "Amarillo -->Sello\n"
                      "--------------------------------------------------\n"
                      "Se debe controlar que el documento no esté expirado y que el sello sea el correspondiente (Verde para los DNI).\n"
                      "Ademas se debe controlar que el nombre y la ciudad coincida con los demas documentos";
    // Crear y configurar el QMessageBox
    QMessageBox msgBox;
    msgBox.setWindowTitle("Ejemplo de Ticket de entrada");
    msgBox.setText(mensaje);
    msgBox.setStandardButtons(QMessageBox::Ok);
    msgBox.setDefaultButton(QMessageBox::Ok);

    // Establecer un ancho mínimo para la ventana
    msgBox.setMinimumWidth(400);

    // Mostrar la ventana
    msgBox.exec();
}


void Reglas::on_TRABAJO_Button_clicked()
{
    // Crear el mensaje con formato
    QString mensaje = "Este es un ejemplo de Permiso de trabajo válido:\n"
                      "--------------------------------------------------\n"
                      "Camila Silva -->Nombre\n"
                      "23/05/2025 -->Fecha de vencimiento\n"
                      "Azul -->Sello\n"
                      "--------------------------------------------------\n"
                      "Se debe controlar que el documento no esté expirado y que el sello sea el correspondiente (Verde para los DNI).\n"
                      "Ademas se debe controlar que el nombre coincida con los demas documentos";
    // Crear y configurar el QMessageBox
    QMessageBox msgBox;
    msgBox.setWindowTitle("Ejemplo de Permiso de trabajo");
    msgBox.setText(mensaje);
    msgBox.setStandardButtons(QMessageBox::Ok);
    msgBox.setDefaultButton(QMessageBox::Ok);

    // Establecer un ancho mínimo para la ventana
    msgBox.setMinimumWidth(400);

    // Mostrar la ventana
    msgBox.exec();
}


void Reglas::on_VISA_Button_clicked()
{
    // Crear el mensaje con formato
    QString mensaje = "Este es un ejemplo de DNI válido:\n"
                      "--------------------------------------------------\n"
                      "Camila Silva -->Nombre\n"
                      "08/07/1958 -->Fecha de nacimiento\n"
                      "Córdoba -->Ciudad\n"
                      "Paso -->Razón de paso\n"
                      "23/05/2025 -->Fecha de vencimiento\n"
                      "Verde -->Sello\n"
                      "--------------------------------------------------\n"
                      "Se debe controlar que el documento no esté expirado y que el sello sea el correspondiente (Verde para los DNI).\n"
                      "Ademas se debe controlar que el nombre y la ciudad coincida con los demas documentos.\n"
                      "Por ultimo se debe controlar que se presente el ticket de trabajo en caso de que la razon sea esa.";

    // Crear y configurar el QMessageBox
    QMessageBox msgBox;
    msgBox.setWindowTitle("Ejemplo de VISA");
    msgBox.setText(mensaje);
    msgBox.setStandardButtons(QMessageBox::Ok);
    msgBox.setDefaultButton(QMessageBox::Ok);

    // Establecer un ancho mínimo para la ventana
    msgBox.setMinimumWidth(400);

    // Mostrar la ventana
    msgBox.exec();
}


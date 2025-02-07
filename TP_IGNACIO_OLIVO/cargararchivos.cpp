#include "cargararchivos.h"
#include <fstream>
#include <QString>
#include <QMessageBox>
#include <iostream>

#include "dni.h"
#include "ticket_de_entrada.h"
#include "creardocumentos.h"
#include "trabajo.h"
#include "visa.h"

// Constructor
CargarArchivos::CargarArchivos() {}

// Carga los datos que contiene un archivo en una funcion QString
QString CargarArchivos::cargarContenidoArchivo(const std::string& rutaArchivo) {
    std::ifstream archivo(rutaArchivo);
    if (!archivo.is_open()) {
        // Si el archivo no se puede abrir, devolver un mensaje de error
        return "Error al abrir el archivo.";
    }

    std::string linea;
    QString contenido;
    while (std::getline(archivo, linea)) {
        contenido += QString::fromStdString(linea) + "\n";  // Añadir cada línea al contenido
    }
    archivo.close();
    return contenido;
}

// Carga los datos del archivo en la ventana correspondiente
void CargarArchivos::cargarArchivoEnVentana(QWidget* ventana, const std::string& rutaArchivo, const QString& tipoArchivo) {
    creardocumentos creador;
    creador.Crear_Archivos(rutaArchivo, tipoArchivo.toStdString());

    QString contenido = cargarContenidoArchivo(rutaArchivo);

    // Convertir QString a std::string para imprimirlo en la consola (opcional)
    std::string contenidoStd = contenido.toStdString();
    std::cout << contenidoStd << std::endl;  // Imprimir en la consola

    // Determinar el tipo de ventana y cargar el contenido
    if (auto* ventanaDNI = dynamic_cast<DNI*>(ventana)) {
        ventanaDNI->cargarTexto(contenido);
    } else if (auto* ventanaTicket = dynamic_cast<ticket_de_entrada*>(ventana)) {
        ventanaTicket->cargarTexto(contenido);
    } else if (auto* ventanaTrabajo = dynamic_cast<class trabajo*>(ventana)) {  // Usar la clase completa
        ventanaTrabajo->cargarTexto(contenido);
    } else if (auto* ventanaVisa = dynamic_cast<class visa*>(ventana)) {  // Usar la clase completa
        ventanaVisa->cargarTexto(contenido);
    } else {
        QMessageBox::critical(nullptr, "Error", "Tipo de ventana no reconocido");
    }
}

// Métodos específicos para cargar archivos en las respectivas ventanas
void CargarArchivos::dni(DNI* ventanaDNI) {
    const std::string ruta = "C:\\Users\\olign\\OneDrive\\Escritorio\\TP2025\\base de datos\\DNI.txt";
    cargarArchivoEnVentana(ventanaDNI, ruta, "DNI");
}

void CargarArchivos::ticket(ticket_de_entrada* ventanaTicket) {
    const std::string ruta = "C:\\Users\\olign\\OneDrive\\Escritorio\\TP2025\\base de datos\\ticket_de_entrada.txt";
    cargarArchivoEnVentana(ventanaTicket, ruta, "TICKET");
}

void CargarArchivos::Trabajo(trabajo* ventanaTrabajo) {
    const std::string ruta = "C:\\Users\\olign\\OneDrive\\Escritorio\\TP2025\\base de datos\\permiso_de_trabajo.txt";
    cargarArchivoEnVentana(ventanaTrabajo, ruta, "TRABAJO");
}

void CargarArchivos::Visa(visa* ventanaVisa) {
    const std::string ruta = "C:\\Users\\olign\\OneDrive\\Escritorio\\TP2025\\base de datos\\visa.txt";
    cargarArchivoEnVentana(ventanaVisa, ruta, "VISA");
}

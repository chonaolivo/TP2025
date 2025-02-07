#include "creardocumentos.h"
#include <vector>
#include <string>
#include <fstream>
#include <QMessageBox>
#include <cstdlib>
#include <ctime>
#include <iostream>

namespace {
/*
¡¡¡¡ ACA COLOCAR LA RUTA QUE DESEE PROFEE !!!!
*/
// Ruta base para los archivos
const std::string RUTA_BASE = "C:\\Users\\olign\\OneDrive\\Escritorio\\TP2025\\base de datos\\";

// Crea una ruta espefica para el archivo segun coloque el programador
std::string construirRuta(const std::string& archivo) {
    return RUTA_BASE + archivo;
}

// Verificar si un vector está vacío y acumula errores
bool verificarDatosVacios(const std::vector<std::string>& datos, const std::string& nombreArchivo, QString& errores) {
    if (datos.empty()) {
        errores += QString::fromStdString("Archivo vacío o no encontrado: " + nombreArchivo + "\n");
        return true;
    }
    return false;
}
}

// Crea nombre y apellido de forma global
void creardocumentos::generarNombreApellidoGlobal() {
    auto nombres = cargarLineas(construirRuta("nombres.txt"));
    auto apellidos = cargarLineas(construirRuta("apellidos.txt"));

    nombreGlobal = seleccionarAleatoria(nombres);
    apellidoGlobal = seleccionarAleatoria(apellidos);
}

// Cargar todas las líneas de un archivo en un vector
std::vector<std::string> creardocumentos::cargarLineas(const std::string& rutaArchivo) {
    std::vector<std::string> lineas;
    std::ifstream archivo(rutaArchivo);

    if (!archivo.is_open()) {
        QMessageBox::warning(this, "Error", "No se pudo abrir el archivo: " + QString::fromStdString(rutaArchivo));
        return lineas;
    }

    std::string linea;
    while (std::getline(archivo, linea)) {
        if (!linea.empty()) {
            lineas.push_back(linea);  // Añadir solo líneas no vacías
        }
    }

    if (lineas.empty()) {
        QMessageBox::warning(this, "Advertencia", "El archivo está vacío: " + QString::fromStdString(rutaArchivo));
    }

    return lineas;
}

// Selecciona una lInea aleatoria de un vector
std::string creardocumentos::seleccionarAleatoria(const std::vector<std::string>& lineas) {
    if (lineas.empty()) {
        QMessageBox::warning(this, "Advertencia", "No hay datos disponibles para seleccionar.");
        return "";
    }
    int indice = rand() % lineas.size();
    return lineas[indice];
}

// Funcion que crea los archivos con datos aleatorios.
void creardocumentos::Crear_Archivos(std::string ruta, std::string tipo) {
    // Cargar datos necesarios (excepto nombres y apellidos)
    auto fechasVencimiento = cargarLineas(construirRuta("fecha_de_vencimiento.txt"));
    auto sellos = cargarLineas(construirRuta("sellos.txt"));
    auto fechasNacimiento = cargarLineas(construirRuta("fechas_de_nacimiento.txt"));
    auto ciudades = cargarLineas(construirRuta("ciudades.txt"));
    auto razones = cargarLineas(construirRuta("razones.txt"));

    QString errores;
    // Verificar datos
    verificarDatosVacios(fechasVencimiento, "fecha_de_vencimiento.txt", errores);
    verificarDatosVacios(sellos, "sellos.txt", errores);

    if (!errores.isEmpty()) {
        QMessageBox::warning(this, "Errores en los datos", errores);
        return;
    }

    // Usar nombreGlobal y apellidoGlobal en lugar de generar nuevos
    std::string fechaVencimiento = seleccionarAleatoria(fechasVencimiento);
    std::string sello = seleccionarAleatoria(sellos);

    std::string contenido;

    //Según el tipo de archivo define que datos debe cargar en cada caso.
    if (tipo == "DNI") {
        std::string fechaNacimiento = seleccionarAleatoria(fechasNacimiento);
        std::string ciudad = seleccionarAleatoria(ciudades);
        contenido = nombreGlobal + " " + apellidoGlobal + "\n" +
                    fechaNacimiento + "\n" +
                    ciudad + "\n" +
                    fechaVencimiento + "\n" +
                    sello;
    }
    else if (tipo == "VISA") {
        std::string fechaNacimiento = seleccionarAleatoria(fechasNacimiento);
        std::string ciudad = seleccionarAleatoria(ciudades);
        std::string razon = seleccionarAleatoria(razones);
        contenido = nombreGlobal + " " + apellidoGlobal + "\n" +
                    fechaNacimiento + "\n" +
                    ciudad + "\n" +
                    fechaVencimiento + "\n" +
                    razon + "\n" +
                    sello;
    }
    else if (tipo == "TICKET") {
        std::string ciudad = seleccionarAleatoria(ciudades);
        contenido = nombreGlobal + " " + apellidoGlobal + "\n" +
                    ciudad + "\n" +
                    fechaVencimiento + "\n" +
                    sello;
    }
    else if (tipo == "TRABAJO") {
        contenido = nombreGlobal + " " + apellidoGlobal + "\n" +
                    fechaVencimiento + "\n" +
                    sello;
    }

    // Guardar en el archivo
    std::ofstream archivoSalida(ruta, std::ios::trunc);
    if (!archivoSalida.is_open()) {
        QMessageBox::warning(this, "Error", "No se pudo abrir el archivo para escritura: " + QString::fromStdString(ruta));
        return;
    }

    archivoSalida << contenido;
    archivoSalida.close();
}

// Constructor de la clase
creardocumentos::creardocumentos() {
    srand(static_cast<unsigned int>(time(nullptr)));
    generarNombreApellidoGlobal();

    // Crear todos los documentos con el mismo nombre y apellido
    Crear_Archivos(construirRuta("DNI.txt"), "DNI");
    Crear_Archivos(construirRuta("VISA.txt"), "VISA");
    Crear_Archivos(construirRuta("TICKET.txt"), "TICKET");
    Crear_Archivos(construirRuta("TRABAJO.txt"), "TRABAJO");
}

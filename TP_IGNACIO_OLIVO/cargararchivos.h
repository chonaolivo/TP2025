// En cargararchivos.h
#ifndef CARGARARCHIVOS_H
#define CARGARARCHIVOS_H

#include <QString>
#include <string>
#include <QWidget>

// Forward declarations
class trabajo;  // Aquí se usa 'class'
class visa;     // Aquí se usa 'class'
class DNI;
class ticket_de_entrada;

class CargarArchivos {
private:
    // Método genérico para cargar un archivo en cualquier ventana
    void cargarArchivoEnVentana(QWidget* ventana, const std::string& rutaArchivo, const QString& tipoArchivo);

public:
    CargarArchivos();

    QString cargarContenidoArchivo(const std::string& rutaArchivo);

    // Métodos para cargar datos específicos
    void dni(DNI* ventanaDNI);
    void ticket(ticket_de_entrada* ventanaTicket);
    void Trabajo(trabajo* ventanaTrabajo);  // Usamos 'trabajo' correctamente aquí
    void Visa(visa* ventanaVisa);          // Usamos 'visa' correctamente aquí
};

#endif // CARGARARCHIVOS_H

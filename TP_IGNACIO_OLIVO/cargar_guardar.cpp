#include "cargar_guardar.h"
#include "cargar_guardar.h"
#include <QFile>
#include <QTextStream>
#include <QDateTime>
#include <QDebug>
cargar_guardar::cargar_guardar() {}


//Guarda en un archivo txt los datos de aciertos y fallos al finalizar el juego.
void cargar_guardar::guardarLog(int aciertos, int fallos) {
    // Abrir el archivo en modo append (agregar al final)
    QFile file("logs.txt");
    if (file.open(QIODevice::Append | QIODevice::Text)) {
        QTextStream stream(&file);

        // Obtener la fecha y hora actual
        QDateTime currentDateTime = QDateTime::currentDateTime();
        QString formattedDateTime = currentDateTime.toString("yyyy-MM-dd HH:mm:ss");

        // Escribir en el archivo
        stream << "----------------------------------------\n";
        stream << "Fecha y Hora: " << formattedDateTime << "\n";
        stream << "Aciertos: " << aciertos << "\n";
        stream << "Fallos: " << fallos << "\n";
        stream << "----------------------------------------\n\n";

        file.close();
        qDebug() << "Log guardado exitosamente";
    } else {
        qWarning() << "No se pudo abrir el archivo de logs";
    }
}

//guarda en un archivo binario los datos necesarios para retomar el juego cuando el jugador lo desee.
void cargar_guardar::guardarEstadoBinario(int tiempo_restante, int nivel, int personas_restantes, int aciertos, int fallos) {
    QFile file("estado.dat");
    if (file.open(QIODevice::WriteOnly)) {
        QDataStream out(&file);

        // Establecer la versión del formato de datos
        out.setVersion(QDataStream::Qt_5_15);

        // Escribir los datos
        out << tiempo_restante
            << nivel
            << personas_restantes
            << aciertos
            << fallos;

        file.close();
        qDebug() << "Estado guardado exitosamente en archivo binario";
    } else {
        qWarning() << "No se pudo abrir el archivo binario para escritura";
    }
}

//Carga los datos de del archivo binario si el jugador lo desea
bool cargar_guardar::cargarEstadoBinario(int& tiempo_restante, int& nivel, int& personas_restantes, int& aciertos, int& fallos) {
    QFile file("estado.dat");
    if (file.open(QIODevice::ReadOnly)) {
        QDataStream in(&file);

        // Establecer la versión del formato de datos
        in.setVersion(QDataStream::Qt_5_15);

        // Leer los datos
        in >> tiempo_restante
            >> nivel
            >> personas_restantes
            >> aciertos
            >> fallos;

        file.close();
        qDebug() << "Estado cargado exitosamente desde archivo binario";
        return true;
    } else {
        qWarning() << "No se pudo abrir el archivo binario para lectura";
        return false;
    }
}

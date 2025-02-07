#include "niveles.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QDate>

//Constructor
niveles::niveles() {}

//Lee el archivo y extrae los datos del mismo
std::vector<QString> niveles::leerArchivo(const QString& rutaArchivo) {
    std::vector<QString> lineas;
    QFile archivo(rutaArchivo);

    if (!archivo.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qWarning() << "No se pudo abrir el archivo:" << rutaArchivo;
        return lineas;
    }

    QTextStream in(&archivo);
    while (!in.atEnd()) {
        QString linea = in.readLine().trimmed();
        if (!linea.isEmpty()) {
            lineas.push_back(linea);
        }
    }
    archivo.close();
    return lineas;
}

// Compara la fecha de vencimiento de algun archivo con la fecha "Actual"
bool niveles::compararFecha(const QString& fechaStr, const QString& fechaActualStr) {
    QDate fecha = QDate::fromString(fechaStr, "dd/MM/yyyy");
    QDate fechaActual = QDate::fromString(fechaActualStr, "dd/MM/yyyy");

    if (!fecha.isValid() || !fechaActual.isValid()) {
        qDebug() << "Error en formato de fechas:" << fechaStr << fechaActualStr;
        return false;
    }

    return fecha >= fechaActual;
}

//Verifica si el sello del papel presentado el el correcto
bool niveles::verificarSello(const QString& rutaArchivo, const QString& selloEsperado) {
    QFile archivo(rutaArchivo);
    if (!archivo.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "No se pudo abrir el archivo:" << rutaArchivo;
        return false;
    }

    QTextStream in(&archivo);
    QString ultimaLinea;

    while (!in.atEnd()) {
        ultimaLinea = in.readLine();
    }

    archivo.close();

    return ultimaLinea.toLower().trimmed() == selloEsperado.toLower();
}

//Verifica que los datos del DNI sean los correctos: fecha de vencimiento y sello.
bool niveles::controlar_dni(QString fecha) {
    auto lineas = leerArchivo("C:\\Users\\olign\\OneDrive\\Escritorio\\TP2025\\base de datos\\DNI.txt");

    if (lineas.size() < 4) {
        qDebug() << "DNI: Archivo no contiene suficientes datos";
        qDebug() << "Líneas encontradas:" << lineas.size();
        qDebug() << "Líneas requeridas: 4";
        return false;
    }

    bool documentoValido = compararFecha(lineas[3], fecha);
    bool selloValido=verificarSello("C:\\Users\\olign\\OneDrive\\Escritorio\\TP2025\\base de datos\\DNI.txt", "Verde");
    if (!documentoValido) {
        qDebug() << "DNI: Documento expirado";
        qDebug() << "Fecha expiración:" << lineas[3];
        qDebug() << "Fecha actual:" << fecha;
    } else {
        qDebug() << "DNI: Documento válido";
    }
    if(!selloValido){
        documentoValido=false;
        qDebug()<<"Sello incorrecto";
    }

    return documentoValido;
}

//Controla que los datos del ticket de entrada sean los correctos: nombre, ciudad, fecha de vencimiento y sello.
bool niveles::controlar_ticket(QString fecha) {
    auto datosDNI = leerArchivo("C:\\Users\\olign\\OneDrive\\Escritorio\\TP2025\\base de datos\\DNI.txt");
    auto datosTicket = leerArchivo("C:\\Users\\olign\\OneDrive\\Escritorio\\TP2025\\base de datos\\ticket_de_entrada.txt");

    struct {
        bool datosCompletos = false;
        bool nombreCoincide = false;
        bool ciudadCoincide = false;
    } verificaciones;

    verificaciones.datosCompletos = (datosDNI.size() >= 4 && datosTicket.size() >= 3);
    if (!verificaciones.datosCompletos) {
        qDebug() << "Ticket: Datos insuficientes";
        qDebug() << "Líneas DNI:" << datosDNI.size() << "(requeridas: 4)";
        qDebug() << "Líneas Ticket:" << datosTicket.size() << "(requeridas: 3)";
        return false;
    }

    verificaciones.nombreCoincide = (datosDNI[0] == datosTicket[0]);
    if (!verificaciones.nombreCoincide) {
        qDebug() << "Ticket: Los nombres no coinciden";
        qDebug() << "Nombre DNI:" << datosDNI[0];
        qDebug() << "Nombre Ticket:" << datosTicket[0];
    }

    verificaciones.ciudadCoincide = (datosDNI[2] == datosTicket[1]);
    if (!verificaciones.ciudadCoincide) {
        qDebug() << "Ticket: Las ciudades no coinciden";
        qDebug() << "Ciudad DNI:" << datosDNI[2];
        qDebug() << "Ciudad Ticket:" << datosTicket[1];
    }

    bool fechaDNIValida = compararFecha(datosDNI[3], fecha);
    bool fechaTicketValida = compararFecha(datosTicket[2], fecha);
    bool selloValido = verificarSello("C:\\Users\\olign\\OneDrive\\Escritorio\\TP2025\\base de datos\\ticket_de_entrada.txt", "Amarillo");
    if (!fechaDNIValida || !fechaTicketValida) {
        qDebug() << "Ticket: Documentos expirados";
        if (!fechaDNIValida) {
            qDebug() << "DNI expirado - Fecha expiración:" << datosDNI[3];
        }
        if (!fechaTicketValida) {
            qDebug() << "Ticket expirado - Fecha expiración:" << datosTicket[2];
        }
        qDebug() << "Fecha actual:" << fecha;
    }

    bool ticketValido = verificaciones.nombreCoincide &&
                        verificaciones.ciudadCoincide &&
                        fechaDNIValida &&
                        fechaTicketValida &&
                        selloValido;

    if (ticketValido) {
        qDebug() << "Ticket: Documento válido";
    } else {
        qDebug() << "Ticket: Documento inválido";
    }
    return ticketValido;
}

//Verifica que los datos del permiso de trabajo sean validos: nombre, fecha de vencimiento y sello
bool niveles::controlar_permiso(QString fecha) {
    auto datosDNI = leerArchivo("C:\\Users\\olign\\OneDrive\\Escritorio\\TP2025\\base de datos\\DNI.txt");
    auto datosPermiso = leerArchivo("C:\\Users\\olign\\OneDrive\\Escritorio\\TP2025\\base de datos\\trabajo.txt");
     bool selloValido=verificarSello("C:\\Users\\olign\\OneDrive\\Escritorio\\TP2025\\base de datos\\permiso_de_trabajo.txt", "Verde");

    if (datosDNI.size() < 4 || datosPermiso.size() < 2) {
        qDebug() << "Datos insuficientes en archivos de DNI o permiso de trabajo";
        return false;
    }

    // Verificar nombre
    if (datosDNI[0] != datosPermiso[0]) {
        qDebug() << "Los nombres no coinciden:";
        qDebug() << "DNI:" << datosDNI[0];
        qDebug() << "Permiso:" << datosPermiso[0];
        return false;
    }

    QDate fechaActual = QDate::fromString(fecha, "dd/MM/yyyy");
    QDate fechaPermiso = QDate::fromString(datosPermiso[1], "dd/MM/yyyy");

    if (!fechaActual.isValid() || !fechaPermiso.isValid()) {
        qDebug() << "Error en formato de fechas del permiso";
        return false;
    }

    if (fechaPermiso < fechaActual) {
        qDebug() << "Permiso de trabajo expirado";
        qDebug() << "Fecha actual:" << fecha;
        qDebug() << "Fecha permiso:" << datosPermiso[1];
        return false;
    }
    if(!selloValido){
        qDebug() << "Sello incorrecto";
        return false;
    }
    return true;
}

//Controla que los datos de la visa sean los correctos: nombre, ciudad, fecha de nacimiento, vencimiento, razon y sello.
bool niveles::controlar_visa(QString fecha) {
    auto datosDNI = leerArchivo("C:\\Users\\olign\\OneDrive\\Escritorio\\TP2025\\base de datos\\DNI.txt");
    auto datosVisa = leerArchivo("C:\\Users\\olign\\OneDrive\\Escritorio\\TP2025\\base de datos\\visa.txt");

    if (datosDNI.size() < 4 || datosVisa.size() < 5) {
        qDebug() << "Datos insuficientes en archivos de DNI o visa";
        return false;
    }

    struct {
        bool nombre = false;
        bool fechaNacimiento = false;
        bool ciudad = false;
        bool fechaExpiracion = false;
        bool razon = false;
        bool razonEsTrabajo = false;
    } verificaciones;

    verificaciones.nombre = (datosDNI[0] == datosVisa[0]);
    if (!verificaciones.nombre) {
        qDebug() << "Los nombres no coinciden";
        qDebug() << "DNI:" << datosDNI[0];
        qDebug() << "Visa:" << datosVisa[0];
    }

    verificaciones.fechaNacimiento = (datosDNI[1] == datosVisa[1]);
    if (!verificaciones.fechaNacimiento) {
        qDebug() << "Las fechas de nacimiento no coinciden";
        qDebug() << "DNI:" << datosDNI[1];
        qDebug() << "Visa:" << datosVisa[1];
    }

    verificaciones.ciudad = (datosDNI[2] == datosVisa[2]);
    if (!verificaciones.ciudad) {
        qDebug() << "Las ciudades no coinciden";
        qDebug() << "DNI:" << datosDNI[2];
        qDebug() << "Visa:" << datosVisa[2];
    }

    QDate fechaActual = QDate::fromString(fecha, "dd/MM/yyyy");
    QDate fechaVisa = QDate::fromString(datosVisa[3], "dd/MM/yyyy");

    if (!fechaActual.isValid() || !fechaVisa.isValid()) {
        qDebug() << "Error en formato de fechas de la visa";
        return false;
    }

    verificaciones.fechaExpiracion = (fechaVisa >= fechaActual);
    if (!verificaciones.fechaExpiracion) {
        qDebug() << "Visa expirada";
        qDebug() << "Fecha actual:" << fecha;
        qDebug() << "Fecha visa:" << datosVisa[3];
    }

    if (datosVisa.size() >= 5) {
        verificaciones.razonEsTrabajo = (datosVisa[4].trimmed().toLower() == "trabajo");
        if (!verificaciones.razonEsTrabajo) {
            qDebug() << "La razón de la visa no es Trabajo";
            qDebug() << "Razón en visa:" << datosVisa[4];
        }
    }

    bool selloValido = verificarSello("C:\\Users\\olign\\OneDrive\\Escritorio\\TP2025\\base de datos\\visa.txt", "Rojo");

    return verificaciones.nombre &&
           verificaciones.fechaNacimiento &&
           verificaciones.ciudad &&
           verificaciones.fechaExpiracion &&
           verificaciones.razonEsTrabajo &&
           selloValido;
}

bool niveles::nivel1(QString fecha) {
    return controlar_dni(fecha);
}

bool niveles::nivel2(QString fecha) {
    int verificaciones = 0;
    if (controlar_dni(fecha)) verificaciones++;
    if (controlar_ticket(fecha)) verificaciones++;
    return verificaciones == 2;
}

bool niveles::nivel3(QString fecha) {
    int verificaciones = 0;

    if (controlar_dni(fecha)) {
        verificaciones++;
        qDebug() << "DNI controlado correctamente";
    } else {
        qDebug() << "error al controlar DNI";
    }

    if (controlar_ticket(fecha)) {
        verificaciones++;
        qDebug() << "ticket controlado correctamente";
    } else {
        qDebug() << "error al controlar ticket";
    }

    if (controlar_permiso(fecha)) {
        verificaciones++;
        qDebug() << "permiso controlado correctamente";
    } else {
        qDebug() << "error al controlar permiso";
    }

    if (controlar_visa(fecha)) {
        verificaciones++;
        qDebug() << "visa controlada correctamente";
    } else {
        qDebug() << "error al controlar visa";
    }

    return verificaciones == 4;
}

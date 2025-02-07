// niveles.h
#ifndef NIVELES_H
#define NIVELES_H
#include <QString>
#include <vector>

class niveles {
public:
    niveles();
    bool nivel1(QString fecha);
    bool nivel2(QString fecha);
    bool nivel3(QString fecha);
    void pasar_nivel();

private:
    bool verificarSello(const QString& rutaArchivo, const QString& selloEsperado);
    bool compararFecha(const QString& fechaStr, const QString& fechaActualStr);
    bool controlar_dni(QString fecha);
    bool controlar_ticket(QString fecha);
    bool controlar_permiso(QString fecha);
    bool controlar_visa(QString fecha);
    std::vector<QString> leerArchivo(const QString& rutaArchivo);
};
#endif // NIVELES_H

#include <QMessageBox>
#include <cstdlib>
#include <ctime>
#include "dni.h"
class creardocumentos : public QWidget {
private:
    std::string nombreGlobal;    // Para almacenar el nombre seleccionado
    std::string apellidoGlobal;  // Para almacenar el apellido seleccionado


    std::string seleccionarAleatoria(const std::vector<std::string>& lineas);
    // Carga todas las líneas de un archivo en un vector
    std::vector<std::string> cargarLineas(const std::string& rutaArchivo);
    void cargarArchivoEnDNI(DNI *ventanaDNI);
    void generarNombreApellidoGlobal();  // Nueva función
public:
    void Crear_Archivos(std::string ruta, std::string tipo);
    creardocumentos();
};

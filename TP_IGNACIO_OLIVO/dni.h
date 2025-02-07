#ifndef DNI_H
#define DNI_H

#include <QWidget>

namespace Ui {
class DNI;
}

class DNI : public QWidget
{
    Q_OBJECT

public:
    explicit DNI(QWidget *parent = nullptr);
    ~DNI();

    // Cargar texto en el editor de texto
    void cargarTexto(const QString &texto);

private:
    Ui::DNI *ui;
    void limpiar();
    // Métodos auxiliares
    void configurarInterfaz(); // Configura las propiedades iniciales del UI
    void inicializarDNI();     // Crea y carga documentos relacionados con el DNI
};

#endif // DNI_H

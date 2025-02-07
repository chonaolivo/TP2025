#ifndef TRABAJO_H
#define TRABAJO_H

#include <QWidget>

namespace Ui {
class trabajo;  // Asegúrate de tener la declaración de la clase Ui::trabajo
}

class trabajo : public QWidget
{
    Q_OBJECT

public:
    explicit trabajo(QWidget *parent = nullptr);
    ~trabajo();

    void cargarTexto(const QString &texto);

private:
    Ui::trabajo *ui;
};

#endif // TRABAJO_H

#ifndef VISA_H
#define VISA_H

#include <QWidget>

namespace Ui {
class visa;
}

class visa : public QWidget
{
    Q_OBJECT

public:
    explicit visa(QWidget *parent = nullptr);
    ~visa();

    // Función para cargar texto en el QPlainTextEdit
    void cargarTexto(const QString &texto);

private:
    Ui::visa *ui;
};

#endif // VISA_H

#ifndef TICKET_DE_ENTRADA_H
#define TICKET_DE_ENTRADA_H

#include <QWidget>

namespace Ui {
class ticket_de_entrada;
}

class ticket_de_entrada : public QWidget
{
    Q_OBJECT

public:
    explicit ticket_de_entrada(QWidget *parent = nullptr);
    ~ticket_de_entrada();
    void cargarTexto(const QString &texto);

private:
    Ui::ticket_de_entrada *ui;
};

#endif // TICKET_DE_ENTRADA_H

#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include "niveles.h"
#include "dni.h"
#include "trabajo.h"
#include "ticket_de_entrada.h"
#include "visa.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    //variables
    int contadoraciertos;
    int contadorfallos;
    int Personas_Restantes;
    DNI nuevoDNI;

    void presentarDNI();
    void presentarTICKET();
    void presentarTRABAJO();
    void presentarVISA();
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:


    void presentarVentanas(int nivel);
    //funciones
    void manejarDecision(bool aprobado);
    void inicializarNivel(int nivel);
    void actualizarContador(int fila, int& contador);
    void Contador();
    void Iniciar_Contador();
    void cargar_planilla_de_control();
    void on_Info_button_clicked();
    void on_Jugar_Button_clicked();
    void on_Aprobado_Button_clicked();
    void on_Denegado_Button_clicked();

    void on_Guardar_Button_clicked();

    void on_Cargar_Button_clicked();

private:

    bool todasVentanasCerradas(); // Nueva función auxiliar

    DNI* ventanaDNI;  // Puntero a la ventana DNI actual
    trabajo* ventanaTrabajo;
    ticket_de_entrada* ventanaTicket;
    visa* ventanaVisa;

    niveles *pasar; // Declarar en MainWindow.h
    Ui::MainWindow *ui;
    QTimer *tiempo;         // Timer para actualizar el label
    int Segundos_Restantes;  // Contador regresivo
};
#endif // MAINWINDOW_H

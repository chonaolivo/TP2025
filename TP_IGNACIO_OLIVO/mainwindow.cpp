#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "reglas.h"
#include "dni.h"
#include "ticket_de_entrada.h"
#include "trabajo.h"
#include "visa.h"
#include "niveles.h"
#include "cargar_guardar.h"

//librerias
#include <QTimer>
#include <QDebug>
#include <QMessageBox>

//en el constructor de la clase MainWindow se inician las variables globales y clases necesarias para las funciones
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , ventanaDNI(nullptr)
    , ventanaTrabajo(nullptr)
    , ventanaTicket(nullptr)
    , ventanaVisa(nullptr)
    , contadoraciertos(0)
    , contadorfallos(0)
    , Personas_Restantes(0)
    , Segundos_Restantes(0)
    , pasar(new niveles()) // Inicializar pasar
{
    ui->setupUi(this);
    setWindowTitle("TP IGNACIO OLIVO 2025");
    //cargamos la planilla con los datos basicos para inciar el programa
    cargar_planilla_de_control();
    //Creamos el contador
    tiempo = new QTimer(this);
    //conectamos el contedor con el MainWindow
    connect(tiempo, &QTimer::timeout, this, &MainWindow::Contador);
}

//dentro del destructor liberamos la memoria de la clase pasar
MainWindow::~MainWindow()
{
    if (ventanaDNI) {
        delete ventanaDNI;
        ventanaDNI = nullptr;
    }
    delete pasar; // Liberar memoria del puntero
    delete ui;
}

//Boton que muestra las reglas del juego: creamos la ventana y agregamos el atributo para borrarla al cerrarla
void MainWindow::on_Info_button_clicked()
{
    Reglas *VentanaRegla = new Reglas();
    VentanaRegla->setAttribute(Qt::WA_DeleteOnClose);
    VentanaRegla->show();
}

/*
Boton Jugar:
- Iniciamos el timmer
- establecemos en 0 el contador de aciertos y de fallos.
- Cerramos las ventanas abiertas para evitar errores o sobrecarga de memoria.
- Iniciamos el nivel 1.
*/
void MainWindow::on_Jugar_Button_clicked()
{
    Iniciar_Contador();

    contadoraciertos = 0;
    contadorfallos = 0;

    if (!todasVentanasCerradas()) {
        presentarVentanas(0);
    }

    inicializarNivel(1);
    presentarVentanas(1);
}

/*
Funcion global para inciar nivel:
-  otorga el valor correspondiente de personas restantes según el nivel.
- otorga el valor correspondiente al Label nivel_label según el nivel actual.
*/
void MainWindow::inicializarNivel(int nivel) {
    switch (nivel) {
    case 1:
        Personas_Restantes = 5;
        break;
    case 2:
        Personas_Restantes = 7;
        break;
    case 3:
        Personas_Restantes = 10;
        break;
    default:
        qWarning() << "Nivel inválido: " << nivel;
        return;
    }
    ui->nivel_label->setText(QString::number(nivel));
    ui->personasR_Label->setText(QString::number(Personas_Restantes));
}

/*Carga los datos en la planilla de control para que el jugador esté al tanto del juego.
  Configura el texto y detalles del QListWidget.*/
void MainWindow::cargar_planilla_de_control()
{
    // Limpiar y configurar planilla
    ui->Planilla_Control->clear();
    QStringList items = {"Planilla de control", "", "Aciertos: 0", "", "Fallos: 0"};
    ui->Planilla_Control->addItems(items);

    QListWidgetItem* item = ui->Planilla_Control->item(0);
    if (item) item->setTextAlignment(Qt::AlignCenter);

    ui->Planilla_Control->setSelectionMode(QAbstractItemView::NoSelection);
    ui->Planilla_Control->setStyleSheet(
        "QListWidget::item:hover { background: transparent; }"
        "QListWidget::item { background: transparent; }"
        );
}

void MainWindow::Iniciar_Contador()
{
    Segundos_Restantes = 75;
    ui->Tiempo_Label->setText("Tiempo: 75 s");
    tiempo->start(1000); // Actualizar cada segundo
}

/*Actualiza la variable Segundos_Restantes para que el Label que muestra los segundos faltantes se actualice.
  Verifica si el contador llegó a cero para así detener el mismo y dar el mensaje de finalizado el juego*/
void MainWindow::Contador()
{
    if (--Segundos_Restantes > 0) {
        ui->Tiempo_Label->setText(QString("Tiempo: %1 s").arg(Segundos_Restantes));
    } else {
        tiempo->stop();
        ui->Tiempo_Label->setText("¡PERDISTE!");
    }
}

/*
actualizarContador:
- El primer condicional verifica que los datos pasados sean los correctos.
- El segundo condicional verifica que el item exista.
- Se obtiene los datos de aciertos y fallos para verificar si el jugador perdió.
- El tercer condicional verifica si el contador de fallos llegó a 3:
    - Se llama a la función que guarda los aciertos y fallos del jugador.
    - Se actualiza todo el ui para poder volver a jugar.
*/
void MainWindow::actualizarContador(int fila, int& contador) {
    if (fila >= 0 && fila < ui->Planilla_Control->count()) {
        contador++;
        QListWidgetItem* item = ui->Planilla_Control->item(fila);
        if (item) {
            QString textoBase = item->text().split(":").first();
            item->setText(QString("%1: %2").arg(textoBase).arg(contador));

            if (fila == 4 && contador >= 3) {
                if (tiempo && tiempo->isActive()) {
                    tiempo->stop();
                }

                cargar_guardar::guardarLog(contadoraciertos, contadorfallos);
                QMessageBox::critical(this, "Game Over", "¡Has perdido! Demasiados errores.");

                if (ventanaDNI) {
                    ventanaDNI->close();
                    delete ventanaDNI;
                    ventanaDNI = nullptr;
                }
                if (ventanaTicket) {
                    ventanaTicket->close();
                    delete ventanaTicket;
                    ventanaTicket = nullptr;
                }
                if (ventanaTrabajo) {
                    ventanaTrabajo->close();
                    delete ventanaTrabajo;
                    ventanaTrabajo = nullptr;
                }
                if (ventanaVisa) {
                    ventanaVisa->close();
                    delete ventanaVisa;
                    ventanaVisa = nullptr;
                }

                ui->nivel_label->setText("0");
                Personas_Restantes = 0;
                ui->personasR_Label->setText("0");
                ui->Tiempo_Label->setText("Tiempo: ");

                contadoraciertos = 0;
                contadorfallos = 0;

                QListWidgetItem* itemAciertos = ui->Planilla_Control->item(2);
                QListWidgetItem* itemFallos = ui->Planilla_Control->item(4);
                if (itemAciertos) {
                    itemAciertos->setText("Aciertos: 0");
                }
                if (itemFallos) {
                    itemFallos->setText("Fallos: 0");
                }
            }
        }
    } else {
        qWarning() << "Fila fuera de rango en actualizarContador: " << fila;
    }
}

//Esta funcion inicializa la ventana que muestra los datos del dni de la persona.
void MainWindow::presentarDNI() {
    if (ventanaDNI) {
        ventanaDNI->close();
        delete ventanaDNI;
        ventanaDNI = nullptr;
    }
    ventanaDNI = new DNI();
    ventanaDNI->show();
}

//Esta funcion muestra el ticket de entrada de cada persona
void MainWindow::presentarTICKET() {
    static ticket_de_entrada* ventana = new ticket_de_entrada();
    ventana->show();
}

// Botón Aprobado: el jugador define a la persona como apta para ingresar al pais.
void MainWindow::on_Aprobado_Button_clicked()
{
    manejarDecision(true);
}

//Boton denegado: el jugador define a la persona como no apta para ingresar al pais.
void MainWindow::on_Denegado_Button_clicked()
{
    manejarDecision(false);
}

/*
Toma la desición del jugador y:
- Extrae la fecha "Actual"
- Crea un booleano que va a guardar la informacion de si es correcta la desición del jugador, o no.
- Obtiene el valor del nivel actual para que el programa sepa que datos ha de revisar.
- Actualiza el contador de aciertos o fallos segun sea necesario.
- Actualiza el contador de personas y verifica que si el contador llego a 0:
    - En caso de que llegue a cero y sea el ultimo nivel, se envía un mensaje al jugador de que ganó.
    - En caso de que llegue a cero y no sea el ultimo nivel se pasa al siguiente nivel.
*/
void MainWindow::manejarDecision(bool aprobado) {
    if (!pasar) {
        qDebug() << "Error: pasar no está inicializado";
        return;
    }

    QString fecha = ui->fecha_label->text();
    if (fecha.isEmpty()) {
        qDebug() << "Error: fecha vacía";
        return;
    }

    bool verificar = false;
    int nivel = ui->nivel_label->text().toInt();

    qDebug() << "Nivel actual:" << nivel;
    qDebug() << "Fecha actual:" << fecha;

    switch (nivel) {
    case 1:
        verificar = pasar->nivel1(fecha);
        qDebug() << "Resultado nivel 1:" << verificar;
        break;
    case 2:
        verificar = pasar->nivel2(fecha);
        qDebug() << "Resultado nivel 2:" << verificar;
        break;
    case 3:
        verificar = pasar->nivel3(fecha);
        qDebug() << "Resultado nivel 3:" << verificar;
        break;
    default:
        qWarning() << "Nivel desconocido en manejarDecisión: " << nivel;
        return;
    }

    if (verificar == aprobado) {
        actualizarContador(2, contadoraciertos);
    } else {
        actualizarContador(4, contadorfallos);
    }

    if (Personas_Restantes > 0) {
        Personas_Restantes--;
        ui->personasR_Label->setText(QString::number(Personas_Restantes));

        if (Personas_Restantes == 0) {
            if (nivel < 3) {
                QMessageBox::information(this, "¡Nivel Completado!",
                                         QString("¡Has completado el nivel %1!").arg(nivel));
                inicializarNivel(nivel + 1);
                presentarVentanas(nivel + 1);
            } else {
                QMessageBox::information(this, "¡Felicitaciones!",
                                         "¡Has completado todos los niveles!");
                inicializarNivel(1); // Volver al nivel 1
                presentarVentanas(1);
                //guardar logs
                cargar_guardar::guardarLog(contadoraciertos, contadorfallos);
            }
        } else {
            // Si aún quedan personas, solo actualizar las ventanas
            presentarVentanas(nivel);
        }
    }
}

//Funcion Booleana que devuelve el estado de las ventanas (cerradas o abiertas)
bool MainWindow::todasVentanasCerradas() {
    return (ventanaDNI == nullptr &&
            ventanaTicket == nullptr &&
            ventanaTrabajo == nullptr &&
            ventanaVisa == nullptr);
}

/*
Funcion que abre las ventanas segun el nivel:
- En caso de ser 1 abre solo la de DNI.
- En caso de ser 2 abre la de DNI y el ticket de entrada.
- En caso de ser 3 abre el DNI, el ticket, el permiso de trabajo y la visa.
- En caso de ser 0, cierra todas las ventanas.
*/
void MainWindow::presentarVentanas(int nivel) {
    // Primero cerramos todas las ventanas existentes
    if (ventanaDNI) {
        ventanaDNI->close();
        delete ventanaDNI;
        ventanaDNI = nullptr;
    }
    if (ventanaTicket) {
        ventanaTicket->close();
        delete ventanaTicket;
        ventanaTicket = nullptr;
    }
    if (ventanaTrabajo) {
        ventanaTrabajo->close();
        delete ventanaTrabajo;
        ventanaTrabajo = nullptr;
    }
    if (ventanaVisa) {
        ventanaVisa->close();
        delete ventanaVisa;
        ventanaVisa = nullptr;
    }

    if (nivel == 0) return;

    try {
        switch (nivel) {
        case 1:
            ventanaDNI = new DNI();
            ventanaDNI->show();
            qDebug() << "Nivel 1: Mostrando ventana DNI";
            break;

        case 2:
            ventanaDNI = new DNI();
            ventanaTicket = new ticket_de_entrada();
            ventanaDNI->show();
            ventanaTicket->show();
            qDebug() << "Nivel 2: Mostrando ventanas DNI y Ticket";
            break;

        case 3:
            ventanaDNI = new DNI();
            ventanaTicket = new ticket_de_entrada();
            ventanaTrabajo = new trabajo();
            ventanaVisa = new visa();
            ventanaDNI->show();
            ventanaTicket->show();
            ventanaTrabajo->show();
            ventanaVisa->show();
            qDebug() << "Nivel 3: Mostrando todas las ventanas";
            break;

        default:
            qWarning() << "Nivel no válido:" << nivel;
            break;
        }
    } catch (const std::exception& e) {
        qWarning() << "Error al crear ventanas:" << e.what();
        QMessageBox::critical(this, "Error", "Error al crear las ventanas del nivel");
    }
}

/*
Boton Guardar:
- pasa los datos (Tiempo restante, nivel actual, personas restantes
                  y contadores de acietos y fallos)a la funcion guardarEstadoBinario.
- Muestra un mensaje para confirmar el guardado de los datos.
*/
void MainWindow::on_Guardar_Button_clicked()
{
    cargar_guardar::guardarEstadoBinario(
        Segundos_Restantes,
        ui->nivel_label->text().toInt(),
        Personas_Restantes,
        contadoraciertos,
        contadorfallos
        );

    QMessageBox::information(this, "Guardado", "Los datos han sido guardados exitosamente.");
}

/*
Boton cargar:
- Crea funciones para almacenar los datos del archivo binario
- Crea una sentencia que verifica si es posible extraer los datos
    -  En caso de no ser posible, envía un mensaje el usuario.
    - En caso de ser posible actualiza el ui.
*/
void MainWindow::on_Cargar_Button_clicked()
{
    int tiempo_restante, nivel, personas_restantes, aciertos, fallos;

    if (cargar_guardar::cargarEstadoBinario(tiempo_restante, nivel, personas_restantes, aciertos, fallos)) {
        Segundos_Restantes = tiempo_restante;
        Personas_Restantes = personas_restantes;
        contadoraciertos = aciertos;
        contadorfallos = fallos;

        ui->nivel_label->setText(QString::number(nivel));
        ui->personasR_Label->setText(QString::number(Personas_Restantes));
        ui->Tiempo_Label->setText(QString("Tiempo: %1 s").arg(Segundos_Restantes));

        QListWidgetItem* itemAciertos = ui->Planilla_Control->item(2);
        QListWidgetItem* itemFallos = ui->Planilla_Control->item(4);
        if (itemAciertos) {
            itemAciertos->setText(QString("Aciertos: %1").arg(contadoraciertos));
        }
        if (itemFallos) {
            itemFallos->setText(QString("Fallos: %1").arg(contadorfallos));
        }

        presentarVentanas(nivel);

        if (Segundos_Restantes > 0) {
            tiempo->start(1000);
        }

        QMessageBox::information(this, "Carga", "Partida cargada exitosamente.");
    } else {
        QMessageBox::warning(this, "Error", "No se pudo cargar la partida guardada.");
    }
}


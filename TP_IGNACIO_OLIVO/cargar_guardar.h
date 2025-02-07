#ifndef CARGAR_GUARDAR_H
#define CARGAR_GUARDAR_H

class cargar_guardar
{
public:
    static void guardarLog(int aciertos, int fallos);
    static void guardarEstadoBinario(int tiempo_restante, int nivel, int personas_restantes, int aciertos, int fallos);
    static bool cargarEstadoBinario(int& tiempo_restante, int& nivel, int& personas_restantes, int& aciertos, int& fallos);
    cargar_guardar();
};

#endif // CARGAR_GUARDAR_H

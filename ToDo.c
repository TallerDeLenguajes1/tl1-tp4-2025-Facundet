#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Tarea
{
    int TareaID;       // Numérico autoincremental comenzando en 1000
    char *Descripcion; //
    int Duracion;      // entre 10 – 100
} Tarea;

typedef struct Nodo
{
    Tarea *T;
    struct Nodo *Siguiente;
} Nodo;

// ---- FUNCIONES ----
Nodo *CrearListaVacia();
Nodo *CrearNodo(int id);
// Nodo * InsertarNodo();

int main()
{
    srand(time(NULL));
    int id = 1000;
    Nodo *TareasPendientes = CrearListaVacia(); // creo dos listas
    Nodo *TareasRealizadas = CrearListaVacia();

    Nodo *tareaUno = CrearNodo(id);

    return 0;
}

// ---- FUNCIONES ----
Nodo *CrearListaVacia()
{
    return NULL;
};

Nodo *CrearNodo(int id)
{
    // NO OLVIDARME DE GUARDAR MEMORIA. SINO EL PROGRAMA NO SE EJECUTA
    // ES PARA CARGAR LA TAREA DEL USUARIO
    Nodo *nuevoNodo = (Nodo *)malloc(sizeof(Nodo));

    //ESCRIBIR EL TIPO TAREA YA QUE LA ESTRUCTURA UNO ES DE ESE TIPO
    nuevoNodo->T = (Tarea*)malloc(sizeof(Tarea));
    nuevoNodo->Siguiente = NULL; // ESTO ES ASÍ SIEMPRE

    nuevoNodo->T->TareaID = id; // VOY AGREGANDO LOS DATOS A LA ESTRUCTURA

    nuevoNodo->T->Descripcion = (char*)malloc(100 * sizeof(char));//RESERVAR MEMORIA PARA LA DESCRIPCION

    printf("\nIngrese la descripcion de la tarea: ");
    fflush(stdin);
    gets(nuevoNodo->T->Descripcion);

    do
    {
        printf("\nIngrese la duracion de la tarea(debe ser entre 10 y 100): ");
        scanf("%d", &nuevoNodo->T->Duracion);
    } while (nuevoNodo->T->Duracion > 100 || nuevoNodo->T->Duracion < 10);
    

    return nuevoNodo;
};

//  Nodo * InsertarNodo() {}

/*
    Desarrolle una interfaz de carga de tareas para solicitar tareas pendientes, en la cual se solicite descripción y duración de la misma (el id debe ser generado automáticamente por el sistema, de manera autoincremental comenzando desde el número 1000). Al cabo de cada tarea consulte al usuario si desea ingresar una nueva tarea o finalizar la carga.
*/
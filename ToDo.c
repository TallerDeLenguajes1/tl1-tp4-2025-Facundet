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
Nodo * InsertarNodo(Nodo* nodo, Nodo** start);
void mostrarLista(Nodo* lista);




int main()
{
    srand(time(NULL));
    int id = 1000, seguirConTarea;

    Nodo *ListaTareasPendientes = CrearListaVacia(); // creo dos listas
    Nodo *ListaTareasRealizadas = CrearListaVacia();


    do
    {
        Nodo *tarea1 = CrearNodo(id++);
        printf("\nQuiere ingresar una tarea nueva?\n>> SI = 1\n>> NO = 0\nRespuesta: \n");
        scanf("%d", &seguirConTarea);
        InsertarNodo(tarea1, &ListaTareasPendientes); // -- USO & PARA OBTENER LA DIRECCION DE MEMORIA DEL PUTNERO DOBLE -- 
    } while (seguirConTarea == 1);

    printf("\n//LISTA DE TAREAS PENDIENTES:");
    mostrarLista(ListaTareasPendientes);

    return 0;
}





// ---- FUNCIONES ----
Nodo *CrearListaVacia()
{
    return NULL;
};

Nodo *CrearNodo(int id)
{
    // ESTA FUNCIÓN ES PARA CARGAR LA TAREA DEL USUARIO
    // NO OLVIDARME DE GUARDAR MEMORIA. SINO EL PROGRAMA NO SE EJECUTA
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

 Nodo * InsertarNodo(Nodo* nodo, Nodo** start) {
    //-- USO PUNTERO DOBLE PARA NO TENER QUE USAR RETURN --

    nodo->Siguiente = *start; //ACORDARME DE IGUALAR A UN PUNTERO
    *start = nodo;
}

void mostrarLista(Nodo* lista){
    int i = 0;
    while (lista != NULL) //ESTO ES PARA ITERAR EN LA LISTA
    {
        printf("\nTarea %d", i + 1);
        printf("\nTareaID: %d", lista->T->TareaID);
        printf("\nDescripcion de la tarea: %s", lista->T->Descripcion);
        printf("\nDuracion: %d minutos", lista->T->Duracion);
        lista = lista->Siguiente; //ESTO ES ASÍ SIEMPRE
        i++;
    }
    
}

/*
int TareaID;       // Numérico autoincremental comenzando en 1000
    char *Descripcion; //
    int Duracion; 
*/
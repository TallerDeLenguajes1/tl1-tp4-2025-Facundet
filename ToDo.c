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
Nodo * InsertarNodo(Nodo* nodo, Nodo** start); //EN ESTAR VA LA LISTA A DONDE VOY A INSERTAR 
void mostrarLista(Nodo* lista);
void mostrarDatosNodoEncontrado (Nodo* lista);
Nodo* BuscarPorID(Nodo* start, int ID); //Start representa el comienzo de la lista que quiero recorrer
Nodo* QuitarNodo(Nodo** start, int ID); //PARA QUITAR EL NODO DEBO UTILIZAR PUNTERO DOBLE ASÍ SEA MÁS FÁCIL



int main()
{
    srand(time(NULL));
    int id = 1000, seguirConTarea, buscarID, IDMover;

    Nodo *ListaTareasPendientes = CrearListaVacia(); // creo dos listas
    Nodo *ListaTareasRealizadas = CrearListaVacia();


    do
    {
        Nodo *tarea1 = CrearNodo(id++);
        printf("\nQuiere ingresar una tarea nueva?\n>> SI = 1\n>> NO = 0\nRespuesta: \n");
        scanf("%d", &seguirConTarea);
        InsertarNodo(tarea1, &ListaTareasPendientes); // -- USO apersan PARA OBTENER LA DIRECCION DE MEMORIA DEL PUTNERO DOBLE -- 
    } while (seguirConTarea == 1);

    printf("\n//LISTA DE TAREAS PENDIENTES:");
    mostrarLista(ListaTareasPendientes);

     //BUSCAR LISTA 
    printf("\n\nIngrese el ID que quiere buscar en la lista antes impresa: ");
    fflush(stdin);
    scanf("%d", &buscarID);
    Nodo* NodoEncontrado = BuscarPorID(ListaTareasPendientes, buscarID);
    mostrarDatosNodoEncontrado (NodoEncontrado);

    printf("\n\nIngrese el ID de la tarea que desea marcar como realizada: ");
    fflush(stdin);
    scanf("%d", &IDMover);
    Nodo* TareaMovida = QuitarNodo(&ListaTareasPendientes, IDMover); // USO & PORQUE USÉ UN PUNTERO DOBLE EN ESA FUNCION
    if (TareaMovida != NULL)
    {
        InsertarNodo(TareaMovida, &ListaTareasRealizadas);
        printf("\nLa tarea fue marcada como realizada con exito."); 
    }
    printf("\n//LISTA DE TAREAS REALIZADAS: ");
    mostrarLista(ListaTareasRealizadas);
    

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

void mostrarDatosNodoEncontrado (Nodo* lista){
    printf("\nLos datos del nodo encontrado por ID son: ");
    printf("\nTareaID: %d", lista->T->TareaID);
    printf("\nDescripcion de la tarea: %s", lista->T->Descripcion);
    printf("\nDuracion: %d minutos", lista->T->Duracion);
}

// ----- BUSCAR EN LA LISTA
Nodo* BuscarPorID(Nodo* start, int ID){
    //Start representa el comienzo de la lista que quiero recorrer
    while (start != NULL)
    {
        if (start->T->TareaID == ID)
        {
            return start; //DEVUELVO LA DIRECCION DE LA LISTA
        }
        start = start->Siguiente; //ITERO EN LA LISTA
    }
    return NULL;
}

Nodo* QuitarNodo(Nodo** start, int ID){
    Nodo ** aux = start;

    while (*aux != NULL && (*aux)->T->TareaID == ID)
    {
        aux = &(*aux)->Siguiente;
    }

    if (aux != NULL)
    {
        Nodo* temp = *aux;   // Guardamos el nodo a quitar
        *aux = (*aux)->Siguiente;   // Enlazamos el anterior con el siguiente
        temp->Siguiente = NULL;  // Desconectamos el nodo quitado
        return temp;    // Lo devolvemos para usarlo después
    }
    return NULL;     // Si no se encontró el ID, devolvemos NULL
    
}
#pragma once

/* Estructura de un nodo de la lista */
struct node
{
    int value;         // El valor del Nodo
    struct node* next; // Puntero al siguiente Nodo
};

typedef struct node Node;

/* Estructura de la lista ligada */
struct stack
{
    Node* first; // Puntero al primer Nodo
    int count;   // Cantidad de Nodos
};

typedef struct stack Stack;

//////////////////////////////////////////////////////////////////////////
//                             Funciones                                //
//////////////////////////////////////////////////////////////////////////

/* Crea un Stack vacio */
Stack* stack_init();

/* Inserta el elemento color en la primera posicion del Stack */
void push(Stack* stack, int color);

/* Elimina el elemento de la primera posicion y retorna el valor */
int pop(Stack* stack);

/* Libera todos los recursos asociados al Stack */
void destroy(Stack* stack);

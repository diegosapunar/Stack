#include "stack.h"    // Estructuras de Stack
#include <stdlib.h>
#include <stdio.h>

//////////////////////////////////////////////////////////////////////////
//                             Funciones                                //
//////////////////////////////////////////////////////////////////////////

/* Crear Nodo con el valor value, y retorna un puntero al nodo. */
Node* node_init(int value)
{
    Node* node = malloc(sizeof(Node)); // Creo el Nodo asignandole espacio de memoria

    node -> value = value; // Le asigno value al atributo value
    node -> next = NULL;   // Le asigno next como NULL

    return node; // Retorno el Nodo
}

/* Crea un Stack vacio */
Stack* stack_init()
{
    Stack* stack = malloc(sizeof(Stack)); // Creo el Stack asignandole espacio de memoria

    stack -> first = NULL; // Le asigno al atributo first NULL
    stack -> count = 0;    // Le asigno al atributo count como 0

    return stack;
}

/* Inserta el elemento color en la primera posicion del Stack */
void push(Stack* stack, int color)
{
    Node* node = node_init(color);         // Creo el Nodo a pushear

    if (!stack -> count)                     // El Stack esta Vacio
    {
        stack -> first = node;
    }

    else
    {
        node -> next = stack -> first;    // El siguiente del Nodo a ingresar es el primero del Stack
        stack -> first = node;            // El Nodo a ingresar es el primero del stack
    }

    stack -> count++;                     // Se aumenta la cuenta del Stack
}

/* Elimina el elemento de la primera posicion y retorna el valor */
int pop(Stack* stack)
{
    int color;                            // Color a retornar

    color = stack -> first -> value;  // El valor a retornar toma el valor de la cabeza de la listal Stack

    Node* node = stack -> first;      // Guardo el Nodo a eliminar
    stack -> first = node -> next;

    free(node);                       // Libero memoria del Nodo a eliminar

    stack -> count--;                 // Disminuyo la cuenta del Stack

    return color;
  
}

/* Libera todos los recursos asociados al Stack */
void destroy(Stack* stack)
{
    while(stack -> count){
        pop(stack);
    }
    free(stack);                        // Libero la memoria del Stack
}

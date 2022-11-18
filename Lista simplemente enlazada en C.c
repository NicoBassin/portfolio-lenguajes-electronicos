// Código de introducción a listas simplemente enlazadas.

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Punto point;

struct Punto{
    float coordX;
    float coordY;
    float distancia;
    point* next;
};

void IngresarPunto(void);
void IngresarOrdenado(point*);
void MostrarPuntos(void);
float Distancia(float, float);

point *primerPunto = NULL;

int main()
{
    int control = 1;
    while(control){
        IngresarPunto();
        printf("\nDesea ingresar otro numero? 1: si, 0: no \n");
        scanf("%d", &control);
    }
    MostrarPuntos();
    return 0;
}

void IngresarPunto(void){
    point* nuevoPunto = malloc(sizeof(point));
    printf("Ingrese la coordenada en x: ");
    scanf("%f", &nuevoPunto->coordX);
    printf("Ingrese la coordenada en y: ");
    scanf("%f", &nuevoPunto->coordY);
    nuevoPunto->distancia = Distancia(nuevoPunto->coordX, nuevoPunto->coordY);
    //printf("alo");
    //printf("Paso por aca2 \n");
    if(primerPunto == NULL){ //primer elemento de la lista
        primerPunto = nuevoPunto;
        nuevoPunto->next = NULL;
    }
    //Si la distancia del punto es la mayor... Lo convierte en el primero de la lista.
    else if(nuevoPunto->distancia >= primerPunto->distancia){
        nuevoPunto->next = primerPunto;
        primerPunto = nuevoPunto;
    }
    //Lo ordena en la lista
    else{
        IngresarOrdenado(nuevoPunto);
    }
}

void MostrarPuntos(void){
    struct Punto *aux = primerPunto;
    int i = 0;
    while(aux != NULL){
        printf("\nPunto %d: ", ++i);
        printf("%.2f, %.2f)", aux->coordX, aux->coordY);
        printf("\nDistancia al origen: %.2f", aux->distancia);
        free(aux);
        aux=aux->next;
    }
}

void IngresarOrdenado(point* nuevoPunto){
    //Mientras la distancia del punto sea menor a la del siguiente del último revisado (empezando por el primero), sigue revisando puntos.
    point* aux = primerPunto;
    if(aux->next != NULL){
        while(aux->next->next != NULL && (nuevoPunto->distancia <= aux->next->distancia)){
            aux = aux->next;
        }
    }
    aux = aux->next;
    //Ingresa el punto entre el inmediatamente mayor y el inmediatamente menor.
    nuevoPunto->next = aux->next;
    aux->next = nuevoPunto;
}

float Distancia(float x, float y){
    return sqrt(pow(x, 2) + pow(y, 2));
}
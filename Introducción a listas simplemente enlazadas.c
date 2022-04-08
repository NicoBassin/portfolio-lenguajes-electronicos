// Código de introducción a listas simplemente enlazadas.

#include <stdio.h>

struct Punto{
    int coordX;
    int coordY;
    struct Punto* next;
};

struct Punto *p;

int main()
{
    struct Punto Punto1;
    printf("Ingrese el punto x1: ");
    scanf("%d", &Punto1.coordX);
    printf("Ingrese el punto y1: ");
    scanf("%d", &Punto1.coordY);
    
    struct Punto Punto2;
    printf("Ingrese el punto x2: ");
    scanf("%d", &Punto2.coordX);
    printf("Ingrese el punto y2: ");
    scanf("%d", &Punto2.coordY);
    
    struct Punto Punto3;
    printf("Ingrese el punto x3: ");
    scanf("%d", &Punto3.coordX);
    printf("Ingrese el punto y3: ");
    scanf("%d", &Punto3.coordY);
    
    Punto1.next = &Punto2;
    Punto2.next = &Punto3;
    Punto3.next = NULL;
    
    int i = 1;
    
    for(p = &Punto1; p != NULL; i++, p=p->next){
        printf("\nPunto %d: ", i);
        printf("(%d, %d)", p->coordX, p->coordY);
    }
    
    
    return 0;
}

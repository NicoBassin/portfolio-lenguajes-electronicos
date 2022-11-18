#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ARGNUM 3

int main(int argc, char* argv[]){
   
    srand(time(NULL));
   
    if(argc < ARGNUM){
        printf("No hay suficientes argumentos");
        return 0;
    }
   
    if (argc > ARGNUM){
        printf("Error. Demasiados argumentos");
        return 0;
    }
   
    int caras = atoi(argv[1]);
    int veces = atoi(argv[2]);
    
    if(veces < 0){
        printf("Error. Iteraciones negativas.");
        return 0;
    }

    int* cara = malloc(caras * sizeof(int));

    for(int i = 0; i < veces; i++){
        int n = rand() % (caras) + 1; //rand() % (N-M+1) + M --> numero aleatorio = [M; N]
        cara[n-1]++;
    }

    for(int i = 0; i < caras; i++){
        printf("La cara %d ha salido: %d veces\n", i+1, cara[i]);
    }

    return 0;
}
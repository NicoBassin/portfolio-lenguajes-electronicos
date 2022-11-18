#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define CARAS 6
#define SUMAS 11

int main(int argc, char* argv[]){
   
    srand(time(NULL));

    int veces;
   
    if(argc == 1){
        printf("No ha ingresado argumentos");
        return 0;
    }
   
    if (argc > 2){
        printf("Error. Demasiados argumentos");
        return 0;
    }
   
    veces = atoi(argv[1]);
   

   
    if(veces < 0){
        printf("Error. Iteraciones negativas.");
        return 0;
    }

    int* cara = malloc(CARAS * sizeof(int));
    int* suma = malloc(SUMAS * sizeof(int));

    for(int i = 0; i < veces; i++){
        int n1 = rand() % (CARAS) + 1;  //rand() % (N-M+1) + M --> numero aleatorio = [M; N]
        int n2 = rand() % (CARAS) + 1;
       
        cara[n1-1]++;
        cara[n2-1]++;
       
        suma[n1+n2-2]++;                //suma[0, 10] <-- [2, 12]
    }

    //CARAS
    for(int i = 0; i < CARAS; i++){
        printf("La cara %d ha salido: %d veces\n", i+1, cara[i]);
    }
   
    printf("\n");

    //SUMAS
    for(int i = 0; i < SUMAS; i++){
        printf("La suma ha sido: %d %d veces\n", i+2, suma[i]);
    }

    return 0;
}

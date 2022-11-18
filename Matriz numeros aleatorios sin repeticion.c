#include <stdio.h>
#include <stdlib.h>
#include <time.h>



int main(void)
{
    srand(time(NULL));
    
    //Algoritmo para meter números del 1 aL 100 de manera aleatoria en una matriz de 100 elementos.
    
    //Creo la matriz
    int matriz[100];
    
    //Voy a hacer esto para cada caja
    for(int i = 0; i < 100; i++){
        //Creo una variable unsigned char que voy a usar como bandera.
        unsigned char flag = 0;
        
        //Creo la variable que será mi número aleatorio.
        int n;
        
        do{
            flag = 0;
            
            //Creo un número aleatorio
            n = rand() % (100) + 1;
            
            //Para todas las anteriores cajas...
            for(int j = 0; j < i; j++){
                //Si aparece en alguna caja...
                if(n == matriz[j]){
                    //El flag cambia (se encontró al menos un elemento igual)
                    flag = 1;
                }
            }
        }
        //Repite hasta que se cree un elemento aleatorio no repetido.
        while(flag);
        
        //Se asigna el elemento no repetido a la caja.
        matriz[i] = n;
    }
    
    for(int i = 0; i < 100; i++){
        printf("Caja %d: %d\n", i, matriz[i]);
    }
    
    return 0;
}
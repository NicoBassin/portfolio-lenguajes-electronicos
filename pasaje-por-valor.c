// Pasaje de parámetros a una función por referencia

#include<stdio.h>

int var = 0;

void miFunc(int);

int main(){
    //int var = 0;
    
    miFunc(var);
    
    printf("Valor en main: %d", var);
    
    return 0;
}

void miFunc(int var2){
    printf("Valor en miFunc: %d\n", ++var2);
}

//Modifica la variable
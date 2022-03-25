// Pasaje de parámetros a una función como valor

#include<stdio.h>

int var = 0;

void miFunc(int);

int main(){
    //int var = 0;
    
    miFunc(var);
    
    printf("%d", var);
    
    return 0;
}

void miFunc(int var2){
    printf("%d\n", ++var2);
}
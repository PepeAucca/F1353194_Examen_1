#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() 
{
    int arregloNumeros[15];
    int contador; 
    int divisor; 
    int sumaDivisores;
    // generar semilla para números 
    srand(time(NULL));
  

    // generar arregloNumeros de forma aleatoria
    for(contador = 0; contador < 15; contador ++) 
    {
        arregloNumeros[contador] = rand() % 100;  //  entre 0 y 99
    }

    // Analizar cada número del arreglo
   
    for(contador = 0; contador < 15; contador ++) 
    {
        printf(" %d - ", arregloNumeros[contador]);

        //  sumaDivisores menores que el número
        sumaDivisores = 0;
        for(divisor = 1; divisor < arregloNumeros[contador]; divisor ++) 
        {
            if(arregloNumeros[contador] % divisor == 0)
            {
                sumaDivisores += divisor;
            }
        }

        // Etiquetar números 
        if(sumaDivisores < arregloNumeros[contador]) 
        {
            printf("deficiente\n");
        } 
        else if(sumaDivisores == arregloNumeros[contador]) 
        {
            printf("perfecto\n");
        } 
        else 
        {
            printf("abundante\n");
        }
    }

    return 0;
}


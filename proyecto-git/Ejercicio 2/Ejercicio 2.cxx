#include <stdio.h>
#include <stdlib.h>


int* generarCoeficientes(int n) {
    
    int* coef = (int*)malloc((n+1) * sizeof(int));
    if (coef == NULL) {
        printf("Error: no se pudo asignar memoria.\n");
        exit(1);
    }
   
    coef[0] = 1;
    for (int i = 1; i <= n; i++) {
     
        coef[i] = 1;  
        for (int j = i-1; j > 0; j--) {
            coef[j] = coef[j] + coef[j-1];
        }
    
    }
    return coef; 
}

int main() {
    int n;
    printf("Ingrese un numero entero no negativo (n) para generar (x+1)^n: ");
    scanf("%d", &n);

    int* coef = generarCoeficientes(n);

    
    printf("\nCoeficientes de (x+1)^%d:\n", n);
    for (int i = 0; i <= n; i++) {
        printf("%d ", coef[i]);
    }
    printf("\n");

    printf("\nPolinomio (x+1)^%d:\n", n);
    for (int i = 0; i <= n; i++) {
        
        if (i == 0) {
            printf("%d", coef[i]);
        } else {
            printf(" + %d*x^%d", coef[i], i);
        }
    }
    printf("\n");

    
    int x;
    printf("\nIngrese un valor entero para x: ");
    scanf("%d", &x);

    long long resultado = 0; 
    printf("\nCalculo paso a paso:\n");
    for (int i = 0; i <= n; i++) {
        
        long long potencia = 1;
        for (int p = 0; p < i; p++) {
            potencia *= x;
        }
        long long termino = coef[i] * potencia;
        printf("Termino k=%d: %d * (%d^%d) = %lld\n", i, coef[i], x, i, termino);
        resultado += termino;
    }

    printf("\nResultado final de f(%d) = (x+1)^%d = %lld\n", x, n, resultado);

    
    free(coef);

    return 0;
}

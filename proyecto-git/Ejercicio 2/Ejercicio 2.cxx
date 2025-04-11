#include <stdio.h>
#include <stdlib.h>

// Función para generar coeficientes usando el Triángulo de Pascal
// Retorna un arreglo dinámico con los coeficientes binomiales de (x+1)^n
int* generarCoeficientes(int n) {
    // Creamos un arreglo de n+1 elementos
    int* coef = (int*)malloc((n+1) * sizeof(int));
    if (coef == NULL) {
        printf("Error: no se pudo asignar memoria.\n");
        exit(1);
    }
    // Caso base: para n=0, (x+1)^0 = 1 => coeficiente = 1
    coef[0] = 1;
    for (int i = 1; i <= n; i++) {
        // Calcular la fila i del triángulo de Pascal a partir de la fila (i-1)
        // Se recorre desde el final para no pisar valores que necesitamos
        coef[i] = 1;  // el último coeficiente de cada fila siempre es 1
        for (int j = i-1; j > 0; j--) {
            coef[j] = coef[j] + coef[j-1];
        }
        // Al final de este for, coef[] contiene la fila i del triángulo
    }
    return coef; 
}

int main() {
    int n;
    printf("Ingrese un numero entero no negativo (n) para generar (x+1)^n: ");
    scanf("%d", &n);

    // Generar coeficientes (usando el Triángulo de Pascal)
    int* coef = generarCoeficientes(n);

    // Mostrar coeficientes
    printf("\nCoeficientes de (x+1)^%d:\n", n);
    for (int i = 0; i <= n; i++) {
        printf("%d ", coef[i]);
    }
    printf("\n");

    // Construir y mostrar el polinomio en forma expandida
    // (x+1)^n = c0 + c1*x + c2*x^2 + ... + cn*x^n
    printf("\nPolinomio (x+1)^%d:\n", n);
    for (int i = 0; i <= n; i++) {
        // Si es el primer término (i=0), solo muestra c0
        if (i == 0) {
            printf("%d", coef[i]);
        } else {
            printf(" + %d*x^%d", coef[i], i);
        }
    }
    printf("\n");

    // Pedir un valor de x para la evaluación
    int x;
    printf("\nIngrese un valor entero para x: ");
    scanf("%d", &x);

    // Evaluar f(x) = (x+1)^n, mostrando el paso a paso.
    // f(x) = sum_{k=0}^n coef[k] * x^k
    long long resultado = 0; 
    printf("\nCalculo paso a paso:\n");
    for (int i = 0; i <= n; i++) {
        // Calcular x^i
        long long potencia = 1;
        for (int p = 0; p < i; p++) {
            potencia *= x;
        }
        long long termino = coef[i] * potencia;
        printf("Termino k=%d: %d * (%d^%d) = %lld\n", i, coef[i], x, i, termino);
        resultado += termino;
    }

    printf("\nResultado final de f(%d) = (x+1)^%d = %lld\n", x, n, resultado);

    // Liberar memoria
    free(coef);

    return 0;
}

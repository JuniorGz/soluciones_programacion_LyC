#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


const char *expr;


void skipSpaces() {
    while (*expr && isspace(*expr)) {
        expr++;
    }
}


double parseExpression();
double parseTerm();
double parseFactor();
double parseNumber();


double parseExpression() {
    double result = parseTerm();
    skipSpaces();
    while (*expr == '+' || *expr == '-') {
        char op = *expr;
        expr++;  
        skipSpaces();
        double term = parseTerm();
        if (op == '+')
            result += term;
        else
            result -= term;
        skipSpaces();
    }
    return result;
}


double parseTerm() {
    double result = parseFactor();
    skipSpaces();
    while (*expr == '*' || *expr == '/') {
        char op = *expr;
        expr++;  
        skipSpaces();
        double factor = parseFactor();
        if (op == '*')
            result *= factor;
        else {
            if (factor == 0.0) {
                fprintf(stderr, "Error: División por cero.\n");
                exit(EXIT_FAILURE);
            }
            result /= factor;
        }
        skipSpaces();
    }
    return result;
}


double parseFactor() {
    skipSpaces();
    double result = 0.0;
    if (*expr == '(') {
        expr++;  
        skipSpaces();
        result = parseExpression();
        skipSpaces();
        if (*expr != ')') {
            fprintf(stderr, "Error: Se esperaba ')' \n");
            exit(EXIT_FAILURE);
        }
        expr++;  
    } else {
        result = parseNumber();
    }
    skipSpaces();
    return result;
}


double parseNumber() {
    skipSpaces();
    char *end;
    double value = strtod(expr, &end);
    if (expr == end) {  
        fprintf(stderr, "Error: Número inválido en la expresión.\n");
        exit(EXIT_FAILURE);
    }
    expr = end;
    return value;
}

int main() {
    
    char input[256];
    printf("Ingrese una expresión aritmética: \n");
    if (!fgets(input, sizeof(input), stdin)) {
        fprintf(stderr, "Error al leer la entrada.\n");
        return EXIT_FAILURE;
    }

    
    expr = input;

    
    double resultado = parseExpression();
    
    
    skipSpaces();
    if (*expr != '\0' && *expr != '\n') {
        fprintf(stderr, "Error: Caracteres no reconocidos al final de la expresión: '%s'\n", expr);
        return EXIT_FAILURE;
    }

    printf("El resultado es: %.15g\n", resultado);
    return EXIT_SUCCESS;
}

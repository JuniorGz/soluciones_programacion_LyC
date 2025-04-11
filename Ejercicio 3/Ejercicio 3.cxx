#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Puntero global que apunta a la posición actual de la cadena de entrada
const char *expr;

// Función para omitir espacios en blanco
void skipSpaces() {
    while (*expr && isspace(*expr)) {
        expr++;
    }
}

// Prototipos de funciones de análisis
double parseExpression();
double parseTerm();
double parseFactor();
double parseNumber();

// parseExpression:
// Lee términos separados por '+' o '-'
double parseExpression() {
    double result = parseTerm();
    skipSpaces();
    while (*expr == '+' || *expr == '-') {
        char op = *expr;
        expr++;  // avanzar el operador
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

// parseTerm:
// Lee factores separados por '*' o '/'
double parseTerm() {
    double result = parseFactor();
    skipSpaces();
    while (*expr == '*' || *expr == '/') {
        char op = *expr;
        expr++;  // avanzar el operador
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

// parseFactor:
// Procesa un factor: puede ser un número o una expresión entre paréntesis
double parseFactor() {
    skipSpaces();
    double result = 0.0;
    if (*expr == '(') {
        expr++;  // consumir '('
        skipSpaces();
        result = parseExpression();
        skipSpaces();
        if (*expr != ')') {
            fprintf(stderr, "Error: Se esperaba ')' \n");
            exit(EXIT_FAILURE);
        }
        expr++;  // consumir ')'
    } else {
        result = parseNumber();
    }
    skipSpaces();
    return result;
}

// parseNumber:
// Convierte la parte numérica de la cadena a double (soporta notación científica)
// Se utiliza la función strtod, que reconoce números en notación decimal y científica.
double parseNumber() {
    skipSpaces();
    char *end;
    double value = strtod(expr, &end);
    if (expr == end) {  // No se pudo convertir ningún número
        fprintf(stderr, "Error: Número inválido en la expresión.\n");
        exit(EXIT_FAILURE);
    }
    expr = end;
    return value;
}

int main() {
    // Se reserva un buffer para la cadena de entrada
    char input[256];
    printf("Ingrese una expresión aritmética: \n");
    if (!fgets(input, sizeof(input), stdin)) {
        fprintf(stderr, "Error al leer la entrada.\n");
        return EXIT_FAILURE;
    }

    // Inicializamos el puntero global a la cadena de entrada
    expr = input;

    // Se evalúa la expresión
    double resultado = parseExpression();
    
    // Si quedan caracteres no procesados, se informa un error
    skipSpaces();
    if (*expr != '\0' && *expr != '\n') {
        fprintf(stderr, "Error: Caracteres no reconocidos al final de la expresión: '%s'\n", expr);
        return EXIT_FAILURE;
    }

    printf("El resultado es: %.15g\n", resultado);
    return EXIT_SUCCESS;
}

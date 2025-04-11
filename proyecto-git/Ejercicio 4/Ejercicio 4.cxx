#include <stdio.h>
#include <string.h>
#include <cctype> 

void contar_ocurrencias(char *cadena, char *palabra) {
    int contador = 0;
    int longitud_cadena = strlen(cadena);
    int longitud_palabra = strlen(palabra);
    
    
    for (int i = 0; cadena[i]; i++) {
        cadena[i] = tolower(cadena[i]); 
    }
    
    for (int i = 0; palabra[i]; i++) {
        palabra[i] = tolower(palabra[i]); 
    }

    
    for (int i = 0; i <= longitud_cadena - longitud_palabra; i++) {
        if (strncmp(&cadena[i], palabra, longitud_palabra) == 0) {
            contador++;
            printf("Ocurrencia encontrada en la posición: %d\n", i);
        }
    }

    printf("La palabra '%s' aparece %d veces en la cadena.\n", palabra, contador);
}

int main() {
    char cadena[256];
    char palabra[50];

    printf("Ingrese la cadena: ");
    fgets(cadena, sizeof(cadena), stdin);
    
    
    cadena[strcspn(cadena, "\n")] = 0;

    printf("Ingrese la palabra a buscar: ");
    fgets(palabra, sizeof(palabra), stdin);
    
    
    palabra[strcspn(palabra, "\n")] = 0;

    contar_ocurrencias(cadena, palabra);

    return 0;
}
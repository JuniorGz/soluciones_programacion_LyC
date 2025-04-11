#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

// Valida la parte del tablero del FEN (campo 1)
bool validar_posicion(const char *pos)
{
    char *row_copy = strdup(pos);
    if (row_copy == NULL)
        return false;
    int row_count = 0;
    char *saveptr;
    char *row = strtok_r(row_copy, "/", &saveptr);
    while (row != NULL)
    {
        row_count++;
        int cell_count = 0;
        for (int i = 0; row[i] != '\0'; i++)
        {
            if (isdigit(row[i]))
            {
                cell_count += row[i] - '0';
            }
            else if (strchr("prnbqkPRNBQK", row[i]) != NULL)
            {
                cell_count++;
            }
            else
            {
                free(row_copy);
                return false;
            }
        }
        if (cell_count != 8)
        {
            free(row_copy);
            return false;
        }
        row = strtok_r(NULL, "/", &saveptr);
    }
    free(row_copy);
    return (row_count == 8);
}

bool validar_color_activo(const char *campo)
{
    return (strlen(campo) == 1 && (campo[0] == 'w' || campo[0] == 'b'));
}

bool validar_enroque(const char *campo)
{
    if (strcmp(campo, "-") == 0)
        return true;
    bool flags[256] = {0};
    for (int i = 0; campo[i] != '\0'; i++)
    {
        char c = campo[i];
        if (c != 'K' && c != 'Q' && c != 'k' && c != 'q')
        {
            return false;
        }
        if (flags[(unsigned char)c])
            return false;
        flags[(unsigned char)c] = true;
    }
    return true;
}

bool validar_en_passant(const char *campo)
{
    if (strcmp(campo, "-") == 0)
        return true;
    if (strlen(campo) != 2)
        return false;
    if (campo[0] < 'a' || campo[0] > 'h')
        return false;
    if (campo[1] != '3' && campo[1] != '6')
        return false;
    return true;
}

bool validar_fen(const char *fen)
{
    char *fen_copy = strdup(fen);
    if (!fen_copy)
        return false;

    char *tokens[6];
    int token_count = 0;
    char *saveptr;
    char *token = strtok_r(fen_copy, " ", &saveptr);
    while (token != NULL && token_count < 6)
    {
        tokens[token_count++] = token;
        token = strtok_r(NULL, " ", &saveptr);
    }
    if (token_count != 6)
    {
        free(fen_copy);
        return false;
    }

    if (!validar_posicion(tokens[0]))
    {
        free(fen_copy);
        return false;
    }
    if (!validar_color_activo(tokens[1]))
    {
        free(fen_copy);
        return false;
    }
    if (!validar_enroque(tokens[2]))
    {
        free(fen_copy);
        return false;
    }
    if (!validar_en_passant(tokens[3]))
    {
        free(fen_copy);
        return false;
    }
    char *endptr;
    long halfmove = strtol(tokens[4], &endptr, 10);
    if (*endptr != '\0' || halfmove < 0)
    {
        free(fen_copy);
        return false;
    }
    long fullmove = strtol(tokens[5], &endptr, 10);
    if (*endptr != '\0' || fullmove < 1)
    {
        free(fen_copy);
        return false;
    }

    free(fen_copy);
    return true;
}

int main()
{
    char fen[256];
    printf("Ingrese la cadena FEN: ");
    if (!fgets(fen, sizeof(fen), stdin))
    {
        fprintf(stderr, "Error al leer la cadena.\n");
        return EXIT_FAILURE;
    }
    fen[strcspn(fen, "\n")] = '\0';

    if (validar_fen(fen))
        printf("El FEN es válido.\n");
    else
        printf("El FEN es inválido.\n");

    return EXIT_SUCCESS;
}

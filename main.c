#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Versão recursiva (baseada no código fornecido)
int eh_palindromo_recursivo(char *palavra, int ini, int fim) {
    if (ini >= fim)
        return 1;
    if (tolower(palavra[ini]) != tolower(palavra[fim]))
        return 0;
    return eh_palindromo_recursivo(palavra, ini + 1, fim - 1);
}

// Versão iterativa
int eh_palindromo_iterativo(char *palavra) {
    int ini = 0;
    int fim = strlen(palavra) - 1;
    
    while (ini < fim) {
        if (tolower(palavra[ini]) != tolower(palavra[fim]))
            return 0;
        ini++;
        fim--;
    }
    return 1;
}

// Função auxiliar para remover espaços e pontuação (opcional)
void prepara_string(char *str) {
    int i, j = 0;
    for (i = 0; str[i]; i++) {
        if (isalpha(str[i])) {
            str[j++] = tolower(str[i]);
        }
    }
    str[j] = '\0';
}

int main() {
    char palavra[100];
    
    printf("Digite uma palavra/frase: ");
    fgets(palavra, sizeof(palavra), stdin);
    palavra[strcspn(palavra, "\n")] = '\0'; // Remove o \n do final
    
    // Remove espaços e pontuação (opcional)
    prepara_string(palavra);
    
    // Testando versão recursiva
    if (eh_palindromo_recursivo(palavra, 0, strlen(palavra) - 1)) {
        printf("(Recursivo) É palíndromo!\n");
    } else {
        printf("(Recursivo) Não é palíndromo!\n");
    }
    
    // Testando versão iterativa
    if (eh_palindromo_iterativo(palavra)) {
        printf("(Iterativo) É palíndromo!\n");
    } else {
        printf("(Iterativo) Não é palíndromo!\n");
    }
    
    return 0;
}

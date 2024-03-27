#include <stdio.h>

#define L 50

int main()
{
    FILE *file_pointer;
    char stringa[L];
    char frase[] = "Oggi è primavera\n";
    int i;

    file_pointer = fopen("prova.txt", "w");

    if(!file_pointer)
    {
        printf("Errore nell'apertura del file\n");
        return 1;
    }

    for(i = 0; frase[i] != '\n'; i++)
        fputc(frase[i], file_pointer);
    
    fclose(file_pointer);

    return 0;
}
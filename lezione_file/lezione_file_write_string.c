#include <stdio.h>

#define L 50

int main()
{
    FILE *file_pointer;

    file_pointer = fopen("prova_2.txt", "w");

    if(!file_pointer)
    {
        printf("Errore nell'apertura del file\n");
        return 1;
    }

    fputs("Buongiorno, ", file_pointer);
    fputs("e benvenuti!\n", file_pointer);
    fputs("Questo è un esempio di funzione puts\n", file_pointer);

    fclose(file_pointer);

    return 0;
}
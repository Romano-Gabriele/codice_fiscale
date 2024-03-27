#include <stdio.h>

int main()
{
    FILE *file_pointer;

    file_pointer = fopen("prova_3.txt", "w");

    if(!file_pointer)
    {
        printf("Errore nell'apertura del file\n");
        return 1;
    }

    fprintf(file_pointer, "Buongiorno a tutti!\n");

    fclose(file_pointer);

    return 0;
}
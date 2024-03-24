#include <stdio.h>
#include <string.h>

#define L 50

int main()
{
    //dichiarazione variabili
    int i;
    FILE *file_point = fopen("prova.txt", "r");
    int mese;
    char line[L];

    printf("Inserire mese: ");
    scanf("%d", &mese);

    if(!file_point)
    {
        printf("Errore apertura file");
        return 1;
    }

    while(!EOF)
    {
        if(strstr(line, "GENNAIO"))
        {
            fgets(line, 50, file_point);
            printf("%s", line);
        }
    }

    fclose(file_point);
    
    return 0;
}

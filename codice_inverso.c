#include <stdio.h>
#include <string.h>

#define L 50
#define LCF 16
#define N 3

char cfi[LCF];
char mesi[] = "ABCDEHLMPRST";
char cat[L];

//stampa caratteri nome
void name()
{
    //dichiarazione variabili
    int i;

    printf("NOME: ");

    //stampa caratteri nome
    for(i=3;i<=5;i++)
        printf("%c", cfi[i]);

    printf("\n");
}

//stampa caratteri cognome
void surname()
{
    //dichiarazione variabili
    int i;

    printf("COGNOME: ");

    //stampa caratteri cognome
    for(i=0;i<N;i++)
        printf("%c", cfi[i]);

    printf("\n");
}

//stampa sesso e data di nascita
void date()
{
    //dichiarazione variabili
    int i;

    //stampa giorno di nascita
    if(cfi[9] <= 51)
    {
        printf("SESSO: MASCHIO\n");
        printf("DATA DI NASCITA: ");
        for(i=9;i<=10;i++)
            printf("%c", cfi[i]);
    }
    else
    {
        printf("SESSO: FEMMINA\n");
        printf("DATA DI NASCITA: ");
        printf("%c", cfi[9]-4);
        printf("%c", cfi[10]);
    }

    printf("/");

    //stampa mese di nascita
    for(i=0;i<strlen(mesi);i++)
    {
        if(cfi[8] == mesi[i])
        {
            if(i < 10)
                printf("0");
            printf("%d", i+1);
        }
    }

    printf("/");

    //stampa anno di nascita
    if(cfi[6] > 50 && cfi[7] > 52)
        printf("19");
    else
        printf("20");
    for(i=6;i<=7;i++)
        printf("%c", cfi[i]);

    printf("\n");
}

//stampa luogo di nascita
void place()
{
    //dichiarazione variabili
    FILE *file_pointer;
    char line[L];
    char luogo[L];
    int i=0,j=0;

    for(j=11;j<15;j++)
    {
        cat[i] = cfi[j];
        i++;
    }

    printf("LUOGO DI NASCITA: ");
    
    //apertura file
    file_pointer = fopen("comuni.txt", "r");

    //verifica apertura file
    if(!file_pointer)
        printf("Errore nell'apertura del file\n");

    //trova luogo di nascita
    while(!strstr(line, cat))
        fgets(line, L, file_pointer);

    j=0;
    
    for(i=5;i<L;i++)
    {
        luogo[j] = line[i];
        j++;
    }

    printf("%s", luogo);
        

    fclose(file_pointer);
}

int main()
{
    printf("Inserire codice fiscale: ");
    scanf("%s", cfi);

    name();
    surname();
    date();
    place();

    return 0;
}
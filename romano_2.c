#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define L 50
#define LCF 16

char nome[L];
char cognome[L];
char anno[L];
int mese;
char giorno[L];
char sesso[1];
char luogo[L];

char vocali[L];
char consonanti[L];
char vocali_c[L];
char consonanti_c[L];
char cf[16];
char comune[L];

void maiuscolo(char stringa[])
{
    int i;

    for(i=0;i<strlen(stringa);i++)
        stringa[i] = toupper(stringa[i]);
}

//calcolo caratteri nome
void name(char nome[])
{
    //dichiarazione variabili
    int nvoc,ncons,i;

    //conversione in maiuscolo
    maiuscolo(nome);

    //divisione vocali e consonanti
    for(i=0;i<strlen(nome);i++)
    {
        switch(nome[i])
        {
            case 'A':
            vocali[nvoc] = nome[i];
            nvoc++;
            break;
            case 'E':
            vocali[nvoc] = nome[i];
            nvoc++;
            break;
            case 'I':
            nvoc++;
            vocali[nvoc] = nome[i];
            break;
            case 'O':
            vocali[nvoc] = nome[i];
            nvoc++;
            break;
            case 'U':
            vocali[nvoc] = nome[i];
            nvoc++;
            break;
            default:
            consonanti[ncons] = nome[i];
            ncons++;
        }
    }

    /*//stampa numero vocali
    printf("vocali: %d\n", nvoc);
    //stampa numero consonanti
    printf("consonanti: %d\n", ncons);

    //stampa vocali
    for(i=0;i<strlen(nome);i++)
        printf("%c", vocali[i]);
    printf("\n");
    //stampa consonanti
    for(i=0;i<strlen(nome);i++)
        printf("%c", consonanti[i]);
    printf("\n\n");*/

    //inserimento caratteri nel codice fiscale
    if(ncons >= 4)
    {
        cf[0] = consonanti[0];
        cf[1] = consonanti[2];
        cf[2] = consonanti[3];
        //printf("%c%c%c", consonanti[0], consonanti[2], consonanti[3]);
    }
    else
    {
        switch(ncons)
        {
            case 3:
            for(i=0;i<=3;i++)
                cf[i] = consonanti[i];
            //printf("%c%c%c", consonanti[0], consonanti[1], consonanti[2]);
            break;
            case 2:
            for(i=0;i<=1;i++)
                cf[i] = consonanti[i];
            cf[i+1] = vocali[0];
            //printf("%c%c%c", consonanti[0], consonanti[1], vocali[0]);
            break;
            case 1:
            if(strlen(nome) >= 3)
            {
                cf[0] = consonanti[0];
                cf[1] = vocali[0];
                cf[2] = vocali[1];
                //printf("%c%c%c", consonanti[0], vocali[0], vocali[1]);
            }
            else
            {
                cf[0] = consonanti[0];
                cf[1] = vocali[0];
                cf[2] = 'X';
                //printf("%c%cx", consonanti[0], vocali[0]);
            }
            break;
            default:
            if(strlen(nome) == 2)
            {
                for(i=0;i<=1;i++)
                    cf[i] = vocali[i];
                cf[i+1] = 'X';
                //printf("%c%cx", vocali[0], vocali[1]);
            }
            else
            {
                for(i=0;i<=2;i++)
                    cf[i] = vocali[i];
                //printf("%c%c%c", vocali[0], vocali[1], vocali[2]);
            }
        }
    }

    /*//stampa caratteri nome
    for(i=0;i<=2;i++)
        printf("%c", cf[i]);
    printf("\n");*/
}

//calcolo caratteri cognome
void surname(char cognome[])
{
    //dichiarazione variabili
    int nvoc=0,ncons=0,i;

    //conversione in maiuscolo
    maiuscolo(cognome);

    //divisione vocali_c e consonanti_c
    for(i=0;i<strlen(cognome);i++)
    {
        switch(cognome[i])
        {
            case 'A':
            vocali_c[nvoc] = cognome[i];
            nvoc++;
            break;
            case 'E':
            vocali_c[nvoc] = cognome[i];
            nvoc++;
            break;
            case 'I':
            nvoc++;
            vocali_c[nvoc] = cognome[i];
            break;
            case 'O':
            vocali_c[nvoc] = cognome[i];
            nvoc++;
            break;
            case 'U':
            vocali_c[nvoc] = cognome[i];
            nvoc++;
            break;
            default:
            consonanti_c[ncons] = cognome[i];
            ncons++;
        }
    }

    /*//stampa numero vocali_c
    printf("vocali_c: %d\n", nvoc);
    //stampa numero consonanti_c
    printf("consonanti_c: %d\n", ncons);

    //stampa vocali_c
    for(i=0;i<strlen(cognome);i++)
        printf("%c", vocali_c[i]);
    printf("\n");
    //stampa consonanti_c
    for(i=0;i<strlen(cognome);i++)
        printf("%c", consonanti_c[i]);
    printf("\n\n");*/

    //inserimento caratteri nel codice fiscale
    if(ncons >= 3)
    {
        cf[3] = consonanti_c[0];
        cf[4] = consonanti_c[1];
        cf[5] = consonanti_c[2];
        //printf("%c%c%c", consonanti_c[0], consonanti_c[1], consonanti_c[2]);
    }
    else
    {
        switch(ncons)
        {
            case 2:
            cf[3] = consonanti_c[0];
            cf[4] = consonanti_c[1];
            cf[5] = vocali_c[0];
            //printf("%c%c%c", consonanti_c[0], consonanti_c[1], vocali_c[0]);
            break;
            case 1:
            if(strlen(cognome) >= 3)
            {
                cf[3] = consonanti_c[0];
                cf[4] = vocali_c[0];
                cf[5] = vocali_c[1];
                //printf("%c%c%c", consonanti_c[0], vocali_c[0], vocali_c[1]);
            }
            else
            {
                cf[3] = consonanti_c[0];
                cf[4] = vocali_c[0];
                cf[5] = 'X';
                //printf("%c%cx", consonanti_c[0], vocali_c[0]);
            }
            break;
            default:
            if(strlen(cognome) == 2)
            {
                cf[3] = vocali_c[0];
                cf[4] = vocali_c[1];
                cf[5] = 'X';
                //printf("%c%cx", vocali_c[0], vocali_c[1]);
            }
            else
            {
                cf[3] = vocali_c[0];
                cf[4] = vocali_c[1];
                cf[5] = vocali_c[2];
                //printf("%c%c%c", vocali_c[0], vocali_c[1], vocali_c[2]);
            }
        }
    }

    /*//stampa caratteri cognome
    for(i=3;i<=5;i++)
        printf("%c", cf[i]);
    printf("\n");*/
}

//calcolo caratteri anno di nascita
void year(char anno[])
{
    //dichiarazione variabili
    int i;

    cf[6] = anno[2];
    cf[7] = anno[3];

    /*//stampa caratteri anno di nascita
    for(i=6;i<=7;i++)
        printf("%c", cf[i]);*/
}

//calcolo carattere mese di nascita
void month(int mese)
{
    //dichiarazione variabili
    char valori[] = "ABCDEHLMPRST";

    //verifica valore inserito
    if(mese > 12)
        printf("Mese non valido\n");

    //inserimento carattere mese di nascita
    cf[8] = valori[mese-1];

    /*//stampa carattere mese di nascita
    printf("%c", cf[8]);*/
}

//calcolo carattere giorno di nascita
void day(char giorno[], char sesso[])
{
    //dichiarazione variabili
    int i;

    //conversione in maiuscolo
    maiuscolo(sesso);

    //inserimento caratteri giorno di nascita
    if(strlen(giorno) == 1)
    {
        if(sesso[0] = 'M')
            cf[9] = '0';
        else
            cf[9] = '4';

        cf[10] = giorno[0];
    }
    else
    {
        if(sesso[0] = 'M')
            cf[9] = giorno[0];
        else
            cf[9] = giorno[0] + 4;

        cf[10] = giorno[1];
    }

    /*//stampa caratteri giorno di nascita
    for(i=9;i<=10;i++)
        printf("%c", cf[i]);*/
}

void place(char luogo[])
{
    //dichiarazione variabili
    FILE *file_pointer;
    char line[L];
    int i,j;

    //conversione in maiuscolo
    maiuscolo(luogo);

    //apertura file
    file_pointer = fopen("comuni.txt", "r");

    //verifica apertura file
    if(!file_pointer)
        printf("Errore nell'apertura del file\n");

    while(!strstr(line, luogo))
        fgets(line, L, file_pointer);

    fclose(file_pointer);

    //inserimento caratteri luogo di nascita
    for(i=11;i<=14;i++)
    {
        cf[i] = line[j];
        j++;
    }

    /*//stampa caratteri luogo di nascita
    for(i=11;i<=14;i++)
        printf("%c", cf[i]);*/
}

int main()
{
    //dichiarazione variabili
    int i;

    //inserimento dati
    printf("Inserire nome: ");
    scanf("%s", nome);
    name(nome);
    printf("Inserire cognome: ");
    scanf("%s", cognome);
    surname(cognome);
    printf("Inserire anno di nascita: ");
    scanf("%s", anno);
    year(anno);
    printf("Inserire mese di nascita: ");
    scanf("%d", &mese);
    month(mese);
    printf("Inserire giorno di nascita: ");
    scanf("%s", giorno);
    printf("Inserire sesso (M/F): ");
    scanf("%c", sesso);
    day(giorno, sesso);
    printf("Inserire luogo di nascita: ");
    scanf("%s", luogo);
    place(luogo);

    //stampa codice fiscale
    for(i=0;i<LCF;i++)
        printf("%c", cf[i]);
    printf("\n");

    return 0;
}
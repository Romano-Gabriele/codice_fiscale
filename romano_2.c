#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define L 50
#define LCF 16

char vocali[L];
char consonanti[L];
char vocali_c[L];
char consonanti_c[L];
char cf[16];

//calcolo caratteri nome
void name(char nome[])
{
    //dichiarazione variabili
    int nvoc,ncons,i;

    //conversione in maiuscolo
    for(i=0;i<strlen(nome);i++)
        nome[i] = toupper(nome[i]);

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
    for(i=0;i<strlen(cognome);i++)
        cognome[i] = toupper(cognome[i]);

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
void month(char mese[])
{
    //dichiarazione variabili
    int i;

    //inserimento carattere mese di nascita
    cf[8] = 'x';

    /*//stampa carattere mese di nascita
    printf("%c", cf[8]);*/
}

//calcolo carattere giorno di nascita
void day(char giorno[])
{
    //dichiarazione variabili
    int i;

    //inserimento caratteri giorno di nascita
    if(strlen(giorno) == 1)
    {
        cf[9] = '0';
        cf[10] = giorno[0];
    }
    else
    {
        cf[9] = giorno[0];
        cf[10] = giorno[1];
    }

    /*//stampa caratteri giorno di nascita
    for(i=9;i<=10;i++)
        printf("%c", cf[i]);*/
}

int main()
{
    //dichiarazione variabili
    int i;
    char nome[L];
    char cognome[L];
    char anno[L];
    char mese[L];
    char giorno[L];

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
    scanf("%s", mese);
    month(mese);
    printf("Inserire giorno di nascita: ");
    scanf("%s", giorno);
    day(giorno);

    /*//stampa codice fiscale
    for(i=0;i<LCF;i++)
        printf("%c", cf[i]);*/
}
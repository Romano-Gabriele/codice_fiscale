#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define L 50
#define LCF 16
#define N 3

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
char cf[LCF];
char comune[L];

char alpha[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
int conv[] = {1, 0, 5, 7, 9, 13, 15, 17, 19, 21, 2, 4, 18, 20, 11, 3, 6, 8, 12, 14, 16, 10, 22, 25, 24, 23};
int check[LCF];

char cfi[LCF];
char mesi[] = "ABCDEHLMPRST";
char cat[L];

void maiuscolo(char stringa[])
{
    int i;

    for(i=0;i<strlen(stringa);i++)
        stringa[i] = toupper(stringa[i]);
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
        cf[0] = consonanti_c[0];
        cf[1] = consonanti_c[1];
        cf[2] = consonanti_c[2];
        //printf("%c%c%c", consonanti_c[0], consonanti_c[1], consonanti_c[2]);
    }
    else
    {
        switch(ncons)
        {
            case 2:
            cf[0] = consonanti_c[0];
            cf[1] = consonanti_c[1];
            cf[2] = vocali_c[0];
            //printf("%c%c%c", consonanti_c[0], consonanti_c[1], vocali_c[0]);
            break;
            case 1:
            if(strlen(cognome) >= 3)
            {
                cf[0] = consonanti_c[0];
                cf[1] = vocali_c[0];
                cf[2] = vocali_c[1];
                //printf("%c%c%c", consonanti_c[0], vocali_c[0], vocali_c[1]);
            }
            else
            {
                cf[0] = consonanti_c[0];
                cf[1] = vocali_c[0];
                cf[2] = 'X';
                //printf("%c%cx", consonanti_c[0], vocali_c[0]);
            }
            break;
            default:
            if(strlen(cognome) == 2)
            {
                cf[0] = vocali_c[0];
                cf[1] = vocali_c[1];
                cf[2] = 'X';
                //printf("%c%cx", vocali_c[0], vocali_c[1]);
            }
            else
            {
                cf[0] = vocali_c[0];
                cf[1] = vocali_c[1];
                cf[2] = vocali_c[2];
                //printf("%c%c%c", vocali_c[0], vocali_c[1], vocali_c[2]);
            }
        }
    }

    /*//stampa caratteri cognome
    for(i=0;i<=2;i++)
        printf("%c", cf[i]);
    printf("\n");*/
}

//calcolo caratteri nome
void name(char nome[])
{
    //dichiarazione variabili
    int nvoc=0,ncons=0,i;

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
        cf[3] = consonanti[0];
        cf[4] = consonanti[2];
        cf[5] = consonanti[3];
        //printf("%c%c%c", consonanti[0], consonanti[2], consonanti[3]);
    }
    else
    {
        switch(ncons)
        {
            case 3:
            cf[3] = consonanti[0];
            cf[4] = consonanti[1];
            cf[5] = consonanti[2];
            //printf("%c%c%c", consonanti[0], consonanti[1], consonanti[2]);
            break;
            case 2:
            cf[3] = consonanti[0];
            cf[4] = consonanti[1];
            cf[5] = vocali[0];
            //printf("%c%c%c", consonanti[0], consonanti[1], vocali[0]);
            break;
            case 1:
            if(strlen(nome) >= 3)
            {
                cf[3] = consonanti[0];
                cf[4] = vocali[0];
                cf[5] = vocali[1];
                //printf("%c%c%c", consonanti[0], vocali[0], vocali[1]);
            }
            else
            {
                cf[3] = consonanti[0];
                cf[4] = vocali[0];
                cf[5] = 'X';
                //printf("%c%cx", consonanti[0], vocali[0]);
            }
            break;
            default:
            if(strlen(nome) == 2)
            {
                cf[3] = vocali[0];
                cf[4] = vocali[1];
                cf[5] = 'X';
                //printf("%c%cx", vocali[0], vocali[1]);
            }
            else
            {
                cf[3] = vocali[0];
                cf[4] = vocali[1];
                cf[5] = vocali[2];
                //printf("%c%c%c", vocali[0], vocali[1], vocali[2]);
            }
        }
    }

    /*//stampa caratteri nome
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

//calcolo caratteri giorno di nascita
void day(char giorno[], char sesso[])
{
    //dichiarazione variabili
    int i;

    //conversione in maiuscolo
    maiuscolo(sesso);

    //inserimento caratteri giorno di nascita
    if(strlen(giorno) == 1)
    {
        if(sesso[0] == 'M')
            cf[9] = '0';
        else
            cf[9] = '4';

        cf[10] = giorno[0];
    }
    else
    {
        if(sesso[0] == 'M')
            cf[9] = giorno[0];
        else
            cf[9] = giorno[0] + 4;

        cf[10] = giorno[1];
    }

    /*//stampa caratteri giorno di nascita
    for(i=9;i<=10;i++)
        printf("%c", cf[i]);*/
}

//calcolo caratteri luogo di nascita
void place(char luogo[])
{
    //dichiarazione variabili
    FILE *file_pointer;
    char line[L];
    int i=0,j=0;

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

//calcolo carattere di controllo
void check_digit()
{
    //dichiarazione variabili
    int i=0,j=0,c=0;

    //inserimento posizioni pari
    for(i=1;i<strlen(cf);i+=2)
    {
        j=0;
        while(cf[i] != alpha[j])
            j++;
        
        if(j <= 25)
            check[i] = j;
        else
            check[i] = j-26;

        /*//stampa posizioni pari 
        printf("%d\t", check[i]);*/
    }

    //inserimento posizioni dispari
    for(i=0;i<strlen(cf);i+=2)
    {
        j=0;
        while(cf[i] != alpha[j])
            j++;

        if(j <= 25)
            check[i] = conv[j];
        else
            check[i] = conv[j-26];

        /*//stampa posizioni dispari
        printf("%d\t", check[i]);*/
    }

    /*//stampa array convertito
    for(i=0;i<LCF;i++)
        printf("%d\t", check[i]);*/

    //somma e divisione
    for(i=0;i<LCF;i++)
        c += check[i];
    c = c%26;

    //inserimento carattere di controllo
    cf[15] = alpha[c];

    /*//stampa carattere di controllo
    printf("%c", cf[15]);*/
}

//stampa caratteri nome
void name_inv()
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
void surname_inv()
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
void date_inv()
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
void place_inv()
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

void calcolo()
{
    //dichiarazione variabili
    int i;

    //inserimento dati
    printf("Inserire cognome: ");
    scanf("%s", cognome);
    surname(cognome);
    printf("Inserire nome: ");
    scanf("%s", nome);
    name(nome);
    printf("Inserire anno di nascita: ");
    scanf("%s", anno);
    year(anno);
    printf("Inserire mese di nascita: ");
    scanf("%d", &mese);
    month(mese);
    printf("Inserire giorno di nascita: ");
    scanf("%s", giorno);
    printf("Inserire sesso (M/F): ");
    scanf("%s", sesso);
    day(giorno, sesso);
    printf("Inserire luogo di nascita: ");
    scanf("%s", luogo);
    place(luogo);
    check_digit();

    //stampa codice fiscale
    for(i=0;i<LCF;i++)
        printf("%c", cf[i]);
    printf("\n");
}

void inverso()
{
    printf("Inserire codice fiscale: ");
    scanf("%s", cfi);

    name_inv();
    surname_inv();
    date_inv();
    place_inv();
}

int main()
{
    //dichiarazione variabili
    int selezione;

    //Selezione modalità
    printf("Benvenuto/a nel calcolo del codice fiscale\n");
    printf("0 - Calcolo del codice fiscale\n");
    printf("1 - Calcolo inverso\n");
    printf("Seleziona la modalità: ");
    scanf("%d", &selezione);

    if(!selezione)
        calcolo();
    else
        inverso();

    return 0;
}
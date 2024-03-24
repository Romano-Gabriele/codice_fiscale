#include <stdio.h>
#include <string.h>

#define L 50

char comune[L];
char line[L];

//calcolo carattere mese di nascita
void month(char comune[])
{
    //dichiarazione variabili
    FILE *file_point = fopen("file_mese.txt", "r");

    if(!file_point)
        printf("Errore file");
    else
        {
            while(!EOF)
            {
                if(strstr(line, comune)) //verifica che nella linea sia contenuta la stringa "comune"
                {
                    fgets(line, 4, file_point); //legge riga del file (primi 4 caratteri)
                    printf("%s", line);
                }
                    
            }
        }
        
    fclose(file_point);

    //inserimento carattere mese di nascita
    //cf[8] = 'x';

    /*//stampa carattere mese di nascita
    printf("%c", cf[8]);*/
}

int main()
{
    printf("Inserire comune di nascita: ");
    scanf("%s", comune);
    month(comune);
}
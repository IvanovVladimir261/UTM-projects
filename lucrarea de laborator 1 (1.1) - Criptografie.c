#include <stdio.h>
#include <ctype.h>
#include <string.h>
int main()
{
    //declaram variabilele intregi folosite in program
    int x,k,alege,i,j,lungime;
    //tabelul cu literele mari
    char alphabet_upper[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    //tabelul cu literele mici
    char alphabet_lower[] = "abcdefghijklmnopqrstuvwxyz";
    //sirul in care se citeste textul introdus de utilizator
    char text[1000];
    //textul dupa eliminarea spatiilor si conversia in majuscule
    char text_final[1000];
    //rezultatul final: textul criptat sau decriptat
    char rezultat[1000];

    //afisam optiunile si citirea de la tastatura
    printf("1 - Criptarea \n");
    printf("2 - Decriptarea \n");
    printf("Alege optiunea: ");
    scanf(" %d", &alege);

    //verificam daca optiunea nu e 1 sau 2
    if (alege!=1 && alege!=2)
    {
        printf("Optiune gresita!");
        return 1;
    }

    //cerem cheia si citirea de la tastatura
    printf("Introduceti cheia: ");
    scanf(" %d", &k);

    //verificam daca cheia e in afara intervalului 1-25
    if (k<1 || k>25)
    {
        printf("Cheia trebuie sa fie intre 1 si 25!");
        return 1;
    }

    //cerem textul
    printf("Introduceti textul: ");
    //citirea caracterelor pana nu va aparea \n
    scanf(" %[^\n]", text);
    // calculam lungimea textului citit
    lungime=strlen(text);

    //parcurgem fiecare caracter din text si verificam daca in text este ceva inafara de litere
    for (i=0; i<lungime; i++)
    {
        //verificam daca nu e nici spatiu, nici litera
        if (text[i] != ' ' && !isalpha(text[i]))
        {
            printf("Text invalid! Sunt acceptate doar literele A-Z, a-z si spatiile.");
            return 1;
        }
    }

    //initializam indexul pentru text_final
    j = 0;
    //parcurgem textul ca sa eliminam spatiile si sa convertim in majuscule
    for (i=0; i<lungime; i++)
    {
        //daca e spatiu, il sarim
        if (text[i] == ' ')
        {
            continue;
        }
        //copiem litera convertita in majuscula
        text_final[j] = toupper(text[i]);
        //avansam indexul din text_final
        j++;
    }
    //marcharea sfârșitului unui șir de caractere
    text_final[j] = '\0';
    // actualizam lungimea, dupa eliminarea spatiilor
    lungime = j;

    //parcurgem fiecare litera din text_final pentru criptare sau decriptare
    for (i=0; i<lungime; i++)
    {
        //aflam valoarea numerica a literei cautand-o in alphabet_upper
        int valoare = strchr(alphabet_upper, text_final[i]) - alphabet_upper;
        //aici va fi pusa valoarea rezultata dupa deplasare
        int noua_valoare;

        //criptarea
        if (alege == 1)
        {
            noua_valoare = (valoare + k) % 26;
        }
        //decriptarea
        else
        {
            //adaugam 26 ca sa evitam rezultat negativ
            noua_valoare = (valoare - k + 26) % 26;
        }

        //punem litera corespunzatoare noii valori in rezultat
        rezultat[i] = alphabet_upper[noua_valoare];
    }
    //marcharea sfârșitului unui șir de caractere
    rezultat[lungime] = '\0';

    //criptarea
    if (alege == 1)
    {
        printf("\nMesajul criptat este: %s\n", rezultat);
    }
    //decriptarea
    else
    {
        printf("\nMesajul decriptat este: %s\n", rezultat);
    }
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    int choix;
    time_t seconde;
    struct tm instant;
    time(&seconde);
    instant=*localtime(&seconde);

    while(1)
    {printf("\n**************** MENU PRINCIPAL *****************");
    printf("\n**************************************************");
    printf("\nGESTION DES PATIENTS DANS UN HOPITAL UNIVERSITAIRE");
    printf("\n**************************************************");
    printf("\n 1.Gestion des services");
    printf("\n 2.Gestion des chirurgiens");
    printf("\n 3.Gestion des patients");
    printf("\n 0.Quitter");
    printf("\n***********************************************");
    printf("\n La date: %d/%d/%d\t\t Horaire:%d:%d",instant.tm_mday,instant.tm_mon+1,instant.tm_year+1900,instant.tm_hour,instant.tm_min);
    printf("\n***********************************************");
    printf("\n Introduire votre choix:");
    scanf("%d",&choix);
    switch(choix)
    {

    case 1:
        {
            menuservice();
            break;
        }
    case 2:
        {
            menumedecin();
            break;
        }
    case 3:
        {
            menupatient();
            break;
        }
    case 0:
        {
            exit(0);
        }
    default:
            {
                printf("\n Choix %crron%c!!",130,130);
            }

    }
}
    return 0;
}

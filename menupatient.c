#include <stdio.h>
#include <stdlib.h>
#include "Patient.h"
#include <string.h>
#include <time.h>

Patient tableau_p[100];
int taille_tab_patient = 0;


int menupatient()
{
    int id;
    int i;
    int choix = 0;
    int rech = -1;
    char rep[3];
    FILE *fichier;
    time_t seconde;
    struct tm instant;
    time(&seconde);
    instant = *localtime(&seconde);
    fichier = fopen("Fpatient.txt", "rt");
    if (fichier == NULL)
    {
        perror("Erreur lors de l'ouverture du fichier");
        return 1;
    }
    else
    {
        i = 0;
        while (1)
        {
            if (fscanf(fichier, "%d\n", &tableau_p[i].identifiant) != 1)
                break;

            if (fgets(tableau_p[i].Prenom, 25, fichier) == NULL)
                break;
            tableau_p[i].Prenom[strcspn(tableau_p[i].Prenom, "\n")] = '\0';

            if (fgets(tableau_p[i].Nom, 25, fichier) == NULL)
                break;
            tableau_p[i].Nom[strcspn(tableau_p[i].Nom, "\n")] = '\0';

            if (fscanf(fichier, "%d/%d/%d\n",
                       &tableau_p[i].naissance.Jour,
                       &tableau_p[i].naissance.Mois,
                       &tableau_p[i].naissance.Annee) != 3)
                break;

            if (fscanf(fichier, "%c\n", &tableau_p[i].sexe) != 1)
                break;

            if (fgets(tableau_p[i].adresse, 50, fichier) == NULL)
                break;
            tableau_p[i].adresse[strcspn(tableau_p[i].adresse, "\n")] = '\0';

            if (fgets(tableau_p[i].nationalite, 25, fichier) == NULL)
                break;
            tableau_p[i].nationalite[strcspn(tableau_p[i].nationalite, "\n")] = '\0';

            i++;
            if (i >= 100)
            {
                printf("Le tableau est plein, arrêt de la lecture\n");
                break;
            }
        }
        taille_tab_patient = i;
    }

    while (1)
    {
        printf("\n************************************");
        printf("\n************MENU PATIENTS***********");
        printf("\n************************************");
        printf("\n********GESTION DES PATIENTS********");
        printf("\n************************************");
        printf("\n 1.Saisir tableau patients");
        printf("\n 2.Ajouter un patient");
        printf("\n 3.Rechercher un patient");
        printf("\n 4.Modifier un patient");
        printf("\n 5.Supprimer un patient");
        printf("\n 6.Afficher tableau patient");
        printf("\n 0.Quitter");
        printf("\n*******************************");
        printf("\n %d/%d/%d\t\t %d:%d", instant.tm_mday, instant.tm_mon + 1, instant.tm_year + 1900, instant.tm_hour, instant.tm_min);
        printf("\n*******************************");
        printf("\n Introduire votre choix:");
        scanf("%d", &choix);
        switch (choix)
        {
        case 1:
        {
            saisir_tab_p(tableau_p, &taille_tab_patient);
            break;
        }
        case 2:
        {
            Ajouter_tab_p(tableau_p, &taille_tab_patient);
            break;
        }
        case 3:
        {
            printf("\n introduire l'identifiant %c rechercher:",133);
            scanf("%d", &id);
            rech = recherche_p(tableau_p, taille_tab_patient, id); // rech c'est l'indice de l'�tudiant trouv�
            if (rech == -1)
            {
                printf("\n identifiant in%cxistant",130);
            }
            else
            {
                affiche_p(tableau_p[rech]);
            }
            break;
        }
        case 4:
        {
            printf("\n introduire l'identifiant du patient à modifier:");
            scanf("%d", &id);
            rech = recherche_p(tableau_p, taille_tab_patient, id); // rech c'est l'indice de l'�tudiant trouv�
            if (rech != -1)
            {
                affiche_p(tableau_p[rech]);
                printf("\n Vous êtes sure de vouloire modifier ce patient oui/non ?: ");
                scanf("%s", rep);
                if (strcmp(rep, "oui") == 0)
                {
                    modifier_p(tableau_p, rech);
                }
            }
            else
            {
                printf("\n identifiant inéxistant");
            }
            break;
        }

        case 5:
        {
            printf("\n introduire l'identifiant du patient à supprimer:");
            scanf("%d", &id);
            rech = recherche_p(tableau_p, taille_tab_patient, id); // rech c'est l'indice de l'�tudiant trouv�
            if (rech != -1)
            {
                affiche_p(tableau_p[rech]);
                printf("\n Vous %ctes sure de vouloire supprimer ce patient oui/non ?: ",136);
                scanf("%s", rep);
                if (strcmp(rep, "oui") == 0)
                {
                    supprimer_p(tableau_p, &taille_tab_patient, rech);
                }
            }
            else
            {
                printf("\n identifiant inéxistant");
            }
            break;
        }

        case 6:
        {
            affiche_tableau_p(tableau_p, taille_tab_patient);
            break;
        }
        case 0:
        {
            fichier = fopen("Fpatient.txt", "wt");
            if (fichier == NULL)
            {
                printf("\n fichier inéxistant!");
            }
            else
            {
                for (i = 0; i < taille_tab_patient; i++)
                {
                    fprintf(fichier, "%d\n%s\n%s\n%d/%d/%d\n%c\n%s\n%s\n", tableau_p[i].identifiant, tableau_p[i].Prenom, tableau_p[i].Nom, tableau_p[i].naissance.Jour, tableau_p[i].naissance.Mois, tableau_p[i].naissance.Annee, tableau_p[i].sexe, tableau_p[i].adresse, tableau_p[i].nationalite);
                }
            }
            fclose(fichier);
            return 0;
        }
        default:
        {
            printf("\n Choix %crron%c!!",130,130);
        }
        }
    }

    return 0;
}

#include "Patient.h"
#include <stdio.h>
#include <string.h>

void clearstdin()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

extern Patient tableau_p[100];
extern int taille_tab_patient;

Patient saisir_p()
{
    Patient p;
    int i;
    int rech;
    do
    {
        printf("\n introduire l'identifiant : ");
        scanf("%d", &p.identifiant);
        rech = recherche_p(tableau_p, taille_tab_patient, p.identifiant);
        if (rech != -1)
        {
            printf("\n Identifiant existe déja!");
        }
    } while (rech != -1);
    clearstdin();
    printf("\n introduire le nom: ");
    fgets(p.Nom, 25, stdin);
    p.Nom[strcspn(p.Nom, "\n")] = '\0';

    printf("\n introduire le prénom: ");
    fgets(p.Prenom, 25, stdin);
    p.Prenom[strcspn(p.Prenom, "\n")] = '\0';

    printf("\n introduire la date de naissance JJ MM YYYY : ");
    scanf("%d %d %d", &p.naissance.Jour, &p.naissance.Mois, &p.naissance.Annee);
    clearstdin();
    printf("\n introduire le sexe m/f :");
    scanf("%c", &p.sexe);
    printf("\n introduire l'adresse: ");
    p.adresse[strcspn(p.adresse, "\n")] = '\0';
    clearstdin();
    fgets(p.adresse, 25, stdin);
    p.adresse[strcspn(p.adresse, "\n")] = '\0';
    printf("\n introduire la nationalité: ");
    fgets(p.nationalite, 25, stdin);
    p.nationalite[strcspn(p.nationalite, "\n")] = '\0';

    return p;
}
void saisir_tab_p(Patient tab[], int *N)
{
    char rep[3];
    Patient e;
    do
    {
        e = saisir_p();
        tab[*N] = e;
        (*N)++;
        printf("\n Voulez-vous ajouter un autre Patient oui/non:");
        scanf("%s", rep);
    } while (strcmp(rep, "oui") == 0);
}
void Ajouter_tab_p(Patient tab[], int *N)
{
    Patient e;
    int i;
    char rep[3];
    i = *N;

    e = saisir_p();
    tab[i] = e;
    i++;

    *N = i;
}

void affiche_p(Patient e)
{
    printf("\n *****\n identifiant : %d", e.identifiant);
    printf("\n Nom: %s", e.Nom);
    printf("\n Prenom : %s", e.Prenom);
    printf("\n Date de naissance : %d/%d/%d", e.naissance.Jour, e.naissance.Mois, e.naissance.Annee);
    printf("\n Sexe : %c", e.sexe);
    printf("\n Adresse : %s", e.adresse);
    printf("\n Nationalite : %s", e.nationalite);
}

void affiche_tableau_p(Patient tab[], int N)
{
    int i;
    for (i = 0; i < N; i++)
    {
        affiche_p(tab[i]);
    }
}

int recherche_p(Patient tab[], int N, int ident)
{
    for (int i = 0; i < N; i++)
    {
        if ((tab[i].identifiant) == ident)
        {
            return i;
        }
    }
    return -1;
}

void modifier_p(Patient tab[], int rech)
{
    int choix;
    printf("\n******MENU***********");
    printf("\n 1.Modifier le nom");
    printf("\n 2.Modifier le prénom");
    printf("\n 3.Modifier la date de naissance");
    printf("\n 4.Modifier le sexe");
    printf("\n 5.Modifier l'adresse");
    printf("\n 6.Modifier la nationalité");
    printf("\n Introduire votre choix: ");
    scanf("%d", &choix);
    switch (choix)
    {
    case (1):
    {
        printf(" \nIntroduire le nom:");
        fflush(stdin);
        fgets(tab[rech].Nom, 25, stdin);
        break;
    }
    case (2):
    {
        printf(" \nIntroduire le prénom:");
        fflush(stdin);
        fgets(tab[rech].Prenom, 25, stdin);
        break;
    }
    case (3):
    {
        printf("\n introduire la date de naissance JJ MM YYYY : ");
        fflush(stdin);
        scanf("%d %d %d", &tab[rech].naissance.Jour, &tab[rech].naissance.Mois, &tab[rech].naissance.Annee);
        break;
    }
    case (4):
    {
        printf("\n introduire le sexe m/f :");
        scanf("%c", &tab[rech].sexe);
        break;
    }

    case (5):
    {
        printf("\n introduire l'adresse: ");
        fflush(stdin);
        break;
    }
    case (6):
    {
        printf("\n introduire la nationalité: ");
        fflush(stdin);
        break;
    }
    default:
    {
        printf("\n Choix érroné!!");
    }
    }
}

void supprimer_p(Patient tab[], int *N, int rech)
{
    int i;
    int taille = (*N);
    for (i = rech; i < taille - 1; i++)
    {
        tab[i] = tab[i + 1];
    }
    (*N)--;
}

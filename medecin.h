#ifndef MEDECIN_H_INCLUDED
#define MEDECIN_H_INCLUDED
typedef struct date{
    int jour;
    int mois;
    int anne;

} DATE;
typedef struct medecin {
    int identifiant;
    char nom[25] ;
    char prenom[25];;
    char specialite[25];
    DATE date;
    int cservice;
} med;
med saisir_medecin();
void saisir_tab_med(med tab[],int *N) ;
void ajouter_tab_med(med tab[],int *N);
void affiche_med(med e);
void affiche_tableau_med(med tab[],int N);
int chercher_medecin(med tab[],int N,int ident);
void modifier_med(med tab[], int rech);
void suprimer_med(med tab[],int *N , int rech);
#endif // MEDECIN_H_INCLUDED

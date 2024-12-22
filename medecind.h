#ifndef MEDECIND_H_INCLUDED

#define MEDECIND_H_INCLUDED



typedef struct DATE{
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

struct cellule

{

med valeur;

struct cellule *suivant;

};

typedef struct cellule *Liste;





med saisir_med();



void affiche_med(med m);



void modifier_med(med *m);



Liste insere(med element , Liste Lst);



void affiche_Liste_med(Liste Lst);



med* rechercher_med(Liste Lst, int ident);







#endif // ETUDIANT_H_INCLUDED


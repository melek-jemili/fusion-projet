#ifndef GESTION_H_INCLUDED
#define GESTION_H_INCLUDED

#include "date.h"


 typedef struct hosp{
     int codepatient ;
     int numservice;
     int nbrechambre;
     Date hospi;
     Date operation;
     char typeop[25];
     char rep[2];
     char med[50];
     Date sortie;
 }hosp;

struct cellule
{
hosp valeur;
struct cellule *suivant;
};
typedef struct cellule *Liste;

hosp saisir_hosp();

void affiche_hosp(hosp h);

void affiche_Liste_hosp(Liste Lst);

hosp* recherche_hosp(Liste Lst,int code);

void modifier_hosp(hosp *h);

Liste insere(hosp element , Liste Lst);

void supprimer_hosp(Liste Lst,int code);

int comparer_dates(Date date1,Date date2);


#endif // GESTION_H_INCLUDED

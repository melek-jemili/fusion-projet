#ifndef HOSPITALISATION_H_INCLUDED
#define HOSPITALISATION_H_INCLUDED

 typedef struct date{
    int jour;
    int mois;
    int annee;
 }date;


 typedef struct hosp{
     int codepatient ;
     int numservice;
     int nbrechambre;
     date hospi;
     date operation;
     char typeop[25];
     char rep[2];
     char med[50];
     date sortie;
 }hosp;



hosp saisir_hosp();
void saisir_tab_hosp(hosp tab[], int *N);
void ajouter_tab_hosp(hosp tab[], int *N);
void affiche_hosp(hosp h);
void affiche_tableau_hosp(hosp tab[],int N);
int recherche_hosp(hosp tab[],int N,int code);
void modifier_hosp(hosp tab[],int rech);
void supprimer_hosp(hosp tab[],int *N,int rech);

#endif // HOSPITALISATION_H_INCLUDED

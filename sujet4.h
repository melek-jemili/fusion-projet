#ifndef SUJET4_H_INCLUDED
#define SUJET4_H_INCLUDED
ypedef struct srv
{
	int code_srv;
	char specialite[25];
	int nombrechambres;

}service;

service saisir_service();
void saisir_tab_srv(service tab[], int *N);
void ajouter_tab_srv(service tab[], int *N);
void affiche_service(service s);
void affiche_tableau_srv(service tab[],int N);
int recherche_srv(service tab[],int N,int code);
void modifier_srv(service tab[],int rech);
void supprimer_srv(service tab[],int *N,int rech);



#endif // SUJET4_H_INCLUDED

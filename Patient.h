#ifndef PATIENT_H_INCLUDED
#define PATIENT_H_INCLUDED


typedef struct Date{
	int Jour;
	int Mois;
	int Annee;
}Date;
typedef struct p
{
	int identifiant ;
	char Nom[25];
	char Prenom[25];
	Date naissance;
	char sexe;
	char adresse[50];
	char nationalite[25];

}Patient;
Patient saisir_p();
void saisir_tab_p(Patient tab[], int *N);
void Ajouter_tab_p(Patient tab[], int *N);
void affiche_p(Patient e);
void affiche_tableau_p(Patient tab[],int N);
int recherche_p(Patient tab[],int N,int ident);
void modifier_p(Patient tab[],int rech);
void supprimer_p(Patient tab[],int *N,int rech);


#endif // PATIENT_H_INCLUDED

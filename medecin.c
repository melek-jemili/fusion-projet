
#include<stdio.h>
#include"medecin.h"
#include<string.h>
#include<ctype.h>
extern tableau_med[100];
extern int taille_tab_medecin;

med saisir_medecin()
{
med e;
int rech;
int i;

do
{   printf("\nintroduire l'identifiant du medecin:");
    scanf("%d",&e.identifiant);
    rech=chercher_medecin(tableau_med,taille_tab_medecin,e.identifiant);
    if (rech!=-1){
        printf("\n identifiant existe d%cja!!",130);
}}while((rech!=-1)||(isdigit(e.identifiant)));

printf("\nintroduire le nom:");
fflush(stdin);
gets(e.nom);

printf("\nintroduire le prenom:");
fflush(stdin);
gets(e.prenom);

printf("\nintroduire la sp%ccialite:",130);
fflush(stdin);
gets(e.specialite);

do{
printf("\nintroduire le jour:");
scanf("%d",&e.date.jour);
if (e.date.jour<0 || e.date.jour>32){
    printf("\n jour invalide !!");
}
}while(e.date.jour<0 || e.date.jour>32);

do {printf("\nintroduire le mois:");
scanf("%d",&e.date.mois);
if (e.date.mois<0 || e.date.mois>13){
    printf("\n mois invalide !!");
}
}while(e.date.mois<0 || e.date.mois>13);

do{printf("\nintroduire l'ann%ce:",130);
scanf("%d",&e.date.anne);
if (e.date.anne<2000){
    printf("\n ann%ce invalide!!",130);
}
}while (e.date.anne<2000);


printf("\nintroduire la code du service:");
scanf("%d",&e.cservice);
return e;
}




void saisir_tab_med(med tab[],int *N)
{
    med e;
    char rep[3];

do {
    e=saisir_medecin();
    tab[*N]=e;
    (*N)++;
    printf("voulez-vous ajouter un autre m%cdecin? oui/non:",130);
    scanf("%s",rep);
    }while(strcmp(rep,"oui")==0);

}



void affiche_med(med e)
{
    printf("\ncode de medecin:%d",e.identifiant);
    printf("\nle nom:%s",e.nom);
    printf("\nle prenom:%s",e.prenom);
    printf("\nLa specialité:%s",e.specialite);
    printf("\nla date d'entrée:%d/%d/%d",e.date.jour,e.date.mois,e.date.anne);
    printf("\nle code de la service:%d",e.cservice);
    printf("\n");
}




void affiche_tableau_med(med tab[],int N)
{
    int i;
    for(i=0;i<N;i++){
        affiche_med(tab[i]);}
}



int chercher_medecin(med tab[],int N,int ident)
{
    int i;
    for(i=0;i<N;i++){
        if (tab[i].identifiant==ident){
            return i;}
}
    return -1;
}






void ajouter_tab_med(med tab[],int *N)
{
med e;
int i;
i=*N;
e=saisir_medecin();
tab[i]=e;
i++;
*N=i;
}



void modifier_med(med tab[], int rech)
{
int choix;
printf("\n 1.modifier le nom");
printf("\n 2.modifier le prenom");
printf("\n 3.modifier la sp%ccialite",130);
printf("\n 4.modifier la date");
printf("\n 5.modifier le code service");;
printf("\n introduire votre choix:");
scanf("%d",&choix);
switch (choix)
{
case 1:
{
printf("\n introduire le nouveau nom:");
fflush(stdin);
gets(tab[rech].nom);
break;
}
case 2:
{
printf("\n introduire le nouveau prenom:");
fflush(stdin);
gets(tab[rech].prenom);
break;
}
case 3:
{
printf("\n introduire la  nouvelle sp%ccialite:",130);
fflush(stdin);
gets(tab[rech].specialite);
break;
}
case 4:
{
do
{printf("\nintroduire le jour:");
scanf("%d",&tab[rech].date.jour);
if (tab[rech].date.jour<0 || tab[rech].date.jour>32){
    printf("\n jour invalide !!");}
}while(tab[rech].date.jour<0 || tab[rech].date.jour>32);

do
{printf("\nintroduire le mois:");
scanf("%d",&tab[rech].date.mois);
if (tab[rech].date.mois<0 || tab[rech].date.mois>13){
    printf("\n mois invalide !!");}
}while(tab[rech].date.mois<0 || tab[rech].date.mois>13);

do
{printf("\nintroduire l'année:");
scanf("%d",&tab[rech].date.anne);
if (tab[rech].date.anne<2000){
    printf("\n ann%ce invalide!!",130);
}
}while(tab[rech].date.anne<2000);

break;
}
case 5:
{
printf("\nintroduire le code du service:");
scanf("%d",&tab[rech].cservice);
break;
}

}

}

void suprimer_med(med tab[],int *N , int rech)
{
int i;
int taille=*N;
for(i=rech;i<taille-1;i++)
{
    tab[i]=tab[i+1];
}
(*N)--;
}

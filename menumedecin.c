#include<time.h>
#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#include"medecin.h"

med tableau_med[100];
int taille_tab_medecin;

int menumedecin(){

int ID;
int rech=-1;

char rep[3];

int choix;
time_t seconde;
struct tm instant;
time(&seconde);
instant=*localtime(&seconde);
int i;
FILE* fichier;
fichier=fopen("Fchirurgiens.txt","rt");
if(fichier==NULL)
    {printf("fichier n'exicte pas");}
else{
    i=0;
    while(!feof(fichier)){
                fscanf(fichier,"%d ",&tableau_med[i].identifiant);
                fgets(tableau_med[i].nom,25,fichier);
                fgets(tableau_med[i].prenom,25,fichier);
                fgets(tableau_med[i].specialite,25,fichier);
                fscanf(fichier,"%d /%d/%d",&tableau_med[i].date.jour,&tableau_med[i].date.mois,&tableau_med[i].date.anne);
                fscanf(fichier," %d ",&tableau_med[i].cservice);
                printf("\n");}
                fclose(fichier);
    i++;
}
fclose(fichier);

while (1) {
printf("\n********************************");
printf("\n********* MENU MEDECIN *********");
printf("\n********************************");
printf("\n****GESTION DES CHIRURGIENS*****");
printf("\n********************************");
printf("\n 1.saisir un tableau de medecin");
printf("\n 2.Ajouter un medecin ");
printf("\n 3.rechercher un medecin");
printf("\n 4.modifier un medecin");
printf("\n 5.supprimer un medecin");
printf("\n 6.afficher le tableau des medecins");
printf("\n 0.Quitter");
printf("\n *******************************\n");
printf("\t %d/%d/%d",instant.tm_mday,instant.tm_mon+1,instant.tm_year+1900,instant.tm_hour,instant.tm_min);
printf("\n *******************************");
printf("\n *******************************\n");
printf("\nIntroduire votre choix :");


scanf("%d",&choix);
switch (choix)
{
case 1:
{
saisir_tab_med(tableau_med,&taille_tab_medecin);
break;
}

case 2:
{
ajouter_tab_med(tableau_med,&taille_tab_medecin) ;
break;
}
case 3:
{
printf("\n introduire l'identifiant du medecin à chercher:\n");
scanf("%d",&ID);
rech=chercher_medecin(tableau_med,taille_tab_medecin,ID);
if (rech!=-1){
        affiche_med(tableau_med[rech]);}
else {
        printf("\n Identifiant n'existe pas!!");}
break;
}
case 4:
{
printf("\n introduire l'identifiant du m%cdecin à modifier:",130);
scanf("%d",&ID);
rech=chercher_medecin(tableau_med,taille_tab_medecin,ID);
if (rech!=-1)
{
    affiche_med(tableau_med[rech]);
    printf("\n vous-etes sure de vouloir modifier ce medecin? oui/non:");
    scanf("%s",rep);
    if(strcmp(rep,"oui")==0)
    {
         modifier_med(tableau_med,rech);
    }
}
else
{printf("\n Identifiant n'existe pas!!");}
break;
}
case 5:
{
printf("\n introduire l'identifiant du medecin à supprimer:");
scanf("%d",&ID);
rech=chercher_medecin(tableau_med,taille_tab_medecin,ID);
if (rech!=-1)
{
    affiche_med(tableau_med[rech]);
    printf("\n vous etes sure de vouloir suprimer ce medecin? oui/non:");
    scanf("%s",rep);
    if(strcmp(rep,"oui")==0)
    {
         suprimer_med(tableau_med,&taille_tab_medecin,rech);
    }
}
else printf("\n Identifiant n'existe pas!!");
break;
}
case 6:
{
affiche_tableau_med(tableau_med,taille_tab_medecin);
break;
}
case 0:
{
    fichier=fopen("Fchirurgiens.txt","wt");
                if (fichier==NULL){
                    printf("\n fichier in%cxistant !! ",130);
                }else{
                    for(i=0;i<taille_tab_medecin;i++){
                        fprintf(fichier,"%d ",tableau_med[i].identifiant);
                        fprintf(fichier,"%s ",tableau_med[i].nom);
                        fprintf(fichier,"%s ",tableau_med[i].prenom);
                        fprintf(fichier," %s ",tableau_med[i].specialite);
                        fprintf(fichier,"%d/%d/%d ",tableau_med[i].date.jour,tableau_med[i].date.mois,tableau_med[i].date.anne);
                        fprintf(fichier,"%d ",tableau_med[i].cservice);
                        printf("\n");}
                        fclose(fichier);

                }

    return 0;
}
default:
{printf("\nchoix est %crron%c!!",130,130);
}
}
}




return 0;
}

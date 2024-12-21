#include "service.h"
#include <stdio.h>
#include<stdlib.h>
#include <string.h>
#include<ctype.h>

extern Liste Liste_srv;


Service saisir_srv(){
	Service srv;
	int i;
	int rech;

    do
	{printf("\n introduire le code du service : ");
	scanf("%d",&srv.code_srv);
    if (rechercher_srv(Liste_srv,srv.code_srv)!=NULL ){
        printf("\n Identifiant existe d%cjà!!\n",130);}
	}while(rechercher_srv(Liste_srv,srv.code_srv)!=NULL || isdigit(srv.code_srv)!=0);

	printf("\n introduire la sp%ccialit%c du service: ",130,130);
	fflush(stdin);
	gets(srv.specialite);

	do{
	printf("\n introduire le nombre des chambres: ");
	scanf("%d",&srv.nombrechambre);
	if(isdigit(srv.nombrechambre)!=0){
        printf("\n Choix Invalide!!");
	}}while(isdigit(srv.nombrechambre)!=0);
	return srv;
}




void affiche_srv(Service s){
	printf("\n *****\n Code : %d",s.code_srv);
	printf("\n sp%ccialit%c: %s",130,130,s.specialite);
	printf("\n nombre des chambres : %d",s.nombrechambre);

}



void modifier_srv(Service *srv){
    int choix;
    printf("\n******MENU***********");
    printf("\n 1.Modifier la sp%ccialit%c",130,130);
    printf("\n 2.Modifier le nombre des chambres");
    printf("\n Introduire votre choix: ");
    scanf("%d",&choix);
    switch(choix){
        case(1):{
            printf(" \nIntroduire la sp%ccialit%c:",130,130);
            fflush(stdin);
            gets(srv->specialite);
            break;
        }
        case(2):{
            do
            {printf(" \nIntroduire le nombre des chambres:");
            scanf("%d",&srv->nombrechambre);
            if(isdigit(srv->nombrechambre)!=0){
                printf("\n Choix Invalide !!");
            }
            }while(isdigit(srv->nombrechambre)!=0);
            break;
        }

        default:{
            printf("\n Choix %crron%c!!",130,130);}
    }
}

Liste insere(Service element , Liste Lst){
    struct cellule * Courrant;
    Courrant=(struct cellule*)malloc(sizeof(struct cellule));
    Courrant->valeur= element;
    Courrant->suivant=Lst;
    return (Courrant);

}

void affiche_Liste_srv(Liste Lst)
{
struct cellule* courrant;
courrant =Lst;
while (courrant!=NULL)
{
//traitement afficher l’entier
affiche_srv(courrant->valeur);
courrant=courrant->suivant;
}
}

Service* rechercher_srv(Liste Lst, int code)
{
    struct cellule* courrant;
    courrant =Lst;
    while (courrant!=NULL){
        if(courrant->valeur.code_srv==code)
            return &courrant->valeur;
        courrant=courrant->suivant;}
    return NULL;
}


void supprime_srv(Liste l, int code)

{
 struct cellule *pred=NULL, *cour=l;
 while (cour)
 {
    if(cour->valeur.code_srv==code) break ;
    pred = cour;
    cour = cour->suivant;
 }
 if (cour)
 {
    if (pred) {
            pred->suivant = cour->suivant;}
    else
    {l = l->suivant ;}
    free(cour);
 }

 }



#include <stdio.h>
#include "Service.h"
#include <string.h>
#include <ctype.h>

extern service tableau_srv[100];
extern int taille_tab_service;

service saisir_service(){
	service srv;
	int rech;

	do
	{printf("\n saisir le code du service:");
	scanf("%d",&srv.code_srv);
	rech=recherche_srv(tableau_srv,taille_tab_service,srv.code_srv);
    if (rech!=-1){
        printf("\n Code existe d%cj�!!\n",130);}
	}while((rech!=-1)||(isdigit(srv.code_srv)!=0));

	printf("\n saisir la sp%cialit%c du service:",130,130);
	fflush(stdin);
	gets(srv.specialite);

	do
	{printf("\n saisir le nombre des chambres dans le service:");
	scanf("%d",&srv.nombrechambres);
	}while(isdigit(srv.nombrechambres)!=0);
	return srv;
}



void saisir_tab_srv(service tab[], int *N){
	service s;
	char rep[3];
	do {
        s = saisir_service();
		tab[*N] = s;
        (*N)++;
		printf("\n Voulez-vous ajouter un autre service O/N:");
		scanf("%s",rep);
	}while(strcmp(rep,"O")==0);
}



void ajouter_tab_srv(service tab[], int *N){
	service s;
	int i;
	i=*N;
    s = saisir_service();
    tab[i] = s;
    i++;
	*N=i;

}

void affiche_service(service srv){
	printf("\n Le code du service :%d",srv.code_srv);
	printf("\n La sp%ccialit%c du service: %s",130,130,srv.specialite);
	printf("\n Le nombre des chambre dans ce service: %d",srv.nombrechambres);

}
void affiche_tableau_srv(service tab[],int N){
	int i;
	for(i=0;i<N;i++){
		affiche_service(tab[i]);
	}
}

int recherche_srv(service tab[],int N,int code){
	for(int i=0;i<N;i++){
		if ((tab[i].code_srv)==code){
			return i;
		}
	}
	return -1;
}

void modifier_srv(service tab[],int rech){
    int choix;
    printf("\n*************************************");
    printf("\n**********MENU MODIFICATION**********");
    printf("\n*************************************");
    printf("\n 1.Modifier la sp%ccialit%c du service",130,130);
    printf("\n 2.Modifier le nombre des chambre");
    printf("\n Introduire votre choix: ");
    scanf("%d",&choix);
    switch(choix){
        case(1):{

            printf(" \nIntroduire la nouvelle sp%ccialit%c:",130,130);
            fflush(stdin);
            gets(tab[rech].specialite);
            break;
        }
        case(2):{
            do
            {printf(" \nIntroduire le nouveau nombre des chambres:");
            scanf("%d",&tab[rech].nombrechambres);
            }while(isdigit(tab[rech].nombrechambres)!=0);
            break;
        }
        default:{
            printf("\n Choix �rron�!!");
        }


    }

}


void supprimer_srv(service tab[],int *N,int rech){
    int i;
    int taille=(*N);
    for(i=rech;i<taille-1;i++){
        tab[i]=tab[i+1];
        }
    (*N)--;
}


#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "hospitalisation.h"

extern hosp tableau_hosp[100];
extern int taille_tab_hosp;

hosp saisir_hosp(){

 hosp hosp;
	int rech;

	do
	{printf("\n saisir le code du patient:");
	scanf("%d",&hosp.codepatient);
	rech=recherche_hosp(tableau_hosp,taille_tab_hosp,hosp.codepatient);
    if (rech!=-1){
        printf("\n Code existe d%cj�!!\n",130);}
	}while((rech!=-1)||(isdigit(hosp.codepatient)!=0));

	printf("\n saisir le numero du service:");
	scanf("%d",&hosp.numservice);

	do
	{printf("\n saisir le nombre de la chambre:");
	scanf("%d",&hosp.nbrechambre);
	if (hosp.nbrechambre>4 || hosp.nbrechambre<1){
        printf("\n choix invalide!!");}
	}while(hosp.nbrechambre>4 || hosp.nbrechambre<1);


    do
	{printf("\n saisir la date de l'hospitalisation:");
	scanf("%d/%d/%d",&hosp.hospi.jour,&hosp.hospi.mois,&hosp.hospi.annee);
	if (hosp.hospi.jour<0 || hosp.hospi.jour>32){
        printf("\n jour invalide !!");
        }
    if (hosp.hospi.mois<0 || hosp.hospi.mois>13){
        printf("\n mois invalide !!");
        }
    if (hosp.hospi.annee<2000){
        printf("\n ann%ce invalide !!",130);}
    }while((hosp.hospi.jour<0 || hosp.hospi.jour>32) || (hosp.hospi.mois<0 || hosp.hospi.mois>13) || (hosp.hospi.annee<2000)) ;


	do
	{printf("\n saisir la date de l'operation:");
	scanf("%d/%d/%d",&hosp.operation.jour,&hosp.operation.mois,&hosp.operation.annee);
    if (hosp.operation.jour<0 || hosp.operation.jour>32){
        printf("\n jour invalide !!");
        }
    if (hosp.operation.mois<0 || hosp.operation.mois>13){
        printf("\n mois invalide !!");
        }
    if (hosp.operation.annee<2000){
        printf("\n ann%ce invalide !!",130);
        }

	}while ((hosp.operation.jour<0 || hosp.operation.jour>32) || (hosp.operation.mois<0 || hosp.operation.mois>13) || (hosp.operation.annee<2000));

	printf("\n saisir type de l'operation:");
	fflush(stdin);
	gets(hosp.typeop);

    do
	{printf("\n saisir la r%cponse:O/N:",130);
	fflush(stdin);
	gets(hosp.rep);
	if (strcmp(hosp.rep,"O")!=0 && strcmp(hosp.rep,"N")!=0){
        printf("\n r%cponse invalide!!",130);
        }
	}while(strcmp(hosp.rep,"O")!=0 && strcmp(hosp.rep,"N")!=0);

	printf("\n saisir le medecin responsable:");
	fflush(stdin);
	gets(hosp.med);

	do
	{printf("\n saisir la date de sortie:");
	scanf("%d/%d/%d",&hosp.sortie.jour,&hosp.sortie.mois,&hosp.sortie.annee);
	if (hosp.sortie.jour<0 || hosp.sortie.jour>32){
        printf("\n jour invalide !!");
        }
    if (hosp.sortie.mois<0 || hosp.sortie.mois>13){
        printf("\n mois invalide !!");
        }
    if (hosp.sortie.annee<2000){
        printf("\n ann%ce invalide !!",130);
        }
    }while((hosp.sortie.jour<0 || hosp.sortie.jour>32) || (hosp.sortie.mois<0 || hosp.sortie.mois>13) || (hosp.sortie.annee<2000)) ;


    return hosp;
}


void saisir_tab_hosp(hosp tab[], int *N){
	hosp h;
    char rep[3];
	do {
        h = saisir_hosp();
		tab[*N] = h;
        (*N)++;
		printf("\n Voulez-vous ajouter une autre hospitalisation O/N:");
		scanf("%s",rep);
	}while(strcmp(rep,"O")==0);
}



void ajouter_tab_hosp(hosp tab[], int *N){
	hosp h;
	int i;
	i=*N;
    h = saisir_hosp();
    tab[i] = h;
    i++;
	*N=i;

}

void affiche_hosp(hosp h){
	printf("\n******\n code patient:%d",h.codepatient);
	printf("\n Hospitalisation dans le service N°:%d   Chambre N°:%d",h.numservice,h.nbrechambre);
	printf("\n Date hospitalisation:%d/%d/%d",h.hospi.jour,h.hospi.mois,h.hospi.annee);
	printf("\n Date op%cration:%d/%d/%d",130,h.operation.jour,h.operation.mois,h.operation.annee);
	printf("\n Type op%cration:%s  R%cussie O/N:%s",130,h.typeop,130,h.rep);
	printf("\n M%cdecin responsable:%s",130,h.med);
	printf("\n Date de sortie : %d/%d/%d",h.sortie.jour,h.sortie.mois,h.sortie.annee);

}
void affiche_tableau_hosp(hosp tab[],int N){
	int i;
	for(i=0;i<N;i++){
		affiche_hosp(tab[i]);
	}
}

int recherche_hosp(hosp tab[],int N,int code){
	for(int i=0;i<N;i++){
		if ((tab[i].codepatient)==code){
			return i;
		}
	}
	return -1;
}

void modifier_hosp(hosp tab[],int rech){
    int choix;
    printf("\n*************************************");
    printf("\n**********MENU MODIFICATION**********");
    printf("\n*************************************");
    printf("\n 1.Modifier le num%cro du service",130);
    printf("\n 2.Modifier le nombre de la chambre");
    printf("\n 3.Modifier la date de l'hospitalisation");
    printf("\n 4.Modifier la date de l'op%cration",130);
    printf("\n 5.Modifier le type de l'op%cration",130);
    printf("\n 6.Modifier la r%cponse",130);
    printf("\n 7.Modifier le m%cdecin responsable",130);
    printf("\n 8.Modifier la date de sortie");
    printf("\n Introduire votre choix: ");
    scanf("%d",&choix);
    switch(choix){
        case(1):{

            printf(" \nIntroduire le NUM du service:");
            scanf("%d",&tab[rech].numservice);
            break;
        }
        case(2):{
            do
            {printf(" \nIntroduire le nombre de la chambre:");
            scanf("%d",&tab[rech].nbrechambre);
            if (tab[rech].nbrechambre>4 || tab[rech].nbrechambre<1){
                printf("\n choix invalide!!");}
            }while(tab[rech].nbrechambre>4 || tab[rech].nbrechambre<1);
            break;
        }
        case (3):{
            do
            {printf("\nIntroduire la date de l'hospitalisation:");
            scanf("%d/%d/%d",&tab[rech].hospi.jour,&tab[rech].hospi.mois,&tab[rech].hospi.annee);
            if (tab[rech].hospi.jour<0 || tab[rech].hospi.jour>32){
                printf("\n jour invalide !!");}
            if (tab[rech].hospi.mois<0 || tab[rech].hospi.mois>13){
                printf("\n mois invalide !!");}
            if (tab[rech].hospi.annee<2000){
                printf("\n ann%ce invalide !!",130);}
            }while((tab[rech].hospi.jour<0 || tab[rech].hospi.jour>32) || (tab[rech].hospi.mois<0 || tab[rech].hospi.mois>13) || (tab[rech].hospi.annee<2000)) ;
            break;
        }
        case(4):{
            do
            {printf("\nIntroduire la date de l'operation:");
            scanf("%d/%d/%d",&tab[rech].operation.jour,&tab[rech].operation.mois,&tab[rech].operation.annee);
            if (tab[rech].operation.jour<0 || tab[rech].operation.jour>32){
                printf("\n jour invalide !!");}
            if (tab[rech].operation.mois<0 || tab[rech].operation.mois>13){
                printf("\n mois invalide !!");}
            if (tab[rech].operation.annee<2000){
                printf("\n ann%ce invalide !!",130);}
            }while((tab[rech].operation.jour<0 || tab[rech].operation.jour>32) || (tab[rech].operation.mois<0 || tab[rech].operation.mois>13) || (tab[rech].operation.annee<2000)) ;

            break;
        }
        case(5):{
            printf("\nIntroduire le type de l'operation:");
            fflush(stdin);
            gets(tab[rech].typeop);
            break;
        }
        case(6):{
            do
            {printf("\nIntroduire la nouvelle reponse:");
            fflush(stdin);
            gets(tab[rech].rep);
            if(strcmp(tab[rech].rep,"O")!=0 && strcmp(tab[rech].rep,"N")!=0){
                printf("\n choix invalidde!!");}
            }while(strcmp(tab[rech].rep,"O")!=0 && strcmp(tab[rech].rep,"N")!=0);
            break;
        }
        case(7):{
            printf("\n IIntroduire le medecin responsable:");
            fflush(stdin);
            gets(tab[rech].med);
            break;
        }
        case(8):{
            do
            {printf("\n Introduire la date de sortie:");
            scanf("%d/%d/%d",&tab[rech].sortie.jour,&tab[rech].sortie.mois,&tab[rech].sortie.annee);
            if (tab[rech].sortie.jour<0 || tab[rech].sortie.jour>32){
                printf("\n jour invalide !!");}
            if (tab[rech].sortie.mois<0 || tab[rech].sortie.mois>13){
                printf("\n mois invalide !!");}
            if (tab[rech].sortie.annee<2000){
                printf("\n ann%ce invalide !!",130);}
            }while((tab[rech].sortie.jour<0 || tab[rech].sortie.jour>32) || (tab[rech].sortie.mois<0 || tab[rech].sortie.mois>13) || (tab[rech].sortie.annee<2000)) ;
            break;
        }
        default:{
            printf("\n Choix %crron%c!!",130,130);
        }

    }

}


void supprimer_hosp(hosp tab[],int *N,int rech){
    int i;
    int taille=(*N);
    for(i=rech;i<taille-1;i++){
        tab[i]=tab[i+1];
        }
    (*N)--;
}

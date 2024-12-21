#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "Gestion.h"
#include "patient.h"
#include "service.h"

extern Liste Liste_hosp;

extern Liste Liste_p;

extern Liste Liste_srv;


hosp saisir_hosp(){

 hosp hosp;
	int rech;
	int rech_p;
	int rech_srv;

	do
	{printf("\n saisir le code du patient:");
	scanf("%d",&hosp.codepatient);
	rech=recherche_hosp(Liste_hosp,hosp.codepatient);
    rech_p=recherche_p(Liste_p,hosp.codepatient);
    if(rech_p == NULL){
        printf("\nErreur:patient n'existe pas!");
    }
    else{
        if (rech!=NULL){
            printf("\nErreur:hospitalistion deja etablie pour ce patient.\n");}
    }
	}while((rech!=NULL)||(isdigit(hosp.codepatient)!=0) || rech_p == NULL);

	do
    {

	printf("\n saisir le numero du service:");
	scanf("%d",&hosp.numservice);
    rech_srv = recherche_srv(Liste_srv,hosp.numservice);
    if(rech_srv == NULL){
        printf("\nErreur:service n'existe pas!");
    }

    }while(rech_srv == NULL)

	do
	{printf("\n saisir le nombre de la chambre:");
	scanf("%d",&hosp.nbrechambre);
	if (hosp.nbrechambre>4 || hosp.nbrechambre<1){
        printf("\nErreur:le numero de la chambre doit etre compris entre 1 et 4!");}


	}while(hosp.nbrechambre>4 || hosp.nbrechambre<1);


    do
	{printf("\n saisir la date de l'hospitalisation:");
	scanf("%d/%d/%d",&hosp.hospi.jour,&hosp.hospi.mois,&hosp.hospi.annee);
	if (hosp.hospi.jour<1 || hosp.hospi.jour>31){
        printf("\n jour invalide !!");
        }
    if (hosp.hospi.mois<1 || hosp.hospi.mois>12){
        printf("\n mois invalide !!");
        }
    if (hosp.hospi.annee<2000){
        printf("\n ann%ce invalide !!",130);}
    }while((hosp.hospi.jour<1 || hosp.hospi.jour>31) || (hosp.hospi.mois<1 || hosp.hospi.mois>12) || (hosp.hospi.annee<2000)) ;


	do
	{printf("\n saisir la Date de l'operation:");
	scanf("%d/%d/%d",&hosp.operation.jour,&hosp.operation.mois,&hosp.operation.annee);
    if (hosp.operation.jour<1 || hosp.operation.jour>31){
        printf("\n jour invalide !!");
        }
    if (hosp.operation.mois<1 || hosp.operation.mois>12){
        printf("\n mois invalide !!");
        }
    if (hosp.operation.annee<2000){
        printf("\n ann%ce invalide !!",130);
        }
    if(comparer_dates(hosp.operation,hosp.hospi)==-1){
        printf("\nErreur:la date de l'operation doit etre comprise entre les dates d'entree et de sortie!");
    }

	}while ((hosp.operation.jour<1 || hosp.operation.jour>31) || (hosp.operation.mois<1 || hosp.operation.mois>12) || (hosp.operation.annee<2000));

	printf("\n saisir type de l'operation:");
	fflush(stdin);
	gets(hosp.typeop);

    do
	{printf("\n saisir la r%cponse:oui/non:",130);
	fflush(stdin);
	gets(hosp.rep);
	if (strcmp(hosp.rep,"oui")!=0 && strcmp(hosp.rep,"non")!=0){
        printf("\n r%cponse invalide!!",130);
        }
	}while(strcmp(hosp.rep,"oui")!=0 && strcmp(hosp.rep,"non")!=0);

	printf("\n saisir le medecin responsable:");
	fflush(stdin);
	gets(hosp.med);

	do
	{printf("\n saisir la date de sortie:");
	scanf("%d/%d/%d",&hosp.sortie.jour,&hosp.sortie.mois,&hosp.sortie.annee);
	if (hosp.sortie.jour<1 || hosp.sortie.jour>31){
        printf("\n jour invalide !!");
        }
    if (hosp.sortie.mois<1 || hosp.sortie.mois>12){
        printf("\n mois invalide !!");
        }
    if (hosp.sortie.annee<2000){
        printf("\n ann%ce invalide !!",130);
        }
    if(comparer_dates(hosp.sortie,hosp.operation)==-1){
        printf("\nErreur:le patient ne peut pas sortir avant son operation!");
    }
    }while((hosp.sortie.jour<1 || hosp.sortie.jour>31) || (hosp.sortie.mois<1 || hosp.sortie.mois>12) || (hosp.sortie.annee<2000) || comparer_dates(hosp.sortie,hosp.operation)==-1) ;


    return hosp;
}





Liste insere(hosp element , Liste Lst){
    struct cellule * Courrant;
    Courrant=(struct cellule*)malloc(sizeof(struct cellule));
    Courrant->valeur= element;
    Courrant->suivant=Lst;
    return (Courrant);

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

void affiche_Liste_hosp(Liste Lst)
{
struct cellule* courrant;
courrant =Lst;
while (courrant!=NULL)
{
//traitement afficher l’entier
affiche_hosp(courrant->valeur);
courrant=courrant->suivant;
}
}

hosp* recherche_hosp(Liste Lst, int code)
{
    struct cellule* courrant;
    courrant =Lst;
    while (courrant!=NULL){
        if(courrant->valeur.codepatient==code)
            return &courrant->valeur;
        courrant=courrant->suivant;}
    return NULL;
}

void modifier_hosp(hosp *hosp){
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
            scanf("%d",&hosp->numservice);
            break;
        }
        case(2):{
            do
            {printf(" \nIntroduire le nombre de la chambre:");
            scanf("%d",&hosp->nbrechambre);
            if (hosp->nbrechambre>4 || hosp->nbrechambre<1){
                printf("\n choix invalide!!");}
            }while(hosp->nbrechambre>4 || hosp->nbrechambre<1);
            break;
        }
        case (3):{
            do
            {printf("\nIntroduire la date de l'hospitalisation:");
            scanf("%d/%d/%d",&hosp->hospi.jour,&hosp->hospi.mois,&hosp->hospi.annee);
            if (hosp->hospi.jour<0 || hosp->hospi.jour>32){
                printf("\n jour invalide !!");}
            if (hosp->hospi.mois<0 || hosp->hospi.mois>13){
                printf("\n mois invalide !!");}
            if (hosp->hospi.annee<2000){
                printf("\n ann%ce invalide !!",130);}
            }while((hosp->hospi.jour<0 || hosp->hospi.jour>32) || (hosp->hospi.mois<0 || hosp->hospi.mois>13) || (hosp->hospi.annee<2000)) ;
            break;
        }
        case(4):{
            do
            {printf("\nIntroduire la date de l'operation:");
            scanf("%d/%d/%d",&hosp->operation.jour,&hosp->operation.mois,&hosp->operation.annee);
            if (hosp->operation.jour<0 || hosp->operation.jour>32){
                printf("\n jour invalide !!");}
            if (hosp->operation.mois<0 || hosp->operation.mois>13){
                printf("\n mois invalide !!");}
            if (hosp->operation.annee<2000){
                printf("\n ann%ce invalide !!",130);}
            }while((hosp->operation.jour<0 || hosp->operation.jour>32) || (hosp->operation.mois<0 || hosp->operation.mois>13) || (hosp->operation.annee<2000)) ;

            break;
        }
        case(5):{
            printf("\nIntroduire le type de l'operation:");
            fflush(stdin);
            gets(hosp->typeop);
            break;
        }
        case(6):{
            do
            {printf("\nIntroduire la nouvelle reponse:");
            fflush(stdin);
            gets(hosp->rep);
            if(strcmp(hosp->rep,"O")!=0 && strcmp(hosp->rep,"N")!=0){
                printf("\n choix invalidde!!");}
            }while(strcmp(hosp->rep,"O")!=0 && strcmp(hosp->rep,"N")!=0);
            break;
        }
        case(7):{
            printf("\n IIntroduire le medecin responsable:");
            fflush(stdin);
            gets(hosp->med);
            break;
        }
        case(8):{
            do
            {printf("\n Introduire la date de sortie:");
            scanf("%d/%d/%d",&hosp->sortie.jour,&hosp->sortie.mois,&hosp->sortie.annee);
            if (hosp->sortie.jour<0 || hosp->sortie.jour>32){
                printf("\n jour invalide !!");}
            if (hosp->sortie.mois<0 || hosp->sortie.mois>13){
                printf("\n mois invalide !!");}
            if (hosp->sortie.annee<2000){
                printf("\n ann%ce invalide !!",130);}
            }while((hosp->sortie.jour<0 || hosp->sortie.jour>32) || (hosp->sortie.mois<0 || hosp->sortie.mois>13) || (hosp->sortie.annee<2000)) ;
            break;
        }
        default:{
            printf("\n Choix %crron%c!!",130,130);
        }

    }

}


void supprimer_hosp(Liste l, int code)

{
 struct cellule *pred=NULL, *cour=l;
 while (cour)
 {
    if(cour->valeur.codepatient==code) break ;
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

int comparer_dates(Date date1, Date date2){
    if (date1.annee>date2.annee){
        return 1;
    }
    if (date1.annee < date2.annee){
        return -1;
    }
    if (date1.mois>date2.mois){
        return 1;
    }
    if (date1.mois < date2.mois){
        return -1;
    }
    if(date1.jour > date2.jour){
        return 1;
    }
    if(date1.jour < date2.jour){
        return -1;
    }
    return 0;
}


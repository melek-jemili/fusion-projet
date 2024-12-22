#include "medecind.h"

#include <stdio.h>

#include<stdlib.h>

#include <string.h>



extern med tableau_etd[100];

extern int taille_tab;



med saisir_med(){

	med m;

	//int i;

	//int rech;

    /*do

	{printf("\n introduire l'identifiant : ");

	scanf("%d",&etd.identifiant);

    rech=recherche_etd(tableau_etd,taille_tab,etd.identifiant);

    if (rech!=-1){

        printf("\n Identifiant existe d%cje!!\n",130);

    }

	}while(rech!=-1);*/

    printf("\n introduire l'identifiant : ");

	scanf("%d",&m.identifiant);

	printf("\n introduire le nom: ");

	fflush(stdin);

	fgets(m.nom,25,stdin);

	printf("\n introduire le prenom: ");

	fflush(stdin);

	fgets(m.prenom,25,stdin);

	printf("\n introduire la specialité: ");

	fflush(stdin);

	fgets(m.specialite,25,stdin);

        do{

		printf("donne le jour");

		scanf("%f",&m.date.jour);

		if((m.date.jour<0)||(m.date.jour>31)){

            printf("\ choix %crron%ce !! : 0<jour<31:",130,130);

		}

        }while((m.date.jour<0)||(m.date.jour>31));



        do{

		printf("donne le mois");

		scanf("%f",&m.date.jour);

		if((m.date.mois)||(m.date.mois>31)){

            printf("\ choix %crron%ce !! : 0<mois<12:",130,130);

		}

    }while((m.date.mois<0)||(m.date.mois>12));



        do{

		printf("donne le annee");

		scanf("%f",&m.date.anne);

		if((m.date.anne<2000)){

            printf("\ choix %crron%ce !! : 2000<annee:",130,130);

		}

        }while((m.date.jour<2000));


   printf("\n introduire le code de service: ");

	fflush(stdin);

	fgets(m.cservice,25,stdin);

	return m;

}









void affiche_med(med m){

	printf("\n *****\n identifiant : %d",m.identifiant);

	printf("\n nom: %s",m.nom);

	printf("\n Prenom : %s",m.prenom);

    printf("\n specialite: %s",m.specialite);
 printf("\n la date:%d/%d/%d %s",m.date.jour,m.date.mois,m.date.anne);
  printf("\n le code de service: %s",m.cservice);
	}








void modifier_med(med *m){

    int choix;

    printf("\n******MENU***********");

    printf("\n 1.Modifier le nom");

    printf("\n 2.Modifier le prenom");

    printf("\n 3.Modifier la specialité");

    printf("\n 4.Modifier la jour ");


    printf("\n 5.Modifier le mois");
printf("\n 6.Modifier le annee");
    printf("\n 7.Modifier le code de cervice");
    printf("\n Introduire votre choix: ");

    scanf("%d",&choix);

    switch(choix){

        case(1):{

            printf(" \nIntroduire le nom:");

            fflush(stdin);

            fgets(m->nom,25,stdin);

            break;

        }

        case(2):{

            printf(" \nIntroduire le prenom:");

            fflush(stdin);

            fgets(m->prenom,25,stdin);

            break;

        }

        case(3):{

            printf(" \nIntroduire la specialite:");

            fflush(stdin);

            fgets(m->specialite,25,stdin);

            break;

        }

        case(4):{
     do{

		printf("donne le jour");

		scanf("%f",&m->date.jour);

		if((m->date.jour<0)||(m->date.jour>31)){

            printf("\ choix %crron%ce !! : 0<jour<31:",130,130);

		}

        }while((m->date.jour<0)||(m->date.jour>31));

	}



        case(5):{
       do{

		printf("donne le mois");

		scanf("%f",&m->date.jour);

		if((m->date.jour)||(m->date.jour>31)){

            printf("\ choix %crron%ce !! : 0<mois<12:",130,130);

		}

        }while((m->date.jour<0)||(m->date.jour>12));

	}
            break;





        case(6):{
     do{

		printf("donne le annee");

		scanf("%f",&m->date.anne);

		if((m->date.anne<2000)){

            printf("\ choix %crron%ce !! : 2000<annee:",130,130);

		}

        }while((m->date.anne<2000));

	          break;

        }

        case(7):{
printf("\n introduire la specialité: ");

	fflush(stdin);

	fgets(m->specialite,25,stdin);

            break;}

        default:{

            printf("\n Choix errone!!");}

    }

}



Liste insere(med element , Liste Lst){

    struct cellule * Courrant;

    Courrant=(struct cellule*)malloc(sizeof(struct cellule));

    Courrant->valeur= element;

    Courrant->suivant=Lst;

    return (Courrant);



}



void affiche_Liste_med(Liste Lst)

{

struct cellule* courrant;

courrant =Lst;

while (courrant!=NULL)

{

//traitement afficher leentier

affiche_med(courrant->valeur);

courrant=courrant->suivant;

}

}



med* rechercher_med(Liste Lst, int ident)

{

    struct cellule* courrant;

    courrant =Lst;

    while (courrant!=NULL){

        if(courrant->valeur.identifiant==ident)

            return &courrant->valeur;

        courrant=courrant->suivant;}

    return NULL;

}












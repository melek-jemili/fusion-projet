#include <stdio.h>

#include <stdlib.h>

#include "medecind.h"

#include <string.h>

#include <time.h>



Liste Liste_m=NULL;





int main()

{

	int id;

	int choix=0;

	med* rech=NULL;

    char rep[3];

	med m;

	struct cellule* courrant;

	FILE* fichier;

	time_t seconde;

    struct tm instant;

    time(&seconde);

    instant=*localtime(&seconde);

    fichier=fopen("note.txt","rt");

    if (fichier==NULL){

        printf("\n fichier inexistant !!!");

    }else{

        while(!feof(fichier)){

                fscanf(fichier,"%d\n",&m.identifiant);

                fgets(m.nom,25,fichier);
                fgets(m.specialite,25,fichier);

                fgets(m.prenom,25,fichier);

                fscanf(fichier,"%d /%d /%d \n",&m.date.jour,&m.date.mois,&m.date.anne);

                fscanf(fichier,"%d\n",&m.cservice);
                Liste_m=insere(m,Liste_m);

        }



    }



	while (1)

	{   printf("\n************************************");

        printf("\n************MENU MEDECIN************");

        printf("\n************************************");

        printf("\n 1.Ajouter un medecin");

        printf("\n 2.Rechercher un medecin");

        printf("\n 3.Modifier un medecin");

        printf("\n 4.Supprimer un medecin");

        printf("\n 5.Afficher liste medecin");

        printf("\n 0.Quitter");

        printf("\n*************************************");

        printf("\n %d/%d/%d\t\t %d:%d",instant.tm_mday,instant.tm_mon+1,instant.tm_year+1900,instant.tm_hour,instant.tm_min);

        printf("\n*************************************");

        printf("\n Introduire votre choix:");

        scanf("%d",&choix);

        switch (choix)

        {

        case 1:

            {

                do

                {m=saisir_med();

                Liste_m=insere(m,Liste_m);

                printf("\n Voulez-vous ajouter un autre meDcin ?  oui/non:");

                scanf("%s",rep);

                }while(strcmp(rep,"oui")==0);

                break;

            }

        case 2:

            {   printf("\n introduire l'identifiant à chercher:");

                scanf("%d",&id);

                rech=rechercher_med(Liste_m,id);

                if (rech==NULL){

                printf("\n identifiant inexistant");

                }

                else{

                    affiche_med(*rech);}

                break;}



        case 3:

            {

                printf("\n introduire l'identifiant e modifier:");

                scanf("%d",&id);

                rech=rechercher_med(Liste_m,id);

                if (rech==NULL){

                printf("\n identifiant inexistant");

                }

                else{

                    affiche_med(*rech);

                    printf("\n Vous etes sure de vouloire modifier ce medcin? oui/non:");

                    scanf("%s",rep);

                    if (strcmp(rep,"oui")==0){

                        modifier_med(rech);}



                }

                break;

            }

        case 4:

            {

                printf("\n introduire l'identifiant à supprimer:");

                scanf("%d",&id);

                rech=rechercher_med(Liste_m,id);

                if (rech==NULL){

                printf("\n identifiant inexistant");

                }

                else{

                    affiche_med(*rech);

                    printf("\n Vous etes sure de vouloire supprimer ce medcin? oui/non:");

                    scanf("%s",rep);

                    if (strcmp(rep,"oui")==0){

                        supprime_med(Liste_m,id);}



                }
                break;}



        case 5:

            {

                affiche_Liste_med(Liste_m);

                break;}



        case 0:

            {

                fichier=fopen("note.txt","wt");

                if (fichier==NULL){

                    printf("\n fichier inexistant !! ");

                }else{

                    courrant =Liste_m;

                    while (courrant!=NULL){

                    //traitement afficher leentier

                        fprintf(fichier,"%d\n",courrant->valeur.identifiant);
                        fprintf(fichier,"%s\n",courrant->valeur.nom);
                        fprintf(fichier,"%s\n",courrant->valeur.prenom);
                        fprintf(fichier,"%s\n",courrant->valeur.specialite);
                        fprintf(fichier,"%d / %d / %d \n",courrant->valeur.date.jour,courrant->valeur.date.mois,courrant->valeur.date.anne);
                        fprintf(fichier,"%s\n",courrant->valeur.cservice);
                        courrant=courrant->suivant;

                    }



                    }

                    fclose(fichier);

                }

                exit(0);



        default:

            {

                printf("\n Choix errone!!");

            }



	}

}



    return 0;



}



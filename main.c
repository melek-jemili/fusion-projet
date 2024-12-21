#include <stdio.h>
#include <stdlib.h>
#include "service.h"
#include <string.h>
#include <time.h>

Liste Liste_srv=NULL;

int main()
{
	int id;
	int choix=0;
	Service* rech=NULL;
    char rep[3];
	Service srv;
	struct cellule* courrant;
	FILE* fichier;
	time_t seconde;
    struct tm instant;
    time(&seconde);
    instant=*localtime(&seconde);
    fichier=fopen("Fservice.txt","rt");
    if (fichier==NULL){
        printf("\n fichier in%cxistant !!!",130);
    }else{
        while(!feof(fichier)){
                fscanf(fichier,"%d\n",&srv.code_srv);
                fgets(srv.specialite,25,fichier);
                fscanf(fichier,"%d\n",&srv.nombrechambre);
                Liste_srv=insere(srv,Liste_srv);
        }

    }

	while (1)
	{   printf("\n****************************");
        printf("\n************MENU************");
        printf("\n****************************");
        printf("\n 1.Ajouter un service");
        printf("\n 2.Rechercher un service");
        printf("\n 3.Modifier un service");
        printf("\n 4.Supprimer un service");
        printf("\n 5.Afficher la liste des services ");
        printf("\n 0.Quitter");
        printf("\n*******************************");
        printf("\n La date:%d/%d/%d\t\t Horaire:%d:%d",instant.tm_mday,instant.tm_mon+1,instant.tm_year+1900,instant.tm_hour,instant.tm_min);
        printf("\n*******************************");
        printf("\n Introduire votre choix: ");
        scanf("%d",&choix);
        switch (choix)
        {
        case 1:
            {
                do
                {srv=saisir_srv();
                Liste_srv=insere(srv,Liste_srv);
                printf("\n Voulez-vous ajouter un autre service?oui/non:");
                scanf("%s",rep);
                }while(strcmp(rep,"oui")==0);
                break;
            }
        case 2:
            {   printf("\n introduire le code du service à chercher:");
                scanf("%d",&id);
                rech=rechercher_srv(Liste_srv,id);
                if (rech==NULL){
                printf("\n identifiant in%cxistant!!",130);
                }
                else{
                    affiche_srv(*rech);}
                break;}

        case 3:
            {
                printf("\n introduire le code du service à modifier:");
                scanf("%d",&id);
                getchar();
                printf("\n Appuyez sur Entr%ce pour valider :",130);
                getchar();
                rech=rechercher_srv(Liste_srv,id);
                if (rech==NULL){
                printf("\n identifiant in%cxistant!!",130);
                }
                else{
                    affiche_srv(*rech);
                    printf("\n Vous êtes sure de vouloire modifier ce service? oui/non:");
                    scanf("%s",rep);
                    if (strcmp(rep,"oui")==0){
                        modifier_srv(rech);
                        printf("\n la modification :");
                        affiche_srv(*rech);
                        printf("\n Voulez-vous confirmer la modification O/N?:");
                        scanf("%s",rep);
                        if(strcmp(rep,"O")==0){
                            printf("\n =>Modification confirm%ce.",130);}}}
                break;
            }
        case 4:
            {
                printf("\n introduire le code du service à supprimer:");
                scanf("%d",&id);
                getchar();
                printf("\n Appuyez sur Entr%ce pour valider :",130);
                getchar();
                rech=rechercher_srv(Liste_srv,id);
                if (rech==NULL){
                printf("\n identifiant inéxistant");
                }
                else{
                    affiche_srv(*rech);
                    printf("\n Vous êtes sure de vouloire supprimer ce service? oui/non:");
                    scanf("%s",rep);
                    if (strcmp(rep,"oui")==0){
                        supprime_srv(Liste_srv,id);
                        getchar();
                        printf("\n Appuyez sur Entr%ce pour valider la supression :",130);
                        getchar();
                        printf("\n =>Service supprim%c .",130);}

                }
                break;}

        case 5:
            {
                affiche_Liste_srv(Liste_srv);
                break;}

        case 0:
            {
                fichier=fopen("Fservice.txt","wt");
                if (fichier==NULL){
                    printf("\n fichier in%cxistant !! ",130);
                }else{
                    courrant =Liste_srv;
                    while (courrant!=NULL){
                    //traitement afficher l’entier
                        fprintf(fichier,"%d\n",courrant->valeur.code_srv);
                        fprintf(fichier,"%s\n",courrant->valeur.specialite);
                        fprintf(fichier,"%d\n",courrant->valeur.nombrechambre);
                        courrant=courrant->suivant;
                    }

                    }
                    fclose(fichier);
                }
                exit(0);

        default:
            {
                printf("\n Choix %crron%c!!",130,130);
            }

	}
}

    return 0;

}

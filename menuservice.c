#include <stdio.h>
#include <stdlib.h>
#include "Service.h"
#include <time.h>


service tableau_srv[100];
int taille_tab_service=0;


int menuservice()
{
	int code;
	int i ;
	int rech=-1;
	int choix;
	char rep[3];
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
                fscanf(fichier,"%d ",&tableau_srv[i].code_srv);
                fgets(tableau_srv[i].specialite,25,fichier);
                fscanf(fichier," %d ",&tableau_srv[i].nombrechambres);
                printf("\n");}
                fclose(fichier);
    }

	while (1)
	{   printf("\n*****************************");
        printf("\n************MENU*************");
        printf("\n*****************************");
        printf("\n****GESTION DES SERVICES****");
        printf("\n*****************************");
        printf("\n 1.Saisir tableau de service");
        printf("\n 2.Ajouter un service");
        printf("\n 3.Rechercher un service");
        printf("\n 4.Modifier un service");
        printf("\n 5.Supprimer un service");
        printf("\n 6.Afficher tableau des services");
        printf("\n 0.Quitter");
        printf("\n*******************************");
        printf("\n %d/%d/%d\t\t %d:%d",instant.tm_mday,instant.tm_mon+1,instant.tm_year+1900,instant.tm_hour,instant.tm_min);
        printf("\n*******************************");
        printf("\n Introduire votre choix: ");
        scanf("%d",&choix);

        switch (choix)
        {
        case 1:
            {   saisir_tab_srv(tableau_srv,&taille_tab_service);
                break;
            }
        case 2:
            {   ajouter_tab_srv(tableau_srv,&taille_tab_service);
                break;
            }
        case 3:
            {   printf("\n introduire le code du service � chercher:");
                scanf("%d",&code);
                rech=recherche_srv(tableau_srv,taille_tab_service,code); // rech c'est l'indice de l'�tudiant trouv�
                if (rech==-1){
                printf("\n Service in%cxistant !!",130);
                }
                else{
                    affiche_service(tableau_srv[rech]);}
                break;
            }
        case 4:
            {   printf("\n introduire le code du service  � modifier:");
                scanf("%d",&code);
                getchar();
                printf("\n Appuyez sur Entr%ce pour valider :",130);
                getchar();
                rech=recherche_srv(tableau_srv,taille_tab_service,code); // rech c'est l'indice de l'�tudiant trouv�
                if (rech!=-1){
                    affiche_service(tableau_srv[rech]);
                    printf("\n Vous �tes sure de vouloire modifier ce service oui/non ?: ");
                    scanf("%s",rep);
                    if(strcmp(rep,"oui")==0){
                        modifier_srv(tableau_srv,rech);
                        printf("\n la modification :");
                        affiche_service(tableau_srv[rech]);
                        printf("\n Voulez-vous confirmer la modification O/N?:");
                        scanf("%s",rep);
                        if(strcmp(rep,"O")==0){
                            printf("\n =>Modification confirm%ce.",130);
                            break;
                        }
                        }
                }
                else{
                   printf("\n Service in%cxistant !!",130);}
                break;
                }

        case 5:
            {   printf("\n introduire le code du service � supprimer:");
                scanf("%d",&code);
                rech=recherche_srv(tableau_srv,taille_tab_service,code); // rech c'est l'indice de l'�tudiant trouv�
                if (rech!=-1){
                    affiche_service(tableau_srv[rech]);
                    printf("\n Vous �tes sure de vouloire supprimer ce service oui/non ?: ");
                    scanf("%s",rep);
                    if(strcmp(rep,"oui")==0){
                        supprimer_srv(tableau_srv,&taille_tab_service,rech);
                        getchar();
                        printf("\n Appuyez sur Entr%ce pour valider la supression :",130);
                        getchar();
                        printf("\n =>Service supprim%c .",130);
                        }
                }
                else{
                   printf("\n Service in%cxistant !!",130);}
                break;}

        case 6:
            {   affiche_tableau_srv(tableau_srv,taille_tab_service);
                break;
            }
        case 0:
            {   fichier=fopen("Fservice.txt","wt");
                if (fichier==NULL){
                    printf("\n fichier in%cxistant !! ",130);
                }else{
                    for(i=0;i<taille_tab_service;i++){
                        fprintf(fichier,"%d ",tableau_srv[i].code_srv);
                        fprintf(fichier,"%s",tableau_srv[i].specialite);
                        fprintf(fichier," %d ",tableau_srv[i].nombrechambres);
                        printf("\n");}
                        fclose(fichier);

                }

               return 0;
            }
        default:
            {
                printf("\n Choix %crron%c!!",130,130);
            }

	}
}

    return 0;

}


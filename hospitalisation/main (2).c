#include <stdio.h>
#include <stdlib.h>
#include "hospitalisation.h"
#include <time.h>


hosp tableau_hosp[100];
int taille_tab_hosp=0;


int main()
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
    fichier=fopen("Fhospitalisation.txt","rt");
    if (fichier==NULL){
        printf("\n fichier in%cxistant !!!",130);
    }else{
            while(!feof(fichier)){
                fscanf(fichier,"%d ",&tableau_hosp[i].codepatient);
                fscanf(fichier,"%d ",&tableau_hosp[i].numservice);
                fscanf(fichier,"%d ",&tableau_hosp[i].nbrechambre);
                fscanf(fichier,"%d/%d/%d ",&tableau_hosp[i].hospi.jour,&tableau_hosp[i].hospi.mois,&tableau_hosp[i].hospi.annee);
                fscanf(fichier,"%d/%d/%d ",&tableau_hosp[i].operation.jour,&tableau_hosp[i].operation.mois,&tableau_hosp[i].operation.annee);
                fgets(tableau_hosp[i].typeop,25,fichier);
                fgets(tableau_hosp[i].rep,2,fichier);
                fgets(tableau_hosp[i].med,50,fichier);
                fscanf(fichier,"%d/%d/%d ",&tableau_hosp[i].sortie.jour,&tableau_hosp[i].sortie.mois,&tableau_hosp[i].sortie.annee);
                printf("\n");}
                fclose(fichier);
    }

	while (1)
	{   printf("\n*****************************");
        printf("\n************MENU*************");
        printf("\n*****************************");
        printf("\n****GESTION DES HOSPITALISATIONS****");
        printf("\n*****************************");
        printf("\n 1.Saisir tableau d'hospitalisation");
        printf("\n 2.Ajouter une hospitalisation");
        printf("\n 3.Rechercher une hospitalisation");
        printf("\n 4.Modifier une hospitalisation");
        printf("\n 5.Supprimer une hospitalisation");
        printf("\n 6.Afficher tableau des hospitalisations");
        printf("\n 0.Quitter");
        printf("\n*******************************");
        printf("\n %d/%d/%d\t\t %d:%d",instant.tm_mday,instant.tm_mon+1,instant.tm_year+1900,instant.tm_hour,instant.tm_min);
        printf("\n*******************************");
        printf("\n Introduire votre choix: ");
        scanf("%d",&choix);

        switch (choix)
        {
        case 1:
            {   saisir_tab_hosp(tableau_hosp,&taille_tab_hosp);
                break;
            }
        case 2:
            {   ajouter_tab_hosp(tableau_hosp,&taille_tab_hosp);
                break;
            }
        case 3:
            {   printf("\n introduire le code du patient hospitalisé à chercher:");
                scanf("%d",&code);
                rech=recherche_hosp(tableau_hosp,taille_tab_hosp,code); // rech c'est l'indice de l'étudiant trouvé
                if (rech==-1){
                printf("\n Service in%cxistant !!",130);
                }
                else{
                    affiche_hosp(tableau_hosp[rech]);}
                break;
            }
        case 4:
            {   printf("\n introduire le code du patient hospitalisé à modifier:");
                scanf("%d",&code);
                getchar();
                printf("\n Appuyez sur Entr%ce pour valider :",130);
                getchar();
                rech=recherche_hosp(tableau_hosp,taille_tab_hosp,code); // rech c'est l'indice de l'étudiant trouvé
                if (rech!=-1){
                    affiche_hosp(tableau_hosp[rech]);
                    printf("\n Vous êtes sure de vouloire modifier cet hospitalisation oui/non ?: ");
                    scanf("%s",rep);
                    if(strcmp(rep,"oui")==0){
                        modifier_hosp(tableau_hosp,rech);
                        printf("\n la modification :");
                        affiche_hosp(tableau_hosp[rech]);
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
            {   printf("\n introduire le code du patient hospitalisé à supprimer:");
                scanf("%d",&code);
                rech=recherche_hosp(tableau_hosp,taille_tab_hosp,code); // rech c'est l'indice de l'étudiant trouvé
                if (rech!=-1){
                    affiche_hosp(tableau_hosp[rech]);
                    printf("\n Vous êtes sure de vouloire supprimer cet hospitalisation oui/non ?: ");
                    scanf("%s",rep);
                    if(strcmp(rep,"oui")==0){
                        supprimer_hosp(tableau_hosp,&taille_tab_hosp,rech);
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
            {   affiche_tableau_hosp(tableau_hosp,taille_tab_hosp);
                break;
            }
        case 0:
            {   fichier=fopen("Fhospitalisation.txt","wt");
                if (fichier==NULL){
                    printf("\n fichier in%cxistant !! ",130);
                }else{
                    for(i=0;i<taille_tab_hosp;i++){
                        fprintf(fichier,"%d ",tableau_hosp[i].codepatient);
                        fprintf(fichier,"%d",tableau_hosp[i].numservice);
                        fprintf(fichier,"%d ",tableau_hosp[i].nbrechambre);
                        fprintf(fichier,"%d/%d/%d ",tableau_hosp[i].hospi.jour,tableau_hosp[i].hospi.mois,tableau_hosp[i].hospi.annee);
                        fprintf(fichier," %d/%d/%d ",tableau_hosp[i].operation.jour,tableau_hosp[i].operation.mois,tableau_hosp[i].operation.annee);
                        fprintf(fichier,"%s ",tableau_hosp[i].typeop);
                        fprintf(fichier,"%s ",tableau_hosp[i].rep);
                        fprintf(fichier,"%s ",tableau_hosp[i].med);
                        fprintf(fichier,"%d/%d/%d ",tableau_hosp[i].sortie.jour,tableau_hosp[i].sortie.mois,tableau_hosp[i].sortie.annee);
                        printf("\n");}
                        fclose(fichier);

                }

                exit(0);
            }
        default:
            {
                printf("\n Choix %crron%c!!",130,130);
            }

	}
}

    return 0;

}



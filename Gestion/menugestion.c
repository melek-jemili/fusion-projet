#include <stdio.h>
#include <stdlib.h>
#include "Gestion.h"
#include <time.h>


Liste Liste_hosp=NULL;



int menugestion()
{
	int id;
	int choix=0;
	hosp* rech=NULL;
    char rep[3];
	hosp hosp;
	struct cellule* courrant;
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
                fscanf(fichier,"%d ",&hosp.codepatient);
                fscanf(fichier,"%d ",&hosp.numservice);
                fscanf(fichier,"%d ",&hosp.nbrechambre);
                fscanf(fichier,"%d/%d/%d ",&hosp.hospi.jour,&hosp.hospi.mois,&hosp.hospi.annee);
                fscanf(fichier,"%d/%d/%d ",&hosp.operation.jour,&hosp.operation.mois,&hosp.operation.annee);
                fgets(hosp.typeop,25,fichier);
                fgets(hosp.rep,3,fichier);
                fgets(hosp.med,50,fichier);
                fscanf(fichier,"%d/%d/%d ",&hosp.sortie.jour,&hosp.sortie.mois,&hosp.sortie.annee);
                Liste_hosp=insere(hosp,Liste_hosp);
                printf("\n");}
                fclose(fichier);
    }

	while (1)
	{   printf("\n*****************************");
        printf("\n************MENU*************");
        printf("\n*****************************");
        printf("\n****GESTION DES HOSPITALISATIONS****");
        printf("\n*****************************");
        printf("\n 1.Saisir une d'hospitalisation");
        printf("\n 2.Rechercher une hospitalisation");
        printf("\n 3.Modifier une hospitalisation");
        printf("\n 4.Supprimer une hospitalisation");
        printf("\n 5.Afficher la liste des hospitalisations");
        printf("\n 0.Quitter");
        printf("\n*******************************");
        printf("\n %d/%d/%d\t\t %d:%d",instant.tm_mday,instant.tm_mon+1,instant.tm_year+1900,instant.tm_hour,instant.tm_min);
        printf("\n*******************************");
        printf("\n Introduire votre choix: ");
        scanf("%d",&choix);

        switch (choix)
        {
        case 1:
            {   do
                {hosp=saisir_hosp();
                Liste_hosp=insere(hosp,Liste_hosp);
                printf("\n Voulez-vous ajouter une autre hospitalisation?oui/non:");
                scanf("%s",rep);
                }while(strcmp(rep,"oui")==0);
                break;
            }
        case 2:
            {   printf("\n introduire l'identifiant du patient hospitalis%c à chercher:",130);
                scanf("%d",&id);
                rech=recherche_hosp(Liste_hosp,id);
                if (rech==NULL){
                printf("\n identifiant in%cxistant!!",130);
                }
                else{
                    affiche_hosp(*rech);}
                break;
            }
        case 3:
            {   printf("\n introduire le code du patient hospitalisé à modifier:");
                scanf("%d",&code);
                getchar();
                printf("\n Appuyez sur Entr%ce pour valider :",130);
                getchar();
                rech=recherche_hosp(Liste_hosp,id); // rech c'est l'indice de l'étudiant trouvé
                if (rech!=-1){
                    affiche_hosp(*rech);
                    printf("\n Vous êtes sure de vouloire modifier cet hospitalisation oui/non ?: ");
                    scanf("%s",rep);
                    if(strcmp(rep,"oui")==0){
                        modifier_hosp(rech);
                        printf("\n la modification :");
                        affiche_hosp(*rech);
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

        case 4:
            {   printf("\n introduire le code du patient hospitalisé à supprimer:");
                scanf("%d",&code);
                rech=recherche_hosp(Liste_hosp,id); // rech c'est l'indice de l'étudiant trouvé
                if (rech!=-1){
                    affiche_hosp(*rech);
                    printf("\n Vous êtes sure de vouloire supprimer cet hospitalisation oui/non ?: ");
                    scanf("%s",rep);
                    if(strcmp(rep,"oui")==0){
                        supprimer_hosp(Liste_hosp,id);
                        getchar();
                        printf("\n Appuyez sur Entr%ce pour valider la supression :",130);
                        getchar();
                        printf("\n =>Service supprim%c .",130);
                        }
                }
                else{
                   printf("\n Service in%cxistant !!",130);}
                break;}

        case 5:
            {   affiche_Liste_hosp(Liste_hosp);
                break;
            }
        case 0:
            {   fichier=fopen("Fhospitalisation.txt","wt");
                if (fichier==NULL){
                    printf("\n fichier in%cxistant !! ",130);
                }else{
                    courrant =Liste_hosp;
                    while (courrant!=NULL){{
                        fprintf(fichier,"%d ",courrant->valeur.codepatient);
                        fprintf(fichier,"%d",courrant->valeur.numservice);
                        fprintf(fichier,"%d ",courrant->valeur.nbrechambre);
                        fprintf(fichier,"%d/%d/%d ",courrant->valeur.hospi.jour,courrant->valeur.hospi.mois,courrant->valeur.hospi.annee);
                        fprintf(fichier," %d/%d/%d ",courrant->valeur.operation.jour,courrant->valeur.operation.mois,courrant->valeur.operation.annee);
                        fprintf(fichier,"%s ",courrant->valeur.typeop);
                        fprintf(fichier,"%s ",courrant->valeur.rep);
                        fprintf(fichier,"%s ",courrant->valeur.med);
                        fprintf(fichier,"%d/%d/%d ",courrant->valeur.sortie.jour,courrant->valeur.sortie.mois,courrant->valeur.sortie.annee);
                        courrant=courrant->suivant;
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



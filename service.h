#ifndef SERVICE_H_INCLUDED
#define SERVICE_H_INCLUDED

typedef struct srv
{
	int code_srv ;
	char specialite[25];
    int nombrechambre ;

}Service;

struct cellule
{
Service valeur;
struct cellule *suivant;
};
typedef struct cellule *Liste;


Service saisir_srv();

void affiche_srv(Service s);

void modifier_srv(Service *s);

Liste insere(Service element , Liste Lst);

void affiche_Liste_srv(Liste Lst);

Service* rechercher_srv(Liste Lst, int code);

void supprime_srv(Liste l, int code);





#endif // SERVICE_H_INCLUDED

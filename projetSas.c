#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>

typedef struct date
{
    int jour;
    int mois;
    int annee;
} date;

typedef struct tache
{
    int id;
    char titre[100];
    date deadline[100];
    char description[100];
    char statut[100];
} tache;
int n = 0;

void ajouter(tache t[])
{

    t->id = n + 1;
    printf("%d\n", n + 1);
    printf("Entrer le titre du tache : \n");
    scanf("%s", t[n].titre);
    printf("Entrer la description du tache : \n");
    scanf("%s", t[n].description);
    printf("Entrer le deadline du tache : \n");
    printf("Entrer le deadline jour mois annee : \n");
    scanf("%d %d %d", &t[n].deadline->jour, &t[n].deadline->mois, &t[n].deadline->annee);
    printf("Entrer le statut du tache : \n");
    scanf("%s", t[n].statut);

        printf("\n\n\n\nLe titre du tache est : %s\n", t.titre);
    printf("La description du tache est : %s\n", t.description);
    printf("Le statut du tache est : %s\n", t.statut);
}

void afficher()
{
    tache t;ç

    printf("%d\n", n + 1);
    printf("Le titre du tache est : %s\n", t.titre);
    printf("La description du tache est : %s\n", t.description);
    printf("Le statut du tache est : %s\n", t.statut);
}

int main()
{
    tache T[200];
    int choix;
    do
    {
        printf("**********1 - Ajouter une nouvelle tache : **********\n");
        printf("**********2 - Ajouter plusieurs nouvelles taches : **********\n");
        printf("**********3 - Afficher la liste de toute les taches : **********\n");
        printf("**********4 - Modifier une tache : **********\n");
        printf("**********5 - Supprimer une tache par identifiant : **********\n");
        printf("**********6 - Rechercher les taches : **********\n");
        printf("**********7 - Statistiques : **********\n");
        printf("**********8 - Quitter les taches : **********\n");

        printf("Tapez votre choix : ");
        scanf("%d", &choix);
        switch (choix)
        {
        case 1:
            printf("1 - Ajouter une nouvelle tache : \n");
            ajouter(T);
            afficher(T);
            break;
        case 2:
            printf("2 - Ajouter plusieurs nouvelles taches : \n");
            break;
        case 3:
            printf("3 - Afficher la liste de toute les taches : \n");
            int choixtri;
            do
            {
                printf("1-Trier la tache par ordre alphabetique : \n");
                printf("2-Trier la tache par deadline : \n");
                printf("3-Afficher les taches dont le deadline est 3 jours ou moins : \n");
                printf("4-Quitter\n");
                printf("Choisi le tri que vous voulez : ");
                scanf("%d", &choixtri);
                switch (choixtri)
                {
                case 1:
                    printf("Choisi le tri que vous voulez : \n");
                    printf("1-Trier la tache par ordre alphabetique : \n");
                    break;
                case 2:
                    printf("2-Trier la tache par deadline : \n");
                    break;
                case 3:
                    printf("3-Afficher les taches dont le deadline est 3 jours ou moins : \n");
                    break;
                case 4:
                    printf("4-Quitter \n");
                    break;
                default:
                    printf("choix invalid : \n");
                    break;
                }

            } while (choixtri != 4);

            break;
        case 4:
            printf("Modifier une tache : \n");
            int choixModifier;
            do
            {
                printf("1-Modifier la descriotion d'une tache : \n");
                printf("2-Modifier le status d'une tache : \n");
                printf("3-Modifier le deadline du tache : \n");
                printf("4-Quitter \n");
                printf("Choisi la modification que vous voulez : ");
                scanf("%d", &choixModifier);
                switch (choixModifier)
                {
                case 1:
                    printf("1-Modifier la descriotion d'une tache : \n");
                    break;
                case 2:
                    printf("2-Modifier le status d'une tache : \n");
                    break;
                case 3:
                    printf("3-Modifier le deadline du tache : \n");
                    break;
                case 4:
                    printf("4-Quitter \n");
                    break;
                default:
                    printf("choix invalid : \n");
                    break;
                }

            } while (choixModifier != 4);

            break;
        case 5:
            printf("Supprimer une tache par identifiant : ");
            break;
        case 6:
            printf("Rechercher les taches : \n");
            int choixRecherche;
            do
            {
                printf("1-Recherche une tache par son Identifiant : \n");
                printf("2-Recherche une tache par son Titre : : \n");
                printf("3-Quitter\n");
                printf("Choisi la recherche que vous voulez : \n");
                scanf("%d", &choixRecherche);
                switch (choixRecherche)
                {
                case 1:
                    printf("1-Recherche une tache par son Identifiant : \n");
                    break;
                case 2:
                    printf("2-Recherche une tache par son Titre : \n");
                    break;
                case 3:
                    printf("3-Quitter");
                    break;
                default:
                    printf("choix invalid : \n");
                    break;
                }

            } while (choixRecherche != 3);

            break;
        case 7:
            printf("Statistiques : ");
            int choixStatistique;
            do
            {
                printf("1-Recherche une tache par son Identifiant : \n");
                printf("2-Recherche une tache par son Titre : : \n");
                printf("3-Quitter\n");
                printf("Choisi la recherche que vous voulez : \n");
                scanf("%d", &choixStatistique);
                switch (choixStatistique)
                {
                case 1:
                    printf("1-Afficher le nombre total des taches : \n");
                    break;
                case 2:
                    printf("2-Afficher le nombre de taches completes et incompletes : \n");
                    break;
                case 3:
                    printf("3-Afficher le nombre de jours restantsn jusqu'au delai de chaque tache:\n");
                case 4:
                    printf("4-Quitter");
                    break;
                default:
                    printf("choix invalid : \n");
                    break;
                }

            } while (choixStatistique != 4);
            break;
        case 8:
            printf("Quitter");
        default:
            printf("Choix invalide : \n");
            break;
        }
    } while (choix != 8);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>

int main()
{

    char menu[100];
    int choix;
    do
    {
        printf("1 - Ajouter une nouvelle tache : \n");
        printf("2 - Ajouter plusieurs nouvelles taches : \n");
        printf("3 - Afficher la liste de toute les taches : \n");
        printf("4 - Modifier une tache : \n");
        printf("5 - Supprimer une tache par identifiant : \n");
        printf("6 - Rechercher les taches : \n");
        printf("7 - Statistiques : \n");
        printf("8 - Quitter les taches : \n");

        printf("Tapez votre choix : ");
        scanf("%d", &choix);
        switch (choix)
        {
        case 1:
            printf("1 - Ajouter une nouvelle tache : \n");
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
                printf("4-Quitter");
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
                    printf("chois invalid : \n");
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
                    printf("chois invalid : \n");
                    break;
                }

            } while (choixModifier != 4);

            break;
        case 5:
            printf("Supprimer une tache par identifiant : ");
            break;
        case 6:
            printf("Rechercher les taches : ");
            break;
        case 7:
            printf("Statistiques : ");
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
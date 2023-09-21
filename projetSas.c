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

int taille = 0;
void ajouter(tache t[])
{
    printf("Entrer les information de votre tache  :\n");
    t[taille].id = taille + 1;
    printf("l'ID = %d\n", t[taille].id);
    printf("Entrer le titre du tache : \n");
    scanf(" %[^\n]", t[taille].titre);
    printf("Entrer la description du tache : \n");
    scanf(" %[^\n]", t[taille].description);
    printf("Entrer le deadline du tache : \n");
    printf("Entrer le deadline ( jour mois annee ): \n");
    scanf("%d/%d/%d", &t[taille].deadline->jour, &t[taille].deadline->mois, &t[taille].deadline->annee);
    int choix;
    printf("Entrer le statut du tache : \n");
    printf("1. Si votre tache est a realiser\n");
    printf("2. Si votre tache est en cours\n");
    printf("3. Si votre tache est finalisee\n");
    scanf("%d", &choix);
    switch (choix)
    {
    case 1:
        strcpy(t[taille].statut, " est a realiser\n");
        break;
    case 2:
        strcpy(t[taille].statut, " est en cours\n");
        break;
    case 3:
        strcpy(t[taille].statut, " est finalisee\n");
        break;
    default:
        break;
    }
    printf("Status : %s", t[taille].statut);
    taille++;
}

void triParOrderAlphabetique(tache t[])
{
    int echange;
    for (int i = 0; i < taille - 1; i++)
    {
        echange = 0;
        for (int j = 0; j < taille - i - 1; j++)
        {
            if (strcmp(t[j].titre, t[j + 1].titre) > 0)
            {
                tache temp = t[j];
                t[j] = t[j + 1];
                t[j + 1] = temp;
                echange = 1;
            }
        }
        if (echange == 0)
            break;
    }
    afficher(t);
}

void triParOrderDeadline(tache t[])
{
    for (int i = 0; i < taille - 1; i++)
    {
        for (int j = 0; j < taille - i - 1; j++)
        {
            if ((t[j].deadline->annee > t[j + 1].deadline->annee) ||
                ((t[j].deadline->annee == t[j + 1].deadline->annee) && (t[j].deadline->mois > t[j + 1].deadline->mois)) ||
                ((t[j].deadline->annee == t[j + 1].deadline->annee) && (t[j].deadline->mois == t[j + 1].deadline->mois) && (t[j].deadline->jour > t[j + 1].deadline->jour)))
            {
                tache temp = t[j];
                t[j] = t[j + 1];
                t[j + 1] = temp;
            }
        }
    }
    afficher(t);
}

void afficher(tache t[])
{
    int i;
    printf("Affichage de la liste des taches :\n");
    for (i = 0; i < taille; i++)
    {
        printf("ID              |  %d\n", t[i].id);
        printf("\n--------------------------------\n");
        printf("Titre           |  %s\n", t[i].titre);
        printf("\n--------------------------------\n");
        printf("Description     |  %s\n", t[i].description);
        printf("\n--------------------------------\n");
        printf("Deadline        |  %d %d %d\n", t[i].deadline->jour, t[i].deadline->mois, t[i].deadline->annee);
        printf("\n--------------------------------\n");
        printf("Statut          |  %s\n", t[i].statut);
    }
}

void ajouterPlusieurTache(tache t[])
{
    int n, i;
    printf("Tapez le nombre des taches que vous voulez : ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        ajouter(t);
    }
}
int main()
{
    tache t[200];
    int choix;
    printf("/* -------------------- Gestion de Taches ToDo -------------------- */\n");
    do
    {
        printf("---------- 1 - Ajouter une nouvelle tache :             ---------- \n");
        printf("---------- 2 - Ajouter plusieurs nouvelles taches :     ---------- \n");
        printf("---------- 3 - Afficher la liste de toute les taches :  ---------- \n");
        printf("---------- 4 - Modifier une tache :                     ---------- \n");
        printf("---------- 5 - Supprimer une tache par identifiant :    ---------- \n");
        printf("---------- 6 - Rechercher les taches :                  ---------- \n");
        printf("---------- 7 - Statistiques :                           ---------- \n");
        printf("---------- 8 - Quitter les taches :                     ---------- \n");

        printf("Tapez votre choix : ");
        scanf("%d", &choix);
        switch (choix)
        {
        case 1:
            printf("1 - Ajouter une nouvelle tache : \n");
            ajouter(t);
            break;
        case 2:
            printf("2 - Ajouter plusieurs nouvelles taches : \n");
            ajouterPlusieurTache(t);
            break;
        case 3:
            printf("3 - Afficher la liste de toute les taches : \n");
            printf("--------------------------------\n");
            printf("1 - Trier par ordre alphabetique :\n");
            printf("2 - Trier par ordre deadline :\n");
            printf("3 - Afficher les taches dont le deadline est dans 3 jours ou moins : \n");
            printf("4 - Quitter \n");
            printf("----------------------------------------------------------------");
            int choixTri;
            do
            {

                switch (choixTri)
                {
                case 1:
                    printf("1-Trier les taches par ordre alphabetique : \n");
                    triParOrderAlphabetique(t);
                    break;
                case 2:
                    printf("2-Trier les taches par deadline  : \n");
                    triParOrderDeadline(t);

                    break;
                case 3:
                    printf("3-Afficher les taches dont le deadline est dans 3 jours ou moins : \n");
                    break;
                case 4:
                    printf("4-Quitter \n");
                    break;
                default:
                    printf("choix invalid : \n");
                    break;
                }
                printf("Tapez le tri qui vous voulez :");
                scanf("%d", &choixTri);

            } while (choixTri != 4);
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

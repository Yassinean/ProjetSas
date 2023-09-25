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

int id;
int taille = 0;
int verifier;
void ajouter(tache t[])
{
    printf("Entrer les information de votre tache  :\n");
    t[taille].id = taille + 1;

    printf("l'ID = %d\n", t[taille].id);
    printf("Entrer le titre du tache : \n");
    scanf(" %[^\n]", t[taille].titre);
    printf("Entrer la description du tache : \n");
    scanf(" %[^\n]", t[taille].description);

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
        strcpy(t[taille].statut, " est finalisee");
        break;
    default:
        printf("\nChoix invalide\n");
        break;
    }
    printf("Status : %s", t[taille].statut);
    taille++;
    printf("\n---------------------------------------------------------\n");
    printf("Votre tache est ajoutee avec succes ");
    printf("\n---------------------------------------------------------\n");
}

void afficher(tache t[])
{
    int i;
    printf("Affichage de la liste des taches :\n");
    for (i = 0; i < taille; i++)
    {
        printf("ID              |  %d\n", t[i].id);
        printf("-------------------------------------------------------------\n");
        printf("Titre           |  %s\n", t[i].titre);
        printf("-------------------------------------------------------------\n");
        printf("Description     |  %s\n", t[i].description);
        printf("-------------------------------------------------------------\n");
        printf("Deadline        |  %d %d %d\n", t[i].deadline->jour, t[i].deadline->mois, t[i].deadline->annee);
        printf("-------------------------------------------------------------\n");
        printf("Statut          |  %s\n\n", t[i].statut);
    }
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

void afficherdeadline(tache t[])
{
    int i, deadline, jours;
    time_t seconds = time(NULL);
    struct tm *current_time = localtime(&seconds);
    int currentYear = (current_time->tm_year + 1900);
    int currentMonth = (current_time->tm_mon + 1);
    int currentDay = current_time->tm_mday;

    for (i = 0; i < taille; i++)
    {
        jours = t[i].deadline->annee * 365 + t[i].deadline->mois * 30 + t[i].deadline->jour;
        deadline = jours - (currentYear * 365 + currentMonth * 30 + currentDay);

        if (deadline > 0 && deadline <= 3)
        {
            printf("--------------------------------------------------------------------------------------------------\n");
            printf("%-4s | %-20s | %-40s | %-12s | %-15s \n", "ID", "Titre", "Description", "Deadline", "Statut");
            printf("--------------------------------------------------------------------------------------------------\n");
            printf("%-4d | %-20s | %-40s | %02d/%02d/%d | %-15s \n", t[i].id, t[i].titre, t[i].description, t[i].deadline->jour, t[i].deadline->mois, t[i].deadline->annee, t[i].statut);
            printf("--------------------------------------------------------------------------------------------------\n");
        }
    }
}
void modifierDescription(tache t[])
{
    printf("Tapez l'ID de la tache que vous voulez modifier : ");
    scanf("%d", &id);
    for (int i = 0; i < taille; i++)
    {
        if (t[i].id == id)
        {
            printf("Tapez la nouvelle description de la tache : ");
            scanf(" %[^\n]", t[i].description);
        }
    }
}

void modifierStatut(tache t[])
{
    int choix;
    printf("Tapez l'ID de la tache que vous voulez modifier : ");
    scanf("%d", &id);
    for (int i = 0; i < taille; i++)
    {
        if (t[i].id == id)
        {
            printf("Choisir le nouveau status de la tache : ");
            printf("1-Si votre status est a realiser : \n");
            printf("2-Si votre status est en cours : \n");
            printf("3-Si votre status est finalisee : \n");
            scanf("%d", &choix);

            switch (choix)
            {
            case 1:
                strcpy(t[i].statut, " est a realiser");
                break;
            case 2:
                strcpy(t[i].statut, " est en cours");
                break;
            case 3:
                strcpy(t[i].statut, " est finalisee");
                break;
            default:
                printf("Choix invalide\n");
                break;
            }
        }
    }
}

void modifierDeadline(tache t[])
{
    printf("Tapez l'ID de la tache que vous voulez modifier : ");
    scanf("%d",&id);
    for (int i = 0; i < taille; i++)
    {
        if (t[i].id == id)
        {
        date:
            printf("Tapez la nouvelle deadline de la tache : \n");
            scanf("%d/%d/%d", &t[i].deadline->jour, &t[i].deadline->mois, &t[i].deadline->annee);
            if (t[i].deadline->jour < 1 || t[i].deadline->jour > 31 || t[i].deadline->mois < 1 || t[i].deadline->mois > 12)
            {
                printf("date invalid!! \n");
                goto date;
            }
        }
    }
}

void supprimerTache(tache t[])
{
    printf("Tapez l'ID de la tache que vous voulez supprimer : ");
    scanf("%d", &id);
    for (int i = 0; i < taille; i++)
    {
        if (t[i].id == id)
        {
            for (int j = i; j < taille - 1; j++)
            {
                t[j] = t[j + 1];
            }
            taille--;
        }
    }
}

void rechercherTacheId(tache t[])
{
    verifier = 0;
    printf("Tapez l'ID de la tache que vous voulez rechercher : ");
    scanf("%d", &id);
    for (int i = 0; i < taille; i++)
    {
        if (t[i].id == id)
        {
            printf("ID :            | %d\n", t[i].id);
            printf("-------------------------------------------------------------\n");
            printf("Titre :         | %s\n", t[i].titre);
            printf("-------------------------------------------------------------\n");
            printf("Description :   | %s\n", t[i].description);
            printf("-------------------------------------------------------------\n");
            printf("Deadline :      | %d %d %d\n", t[i].deadline->jour, t[i].deadline->mois, t[i].deadline->annee);
            printf("-------------------------------------------------------------\n");
            printf("Statut :        | %s\n", t[i].statut);
            verifier = 1;
        }
    }
    if (verifier == 0)
        printf("Aucune tache trouvee a cet ID !\n");
}

void rechercherTacheTitre(tache t[])
{
    char tu[100]; // titre utilisateur
    int i;
    verifier = 0;
    printf("Tapez le titre de la tache que vous voulez rechercher : \n");
    scanf(" %[^\n]", tu);
    for (i = 0; i < taille; i++)
    {
        if (strcmp(t[i].titre, tu) == 0)
        {
            printf("Cette tache est touvee : \n");
            printf("ID :            | %d\n", t[i].id);
            printf("-------------------------------------------------------------\n");
            printf("Titre :         | %s\n", t[i].titre);
            printf("-------------------------------------------------------------\n");
            printf("Description :   | %s\n", t[i].description);
            printf("-------------------------------------------------------------\n");
            printf("Deadline :      | %d %d %d\n", t[i].deadline->jour, t[i].deadline->mois, t[i].deadline->annee);
            printf("-------------------------------------------------------------\n");
            printf("Statut :        | %s\n\n", t[i].statut);
            verifier = 1;
            break;
        }
    }
    if (verifier == 0)
        printf("Aucune tache trouvee a ce titre !\n");
}
void afficherNbrTotalTaches()
{
    printf("Le nombre total de taches est : %d\n", taille);
}

void afficherNbrTachesCompleteIncompletes(tache t[])
{
    int complete = 0;
    int incomplete = 0;

    for (int i = 0; i < taille; i++)
    {
        if (strcmp(t[i].statut, " est finalisee") == 0)
        {
            complete++;
        }
        else
        {
            incomplete++;
        }
    }

    printf("Nombre de taches completes : %d\n", complete);
    printf("Nombre de taches incompletes : %d\n\n", incomplete);
}

void statistiques(tache t[])
{
    printf("Statistiques :\n");


    printf("Nombre de jours restants jusqu'au delai de chaque tache :\n");
    printf("%-5s %-20s %-12s %-20s\n", "ID", "Titre", "Delai (j)", "Statut");

    for (int i = 0; i < taille; i++)
    {
        struct tm task_tm = {0};
        task_tm.tm_mday = t[i].deadline->jour;
        task_tm.tm_mon = t[i].deadline->mois - 1;
        task_tm.tm_year = t[i].deadline->annee - 1900;

        time_t currentTime;
        time(&currentTime);

        time_t taskTime = mktime(&task_tm);
        double diff = difftime(taskTime, currentTime);
        int joursRestants = diff / (60 * 60 * 24);

        printf("%-5d %-20s %-12d %-20s\n", t[i].id, t[i].titre, joursRestants, t[i].statut);
    }
}

int main()
{
    tache t[200];
    int choix;
    printf("===================== Gestion de Taches ToDo =====================\n");
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
            printf("\n---------------------- Ajouter une nouvelle tache -----------------\n");
            ajouter(t);
            break;
        case 2:
            printf("\n---------------- Ajouter plusieurs nouvelles taches -----------------------\n");
            ajouterPlusieurTache(t);
            break;
        case 3:
            printf("--------------- Afficher la liste de toute les taches ---------------------\n");
            printf("-----------------------------------------------------------------\n");
            printf("1 - Trier par ordre alphabetique :\n");
            printf("2 - Trier par ordre deadline :\n");
            printf("3 - Afficher les taches dont le deadline est dans 3 jours ou moins : \n");
            printf("4 - Quitter \n");
            printf("----------------------------------------------------------------\n");
            int choixTri;
            printf("Tapez le tri qui vous voulez :");
            scanf("%d", &choixTri);
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
                afficherdeadline(t);
                break;
            case 4:
                printf("4-Quitter \n");
                break;
            default:
                printf("choix invalid : \n");
                break;
            }
            break;
        case 4:
            printf("\n----------- Modifier une tache ---------------\n");
            int choixModifier;
            printf("----------------------------------------------------------------\n");
            printf("1-Modifier la description d'une tache : \n");
            printf("2-Modifier le status d'une tache : \n");
            printf("3-Modifier le deadline du tache : \n");
            printf("4-Quitter \n");
            printf("----------------------------------------------------------------\n");
            printf("Choisi la modification que vous voulez : ");
            scanf("%d", &choixModifier);
            switch (choixModifier)
            {
            case 1:
                printf("1-Modifier la description d'une tache : \n");
                modifierDescription(t);
                break;
            case 2:
                printf("2-Modifier le status d'une tache : \n");
                modifierStatut(t);
                break;
            case 3:
                printf("3-Modifier le deadline du tache : \n");
                modifierDeadline(t);
                break;
            case 4:
                printf("4-Quitter \n");
                break;
            default:
                printf("choix invalid : \n");
                break;
            }
            break;
        case 5:
            printf("\n-------- Supprimer une tache par identifiant ------------\n");
            supprimerTache(t);
            break;
        case 6:
            printf("\n---------- Rechercher les taches ---------------\n");
            int choixRecherche;
            printf("----------------------------------------------------------------\n");
            printf("1-Recherche une tache par son Identifiant : \n");
            printf("2-Recherche une tache par son Titre : : \n");
            printf("3-Quitter\n");
            printf("----------------------------------------------------------------\n");
            printf("Choisi la recherche que vous voulez : \n");
            scanf("%d", &choixRecherche);
            switch (choixRecherche)
            {
            case 1:
                printf("1-Recherche une tache par son Identifiant : \n");
                rechercherTacheId(t);
                break;
            case 2:
                printf("2-Recherche une tache par son Titre : \n");
                rechercherTacheTitre(t);
                break;
            case 3:
                printf("3-Quitter\n");
                break;
            default:
                printf("choix invalid : \n");
                break;
            }
            break;
        case 7:
            printf("\n---------------- Statistiques  -------------------\n");
            int choixStatistique;
            printf("----------------------------------------------------------------\n");
            printf("1-Afficher le nombre total des taches : \n");
            printf("2-Afficher le nombre de taches completes et incompletes :  \n");
            printf("3-Afficher le nombre de jours restants jusqu'au delai de chaque tache\n");
            printf("4-Quitter : \n");
            printf("----------------------------------------------------------------\n");
            printf("Choisi la recherche que vous voulez : \n");
            scanf("%d", &choixStatistique);
            switch (choixStatistique)
            {
            case 1:
                printf("1-Afficher le nombre total des taches :\n");
                afficherNbrTotalTaches(t);
                break;
            case 2:
                printf("2-Afficher le nombre de taches completes et incompletes : \n");
                afficherNbrTachesCompleteIncompletes(t);
                break;
            case 3:
                printf("3-Afficher le nombre de jours restants jusqu'au delai de chaque tache:\n");
                statistiques(t);
            case 4:
                printf("4-Quitter\n");
                break;
            default:
                printf("choix invalid : \n");
                break;
            }
            break;
        case 8:
            printf("Quitter\n");
            break;
        default:
            printf("Choix invalide : \n");
            break;
        }
    } while (choix != 8);

    return 0;
}

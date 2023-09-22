
#include <stdio.h>
#include <string.h>

int taille = 0;

typedef struct
{
    int jour;
    int mois;
    int annee;
} date;

typedef struct
{
    int id;
    char titre[100];
    char description[255];
    date deadline;
    char statut[100];
} tache;

void AjoutTache(tache TabTache[])
{

    printf("     Entrez les informations des taches: \n");

    TabTache[taille].id = taille + 1;

    printf("Id = %d \n", TabTache[taille].id);
    printf("Le titre de la tache est: \n");
    scanf(" %[^\n]", TabTache[taille].titre);
    printf("Description: \n");
    // scanf("%s", TabTache[taille].description);
    scanf(" %[^\n]", TabTache[taille].description);
    printf("Entrez le Deadline (jour mois annee) : \n");
    scanf("%d%d%d", &TabTache[taille].deadline.jour, &TabTache[taille].deadline.mois, &TabTache[taille].deadline.annee);

    int choix;
    printf("Le statut de le tache: \n");
    printf("Cliquez 1 si votre tache est a realiser: \n");
    printf("Cliquez 2 si votre tache est en cours de realisation\n");
    printf("Cliquez 3 si votre tache est finalisee\n");
    scanf("%d", &choix);

    switch (choix)
    {

    case 1:
        strcpy(TabTache[taille].statut, "a realiser");
        break;

    case 2:
        strcpy(TabTache[taille].statut, "en cours de realisation");
        break;

    case 3:
        strcpy(TabTache[taille].statut, "finalisee");
        break;

    default:
        printf("Entrez un des trois etats cite.\n");
        break;
    }

    printf("Statut : %s\n", TabTache[taille].statut);

    taille++;
}

void AjoutPlusieurTaches(tache TabTache[])
{
    int i, a;
    printf("Combien de taches voulez vous entrer? ");
    scanf("%d", &a);
    for (i = 0; i < a; i++)
    {
        AjoutTache(TabTache);
    }
}
void TriTachesAlphabetique(tache TabTache[])
{
    int i, j;
    tache temp;
    int echange;

    // Tri à bulles amélioré
    for (i = 0; i < taille - 1; i++)
    {
        echange = 0;
        for (j = 0; j < taille - i - 1; j++)
        {
            // Compare les premières lettres des titres de tâches
            if (TabTache[j].titre[0] > TabTache[j + 1].titre[0])
            {
                temp = TabTache[j];
                TabTache[j] = TabTache[j + 1];
                TabTache[j + 1] = temp;
                echange = 1; // Indique qu'un échange a été effectué
            }
        }
        // Si aucune permutation n'a été effectuée lors de cette passe, le tableau est trié
        if (echange == 0)
            break;
    }

    /*int i, j;
    tache temp;

    //tri a bulles
    for (i = 0; i < taille - 1; i++)
    {
        for (j = 0; j < taille - i - 1; j++)
        {
            // Compare les titres de tâches et les échange si nécessaire
            if (strcmp(TabTache[j].titre, TabTache[j + 1].titre) > 0)
            {
                temp = TabTache[j];
                TabTache[j] = TabTache[j + 1];
                TabTache[j + 1] = temp;
            }
        }
    }
    */
}

void AfficherListe(tache TabTache[])
{
    int i;
    printf("Liste des taches :\n");
    for (i = 0; i < taille; i++)
    {
        printf("ID : %d\n", TabTache[i].id);
        printf("Titre : %s\n", TabTache[i].titre);
        printf("Description : %s\n", TabTache[i].description);
        printf("Deadline : %d/%d/%d\n", TabTache[i].deadline.jour, TabTache[i].deadline.mois, TabTache[i].deadline.annee);
        printf("Statut : %s\n", TabTache[i].statut);
        printf("\n");
    }
}

int main()
{
    tache TabTache[500];
    // AjoutTache(TabTache);
    AjoutPlusieurTaches(TabTache);
    AfficherListe(TabTache);
    TriTachesAlphabetique(TabTache);
    AfficherListe(TabTache);
    return 0;

}



































bool found = false;
            for (int i = 0; i < taille; i++) {
                if (tasks[i].id == id1) {
                    printf("Votre tache est trouvee:\n");
                    printf("ID:            | %d\n", taille[i].id);
                    printf("Title:         | %s\n", taille[i].title);
                    printf("Description:   | %s\n", taille[i].description);
                    printf("Deadline:      | %s\n", taille[i].deadline);
                    printf("Status:        | %s\n" , taille[i].status);
                    found = true;
                    break;
                }
            }

            if (!found) {
                printf("La tache de cet ID %d non trouvee.\n", id1);
            }
            break;
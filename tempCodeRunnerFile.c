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
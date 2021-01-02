#include <stdlib.h>
#include <stdio.h>



void echanger(float tableau[], int a, int b)
{
    float temp = tableau[a];
    tableau[a] = tableau[b];
    tableau[b] = temp;
}

void quickSort(float tableau[], int debut, int fin)
{
    int gauche = debut-1;
    int droite = fin+1;
    const float pivot = tableau[debut];

    /* Si le tableau est de longueur nulle, il n'y a rien à faire. */
    if(debut >= fin)
        return;

    /* Sinon, on parcourt le tableau, une fois de droite à gauche, et une
       autre de gauche à droite, à la recherche d'éléments mal placés,
       que l'on permute. Si les deux parcours se croisent, on arrête. */
    while(1)
    {
        do droite--; while(tableau[droite] > pivot);
        do gauche++; while(tableau[gauche] < pivot);

        if(gauche < droite)
            echanger(tableau, gauche, droite);
        else break;
    }

    /* Maintenant, tous les éléments inférieurs au pivot sont avant ceux
       supérieurs au pivot. On a donc deux groupes de cases à trier. On utilise
       pour cela... la méthode quickSort elle-même ! */
    quickSort(tableau, debut, droite);
    quickSort(tableau, droite+1, fin);
}

int main(void)
{
    float tab[5] = {0.05, -0.3, 4.5, -0.1115, 0.542};
    int i;

    quickSort(tab, 0, 4);
    
    for(i = 0; i < 5; i++)
    {
	printf("%f ", tab[i]);
    }
    putchar('\n');
    
    return 0;
}

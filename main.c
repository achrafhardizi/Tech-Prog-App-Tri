#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "methodeTri.h"
#define MAX 9999
#define WINDOW_SIZE 100

// Declaration des tableaus:
double tableComplexiteBulle[MAX];
double tableComplexiteInsertion[MAX];
double tableComplexiteSelection[MAX];
double tableComplexiteFusion[MAX];
double tableComplexiteRapide[MAX];
double tableComplexiteShaker[MAX];
double tableComplexiteGnome[MAX];
double tableComplexitePeigne[MAX];
double tableComplexiteShell[MAX];

// Declaration des fonctions

int *initTab(int *, int);
int *initTabDesc(int *, int);
int *initTabAsc(int *, int);
void copierTableau(int *, int *, int);
void moyennePonderee(const double *, double *, int, int);
void triAvecComplexite(int *, int);
void saveTimeCSV(int);
void tracerGraph(char[]);

int *initTab(int *T, int n)
{
    int i;
    T = (int *)malloc(sizeof(int) * n);
    srand(time(NULL));
    for (i = 0; i < n; i++)
    {
        T[i] = rand() % 256;
    }
    return T;
}

int *initTabDesc(int *T, int n)
{
    int i;
    T = (int *)malloc(sizeof(int) * n);

    for (i = 0; i < n; i++)
    {
        T[i] = n - i;
    }

    return T;
}

int *initTabAsc(int *T, int n)
{
    int i;
    T = (int *)malloc(sizeof(int) * n);

    for (i = 0; i < n; i++)
    {
        T[i] = 1 + i;
    }

    return T;
}

void copierTableau(int *source, int *destination, int n)
{
    for (int i = 0; i < n; i++)
    {
        destination[i] = source[i];
    }
}

void moyennePonderee(const double *data, double *smoothed_data, int num_points, int window_size)
{
    double sum;
    for (int i = 0; i < num_points; i++)
    {
        sum = 0.0;
        int count = 0;

        for (int j = i; j < i + (window_size / 2) && i + (window_size / 2) < num_points; j++)
        {
            sum += data[j];
            count++;
        }
        smoothed_data[i] = sum / count;
    }
}

void triAvecComplexite(int *tableauNonTrie, int n)
{
    clock_t start, end;

    int *original = (int *)malloc(sizeof(int) * n);

    copierTableau(tableauNonTrie, original, n);

    // Tri bulle
    start = clock();
    triBulle(tableauNonTrie, n);
    end = clock();
    tableComplexiteBulle[n] = ((double)(end - start));

    copierTableau(original, tableauNonTrie, n);

    // Tri par selection
    start = clock();
    triSelection(tableauNonTrie, n);
    end = clock();
    tableComplexiteSelection[n] = ((double)(end - start));

    copierTableau(original, tableauNonTrie, n);

    // Tri par insertion
    start = clock();
    triInsertion(tableauNonTrie, n);
    end = clock();
    tableComplexiteInsertion[n] = ((double)(end - start));

    copierTableau(original, tableauNonTrie, n);

    // Tri par fusion
    start = clock();
    triFusion(tableauNonTrie, n);
    end = clock();
    tableComplexiteFusion[n] = ((double)(end - start));

    copierTableau(original, tableauNonTrie, n);

    // Tri rapide
    start = clock();
    triRapide(tableauNonTrie, n);
    end = clock();
    tableComplexiteRapide[n] = ((double)(end - start));

    copierTableau(original, tableauNonTrie, n);

    // Tri Shaker
    start = clock();
    triShaker(tableauNonTrie, n);
    end = clock();
    tableComplexiteShaker[n] = ((double)(end - start));

    copierTableau(original, tableauNonTrie, n);

    // Tri Gnome
    start = clock();
    triGnome(tableauNonTrie, n);
    end = clock();
    tableComplexiteGnome[n] = ((double)(end - start));

    copierTableau(original, tableauNonTrie, n);

    // Tri Peigne
    start = clock();
    triPeigne(tableauNonTrie, n);
    end = clock();
    tableComplexitePeigne[n] = ((double)(end - start));

    copierTableau(original, tableauNonTrie, n);

    // Tri Shell
    start = clock();
    triShell(tableauNonTrie, n);
    end = clock();
    tableComplexiteShell[n] = ((double)(end - start));

    free(original);
}

void saveTimeCSV(int tailleMaximale)
{
    FILE *bulle = fopen("complexiteBulle.csv", "w");
    FILE *insertion = fopen("complexiteInsertion.csv", "w");
    FILE *selection = fopen("complexiteSelection.csv", "w");
    FILE *fusion = fopen("complexiteFusion.csv", "w");
    FILE *rapide = fopen("complexiteRapide.csv", "w");
    FILE *shaker = fopen("complexiteShaker.csv", "w");
    FILE *gnome = fopen("complexiteGnome.csv", "w");
    FILE *peigne = fopen("complexitePeigne.csv", "w");
    FILE *shell = fopen("complexiteShell.csv", "w");

    int i;

    double dataBulleLisse[tailleMaximale];
    double dataInsertionLisse[tailleMaximale];
    double dataSelectionLisse[tailleMaximale];
    double dataFusionLisse[tailleMaximale];
    double dataRapideLisse[tailleMaximale];
    double dataShakerLisse[tailleMaximale];
    double dataGnomeLisse[tailleMaximale];
    double dataPeigneLisse[tailleMaximale];
    double dataShellLisse[tailleMaximale];

    moyennePonderee(tableComplexiteBulle, dataBulleLisse, tailleMaximale, WINDOW_SIZE);
    moyennePonderee(tableComplexiteInsertion, dataInsertionLisse, tailleMaximale, WINDOW_SIZE);
    moyennePonderee(tableComplexiteSelection, dataSelectionLisse, tailleMaximale, WINDOW_SIZE);
    moyennePonderee(tableComplexiteFusion, dataFusionLisse, tailleMaximale, WINDOW_SIZE);
    moyennePonderee(tableComplexiteRapide, dataRapideLisse, tailleMaximale, WINDOW_SIZE);
    moyennePonderee(tableComplexiteShaker, dataShakerLisse, tailleMaximale, WINDOW_SIZE);
    moyennePonderee(tableComplexiteGnome, dataGnomeLisse, tailleMaximale, WINDOW_SIZE);
    moyennePonderee(tableComplexitePeigne, dataPeigneLisse, tailleMaximale, WINDOW_SIZE);
    moyennePonderee(tableComplexiteShell, dataShellLisse, tailleMaximale, WINDOW_SIZE);

    for (i = 0; i < tailleMaximale; i++)
    {
        fprintf(bulle, "%d,%.4f\n", i, dataBulleLisse[i]);
        fprintf(insertion, "%d,%.4f\n", i, dataInsertionLisse[i]);
        fprintf(selection, "%d,%.4f\n", i, dataSelectionLisse[i]);
        fprintf(fusion, "%d,%.4f\n", i, dataFusionLisse[i]);
        fprintf(rapide, "%d,%.4f\n", i, dataRapideLisse[i]);
        fprintf(shaker, "%d,%.4f\n", i, dataShakerLisse[i]);
        fprintf(gnome, "%d,%.4f\n", i, dataGnomeLisse[i]);
        fprintf(peigne, "%d,%.4f\n", i, dataPeigneLisse[i]);
        fprintf(shell, "%d,%.4f\n", i, dataShellLisse[i]);
    }

    fclose(bulle);
    fclose(insertion);
    fclose(selection);
    fclose(fusion);
    fclose(rapide);
    fclose(shaker);
    fclose(gnome);
    fclose(peigne);
    fclose(shell);
}

void tracerGraph(char courbeName[20])
{
    char cmd[100];
    char commande[30] = "gnuplot ";

    strcat(commande, courbeName);

    strcpy(cmd, commande);
    system(cmd);
}

int main()
{
    int tailleMax;
    do
    {
        printf("Veuillez saisir la taille max du tableau: (MAX 9999)");
        scanf("%d", &tailleMax);
    } while (tailleMax > MAX);

    int *T = NULL;
    int i;
    tableComplexiteBulle[0] = tableComplexiteInsertion[0] = tableComplexiteSelection[0] = tableComplexiteFusion[0] = tableComplexiteRapide[0] = 0;

    printf("Choisissez le type de tableau :\n");
    printf("1. Ascendant\n");
    printf("2. Descendant\n");
    printf("3. Aléatoire\n");
    int choice;
    printf("Entrez le numéro correspondant à votre choix : ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        for (i = 1; i <= tailleMax; i++)
        {
            T = initTabAsc(T, i);
            triAvecComplexite(T, i);
        }
        saveTimeCSV(tailleMax);
        tracerGraph("courbeAsc.plg");
        break;
    case 2:
        for (i = 1; i <= tailleMax; i++)
        {
            T = initTabDesc(T, i);
            triAvecComplexite(T, i);
        }
        saveTimeCSV(tailleMax);
        tracerGraph("courbeDesc.plg");
        break;
    case 3:
        for (i = 1; i <= tailleMax; i++)
        {
            T = initTab(T, i);
            triAvecComplexite(T, i);
        }
        saveTimeCSV(tailleMax);
        tracerGraph("courbeAleat.plg");
        break;
    default:
        printf("Choix invalide.\n");
        break;
    }

    return 0;
}

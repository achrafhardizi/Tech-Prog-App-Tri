#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "methodeTri.h"
#define MAX 10000

// Declaration des tableaus:
double bulleComplexity[MAX];
double insertionComplexity[MAX];
double selectionComplexity[MAX];
double fusionComplexity[MAX];
double rapideComplexity[MAX];

// Declaration des fonctions

int *initTab(int *, int);
void shuffleFisherYates(int *, int);
void triAvecComplexite(int *, int);
void saveTimeCSV(int);
void tracerGraph();

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

void copierTableau(int *source, int *destination, int n)
{
    for (int i = 0; i < n; i++)
    {
        destination[i] = source[i];
    }
}

void movingAverage(const double *data, double *smoothed_data, int num_points, int window_size)
{
    double sum;
    for (int i = 0; i < num_points; i++)
    {
        sum = 0.0;
        int count = 0;

        for (int j = i; j < i + window_size && i + window_size < num_points; j++)
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
    bulleComplexity[n] = ((double)(end - start));

    copierTableau(original, tableauNonTrie, n);

    // Tri par insertion
    start = clock();
    triInsertion(tableauNonTrie, n);
    end = clock();
    insertionComplexity[n] = ((double)(end - start));

    copierTableau(tableauNonTrie, original, n);

    // Tri par selection
    start = clock();
    triSelection(tableauNonTrie, n);
    end = clock();
    selectionComplexity[n] = ((double)(end - start));

    copierTableau(tableauNonTrie, original, n);

    // Tri par fusion
    start = clock();
    triFusion(tableauNonTrie, n);
    end = clock();
    fusionComplexity[n] = ((double)(end - start));

    copierTableau(tableauNonTrie, original, n);

    // Tri rapide
    start = clock();
    triRapide(tableauNonTrie, n);
    end = clock();
    rapideComplexity[n] = ((double)(end - start));

    free(original);
}

void tracerGraph()
{
    char cmd[100];
    strcpy(cmd, "gnuplot plot.plg");
    system(cmd);
}

int main()
{
    int tailleMax;
    do
    {
        printf("Veuillez saisir la taille max du tableau: (MAX 200000)");
        scanf("%d", &tailleMax);
    } while (tailleMax > 200000);

    int *T = NULL;
    int i;
    bulleComplexity[0] = insertionComplexity[0] = selectionComplexity[0] = fusionComplexity[0] = rapideComplexity[0] = 0;
    for (i = 1; i <= tailleMax; i++)
    {
        T = initTab(T, i);
        triAvecComplexite(T, i);
    }
    saveTimeCSV(tailleMax);
    tracerGraph();
    return 0;
}

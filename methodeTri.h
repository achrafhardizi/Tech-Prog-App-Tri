
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// les fonctions :
void triBulle(int T[], int n);
void triSelection(int T[], int n);
void triInsertion(int T[], int n);
void triRapide(int T[], int n);
void triFusion(int T[], int n);
void triShaker(int T[], int n);
void triGnome(int T[], int n);
void triPeigne(int T[], int n);
void triShell(int T[], int n);

// Les implémentations
void triBulle(int T[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (T[j] > T[j + 1])
            {

                int temp = T[j];
                T[j] = T[j + 1];
                T[j + 1] = temp;
            }
        }
    }
}

void triSelection(int T[], int n)
{
    int i, min, j, temp;

    for (i = 0; i < n - 1; i++)
    {
        min = i;
        for (j = i; j < n; j++)
            if (T[j] < T[min])
                min = j;
        temp = T[i];
        T[i] = T[min];
        T[min] = temp;
    }
}

void triInsertion(int T[], int n)
{

    int i, j, key;
    for (i = 1; i < n; i++)
    {
        key = T[i];
        j = i - 1;
        while (j >= 0 && T[j] > key)
        {
            T[j + 1] = T[j];
            j = j - 1;
        }
        T[j + 1] = key;
    }
}

void triRapide(int T[], int n)
{
    int mur, courant, pivot, tmp;
    if (n < 2)
        return;

    pivot = T[n - 1];
    mur = courant = 0;
    while (courant < n)
    {
        if (T[courant] <= pivot)
        {
            if (mur != courant)
            {
                tmp = T[courant];
                T[courant] = T[mur];
                T[mur] = tmp;
            }
            mur++;
        }
        courant++;
    }
    triRapide(T, mur - 1);
    triRapide(T + mur, n - mur);
}

void fusion(int *a, int n, int m)
{
    int i, j, k;
    int *x = (int *)malloc(sizeof(int) * n);
    for (i = 0, j = m, k = 0; k < n; k++)
    {
        x[k] = j == n        ? a[i++]
               : i == m      ? a[j++]
               : a[j] < a[i] ? a[j++]
                             : a[i++];
    }
    for (i = 0; i < n; i++)
    {
        a[i] = x[i];
    }
    free(x);
}

void triFusion(int T[], int n)
{
    if (n < 2)
        return;
    int milieu = n / 2;
    triFusion(T, milieu);
    triFusion(T + milieu, n - milieu);
    fusion(T, n, milieu);
}

void triShaker(int T[], int n)
{
    int i, j, sens = 1;
    int debut = 0, fin = n - 1;
    int permutation;
    do
    {
        permutation = 0;
        if (sens == 1)
        {
            for (i = debut; i < fin; i++)
            {
                if (T[i] > T[i + 1])
                {
                    int temp = T[i];
                    T[i] = T[i + 1];
                    T[i + 1] = temp;
                    permutation = 1;
                }
            }
            fin--;
        }
        else
        {
            for (j = fin; j > debut; j--)
            {
                if (T[j] < T[j - 1])
                {
                    int temp = T[j];
                    T[j] = T[j - 1];
                    T[j - 1] = temp;
                    permutation = 1;
                }
            }
            debut++;
        }
        sens = 1 - sens;
    } while (permutation);
}

void triGnome(int T[], int n)
{
    int i, j;
    for (i = 1; i < n;)
    {
        if (T[i] >= T[i - 1])
        {
            i++;
        }
        else
        {
            int temp = T[i];
            T[i] = T[i - 1];
            T[i - 1] = temp;
            if (i > 1)
            {
                i--;
            }
        }
    }
}

void triPeigne(int T[], int n)
{
    int gap = n;
    bool permutation = true;

    while (permutation || gap > 1)
    {
        gap = (gap * 10) / 13; // Réduction de l'écart
        if (gap < 1)
            gap = 1;
        permutation = false;

        for (int en_cours = 0; en_cours < n - gap; en_cours++)
        {
            if (T[en_cours] > T[en_cours + gap])
            {
                int temp = T[en_cours];
                T[en_cours] = T[en_cours + gap];
                T[en_cours + gap] = temp;
                permutation = true;
            }
        }
    }
}

void triParInsertion(int t[], int gap, int debut, int taille)
{
    int j, en_cours;
    for (int i = gap + debut; i < taille; i += gap)
    {
        en_cours = t[i];
        for (j = i; j >= gap && t[j - gap] > en_cours; j -= gap)
        {
            t[j] = t[j - gap];
        }
        t[j] = en_cours;
    }
}

void triShell(int T[], int n)
{
    int gap = n / 2;
    while (gap > 0)
    {
        for (int i = 0; i < gap; i++)
        {
            triParInsertion(T, gap, i, n);
        }
        gap /= 2;
    }
}
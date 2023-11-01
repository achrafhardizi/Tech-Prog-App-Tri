```
void triAvecComplexite(int *T, int n)
{
    clock_t start, end;
    int temp2[n];
    double smoothedBulle = 0;
    double smoothedInsertion = 0;
    double smoothedSelection = 0;
    double smoothedFusion = 0;
    double smoothedRapide = 0;

    for (int i = 1; i <= n; i++)
    {
        T = initTab(T, i);

        // Perform sorting and measure time
        // ...

        // Calculate execution times and apply moving average
        // Bulle
        start = clock();
        triBulle(T, i);
        end = clock();
        bulleComplexity[i] = ((double)(end - start));
        smoothedBulle += bulleComplexity[i];
        shuffleFisherYates(T, i);

        // Insertion
        start = clock();
        triInsertion(T, i);
        end = clock();
        insertionComplexity[i] = ((double)(end - start));
        smoothedInsertion += insertionComplexity[i];
        shuffleFisherYates(T, i);

        // Selection
        start = clock();
        triSelection(T, i);
        end = clock();
        selectionComplexity[i] = ((double)(end - start));
        smoothedSelection += selectionComplexity[i];
        shuffleFisherYates(T, i);

        // Fusion
        start = clock();
        triFusion(T,0, i - 1);
        end = clock();
        fusionComplexity[i] = ((double)(end - start));
        smoothedFusion += fusionComplexity[i];
        shuffleFisherYates(T, i);

        // Rapide
        start = clock();
        triRapide(T, 0, i - 1);
        end = clock();
        rapideComplexity[i] = ((double)(end - start));
        smoothedRapide += rapideComplexity[i];

        // Apply moving average to the smoothed data
        if (i >= MOVING_AVERAGE_WINDOW)
        {
            bulleComplexity[i] = smoothedBulle / MOVING_AVERAGE_WINDOW;
            insertionComplexity[i] = smoothedInsertion / MOVING_AVERAGE_WINDOW;
            selectionComplexity[i] = smoothedSelection / MOVING_AVERAGE_WINDOW;
            fusionComplexity[i] = smoothedFusion / MOVING_AVERAGE_WINDOW;
            rapideComplexity[i] = smoothedRapide / MOVING_AVERAGE_WINDOW;
            smoothedBulle -= bulleComplexity[i - MOVING_AVERAGE_WINDOW];
            smoothedInsertion -= insertionComplexity[i - MOVING_AVERAGE_WINDOW];
            smoothedSelection -= selectionComplexity[i - MOVING_AVERAGE_WINDOW];
            smoothedFusion -= fusionComplexity[i - MOVING_AVERAGE_WINDOW];
            smoothedRapide -= rapideComplexity[i - MOVING_AVERAGE_WINDOW];
        }
    }
}
```
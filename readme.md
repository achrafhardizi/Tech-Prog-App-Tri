# Analyse des Algorithmes de Tri en C

Ce projet implémente divers algorithmes de tri en C et analyse leur complexité temporelle pour comparer leurs performances.

## Structure des Fichiers

- `main.c` : Le programme principal qui génère des données, effectue des tris et analyse la complexité.
- `methodeTri.h` : Fichier d'en-tête contenant les implémentations des algorithmes de tri.
- `courbeAleat.plg` : Script Gnuplot pour générer des graphiques basés sur les données __Aleatoire__.
- `courbeAsc.plg` : Script Gnuplot pour générer des graphiques basés sur les données __Triage Ascendant__.
- `courbeDesc.plg` : Script Gnuplot pour générer des graphiques basés sur les données __Triage Descendant__.

## Compilation et Exécution

1. Assurez-vous d'avoir `gcc` et `gnuplot` installés sur votre système.
2. Compilez le programme en exécutant :

   ```bash
   gcc -o sorting main.c

3. Exécutez le programme :
    ```bash
    ./sorting

4. Le programme générera des données et tracera des graphiques à l'aide de gnuplot en des Images `.png`.
    - CourbeComplexiteAlgosTrie.png
    - CourbeComplexiteAlgosTrieAsc.png
    - CourbeComplexiteAlgosTrieDesc.png

### Algorithmes de Tri

- Tri à Bulles
- Tri par Sélection
- Tri par Insertion
- Tri Rapide
- Tri Fusion
- Tri Shaker
- Tri Gnome
- Tri Peigne
- Tri Shell

### Analyse des Données

Le programme génère des données aléatoires et applique divers algorithmes de tri pour mesurer leur temps d'exécution. La complexité temporelle est enregistrée et ultérieurement tracée pour analyser et comparer les performances des algorithmes.

### Tracé des Graphiques
Les graphiques sont générés à l'aide des scripts Gnuplot. Les scripts lit les données à partir de fichiers CSV et trace des graphiques de complexité temporelle pour différents algorithmes de tri.

### Résultats

![Courbe qui Represente la complexite des differents Algorithmes de Trie d'un tableau Aleatoire](CourbeComplexiteAlgosTrie.png)\
___Figure 1: Courbe qui Represente la complexite des differents Algorithmes de Trie d'un tableau Aleatoire___

![Courbe qui Represente la complexite des differents Algorithmes de Trie d'un tableau Asc](CourbeComplexiteAlgosTrieAsc.png)\
___Figure 2: Courbe qui Represente la complexite des differents Algorithmes de Trie d'un tableau Asc___

![Courbe qui Represente la complexite des differents Algorithmes de Trie](CourbeComplexiteAlgosTrieDesc.png)\
___Figure 3: Courbe qui Represente la complexite des differents Algorithmes de Trie d'un tableau Desc___

### Références
Gnuplot : https://gnuplot.sourceforge.io/

### Auteur

Achraf HARDIZI
[<span style="background-color:#0366d6; color:#ffffff; padding:8px 16px; border-radius:6px; text-decoration:none;">@R0gueCs</span>](https://github.com/R0gueCS)\
\
Zakaria OUAKRIM
[<span style="background-color:#0366d6; color:#ffffff; padding:8px 16px; border-radius:6px; text-decoration:none;">@ZakariaOuakrim</span>](https://github.com/ZakariaOuakrim)\
\
Darius KONSEBO
[<span style="background-color:#0366d6; color:#ffffff; padding:8px 16px; border-radius:6px; text-decoration:none;">@dariuskonsebo</span>](https://github.com/dariuskonsebo)

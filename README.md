# Projet Tetris

Ce projet consiste à créer une version informatique du célèbre jeu **Tetris**, conçu par Alekseï Pajitnov en 1984. L'objectif est de développer un programme dans lequel un ordinateur joue de manière optimale au jeu, en utilisant des stratégies d'optimisation pour positionner les pièces.

## Auteurs

- **Antonin Monneret**
- **Alois Thomasson**
- **Nicolas Rabreau**

## Description du Projet

Le programme simule un joueur de Tetris. Le jeu se déroule sur un plateau de 22 lignes par 10 colonnes, où des pièces de différentes formes tombent et doivent être placées de manière à former des lignes complètes. Chaque ligne complétée est supprimée pour libérer de l'espace. L'objectif est de maximiser le score en optimisant le placement des pièces grâce à des algorithmes prédéfinis.

### Fonctionnalités principales

- **Mécanique du Jeu** : Le programme génère et place des pièces de Tetris de manière automatique.
- **Évaluation des coups** : Utilisation des coefficients de Dellacherie pour évaluer et choisir le meilleur coup possible.
- **Interface graphique** : Le jeu dispose d'une interface utilisateur interactive permettant de visualiser le plateau de jeu, de suivre le score et d'ajuster certains paramètres.
- **Cycle infini** : Le programme fonctionne en boucle, le plateau étant mis à jour à chaque cycle.

### Organisation du Code

Le projet est structuré en plusieurs fichiers `.cpp` et `.h` afin de modulariser le code :

- **main.cpp / main.h** : Contient la fonction principale du programme qui lance le cycle de jeu.
- **callback.cpp / callback.h** : Gère le cycle du jeu, appelant les différentes fonctions pour mettre à jour le plateau.
- **fonctions.cpp / fonction.h** : Implémente les fonctions de création des pièces, évaluation des coups, et choix du meilleur coup.
- **dessin.cpp / dessin.h** : S'occupe du dessin du plateau de jeu et des pièces.
- **interface.cpp / interface.h** : Gère l'interface utilisateur.

### Algorithme d'évaluation des coups

Le programme utilise les **coefficients de Dellacherie**, une méthode d'évaluation basée sur plusieurs critères :

- Hauteur d'arrivée de la pièce
- Nombre de lignes complétées
- Réduction des trous dans le plateau
- Homogénéité du mur
- Nombre de puits formés

Ces critères permettent de déterminer le meilleur coup pour chaque pièce.

### Interface Graphique

L'interface utilisateur permet d'interagir avec le programme :

- Ajustement des coefficients de Dellacherie
- Suivi du score
- Contrôle de la pause et du redémarrage
- Affichage des niveaux et du plateau de jeu mis à jour en temps réel

## Installation

1. Clonez le dépôt :
   ```bash
   git clone https://github.com/votre-utilisateur/projet-tetris.git
   
2. Compilez le projet (nécessite un compilateur C++) :

   ```bash
   make

3. Lancez le programme :

   ```bash
    ./projet-tetris

## Utilisation

Le programme commence automatiquement en mode de jeu.
Vous pouvez ajuster les paramètres via l'interface utilisateur.

## Problèmes connus

Limitation du score : Le programme ne parvient pas à dépasser un score de 2000 points, probablement en raison d'un bug dans la recherche de maximum pour les coups possibles.
Optimisation : Bien que le jeu fonctionne, certaines optimisations sont encore nécessaires pour améliorer la performance et l'efficacité du placement des pièces.

## Améliorations futures

Résolution des problèmes de score et d'évaluation des coups.
Ajout d'un mode joueur où l'utilisateur pourrait jouer directement contre l'ordinateur.
Amélioration de l'algorithme de placement des pièces pour surpasser les performances humaines.

## Licence

Ce projet est sous licence MIT. Consultez le fichier LICENSE pour plus de détails.

### Comment intégrer à votre dépôt GitHub

1. Copiez ce texte dans un fichier nommé `README.md`.
2. Placez ce fichier à la racine de votre dépôt local.
3. Ajoutez, validez et poussez les changements vers GitHub :
   ```bash
   git add README.md
   git commit -m "Ajout du fichier README"
   git push origin main

# Morpion (Tic-Tac-Toe) en C

Un jeu de morpion (Tic-Tac-Toe) développé en langage C, avec plusieurs modes de jeu :
- **Joueur contre Joueur**
- **Joueur contre Bot**
- **Bot contre Bot**

## Description

Ce programme permet de jouer au morpion dans un terminal. Le jeu utilise les flèches directionnelles pour choisir une case et le bouton "Entrée" pour effectuer un choix. Il supporte trois modes de jeu :

1. **Joueur contre Joueur** : Deux joueurs se relaient pour jouer.
2. **Joueur contre Bot** : Un joueur joue contre l'IA (le bot).
3. **Bot contre Bot** : Deux bots jouent automatiquement entre eux.

Le jeu affiche le plateau de jeu dans le terminal et détecte lorsqu'un joueur gagne ou si la partie est un match nul.

## Fonctionnalités

- Choix du mode de jeu via les flèches directionnelles.
- Affichage du plateau de jeu avec des cases sélectionnables via les flèches.
- Support de l'IA basique pour le mode **Joueur contre Bot**.
- Détection de victoire ou de match nul.
- Jeu en mode texte dans le terminal.

## Prérequis

- Un compilateur C (`gcc` ou équivalent).
- Un terminal ou un IDE avec support de la ligne de commande.

### Installation

1. Clonez ce dépôt sur votre machine :

   ```bash
   git clone https://github.com/<votre-nom-utilisateur>/morpion-c.git
   ```

2. Naviguez dans le répertoire du projet :


 ```bash
cd morpion-c
```
3. Compilez le programme :

 ```bash
gcc -o morpion morpion.c
 ```
Exécutez le jeu :

- Sur **Linux/macOS** :

```bash
./morpion
```
- Sur **Windows** :

```bash
morpion.exe
```
## Commandes
- Utilisez les flèches directionnelles pour déplacer le curseur sur le plateau.

- Appuyez sur Entrée pour placer votre symbole (X ou O) sur la case sélectionnée.

- Choisissez un mode de jeu et commencez à jouer en appuyant sur Entrée après la sélection.

## Exemple de jeu

Use arrows to choose mode, Enter to confirm:
1. Player vs Player
2. Player vs Bot
3. Bot vs Bot

Selected mode: 1

Player X's turn:
[ X ] [   ] [   ]
[   ] [ O ] [   ]
[   ] [   ] [   ]

## Contribution
1. Fork ce dépôt.

2. Créez une nouvelle branche (git checkout -b feature-xyz).

3. Effectuez vos modifications et committez-les (git commit -am 'Ajout de nouvelles fonctionnalités').

4. Poussez sur votre branche (git push origin feature-xyz).

5. Créez une pull request.

## Auteurs
Emrane smaki

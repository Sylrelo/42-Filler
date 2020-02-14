# [42] Filler
**Filler** est un jeu algorithmique qui consiste à remplir une grille d’une taille connue à l’avance avec des pièces de taille et de formes aléatoires, sans que les pièces ne se superposent de plus d’une seule case et sans qu’elles ne depassent de la grille.

Si l’une deces conditions n’est pas remplie, la partie s’arrête.

[Le sujet, au format PDF, est disponible ici.](https://github.com/Sylrelo/42-Filler/blob/master/git_ressources/sujet.fr.pdf)

**L'algorithme choisi est une map de chaleur.**

## Contraintes du projet

**Fonction de la libc autorisée :**
>- write
>- malloc
>- free
>- read
>- perror
>- strerror

**Librairies autorisée** :
>- Libft

## Installation
````bash
git clone https://github.com/Sylrelo/42-Filler.git
make
make -C ./visualizer/
````
### Utilisation

````bash
./ressources/filler_vm -f [map] -p1 [joueur_1] -p1 [joueur_2]
````
**Exemple**
````bash
./ressources/filler_vm -f ressources/maps/map01 -p2 ./ressources/players/carli.filler -p1 ./slopez.filler
````
Pour lancer avec le visualisateur bonus :
````bash
./ressources/filler_vm -f ressources/maps/map01 -p2 ./ressources/players/carli.filler -p1 ./slopez.filler | ./visualizer/filler-gui
````
## Aperçu du visualiateur bonus

![screenshot](https://raw.githubusercontent.com/Sylrelo/42-Filler/master/git_ressources/example.gif)

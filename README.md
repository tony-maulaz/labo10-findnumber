# labo 10 - Number

- **Durée**: 4 périodes + travail à la maison

## Objectifs

Les principaux buts de ce travail de laboratoire sont :

- Utiliser le générateur de nombres aléatoires.
- Apprendre à programmer un problème ludique et un peu plus complexe.
- Étudier et coder l’algorithme de la dichotomie sur un exemple concret.

## Ecriture du programme et aide de l’IA
- Vous pouvez discuter du problème entre vous, mais le code doit être écrit individuellement.
- Vous devez remettre un code propre, bien commenté et correctement formaté.
- Vous pouvez vous aider de l’IA, mais le code doit être écrit par vous-même et vous devez comprendre chaque ligne.
- En cas de doute concernant le plagiat ou l’utilisation de l’IA pour l’écriture du code, une entrevue orale pourra être demandée afin de vérifier votre compréhension du code remis. Si l'entrevue révèle un manque de compréhension, cela sera considéré comme de la tricherie.

## Cahier des charges

On vous demande de concevoir puis d’écrire un programme qui permet de jouer au jeu du "juste prix"
de deux manières :

- L’utilisateur doit deviner un nombre entre `0` et `1000`.
- L’ordinateur doit deviner un nombre entre `0` et `1000`.
- Afficher une version du programme.
- Afficher une aide sur le fonctionnement du programme.
- Afficher le nombre à trouver lorsqu’une option de triche est demandée.

`0` et `1000` sont des valeurs possibles.

La valeur max doit être définie par un `#define`.

Le choix de l’opération doit être effectué par l'intermédiaire d'arguments en ligne de commande.

Si aucune option n'est fournie, le programme affiche une aide (voir `print_help`).

Les options sont les suivantes :
- `-n<nombre>` : Permet de fixer le nombre que l'ordinateur fait deviner.
- `-h` ou `--help` : Affiche l'aide du programme.
- `-v` ou `--version` : Affiche la version du programme.
- `-t` ou `--test` : Permet de tester le générateur de nombre aléatoire en affichant 10 nombres générés.
- `-o1` : Permet de jouer au jeu où l'utilisateur doit deviner le nombre.
- `-o2` : Permet de jouer au jeu où l'ordinateur doit deviner le nombre.
- `--cheat` : Affiche le nombre à deviner au début du jeu.

Si une option invalide est entrée ou une combinaison d'options impossible, il faut retourner un code d'erreur `4`.

### Exemples d'utilisation des options

```console
$ ./number -h
$ ./number --version
$ ./number -t
$ ./number -o1
$ ./number -o1 -n500 --cheat
$ ./number -o2
$ ./number -v -o1 -h --cheat
```

## Descriptif

### Jeu 1
- L'ordinateur choisit un nombre entier entre 0 et la valeur max définie (bornes incluses).
- L'utilisateur est invité à saisir un nombre entre les bornes définies.
- L'ordinateur indique si le nombre est trop grand, trop petit ou juste.
- Le système compte le nombre d’essais.
- Une fois le nombre trouvé, le programme affiche le nombre d'essais.
- Le jeu s'arrête.

### Jeu 2
- L'ordinateur doit deviner un nombre, il va le faire par dichotomie. C'est-à-dire qu'il va à chaque fois diviser
  l'intervalle par 2.
- L'utilisateur est invité à saisir `+`, `-`, `=`, `q`.
- Le système compte le nombre d’essais.
- Une fois le nombre trouvé, le programme affiche le nombre d'essais.
- Le jeu s'arrête.

## Nombre aléatoire

Pour générer un nombre aléatoire, nous allons utiliser le générateur de la bibliothèque `C`.

Pour utiliser le générateur, vous devez inclure :

```c
#include <stdlib.h>
#include <time.h>
```

Une seule fois au début du programme, il faut initialiser le générateur :

```c
srand( (unsigned int)time(NULL) );
```

Ensuite pour obtenir un nombre il faut faire :

```c
i = rand (); // nombre aléatoire entre 0 et RAND_MAX
```

## Qualité du code

La qualité du code est évaluée. Pour mémoire :
- Les variables sont nommées de façon **appropriée**.
- La **visibilité** (*scope*) des variables est minimale.
- Les **constantes littérales** sont nommées pour une meilleure compréhension.
- Les **types** de données doivent être appropriés au contenu ciblé.
- Le programme doit être **robuste**, les cas d'exception doivent être traités.
- Le nom des fonctions **doit** être explicite et non trop générique.
- Les fonctions **doivent** avoir un commentaire explicatif.
- Une fonction ne doit pas dépasser `50` lignes de code.
- Attention à la longueur des lignes.

## Exemples

```console
$ ./number -o1 -n500 --cheat
Bonjour
J'ai choisi un nombre entre 0 et 1000 (500)
Quel nombre avez-vous choisi ? > 400
Vous avez choisi un nombre trop petit.
Quel nombre avez-vous choisi ? > a
Vous devez saisir un nombre entre 0 et 1000.
Quel nombre avez-vous choisi ? > 600
Vous avez choisi un nombre trop grand.
Quel nombre avez-vous choisi ? > 500

Vous avez gagné en 3 coups, le nombre est : 500
```

```console
$ ./number -o2
Bonjour
Veuillez choisir un nombre entre 0 et 1000

Indiquez où je me situe avec un des opérateurs suivants :
        + : le nombre est trop grand
        - : le nombre est trop petit
        = : le nombre est juste
        q : abandonner

J'ai choisi le nombre : 500
Votre indication ? > -
J'ai choisi le nombre : 750
Votre indication ? > +
J'ai choisi le nombre : 625
Votre indication ? > +
J'ai choisi le nombre : 562
Votre indication ? > +
J'ai choisi le nombre : 531
Votre indication ? > =

Vous avez gagné en 5 coups, le nombre est : 531
```

```console
$ ./number -o2
Bonjour
Veuillez choisir un nombre entre 0 et 1000

Indiquez où je me situe avec un des opérateurs suivants :
        + : le nombre est trop grand
        - : le nombre est trop petit
        = : le nombre est juste
        q : abandonner

J'ai choisi le nombre : 500
Votre indication ? > q

Vous avez abandonné au 1er coup, dommage.
```

```console
$ ./number -t
742 15 999 318 406 77 520 1000 3 654
```

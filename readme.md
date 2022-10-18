# TP3 - DICHOTOMIE – METHODE DES TRAPEZES – DECOMPOSITION EN SERIE

Le but de ce TP est d'aborder les sous-programmes à travers trois méthodes de calcul numérique usuelles. On retrouve ici les structures de contrôle vues précédemment : l'alternative et les boucles. À ces structures, on ajoute les notions de procédure et de fonction. Le TP comprend trois parties :

- La recherche d'un zéro d'une fonction dans un intervalle donné en appliquant le principe de recherche par dichotomie

- Le calcul de l'intégrale d'une fonction dans un intervalle donné à l'aide de la méthode des trapèzes

- Le calcul de sin(x) à partir de la décomposition en série de Taylor et d'une précision donnée

---

## 1.2 Bibliothèques Standard & fonctions mathématiques
Les trois exercices suivants font appel aux fonctions mathématiques fournies par les bibliothèques standard des langages C et C++. Dans le contexte de ce TP, on utilise les macros et déclarations définies par le standard POSIX IEEE Std 1003.1 : [lien](http://www.unix.com/man- page/posix/7posix/math.h/)

En C++ le catalogue des macros et déclarations est inclus au début du code source avec la directive : `#include <cmath>`

1. Comment le nombre 𝜋 est-il défini dans la bibliothèque standard ?
> le nombre 𝜋 est défini dans la bibliothèque standard comme la constante `M_PI`

2. Quels sont les types utilisés avec la définition de la fonction sinus ?
> la fonction sinus est définie avec le type `double`

3. Quels sont les types utilisés avec la fonction qui renvoie la valeur absolue d'un nombre réel ?
> la fonction qui renvoie la valeur absolue d'un nombre réel est définie avec le type `double`

4. Comment appelle-t-on la fonction qui permet de calculer les puissances sous la forme y^x ?
> la fonction qui permet de calculer les puissances sous la forme y^x est définie comme `pow(y,x)`

## 1.3 Recherche d'un zéro d'une fonction par dichotomie

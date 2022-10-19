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

1. Ecrire l'algorithme d'un sous programme SinusCardinal qui effectue le calcul de la fonction f(x) = 3. sin(x)/x, avec f(0) = 3. Choisir le type de la valeur donnée en entrée et le type de la valeur renvoyée par la fonction.

    ```cpp
    // Cette fonction calcule la valeur de la fonction f(x) = 3. sin(x)/x 
    void SinusCardinal(double x, double &f) {
    if (x == 0) {
        f = 3;
    } else {
        f = 3 * sin(x) / x;
    }
    ```

2. Ecrire l'algorithme du sous-programme dichotomie qui reçoit en paramètres : les bornes de l'intervalle de recherche initial ainsi que la précision recherchée et renvoie la valeur du zéro de la fonction ainsi que le nombre d'itérations nécessaires pour trouver la solution.

    ```cpp
    // Cette fonction calcule la valeur du zéro de la fonction f(x) = 3. sin(x)/x
    // dans l'intervalle [a,b] avec une précision donnée
    void dichotomie(double a, double b, double precision, double &zero, int &nbIterations) {
        double fA, fB, fM, m;

        SinusCardinal(a, fA);
        SinusCardinal(b, fB);

        nbIterations = 0;

        while (b - a > precision) {
            m = (a + b) / 2;

            SinusCardinal(m, fM);
            
            if (fM * fA < 0) {
                b = m;
                fB = fM;
            } else {
                a = m;
                fA = fM;
            }
            nbIterations++;
        }
        zero = (a + b) / 2;
    }
    ```

4. Préparer un jeu de test complet de calcul d'un zéro de la fonction f(x) en utilisant des bornes d'intervalle différentes de celles de la copie d'écran GeoGebra donnée en TP3

| Bornes            |  \|a-b\| < epsilon | itération  | Valeur de x|
| :---------------: |:------------------:| :---------:| :--------: |
| a = -1.5; b = 1.5 |   faux             |        5   |  1.45312   |


## 1.4 Calcul de l'intégrale d'une fonction par la méthode des trapèzes

Objectif : Calculer l'intégrale de la fonction f(x) = sin(x) + 1 sur un intervalle défini [a,b] à l'aide de la méthode des trapèzes. Cette méthode consiste à découper l'intervalle choisi en n trapèzes de même largeur dont on sait calculer l'aire.

La somme des aires des trapèzes est une approximation de l'intégrale de la fonction sur l'intervalle [a,b]. Plus le nombre de trapèzes est important, meilleure est l'approximation.

L'expression de la largeur l d'un trapèze est l = (b-a)/n ou a et b sont les bornes de l'intervalle choisi pour le calcul et n le bomvre de trapèzes dont on doit calculer l'aire.

L'expression de l'aide du trapèze ABCD dans la copie d'écran du document du TP3 est : AD.(AB+BC)/2 = l.(f(a)+f(b))/2

En se basant sur les bornes de l'intervalle [a,b], l'expression de l'aire de chaque trapèze est de la forme:

* aire du trapèze n°1 = l.(f(a)+f(a+l))/2
* aire du trapèze n°2 = l.(f(a+l)+f(a+2.l))/2
* aire du n-1ème trapèze = l.(f(a+(n-2).l)+f(a+(n-1).l))/2
* aire du nème trapèze = l.(f(a+(n-1).l)+f(b))/2

1. Donner la primitive de la fonction f(x) = sin(x) + 1 sur l'intervalle [a, b] sin(x) + 1 
> la primitive de la fonction f(x) = sin(x) + 1 sur l'intervalle [a, b] est : -cos(x) + x + C

2. Choisir un jeu de bornes a et b en radians et calculer le résultat théorique à approcher par la méthode des trapèzes.
> on choisit les bornes a = 0 et b = 𝜋/2

3. Préparer un jeu de test à partir d'un découpage en 5 trapèzes entre les bornes a et b.

4. Ecrire l'algorithme du sous-programme SinusPlusUn qui effecute le calcul de la fonction f(x) défini ci-avant. Choisir le type de la valeur donnée en entrée et le type de la valeur renvoyée par la fonction.

    ```cpp
    // Cette fonction calcule la valeur de la fonction f(x) = sin(x) + 1
    void SinusPlusUn(double x, double &f) {
        f = sin(x) + 1;
    }
    ```

5. Ecrire l'algorithme du sous-programme trapeze qui reçoit en paramètres les bornes de l'intervalle de calcul ainsi que le nombre de trapèzes. Ce sous-programme renvoie le résultat du calcul par la méthode des trapèzes.
    
    ```cpp
    // Cette fonction calcule l'intégrale de la fonction f(x) = sin(x) + 1
    // dans l'intervalle [a,b] avec un nombre de trapèzes donné
    void trapeze(double a, double b, int n, double &resultat) {
        double l, fA, fB, fM, m;

        SinusPlusUn(a, fA);
        SinusPlusUn(b, fB);

        l = (b - a) / n;

        resultat = 0;

        for (int i = 1; i < n; i++) {
            m = a + i * l;
            SinusPlusUn(m, fM);
            resultat += l * (fA + fM) / 2;
            fA = fM;
        }

        resultat += l * (fA + fB) / 2;
    }
    ```

6. Ecrire l'algorithme du programme principal qui demande à l'utilisateur de fournir les bornes de l'intervalle de calcul de l'intégrale a et b ainsi que le nombre de trapèzes. Ce programme principal appelle la fonction trapeze et affiche le résultat du calcul intégral par la méthode des trapèzes.

Le programme principal doit aussi afficher le résultat du calcul intégram "théorique" obtenu avec la primitive de la fonction f(x) ainsi que l'erreur relative entre les deux méthodes de calcul.

## 1.5 Calcul de sin(x) à l'aide d'une série de Taylor

Objectif : Le but de cet exercice est de déterminer le nombre de termes de la série de Taylor à calculer pour une valeur de sin(x) avec une précision donnée. Une fois la précision souhaitée atteinte, on détermine l'erreur relative à l'aide du calcul direct de sin(x).

On utilise une valeur caractéristique de x pour faciliter la mise au point du programme : x = pi/6.

2. Reprendre l'algorithme de la fonction puisssance étudiée en TD et le modifierp our prendre en compte le type de la valeur donnée en entrée et le type de la valeur renvoyée par la fonction.

    ```cpp
    // Cette fonction calcule la puissance d'un nombre
    void puissance(double x, int n, double &resultat) {
        resultat = 1;
        for (int i = 1; i <= n; i++) {
            resultat *= x;
        }
    }
    ```

3. Reprendre l'algorithme de la fonction factorielle étudiée en préambule du TP N°1 et le modifier afin de prendre en compte le type de la valeur donnée en entréee et le type de la valeur renvoyée par la fonction.

    ```cpp
    // Cette fonction calcule la factorielle d'un nombre
    void factorielle(int n, double &resultat) {
        resultat = 1;
        for (int i = 1; i <= n; i++) {
            resultat *= i;
        }
    }
    ```

4. Ecrire l'algortihme du sous-programme sinusTaylor qui recoit en paramètre la valeur de x et la précision epsilon souhaitée. Ce sous-programme calcule les termes de la série de Taylor les uns après les autres. Le calcul s'arrête dès que le terme calculé est inférieur à la précision souhaitée. La valeur approchée du sinus est alors renvoyée au programme appelant ainsi que le nombre de termes calculés pour atteidnre la précision souhaitée.

    ```cpp
    // Cette fonction calcule la valeur approchée de sin(x) avec une précision epsilon
    void sinusTaylor(double x, double epsilon, double &resultat, int &nbTermes) {
        double terme, signe;
        int n;

        resultat = 0;
        n = 0;
        signe = 1;

        do {
            puissance(x, 2 * n + 1, terme);
            factorielle(2 * n + 1, terme);
            terme *= signe;
            resultat += terme;
            signe *= -1;
            n++;
        } while (terme > epsilon);

        nbTermes = n;
    }
    ```

5. Ecrire l'agorithme du programme principal qui demande à l'utilisateur de fournir la valeur de x et la précision souhaitée pour la valeur approchée de sin(x). Ce programme principal appelle le sous-programme sinusTaylor et affiche le résultat du calcul.

Le programme principal doit aussi afficher le résultat du calcul direct de sin(x) ainsi que l'erreur relative entre les deux méthodes de calcul.
/**
 * @author Benjamin Peronne
 * @email contact@benjaminperonne.fr
 * @create date 2022-10-18 10:20:13
 * @modify date 2022-10-18 10:20:13
 * @desc [TP3 - Ex1.5]
 */
// TP3 - DICHOTOMIE – METHODE DES TRAPEZES – DECOMPOSITION EN SERIE

/*
Objectif : Le but de cet exercice est de déterminer le nombre de termes de la série de Taylor à calculer pour une valeur de sin(x) avec une précision donnée. Une fois la précision souhaitée atteinte, on détermine l'erreur relative à l'aide du calcul direct de sin(x).

On utilise une valeur caractéristique de x pour faciliter la mise au point du programme : x = pi/6.
*/

// ==================================================
// ================ INCLUDES ========================
// ==================================================
#include <cmath>
#include <iostream>

using namespace std;

// ==================================================
// ================ FUNCTIONS =======================
// ==================================================

void puissance(float x, int n, float &resultat) {
    resultat = 1;
    for (int i = 1; i <= n; i++) {
        resultat *= x;
    }
}

void factorielle(int n, float &resultat) {
    resultat = 1;
    for (int i = 1; i <= n; i++) {
        resultat *= i;
    }
}

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

// ==================================================
// ================ MAIN ============================
// ==================================================

int main() {
    double x, epsilon, resultat, resultatDirect;
    int nbTermes;

    cout << "Valeur de x : ";
    cin >> x;

    cout << "Précision epsilon : ";
    cin >> epsilon;

    sinusTaylor(x, epsilon, resultat, nbTermes);

    resultatDirect = sin(x);

    cout << "Résultat approché : " << resultat << endl;
    cout << "Résultat direct : " << resultatDirect << endl;
    cout << "Erreur relative : " << abs(resultat - resultatDirect) / resultatDirect << endl;
    cout << "Nombre de termes : " << nbTermes << endl;

    return 0;
}

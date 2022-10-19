/**
 * @author Benjamin Peronne
 * @email contact@benjaminperonne.fr
 * @create date 2022-10-18 10:20:13
 * @modify date 2022-10-18 10:20:13
 * @desc [TP3 - Ex1]
 */
// TP3 - DICHOTOMIE – METHODE DES TRAPEZES – DECOMPOSITION EN SERIE

/*
1. Ecrire l'algorithme d'un sous programme SinusCardinal qui effectue le calcul de la fonction f(x) = 3. sin(x)/x, avec f(0) = 3. Choisir le type de la valeur donnée en entrée et le type de la valeur renvoyée par la fonction.

2. Ecrire l'algorithme du sous-programme dichotomie qui reçoit en paramètres : les bornes de l'intervalle de recherche initial ainsi que la précision recherchée et renvoie la valeur du zéro de la fonction ainsi que le nombre d'itérations nécessaires pour trouver la solution.

3. Ecrire l'algoritgme du programme principal qui demande à l'utilisateur de fournir les bornes de l'intervalle de recherche intiial a et b puus appelle le sous-programme dichotomie et enfin affciha la valeur de x pour laquelle la fonction f(x) s'annule ainsi que le nombre d'itérations.

4. Préparer un jeu de test complet de calcul d'un zéro de la fonction f(x) en tuilisant des bornes d'intervella différentes de la copie d'écran Geogebra donnée dans le document du TP3

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

// Cette fonction calcule la valeur de la fonction f(x) = 3. sin(x)/x avec f(0) = 3
void SinusCardinal(double x, double &f) {
    if (x == 0) {
        f = 3;
    } else {
        f = 3 * sin(x) / x;
    }
}

// Fonction qui effectue la dichotomie ...
void dichotomie(double a, double b, double precision, double &zero, int &nbIterations) {
    double fA, fB, fM, m;

    SinusCardinal(a, fA); // Calcul de f(a)
    SinusCardinal(b, fB); // Calcul de f(b)

    nbIterations = 0;

    while (b - a > precision) { // Tant que l'intervalle est plus grand que la précision
        m = (a + b) / 2;        // Calcul du milieu de l'intervalle

        SinusCardinal(m, fM); // Calcul de f(m)

        if (fM * fA < 0) { // Si f(m) et f(a) ont des signes opposés
            b = m;
            fB = fM;
        } else { // Sinon f(m) et f(b) ont des signes opposés
            a = m;
            fA = fM;
        }
        nbIterations++;
    }
    zero = (a + b) / 2;
}

// ==================================================
// ================ MAIN ============================
// ==================================================
int main() {
    double a, b, eps, x;
    int n;
    cout << "Donner les bornes de l'intervalle de recherche initial : " << endl;

    cout << "a = ";
    cin >> a;

    cout << "b = ";
    cin >> b;

    cout << "Donner la precision recherchee : ";
    cin >> eps;

    dichotomie(a, b, eps, x, n);

    cout << "La solution est x = " << x << endl;
    cout << "Le nombre d'iterations necessaires est n = " << n << endl;

    return 0;
}

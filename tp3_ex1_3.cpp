/**
 * @author Benjamin Peronne
 * @email contact@benjaminperonne.fr
 * @create date 2022-10-18 10:20:13
 * @modify date 2022-10-18 10:20:13
 * @desc [TP3 - Ex1.3]
 */
// TP3 - DICHOTOMIE – METHODE DES TRAPEZES – DECOMPOSITION EN SERIE

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

// Vérifier si |a - b| < precision (vrai ou faux)
bool verifPrecision(double a, double b, double precision) {
    return (abs(a - b) < precision);
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

    cout << "Vérification : |a - b| < eps : " << verifPrecision(a, b, eps) << endl;

    return 0;
}

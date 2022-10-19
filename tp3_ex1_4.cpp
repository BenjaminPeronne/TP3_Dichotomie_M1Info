/**
 * @author Benjamin Peronne
 * @email contact@benjaminperonne.fr
 * @create date 2022-10-18 10:20:13
 * @modify date 2022-10-18 10:20:13
 * @desc [TP3 - Ex1.4]
 */
// TP3 - DICHOTOMIE – METHODE DES TRAPEZES – DECOMPOSITION EN SERIE

/*
Objectif : Calculer l'intégrale de la fonction f(x) = sin(x) + 1 sur un intervalle défini [a,b] à l'aide de la méthode des trapèzes. Cette méthode consiste à découper l'intervalle choisi en n trapèzes de même largeur dont on sait calculer l'aire.

Vous compléterez le code du sous-programme trapeze de façon à afficher la valeur de l'aire de chaque trapèze et la valeur intermédiaire de l'aire totale.

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

// Cette fonction calcule la valeur de la fonction f(x) = sin(x) + 1
void sinusPlusUn(float x, float &y) {
    y = sin(x) + 1;
}

// Cette fonction calcule l'intégrale de la fonction f(x) = sin(x) + 1
// dans l'intervalle [a,b] avec un nombre de trapèzes donné
void trapeze(float a, float b, int n, float &resultat) {
    float l, fA, fB, fM, m;

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

    cout << "Aire du trapèze : " << l * (fA + fB) / 2 << endl;

    cout << "Aire totale : " << resultat << endl;
}

// ==================================================
// ================ MAIN =============================
// ==================================================
int main() {
    float a, b, res;
    int n;

    cout << "Entrez la borne a : ";
    cin >> a;
    cout << "Entrez la borne b : ";
    cin >> b;
    cout << "Entrez le nombre de trapezes : ";
    cin >> n;

    trapeze(a, b, n, res);

    cout << "Resultat : " << res << endl;
    cout << "Resultat theorique : " << cos(a) - cos(b) << endl; // cos(a) - cos(b) est la primitive de sin(x) + 1
    cout << "Erreur relative : " << (res - (cos(a) - cos(b))) / (cos(a) - cos(b)) << endl;

    return 0;
}
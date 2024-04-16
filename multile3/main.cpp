#include <iostream>

using namespace std;

int main () {
    int num;

    cout << "Inserisci un numero: ";
    cin >> num;

    if (num % 3 == 0)
        cout << "Il numero e' multiplo di 3." << endl;
    else
        cout << "Il numero non e' multiplo di 3." << endl;
}
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

struct Dipendente {
    string nome;
    string cognome;
    int stipendio;
};

int main () {
    vector<Dipendente> dipendenti;
    int scelta;
    string nome, cognome;

    do{
        cout << "1. Inserisci dipendente" << endl;
        cout << "2. Licenzia dipendente" << endl;
        cout << "3. Stampa dipendenti" << endl;
        cout << "97. Salva lista dipendenti" << endl;
        cout << "98. Carica lista dipendenti" << endl;
        cout << "99. Esci" << endl;

        cout << "Scelta: ";
        cin >> scelta;

        switch (scelta)
        {
            case 1: {
                Dipendente d;
                cout << "Inserisci nome: ";
                cin >> d.nome;

                cout << "Inserisci cognome: ";
                cin >> d.cognome;

                cout << "Inserisci stipendio: ";
                cin >> d.stipendio;
                
                dipendenti.push_back(d);

                cout << "Dipendente inserito." << endl;
                break;
            }
            case 2: {
                if (dipendenti.size() == 0)
                {
                    cout << "Non ci sono dipendenti." << endl;
                } else {
                    cout << "Inserisci nome: ";
                    cin >> nome;

                    cout << "Inserisci cognome: ";
                    cin >> cognome;

                    bool trovato = false;
                    for (int i = 0; i < dipendenti.size(); i++) {
                        if (dipendenti[i].nome == nome && dipendenti[i].cognome == cognome) {
                            dipendenti.erase(dipendenti.begin() + i);
                            trovato = true;
                            break;
                        }
                    }

                    if (trovato) {
                        cout << "Dipendente licenziato." << endl;
                    }
                    else {
                        cout << "Dipendente non trovato." << endl;
                    }
                }
                break;
            }

            case 3: {
                if (dipendenti.size() == 0)
                {
                    cout << "Non ci sono dipendenti." << endl;
                } else {
                    for (int i = 0; i < dipendenti.size(); i++) {
                        cout << dipendenti[i].nome << " " << dipendenti[i].cognome << " " << dipendenti[i].stipendio << endl;
                    }   
                }
                break;
            }

            case 97: {
                if (dipendenti.size() == 0)
                {
                    cout << "Non ci sono dipendenti." << endl;
                } else {
                    ofstream file("dipendenti.txt");
                    if (file.is_open()) {
                        for (int i = 0; i < dipendenti.size(); i++) {
                            file << dipendenti[i].nome << "," << dipendenti[i].cognome << "," << dipendenti[i].stipendio << endl;
                        }
                        file.close();
                        cout << "Lista dipendenti salvata." << endl;
                    }
                    else {
                        cout << "Errore: impossibile aprire il file." << endl;
                    }
                }

                break;
            }

            case 98: {
                ifstream file("dipendenti.txt");
                if (file.is_open()) {
                    string line;
                    while (getline(file, line)) {
                        Dipendente d;
                        d.nome = line.substr(0, line.find(","));
                        line.erase(0, line.find(",") + 1);
                        d.cognome = line.substr(0, line.find(","));
                        line.erase(0, line.find(",") + 1);
                        d.stipendio = stoi(line);
                        dipendenti.push_back(d);
                    }
                    file.close();
                    cout << "Lista dipendenti caricata." << endl;
                }
                else {
                    cout << "Errore: impossibile aprire il file." << endl;
                }
                break;
            }

            default: {
                if (scelta != 99)
                    cout << "Scelta non valida." << endl;
            }
        }
        cout << endl;
    }while(scelta != 99);
}
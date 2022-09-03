#include <iostream>
#include <time.h>
using namespace std;

/*      C'e' un vettore con numeri generati casualmente da 1 a 10 poi si inserisce un valore da ricercare sempre da 1 a 10,  
        poi il programma cicla automaticamente fino a all'inserimento dell carattere q.
*/

/*      L'ordinamento bubble sort prendera un po'di tempo perchè aumenta esponenzialmente.

        Varibili(main):   
            vett(int) = vettore,                 
            n(int) = dimensione del vettore,
            val(int) = posizione del valore da ricercare se trovato,
            dato(int) = valore da cercare,
            c(char) = carattere da inserire se si vuole fermare il programma. 
*/

/*      Genera Vettore Casuale      */

void generaNumeri(int v[], int n)
{
    srand(time(NULL));
    for (int i = 0; i < n; i++)
    {
        v[i] = rand()%11;
        while(v[i] == 0)
            v[i] = rand()%11;

    }
        
}

/*      Stampa       */

void stampa(int v[], int n)
{
    for (int i = 0; i < n; i++)
        cout << v[i] << " ";
    cout << endl;
}

/*      Scambio per ordinamento       */

void scambia(int &i, int &k)
{
    int aus = i;
    i = k;
    k = aus;
}

/*      Ordinamento     */

void ordina(int v[], int n)
{
    for ( int i = 0; i < n - 1; i++)
    {
        for (int k = i + 1; k < n; k++)
        {
            if (v[k] < v[i])
                scambia(v[i], v[k]);
        }
    }
}

/*      Ricerca     */

int ricerca(int v[], int val, int dim)
{
    int i = 0;
    bool trovato = false;
    while(i < dim && v[dim - 1] > val)
    {
        if(v[i] == val)
        {
            trovato = true;
            cout << "Trovato in posizione: " << i << endl;
        }
        if(v[i + 1] > val)
            break;
        i++;
    }

    if(!trovato)
        cout << "Non trovato" << endl;

}

/*      Main        */

int main ()
{
    int n;
    char c;
    do
    {
        cout << "Quanti numeri vuoi? ";
        cin >> n;
        int vett[n];

        generaNumeri(vett, n);
        ordina(vett, n);
        stampa(vett, n);

        int dato;
        cout << "Inserisci il valore da torvare(1-10): ";
        cin >> dato;

        int val;
        val = ricerca(vett, dato, n);
        if (val == -1)
            cout << "Valore non trovato" << endl;      
    
        bool stmp;
        cout << "Vuoi che stampi i valori? ";
        cin >> stmp;
        if (stmp)
            stampa(vett, n);

        cout << "Premi q per smettere: ";
        cin >> c;
    }while(c != 'q');
}
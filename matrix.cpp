#include <iostream>
using namespace std;

#define DIM 5

void costruzione(int tab[][DIM])
{
   int parziale = DIM - 1;
    for (int r = 0; r < DIM; r++)
    {
       for (int c = 0; c < DIM; c++)
        {
            if (c == r)
                tab[r][c] = 1;
            
            else
                tab[r][c] = 0;
            if (c == parziale)
            {
                tab[r][c] = 1;
                parziale--;
            }
        }   
    }
}

void stampa(int tab[][DIM])
{
    for (int r = 0; r < DIM; r++)
    {
       for (int c = 0; c < DIM; c++)
            cout << tab[r][c] << ' ';
        cout << endl;
    }
}

int main ()
{
    int tab[DIM][DIM];
    costruzione(tab);
    stampa(tab);
    bool a = false;
    /* do
    {
        cin >> a;
    }while(!a); */
}
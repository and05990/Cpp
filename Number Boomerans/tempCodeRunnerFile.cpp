#include <iostream>
#include <string>
using namespace std;

#define ARRAY_SIZE 11

int countBoomerangs(int array[], int size, int boomerangs[])
{
    int count = 0;
    for (int i = 0; i < size - 2; i++)
    {
        if (array[i] == array[i + 2] && array[i] != array[i + 1])
        {
            boomerangs[count] = array[i];
            boomerangs[count + 1] = array[i + 1];
            boomerangs[count + 2] = array[i + 2];
            count += 3;
        }
    }
    return count / 3;
}

int main() {
    int array[ARRAY_SIZE] = {3, 7, 3, 2, 1, 5, 1, 2, 2, -2, 2};
    int boomerangs[ARRAY_SIZE];
    int numBoomerangs = countBoomerangs(array, ARRAY_SIZE, boomerangs);

    cout << "Number of boomerangs: " << numBoomerangs << endl;
    cout << "Boomerangs: ";
    for (int i = 0; i < numBoomerangs * 3; i++)
    {
        cout << boomerangs[i] << " ";
    }
}
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

void removeNonNumeric(string& str)
{
    str.erase(remove_if(str.begin(), str.end(), [](char c) { return !isdigit(c); }), str.end());
}

int main() {
    string array[] = {"123", "abc123", "456def", "789"};
    int size = sizeof(array) / sizeof(array[0]);

    for (int i = 0; i < size; i++)
    {
        removeNonNumeric(array[i]);
        cout << array[i] << endl;
    }
}
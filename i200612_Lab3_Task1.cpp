// i200612_Lab03_Task1.cpp
// Data Structures Lab 02 Task 01
// Saamiya Mariam 20i-0612 Section A

#include <iostream>
#include <string.h>
using namespace std;

int* insertionSorting(int S[], int size)
{
     int end;


    for (int i = 1; i < size; i++)
    {
        end = S[i];
        int j = i - 1;
        while (j >= 0 && S[j] > end)
        {
            S[j + 1] = S[j];
            j = j - 1;
        }
        S[j + 1] = end;
    }

    for (int i = 0; i < 7; i++)
    {
        cout << S[i] << " ";
    }



    return S;

}

int main()
{
    string Str = { "zDvLaGT" };
    int size = 0;

    for (int i = 0; Str[i] != '\0'; i++)
    {
        size++;
    }
    int S1[size];
    for (int i = 0; i < size; i++)
    {
        S1[i] = int(Str[i]);
    }
    insertionSorting(S1, size);
}





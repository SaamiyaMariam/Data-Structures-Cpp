// i200612_Lab03_Task2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int* selectionSort(int Arr[], int size)
{
    int minimum=0;

    for (int i = 0; i < size - 1; i++)
    {
        minimum = i;
        for (int j = i + 1; j < size; j++)
        {
            if (Arr[j] < Arr[minimum])
            {
                minimum = j;
                int temp = Arr[minimum];
                Arr[minimum] = Arr[i];
                Arr[i] = temp;
            }
        }


    }

    for (int i = 0; i < 7; i++)
    {
        cout << Arr[i] << " ";
    }
    return Arr;
}
int* InsertionSort(int S[], int size)
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
    int Puzzle[3][7] = { {32,30,39,34,37,35,33},{50,48,54,59,47,49,52},{9,3,6,5,12,2,4} };
    int row = 3;
    int col = 7;

    int A1[7],A2[7],A3[7];
    for (int i = 0; i < 7; i++)
    {
        A1[i] = Puzzle[0][i];
    }
    for (int i = 0; i < 7; i++)
    {
        A2[i] = Puzzle[1][i];
    }
    for (int i = 0; i < 7; i++)
    {
        A3[i] = Puzzle[2][i];
    }
    selectionSort(A1, 7);
    cout << endl;
    InsertionSort(A2, 7);
    return 0;
}


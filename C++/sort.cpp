#include<iostream>

using namespace std;

/**
 *快排 
 * 
**/

int tab[10] = {0, 9, 1, 8, 5, 6, 7, 11, 12, 3};

void quicksort(int r[], int low, int high)
{
    int i = low, j = high;
    int base = r[(low + high) / 2];
    while(i < j)
    {
        while(r[i] < base)
            i++;
        while(r[j] > base)
            j--;
        if(i <= j)
        {
            swap(r[i], r[j]);
            i++;
            j--;
        }
    }
    if(j > low)
        quicksort(tab, low, j);
    if(i < high)
        quicksort(tab, i, high);
}

int main()
{
    quicksort(tab, 0, 9);
    for(int i=0; i < 10 ; i++)
    {
        cout << tab[i] << endl;
    }
    return 0;
}
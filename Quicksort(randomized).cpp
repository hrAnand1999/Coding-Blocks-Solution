#include <iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
void shuffle(int *a, int s, int e)
{
    srand(time(NULL));
    int i, j;
    for(i = e; i > 0; i--)
    {
        j = rand() % (i  + 1);
        swap(a[j], a[i]);
    }
}
int partition(int *a, int s, int e)
{
    int pivot = e;
    int i = s - 1;
    int j = s;
    for(; j < e; )
    {
        if(a[j] <= a[pivot])
        {
            i++;
            swap(a[i], a[j]);
            j++;
        }
        else
        j++;
    }
    i++;
    swap(a[e], a[i]);
    return i;
}
void quick_sort(int *a, int s, int e)
{
    if(s >= e)
    return;
    int j = partition(a, s, e);
    quick_sort(a, s, j - 1);
    quick_sort(a, j + 1, e);
}
int main() {
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    shuffle(a, 0, n - 1);
    
    quick_sort(a, 0, n - 1);
    for(int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}

#include <iostream>
using namespace std;

#define MAX 100

int suma_pos(int *a, int ind, int n) {
    int i, s = 0;
    if (ind > n) return 0;
    else 
        for (i = ind; i < n; i++)
            s = s + *(a + i);
    return s;
}

int main() {
    int n, ind, i, a[MAX];
    
    cin >> n;
    
    for (i = 0; i < n; i++)
        cin >> *(a + i);
    
    cin >> ind;
    
    cout << suma_pos(a, ind, n) << endl;

    return 0;
}
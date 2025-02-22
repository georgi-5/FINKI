#include <iostream>
#include <cmath>
using namespace std;

#define SIZE 100

double cf(int n, int a[]) {
    if (n == 1)
        return a[0];
    else
        return a[0] + 1.0 / cf(n - 1, a + 1);
}

int main() {
    int n, coef[SIZE];
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> coef[i];
    cout << cf(n, coef) << endl;
    
    return 0;
}
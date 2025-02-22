#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
    int i, j, m, n, a[100][100];
    cin >> m >> n;
    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++)
            cin >> a[i][j];
    
    for (i = 0; i < m; i++) {
        int sum1 = 0, sum2 = 0;
        for (j = 0; j < n / 2 + n % 2; j++)
            sum1 += a[i][j];
        for (j = n / 2; j < n; j++)
            sum2 += a[i][j];
        if (n % 2)
            a[i][n / 2] = abs(sum1 - sum2);
        else {
            a[i][n / 2] = a[i][n / 2 - 1] = abs(sum1 - sum2);
        }
    }
    
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
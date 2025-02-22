#include <iostream>
#include <cmath>
using namespace std;

#define MAX 100

int main() {
    int a[MAX][MAX], b[MAX], m, n, i, j, maxJ, l = 0;
    float as;
    cin >> m >> n;
    
    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++)
            cin >> a[i][j];

    for (i = 0; i < m; i++) {
        as = 0;
        for (j = 0; j < n; j++) {
            as += a[i][j];
        }
        as /= n;
        float maxD = fabs(as - a[i][0]);
        float d = 0;
        maxJ = 0;
        for (j = 0; j < n; j++) {
            d = fabs(as - a[i][j]);
            if (d > maxD) {
                maxD = d;
                maxJ = j;
            }
        }
        b[l++] = a[i][maxJ];
    }

    for (i = 0; i < l; i++)
        cout << b[i] << " ";
    
    return 0;
}
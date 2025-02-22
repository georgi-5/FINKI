#include <iostream>

using namespace std;

const int MAX = 100;

int BrojPozitivni(int niza[], int n);

int main() {
    int n, i;
    int niza[MAX];
    cin >> n;
    
    for (i = 0; i < n; i++) {
        cin >> niza[i];
    }

    cout << BrojPozitivni(niza, n - 1) << endl;

    return 0;
}

int BrojPozitivni(int niza[], int n) {
    if (n == 0) {
        return (niza[0] > 0) ? 1 : 0;
    }

    return (niza[n] > 0 ? 1 : 0) + BrojPozitivni(niza, n - 1);
}
#include <iostream>
#include <algorithm>

using namespace std;

int poramni(int a) {
    if (a == 0)
        return 0;
    else if (a % 10 == 9)
        return 7 + poramni(a / 10) * 10;
    return (a % 10) + poramni(a / 10) * 10;
}

void sort(int *a, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] > a[j]) {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}

int main() {
    const int MAX = 100;
    int a[MAX], i = 0, n;

    while (cin >> a[i]) {
        i++;
    }

    n = i;

    for (i = 0; i < n; i++) {
        a[i] = poramni(a[i]);
    }

    sort(a, n);

    if (n < 5) {
        for (i = 0; i < n; i++)
            cout << a[i] << " ";
    } else {
        for (i = 0; i < 5; i++)
            cout << a[i] << " ";
    }

    return 0;
}
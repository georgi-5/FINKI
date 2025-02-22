#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;

void substring(char *x, char z1, char z2) {
    char *c1, *c2, newS[80];
    c1 = strchr(x, z1);
    c2 = strchr(x, z2);
    if (c1 && c2 && c1 < c2) {
        strncpy(newS, c1 + 1, c2 - c1 - 1);
        newS[c2 - c1 - 1] = '\0';
        cout << newS << endl;
    }
}

int main() {
    char z1, z2;
    char row[80];
    
    cin >> z1;    
    cin >> z2;
    cin.get();
    while (true) {
        cin.getline(row, 80);
        if (!strcmp(row, "#")) break;
        substring(row, z1, z2);
    }
  
    return 0;
}
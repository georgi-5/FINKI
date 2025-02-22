#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;

void cipher(char *word, int x) {
    if (*word == 0) return;
    if (isalpha(*word)) {
        char first = isupper(*word) ? 'A' : 'a';
        *word = first + (*word + x - first) % 26;
    }
    cipher(++word, x);
}

int main() {
    int n, x;
    cin >> n >> x;
    cin.ignore();
    char word[80];
    for (int i = 0; i < n; ++i) {
        cin.getline(word, sizeof(word));
        cipher(word, x);
        cout << word << endl;
    }
    return 0;
}
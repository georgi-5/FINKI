#include <iostream>
#include <cctype>

using namespace std;

bool is_cik_cak(int number) {
    string num_str = to_string(number);
    bool is_cikcak = true;
    
    for (size_t i = 0; i < num_str.length() - 1; ++i) {
        int mom = num_str[i] - '0';
        int sledna = num_str[i + 1] - '0';
        
        if (!((mom < 5 && sledna >= 5) || (mom >= 5 && sledna < 5))) {
            is_cikcak = false;
            break;
        }
    }
    
    return is_cikcak;
}

int main() {
    int n;
    
    while (cin >> n) {
        if (n < 10) {
            continue;
        }
        
        if (is_cik_cak(n)) {
            cout << n << endl;
        }
    }
    
    return 0;
}
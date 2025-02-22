#include <iostream>
using namespace std;

int main() {
    int a[100][100];
    int rows, cols;
    cin >> rows >> cols;
    
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cin >> a[i][j];
        }
    }
    
    int count = 0;
    int flag, c;
    
    for (int i = 0; i < rows; ++i) {
        c = 0;
        flag = 0;
        for (int j = 0; j < cols; ++j) {
            if (a[i][j] == 1) {
                ++c;
            } else {
                if (c >= 3) {
                    flag = 1;
                    ++count;
                    break;
                }
                c = 0;
            }
        }
        if (!flag && c >= 3) {
            ++count;
        }
    }
    
    for (int i = 0; i < cols; ++i) {
        c = 0;
        flag = 0;
        for (int j = 0; j < rows; ++j) {
            if (a[j][i] == 1) {
                ++c;
            } else {
                if (c >= 3) {
                    flag = 1;
                    ++count;
                    break;
                }
                c = 0;
            }
        }
        if (!flag && c >= 3) {
            ++count;
        }
    }
    
    cout << count << endl;
    return 0;
}
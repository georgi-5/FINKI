#include <iostream>
#include <cctype>  

using namespace std;

int main() {
    char rec[1000];

    int br = 0;
    while (true) {
        cin.getline(rec, sizeof(rec));

        if (rec[0] == '#') {
            break;
        }


        for (int i = 0; rec[i] != '\0'; ++i) {
            char bukva = tolower(rec[i]);

            if (bukva == 'a' || bukva == 'e' || bukva == 'i' ||
                bukva == 'o' || bukva == 'u') {

                char sbukva = tolower(rec[i + 1]);
                if (sbukva == 'a' || sbukva == 'e' || sbukva == 'i' ||
                    sbukva == 'o' || sbukva == 'u') {


                    cout << bukva << sbukva << endl;
                    ++br;
                }
            }
        }

    }
    cout << br << endl;
    return 0;
}

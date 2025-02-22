#include <iostream>

using namespace std;

int main()
{
    int n, cifra1, cifra2, sign, pom;

    while (cin >> n)
    {
        if (n < 10)
        {
            continue;
        }

        pom = n;
        cifra1 = n % 10;
        cifra2 = (n / 10) % 10;
        
        if (cifra1 > cifra2)
        {
            sign = 1;
        }
        else if (cifra1 < cifra2)
        {
            sign = 0;
        }
        else
        {
            continue;
        }

        n = n / 10;
        int cikcak = 1;

        while (n > 9)
        {
            cifra1 = n % 10;
            cifra2 = (n / 10) % 10;
            
            if (sign == 1)
            {
                if (cifra1 >= cifra2)
                {
                    cikcak = 0;
                    break;
                }
                sign = 0;
            }
            else // sign == 0
            {
                if (cifra1 <= cifra2)
                {
                    cikcak = 0;
                    break;
                }
                sign = 1;
            }
            n = n / 10;
        }

        if (cikcak == 1)
        {
            cout << pom << endl;
        }
    }

    return 0;
}
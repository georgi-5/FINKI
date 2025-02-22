#include <iostream>


using namespace std;
int main()
{
    int n,x,totalnoRazlicen;
    cin>>n>>x;
    --n;//bidejki vo zadacata se bara brojot da bide pomal od n
    while(n>0)
    {
        totalnoRazlicen=1;
        int pomX = x;
        while(pomX!=0)
        {
            int najde=0;
            int cifraX = pomX%10;
            int pomN = n;
            while(pomN!=0)
            {
                int cifraN = pomN%10;
                if(cifraX==cifraN)
                {
                    najde=1;
                    break;
                }
                pomN = pomN/10;
            }
            if(najde==1)
            {
                totalnoRazlicen=0;
                break;
            }
            pomX =pomX/10;
        }
        if(totalnoRazlicen==1)
        {
            cout<<n;
            break;
        }
        n--;
    }
    if(totalnoRazlicen==0){
        cout<<n;
    }
    return 0;
}
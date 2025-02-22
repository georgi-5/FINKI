#include <iostream>

using namespace std;
int najgCif(int n)
{
    int cifra=0;
    int najgC=0;
    while(n!=0)
    {
        cifra=n%10;
        n/=10;

    if(cifra>najgC){
        najgC=cifra;
    }
    }
    return najgC;
}
int main()
{
    int n;
    while(cin>>n){
        cout<<najgCif(n)<<endl;
    }
    return 0;
}
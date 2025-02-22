#include <iostream>
#include <iomanip>
using namespace std;


int main()
{
    int n,x,cifra=0,maxcifra=0,maxbr=0;
    while(1){
        cin>>n;
        if(n<=0){
            break;
        }
        maxcifra=0;
        for(int i=0; i<n; i++){
            cin>>x;
            int pom=x;
            while(pom!=0){
                cifra=pom%10;
                pom/=10;
            }
            if(maxcifra<cifra){
                maxcifra=cifra;
                maxbr=x;
            }
        }
        cout<<maxbr<<endl;
    }
    return 0;
}
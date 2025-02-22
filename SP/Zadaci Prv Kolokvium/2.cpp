#include <iostream>

using namespace std;

int main()
{
    int a,cifra,flag,broj=0,br=0;
    cin>>a;
    if(a<=9){
        cout<<"Brojot ne e validen"<<endl;
    }
    else{
        while(a>9){
        --a;
        int pomosna=a;
        br=0;
        broj=0;
        while(pomosna!=0){
        cifra=pomosna%10;
        broj=broj*10+cifra;
        pomosna/=10;
        br++;
        }
        if(broj%br==0){
            cout<<a;
            break;
        }
        }
    }

    return 0;
}
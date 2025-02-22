#include <iostream>

using namespace std;

int main()
{
    char c;
    int zbir=0;
    while(1){
        cin>>c;
        if(c=='.'){
            break;
        }
        if((c>='0')&&(c<='9')){
            zbir+=c-'0';
        }
        if((c>='a')&&(c<='f')){
            zbir+=c-'a'+10;
        }
         if((c>='A')&&(c<='F')){
            zbir+=c-'A'+10;
        }
    }
    if(zbir%16==0){
        if(zbir%100==16){
            cout<<"Poln pogodok"<<endl;
        }
        else
            cout<<"Pogodok"<<endl;
    }
    else
        cout<<zbir;
    return 0;
}
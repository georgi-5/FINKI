#include <iostream>

using namespace std;

int main()
{
    char c;
    int broj=0;
    int zbir=0;
    while(cin>>noskipws>>c){
            if(c>='0'&&c<='9'){
                broj=broj*10+c-'0';
            }
            else{
               zbir+=broj;
               broj=0;
            }
        if(c=='!'){
            break;
        }
    }
    cout<<zbir;
    return 0;
}
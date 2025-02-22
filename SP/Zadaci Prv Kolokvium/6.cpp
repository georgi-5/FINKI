#include <iostream>

using namespace std;

int main()
{
    float a,b,c,br2=0;
    cin>>a;
    float br=0,zbir=0;
    while(cin>>b>>c){
        zbir=0;
        zbir+=b+c;
        if(b+c==a){
            br++;
        }
        if(b==0 && c==0){
            break;
        }
        br2++;
    }
    float procent=(br/br2)*100;
    cout<<"Vnesovte "<<br<<" parovi od broevi chij zbir e "<<a<<endl;
    cout<<"Procentot na parovi so zbir "<<a<<" e "<<procent<<"%";
    return 0;
}
#include <iostream>

using namespace std;
struct laptop{
 char firma[100];
 float golemina;
 bool touch;
 int cena;
 void print(){
    cout<<firma<<" "<<golemina<<" "<<cena<<endl;
 }
};
struct it{
 char ime[100];
 char lokacija[100];
 laptop l[100];
 int brLaptopi;
 void print(){
    cout<<ime<<" "<<lokacija<<endl;
    for(int i=0; i<brLaptopi; i++){
        l[i].print();
    }
 }
};

void najeftina(it *s,int n){
    int najniska=99999999999;
    int x;
    for(int i=0; i<n; i++){
        for(int j=0; j<s[i].brLaptopi; j++){
            if(najniska>s[i].l[j].cena && s[i].l[j].touch==1){
                najniska=s[i].l[j].cena;
                x=i;
            }
        }
    }
    cout<<"Najeftina ponuda ima prodavnicata:"<<endl;
    cout<<s[x].ime<<" "<<s[x].lokacija<<endl;
    cout<<"Najniskata cena iznesuva: "<<najniska<<endl;;
}
int main()
{
    it s[100];
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>s[i].ime>>s[i].lokacija>>s[i].brLaptopi;
        for(int j=0; j<s[i].brLaptopi; j++){
            cin>>s[i].l[j].firma;
            cin>>s[i].l[j].golemina;
            cin>>s[i].l[j].touch;
            cin>>s[i].l[j].cena;
        }
    }
    for(int i=0; i<n; i++){
        s[i].print();
    }
    najeftina(s,n);
    return 0;
}
#include <iostream>

using namespace std;
struct Laptop{
    char firma[100];
    float golemina;
    bool touch;
    int cena;
    void print(){
    cout<<firma<<" "<<golemina<<" "<<cena<<endl;
    }
};
struct ItStore{
 char ime[100];
 char lokacija[100];
 Laptop l[100];
 int brLaptopi;
 void print(){
    cout<<ime<<" "<<lokacija<<endl;
    for(int i=0; i<brLaptopi; i++){
        l[i].print();
    }
 }
};
void najeftinaPonuda(ItStore *is ,int n){
    bool minInit=false;
    int min=999999999;
    int index,indexJ;
    for(int i=0; i<n; i++){
        for(int j=0; j<is[i].brLaptopi; j++){
            if(is[i].l[j].touch==1){
                if(min>is[i].l[j].cena){
                    min=is[i].l[j].cena;
                    index=i;
                    indexJ=j;
                }
            }
        }
    }
    cout<<"Najeftina ponuda ima prodavnicata:"<<endl;
    cout<<is[index].ime<<" "<<is[index].lokacija<<endl;
    cout<<"Najniskata cena iznesuva: "<<is[index].l[indexJ].cena<<endl;
}
int main()
{
    ItStore is[100];
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>is[i].ime;
        cin>>is[i].lokacija;
        cin>>is[i].brLaptopi;
        for(int j=0; j<is[i].brLaptopi; j++){
            cin>>is[i].l[j].firma;
            cin>>is[i].l[j].golemina;
            cin>>is[i].l[j].touch;
            cin>>is[i].l[j].cena;

        }
    }
    for(int i=0; i<n; i++){
        is[i].print();
    }
    najeftinaPonuda(is,n);
    return 0;
}
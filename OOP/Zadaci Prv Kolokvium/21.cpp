#include <iostream>
#include <cstring>
using namespace std;
struct Tanc{
  char imeT[15];
  char zPoteklo[15];
};
struct Tancer{
    char ime[20];
    char prezime[20];
    Tanc t[5];
};
void tancuvanje(Tancer *tn,int n,char *zemja){
    bool najde=false;
    for(int i=0; i<n; i++){
            najde=false;
        for(int j=0; j<3; j++){
            if(strcmp(tn[i].t[j].zPoteklo,zemja)==0){
                najde=true;
                break;
            }
        }
        for(int j=0; j<3; j++){
            if(najde==true){
                if(strcmp(tn[i].t[j].zPoteklo,zemja)==0){
                cout<<tn[i].ime<<" "<<tn[i].prezime<<", "<<tn[i].t[j].imeT<<endl;
                break;
                }
            }
        }
    }
}
int main()
{
    Tancer tn[100];
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>tn[i].ime;
        cin>>tn[i].prezime;
        for(int j=0; j<3; j++){
        cin>>tn[i].t[j].imeT;
        cin>>tn[i].t[j].zPoteklo;
        }
    }
    char zemja[20];
    cin>>zemja;
    tancuvanje(tn,n,zemja);
    return 0;
}
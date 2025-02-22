#include <iostream>
#include <iomanip>
using namespace std;
struct Vozenje{
    char ime[100];
    int vreme;
    float cena;
    int popust;
};
struct ZabavenPark{
    char imeNaPark[100];
    char lokacija[100];
    Vozenje v[100];
    int brVozenja;
};
void print(ZabavenPark *z,int n){
    for(int i=0; i<n; i++){
        cout<<z[i].imeNaPark<<" "<<z[i].lokacija<<endl;
        for(int j=0; j<z[i].brVozenja; j++){
            cout<<z[i].v[j].ime<<" "<<z[i].v[j].vreme<<" "<<fixed<<setprecision(2)<<z[i].v[j].cena<<endl;
        }
    }
}
void najdobar(ZabavenPark *z,int n){
    int maxSum=0;
    int x;
    int l;
    int sum=0;
            int sum2=0;
            int maxSum2=0;
    for(int i=0; i<n; i++){
            sum=0;
            sum2=0;

        for(int j=0; j<z[i].brVozenja; j++){
            sum+=z[i].v[j].popust;
            sum2+=z[i].v[j].vreme;
            if(maxSum<sum){
            maxSum=sum;
            x=i;
        }
        if(maxSum2<sum2){
                    maxSum2=sum2;
                    l=i;
                }
        }


    }
    if(maxSum<sum){
    cout<<"Najdobar park: "<<z[x].imeNaPark<<" "<<z[x].lokacija<<endl;
    }
    else
        cout<<"Najdobar park: "<<z[l].imeNaPark<<" "<<z[l].lokacija<<endl;
}
int main()
{
    ZabavenPark z[100];
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>z[i].imeNaPark;
        cin>>z[i].lokacija;
        cin>>z[i].brVozenja;
        for(int j=0; j<z[i].brVozenja; j++){
            cin>>z[i].v[j].ime;
            cin>>z[i].v[j].vreme;
            cin>>z[i].v[j].cena;
            cin>>z[i].v[j].popust;
        }
    }
    print(z,n);
    najdobar(z,n);
    return 0;
}
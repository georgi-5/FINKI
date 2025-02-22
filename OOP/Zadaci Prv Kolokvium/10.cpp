#include <iostream>

using namespace std;
struct Igrac{
    char kIme[15];
    int nivo;
    int osvoeni;
};
struct KompjuterskaIgra{
    char ime[20];
    int brIgraci;
    Igrac x[30];
};
void najdobarIgrac ( KompjuterskaIgra *k,int n){
    int sum=0;
    int popularnost=0;
    int maxP=0;
    int poeni=0;
    int maxpo=0;
    for(int i=0; i<n; i++){
        if(popularnost<k[i].brIgraci){
            popularnost=k[i].brIgraci;
            maxP=i;
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<k[i].brIgraci; j++){
            if(poeni<k[i].x[j].osvoeni && i==maxP){
                poeni=k[i].x[j].osvoeni;
                maxpo=j;
            }
        }
    }
    cout<<"Najdobar igrac e igracot so korisnicko ime "<<k[maxP].x[maxpo].kIme<<" koj ja igra igrata "<<k[maxP].ime;
}
int main()
{
    KompjuterskaIgra k[100];
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>k[i].ime;
        cin>>k[i].brIgraci;
        for(int j=0; j<k[i].brIgraci; j++){
            cin>>k[i].x[j].kIme;
            cin>>k[i].x[j].nivo;
            cin>>k[i].x[j].osvoeni;
        }
    }
    najdobarIgrac(k,n);
    return 0;
}
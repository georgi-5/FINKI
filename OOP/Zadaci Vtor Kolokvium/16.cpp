#include <iostream>
#include <cstring>
using namespace std;
class Transport {
protected:
    char *destinacija;
    int cena;
    int km;
public:
    Transport() {
        this->destinacija=new char[0];
        cena=0;
        km=0;
    }
    Transport(char *destinacija,int cena,int km) {
        this->destinacija=new char[strlen(destinacija)+1];
        strcpy(this->destinacija,destinacija);
        this->cena=cena;
        this->km=km;
    }
    Transport(const Transport &t) {
        this->destinacija=new char[strlen(t.destinacija)+1];
        strcpy(this->destinacija,t.destinacija);
        this->cena=t.cena;
        this->km=t.km;
    }
    Transport& operator==(const Transport &t) {
        if(this!=&t) {
            delete []destinacija;
            this->destinacija=new char[strlen(t.destinacija)+1];
            strcpy(this->destinacija,t.destinacija);
            this->cena=t.cena;
            this->km=t.km;
        }
        return *this;
    }
    virtual int cenaTransport()=0;
    virtual bool operator<(const Transport &t) {
        return destinacija<t.destinacija;
    }
    char* getDestinacija() {
        return destinacija;
    }
    int getKm() {
        return km;
    }
    ~Transport() {
        delete []destinacija;
    }
};
class AvtomobilTransport:public Transport {
private:
    bool platenSofer;
public:
    AvtomobilTransport(){}
    AvtomobilTransport(char *destinacija,int cena,int km,bool platenSofer):Transport(destinacija,cena,km) {
        this->platenSofer=platenSofer;
    }
    int cenaTransport() {
        float cena2=cena;
        if(platenSofer) {
            float procent=cena*20/100;
            cena2+=procent;
        }
        return cena2;
    }
};
class KombeTransport:public Transport {
private:
    int brLugje;
public:
    KombeTransport(){}
    KombeTransport(char *destinacija,int cena,int km,int brLugje):Transport(destinacija,cena,km) {
        this->brLugje=brLugje;
    }
    int cenaTransport() {
        int cenaPatnik=200;
        int cena2=cena;
        for (int i=0; i<brLugje; i++) {
            cena2-=cenaPatnik;
        }
        return cena2;
    }
};
void pecatiPoloshiPonudi(Transport **ponudi,int n,AvtomobilTransport nov) {
     for(int i=0; i<n; i++) {
        for(int j=0; j<n-1; j++) {
            if(ponudi[j]->getKm()>ponudi[j+1]->getKm()) {
                Transport* temp=ponudi[j];
                ponudi[j]=ponudi[j+1];
                ponudi[j+1]=temp;
            }
        }
    }
    for(int i=0; i<n; i++) {
        if(ponudi[i]->cenaTransport()>nov.cenaTransport()) {
            cout<<ponudi[i]->getDestinacija()<<" "<<ponudi[i]->getKm()<<" "<<ponudi[i]->cenaTransport()<<endl;
        }
    }
}
int main(){

    char destinacija[20];
    int tip,cena,rastojanie,lugje;
    bool shofer;
    int n;
    cin>>n;
    Transport  **ponudi;
    ponudi=new Transport *[n];

    for (int i=0;i<n;i++){

        cin>>tip>>destinacija>>cena>>rastojanie;
        if (tip==1) {
            cin>>shofer;
            ponudi[i]=new AvtomobilTransport(destinacija,cena,rastojanie,shofer);

        }
        else {
            cin>>lugje;
            ponudi[i]=new KombeTransport(destinacija,cena,rastojanie,lugje);
        }


    }

    AvtomobilTransport nov("Ohrid",2000,600,false);
    pecatiPoloshiPonudi(ponudi,n,nov);

    for (int i=0;i<n;i++) delete ponudi[i];
    delete [] ponudi;
    return 0;
}
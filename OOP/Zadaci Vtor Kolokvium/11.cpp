#include<iostream>
#include<string.h>
using namespace std;

//место за вашиот код
class Delo {
private:
    char ime[50];
    int godina;
    char poteklo[50];
public:
    Delo(){}
    Delo(char *ime,int godina,char *poteklo) {
        strcpy(this->ime,ime);
        this->godina=godina;
        strcpy(this->poteklo,poteklo);
    }
    Delo(const Delo &d) {
        strcpy(this->ime,d.ime);
        this->godina=d.godina;
        strcpy(this->poteklo,d.poteklo);
    }
    Delo& operator=(const Delo &d) {
        if(this!=&d) {
            strcpy(this->ime,d.ime);
            this->godina=d.godina;
            strcpy(this->poteklo,d.poteklo);
        }
        return *this;
    }
    void setIme(char *ime) {
        strcpy(this->ime,ime);
    }
    void setGodina(int godina) {
        this->godina=godina;
    }
    void setZemja(char *poteklo) {
        strcpy(this->poteklo,poteklo);
    }
    char* getIme() {
        return ime;
    }
    int getGodina() {
        return godina;
    }
    char* getZemja() {
        return poteklo;
    }
    bool operator==(const Delo &d) {
        return strcmp(this->ime,d.ime)==0;
    }
    ~Delo(){}
};
class Pretstava {
protected:
    Delo delo;
    int n;
    char data[15];
public:
    Pretstava(){}
    Pretstava(Delo delo,int n,char *data) {
        this->delo=delo;
        this->n=n;
        strcpy(this->data,data);
    }
    Pretstava(const Pretstava &p) {
        this->delo=p.delo;
        this->n=p.n;
        strcpy(this->data,p.data);
    }
   virtual  int cena() {
        int m;
        int n;
        if(delo.getGodina()>=1900) {
            m=50;
        }
        else if(delo.getGodina()>=1800 && delo.getGodina()<1900) {
            m=75;
        }
        else {
            m=100;
        }
        if(strcmp(delo.getZemja(),"Rusija")==0) {
            n=150;
        }
        else if(strcmp(delo.getZemja(),"Italija")==0) {
            n=100;
        }
        else {
            n=80;
        }
        return m+n;
    }
    int getN() {
        return n;
    }
    Delo getDelo() {
        return delo;
    }
    ~Pretstava(){}
};
class Balet:public Pretstava {
private:
    static int cena1;
public:
    Balet(Delo delo,int n,char *data):Pretstava(delo,n,data){}
    static void setCenaBalet(int cenabalet) {
        cena1=cenabalet;
    }
    int cena() {
        int cena=Pretstava::cena();
        cena+=cena1;
        return cena;
    }
    ~Balet(){}
};
class Opera:public Pretstava {
public:
    Opera(Delo delo,int n,char *data):Pretstava(delo,n,data){}
};
int Balet::cena1=150;
//citanje na delo
Delo readDelo(){
    char ime[50];
    int godina;
    char zemja[50];
    cin>>ime>>godina>>zemja;
    return Delo(ime,godina,zemja);
}
//citanje na pretstava
Pretstava* readPretstava(){
    int tip; //0 za Balet , 1 za Opera
    cin>>tip;
    Delo d=readDelo();
    int brojProdadeni;
    char data[15];
    cin>>brojProdadeni>>data;
    if (tip==0)  return new Balet(d,brojProdadeni,data);
    else return new Opera(d,brojProdadeni,data);
}
int prihod(Pretstava **pole,int n) {
    int sum=0;
    for(int i=0; i<n; i++) {
        sum+=pole[i]->cena()*pole[i]->getN();
    }
    return sum;
}
int brojPretstaviNaDelo(Pretstava **pole,int n,Delo d) {
    int br=0;
    for(int i=0; i<n; i++) {
        if(pole[i]->getDelo()==d) {
            br+=1;
        }
    }
    return br;
}
int main(){
    int test_case;
    cin>>test_case;

    switch(test_case){
    case 1:
    //Testiranje na klasite Opera i Balet
    {
        cout<<"======TEST CASE 1======="<<endl;
        Pretstava* p1=readPretstava();
        cout<<p1->getDelo().getIme()<<endl;
        Pretstava* p2=readPretstava();
        cout<<p2->getDelo().getIme()<<endl;
    }break;

    case 2:
    //Testiranje na  klasite Opera i Balet so cena
    {
        cout<<"======TEST CASE 2======="<<endl;
        Pretstava* p1=readPretstava();
        cout<<p1->cena()<<endl;
        Pretstava* p2=readPretstava();
        cout<<p2->cena()<<endl;
    }break;

    case 3:
    //Testiranje na operator ==
    {
        cout<<"======TEST CASE 3======="<<endl;
        Delo f1=readDelo();
        Delo f2=readDelo();
        Delo f3=readDelo();

        if (f1==f2) cout<<"Isti se"<<endl; else cout<<"Ne se isti"<<endl;
        if (f1==f3) cout<<"Isti se"<<endl; else cout<<"Ne se isti"<<endl;

    }break;

    case 4:
    //testiranje na funkcijata prihod
    {
        cout<<"======TEST CASE 4======="<<endl;
        int n;
        cin>>n;
        Pretstava **pole=new Pretstava*[n];
        for (int i=0;i<n;i++){
            pole[i]=readPretstava();

        }
        cout<<prihod(pole,n);
    }break;

    case 5:
    //testiranje na prihod so izmena na cena za 3d proekcii
    {
        cout<<"======TEST CASE 5======="<<endl;
        int cenaBalet;
        cin>>cenaBalet;
        Balet::setCenaBalet(cenaBalet);
        int n;
        cin>>n;
        Pretstava **pole=new Pretstava*[n];
        for (int i=0;i<n;i++){
            pole[i]=readPretstava();
        }
        cout<<prihod(pole,n);
        }break;

    case 6:
    //testiranje na brojPretstaviNaDelo
    {
        cout<<"======TEST CASE 6======="<<endl;
        int n;
        cin>>n;
        Pretstava **pole=new Pretstava*[n];
        for (int i=0;i<n;i++){
            pole[i]=readPretstava();
        }

        Delo f=readDelo();
        cout<<brojPretstaviNaDelo(pole,n,f);
    }break;

    };


return 0;
}
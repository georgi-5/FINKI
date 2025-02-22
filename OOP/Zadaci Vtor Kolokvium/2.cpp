#include <iostream>
#include <cstring>
using namespace std;

// vashiot kod ovde
class Vozac
{
protected:
    char ime[100];
    int vozrast;
    int brTrki;
    bool veteran;
public:
    Vozac(){}
    Vozac(char *ime,int vozrast,int brTrki,bool veteran)
    {
        strcpy(this->ime,ime);
        this->vozrast=vozrast;
        this->brTrki=brTrki;
        this->veteran=veteran;
    }
    friend ostream &operator<<(ostream &out,Vozac &v)
    {
        out<<v.ime<<endl;
        out<<v.vozrast<<endl;
        out<<v.brTrki<<endl;
        if(v.veteran==true)
        {
            out<<"VETERAN"<<endl;
        }
        return out;
    }
    bool operator==(const Vozac &v)
    {
        if(this->zarabotuvackaPoTrka()==v.zarabotuvackaPoTrka())return true;
        else
            return false;
    }
    virtual int zarabotuvackaPoTrka() const=0;
    virtual float danok() const=0;
};
class Avtomobilist : public Vozac
{
private:
    float cena;
public:
    Avtomobilist() {}
    Avtomobilist(char *ime,int vozrast,int brTrki,bool veteran,float cena):Vozac(ime,vozrast,brTrki,veteran)
    {
        this->cena=cena;
    }
    int zarabotuvackaPoTrka()const
    {
        return (cena/5);
    }
    float danok()const
    {
        if(this->brTrki>10)
        {
            return zarabotuvackaPoTrka()*0.15;
        }
        else
            return zarabotuvackaPoTrka()*0.10;
    }
};
class Motociklist:public Vozac
{
private:
    int moknost;
public:
    Motociklist() {}
    Motociklist(char *ime,int vozrast,int brTrki,bool veteran,int moknost):Vozac(ime,vozrast,brTrki,veteran)
    {
        this->moknost=moknost;
    }
    int zarabotuvackaPoTrka()const
    {
        return moknost*20;
    }
    float danok() const
    {
        if(veteran==true)
        {
            return zarabotuvackaPoTrka()*0.25;
        }
        else
            return zarabotuvackaPoTrka()*0.20;
    }
};
int soIstaZarabotuvachka(Vozac **v,int n,Vozac *vx) {
    int br=0;
    for(int i=0; i<n; i++){
        if(v[i]->zarabotuvackaPoTrka()==vx->zarabotuvackaPoTrka()){
            br++;
        }
    }
    return br;
}
int main()
{
    int n, x;
    cin >> n >> x;
    Vozac **v = new Vozac*[n];
    char ime[100];
    int vozrast;
    int trki;
    bool vet;
    for(int i = 0; i < n; ++i)
    {
        cin >> ime >> vozrast >> trki >> vet;
        if(i < x)
        {
            float cena_avto;
            cin >> cena_avto;
            v[i] = new Avtomobilist(ime, vozrast, trki, vet, cena_avto);
        }
        else
        {
            int mokjnost;
            cin >> mokjnost;
            v[i] = new Motociklist(ime, vozrast, trki, vet, mokjnost);
        }
    }
    cout << "=== DANOK ===" << endl;
    for(int i = 0; i < n; ++i)
    {
        cout << *v[i];
        cout << v[i]->danok() << endl;
    }
    cin >> ime >> vozrast >> trki >> vet;
    int mokjnost;
    cin >> mokjnost;
    Vozac *vx = new Motociklist(ime, vozrast, trki, vet, mokjnost);
    cout << "=== VOZAC X ===" << endl;
    cout << *vx;
    cout << "=== SO ISTA ZARABOTUVACKA KAKO VOZAC X ===" << endl;
    cout << soIstaZarabotuvachka(v, n, vx);
    for(int i = 0; i < n; ++i)
    {
        delete v[i];
    }
    delete [] v;
    delete vx;
    return 0;
}
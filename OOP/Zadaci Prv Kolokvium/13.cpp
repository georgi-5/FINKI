#include<iostream>
#include<string.h>
using namespace std;

//ова е место за вашиот код
class Zichara{
private:
    char *mesto;
    int cena;
public:
    Zichara(){
        this->mesto=new char[0];
        this->cena=0;
    }
    Zichara(char *mesto,int cena){
        this->mesto=new char[strlen(mesto)+1];
        strcpy(this->mesto,mesto);
        this->cena=cena;
    }
    Zichara& operator=(const Zichara &zc){
        if(this!=&zc){
        delete[] mesto;
        this->mesto=new char[strlen(zc.mesto)+1];
        strcpy(this->mesto,zc.mesto);
        this->cena=zc.cena;
        }
        return *this;
    }
    Zichara(const Zichara &zc){
        this->mesto=new char[strlen(zc.mesto)+1];
        strcpy(this->mesto,zc.mesto);
        this->cena=zc.cena;
    }
    int getCenaKarta(){
        return cena;
    }
    ~Zichara(){
    delete[] mesto;
    }
};
class PlaninarskiDom{
private:
    char ime[15];
    char klasa;
    int ceni[2];
    bool daliZc;
    Zichara *z;
public:
    PlaninarskiDom(){}
    PlaninarskiDom(char *ime,int *ceni,char klasa){
        strcpy(this->ime,ime);
        this->klasa=klasa;
        for(int i=0; i<2; i++){
            this->ceni[i]=ceni[i];
        }
        this->daliZc=daliZc;
        z=NULL;
    }

    PlaninarskiDom& operator--(){
        if(klasa<'F'){
            klasa++;
        }
        return *this;
    }
    friend ostream& operator<<(ostream &out,PlaninarskiDom &pd){
        out<<pd.ime<<" "<<"klasa:"<<pd.klasa;
        if(pd.daliZc==true){
            out<<" so Zichara";
        }
        out<<endl;
        return out;
    }
    bool operator<=(char klasa){
     return this->klasa >=klasa;
    }
    void presmetajDnevenPrestoj(int den,int mesec,int &cena){
        if(den>31 || den<1 || mesec<1 || mesec>12){
            throw 1;
        }
        if(daliZc){
            cena=z->getCenaKarta();
        }
        else
        {
            cena=0;
        }
        if(mesec>3 && mesec<9){
            cena+=ceni[0];
        }
        if(mesec<4 || mesec>8){
            cena+=ceni[1];
             }

    }
    void setZichara(Zichara &zc){
        this->z=&zc;

    }
    ~PlaninarskiDom(){}
};

int main(){

   PlaninarskiDom p; //креирање на нов објект од класата планинарски дом

   //во следниот дел се вчитуваат информации за планинарскиот дом
   char imePlaninarskiDom[15],mestoZichara[30],klasa;
   int ceni[12];
   int dnevnakartaZichara;
   bool daliZichara;
   cin>>imePlaninarskiDom;
   for (int i=0;i<2;i++) cin>>ceni[i];
   cin>>klasa;
   cin>>daliZichara;

   //во следниот дел се внесуваат информации и за жичарата ако постои
   if (daliZichara) {
      cin>>mestoZichara>>dnevnakartaZichara;
      PlaninarskiDom pom(imePlaninarskiDom,ceni,klasa);
      Zichara r(mestoZichara,dnevnakartaZichara);
      pom.setZichara(r);
      p=pom;
   }
   else{
      PlaninarskiDom *pok=new PlaninarskiDom(imePlaninarskiDom,ceni,klasa);
      p=*pok;
   }

   //се намалува класата на планинарскиот дом за 2
   --p;
   --p;

   int cena;
   int den,mesec;
   cin>>den>>mesec;
   try{
   p.presmetajDnevenPrestoj(den,mesec,cena); //тука се користи функцијата presmetajDnevenPrestoj
   cout<<"Informacii za PlaninarskiDomot:"<<endl;
   cout<<p;
   if (p<='D')
       cout<<"Planinarskiot dom za koj se vneseni informaciite ima klasa poniska ili ista so D\n";

   cout<<"Cenata za "<<den<<"."<<mesec<<" e "<<cena; //се печати цената за дадениот ден и месец
   }
   catch (int){
      cout<<"Mesecot ili denot e greshno vnesen!";
   }
}
#include <iostream>
#include <cstring>
using namespace std;
class Koncert{
private:
    char naziv[20];
    char lokacija[20];
    static float popust;
    float cenabilet;
public:
    Koncert(){}
    Koncert(char *naziv,char *lokacija,float cenabilet){
        strcpy(this->naziv,naziv);
        strcpy(this->lokacija,lokacija);
        this->popust=popust;
        this->cenabilet=cenabilet;
    }
    Koncert(const Koncert &k){
        strcpy(this->naziv,k.naziv);
        strcpy(this->lokacija,k.lokacija);
        this->popust=k.popust;
        this->cenabilet=k.cenabilet;
    }
     Koncert& operator=(const Koncert &k){
         if(this!=&k){
        strcpy(this->naziv,k.naziv);
        strcpy(this->lokacija,k.lokacija);
        this->popust=k.popust;
        this->cenabilet=k.cenabilet;
         }
         return *this;
    }
    static void setSezonskiPopust(float p){
        popust=p;
    }
    virtual float cena(){
        float nova=cenabilet;
        float procent=cenabilet*popust;
        nova-=procent;
        return nova;
        cout<<nova;
    }
    char* getNaziv(){
     return naziv;
    }
    float getCena(){
        return cenabilet;
    }
    float getProcent(){
        return popust;
    }
    virtual bool isElektronski(){
        return false;
    }
    ~Koncert(){}
};
class ElektronskiKoncert:public Koncert{
private:
    char *imeDj;
    float vremetraenje;
    bool dnevna;
public:
    ElektronskiKoncert(){
        this->imeDj=new char[0];
        vremetraenje=0;
    }
    ElektronskiKoncert(char *naziv,char *lokacija,float cenabilet,char *imeDj,float vremetraenje,bool dnevna):Koncert(naziv,lokacija,cenabilet){
            this->imeDj=new char[strlen(imeDj)+1];
            strcpy(this->imeDj,imeDj);
            this->vremetraenje=vremetraenje;
            this->dnevna=dnevna;
    }
    ~ElektronskiKoncert(){
        delete []imeDj;
    }
    float cena(){
        float nova=Koncert::cena();
        if(dnevna){
            nova-=50;
        }
        else
        {
            nova+=100;
        }
        if(vremetraenje>5.0 && vremetraenje <=7.0){
            nova+=150;
        }
        if(vremetraenje>7.0){
            nova+=360;
        }

        return nova;
    }
    float getSezonskiPopust(){
        return Koncert::getProcent();
    }
    bool isElektronski(){
        return true;
    }
};
void najskapKoncert(Koncert ** koncerti, int n){
    int max=0;
    int index=0;
    int brF=0,br=0;
    for(int i=0; i<n; i++){
        if(koncerti[i]->cena()>max){
            max=koncerti[i]->cena();
            index=i;
        }
    }
    ElektronskiKoncert *ek;
    for(int i=0; i<n; i++){
        if(ElektronskiKoncert *ek=dynamic_cast<ElektronskiKoncert *>(koncerti[i])){
            br++;
        }
        brF++;
    }
    cout<<"Najskap koncert: "<<koncerti[index]->getNaziv()<<" "<<koncerti[index]->cena()<<endl;
    cout<<"Elektronski koncerti: "<<br<<" od vkupno "<<brF<<endl;
}
bool prebarajKoncert(Koncert ** koncerti, int n, char * naziv, bool elektronski){
    if(elektronski){
    for(int i=0; i<n; i++){
        if(ElektronskiKoncert *ek=dynamic_cast<ElektronskiKoncert *>(koncerti[i])){
            if(strcmp(koncerti[i]->getNaziv(),naziv)==0){
                cout<<koncerti[i]->getNaziv()<<" "<<koncerti[i]->cena()<<endl;
                return true;
            }
        }
    }
    }
    else{
        for(int i=0; i<n; i++){
        if(strcmp(koncerti[i]->getNaziv(),naziv)==0){
            cout<<koncerti[i]->getNaziv()<<" "<<koncerti[i]->cena()<<endl;
                return true;
        }
    }
    }
    
        return false;
}
float Koncert::popust=0.2;
int main(){

    int tip,n,novaCena;
    char naziv[100], lokacija[100], imeDJ[40];
    bool dnevna;
    float cenaBilet, novPopust;
    float casovi;

        cin>>tip;
        if (tip==1){//Koncert
        	cin>>naziv>>lokacija>>cenaBilet;
        	Koncert k1(naziv,lokacija,cenaBilet);
        	cout<<"Kreiran e koncert so naziv: "<<k1.getNaziv()<<endl;
        }
        else if (tip==2){//cena - Koncert
            cin>>naziv>>lokacija>>cenaBilet;
        	Koncert k1(naziv,lokacija,cenaBilet);
        	cout<<"Osnovna cena na koncertot so naziv "<<k1.getNaziv()<< " e: " <<k1.cena()<<endl;
        }
        else if (tip==3){//ElektronskiKoncert
            cin>>naziv>>lokacija>>cenaBilet>>imeDJ>>casovi>>dnevna;
            ElektronskiKoncert s(naziv,lokacija,cenaBilet,imeDJ,casovi,dnevna);
            cout<<"Kreiran e elektronski koncert so naziv "<<s.getNaziv()<<" i sezonskiPopust "<<s.getSezonskiPopust()<<endl;
        }
        else if (tip==4){//cena - ElektronskiKoncert
             cin>>naziv>>lokacija>>cenaBilet>>imeDJ>>casovi>>dnevna;
             ElektronskiKoncert s(naziv,lokacija,cenaBilet,imeDJ,casovi,dnevna);
             cout<<"Cenata na elektronskiot koncert so naziv "<<s.getNaziv()<<" e: "<<s.cena()<<endl;
        }
        else if (tip==5) {//najskapKoncert

        }
        else if (tip==6) {//prebarajKoncert
            Koncert ** koncerti = new Koncert *[5];
            int n;
            koncerti[0] = new Koncert("Area","BorisTrajkovski",350);
            koncerti[1] = new ElektronskiKoncert("TomorrowLand","Belgium",8000,"Afrojack",7.5,false);
            koncerti[2] = new ElektronskiKoncert("SeaDance","Budva",9100,"Tiesto",5,true);
            koncerti[3] = new Koncert("Superhiks","PlatoUkim",100);
            koncerti[4] = new ElektronskiKoncert("CavoParadiso","Mykonos",8800,"Guetta",3,true);
            char naziv[100];
        	najskapKoncert(koncerti,5);
        }
        else if (tip==7){//prebaraj
        	  Koncert ** koncerti = new Koncert *[5];
            int n;
            koncerti[0] = new Koncert("Area","BorisTrajkovski",350);
            koncerti[1] = new ElektronskiKoncert("TomorrowLand","Belgium",8000,"Afrojack",7.5,false);
            koncerti[2] = new ElektronskiKoncert("SeaDance","Budva",9100,"Tiesto",5,true);
            koncerti[3] = new Koncert("Superhiks","PlatoUkim",100);
            koncerti[4] = new ElektronskiKoncert("CavoParadiso","Mykonos",8800,"Guetta",3,true);
            char naziv[100];
            bool elektronski;
        	cin>>elektronski;
        	if(prebarajKoncert(koncerti,5, "Area",elektronski))
                cout<<"Pronajden"<<endl;
            else cout<<"Ne e pronajden"<<endl;

            if(prebarajKoncert(koncerti,5, "Area",!elektronski))
                cout<<"Pronajden"<<endl;
            else cout<<"Ne e pronajden"<<endl;

        }
        else if (tip==8){//smeni cena
        	  Koncert ** koncerti = new Koncert *[5];
            int n;
            koncerti[0] = new Koncert("Area","BorisTrajkovski",350);
            koncerti[1] = new ElektronskiKoncert("TomorrowLand","Belgium",8000,"Afrojack",7.5,false);
            koncerti[2] = new ElektronskiKoncert("SeaDance","Budva",9100,"Tiesto",5,true);
            koncerti[3] = new Koncert("Superhiks","PlatoUkim",100);
            koncerti[2] -> setSezonskiPopust(0.9);
        	najskapKoncert(koncerti,4);
        }

    return 0;
}
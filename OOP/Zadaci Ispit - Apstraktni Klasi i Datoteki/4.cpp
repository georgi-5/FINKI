#include <iostream>
#include <cstring>
#include <climits>
#include <float.h>
using namespace std;

//Your code here
class Museum {
protected:
    string ime;
    string grad;
    float cena;
    int casovi;
public:
    Museum(){}
    Museum(string ime,string grad,float cena,int casovi) {
        this->ime=ime;
        this->grad=grad;
        this->cena=cena;
        this->casovi=casovi;
    }
    Museum(const Museum &m) {
        this->ime=m.ime;
        this->grad=m.grad;
        this->cena=m.cena;
        this->casovi=m.casovi;
    }
    Museum& operator=(const Museum &m) {
        if(this!=&m) {
            this->ime=m.ime;
            this->grad=m.grad;
            this->cena=m.cena;
            this->casovi=m.casovi;
        }
        return *this;
    }
    float getCena() {
        return cena;
    }
    int getCasovi() {
        return casovi;
    }
    virtual double calculateTicketCost()=0;
    virtual void printDetail() {
        cout<<ime<<" "<<grad;
    };
    ~Museum(){}
};
class ScientificMuseum:public Museum {
private:
    bool interaktivni;
    int x;
public:
    ScientificMuseum(){}
    ScientificMuseum(string ime,string grad,float cena,int casovi,bool interaktivni,int x):Museum(ime,grad,cena,casovi) {
            this->interaktivni=interaktivni;
            this->x=x;
    }
    double calculateTicketCost() override {
        float cena2=cena;
        if(interaktivni) {
            float procent=cena2*0.12;
            cena2+=procent;
        }
        for(int i=0; i<x; i++) {
            cena2+=6;
        }
        return cena2;
    }
    void printDetail() {
        cout<<ime<<" - (Scientific) "<<grad<<" "<<x<<" "<<calculateTicketCost()<<endl;
    }
};
class ArtMuseum:public Museum{
private:
    bool amaterski;
    int y;
public:
    ArtMuseum(){}
    ArtMuseum(string ime,string grad,float cena,int casovi,bool amaterski,int y):Museum(ime,grad,cena,casovi) {
        this->amaterski=amaterski;
        this->y=y;
    }
    double calculateTicketCost() override {
        float cena2=cena;
        if(amaterski) {
            float procent=cena2*0.18;
            cena2-=procent;
        }
        for(int i=0; i<y; i++) {
            cena2+=3;
        }
        return cena2;
    }
    int br() {
        int br1=0;
        if(amaterski) {
            br1++;
        }
        return br1;
    }
    void printDetail() override {
        cout<<ime<<" - (Art) "<<grad<<" "<<br()<<" "<<calculateTicketCost()<<endl;
    }
};
int findCheapestScientificMuseum(Museum **m, int n) {
    if(n==0) {
        return -1;
    }
    float min=FLT_MAX;
    int index=-1;
    int max=INT_MIN;
    int indexJ=-1;
    for(int i=0; i<n; i++) {
        ScientificMuseum *niza=dynamic_cast<ScientificMuseum *>(m[i]);
        if(niza!=nullptr) {
            if(max<niza->getCasovi()) {
                max=niza->getCasovi();
                indexJ=i;
            }
        }
    }
    for(int i=0; i<n; i++) {
        ScientificMuseum *niza=dynamic_cast<ScientificMuseum *>(m[i]);
        if(niza!=nullptr) {
            if(niza->getCena()<min) {
                min=niza->getCena();
                index=i;
            }
            else if(min==niza->getCena()) {
                index=indexJ;
            }
        }

    }
    return index;
}
int main() {
    int n, testCase, type;
    cin >> testCase >> n;
    cin.ignore();

    Museum** m = new Museum*[n];

    for (int i = 0; i < n; ++i) {
        string name;
        string city;
        float base_price;
        int working_hours;

        cin >> type;
        cin.ignore();
        getline(cin, name);
        getline(cin, city);
        cin >> base_price;
        cin.ignore();
        cin >> working_hours;
        cin.ignore();

        if (type == 1) {
            bool interactive_shows;
            int multimedia_pres;

            cin >> interactive_shows >> multimedia_pres;
            cin.ignore();

            m[i] = new ScientificMuseum(name, city, base_price, working_hours, interactive_shows, multimedia_pres);
        } else {
            bool amateur_shows;
            int original_artwork;

            cin >> amateur_shows >> original_artwork;
            cin.ignore();

            m[i] = new ArtMuseum(name, city, base_price, working_hours, amateur_shows, original_artwork);
        }
    }

    if(testCase == 1){
        cout << "Abstract and child classes OK" << endl;
    }
    else if(testCase == 2){
        for(int i = 0; i < n; i++){
            cout << m[i]->calculateTicketCost() << endl;
        }
        cout << "calculateTicketCost method OK" << endl;
    }
    else if(testCase == 3){
        for(int i = 0; i < n; i++){
            m[i]->printDetail();
        }
        cout << "printDetail method OK" << endl;
    }
    else if(testCase == 4){
        int cheapest_sci_museum_index = findCheapestScientificMuseum(m, n);
        if(cheapest_sci_museum_index>=0){
            m[cheapest_sci_museum_index]->printDetail();
        }else{
            cout << "Scientific Museum not found in the array!"<<endl;
        }
        cout << "findCheapestOnlineOrder method OK" << endl;
    }


    for (int i = 0; i < n; ++i) {
        delete m[i];
    }

    delete[] m;

    return 0;
}
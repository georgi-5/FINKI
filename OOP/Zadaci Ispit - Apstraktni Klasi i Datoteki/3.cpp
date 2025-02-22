#include <iostream>

using namespace std;

//Your code here
class Library {
protected:
    string ime;
    string grad;
    float cena;
    bool vikend;
public:
    Library(){}
    Library(string ime,string grad,float cena,bool vikend) {
        this->ime=ime;
        this->grad=grad;
        this->cena=cena;
        this->vikend=vikend;
    }
    Library(const Library &l) {
        this->ime=l.ime;
        this->grad=l.grad;
        this->cena=l.cena;
        this->vikend=l.vikend;
    }
    Library& operator=(const Library &l) {
        if(this!=&l) {
            this->ime=l.ime;
            this->grad=l.grad;
            this->cena=l.cena;
            this->vikend=l.vikend;
        }
        return *this;
    }
    bool getVikend() {
        return vikend;
    }
    virtual double calculateMembershipCardCost()=0;
    virtual void printDetail() {
    }
    ~Library(){}

};
class AcademicLibrary:public Library {
private:
    bool istrazuvanje;
    int speCol;
public:
    AcademicLibrary(){}
    AcademicLibrary(string ime,string grad,float cena,bool vikend,bool istrazuvanje,int speCol):Library(ime,grad,cena,vikend) {
        this->istrazuvanje=istrazuvanje;
        this->speCol=speCol;
    }
    double calculateMembershipCardCost() override {
        float cena2=cena;
        if(istrazuvanje) {
            float procent=cena2*0.24;
            cena2+=procent;
        }

        for(int i=0; i<speCol; i++) {
            cena2+=6;
        }
        return cena2;
    }
    void printDetail() {
        cout<<ime<<" - (Academic) "<<grad<<" ";
        cout<<speCol<<" "<<calculateMembershipCardCost()<<endl;
    }
};
class NationalLibrary:public Library {
private:
    bool edukativni;
    int rakopisi;
public:
    NationalLibrary(){}
    NationalLibrary(string ime,string grad,float cena,bool vikend,bool edukativni,int rakopisi):Library(ime,grad,cena,vikend) {
        this->edukativni=edukativni;
        this->rakopisi=rakopisi;
    }
    double calculateMembershipCardCost() override {
        float cena2=cena;
        if(edukativni) {
            float procent=cena2*0.07;
            cena2-=procent;
        }
        for(int i=0; i<rakopisi; i++) {
            cena2+=15;
        }
        return cena2;
    }
    void printDetail() {
        cout<<ime<<" - (National) "<<grad<<" ";
        cout<<rakopisi<<" "<<calculateMembershipCardCost()<<endl;
    }
};
int findMostExpensiveNationalLibrary(Library **l, int n) {
    int index=-1;
    float max=0;

    for(int i=0; i<n; i++) {
        NationalLibrary *niza=dynamic_cast<NationalLibrary *>(l[i]);
        if(niza) {
            if(niza->calculateMembershipCardCost()>max) {
                max=niza->calculateMembershipCardCost();
                index=i;
            }
            if (niza->calculateMembershipCardCost()==max && niza->getVikend()) {
                max=niza->calculateMembershipCardCost();
                index=i;
            }
        }
    }

    return index;

}
int main() {
    int n, testCase, type;
    cin >> testCase >> n;
    cin.ignore();

    Library** m = new Library*[n];

    for (int i = 0; i < n; ++i) {
        string name;
        string city;
        float base_price;
        bool weekend_working;

        cin >> type;
        cin.ignore();
        getline(cin, name);
        getline(cin, city);
        cin >> base_price;
        cin.ignore();
        cin >> weekend_working;
        cin.ignore();

        if (type == 1) {
            bool open_cooperation;
            int specialized_articles;

            cin >> open_cooperation >> specialized_articles;
            cin.ignore();

            m[i] = new AcademicLibrary(name, city, base_price, weekend_working, open_cooperation, specialized_articles);
        } else {
            bool cultural_program;
            int national_articles;

            cin >> cultural_program >> national_articles;
            cin.ignore();

            m[i] = new NationalLibrary(name, city, base_price, weekend_working, cultural_program, national_articles);
        }
    }

    if(testCase == 1){
        cout << "Abstract and child classes OK" << endl;
    }
    else if(testCase == 2){
        for(int i = 0; i < n; i++){
            cout << m[i]->calculateMembershipCardCost() << endl;
        }
        cout << "calculateMembershipCardCost method OK" << endl;
    }
    else if(testCase == 3){
        for(int i = 0; i < n; i++){
            m[i]->printDetail();
        }
        cout << "printDetail method OK" << endl;
    }
    else if(testCase == 4){
        int most_expensive_nat_lib_index = findMostExpensiveNationalLibrary(m, n);
        if(most_expensive_nat_lib_index>=0){
            m[most_expensive_nat_lib_index]->printDetail();
        }else{
            cout << "National Library not found in the array!"<<endl;
        }
        cout << "findMostExpensiveNationalLibrary method OK" << endl;
    }


    for (int i = 0; i < n; ++i) {
        delete m[i];
    }

    delete[] m;

    return 0;
}
#include <iostream>
#include <cstring>
using namespace std;

class IceCream{
private:
    char *ime;
    char sostav[100];
    float cena;
    int popust;
public:
    IceCream(){
    this->ime=nullptr;
    this->cena=0;
    this->popust=0;
    }
    IceCream(const char *ime,const char *sostav,float cena,int popust=0){
        this->ime=new char[strlen(ime)+1];
        strcpy(this->ime,ime);
        strcpy(this->sostav,sostav);
        this->cena=cena;
        this->popust=popust;
    }
    IceCream(const IceCream &ic){
        this->ime=new char[strlen(ic.ime)+1];
        strcpy(this->ime,ic.ime);
        strcpy(this->sostav,ic.sostav);
        this->cena=ic.cena;
        this->popust=ic.popust;
    }
    IceCream& operator=(const IceCream &ic){
        if(this!=&ic){
        delete []ime;
        this->ime=new char[strlen(ic.ime)+1];
        strcpy(this->ime,ic.ime);
        strcpy(this->sostav,ic.sostav);
        this->cena=ic.cena;
        this->popust=ic.popust; }
        return *this;
    }

    ~IceCream(){
        delete []ime;
    }
    friend ostream& operator<<(ostream &out,const IceCream &ic){
        out<<ic.ime<<": ";
        out<<ic.sostav<<" ";
        out<<ic.cena<<" "   ;
        if(ic.popust>0){
            out<<"("<<ic.cena*(100-ic.popust)/100<<")";
        }
        return out;
    }
    void setDiscount(int popust){
        this->popust=popust;
    }
    IceCream& operator++(){
        popust+=5;
        return *this;
    }
    IceCream operator+(const char *ic) const{
        int novaDolz=strlen(ime)+strlen(" + ")+strlen(ic)+1;
        char *novoIme=new char[novaDolz];
        strcpy(novoIme,ime);
        strcat(novoIme," + ");
        strcat(novoIme,ic);
        double novaCena=cena+10.0;
        IceCream novSladoled(novoIme,sostav,novaCena,popust);
        delete []novoIme;
        return novSladoled;
    }
    void setName(const char* ime){
        delete []this->ime;
        this->ime=new char[strlen(ime)+1];
        strcpy(this->ime,ime);
    }
};
class IceCreamShop{
private:
    char ime[50];
    IceCream *ic;
    int n;
public:
    IceCreamShop(){
        ic=nullptr;
        n=0;
    }
    IceCreamShop(const char *ime){
        strcpy(this->ime,ime);
        ic=nullptr;
        n=0;
    }
    IceCreamShop(const IceCreamShop &ics){
        strcpy(this->ime,ics.ime);
        n=ics.n;
        if(ics.ic!=nullptr){
            ic=new IceCream[ics.n];
            for(int i=0; i<ics.n; i++){
                ic[i]=ics.ic[i];
            }
        }
        else
        {
            ic=nullptr;
        }
    }

    IceCreamShop& operator=(const IceCreamShop &ics){
        if(this!=&ics){
            delete[] ic;
        strcpy(this->ime,ics.ime);
        n=ics.n;
        if(ics.ic!=nullptr){
            ic=new IceCream[ics.n];
            for(int i=0; i<ics.n; i++){
                ic[i]=ics.ic[i];
            }
        }
        else
        {
            ic=nullptr;
        }
        }
        return *this;
    }
    ~IceCreamShop(){
    delete []ic;
    }
    IceCreamShop& operator+=(const IceCream &iceCream) {
        IceCream *newArray = new IceCream[n + 1];
        for (int i = 0; i < n; ++i) {
            newArray[i] = ic[i];
        }
        newArray[n] = iceCream;
        ++n;
        delete[] ic;
        ic = newArray;

        return *this;
    }
    friend ostream& operator<<(ostream &out,const IceCreamShop &ics){
        out<<ics.ime<<endl;
        for(int i=0; i<ics.n; i++){
            out<<ics.ic[i]<<endl;
        }
        return out;
    }

};
int main() {
    char name[100];
    char ingr[100];
    float price;
    int discount;

    int testCase;

    cin >> testCase;
	cin.get();
    if(testCase == 1) {
        cout << "====== TESTING IceCream CLASS ======" << endl;
        cin.getline(name,100);
        cin.getline(ingr,100);
        cin >> price;
        cin >> discount;
        cout << "CONSTRUCTOR" << endl;
        IceCream ic1(name, ingr, price);
        ic1.setDiscount(discount);
        cin.get();
        cin.getline(name,100);
        cin.getline(ingr,100);
        cin >> price;
        cin >> discount;
        IceCream ic2(name, ingr, price);
        ic2.setDiscount(discount);
        cout << "OPERATOR <<" << endl;
        cout << ic1 << endl;
        cout << ic2 << endl;
        cout << "OPERATOR ++" << endl;
        ++ic1;
        cout << ic1 << endl;
        cout << "OPERATOR +" << endl;
        IceCream ic3 = ic2 + "chocolate";
        cout << ic3 << endl;
    } else if(testCase == 2) {
        cout << "====== TESTING IceCream CONSTRUCTORS ======" << endl;
        cin.getline(name,100);
        cin.getline(ingr,100);
        cin >> price;
        cout << "CONSTRUCTOR" << endl;
        IceCream ic1(name, ingr, price);
        cout << ic1 << endl;
        cout << "COPY CONSTRUCTOR" << endl;
        IceCream ic2(ic1);
        cin.get();
        cin.getline(name,100);
        ic2.setName(name);
        cout << ic1 << endl;
        cout << ic2 << endl;
        cout << "OPERATOR =" << endl;
        ic1 = ic2;
        cin.getline(name,100);
        ic2.setName(name);
        cout << ic1 << endl;
        cout << ic2 << endl;

        cin >> discount;
        ic1.setDiscount(discount);


    }
    else if(testCase == 3) {
        cout << "====== TESTING IceCreamShop ======" << endl;
        char icsName[50];
        cin.getline(icsName,100);
        cout << "CONSTRUCTOR" << endl;
        IceCreamShop ics(icsName);
        int n;
        cin >> n;
        cout << "OPERATOR +=" << endl;
        for(int i = 0; i < n; ++i) {
            cin.get();
            cin.getline(name,100);
        	cin.getline(ingr,100);
            cin >> price;
            IceCream ic(name, ingr, price);
            ics += ic;
        }
        cout << ics;
    }
     else if(testCase == 4) {
        cout << "====== TESTING IceCreamShop CONSTRUCTORS ======" << endl;
        char icsName[50];
        cin.getline(icsName,100);
        IceCreamShop ics(icsName);
        int n;
        cin >> n;
        for(int i = 0; i < n; ++i) {
            cin.get();
            cin.getline(name,100);
        	cin.getline(ingr,100);
            cin >> price;
            IceCream ic(name, ingr, price);
            ics += ic;
        }
        IceCream x("FINKI fruits", "strawberry ice cream, raspberry ice cream, blueberry ice cream", 60);
        IceCreamShop icp = ics;
        ics+=x;
        cout << ics << endl;
        cout << icp << endl;
    }
//

    return 0;
}
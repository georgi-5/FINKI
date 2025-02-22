#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;
class NoProductFoundException{
private:
    string msg;
public:
    NoProductFoundException(string msg){
        this->msg=msg;
    }
    void message(){
        cout<<msg<<endl;
    }
};
class Product {
private:
    string ime;
    string kategorija;
    int cena;
    int kolicina;
public:
    Product(){}
    Product(string ime,string kategorija,int cena,int kolicina){
        this->ime=ime;
        this->kategorija=kategorija;
        this->cena=cena;
        this->kolicina=kolicina;
    }
    Product(const Product &p){
        this->ime=p.ime;
        this->kategorija=p.kategorija;
        this->cena=p.cena;
        this->kolicina=p.kolicina;
    }
    Product& operator=(const Product &p){
        if(this!=&p){
        this->ime=p.ime;
        this->kategorija=p.kategorija;
        this->cena=p.cena;
        this->kolicina=p.kolicina;
        }
        return *this;
    }
    string getKat(){
        return kategorija;
    }

    int totalPrice(){
        return cena*kolicina;
    }
    friend ostream& operator<<(ostream &out,Product &p){
        out<<p.ime<<" ("<<p.kategorija<<")"<<" "<<p.kolicina<<" x "<<p.cena<<" = "<<p.totalPrice()<<endl;
    }
};
class Store{
private:
    int n;
    Product *products;
public:
    Store(){
        this->products=new Product[0];
        n=0;
    }
    Store(Product *products,int n){
        this->n=n;
        this->products=new Product[n];
        for(int i=0; i<n; i++){
            this->products[i]=products[i];
        }
    }
    Store(const Store &s){
        this->n=s.n;
        this->products=new Product[s.n];
        for(int i=0; i<s.n; i++){
            this->products[i]=s.products[i];
        }
    }
    Store& operator=(const Store &s){
        if(this!=&s){
            delete []products;
        this->n=s.n;
        this->products=new Product[s.n];
        for(int i=0; i<s.n; i++){
            this->products[i]=s.products[i];
        }
        }
        return *this;
    }
    Store& operator+=(Product &p){
        Product *temp=new Product[n+1];
        for(int i=0; i<n; i++){
            temp[i]=products[i];
        }
        temp[n++]=p;
        delete []products;
        products=temp;
        return *this;
    }

    Store fromCategory (string & category){
        Store newStore;
        for(int i=0; i<n; i++){
            if(products[i].getKat()==category){
                newStore+=products[i];
            }
        }
        if(newStore.n==0){
            throw NoProductFoundException("No products from category "+category+" were found in the store");
        }
        return newStore;
    }
     friend ostream& operator<<(ostream &out,Store &s){
        for(int i=0; i<s.n; i++){
            out<<s.products[i];
        }
    }
    ~Store(){
        delete []products;
    }
};
void wtf() {
    ofstream fout("input.txt");
    string line;
    while (getline(std::cin, line)) {
        if (line == "----") {
            break;
        }
        fout << line << endl;
    }
}

void rff(string path) {
    ifstream fin(path);
    string line;
    while (getline(fin, line)) {
        cout << line << endl;
    }
}


int main() {
    // Write to input.txt from standard input
    wtf();

    // Create a Store object
    Store s;

    // Read the products from the file and add them to the store `s`
    ifstream isf("input.txt");
    if (!isf.is_open()) {
        cerr << "Failed to open input.txt" << endl;
        return 1;
    }

    string ime, kategorija;
    int cena, kolicina;

    while (getline(isf, ime)) {
        if (ime.empty()) continue;

        getline(isf, kategorija);
        isf >> cena;
        isf >> kolicina;
        isf.ignore();

        Product p(ime, kategorija, cena, kolicina);
        s += p;
    }

    isf.close();

    // Write all products to output1.txt
    ofstream of1("output1.txt");
    if (!of1.is_open()) {
        cerr << "Failed to open output1.txt" << endl;
        return 1;
    }
    of1 << s;
    of1.close();

    // DO NOT MODIFY THE CODE BETWEEN THIS AND THE NEXT COMMENT
    string category;
    cin >> category;
    // DO NOT MODIFY THE CODE BETWEEN THIS AND THE PREVIOUS COMMENT

    // Save the results in the file output2.txt
    ofstream of2("output2.txt");
    if (!of2.is_open()) {
        cerr << "Failed to open output2.txt" << endl;
        return 1;
    }
    try {
        Store categoryStore = s.fromCategory(category);
        of2 << categoryStore;
    } catch (NoProductFoundException& e) {
        e.message();

    }
    of2.close();

    // DO NOT MODIFY THE CODE BELOW
    cout << "All products:" << endl;
    rff("output1.txt");
    cout << "Products from category " << category << ": " << endl;
    rff("output2.txt");

    return 0;
}

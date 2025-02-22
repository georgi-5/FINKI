#include <iostream>
#define MAX 100
#include <cstring>
enum typeC{STANDARD,LOYAL,VIP};
using namespace std;
class UserExistsException{
private:
    string msg;
public:
    UserExistsException(string msg){
        this->msg=msg;
    }
    void message(){
        cout<<msg<<endl;
    }
};
class Customer{
private:
    char ime[50];
    char email[50];
    typeC tip;
    int popust;
    static int dPopust;
    int brKupeni;
public:
    Customer(){}
    Customer(char *ime,char *email,typeC tip,int brKupeni){
        strcpy(this->ime,ime);
        strcpy(this->email,email);
        this->tip=tip;
        this->popust=10;
        this->brKupeni=brKupeni;
        dPopust=popust+20;
    }
    Customer(const Customer &c){
        strcpy(this->ime,c.ime);
        strcpy(this->email,c.email);
        this->tip=c.tip;
        this->popust=c.popust;
        this->brKupeni=c.brKupeni;
    }
    Customer& operator=(const Customer &c){
        if(this!=&c){
        strcpy(this->ime,c.ime);
        strcpy(this->email,c.email);
        this->tip=c.tip;
        this->popust=c.popust;
        this->brKupeni=c.brKupeni;
        }
        return *this;
    }
    string kojtip(typeC tip){
        string line;
        switch(tip){
    case STANDARD:
            line="standard";
            break;
    case LOYAL:
            line="loyal";
            break;
    case VIP:
            line="vip";
            break;
        }
        return line;
    }
    int kojpopust(){
        int popust2;
        switch(tip){
    case STANDARD:
        popust2=0;
        break;
    case LOYAL:
        popust2=popust;
        break;
    case VIP:
        popust2=dPopust;
        break;
        }
        return popust2;
    }
    void setDiscount1(int popust){
        this->popust=popust;
    }
    friend ostream& operator<<(ostream &out,Customer &cs){
        out<<cs.ime<<endl;
        out<<cs.email<<endl;
        out<<cs.brKupeni<<endl;
        if(cs.tip==STANDARD){
            out<<cs.kojtip(cs.tip)<<" "<<cs.kojpopust()<<endl;
        }
        else if(cs.tip==LOYAL){
            out<<cs.kojtip(cs.tip)<<" "<<cs.kojpopust()<<endl;
        }
       else if(cs.tip==VIP){
            out<<cs.kojtip(cs.tip)<<" "<<cs.kojpopust()<<endl;
        }
        return out;
    }
    char* getEmail(){
        return email;
    }
    int getKupeni(){
        return brKupeni;
    }
    int getPopust(){
        return popust;
    }
    void setTip(typeC tip){
        this->tip=tip;
    }
    typeC getTip(){
        return tip;
    }
};
class FINKI_bookstore{
private:
    Customer *cs;
    int n;
public:
        FINKI_bookstore(){
        this->cs=new Customer[0];
        this->n=0;
    }
    FINKI_bookstore(Customer *cs,int n){
        this->cs=new Customer[n];
        for(int i=0; i<n; i++){
            this->cs[i]=cs[i];
        }
        this->n=n;
    }
    FINKI_bookstore(const FINKI_bookstore &fb){
        this->cs=new Customer[fb.n];
        for(int i=0; i<fb.n; i++){
            this->cs[i]=fb.cs[i];
        }
        this->n=fb.n;
    }
    FINKI_bookstore& operator=(const FINKI_bookstore &fb){
        if(this!=&fb){
        delete []this->cs;
        this->cs=new Customer[fb.n];
        for(int i=0; i<n; i++){
            this->cs[i]=fb.cs[i];
        }
        this->n=fb.n;
        }
        return *this;
    }

    void operator+=( Customer &c){
        for(int i=0; i<n; i++){
            if(strcmp(cs[i].getEmail(),c.getEmail())==0){
                throw UserExistsException("The user already exists in the list!");
            }
        }
        Customer *temp=new Customer[n+1];
        for(int i=0; i<n; i++){
            temp[i]=cs[i];
        }
        temp[n]=c;
        delete []cs;
        cs=temp;
        ++n;
    }
    void setCustomers(Customer *cs,int n){
        delete []this->cs;
        this->cs=new Customer[n];
        for(int i=0; i<n; i++){
            this->cs[i]=cs[i];
        }
        this->n=n;
    }
    friend ostream& operator<<(ostream &out,FINKI_bookstore &fb){
        for(int i=0; i<fb.n; i++){
            out<<fb.cs[i];

        }
        return out;
    }
    void update(){
        for(int i=0; i<n; i++){
            if(cs[i].getTip()==LOYAL && cs[i].getKupeni()>10){
                cs[i].setTip(VIP);
            }
            if(cs[i].getTip()==STANDARD && cs[i].getKupeni()>5){
                cs[i].setTip(LOYAL);
            }

        }
    }
    ~FINKI_bookstore(){
        delete []cs;
    }
};
int Customer::dPopust=0;
int main(){
  int testCase;
  cin >> testCase;

  char name[MAX];
  char email[MAX];
  int tC;
  int discount;
  int numProducts;


  if (testCase == 1){
    cout << "===== Test Case - Customer Class ======" << endl;
    cin.get();
    cin.getline(name,MAX);
    cin.getline(email,MAX);
    cin >> tC;
    cin >> numProducts;
    cout << "===== CONSTRUCTOR ======" << endl;
    Customer c(name, email, (typeC) tC, numProducts);
    cout << c;

  }

  if (testCase == 2){
    cout << "===== Test Case - Static Members ======" << endl;
    cin.get();
    cin.getline(name,MAX);
    cin.getline(email,MAX);
    cin >> tC;
    cin >> numProducts;
    cout << "===== CONSTRUCTOR ======" << endl;
    Customer c(name, email, (typeC) tC, numProducts);
    cout << c;

    c.setDiscount1(5);

    cout << c;
  }

  if (testCase == 3){
    cout << "===== Test Case - FINKI-bookstore ======" << endl;
    FINKI_bookstore fc;
    int n;
    cin >> n;
    Customer customers[MAX];
    for(int i = 0; i < n; ++i) {
      cin.get();
      cin.getline(name,MAX);
      cin.getline(email,MAX);
      cin >> tC;
      cin >> numProducts;
      Customer c(name, email, (typeC) tC, numProducts);
      customers[i] = c;
    }

    fc.setCustomers(customers, n);

    cout << fc <<endl;
  }

  if (testCase == 4){
    cout << "===== Test Case - operator+= ======" << endl;
    FINKI_bookstore fc;
    int n;
    cin >> n;
    Customer customers[MAX];
    for(int i = 0; i < n; ++i) {
      cin.get();
      cin.getline(name,MAX);
      cin.getline(email,MAX);
      cin >> tC;
      cin >> numProducts;
      Customer c(name, email, (typeC) tC, numProducts);
      customers[i] = c;
    }

    fc.setCustomers(customers, n);
    cout << "OPERATOR +=" << endl;
    cin.get();
    cin.getline(name,MAX);
    cin.getline(email,MAX);
    cin >> tC;
    cin >> numProducts;
    Customer c(name, email, (typeC) tC, numProducts);
    fc+=c;

    cout << fc;
  }

  if (testCase == 5){
    cout << "===== Test Case - operator+= (exception) ======" << endl;
    FINKI_bookstore fc;
    int n;
    cin >> n;
    Customer customers[MAX];
    for(int i = 0; i < n; ++i) {
      cin.get();
      cin.getline(name,MAX);
      cin.getline(email,MAX);
      cin >> tC;
      cin >> numProducts;
      Customer c(name, email, (typeC) tC, numProducts);
      customers[i] = c;
    }
    try{
    fc.setCustomers(customers, n);
    cout << "OPERATOR +=" << endl;
    cin.get();
    cin.getline(name,MAX);
    cin.getline(email,MAX);
    cin >> tC;
    cin >> numProducts;
    Customer c(name, email, (typeC) tC, numProducts);
    fc+=c;
    }catch (UserExistsException &e){
        e.message();
    }
    cout << fc;
  }

  if (testCase == 6){
    cout << "===== Test Case - update method  ======" << endl << endl;
    FINKI_bookstore fc;
    int n;
    cin >> n;
    Customer customers[MAX];
    for(int i = 0; i < n; ++i) {
      cin.get();
      cin.getline(name,MAX);
      cin.getline(email,MAX);
      cin >> tC;
      cin >> numProducts;
      Customer c(name, email, (typeC) tC, numProducts);
      customers[i] = c;
    }

    fc.setCustomers(customers, n);

    cout << "Update:" << endl;
    fc.update();
    cout << fc;
  }
  return 0;

}
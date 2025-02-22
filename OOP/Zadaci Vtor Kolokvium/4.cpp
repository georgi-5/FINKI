#include <cstring>
#include <iostream>
using namespace std;
enum Size{MALA,GOLEMA,FAMILIJARNA,UNKNOWN};
// Your Code goes here
class Pizza{
protected:
    char ime[20];
    char sosotjki[100];
    float cena;
    Size tip;
    bool belo;
public:
    Pizza(){
    }
    Pizza(char *ime,char *sosotjki,float cena){
        strcpy(this->ime,ime);
        strcpy(this->sosotjki,sosotjki);
        this->cena=cena;
        this->tip=tip;

    }
    Pizza(const Pizza &p){
        strcpy(this->ime,p.ime);
        strcpy(this->sosotjki,p.sosotjki);
        this->cena=p.cena;
         this->tip=p.tip;
        this->belo=p.belo;
    }
    string tipce(Size tip){
    string kojtip;
    switch(tip){
    case(MALA):
        kojtip="small";
        break;
    case(GOLEMA):
    kojtip="big";
    break;
    case(FAMILIJARNA):
        kojtip="family";
        break;
    }
    return kojtip;
    }
    Pizza& operator=(const Pizza &p){
        if(this!=&p){
        strcpy(this->ime,p.ime);
        strcpy(this->sosotjki,p.sosotjki);
        this->cena=p.cena;
        this->tip=p.tip;
        this->belo=p.belo;
        }
    }
    bool operator<(Pizza &p){
     return this->price()<p.price();
    }
    virtual float price()=0;
    virtual bool isThis()=0;
    friend ostream& operator<<(ostream &out,Pizza &fp){
        out<<fp.ime<<": ";
        for(int i=0; i<strlen(fp.sosotjki); i++){
               out<< fp.sosotjki[i];
        }
                if(fp.isThis()==true){
               out<<", "<<fp.tipce(fp.tip);
                }
                else{
                    if(!fp.belo){
                        out<<", "<<"nwf";
                    }
                    else{
                        out<<", "<<"wf";
                        }
                        }
               out <<" - "<<fp.price()<<endl;
        return out;
    }
};
class FlatPizza:public Pizza{
private:
    Size tip;
public:
    FlatPizza(){}

    FlatPizza(char *ime,char*sosotjki,float cena,Size tip):Pizza(ime,sosotjki,cena){
        this->tip=tip;
    }
    FlatPizza(char *ime,char *sosotjki,float cena):Pizza(ime,sosotjki,cena){
        this->tip=Size::MALA;
    }
    float price(){
        float rez=0.0;
        if(tip==0){
            float procent=cena*0.10;
            rez=cena;
            rez+=procent;
        }
        if(tip==1){
            float procent=cena*0.2;
            rez=cena;
            rez+=procent;
        }
        if(tip==2){
            float procent=cena*0.3;
            rez=cena;
            rez+=procent;
        }
        return rez;
    }
    friend ostream& operator<<(ostream &out,FlatPizza &fp){
        out<<fp.ime<<": ";
        for(int i=0; i<strlen(fp.sosotjki); i++){
               out<< fp.sosotjki[i];
        }
               out<<", "<<fp.tipce(fp.tip);
               out <<" - "<<fp.price()<<endl;
        return out;
    }
    bool isThis(){
        return true;
    }
};
class FoldedPizza:public Pizza{
private:
    bool belo;
public:
    FoldedPizza(){
    }
    FoldedPizza(char *ime,char *sosotjki,float cena):Pizza(ime,sosotjki,cena){
        this->belo=true;
    }
    float price(){
        float rez=cena;
        float procent=0.0;
        if(belo==true){
            procent=cena*0.1;
            rez+=procent;
        }
        if(belo==false)
        {
            procent=cena*0.3;
            rez+=procent;
        }
        return rez;
    }
    void setWhiteFlour(bool belo){
        this->belo=belo;
    }
    friend ostream& operator<<(ostream &out,FoldedPizza &fp){
        out<<fp.ime<<": ";
        for(int i=0; i<strlen(fp.sosotjki); i++){
               out<< fp.sosotjki[i];
        }
               if(fp.belo==true){
                out<<", "<<"wf";
               }
               else
               {
                   out<<", "<<"nwf";
               }
               out <<" - "<<fp.price()<<endl;
        return out;
    }
    bool isThis(){
        return false;
    }
};
void expensivePizza(Pizza **pi,int n){
    int maxSum=0;
    int index=0;
    for(int i=0; i<n; i++){
        if(pi[i]->price()>maxSum){
            maxSum=pi[i]->price();
            index=i;
        }

    }
    cout<<*pi[index]<<endl;
}
// Testing

int main() {
  int test_case;
  char name[20];
  char ingredients[100];
  float inPrice;
  Size size;
  bool whiteFlour;

  cin >> test_case;
  if (test_case == 1) {
    // Test Case FlatPizza - Constructor, operator <<, price
    cin.get();
    cin.getline(name,20);
    cin.getline(ingredients,100);
    cin >> inPrice;
    FlatPizza fp(name, ingredients, inPrice);
    cout << fp;
  } else if (test_case == 2) {
    // Test Case FlatPizza - Constructor, operator <<, price
    cin.get();
    cin.getline(name,20);
    cin.getline(ingredients,100);
    cin >> inPrice;
    int s;
    cin>>s;
    FlatPizza fp(name, ingredients, inPrice, (Size)s);
    cout << fp;

  } else if (test_case == 3) {
    // Test Case FoldedPizza - Constructor, operator <<, price
    cin.get();
    cin.getline(name,20);
    cin.getline(ingredients,100);
    cin >> inPrice;
    FoldedPizza fp(name, ingredients, inPrice);
    cout << fp;
  } else if (test_case == 4) {
    // Test Case FoldedPizza - Constructor, operator <<, price
    cin.get();
    cin.getline(name,20);
    cin.getline(ingredients,100);
    cin >> inPrice;
    FoldedPizza fp(name, ingredients, inPrice);
    fp.setWhiteFlour(false);
    cout << fp;

  } else if (test_case == 5) {
	// Test Cast - operator <, price
    int s;

    cin.get();
    cin.getline(name,20);
    cin.getline(ingredients,100);
    cin >> inPrice;
    cin>>s;
    FlatPizza *fp1 = new FlatPizza(name, ingredients, inPrice, (Size)s);
    cout << *fp1;

    cin.get();
    cin.getline(name,20);
    cin.getline(ingredients,100);
    cin >> inPrice;
    cin>>s;
    FlatPizza *fp2 = new FlatPizza(name, ingredients, inPrice, (Size)s);
    cout << *fp2;

    cin.get();
    cin.getline(name,20);
    cin.getline(ingredients,100);
    cin >> inPrice;
    FoldedPizza *fp3 = new FoldedPizza(name, ingredients, inPrice);
    cout << *fp3;

    cin.get();
    cin.getline(name,20);
    cin.getline(ingredients,100);
    cin >> inPrice;
    FoldedPizza *fp4 = new FoldedPizza(name, ingredients, inPrice);
    fp4->setWhiteFlour(false);
    cout << *fp4;

    cout<<"Lower price: "<<endl;
    if(*fp1<*fp2)
        cout<<fp1->price()<<endl;
    else cout<<fp2->price()<<endl;

    if(*fp1<*fp3)
        cout<<fp1->price()<<endl;
    else cout<<fp3->price()<<endl;

    if(*fp4<*fp2)
        cout<<fp4->price()<<endl;
    else cout<<fp2->price()<<endl;

    if(*fp3<*fp4)
        cout<<fp3->price()<<endl;
    else cout<<fp4->price()<<endl;

  } else if (test_case == 6) {
	// Test Cast - expensivePizza
    int num_p;
    int pizza_type;

    cin >> num_p;
    Pizza **pi = new Pizza *[num_p];
    for (int j = 0; j < num_p; ++j) {

      cin >> pizza_type;
      if (pizza_type == 1) {
        cin.get();
        cin.getline(name,20);

        cin.getline(ingredients,100);
        cin >> inPrice;
        int s;
        cin>>s;
        FlatPizza *fp = new FlatPizza(name, ingredients, inPrice, (Size)s);
        cout << (*fp);
        pi[j] = fp;
      }
      if (pizza_type == 2) {

        cin.get();
        cin.getline(name,20);
        cin.getline(ingredients,100);
        cin >> inPrice;
        FoldedPizza *fp =
            new FoldedPizza (name, ingredients, inPrice);
        if(j%2)
          (*fp).setWhiteFlour(false);
        cout << (*fp);
        pi[j] = fp;

      }
    }

    cout << endl;
    cout << "The most expensive pizza:\n";
    expensivePizza(pi,num_p);


  }
  return 0;
}
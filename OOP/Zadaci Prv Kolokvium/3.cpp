/*
За потребите на еден приватен банкар кој тргува со акции, потребно е да се направи модул за менаџирање со клиентски портфолија.

За таа цел, треба да се креира класа StockRecord. Класата треба да содржи:

ID, кој означува која е акцијата која се тргува (низа од 12 знаци)
Име на компанијата која ја издала акцијата (низа од 50 знаци)
Цена според која се купени акциите (реален број)
Моментална цена на акцијата (реален број)
Број на акции кои се купени (цел број)
За класата да се дефинираат потребните конструктори и set метода за моменталната цена со потпис void setNewPrice(double c) (10 поени). Исто така, да се имплементираат методи double value() и double profit(). Првата треба да ја пресметува вредноста на акциите, а втората треба да го пресметува моменталниот профит од акциите. Пресметката се врши на следниот начин (5 поени):

Вредност = број на акции * моментална цена 
Профит = број на акции * (моментална цена - цена по која се купени)
Дополнително, да се преоптовари операторот << за печатење на објектот во следниот формат (5 поени): Компанија БројНаАкции КуповнаЦена МоменталнаЦена Профит

Да се креира класа Client која содржи:

Име и презиме на клиентот (низа од 60 знаци)
ID на сметка (цел број)
Низа од компании кои ги поседува клиентот (динамичка низа од објекти од класата StockRecord)
Број на објекти во низата (цел број)
За класата Client да се дефинираат потребните конструктори, деструктор и метода double totalValue() која ќе ја пресметува моменталната вредност на акциите кои ги поседува клиентот. Таа се пресметува како збир од вредноста на сите акции од секоја компанија од кои е составено клиентското портфолио (15 поени). Дополнително, за класата да се преоптоварат операторите:

+= за купување на нова компанија во портфолиото (додавање на нов објект од класата StockRecord во низата со компании) (10 поени)

<< за печатење на информации за портфолиото на клиентот така што во првиот ред ќе бидат прикажани ID на сметката и моменталната вредност на портфолиото одделени со празно место, а во секој нареден ред ќе бидат прикажани компаниите од кои е составено портфолиото, секоја во посебен ред (5 поени)

Комплетна функционанлост (5 поени)

For example:

Input	Result
3
Aleksandar
240992
3
CH0038863350
Nestle
100
90
100
DE000BAY0017
Bayer
60
70
500
DE0007164600
SAP
110
115
200
=====TEST NA KLASATA Client=====
Konstruktor OK
Operator += OK
240992 67000
Nestle 100 100 90 -1000
Bayer 500 60 70 5000
SAP 200 110 115 1000
Operator << OK

*/

#include<iostream>
#include<cstring>
using namespace std;

class StockRecord{

private:
    char id[12];
    char company[50];
    double oldPrice;
    double newPrice;
    int shares;
public:
    StockRecord(char *i = "", char *c = "", double op = 0.0, int s = 0){
    	strcpy(id, i);
        strcpy(company, c);
        oldPrice = op;
        newPrice = 0.0;
        shares = s;
    }
    ~StockRecord(){}
    void setNewPrice(double np){
    	newPrice = np;
    }
    double value(){
    	return shares * newPrice;
    }
    double profit(){
    	return shares * (newPrice - oldPrice);
    }
    friend ostream& operator<<(ostream &out, StockRecord &sr){
    	out << sr.company << " " << sr.shares << " " << sr.oldPrice << " " << sr.newPrice << " " << sr.profit() << endl;
    	return out;
    }

};



class Client{

private:
    char name[50];
    int id;
    StockRecord *stocks;
    int n;
public:
    Client(char *name = "", int id = 0){
    	strcpy(this->name, name);
        this->id = id;
        stocks = NULL;
        n = 0;
    }
    ~Client(){
    	delete [] stocks;
    }
    double totalValue(){
        double tv = 0.0;
        for(int i = 0; i < n; ++i){
        	tv += stocks[i].value();
        }
        return tv;
    }
    Client& operator+=(StockRecord &sr){
    	StockRecord *tmp = new StockRecord[n + 1];
        for(int i = 0; i < n; ++i){
        	tmp[i] = stocks[i];
        }
        tmp[n++] = sr;
        delete [] stocks;
        stocks = tmp;
        return *this;
    }
    friend ostream& operator<<(ostream &out, Client &c){
    	out << c.id << " " << c.totalValue() << endl;
        for(int i = 0; i < c.n; ++i){
        	out << c.stocks[i];
        }
        return out;
    }

};



int main(){
	
    int test;
    cin >> test;
    
    if(test == 1){
    	double price;
        cout << "=====TEST NA KLASATA StockRecord=====" << endl;
        StockRecord sr("1", "Microsoft", 60.0, 100);
        cout << "Konstruktor OK" << endl;
        cin >> price;
        sr.setNewPrice(price);
        cout << "SET metoda OK" << endl;
    }
    else if(test == 2){
        cout << "=====TEST NA METODITE I OPERATOR << OD KLASATA StockRecord=====" << endl;
    	char id[12], company[50];
        double price, newPrice;
        int n, shares;
        cin >> n;
        for(int i = 0; i < n; ++i){
        	cin >> id;
            cin >> company;
            cin >> price;
            cin >> newPrice;
            cin >> shares;
            StockRecord sr(id, company, price, shares);
            sr.setNewPrice(newPrice);
            cout << sr.value() << endl;
            cout << sr;
        }
    }
    else if(test == 3){
    	cout << "=====TEST NA KLASATA Client=====" << endl;
        char companyID[12], companyName[50], clientName[50];
        int clientID, n, shares;
        double oldPrice, newPrice;
        bool flag = true;
        cin >> clientName;
        cin >> clientID;
        cin >> n;
        Client c(clientName, clientID);
        cout << "Konstruktor OK" << endl;
        for(int i = 0; i < n; ++i){
            cin >> companyID;
            cin >> companyName;
            cin >> oldPrice;
            cin >> newPrice;
            cin >> shares;
        	StockRecord sr(companyID, companyName, oldPrice, shares);
            sr.setNewPrice(newPrice);
            c += sr;
            if(flag){
            	cout << "Operator += OK" << endl;
                flag = false;
            }
        }
        cout << c;
        cout << "Operator << OK" << endl;
    } 
    return 0;

}
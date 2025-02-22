#include <iostream>
#include <cstring>
enum tip{SMARTPHONE,COMPUTER};
using namespace std;
class InvalidProductionDate {
private:
	string msg;
public:
	InvalidProductionDate(string msg) {
		this->msg=msg;
	}
	void print() {
		cout<<msg<<endl;
	}
};
class Device {
private:
	char podatoci[100];
	tip kojtip;
	static int casovi;
	int godinaP;
public:
	Device(){}
	Device(char *podatoci,tip kojtip,int godinaP) {
		strcpy(this->podatoci,podatoci);
		this->kojtip=kojtip;
		this->godinaP=godinaP;
	}
	Device(const Device &d) {
		strcpy(this->podatoci,d.podatoci);
		this->kojtip=d.kojtip;
		this->godinaP=d.godinaP;
	}
	Device& operator==(const Device &d) {
		if(this!=&d) {
			strcpy(this->podatoci,d.podatoci);
			this->kojtip=d.kojtip;
			this->godinaP=d.godinaP;
		}
		return *this;
	}
	int getGodina() {
		return godinaP;
	}
	static void setPocetniCasovi(int cas) {
		casovi=cas;
	}
	float getCasovi() {
		return casovi;
	}
	string tipce(tip kojtip){
		string line;
		switch (kojtip) {
			case (SMARTPHONE):
				line="Mobilen";
			break;
			case (COMPUTER):
				line="Laptop";
			break;
			return line;
		}
	}
	float casoviZaProverka() {
		int cas=casovi;
		if(godinaP>2015 && kojtip==SMARTPHONE) {
			cas+=2;
		}
		if(kojtip==COMPUTER && godinaP<2016) {
			cas+=2;
		}
		if(godinaP>2015 && kojtip==COMPUTER) {
			cas+=4;
		}
		return cas;
	}
	friend ostream& operator<<(ostream &out,Device &d) {
		out<<d.podatoci<<endl;
		out<<d.tipce(d.kojtip)<<" "<<d.casoviZaProverka()<<endl;
		return out;
	}
	~Device(){}
};
class MobileServis {
private:
	char adresa[100];
	Device *devices;
	int n;
public:
	MobileServis() {
		strcpy(this->adresa,"");
		this->devices=new Device[0];
		n=0;
	}
	MobileServis(char *adresa) {
		strcpy(this->adresa,adresa);
		this->n=n;
		this->devices=new Device[n];
		for(int i=0; i<n; i++) {
			this->devices[i]=devices[i];
		}
	}
	MobileServis(const MobileServis &mb) {
		strcpy(this->adresa,mb.adresa);
		this->n=mb.n;
		this->devices=new Device[mb.n];
		for(int i=0; i<mb.n; i++) {
			this->devices[i]=mb.devices[i];
		}
	}
	MobileServis& operator==(const MobileServis &mb) {
		if(this!=&mb) {
			strcpy(this->adresa,mb.adresa);
			this->n=mb.n;
			this->devices=new Device[mb.n];
			for(int i=0; i<mb.n; i++) {
				this->devices[i]=mb.devices[i];
			}
		}
		return *this;
	}
	MobileServis& operator+=( Device &d) {

			if(d.getGodina()>2019 || d.getGodina()<2000) {
				throw InvalidProductionDate("Невалидна година на производство");
			}

		Device *temp=new Device[n+1];
		for(int i=0; i<n; i++) {
			temp[i]=devices[i];
		}
		temp[n]=d;
		n++;
		delete []devices;
		devices=temp;
		return *this;
	}
	void pecatiCasovi() {
		cout<<"Ime: "<<adresa<<endl;
		for(int i=0; i<n; i++) {
			cout<<devices[i];
		}
	}
	~MobileServis() {
		delete []devices;
	}
};
int Device::casovi=1;
int main()
{
	int testCase;
	cin >> testCase;
    char ime[100];
    int tipDevice;
    int godina;
    int n;
    Device devices[50];
	if (testCase == 1){
		cout << "===== Testiranje na klasite ======" << endl;
		cin >> ime;
		cin >> tipDevice;
		cin >> godina;
		Device ig(ime,(tip)tipDevice,godina);
        cin>>ime;
		MobileServis t(ime);
        cout<<ig;
		}
	if (testCase == 2){
		cout << "===== Testiranje na operatorot += ======" << endl;
        cin>>ime;
        cin >> n;
		MobileServis t(ime);
		for(int i=0;i<n;i++)
        {
            cin >> ime;
            cin >> tipDevice;
            cin >> godina;
            Device tmp(ime,(tip)tipDevice,godina);
            t+=tmp;
        }
        t.pecatiCasovi();
	}
	if (testCase == 3){
		cout << "===== Testiranje na isklucoci ======" << endl;
        cin>>ime;
        cin >> n;
		MobileServis t(ime);

		for(int i=0;i<n;i++)
        {
			try{
            cin >> ime;
            cin >> tipDevice;
            cin >> godina;
            Device tmp(ime,(tip)tipDevice,godina);

				t+=tmp;
			}catch (InvalidProductionDate &ie) {
				ie.print();
			}
        }
        t.pecatiCasovi();
	}
	if (testCase == 4){
		cout <<"===== Testiranje na konstruktori ======"<<endl;
		 cin>>ime;
        cin >> n;
		MobileServis t(ime);
		for(int i=0;i<n;i++)
        {
			try {
				cin >> ime;
				cin >> tipDevice;
				cin >> godina;
				Device tmp(ime,(tip)tipDevice,godina);
				t+=tmp;
			}catch (InvalidProductionDate &ie) {
				ie.print();
			}
        }
        MobileServis t2 = t;
        t2.pecatiCasovi();
	}
	if (testCase == 5){
		cout << "===== Testiranje na static clenovi ======" << endl;
        cin>>ime;
        cin >> n;
		MobileServis t(ime);
		for(int i=0;i<n;i++)
        {
            cin >> ime;
            cin >> tipDevice;
            cin >> godina;
            Device tmp(ime,(tip)tipDevice,godina);

            t+=tmp;
        }
        t.pecatiCasovi();
        cout << "===== Promena na static clenovi ======" << endl;
		Device::setPocetniCasovi(2);
        t.pecatiCasovi();
	}

		if (testCase == 6){
		cout << "===== Testiranje na kompletna funkcionalnost ======" << endl;
		cin>>ime;
        cin >> n;
		MobileServis t(ime);
		for(int i=0;i<n;i++)
        {
			try {
				cin >> ime;
				cin >> tipDevice;
				cin >> godina;
				Device tmp(ime,(tip)tipDevice,godina);
				t+=tmp;
			}catch (InvalidProductionDate &ie) {
				ie.print();
			}
        }
		Device::setPocetniCasovi(3);
        MobileServis t2 = t;
        t2.pecatiCasovi();
	}

	return 0;

}
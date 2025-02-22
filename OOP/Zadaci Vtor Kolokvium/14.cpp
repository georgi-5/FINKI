#include <iostream>
#include <cstring>
using namespace std;
class SMS {
protected:
	float cena;
	char broj[14];
	static float danok;
public:
	SMS(){}
	SMS(char *broj,float cena) {
		strcpy(this->broj,broj);
		this->cena=cena;
	}
	SMS(const SMS &s) {
		strcpy(this->broj,s.broj);
		this->cena=s.cena;
	}
	SMS& operator==(const SMS &s) {
		if(this!=&s) {
			strcpy(this->broj,s.broj);
			this->cena=s.cena;
		}
		return  *this;
	}
	virtual float SMS_Cena()=0;
	friend ostream& operator<<(ostream &out,SMS &s) {
		out<<"Tel: "<<s.broj<<" - cena: "<<s.SMS_Cena()<<"den."<<endl;
		return out;
	}
	~SMS(){}
};
class RegularSMS:public SMS{
private:
	string text;
	bool roaming;
	static float procentS;
public:
	RegularSMS() {
		this->roaming=false;
	}
	RegularSMS(char *broj,float cena,string text,bool roaming):SMS(broj,cena){
		this->text=text;
		this->roaming=roaming;
	}
	RegularSMS(const RegularSMS &r){
		this->text=r.text;
		this->roaming=r.roaming;
	}
	RegularSMS& operator==(const RegularSMS &r) {
		if(this!=&r){
			this->text=r.text;
			this->roaming=r.roaming;
		}
		return *this;
	}


	int kolkuPoraki() {
		int dolzinaNaPoraka=text.length();
		int maxDolzina=160;
		int kolku=dolzinaNaPoraka/maxDolzina;
		if(dolzinaNaPoraka%maxDolzina!=0) {
			kolku++;
		}
		return kolku;
	}
	float SMS_Cena() {
		float cena2=cena;
		if(roaming) {
			float procent=cena*procentS/100;
			cena2=cena+procent*kolkuPoraki();
		}
		if(!roaming) {
			float danok2=cena*danok/100;
			cena2=(cena+danok2)*kolkuPoraki();
		}
		return cena2;
	}
	static void set_rProcent(float procent) {
		procentS=procent;
	}
	friend ostream& operator<<(ostream &out,RegularSMS &s) {
		out<<"Tel: "<<s.broj<<" - cena: "<<s.SMS_Cena()<<"den."<<endl;
		return out;
	}
	~RegularSMS() {}
};
class SpecialSMS:public SMS{
private:
	bool humanitarni;
	static float procentR;
	RegularSMS *r;
public:
	SpecialSMS() {
		humanitarni=false;
	}
	SpecialSMS(char *broj,float cena,bool humanitarni):SMS(broj,cena) {
		this->humanitarni=humanitarni;
	}
	float SMS_Cena() {
		float procent=0.0;
		if(!humanitarni) {
			procent=cena*procentR/100;
			cena=(cena+procent);
		}
		return cena;
	}
	static void set_sProcent(float procent) {
		procentR=procent;
	}
	friend ostream& operator<<(ostream &out,SpecialSMS &s) {
		out<<"Tel: "<<s.broj<<" - cena: "<<s.SMS_Cena()<<"den."<<endl;
		return out;
	}
	~SpecialSMS(){}
};
float SMS::danok=18;
float RegularSMS::procentS=300;
float SpecialSMS::procentR=150;
void vkupno_SMS(SMS** poraka, int n) {
	int br1,br2; br1=br2=0;
	float sum,sum2;sum=sum2=0.0;
	for(int i=0; i<n; i++) {
		RegularSMS *reg=dynamic_cast<RegularSMS*>(poraka[i]);
		if(reg!=nullptr) {
			sum+=reg->SMS_Cena();
			br1++;
		}
	}
	for(int i=0; i<n; i++) {
		SpecialSMS *sp=dynamic_cast<SpecialSMS*>(poraka[i]);
		if(sp!=nullptr) {
			sum2+=sp->SMS_Cena();
			br2++;
		}
	}
	cout<<"Vkupno ima "<<br1<<" regularni SMS poraki i nivnata cena e: "<<sum<<endl;
	cout<<"Vkupno ima "<<br2<<" specijalni SMS poraki i nivnata cena e: "<<sum2;
}
int main(){

	char tel[20], msg[1000];
	float cena;
	float price;
    int p;
	bool roam, hum;
	SMS  **sms;
	int n;
	int tip;

	int testCase;
	cin >> testCase;

	if (testCase == 1){
		cout << "====== Testing RegularSMS class ======" << endl;
		cin >> n;
		sms = new SMS *[n];

		for (int i = 0; i < n; i++){
			cin >> tel;
			cin >> cena;
            cin.get();
			cin.getline(msg, 1000);
			cin >> roam;
			cout << "CONSTRUCTOR" << endl;
			sms[i] = new RegularSMS(tel, cena, msg, roam);
			cout << "OPERATOR <<" << endl;
			cout << *sms[i];
		}
        for (int i = 0; i<n; i++) delete sms[i];
		delete[] sms;
	}
	if (testCase == 2){
		cout << "====== Testing SpecialSMS class ======" << endl;
		cin >> n;
		sms = new SMS *[n];

		for (int i = 0; i < n; i++){
			cin >> tel;
			cin >> cena;
			cin >> hum;
			cout << "CONSTRUCTOR" << endl;
			sms[i] = new SpecialSMS(tel, cena, hum);
			cout << "OPERATOR <<" << endl;
			cout << *sms[i];
		}
        for (int i = 0; i<n; i++) delete sms[i];
		delete[] sms;
	}
	if (testCase == 3){
		cout << "====== Testing method vkupno_SMS() ======" << endl;
		cin >> n;
		sms = new SMS *[n];

		for (int i = 0; i<n; i++){

			cin >> tip;
			cin >> tel;
			cin >> cena;
			if (tip == 1) {

				cin.get();
				cin.getline(msg, 1000);
                cin >> roam;

				sms[i] = new RegularSMS(tel, cena, msg, roam);

			}
			else {
				cin >> hum;

				sms[i] = new SpecialSMS(tel, cena, hum);
			}
		}

		vkupno_SMS(sms, n);
        for (int i = 0; i<n; i++) delete sms[i];
		delete[] sms;
	}
    if (testCase == 4){
		cout << "====== Testing RegularSMS class with a changed percentage======" << endl;
        SMS *sms1, *sms2;
        	cin >> tel;
			cin >> cena;
            cin.get();
			cin.getline(msg, 1000);
			cin >> roam;
			sms1 = new RegularSMS(tel, cena, msg, roam);
			cout << *sms1;

            cin >> tel;
			cin >> cena;
            cin.get();
			cin.getline(msg, 1000);
			cin >> roam;
        	cin >> p;
        	RegularSMS::set_rProcent(p);
        	sms2 = new RegularSMS(tel, cena, msg, roam);
        	cout << *sms2;

        delete sms1, sms2;
	}
    if (testCase == 5){
		cout << "====== Testing SpecialSMS class with a changed percentage======" << endl;
        SMS *sms1, *sms2;
        	cin >> tel;
			cin >> cena;
			cin >> hum;
			sms1 = new SpecialSMS(tel, cena, hum);
			cout << *sms1;

            cin >> tel;
			cin >> cena;
			cin >> hum;
        	cin >> p;
        	SpecialSMS::set_sProcent(p);
        	sms2 = new SpecialSMS(tel, cena, hum);
        	cout << *sms2;

        delete sms1, sms2;
	}

	return 0;
}
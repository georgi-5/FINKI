#include <iostream>
#include <string.h>
#include <cstdlib>

using namespace std;

//место за вашиот код
class NegativnaVrednost {
private:
	string msg;
public:
	NegativnaVrednost(string msg) {
		this->msg=msg;
	}
	void print() {
		cout<<msg<<endl;
	}
};
class Oglas {
private:
	char naslov[50];
	char kategorija[30];
	char opis[100];
	float cena;
public:
	Oglas(){}
	Oglas(char *naslov,char *kategorija,char *opis,float cena) {
		strcpy(this->naslov,naslov);
		strcpy(this->kategorija,kategorija);
		strcpy(this->opis,opis);
		this->cena=cena;
	}
	Oglas(const Oglas &o) {
		strcpy(this->naslov,o.naslov);
		strcpy(this->kategorija,o.kategorija);
		strcpy(this->opis,o.opis);
		this->cena=o.cena;
	}
	Oglas& operator=(const Oglas &o) {
		if(this!=&o) {
			strcpy(this->naslov,o.naslov);
			strcpy(this->kategorija,o.kategorija);
			strcpy(this->opis,o.opis);
			this->cena=o.cena;
		}
		return *this;
	}
	bool operator>(Oglas &o) {
		return this->cena>o.cena;
	}
	friend ostream& operator<<(ostream &out,Oglas &o) {
		out<<o.naslov<<endl;
		out<<o.opis<<endl;
		out<<o.cena<<" evra"<<endl;
		return out;
	}
	char* getNaslov() {
		return naslov;
	}
	char* getOpis() {
		return opis;
	}
	float getCena() {
		return cena;
	}
	char* getKategorija() {
		return kategorija;
	}
	~Oglas(){}
};
class Oglasnik {
private:
	char ime[20];
	Oglas *oglasi;
	int n;
public:
	Oglasnik() {
		strcpy(this->ime,"");
		this->oglasi=new Oglas[0];
		n=0;
	}
	Oglasnik(char *ime) {
		strcpy(this->ime,ime);
		this->n=n;
		this->oglasi=new Oglas[n];

	}
	Oglasnik(const Oglasnik &ogl) {
		strcpy(this->ime,ogl.ime);
		this->n=ogl.n;
		this->oglasi=new Oglas[ogl.n+1];
		for(int i=0; i<ogl.n; i++) {
			this->oglasi[i]=ogl.oglasi[i];
		}
	}
	Oglasnik& operator=(const Oglasnik &ogl) {
		if(this!=&ogl) {
			delete []oglasi;
			strcpy(this->ime,ogl.ime);
			this->n=ogl.n;
			this->oglasi=new Oglas[ogl.n+1];
			for(int i=0; i<ogl.n; i++) {
				this->oglasi[i]=ogl.oglasi[i];
			}
		}
		return *this;
	}
	Oglasnik& operator+=(Oglas &o) {
		Oglas *temp=new Oglas[n+1];
			if(o.getCena()<0) {
				throw NegativnaVrednost("Oglasot ima nevalidna vrednost za cenata i nema da bide evidentiran!");
			}
		for(int i=0; i<n; i++) {
			temp[i]=oglasi[i];
		}
		temp[n]=o;
		delete []this->oglasi;
		this->oglasi=temp;
		this->n++;
		return *this;
	}
	friend ostream& operator<<(ostream &out,Oglasnik &o) {
		out<<o.ime<<endl;
		for(int i=0; i<o.n; i++) {
			out<<o.oglasi[i]<<endl;
		}
		return out;
	}
	~Oglasnik() {
		delete []oglasi;
	}
	void oglasiOdKategorija(const char *k) {
		for(int i=0; i<n; i++) {
			if(strcmp(oglasi[i].getKategorija(),k)==0) {
				cout<<oglasi[i]<<endl;
			}
		}

	}
	void najniskaCena() {
		float min=oglasi[0].getCena();
		int index=0;
		for(int i=1; i<n; i++) {
			if(oglasi[i].getCena()<min) {
				min=oglasi[i].getCena();
				index=i;
			}
		}
		cout<<oglasi[index];
	}
};

int main(){

    char naslov[50];
    char kategorija[30];
    char opis[100];
    float cena;
    char naziv[50];
    char k[30];
    int n;

    int tip;
    cin>>tip;

    if (tip==1){
        cout<<"-----Test Oglas & operator <<-----" <<endl;
        cin.get();
		cin.getline(naslov,49);
        cin.getline(kategorija,29);
        cin.getline(opis,99);
        cin>>cena;
        Oglas o(naslov, kategorija, opis, cena);
        cout<<o;
    }
    else if (tip==2){
    	cout<<"-----Test Oglas & operator > -----" <<endl;
        cin.get();
		cin.getline(naslov,49);
        cin.getline(kategorija,29);
        cin.getline(opis,99);
        cin>>cena;
        Oglas o1(naslov, kategorija, opis, cena);
        cin.get();
		cin.getline(naslov,49);
        cin.getline(kategorija,29);
        cin.getline(opis,99);
        cin>>cena;
        Oglas o2(naslov, kategorija, opis, cena);
        if (o1>o2) cout<<"Prviot oglas e poskap."<<endl;
        else cout<<"Prviot oglas ne e poskap."<<endl;
    }
    else if (tip==3){
        cout<<"-----Test Oglasnik, operator +=, operator << -----" <<endl ;
        cin.get();
		cin.getline(naziv,49);
        cin>>n;
        Oglasnik ogl(naziv);
        for (int i = 0; i < n; i++){
            cin.get();
            cin.getline(naslov,49);
            cin.getline(kategorija,29);
            cin.getline(opis,99);
            cin>>cena;
        	Oglas o(naslov, kategorija, opis, cena);
            ogl+=o;
        }
        cout<<ogl;
    }
    else if (tip==4){
      	cout<<"-----Test oglasOdKategorija -----" <<endl ;
      	cin.get();
		cin.getline(naziv,49);
        cin>>n;
        Oglasnik ogl(naziv);
        for (int i = 0; i < n; i++){
            cin.get();
            cin.getline(naslov,49);
            cin.getline(kategorija,29);
            cin.getline(opis,99);
            cin>>cena;
        	Oglas o(naslov, kategorija, opis, cena);
            ogl+=o;
        }
        cin.get();
		cin.getline(k,29);
        cout<<"Oglasi od kategorijata: " <<k<<endl;
      	ogl.oglasiOdKategorija(k);

    }
    else if (tip==5){
    	cout<<"-----Test Exception -----" <<endl ;
      	cin.get();
		cin.getline(naziv,49);
        cin>>n;
        Oglasnik ogl(naziv);

        for (int i = 0; i < n; i++){
            cin.get();
            cin.getline(naslov,49);
            cin.getline(kategorija,29);
            cin.getline(opis,99);
            cin>>cena;
        	try {
        		Oglas o(naslov, kategorija, opis, cena);
        		ogl+=o;
        	}catch (NegativnaVrednost &ne) {
        		ne.print();
        	}
        }
        cout<<ogl;

    }
    else if (tip==6){
    	cout<<"-----Test najniskaCena -----" <<endl ;
      	cin.get();
		cin.getline(naziv,49);
        cin>>n;
        Oglasnik ogl(naziv);
        for (int i = 0; i < n; i++){
            cin.get();
            cin.getline(naslov,49);
            cin.getline(kategorija,29);
            cin.getline(opis,99);
            cin>>cena;
        	Oglas o(naslov, kategorija, opis, cena);
            ogl+=o;
        }
        cout<<"Oglas so najniska cena:"<<endl;
      	ogl.najniskaCena();

    }
    else if (tip==7){
    	cout<<"-----Test All -----" <<endl ;
      	cin.get();
		cin.getline(naziv,49);
        cin>>n;
        Oglasnik ogl(naziv);

    		for (int i = 0; i < n; i++){
    			cin.get();
    			cin.getline(naslov,49);
    			cin.getline(kategorija,29);
    			cin.getline(opis,99);
    			cin>>cena;
    			try {
    			Oglas o(naslov, kategorija, opis, cena);
    			ogl+=o;
    			}catch (NegativnaVrednost &ne) {
    				ne.print();
    			}
    		}

        cout<<ogl;

        cin.get();
        cin.get();
		cin.getline(k,29);
        cout<<"Oglasi od kategorijata: " <<k<<endl;
      	ogl.oglasiOdKategorija(k);

        cout<<"Oglas so najniska cena:"<<endl;
      	ogl.najniskaCena();

    }

	return 0;
}
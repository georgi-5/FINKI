#include <iostream>
#include <cstring>

using namespace std;

class Pica {
private:
	char ime[15];
	int cena;
	char* sostojki;
	int namaluvanje;
public:

	Pica(const char* ime = "", int cena = 0, const char* sostojki = "", int namaluvanje = 0) {

		strcpy(this->ime, ime);
		this->cena = cena;
		this->sostojki = new char[strlen(sostojki) + 1];
		strcpy(this->sostojki, sostojki);
		this->namaluvanje = namaluvanje;
	}

	Pica(const Pica& p) {
		strcpy(ime, p.ime);
		cena = p.cena;
		sostojki = new char[strlen(p.sostojki) + 1];
		strcpy(sostojki, p.sostojki);
		namaluvanje = p.namaluvanje;
	}

	~Pica() {
		delete[] sostojki;
	}

	Pica& operator= (Pica& p) {
		if (this != &p) {
			strcpy(ime, p.ime);
			cena = p.cena;
			delete[] sostojki;
			sostojki = new char[strlen(p.sostojki) + 1];
			strcpy(sostojki, p.sostojki);
			namaluvanje = p.namaluvanje;
		}
		return *this;
	}
	void pecati(){
		cout << ime << " - " << sostojki << ", " << cena;
	}

	bool istiSe(Pica p){
		return (strcmp(sostojki, p.sostojki) == 0);
	}
	int getNamaluvanje(){
		return namaluvanje;
	}
	int getCena(){
		return cena;
	}
};

class Picerija {

private:
	char ime[15];
	Pica* pici;
	int br;

public:
	Picerija(const char *ime = ""){
		strncpy(this->ime, ime, 14);
		this->ime[14] = 0;
		pici = NULL;
		br = 0;
	}
	Picerija(const char *ime, Pica* pici, int br) {
		strncpy(this->ime, ime, 14);
		this->ime[14] = 0;
		this->br = br;
		this->pici = new Pica[br];
		for (int i = 0; i < br; i++)
			this->pici[i] = pici[i];
	}

	Picerija(const Picerija &p) {
		strcpy(ime, p.ime);
		br = p.br;
		pici = new Pica[br];
		for (int i = 0; i < br; i++)
			pici[i] = p.pici[i];
	}
	Picerija& operator= (const Picerija &p) {
		if (this != &p) {
			strcpy(ime, p.ime);
			br = p.br;
			delete[] pici;
			pici = new Pica[br];
			for (int i = 0; i < br; i++)
				pici[i] = p.pici[i];
		}
		return *this;
	}
	~Picerija() {
		delete[] pici;
	}

	Picerija& operator+=(Pica &p){
		bool imaIsta = false;
		for (int i = 0; i < br; i++)
			if (pici[i].istiSe(p))
				imaIsta = true;
		if (!imaIsta)
		{
			Pica* tmp = new Pica[br + 1];
			for (int i = 0; i < br; i++)
				tmp[i] = pici[i];
			tmp[br++] = p;
			delete[] pici;
			pici = tmp;
		}
		return *this;
	}

	void piciNaPromocija() {
		for (int i = 0; i < br; i++){
			if (pici[i].getNamaluvanje() != 0){
				pici[i].pecati();
				cout << " " << pici[i].getCena() * (1 - pici[i].getNamaluvanje() / 100.0) << endl;
			}
		}

	}
	const char* getIme(){
		return ime;
	}
	void setIme(const char* ime){
		strncpy(this->ime, ime, 14);
		this->ime[14] = 0;
	}

};
int main() {

	int n;
	char ime[15];
	cin >> ime;
	cin >> n;

	Picerija p1(ime);
	for (int i = 0; i < n; i++){
		char imp[100];
		cin.get();
		cin.getline(imp, 100);
		int cena;
		cin >> cena;
		char sostojki[100];
		cin.get();
		cin.getline(sostojki, 100);
		int popust;
		cin >> popust;
		Pica p(imp, cena, sostojki, popust);
		p1+=p;
	}

	Picerija p2 = p1;
	cin >> ime;
	p2.setIme(ime);
	char imp[100];
	cin.get();
	cin.getline(imp, 100);
	int cena;
	cin >> cena;
	char sostojki[100];
	cin.get();
	cin.getline(sostojki, 100);
	int popust;
	cin >> popust;
	Pica p(imp, cena, sostojki, popust);
	p2+=p;

	cout << p1.getIme() << endl;
	cout << "Pici na promocija:" << endl;
	p1.piciNaPromocija();

	cout << p2.getIme() << endl;
	cout << "Pici na promocija:" << endl;
	p2.piciNaPromocija();

	return 0;
}
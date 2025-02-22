/*

(40 поени)

Да се креира класа Patnik во која се чуваат податоци за патниците на еден воз и тоа: име (низа од максимум 100 знаци), класа на вагон во која се вози (цел број 1 или 2) и велосипед (булова променлива).

За оваа класа да се преоптоварат:

Оператор << - за печатење на информациите за патникот во формат:
Име на патник

Бројот на класата (1 или 2)

Дали има велосипед?

Потоа да се креира клaса Voz во која се чува: крајна дестинација (низа од максимум 100 знаци), динамички алоцирана низа од објекти од класата Patnik, како и број на елементи во низата (цел број), број на дозволени велосипеди (цел број).

За класата да се обезбедат:

Оператор += – за додавање нов патник во воз. Патник со велосипед ќе може да се качи во воз само ако возот го дозволува тоа.
Оператор << - за печатење на крајната дестинација до која вози и листата на патници
Функција со потпис: patniciNemaMesto(). Со оваа функција се пресметува вкупниот број на патници (од 1-ва класа и 2-ра класа) за кои нема место да влезат во возот со велосипед. Притоа треба да се внимава дека во пресметувањето на вкупниот број патници со велосипеди кои ќе влезат во возот прво треба да се земат предвид патниците од 1-ва класа, а потоа се дозволува да влегуваат патниците од 2-ра класа се додека не се достигне максималниот број на дозволени велосипеди во возот. На крај се печати бројот на патници со велосипеди кои остануваат (не влегуваат во возот) од 1-ва класа, а потоа од 2-ра класа.
For example:

Input	Result
Amsterdam
0
5
Ana 
1 
1
Kate
2
0
Ace
2
0
Borce
2
1
Mimi
2
0
Amsterdam
Kate
2
0

Ace
2
0

Mimi
2
0

Brojot na patnici od 1-va klasa koi ostanale bez mesto e: 0
Brojot na patnici od 2-ra klasa koi ostanale bez mesto e: 0

*/

#include<iostream>
#include<cstring>
using namespace std;

class Patnik{

private:
	char ime[100];
	int klasa;
	bool velosiped;

public:
	Patnik(const char *i = "", int k = 2, bool ve = false){
		strncpy(ime, i, 99);
		ime[99] = '\0';
		klasa = k;
		velosiped= ve;
	}

	int getKlasa() { return klasa; }
	bool getVelosiped() { return velosiped; }

	friend ostream& operator<<(ostream& out, Patnik &p){
		out << p.ime << endl;
		out << p.klasa << endl;
		out << p.velosiped << endl;
		return out;
	}

};

class Voz{

private:
	char destinacija[100];
	Patnik *patnici;
	int br;
	int maxVelosipedi;
public:
	Voz(const char *d = "", int mve = 0){
		strncpy(destinacija, d, 99);
		destinacija[99] = '\0';
		patnici = NULL;
		br = 0;
		maxVelosipedi = mve;
	}
	~Voz(){
		delete[] patnici;
	}

	Voz& operator+=(Patnik &p){
		int f = 0;
		if ((p.getVelosiped()&&maxVelosipedi > 0) || !p.getVelosiped())
		{
			Patnik *tmp = new Patnik[br + 1];
			for (int i = 0; i < br; i++){
				tmp[i] = patnici[i];
			}
			tmp[br] = p;
			br++;
			delete[] patnici;
			patnici = tmp;
		}

		return *this;
	}

	friend ostream& operator<<(ostream& out, Voz &v){
		out << v.destinacija << endl;
		for (int i = 0; i < v.br; i++)
			out << v.patnici[i] << endl;
		return out;
	}

	void patniciNemaMesto(){
		int pat1 = 0, pat2 = 0, nepat1 = 0, nepat2 = 0;
		for (int i = 0; i < br; i++){
			if (patnici[i].getKlasa() == 1&&patnici[i].getVelosiped()){
				pat1++;
				if (pat1 > maxVelosipedi){
					nepat1++;
				}
			}
        }
        for (int i = 0; i < br; i++){
            if (patnici[i].getKlasa() == 2&&patnici[i].getVelosiped()){
				pat2++;
				if ((pat1+pat2) > maxVelosipedi){
					nepat2++;
				}
			}
		}

		cout << "Brojot na patnici od 1-va klasa koi ostanale bez mesto e: " << nepat1 << endl;
		cout << "Brojot na patnici od 2-ra klasa koi ostanale bez mesto e: " << nepat2 << endl;
	}
};


int main()
{
	Patnik p;
	char ime[100], destinacija[100];
	int n;
	bool velosiped;
	int klasa;
	int maxv;
	cin >> destinacija >> maxv;
	cin >> n;
	Voz v(destinacija, maxv);
	//cout<<v<<endl;
	for (int i = 0; i < n; i++){
		cin >> ime >> klasa >> velosiped;
		Patnik p(ime, klasa, velosiped);
		//cout<<p<<endl;
		v += p;
	}
	cout << v;
	v.patniciNemaMesto();

	return 0;
}
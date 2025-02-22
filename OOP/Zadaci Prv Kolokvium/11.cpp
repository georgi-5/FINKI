#include <iostream>
#include <cstring>
using namespace std;
class Ucesnik {
private:
	char *ime;
    bool maski;
    int vozrast;

public:
	Ucesnik() {

	}
	Ucesnik(const char *i, bool m, int v) {
		ime = new char[strlen(i) + 1];
        strcpy(ime, i);
		maski = m;
		vozrast = v;
	}
	Ucesnik(const Ucesnik &u) {
		ime = new char[strlen(u.ime) + 1];
        strcpy(ime, u.ime);
		maski = u.maski;
		vozrast = u.vozrast;
	}
	Ucesnik& operator=(const Ucesnik &u) {
		if (this == &u)
			return *this;
		delete[] ime;
		ime = new char[strlen(u.ime) + 1];
        strcpy(ime, u.ime);
		maski = u.maski;
		vozrast = u.vozrast;
		return *this;
	}
	~Ucesnik() {
		delete [] ime;
	}
	bool operator>(const Ucesnik &u) {
		return vozrast > u.vozrast;
	}

	friend ostream& operator<<(ostream& out, const Ucesnik &u) {
		out << u.ime << endl;
        if(u.maski) {
            cout << "mashki" << endl;
        } else {
            cout << "zhenski" << endl;
        }
		out << u.vozrast << endl;
		return out;
	}

	int getVozrast() {
        return vozrast;
	}
};
class Maraton {
private:
    char lokacija[100];
	Ucesnik *list;
	int n;
public:
	Maraton(const char *l) {
        strcpy(lokacija, l);
		list = NULL;
		n = 0;
	}
	~Maraton() {
		delete [] list;
	}
	Maraton& operator+=(const Ucesnik &u) {
		Ucesnik *tmp = list;
		list = new Ucesnik[n + 1];
		for (int i = 0; i < n; i++) {
			list[i] = tmp[i];
		}
		list[n] = u;
		n++;
		delete[] tmp;
		return *this;
	}
	void pecatiPomladi(Ucesnik &u) {
        for(int i = 0; i < n; ++i) {
            if(u > list[i]) {
            	cout << list[i];
            }
        }
	}
	float prosecnoVozrast() {
		float total = 0;
        for(int i = 0; i < n; ++i) {
            total += list[i].getVozrast() ;
        }
        return total / n;
	}
};
int main() {
    char ime[100];
    bool maski;
    int vozrast, n;
    cin >> n;
    char lokacija[100];
    cin >> lokacija;
    Maraton m(lokacija);
    Ucesnik **u = new Ucesnik*[n];
    for(int i = 0; i < n; ++i) {
        cin >> ime >> maski >> vozrast;
    	u[i] = new Ucesnik(ime, maski, vozrast);
        m += *u[i];
    }
	m.pecatiPomladi(*u[n - 1]);
    cout << m.prosecnoVozrast() << endl;
    for(int i = 0; i < n; ++i) {
        delete u[i];
    }
    delete [] u;
	return 0;
}
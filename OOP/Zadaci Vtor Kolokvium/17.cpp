#include <iostream>
#include <cstring>
using namespace std;

// vashiot kod ovde
class FudbalskaEkipa {
protected:
    char teren[100];
    int golovi[10];
    int index;
public:
    FudbalskaEkipa():index(0) {
    }
    FudbalskaEkipa(char *teren,int *golovi) {
        strcpy(this->teren,teren);
        for(int i=0; i<10; i++) {
            this->golovi[i]=golovi[i];
        }
        index=0;
    }
    FudbalskaEkipa(const FudbalskaEkipa &fe) {
        strcpy(this->teren,fe.teren);
        for(int i=10; i>0; i--) {
            this->golovi[i]=fe.golovi[i];
        }
        index=fe.index;
    }
    FudbalskaEkipa& operator==(const FudbalskaEkipa &fe) {
        if(this!=&fe) {
            strcpy(this->teren,fe.teren);
            for(int i=10; i>0; i--) {
                this->golovi[i]=fe.golovi[i];
            }
            index=fe.index;
        }
        return *this;
    }
    virtual int uspeh() const=0;
    virtual ostream& output(ostream& out)const {
        out<<teren<<endl;
        return out;
    }
    friend ostream& operator<<(ostream &out,const FudbalskaEkipa &fe) {

    return fe.output(out);
    }
    bool operator>(FudbalskaEkipa &f) {
        return uspeh()>f.uspeh();
    }
    FudbalskaEkipa& operator+=(int novi) {
        golovi[index]=novi;
        index=(index+1)%10;
        return *this;
    }
    virtual ~FudbalskaEkipa(){}
};
class Klub:public FudbalskaEkipa {
private:
    string ime;
    int brTituli;
public:
    Klub(){}
    Klub(char *teren,int *golovi,string ime,int brTituli):FudbalskaEkipa(teren,golovi) {
        this->ime=ime;
        this->brTituli=brTituli;
    }

    friend ostream& operator<<(ostream &out,Klub &fe) {
        return fe.output(out);
    }
    int uspeh() const {
        int sum=0;
        for(int i=0; i<10; i++) {
            sum+=golovi[i];
        }
        int final=0;
        final=(sum*3)+(brTituli*1000);
        return final;
    }
    ostream& output(ostream &out)const {
        out<<ime<<endl;
        out<<teren<<endl;
        out<<uspeh()<<endl;
        return out;
    }
    bool operator>(Klub &k) {
        return uspeh()>k.uspeh();
    }
    ~Klub(){}
};
class Reprezentacija:public FudbalskaEkipa {
private:
    string imeDrzava;
    int brNastani;
public:
    Reprezentacija(){}
    Reprezentacija(char *teren,int *golovi,string imeDrzava,int brNastani):FudbalskaEkipa(teren,golovi) {
        this->imeDrzava=imeDrzava;
        this->brNastani=brNastani;
    }
    ostream& output(ostream &out) const {
        out<<imeDrzava<<endl;
        out<<teren<<endl;
        out<<uspeh()<<endl;
        return out;
    }
    friend ostream& operator<<(ostream &out,Reprezentacija &fe) {
       return fe.output(out);
    }
    int uspeh() const {
        int sum=0;
        for(int i=0; i<10; i++) {
            sum+=golovi[i];
        }
        int final=0;
        final=(sum*3)+(brNastani*50);
        return final;
    }
    bool operator>(Reprezentacija &k) {
        return uspeh()>k.uspeh();
    }
    ~Reprezentacija(){}
};
void najdobarTrener(FudbalskaEkipa **ekipi, int n) {
        int max=0;
        int index=0;
    for(int i=0; i<n; i++) {
        if(ekipi[i]->uspeh()>max) {
            max=ekipi[i]->uspeh();
            index=i;
        }
    }
    cout<<*ekipi[index];
}
int main() {
    int n;
    cin >> n;
    FudbalskaEkipa **ekipi = new FudbalskaEkipa*[n];
    char coach[100];
    int goals[10];
    char x[100];
    int tg;
    for (int i = 0; i < n; ++i) {
        int type;
        cin >> type;
        cin.getline(coach, 100);
        cin.getline(coach, 100);
        for (int j = 0; j < 10; ++j) {
            cin >> goals[j];
        }
        cin.getline(x, 100);
        cin.getline(x, 100);
        cin >> tg;
        if (type == 0) {
            ekipi[i] = new Klub(coach, goals, x, tg);
        } else if (type == 1) {
            ekipi[i] = new Reprezentacija(coach, goals, x, tg);
        }
    }
    cout << "===== SITE EKIPI =====" << endl;
    for (int i = 0; i < n; ++i) {
        cout << *ekipi[i];
    }
    cout << "===== DODADI GOLOVI =====" << endl;
    for (int i = 0; i < n; ++i) {
        int p;
        cin >> p;
        cout << "dodavam golovi: " << p << endl;
        *ekipi[i] += p;
    }
    cout << "===== SITE EKIPI =====" << endl;
    for (int i = 0; i < n; ++i) {
        cout << *ekipi[i];
    }
    cout << "===== NAJDOBAR TRENER =====" << endl;
    najdobarTrener(ekipi, n);
    for (int i = 0; i < n; ++i) {
        delete ekipi[i];
    }
    delete [] ekipi;
    return 0;
}vvvvvvvv
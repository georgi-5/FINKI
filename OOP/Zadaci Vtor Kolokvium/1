#include <iostream>
#include <cstring>
using namespace std;
class Book{
protected:
    char isbn[20];
    char naslov[50];
    char avtor[30];
    float cena;
public:
    Book(){}
    Book(char *isbn,char *naslov,char *avtor,float cena){
        strcpy(this->isbn,isbn);
        strcpy(this->naslov,naslov);
        strcpy(this->avtor,avtor);
        this->cena=cena;
    }
    Book(const Book &b){
        strcpy(this->isbn,b.isbn);
        strcpy(this->naslov,b.naslov);
        strcpy(this->avtor,b.avtor);
        this->cena=b.cena;
    }
    Book& operator=(const Book &b){
        if(this!=&b){
        strcpy(this->isbn,b.isbn);
        strcpy(this->naslov,b.naslov);
        strcpy(this->avtor,b.avtor);
        this->cena=b.cena;
        }
        return *this;
    }
    virtual float bookPrice()=0;

    friend ostream& operator<<(ostream &out,Book &b){
        out<<b.isbn<<": "<<b.naslov<<", "<<b.avtor<<" "<<b.bookPrice();
        return out;
    }
    bool operator>(const Book &b){
        return this->cena>b.cena;
    }
    void setISBN(char *isbn){
        strcpy(this->isbn,isbn);
    }
    virtual bool isOnline()=0;
};
class OnlineBook:public Book{
private:
    char *url;
    int mb;
public:
    OnlineBook(){
        this->url=new char[0];
        mb=0;
    }
    OnlineBook(char *isbn,char *naslov,char *avtor,float cena,char *url,int mb):Book(isbn,naslov,avtor,cena){
        this->url=new char[strlen(url)+1];
        strcpy(this->url,url);
        this->mb=mb;
    }
    float bookPrice(){
        float procent=cena*0.2;
        float rez=cena;
        if(mb>20){
            rez+=procent;
        }
        return rez;
    }
    friend ostream& operator<<(ostream &out, OnlineBook &ob){
        out<<ob.isbn<<": "<<ob.naslov<<", "<<ob.avtor<<" "<<ob.bookPrice()<<endl;
        return out;
    }
    bool isOnline(){
    return true;
    }

};
class PrintBook:public Book{
private:
    float kg;
    bool zaliha;
public:
    PrintBook(){}
    PrintBook(char *isbn,char *naslov,char *avtor,float cena,float kg,bool zaliha):Book(isbn,naslov,avtor,cena){
        this->kg=kg;
        this->zaliha=zaliha;
    }
    float bookPrice(){
        float procent=cena*0.15;
        float rez=cena;
        if(kg>0.7){
            rez+=procent;
        }
        return rez;
    }
    friend ostream& operator<<(ostream &out,PrintBook &pb){
        out<<pb.cena;
        out<<pb.isbn<<": "<<pb.naslov<<", "<<pb.avtor<<" "<<pb.bookPrice()<<endl;
        return out;
    }
    bool isOnline(){
        return false;
    }
};
void mostExpensiveBook(Book **books,int n){
    float maxCena=0.0;
    int online=0;
    int print=0;
    int index=0;
    for(int i=0; i<n; i++){
            if(books[i]->isOnline()){
                online++;
            }
            else{
                print++;
            }
            float currentPrice=books[i]->bookPrice();
        if(currentPrice>maxCena){
            maxCena=currentPrice;
            index=i;
        }
    }
cout<<"FINKI-Education"<<endl;
cout<<"Total number of online books: "<<online<<endl;
cout<<"Total number of print books: "<<print<<endl;
cout<<"The most expensive book is:"<<endl;
cout<<*books[index]<<endl;
}
using namespace std;
int main(){

	char isbn[20], title[50], author[30], url[100];
	int size, tip;
	float price, weight;
	bool inStock;
	Book  **books;
	int n;

	int testCase;
	cin >> testCase;

	if (testCase == 1){
		cout << "====== Testing OnlineBook class ======" << endl;
		cin >> n;
		books = new Book *[n];

		for (int i = 0; i < n; i++){
			cin >> isbn;
			cin.get();
			cin.getline(title, 50);
			cin.getline(author, 30);
			cin >> price;
			cin >> url;
			cin >> size;
			cout << "CONSTRUCTOR" << endl;
			books[i] = new OnlineBook(isbn, title, author, price, url, size);
			cout << "OPERATOR <<" << endl;
			cout << *books[i]<<endl;
		}
		cout << "OPERATOR >" << endl;
		cout << "Rezultat od sporedbata e: " << endl;
		if (*books[0] > *books[1])
			cout << *books[0];
		else
			cout << *books[1];
	}
	if (testCase == 2){
		cout << "====== Testing OnlineBook CONSTRUCTORS ======" << endl;
		cin >> isbn;
		cin.get();
		cin.getline(title, 50);
		cin.getline(author, 30);
		cin >> price;
		cin >> url;
		cin >> size;
		cout << "CONSTRUCTOR" << endl;
		OnlineBook ob1(isbn, title, author, price, url, size);
		cout << ob1 << endl;
		cout << "COPY CONSTRUCTOR" << endl;
		OnlineBook ob2(ob1);
		cin >> isbn;
		ob2.setISBN(isbn);
		cout << ob1 << endl;
		cout << ob2 << endl;
		cout << "OPERATOR =" << endl;
		ob1 = ob2;
		cin >> isbn;
		ob2.setISBN(isbn);
		cout << ob1 << endl;
		cout << ob2 << endl;
	}
	if (testCase == 3){
		cout << "====== Testing PrintBook class ======" << endl;
		cin >> n;
		books = new Book *[n];

		for (int i = 0; i < n; i++){
			cin >> isbn;
			cin.get();
			cin.getline(title, 50);
			cin.getline(author, 30);
			cin >> price;
			cin >> weight;
			cin >> inStock;
			cout << "CONSTRUCTOR" << endl;
			books[i] = new PrintBook(isbn, title, author, price, weight, inStock);
			cout << "OPERATOR <<" << endl;
			cout << *books[i]<<endl;;
		}
		cout << "OPERATOR >" << endl;
		cout << "Rezultat od sporedbata e: " << endl;
		if (*books[0] > *books[1])
			cout << *books[0];
		else
			cout << *books[1];
	}
	if (testCase == 4){
		cout << "====== Testing method mostExpensiveBook() ======" << endl;
		cin >> n;
		books = new Book *[n];

		for (int i = 0; i<n; i++){

			cin >> tip >> isbn;
			cin.get();
			cin.getline(title, 50);
			cin.getline(author, 30);
			cin >> price;
			if (tip == 1) {

				cin >> url;
				cin >> size;

				books[i] = new OnlineBook(isbn, title, author, price, url, size);

			}
			else {
				cin >> weight;
				cin >> inStock;

				books[i] = new PrintBook(isbn, title, author, price, weight, inStock);
			}
		}

		mostExpensiveBook(books, n);
	}

	for (int i = 0; i<n; i++) delete books[i];
		delete[] books;
	return 0;
}

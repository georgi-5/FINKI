/*
Да се имплементира класа List во којашто ќе се чуваат информации за:

броеви што се дел од листата (динамички алоцирана низа од цели броеви)
бројот на броеви што се дел од листата
За класата да се дефинираат следните методи:

конструктор (со аргументи), copy-конструктор, деструктор, оператор =
void pecati()метод што ќе ги печати информациите за листата во форматот: [број на елементи во листата]: x1 x2 .. xn sum: [сума] average: [просек]
int sum() метод што ја враќа сумата на елементите во листата
double average() метод што ќе го враќа просекот на броевите во листата
Дополнително, креирајте класата ListContainer, во која што ќе се чуваат информации за:

низа од листи (динамички алоцирана низа од објекти од класата List)
број на елементи во низата од листи (цел број)
број на обиди за додавање на листа во контејнерот (цел број првично поставен на нула)
За класата потребно е да ги дефинирате следните методи:

конструктор (default), copy-конструктор, деструктор, оператор =
void pecati() метод што ќе ги печати информациите за контејнерот во форматот: List number: [реден број на листата] List info: [испечатени информации за листата со методот List::pecati()] \n sum: [сума] average: [просек]
доколку контејнерот е празен се печати само порака The list is empty.
void addNewList(List l) метод со којшто се додава листа во контејнерот
Напомена: една листа се додава во контејнерот ако и само ако има различна сума од сите листи што се веќе додадени во контејнерот
int sum() метод што ја враќа сумата на сите елементи во сите листи
double average() метод што го враќа просекот на сите елементи во сите листи во контејнерот
For example:

Input	Result
2
1
1
2
0 1
0
List number: 1 List info: 1: 1 sum: 1 average: 1
Sum: 1 Average: 1
Successful attempts: 1 Failed attempts: 1

*/

#include<iostream>
using namespace std;

class List {
	int * numbers;
	int n;
	
	void copy(const List &l){
		this->n=l.n;
		numbers = new int [l.n+1];
		
		for (int i=0;i<n;i++)
			this->numbers[i]=l.numbers[i];
	}
	
	public:
	List() {}
	
	//constructor
	List (int * numbers, int n) {
		this->n=n;
		this->numbers = new int [n+1];
		
		for (int i=0;i<n;i++){
			this->numbers[i]=numbers[i];
		}
	}
	
	List (const List &l){
		copy(l);
	}
	
	List &operator = (const List &l){
		if (this!=&l){
			delete [] numbers;
			copy(l);
		}
		return *this;
	}
	
	~List() {
		delete [] numbers;
	}
	
	
	
	void print() {
		cout<<n<<": ";
		for (int i=0;i<n;i++){
			cout<<numbers[i]<<" ";
		}
		cout<<"sum: "<<sum()<<" average: "<<average()<<endl;
	}
	
	int sum() {
		int s = 0;
		for (int i=0;i<n;i++){
			s+=numbers[i];
		}
		
		return s;
	}
	
	double average() {
		return (double) sum() / n;
	}
	
	int getN () {
		return n;
	}
};

class ListContainer{
	List * lists;
	int n;
	int failedAttempts;
	
	void copy(const ListContainer &lc){
		this->failedAttempts = lc.failedAttempts;
		this->n=lc.n;
		lists = new List [this->n+1];
		for (int i=0;i<this->n;i++)
			lists[i]=lc.lists[i];
	}
	
	public:
	ListContainer () {
		n = failedAttempts = 0;
		lists = new List [0];
	}
	
	ListContainer (const ListContainer &lc){
		copy(lc);
	}
	
	ListContainer &operator = (const ListContainer &lc){
		if (this!=&lc){
			delete [] lists;
			copy(lc);
		}
		
		return *this;
	}
	
	~ListContainer() {
		delete [] lists;
	}
	
	void addNewList(List l){
		for (int i=0;i<n;i++)
			if (lists[i].sum()==l.sum()){
				failedAttempts++;
				return;				
			}
				
		
		List * tmp = new List[n+1];
		
		for (int i=0;i<n;i++)
			tmp[i]=lists[i];
		
		tmp[n++]=l;
		
		delete [] lists;
		
		lists = tmp;
	}
	
	int sum() {
		int s = 0;
		for (int i=0;i<n;i++){
			s+=lists[i].sum();
		}
		return s;
	}
	
	double average() {
		int sN = 0;
		for (int i=0;i<n;i++){
			sN+=lists[i].getN();
		}
		return (double) sum() / sN;
	}
	
	void print () {
        if (n==0){
            cout<<"The list is empty"<<endl;
            return;
        }
		for (int i=0;i<n;i++){
			cout<<"List number: "<<i+1<<" List info: ";
			lists[i].print();		
		}
		cout<<"Sum: "<<sum()<<" Average: "<<average()<<endl;
		cout<<"Successful attempts: "<<n<<" Failed attempts: "<<failedAttempts<<endl;
	}
};

int main() {
	
	ListContainer lc;
	int N;	
	cin>>N;	
    //cout<<N;
	for (int i=0;i<N;i++) {
		int n;
		int niza[100];
		
		cin>>n;
        //cout<<n;
		for (int j=0;j<n;j++){
			cin>>niza[j];
            //cout<<niza[j];
		}
        //cout<<"Greshka";
		List l=List(niza,n);
		//l.print();
		lc.addNewList(l);
	}	
	
    
    int testCase;
    cin>>testCase;
    
    if (testCase==1) {
        cout<<"Test case for operator ="<<endl;
        ListContainer lc1;
        lc1.print();
        cout<<lc1.sum()<<" "<<lc.sum()<<endl;
        lc1=lc;
        lc1.print();
        cout<<lc1.sum()<<" "<<lc.sum()<<endl;
        
    }
    else {
        lc.print();
    }
}
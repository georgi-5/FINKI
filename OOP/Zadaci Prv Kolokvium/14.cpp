#include<iostream>
#include<cstring>

using namespace std;
enum Extension{PDF,TXT,EXE};
class File{
private:
    char *imeDat;
    Extension tip;
    char *imeSops;
    int goleminaMb;
public:
    File(){
    this->imeDat=new char[0];
    this->tip=TXT;
    this->imeSops=new char[0];
    this->goleminaMb=0;
    }
    File(char *imeDat,char *imeSops,int goleminaMb,Extension tip){
        this->imeDat=new char[strlen(imeDat)+1];
        strcpy(this->imeDat,imeDat);
        this->imeSops=new char[strlen(imeSops)+1];
        strcpy(this->imeSops,imeSops);
        this->goleminaMb=goleminaMb;
        this->tip=tip;
    }
    File(const File &f){
        this->imeDat=new char[strlen(f.imeDat)+1];
        strcpy(this->imeDat,f.imeDat);
        this->imeSops=new char[strlen(f.imeSops)+1];
        strcpy(this->imeSops,f.imeSops);
        this->goleminaMb=f.goleminaMb;
        this->tip=f.tip;
    }
    File& operator=(const File &f){
        if(this!=&f){
            delete []imeDat;
            delete []imeSops;
        this->imeDat=new char[strlen(f.imeDat)+1];
        strcpy(this->imeDat,f.imeDat);
        this->imeSops=new char[strlen(f.imeSops)+1];
        strcpy(this->imeSops,f.imeSops);
        this->goleminaMb=f.goleminaMb;
        this->tip=f.tip;
        }
        return *this;
    }
    ~File(){
    delete []imeDat;
    delete []imeSops;
    }
    bool equals(const File &f){
        if(strcmp(this->imeDat,f.imeDat)==0 && this->tip==f.tip && strcmp(this->imeSops,f.imeSops)==0){
            return 1;
        }
        else{
            return 0;
        }
    }
    bool equalsType(const File &f){
        if(strcmp(this->imeDat,f.imeDat)==0 && this->tip==f.tip){
            return 1;
        }
        else{
            return 0;
        }
    }
    string enumToString(Extension tip){
    switch(tip){
        case Extension::EXE:
        return "exe";
        case Extension::PDF:
            return "pdf";
        case Extension::TXT:
            return "txt";

    }
    }
    void print(){
     cout<<"File name: "<<imeDat<<"."<<enumToString(tip)<<endl;
     cout<<"File owner: "<<imeSops<<endl;
     cout<<"File size: "<<goleminaMb<<endl;
    }
};
class Folder{
private:
    char *ime;
    int brDat;
    File *files;
public:

    Folder(){
        this->ime=nullptr;
        this->brDat=NULL;
        this->files=nullptr;
    }
    Folder(const char *ime){
        this->ime=new char[strlen(ime)+1    ];
        strcpy(this->ime,ime);
            brDat=0;
            files=nullptr;

    }

    ~Folder(){
    delete []ime;
    delete []files;
    }
    Folder &remove(const File &f){
        int br=0;
        for(int i=0; i<brDat; i++){
            if(files[i].equals(f)){
                br++;
                break;
            }
        }
        if(br>0){
            File *temp=new File[brDat-1];
            int j=0;
            bool izbrisiPrv=false;
            for(int i=0; i<brDat; i++){
                if(izbrisiPrv==false){
                if(!files[i].equals(f)){
                    temp[j]=files[i];
                    j++;}
                    else
                    izbrisiPrv=true;

            }
                else
                {
                    temp[j]=files[i];
                    j++;
                }
            }
            delete []files;
            files=temp;
            brDat--;
        }
    return *this;
    }
    Folder &add(const File &f){
        for(int i=0; i<brDat; i++){
            if(files[i].equals(f)){
               return *this;
            }
        }
            File *temp=new File[brDat+1];
            for(int i=0; i<brDat; i++){
                temp[i]=files[i];
            }
            temp[brDat]=f;
            delete []files;
            files=temp;
            brDat++;
         return *this;
    }
    void print()const{
     cout<<"Folder name: "<<ime<<endl;
     for (int i = 0; i < brDat; ++i) {
            files[i].print();
        }
    }
};
int main() {
	char fileName[20];
	char fileOwner[20];
	int ext;
	int fileSize;

	int testCase;
	cin >> testCase;
	if (testCase == 1) {
		cout << "======= FILE CONSTRUCTORS AND = OPERATOR =======" << endl;
		cin >> fileName;
		cin >> fileOwner;
		cin >> fileSize;
		cin >> ext;

		File created = File(fileName, fileOwner, fileSize, (Extension) ext);
		File copied = File(created);
		File assigned = created;

		cout << "======= CREATED =======" << endl;
		created.print();
		cout << endl;
        cout << "======= COPIED =======" << endl;
		copied.print();
		cout << endl;
        cout << "======= ASSIGNED =======" << endl;
		assigned.print();
	}
	else if (testCase == 2) {
		cout << "======= FILE EQUALS & EQUALS TYPE =======" << endl;
		cin >> fileName;
		cin >> fileOwner;
		cin >> fileSize;
		cin >> ext;

		File first(fileName, fileOwner, fileSize, (Extension) ext);
		first.print();

		cin >> fileName;
		cin >> fileOwner;
		cin >> fileSize;
		cin >> ext;

		File second(fileName, fileOwner, fileSize, (Extension) ext);
		second.print();

		cin >> fileName;
		cin >> fileOwner;
		cin >> fileSize;
		cin >> ext;

		File third(fileName, fileOwner, fileSize, (Extension) ext);
		third.print();

		bool equals = first.equals(second);
		cout << "FIRST EQUALS SECOND: ";
		if (equals)
			cout << "TRUE" << endl;
		else
			cout << "FALSE" << endl;

		equals = first.equals(third);
		cout << "FIRST EQUALS THIRD: ";
		if (equals)
			cout << "TRUE" << endl;
		else
			cout << "FALSE" << endl;

		bool equalsType = first.equalsType(second);
		cout << "FIRST EQUALS TYPE SECOND: ";
		if (equalsType)
			cout << "TRUE" << endl;
		else
			cout << "FALSE" << endl;

		equalsType = second.equals(third);
		cout << "SECOND EQUALS TYPE THIRD: ";
		if (equalsType)
			cout << "TRUE" << endl;
		else
			cout << "FALSE" << endl;

	}
	else if (testCase == 3) {
		cout << "======= FOLDER CONSTRUCTOR =======" << endl;
		cin >> fileName;
		Folder folder(fileName);
		folder.print();

	}
	else if (testCase == 4) {
		cout << "======= ADD FILE IN FOLDER =======" << endl;
		char name[20];
		cin >> name;
		Folder folder(name);

		int iter;
		cin >> iter;

		while (iter > 0) {
			cin >> fileName;
			cin >> fileOwner;
			cin >> fileSize;
			cin >> ext;

			File file(fileName, fileOwner, fileSize, (Extension) ext);
			folder.add(file);
			iter--;
		}
		folder.print();
	}
	else {
		cout << "======= REMOVE FILE FROM FOLDER =======" << endl;
		char name[20];
		cin >> name;
		Folder folder(name);

		int iter;
		cin >> iter;

		while (iter > 0) {
			cin >> fileName;
			cin >> fileOwner;
			cin >> fileSize;
			cin >> ext;

			File file(fileName, fileOwner, fileSize, (Extension) ext);
			folder.add(file);
			iter--;
		}
		cin >> fileName;
		cin >> fileOwner;
		cin >> fileSize;
		cin >> ext;

		File file(fileName, fileOwner, fileSize, (Extension) ext);
		folder.remove(file);
		folder.print();
	}
	return 0;
}
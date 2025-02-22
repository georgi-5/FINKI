#include <iostream>
#include <cstring>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;
class StudentFailedException{
private:
    string msg;
public:
    StudentFailedException(string msg){
        this->msg=msg;
    }
    void print(){
        cout<<msg<<endl;
    }
};
using namespace std;
class Student {
private:
    string index;
    string ime;
    string prezime;
    int poeni;
public:
    Student(){}
    Student(string index,string ime,string prezime,int poeni){
        this->index=index;
        this->ime=ime;
        this->prezime=prezime;
        this->poeni=poeni;
    }
    Student(const Student &s){
        this->index=s.index;
        this->ime=s.ime;
        this->prezime=s.prezime;
        this->poeni=s.poeni;
    }
    Student& operator=(const Student &s){
        if(this!=&s){
        this->index=s.index;
        this->ime=s.ime;
        this->prezime=s.prezime;
        this->poeni=s.poeni;
        }
        return *this;
    }
    int getPoeni(){
        return poeni;
    }
    string getIndex(){
        return index;
    }
     int grade(){
        if(poeni<50){
            return 5;
        }
        if(poeni>=50 && poeni<=59){
            return 6;
        }
        if(poeni>=60 && poeni<=69){
            return 7;
        }
        if(poeni>=70 && poeni<=79){
            return 8;
        }
        if(poeni>=80 && poeni<=89){
            return 9;
        }
        if(poeni>=90 && poeni<=100){
            return 10;
        }
     }
     void setIme(string ime){
        this->ime=ime;
     }
     string getIme(){
        return ime;
     }
     friend ostream& operator<<(ostream &out,Student &s){
        out<<s.index<<" "<<s.ime<<" "<<s.prezime<<" "<<s.poeni<<" Grade: "<<s.grade()<<endl;
     }
     ~Student(){}
};
class Results {
private:
    Student *students;
    int n;
public:
    Results(){
        this->students=new Student[0];
        n=0;
    }
    Results(Student *students,int n){
        this->n=n;
        this->students=new Student[n];
        for(int i=0; i<n; i++){
            this->students[i]=students[i];
        }
    }
    Results(const Results &r){
        this->n=r.n;
        this->students=new Student[r.n];
        for(int i=0; i<r.n; i++){
            this->students[i]=r.students[i];
        }
    }
    Results& operator=(const Results &r){
        if(this!=&r){
        delete []students;
        this->n=r.n;
        this->students=new Student[r.n];
        for(int i=0; i<r.n; i++){
            this->students[i]=r.students[i];
        }
        }
    }
    Results& operator+=(Student &s){
       if(s.getPoeni()<50){
                string index=s.getIndex();
                throw StudentFailedException("Student with id "+index+" failed the course");
       }
        Student *temp=new Student[n+1];
        for(int i=0; i<n; i++){
            temp[i]=students[i];
        }
        temp[n++]=s;
        delete []students;
        students=temp;
        return *this;
    }
    Results withGrade(int grade){
        Results newNiza;
        for(int i=0; i<n; i++){
            if(students[i].grade()==grade){
                newNiza+=students[i];
            }
        }
        return newNiza;
    }
    friend ostream& operator<<(ostream &out,Results &r){
        for(int i=0; i<r.n; i++){
            out<<r.students[i];
        }
    }
    int getN(){
        return n;
    }
    ~Results(){
        delete []students;
    }
};
void wtf() {
    ofstream fout("input.txt");
    string line;
    while (getline(std::cin, line)) {
        if (line == "----"){
            break;
        }
        fout << line << endl;
    }
}

void rff(string path) {
    ifstream fin(path);
    string line;
    while (getline(fin, line)) {
        cout << line << endl;
    }
}


int main() {

    wtf();

    Results results;
    //TODO your code here
    //TODO Read the students from the file and add them in `results`
    ifstream ifs("input.txt");
    string index,ime,prezime;
    int poeni=0;
    string line;
    while(ifs>>index>>ime>>prezime>>poeni){
        try{
        Student s(index,ime,prezime,poeni);
        results+=s;
        }catch (StudentFailedException s){
            s.print();
        }
    }
    ifs.close();
    ofstream ofs1("output1.txt");
    ofs1<<results;
    ofs1.close();
    //DO NOT MODIFY THE CODE BETWEEN THIS AND THE NEXT COMMENT
    int grade;
    cin >> grade;
    //DO NOT MODIFY THE CODE BETWEEN THIS AND THE PREVIOUS COMMENT

    //TODO Save the results in the files output1.txt and output2.txt after this line
    ofstream ofs2("output2.txt");
    Results withR=results.withGrade(grade);
    if(withR.getN()!=0){
    ofs2<<withR;
    }
    else
    {
        ofs2<<"None";
    }
    ofs2.close();

    //DO NOT MODIFY THE CODE BELLOW

    cout << "All students:" << endl;
    rff("output1.txt");
    cout << "Grade report for grade " << grade << ": " << endl;
    rff("output2.txt");


    return 0;
}
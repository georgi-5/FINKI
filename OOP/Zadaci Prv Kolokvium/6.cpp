/*
Да се креира структура Воз во која се чуваат податоци за релацијата по која се движи возот (низа од најмногу 50 знаци), предвиден бројот на километри што треба да се поминат (реален број), како и бројот на патници во возот (цел број).

Потоа да се креирa структура ZeleznickaStanica во која се чуваат податоци за градот во кој се наоѓа (низа од 20 знаци), низа од возови што поаѓаат од станицата (најмногу 30) и бројот на возови (цел број).

Треба да се направи функција со потпис

void najkratkaRelacija(ZeleznickaStanica* zs, int n, char* grad)
во која се печати релацијата и бројот на километри на возот што поминува најкратка релација (најмалку километри), а поаѓа од железничката станица од градот што се проследува како влезен аргумент. Ако има повеќе возови со ист најмал број на километри, да се испечати релацијата на последниот таков.

Забелешка: Задачата да се реши во програмскиот јазик C++

For example:

Input	Result
1
Dresden
2
Dresden-Berlin 192 200
Dresden-Lajpcig 115 90
Dresden
Najkratka relacija: Dresden-Lajpcig (115 km)

*/

#include <iostream>
#include <cstring>
using namespace std;
struct Voz
{
    char relacija[50];
    float km;
    int brPatnici;
};
struct ZeleznickaStanica
{
    char grad[20];
    Voz v[30];
    int brVozovi;
};
void najkratkaRelacija(ZeleznickaStanica* z, int n, char *grad)
{
    bool najde=false;
    int index=0;
    int indexJ=0;
    int min=9999999999;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<z[i].brVozovi; j++)
        {
            if(strcmp(z[i].grad,grad)==0)
            {
                najde=true;
                if(min>=z[i].v[j].km)
                {
                    min=z[i].v[j].km;
                    index=i;
                    indexJ=j;
                }
            }
        }
        for(int j=0; j<z[i].brVozovi; j++)
        {
            if(strcmp(z[i].grad,grad)==0)
            {
                if(najde==true){
                    cout<<"Najkratka relacija: "<<z[index].v[indexJ].relacija<<" "<<"("<<z[index].v[indexJ].km<<" km)"<<endl;
                    break;
                }
            }
        }
    }
}
int main()
{
    ZeleznickaStanica z[100];
    int n;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>z[i].grad;
        cin>>z[i].brVozovi;
        for(int j=0; j<z[i].brVozovi; j++)
        {
            cin>>z[i].v[j].relacija>>z[i].v[j].km>>z[i].v[j].brPatnici;
        }
    }
    char grad[20];
    cin>>grad;
    najkratkaRelacija(z,n,grad);
    return 0;
}
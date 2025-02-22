#include <iostream>

using namespace std;

int main()
{
    int n,matrica[100][100],matricab[100][100];
    cin>>n;
    int red,kolona;
    red=n;
    kolona=n*2;
    for(int i=0; i<red; ++i){
        for(int j=0; j<kolona; ++j){
            cin>>matrica[i][j];

        }
    }
    int novred=n*2;
    int novakolona=n;
    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            matricab[i][j]=matrica[i][j];
        }

    }
    for(int i=0; i<red; ++i){
        for(int j=n; j<kolona; ++j){
            matricab[i+n][j-n]=matrica[i][j];
        }
    }
    for(int i=0; i<novred; ++i){
        for(int j=0; j<novakolona; ++j){
            cout<<matricab[i][j]<<" ";
        }
        cout<<endl;
    }


    return 0;
}
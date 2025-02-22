#include <iostream>

using namespace std;

int main()
{
    int x,m,n,matrica[100][100];
    cin>>x;
    cin>>m>>n;

    for(int i=0; i<m; ++i){
        for(int j=0; j<n; ++j)
        {
           cin>>matrica[i][j];
        }
    }
    for(int i=0; i<m; ++i){
        int zbir=0;
        for(int j=0; j<n; ++j)
        {
        zbir+=matrica[i][j];
        }
    if(zbir>x){
            for(int j=0; j<n; ++j)
        {
        matrica[i][j]=1;
        }
    }
    else if(zbir==x){
            for(int j=0; j<n; ++j)
        {
        matrica[i][j]=0;
        }
    }
    else if(zbir<x){
            for(int j=0; j<n; ++j)
        {
        matrica[i][j]=-1;
        }
    }
    }
    for(int i=0; i<m; ++i){
        for(int j=0; j<n; ++j)
        {
            cout<<matrica[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
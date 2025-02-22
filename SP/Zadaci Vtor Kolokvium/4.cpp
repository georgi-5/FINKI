#include <iostream>
#define fori for(int i=0; i<n; i++)
#define forj for(int j=0; j<m; j++)
using namespace std;

int main()
{
    int a[100][100],n,m,b,c;
    cin>>n>>m;
    fori{
    forj{
    cin>>a[i][j];
    }
    }
    cin>>b>>c;
    int s1,s2,s3,s4;
    s1=s2=s3=s4=0;
    fori{
    forj
        {
          if(i<b && j>=c){//r1
            s1=s1+a[i][j];
          }
          if(i<b && j<c){//r2
            s2=s2+a[i][j];
          }
          if(i>=b && j<c){//r3
            s3=s3+a[i][j];
          }
          if(i>=b && j>=c){//r4
            s4=s4+a[i][j];
          }
        }
    }
    cout<<s1<<" "<<s2<<" "<<s3<<" "<<s4;
    return 0;
}
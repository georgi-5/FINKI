#include <iostream>

using namespace std;

int main()
{
    int c,br=-1,br2=0,cifra=0,maxcifra=0;
    int x0=0,x1=0,x2=0,x3=0,x4=0;
    while(cin>>c){
        int pomosna=c;
        br2=0;
        br=-1;
        maxcifra=0;
        while(pomosna!=0){
            cifra=pomosna%10;
            pomosna/=10;
            br++;
            if(maxcifra<cifra){
                maxcifra=cifra;
                br2=br;
            }
        }
            if(br2==0){
                x0++;
            }
            else if(br2==1){
                x1++;
            }
             else if(br2==2){
                x2++;
            }
             else if(br2==3){
                x3++;
            }
             else if(br2==4){
                x4++;
            }
    }
    cout<<"0: "<<x0<<endl;
    cout<<"1: "<<x1<<endl;
    cout<<"2: "<<x2<<endl;
    cout<<"3: "<<x3<<endl;
    cout<<"4: "<<x4<<endl;
    return 0;
}
#include <iostream>
#include <climits>
using namespace std;
//a = 1234567
//b = 324

//a = 456564
//b = 23


int main()
{
    int a,b;
    cin>>a>>b;
    if(a<=0 || b<=0)
    {
        cout<<"Invalid input"<<endl;
    }
    else
    {
        //Sekogas a da bide pogolemo od b
        //a = 15   temp = 10
        //b = 10
        if(a<b)
        {//swap
            int temp = a;
            a = b;
            b = temp;
        }
        int flag=1;
        while(b!=0)
        {
            if(b%10!=a%100/10)
            {
                flag=0;
                break;
            }
            b = b/10;
            a = a/100;
        }
        if(flag==0)
        {
            cout<<"NE"<<endl;
        }
        else
        {
            cout<<"PAREN"<<endl;
        }

    }
    return 0;
}
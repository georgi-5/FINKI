/*
Благ број е број што е составен само од парни цифри (0, 2, 4, 6, 8).
Во зададен опсег (почетокот m и крајот на опегот n се цели броеви чија вредност се внесува од тастатура),

For example:

Input	Result
99 500
200


да се најде и испечати најмалиот „благ број“. Ако не постои таков број, да се испечати NE.*/


#include <iostream>

using namespace std;

int main()
{
    int a,b,cifra,flag,i;
    cin>>a>>b;
    for(i=a; i<=b; i++){
        int pomosna=i;
        while(pomosna!=0)
        {
            cifra=pomosna%10;
            pomosna/=10;
        if(cifra%2==0)
        {
            flag=1;
        }
        else
        {
            flag=0;
            break;
        }
        }
        if(flag==1){
            cout<<i;
            break;
        }

    }
    if(flag==0){
        cout<<"NE"<<endl;
    }
    return 0;
}

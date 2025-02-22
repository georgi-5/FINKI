#include <iostream>

using namespace std;
struct SkiLift
{
    char imeSki[15];
    int maxSeat;
    bool functional;
};
struct SkiCenter
{
    char imeCentar[20];
    char imeDrzava[20];
    SkiLift s[20];
    int brSki;
};
void najgolemKapacitet(SkiCenter *c,int n)
{
    int sum=0;
    int maxSum=0;
    int x;
    int l;
    int b;
    for(int i=0; i<n; i++)
    {

        sum=0;
        for(int j=0; j<c[i].brSki; j++)
        {
            if(c[i].s[j].functional==1)
            {
                sum+=c[i].s[j].maxSeat;
                if(maxSum<=sum){
                maxSum=sum;
                x=i;
                }
            }


        }

    }

        cout<<c[x].imeCentar<<endl;
        cout<<c[x].imeDrzava<<endl;
        cout<<maxSum;
}
int main()
{
    SkiCenter c[100];
    int n;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>c[i].imeCentar;
        cin>>c[i].imeDrzava;
        cin>>c[i].brSki;
        for(int j=0; j<c[i].brSki; j++)
        {
            cin>>c[i].s[j].imeSki;
            cin>>c[i].s[j].maxSeat;
            cin>>c[i].s[j].functional;
        }
    }
    najgolemKapacitet(c,n);
    return 0;
}
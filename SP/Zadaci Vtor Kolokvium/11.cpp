#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    string s;
    int counter=0;
    int arr[100];

    while(cin>>s){
        counter=0;
        if(s=="#"){
            break;
        }
        else{
            for(int i=0; i<s.length(); i++){
                char c=s.at(i);
                if(isdigit(c)){
                    arr[counter]=c-48;
                    counter++;
                }
            }
        }
        for(int i=0; i<counter; i++){
            for(int j=i+1; j<counter; j++){
                if(arr[i]>arr[j]){
                    int temp=arr[i];
                    arr[i]=arr[j];
                    arr[j]=temp;
                }
            }
        }
        
        cout<<counter<<":";
        for(int i=0; i<counter; i++){
            cout<<arr[i];
        }
    cout<<endl;
    }
    return 0;
}
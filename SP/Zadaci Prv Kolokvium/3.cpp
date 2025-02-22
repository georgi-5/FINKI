#include <iostream>

using namespace std;
//Од стандарден влез се чита еден природен број n.
// Меѓу природните броеви помали од n, да се најде оној чиј што збир на делителите е најголем.
// Во пресметувањето на збирот на делителите на даден број, да не се зема предвид самиот број.

int main()
{
    int n;
    cin>>n;
    int suma=0;
    int newsuma=0;
    int broj=0;
    for(int i=n-1; i>0; i--){
        suma=0;
        for(int j=1; j<i; j++){
            if(i%j==0){
                suma+=j;
            }
        }
        if(newsuma<suma){
            newsuma=suma;
            broj=i;
        }
    }
    cout<<broj;
    return 0;
}
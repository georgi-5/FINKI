#include <stdio.h>
#include <string.h>

struct Proizvod {
    char kod[20];
    int edincena;
    int brojmagacin;
};
typedef struct Proizvod Proizvod;

struct Narachka {
    char ime[15];
    Proizvod pole[10];
    int brojnaracani[10];
    int n;
};
typedef struct Narachka Narachka;

void pecatiFaktura(Narachka n){
printf("Faktura za %s\n",n.ime);
int i,j, daliMoze=1;
for ( i=0;i<n.n;i++){
    if (n.pole[i].brojmagacin<n.brojnaracani[i])
    {
        daliMoze=0;
        break;
    }
}
if (daliMoze==0){
    printf("Fakturata ne moze da se izgotvi");
}
else{
    for (i=0;i<n.n;i++){
            for(j=i+1;j<n.n;j++)
    if (strcmp(n.pole[i].kod,n.pole[j].kod)>0)
    {
        Proizvod pom=n.pole[i];
        n.pole[i]=n.pole[j];
        n.pole[j]=pom;

    }
    }
    int sum=0;
    for (i=0;i<n.n;i++){
            sum+=n.brojnaracani[i]*n.pole[i].edincena;
            n.pole[i].brojmagacin-=n.brojnaracani[i];
     printf("%s %d %d %d\n",n.pole[i].kod,n.pole[i].edincena,n.brojnaracani[i],n.brojnaracani[i]*n.pole[i].edincena);
    }
    printf("Vkupnata suma na fakturata e %d",sum);
}
}




int main() {

    Narachka narachka;

    scanf("%s", narachka.ime);
    scanf("%d", &narachka.n);
    int i;
    for (i = 0; i < narachka.n; ++i) {
        scanf("%s", narachka.pole[i].kod);
        scanf("%d", &narachka.pole[i].edincena);
        scanf("%d", &narachka.pole[i].brojmagacin);
    }
    int j;
    for (j = 0; j < narachka.n; ++j) {
        scanf("%d", &narachka.brojnaracani[j]);
    }


    //tuka se povikuva baranata funkcija
    pecatiFaktura(narachka);

 
    return 0;
}
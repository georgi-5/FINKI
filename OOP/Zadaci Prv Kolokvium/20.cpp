#include<stdio.h>
#include<string.h>

typedef struct Pacient{
	char ime[100];
	short zdrastveno;
	int pregledi;
}pacient;

typedef struct MaticenDoktor {
	char ime[100];
	pacient niza[200];
	int br_pac;
	float cena;
}doktor;

float suma_doktor(doktor md){
	int i;
	int suma = 0;
	for (i = 0; i < md.br_pac; i++){
		if (md.niza[i].zdrastveno == 0)
			suma += md.niza[i].pregledi;
	}
	return suma*md.cena;
}

int pregledi_doktor(doktor md){
	int i;
	int suma = 0;
	for (i = 0; i < md.br_pac; i++){
		suma += md.niza[i].pregledi;
	}
	return suma;
}

void najuspesen_doktor(doktor *md, int n)
{
	int tmp, i, j, max_ind;
	float max = 0.00;
	max_ind = 0;
	for (i = 0; i < n; i++)
	{
		float priv = suma_doktor(md[i]);
		//printf("%.2f\n", priv);
        if (priv == max){
			int broj = pregledi_doktor(md[i]);
			int broj_max = pregledi_doktor(md[max_ind]);
            //printf("%d %d\n", broj, broj_max);
			if (broj > broj_max){
				max = priv;
				max_ind = i;
			}
		}
        if (priv > max){
			max = priv;
			max_ind = i;
		}
	}
	printf("%s %.2f %d\n", md[max_ind].ime, max, pregledi_doktor(md[max_ind]));
}

int main()
{
	int i, j, n, broj;
	doktor md[200];
	scanf("%d", &n);
	for (i = 0; i < n; i++){
		//ime na doktor
		scanf("%s", &md[i].ime);
		//broj na pacienti
		scanf("%d", &md[i].br_pac);
		//cena na pregled
		scanf("%f", &md[i].cena);

		for (j = 0; j < md[i].br_pac; j++){
			scanf("%s", &md[i].niza[j].ime);
			scanf("%d", &md[i].niza[j].zdrastveno);
			scanf("%d", &md[i].niza[j].pregledi);
		}
	}
	najuspesen_doktor(md, n);

	return 0;
}
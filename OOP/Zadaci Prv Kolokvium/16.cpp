#include <stdio.h>
#include <string.h>
#define NEDELI 4
#define DENOVI 5

struct RabotnaNedela {
    int broj;
    int casovi[DENOVI];
};
typedef struct RabotnaNedela RN;

struct Rabotnik {
    char ime[50];
    RN nedeli[NEDELI];
};

typedef struct Rabotnik R;

int sum(int *x, int n) {
    int s = 0;
    int i;
    for (i = 0; i < n; ++i) {
        s += x[i];
    }
    return s;
}

int maxNedela(R *r) {
    int i;
    int max = 0;
    int maxi = 0;
    for (i = 0; i < NEDELI; ++i) {
        int s = sum(r->nedeli[i].casovi, DENOVI);
        if (s > max) {
            max = s;
            maxi = i;
        }
    }
    return maxi + 1;
}
void table(R *r, int n) {
    printf("Rab\t");
    int i;
    for (i = 0; i < NEDELI; ++i) {
        printf("%d\t", i + 1);
    }
    printf("Vkupno\n");
    for (i = 0; i < n; ++i) {
        printf("%s\t", r[i].ime);
        int j;
        int total = 0;
        for (j = 0; j < NEDELI; ++j) {
            int s = sum(r[i].nedeli[j].casovi, DENOVI);
            printf("%d\t", s);
            total += s;
        }
        printf("%d\n", total);
    }
}



int main() {
    int n;
    scanf("%d", &n);
    R rabotnici[n];
    int i;
    for (i = 0; i < n; ++i) {
        scanf("%s", rabotnici[i].ime);
        int j;
        for (j = 0; j < NEDELI; ++j) {
            int k;
            for (k = 0; k < DENOVI; ++k) {
                scanf("%d", &rabotnici[i].nedeli[j].casovi[k]);
            }

        }
    }
    printf("TABLE\n");
    table(rabotnici, n);
    printf("MAX NEDELA NA RABOTNIK: %s\n", rabotnici[n / 2].ime);
    printf("%d\n", maxNedela(&rabotnici[n / 2]));
    return 0;
}
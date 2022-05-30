#include <stdio.h>

int solicitar_grau();
void deriva(double poli[ ], int grau, double out[ ]);

int main (void) {
    printf("\nCalculadora de Derivada");
    int grau = solicitar_grau();
    double poli[grau], out[grau];
    deriva(&poli[grau], grau, &out[grau]);
}

int solicitar_grau() {
    int grau;
    printf("\n\nQual o grau do polinomio? ");
    scanf("%d", &grau);
    if (grau>10) {
        printf("\nGrau muito elevado!");
        solicitar_grau();
    }
    return grau;
}

void deriva(double poli[ ], int grau, double out[grau]) {
    int i = grau;
    printf("\nAgora voce ira digitar seus %d coeficientes (c), ordem da direita para a esquerda (<--).", grau+1);
    printf("\nExemplo: p(x) = ");
    while (i > 0) {
        printf("(%d)x^%d + ", i+1, i);
        i--;
    }
    printf("(1)\n\n");

    //solicitar coeficientes
    while (i <= grau) {
        printf("Qual o seu coeficiente (%d)? ", i+1);
        scanf("%lf", &poli[i]);
        i++;
    }

    //mostrar polinomio
    printf("\nDerivando seu polinomio:\np (x) = ");
    for (int i = grau; i > 1; i--) {
        printf("%.lfx^%d + ", poli[i], i);
    }
    printf("%.lfx ", poli[1]);
    printf("+ %.lf\n", poli[0]);

    //calcular dervidado
    int exp=grau;
    for (i = grau; i>=0; i--) {
        out[i-1] = poli[i]*exp;
        exp--;
    }

    //mostrar resolução
    printf("p'(x) = ");
    for (int i = grau; i > 1; i--) {
        printf("(%d.%.lf)x^(%d-1) + ", i, poli[i], i);
    }
    printf("(1.%.lf)x^(1-1)) ", poli[1]);
    printf("+ (0.%.lf)\n", poli[0]);

    //mostrar resultado
    printf("p'(x) = ");
    for (int i = grau-1; i > 1; i--) {
        printf("%.lfx^%d + ", out[i], i);
    }
    printf("%.lfx + %.lf + 0\n", out[1], out[0]);
}
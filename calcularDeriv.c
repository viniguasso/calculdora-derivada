#include <stdio.h>

int grau, i;
int poli[0], out[0];

int solicitar_grau() {
    printf("\n\nQual o grau do polinômio? ");
    scanf("%d", &grau);
    if (grau>10) {
        printf("\nGrau muito elevado!");
        solicitar_grau();
    }
    return grau;
}

int solicitar_coef(int grau) {
    printf("\nAgora você ira digitar seus %d coeficientes (c), ordem da direita para a esquerda (<--).", grau+1);
    printf("\nExemplo: p(x) = ");
    for (i = grau; i != 0; i--) {
        printf("(%dºc)x^%d + ", i+1, i);
    }
    printf("(1º)\n\n");

    for (i = 0; i <= grau; i++) {
        printf("Qual é seu %dº coeficiente? ", i+1);
        scanf("%d", &poli[i]);
    }
    
    printf("\nSeu polinômio: p(x) = ");
    for (i = grau; i != 0; i--) {
        printf("%d", poli[i]);
        if (i==1) {
            break;
        }
        printf("x^%d + ", i);
    }
    printf("x + %d\n", poli[0]);
    return poli[grau], grau;
}

int deriva (int grau) {
    int exp=grau;
    for (i=grau; i>=0; i--) {
        out[i] = poli[i]*exp;
        exp--;
    }

    printf("\nDerivada: p'(x) = ");
    for (i = grau; i != 0; i--) {
        printf("%d", out[i]);
        if (i==1) {
            break;
        }
        printf("x^%d + ", i-1);
    }
}

int main (void) {
    printf("\nCalculadora de Derivada");
    solicitar_grau();
    grau = solicitar_coef(grau);
    deriva(grau);
}
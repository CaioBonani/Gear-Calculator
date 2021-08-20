#include <stdio.h>
#include <locale.h>
#include <math.h>
#include <conio.h>
#define _USE_MATH_DEFINES

int main(void){
    setlocale(LC_ALL, "Portuguese_Brazil");

    FILE *pont_arq;
    pont_arq = fopen("engrenagem.txt", "w");

    if (pont_arq == NULL){
        printf("Não foi possível criar um arquivos com os dados da engrenagem...");
        return 1;
    }


    int zint;
    float m, z, alin, ap, apdivang,  wk, k, x, dmr, mdr, y;

    printf("\n\n");
    printf("      ||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||");
    printf("\n      |||||||||||||                                                        |||||||||||||");
    printf("\n      |||||||||||||   Programa para calcular dimensões de uma engrenagem   |||||||||||||");
    printf("\n      |||||||||||||                                                        |||||||||||||\n");
    printf("      ||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
    printf("\n\nQual o número de dentes: ");
    scanf("%f", &z);

    zint = (int) z;

    printf("\n\nQual o módulo: ");
    scanf("%f", &m);
    printf("\n\nQual o ângulo de pressão: ");
    scanf("%f", &ap);

    alin = m*(1+((z/2)*(1-cos((90*2*M_PI/360)/z))));

    x = m*z*sin((90*2*M_PI/360)/z);

    if(ap == 20.0f){
        apdivang = 20.0f/180.0f;
    } else if (ap == 15.0f){
        apdivang = 15.0f/180.0f;
    } else {
        apdivang = 14.5f/180.0f;
    }

    k = round((z*(apdivang))+0.5);

    if(ap == 20.0f){
        wk = m*(((2.952131*k)-1.476066)+(0.014904*z));
    } else if (ap == 15){
        wk = m*(((3.034545*k)-1.517273)+(0.006150*z));
    } else {
        wk = m*(((3.041526*k)-1.520763)+(0.005545*z));
    }

    dmr = 1.728*m;

    if (zint%2==0){
        if(ap == 20.0f){
            y = z*cos(20*2*M_PI/360)/cos((20+90/z)*2*M_PI/360);
        } else if (ap == 15.0f){
            y = z*cos(15*2*M_PI/360)/cos((15+90/z)*2*M_PI/360);
        } else {
            y = z*cos(14.5*2*M_PI/360)/cos((14.5+90/z)*2*M_PI/360);
        }

    } else {
        if(ap == 20.0f){
            y = z*cos(20*2*M_PI/360)/cos((20+90/z)*2*M_PI/360)*(cos((90/z)*2*M_PI/360));
        } else if (ap == 15.0f){
            y = z*cos(15*2*M_PI/360)/cos((15+90/z)*2*M_PI/360)*(cos((90/z)*2*M_PI/360));
        } else {
            y = z*cos(14.5*2*M_PI/360)/cos((14.5+90/z)*2*M_PI/360)*(cos((90/z)*2*M_PI/360));
        }
    }

    mdr = (m*y)+dmr;

    printf("  ||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||");
    fprintf(pont_arq,"  ||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||");

    printf("\n  ||||||||||||||||||||||||||                ||||||||||||||||||||||||||||||");
    fprintf(pont_arq, "\n  ||||||||||||||||||||||||||                ||||||||||||||||||||||||||||||");

    printf("\n  ||||||||||||||||||||||||||   Dimensões    ||||||||||||||||||||||||||||||");
    fprintf(pont_arq, "\n  ||||||||||||||||||||||||||   Dimensões    ||||||||||||||||||||||||||||||");

    printf("\n  ||||||||||||||||||||||||||                ||||||||||||||||||||||||||||||\n");
    fprintf(pont_arq, "\n  ||||||||||||||||||||||||||                ||||||||||||||||||||||||||||||\n");

    printf("  ||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
    fprintf(pont_arq, "  ||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");

    printf("\n---> Número de dentres da engrenagem: %d", zint);
    fprintf(pont_arq, "\n---> Número de dentres da engrenagem: %d", zint);

    printf("\n\n---> Módulo: %.0f", m);
    fprintf(pont_arq, "\n\n---> Módulo: %.0f", m);

    printf("\n\n---> Ângulo de pressão: %.1f", ap);
    fprintf(pont_arq, "\n\n---> Ângulo de pressão: %.1f", ap);

    printf("\n\n---> Altura do dente corrigida(a'): %.3f", alin);
    fprintf(pont_arq, "\n\n---> Altura do dente corrigida(a'): %.3f", alin);

    printf("\n\n---> Espessura cordal(X): %.3f", x);
    fprintf(pont_arq, "\n\n---> Espessura cordal(X): %.3f", x);

    printf("\n\n---> Número mínimo de dentes(K): %.0f", k);
    fprintf(pont_arq, "\n\n---> Número mínimo de dentes(K): %.0f", k);

    printf("\n\n---> Distância entre os dentes(Wk): %.3f", wk);
    fprintf(pont_arq, "\n\n---> Distância entre os dentes(Wk): %.3f", wk);

    printf("\n\n---> Diâmetro teórico do cilindro calibrado(DMR): %.3f", dmr);
    fprintf(pont_arq, "\n\n---> Diâmetro teórico do cilindro calibrado(DMR): %.3f", dmr);

    printf("\n\n---> Diâmetro da engrenagem com os cilindros(Y): %.3f", y);
    fprintf(pont_arq, "\n\n---> Diâmetro da engrenagem com os cilindros(Y): %.3f", y);

    printf("\n\n---> Diâmetro primitivo efetivo(MDR): %.3f\n\n", mdr);
    fprintf(pont_arq, "\n\n---> Diâmetro primitivo efetivo(MDR): %.3f\n\n", mdr);

    getch();
    return 0;
}

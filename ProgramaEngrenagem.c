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
        printf("N�o foi poss�vel criar um arquivos com os dados da engrenagem...");
        return 1;
    }


    int zint;
    float m, z, alin, ap, apdivang,  wk, k, x, dmr, mdr, y;

    printf("\n\n");
    printf("      ||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||");
    printf("\n      |||||||||||||                                                        |||||||||||||");
    printf("\n      |||||||||||||   Programa para calcular dimens�es de uma engrenagem   |||||||||||||");
    printf("\n      |||||||||||||                                                        |||||||||||||\n");
    printf("      ||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
    printf("\n\nQual o n�mero de dentes: ");
    scanf("%f", &z);

    zint = (int) z;

    printf("\n\nQual o m�dulo: ");
    scanf("%f", &m);
    printf("\n\nQual o �ngulo de press�o: ");
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

    printf("\n  ||||||||||||||||||||||||||   Dimens�es    ||||||||||||||||||||||||||||||");
    fprintf(pont_arq, "\n  ||||||||||||||||||||||||||   Dimens�es    ||||||||||||||||||||||||||||||");

    printf("\n  ||||||||||||||||||||||||||                ||||||||||||||||||||||||||||||\n");
    fprintf(pont_arq, "\n  ||||||||||||||||||||||||||                ||||||||||||||||||||||||||||||\n");

    printf("  ||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
    fprintf(pont_arq, "  ||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");

    printf("\n---> N�mero de dentres da engrenagem: %d", zint);
    fprintf(pont_arq, "\n---> N�mero de dentres da engrenagem: %d", zint);

    printf("\n\n---> M�dulo: %.0f", m);
    fprintf(pont_arq, "\n\n---> M�dulo: %.0f", m);

    printf("\n\n---> �ngulo de press�o: %.1f", ap);
    fprintf(pont_arq, "\n\n---> �ngulo de press�o: %.1f", ap);

    printf("\n\n---> Altura do dente corrigida(a'): %.3f", alin);
    fprintf(pont_arq, "\n\n---> Altura do dente corrigida(a'): %.3f", alin);

    printf("\n\n---> Espessura cordal(X): %.3f", x);
    fprintf(pont_arq, "\n\n---> Espessura cordal(X): %.3f", x);

    printf("\n\n---> N�mero m�nimo de dentes(K): %.0f", k);
    fprintf(pont_arq, "\n\n---> N�mero m�nimo de dentes(K): %.0f", k);

    printf("\n\n---> Dist�ncia entre os dentes(Wk): %.3f", wk);
    fprintf(pont_arq, "\n\n---> Dist�ncia entre os dentes(Wk): %.3f", wk);

    printf("\n\n---> Di�metro te�rico do cilindro calibrado(DMR): %.3f", dmr);
    fprintf(pont_arq, "\n\n---> Di�metro te�rico do cilindro calibrado(DMR): %.3f", dmr);

    printf("\n\n---> Di�metro da engrenagem com os cilindros(Y): %.3f", y);
    fprintf(pont_arq, "\n\n---> Di�metro da engrenagem com os cilindros(Y): %.3f", y);

    printf("\n\n---> Di�metro primitivo efetivo(MDR): %.3f\n\n", mdr);
    fprintf(pont_arq, "\n\n---> Di�metro primitivo efetivo(MDR): %.3f\n\n", mdr);

    getch();
    return 0;
}

#include <stdio.h>

int numDiscos=8,pinoA=0,pinoB=0,pinoC=0,pinoD=0,op=0;
void HanoiRecursivo(int nDiscos, char origem, char intermed1, char intermed2, char dest)
{
    // printf("ori:%c int1:%c int2:%c dest:%c\n", origem, intermed1, intermed2, dest);
   if ( nDiscos == 1 )
    {
        printf("\nOperacao:%d %c  --> %c\n",++op, origem, dest);
        atualizarValorPino(origem,dest);
    }
    else if ( nDiscos == 2 )
    {
        printf("\nOperacao:%d %c  --> %c\n",++op,origem,intermed1);
        atualizarValorPino(origem,intermed1);
        printf("\nOperacao:%d %c  --> %c\n",++op,origem,dest);
        atualizarValorPino(origem,dest);
        printf("\nOperacao:%d %c  --> %c\n",++op,intermed1,dest);
        atualizarValorPino(intermed1,dest);
    }
    else
    {
        //Movendo os dois discos de cima
        HanoiRecursivo(nDiscos - 2, origem, intermed2, dest, intermed1);
        printf("\nOperacao:%d %c  --> %c\n",++op,origem,intermed2);
        atualizarValorPino(origem,intermed2);
        printf("\nOperacao:%d %c  --> %c\n",++op,origem,dest);
        atualizarValorPino(origem,dest);
        printf("\nOperacao:%d %c  --> %c\n",++op,intermed2,dest);
        atualizarValorPino(intermed2,dest);
        HanoiRecursivo(nDiscos - 2, intermed1, origem, intermed2, dest);
     }
}

int main()
{
    pinoA=numDiscos;
    printf("Abaixo esta o passo a passo para a solucao da Torre de Hanoi com %d disco\n",numDiscos);
    printf("Estado da torre:\n");
    printf("\tA\tB\tC\tD\n");
    printf("\t%d\t%d\t%d\t%d\n",pinoA,pinoB,pinoC,pinoD);
    HanoiRecursivo(numDiscos, 'A', 'B', 'C', 'D');

    return 0;
}

atualizarValorPino(int pino1, int pino2)
{
    int i;
    //PINO QUE TEVE DISCO RETIRADO
    if(pino1=='A')
        pinoA--;
    else if(pino1=='B')
        pinoB--;
    else if(pino1=='C')
        pinoC--;
    else
        pinoD--;
    //PINO QUE TEVE DISCO INSERIDO
    if(pino2=='A')
        pinoA++;
    else if(pino2=='B')
        pinoB++;
    else if(pino2=='C')
        pinoC++;
    else
        pinoD++;

    printf("estado da torre:\n");
    printf("\tA\tB\tC\tD\n");
    printf("\t%d\t%d\t%d\t%d",pinoA,pinoB,pinoC,pinoD);
    printf("\n");

}

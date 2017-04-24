#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int linhaGlobal,colunaGlobal;

typedef struct nodo
{
    float dado;
    int lin, col;
    struct nodo *prox;
} Matriz_Esparsa;

void mostrarMatriz(Matriz_Esparsa *m, int linhas,int colunas)
{
    int l,c,i,j;
        for (i = 0; i < linhas; i++){
        for (j = 0; j < colunas; j++){
            if (m->lin == i && m->col == j){
                printf("  \t%0.2f   ", m->dado);
            }
            else{
                printf("  \t%0.2f   ", 0.0F);
            }
        }
        printf("\n");
    }
    printf("\nSua matriz ficou assim:\n");
    for(l=0; l<linhas; l++)
    {
        for(c=0; c<colunas; c++)
        {
        printf("[%.2f] ",m[l+c].dado);
        }
        printf("\n");
    }
}


void imprime_matriz(Matriz_Esparsa *N)
{
    Matriz_Esparsa *axs;

    if(N == NULL)
    {
        printf("\n Lista  vazia");
    }
    else
    {
        for(axs = N; axs != NULL; axs = axs->prox)
        printf("\n%.2f", axs->dado);
    }
}


///Aqui faz UM nodo
void inicializar_matriz(Matriz_Esparsa **N)
{
    *N = NULL;
}
Matriz_Esparsa* Cria_Nodo()
{
    ///Faz uma matriz com nome prox
    Matriz_Esparsa *prox;
    ///Se for [2x2]
    ///prox[4];
    prox = (Matriz_Esparsa*) malloc(sizeof(Matriz_Esparsa));
    if(!prox)
    {
        printf("\nErro de alocacao");
        exit(0);
    }
    return prox;
}

float busca_lista(Matriz_Esparsa **N, int li, int co)
{
    Matriz_Esparsa *axs;
    if(*N!=NULL)
    {
        while((axs->lin != li)&&(axs->col != co)||(axs->prox!=NULL))
        {
            axs=axs -> prox;
        }
        if((axs->lin != li)&&(axs->col !=co))
        {
            return axs->dado;
        }
        else
        {
            return 0;
        }
        {
            printf("\n Matriz vazia!!!");
        }
    }
}

void libera_memoria(Matriz_Esparsa **N)
{
    Matriz_Esparsa *p = *N, *axs;
    while(p != NULL)
    {
        axs = p->prox;
        free(axs);
    }
    inicializar_matriz(N);
}

void insere(Matriz_Esparsa **N, float dado, int li, int co)
{

    Matriz_Esparsa *nv, *axs;

    nv = Cria_Nodo();
    nv-> dado=dado;
    nv->lin = li;
    nv->col = co;
    nv->prox = NULL;
    if(*N == NULL)
    {
        *N = nv;
    }
    else
    {
        axs = *N;
        while(axs->prox !=NULL)
        {
            axs = axs -> prox;
        }
        axs->prox = nv;
    }
}

void le_dado(Matriz_Esparsa *m)
{
    ///É uma matriz auxiliar
    Matriz_Esparsa *Nodo;
    int li, co, g,h;
    float s;

    ///nv = é a matriz que recebe os dados do usuário
    Matriz_Esparsa *nv;
    ///m = Matriz que vem no parametro
    Nodo = m;

    printf("\nDigite quantidade de linha: ");
    scanf("%d", &li);
    printf("\nDigite quantidade de coluna: ");
    scanf("%d", &co);
    for(g=0; g<li; g++)
    {
        for(h=0; h<co; h++)
        {
            system("cls");
            printf("\nDigite o elemento [%d,%d] para insercao: ",g+1,h+1);
            scanf("%f",&s);
           //mostrarMatriz(m,li,co);
            if(s!=0)
            {
                ///Cria uma matriz do tamanho desejado com malloc
                nv = Cria_Nodo();
                ///Recebe o valor inserido pelo usuário
                nv-> dado=s;
                ///Recebe o valor da linha, começando de zero
                nv->lin = g;
                ///Recebe o valor da coluna, começando de zero
                nv->col = h;
                ///A matriz recebe NULO como o valor de prox
                nv->prox = NULL;
                ///Pasando os valores recebido para a matriz da main
                m=nv;
                //insere(&Nodo, s, li, co);
                //imprime_matriz(m);
                mostrarMatriz(m,li,co);
            }
        }
    }
}

int main()
{
    float d;
    int i,j;
    Matriz_Esparsa *m;
    inicializar_matriz(&m);
    int lin,col;
    int opc;
    printf("\n Escolha uma opcao:");
    printf("\n 1-Iniciar");
    printf("\n 2-Sair");
    printf("\nOpcao :");
    scanf("%d", &opc);

    switch(opc)
    {
    case 1:
        le_dado(m);
        //mostrarMatriz(m);
        break;

    case 2:
    default:
        printf("\nSaindo...\n\n");
        break;
    }

}

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct nodo
{
    float dado;
    int lin, col;
    struct nodo *prox;
} matriz_Esparsa;

///Busca o valor do elemento;
float busca_valor(matriz_Esparsa *matriz1, int lin, int col)
{
    matriz_Esparsa *aux;
    ///A partir da matriz matriz1, percorrendo cada nodo da lista,
	/// retorne o valor daquela linha e coluna específica
    for(aux = matriz1; aux != NULL; aux = aux->prox)
        if(aux->lin==lin&&aux->col==col)
            return aux->dado;
    return 0;
}

///Pega a matriz matriz1, que é global, e mostra ela.
void mostrarMatriz(matriz_Esparsa *matriz1, int linhas, int colunas)
{
    int l,c;
    float valor;
    if(matriz1 == NULL)
    printf("Erro, matriz vazia.\n");

    printf("\nSua matriz ficou assim:\n");
    for(l=0; l<linhas; l++)
    {
        for(c=0; c<colunas; c++)
        {
        	valor=busca_valor(matriz1,l,c);
        	printf("[%.2f] ",valor);
        }
        printf("\n");
    }
}


void imprime_matriz(matriz_Esparsa *N)
{
    matriz_Esparsa *axs;

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


///Aqui faz um nodo nulo
//**N é o endereço de memória do ponteiro da matriz
void inicializar_matriz(matriz_Esparsa **N)
{
    *N = NULL;
}

matriz_Esparsa* Aloca_Matriz()
{
    ///Faz uma matriz com nome prox
    matriz_Esparsa *prox;
    ///Se for [2x2]
    ///prox[4];
    prox = (matriz_Esparsa*) malloc(sizeof(matriz_Esparsa));
    if(!prox)
    {
        printf("\nErro de alocacao");
        exit(0);
    }
    return prox;
}

float busca_lista(matriz_Esparsa **N, int li, int co)
{
    matriz_Esparsa *axs;
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

void libera_memoria(matriz_Esparsa **N)
{
    matriz_Esparsa *p = *N, *axs;
    while(p != NULL)
    {
        axs = p->prox;
        free(axs);
    }
    inicializar_matriz(N);
}

void insere(matriz_Esparsa **N, float dado, int li, int co)
{
	///Matrizes auxiliares
    matriz_Esparsa *novo, *axs;

	//Retorna um vetor alocado dinamicamente do tipo 'matriz_Esparsa'
    novo = Aloca_Matriz();
    //Esse nodo recebe os valores dado pelos parametros desta função
    novo-> dado=dado;
    novo->lin = li;
    novo->col = co;
    novo->prox = NULL;
    
    //Até esse ponto novo está o valor de UM elemento da matriz
    
    //Se o nodo for nulo, ela é o primeiro elemento da matriz
    if(*N == NULL)
    {
        *N = novo;
    }
    //Caso contrário, enqnt o valor de prox não for NULL 
    else
    {
        axs = *N;
        while(axs->prox !=NULL)
        {
            axs = axs -> prox;
        }
        axs->prox = novo;
    }
}

void Le_dado(matriz_Esparsa **matriz1,  int *li, int *co)
{
	int numLinhas = *li;
	int numColunas = *co;
    ///É uma matriz auxiliar
    //matriz_Esparsa *matriz;
    int g,h;
    float valorInseridoPeloUsuario;

	//Quantidade de linhas e colunas que a matriz tem
    printf("\nDigite quantidade de linha: ");
    scanf("%d", &numLinhas);
    printf("\nDigite quantidade de coluna: ");
    scanf("%d", &numColunas);
    for(g=0; g<numLinhas; g++)
    {
        for(h=0; h<numColunas; h++)
        {
            system("cls");
            printf("\nDigite o elemento [%d,%d] para insercao: ",g+1,h+1);
            scanf("%f",&valorInseridoPeloUsuario);
            if(valorInseridoPeloUsuario!='\n')
            {
                insere(matriz1, valorInseridoPeloUsuario, g, h);
                //imprime_matriz(matriz1);
                
            }
        }
    }
    mostrarMatriz(*matriz1 ,numLinhas,numColunas);
}

int main()
{
    float d;
    int i,j;
    matriz_Esparsa *matriz1,*matriz2;
    //matriz1=NULL
    inicializar_matriz(&matriz1);
    int lin,col;
    int opc;
    printf("\n");
    printf("Software de manipulacao de matrizes esparsas\n");
    printf("\n Escolha uma opcao:");
    printf("\n 1-Iniciar");
    printf("\n 2-Encerrar");
    printf("\nOpcao :");
    scanf("%d", &opc);

    switch(opc)
    {
    case 1:
        Le_dado(&matriz1, &lin, &col);
        break;

    case 2:
    default:
        printf("\nAte a proxima.\n\n");
        break;
    }

}

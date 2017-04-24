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
float Busca_valor(matriz_Esparsa *matriz, int lin, int col)
{
    matriz_Esparsa *aux;
    ///A partir da matriz matriz, percorrendo cada nodo da lista,
    /// retorne o valor daquela linha e coluna específica
    for(aux = matriz; aux != NULL; aux = aux->prox)
        if(aux->lin==lin&&aux->col==col)
            return aux->dado;
    return 0;
}

///Pega a matriz matriz1 ou 2, que é global, e mostra ela.
void MostrarMatriz(matriz_Esparsa *matriz, int linhas, int colunas, int qualMatriz)
{
    int l,c;
    float valor;
    if(matriz == NULL)
        printf("Erro, matriz vazia.\n");

    printf("\nA matriz %d ficou assim:\n",qualMatriz);
    for(l=0; l<linhas; l++)
    {
        for(c=0; c<colunas; c++)
        {
            valor=Busca_valor(matriz,l,c);
            printf("[%4.1f] ",valor);
        }
        printf("\n");
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

void Le_dado(matriz_Esparsa **matriz,  int *li, int *co)
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
    //O conteúdo de li,co(variaveis globais de linha e coluna) é atualizado aqui
    *li=numLinhas;
    *co=numColunas;
    for(g=0; g<numLinhas; g++)
    {
        for(h=0; h<numColunas; h++)
        {
            system("cls");
            printf("\nDigite o elemento [%d,%d] para insercao: ",g+1,h+1);
            scanf("%f",&valorInseridoPeloUsuario);
            if(valorInseridoPeloUsuario!='\n')
            {
                insere(matriz, valorInseridoPeloUsuario, g, h);
            }
        }
    }
}

void Soma_subitracaoMatriz(matriz_Esparsa *m1, matriz_Esparsa *m2, int lin, int col, int operacao)
{
    int i,j;
    float valor1,valor2,valorResultado;
    for(i=0; i<=lin-1; i++)
    {
        for(j=0; j<=col-1; j++)
        {
            valor1 = Busca_valor(m1, i, j);
            valor2 = Busca_valor(m2, i, j);
            if(operacao ==1)
            valorResultado = valor1 + valor2;
            else
            valorResultado = valor1 - valor2;
            printf("[%4.1f] ", valorResultado);

        }
        printf("\n");
    }
}

int main()
{
    int i,j;
    matriz_Esparsa *matriz1,*matriz2;
    //matriz1=NULL
    inicializar_matriz(&matriz1);
    inicializar_matriz(&matriz2);
    int lin,col,lin2,col2;
    int opc,opc2;
    printf("\n");
    printf("Software de manipulacao de matrizes esparsas\n");
    printf("\n Escolha uma opcao:");
    printf("\n 1-Iniciar");
    printf("\n 2-Encerrar");
    printf("\n\nOpcao :");
    scanf("%d", &opc);

    switch(opc)
    {
    case 1:
        system("cls");
        printf("\nInsira os valores da primeira matriz\n");
        Le_dado(&matriz1, &lin, &col);
        system("cls");
        printf("\nInsira os valores da segunda matriz\n");
        Le_dado(&matriz2, &lin2, &col2);
		system("cls");
        MostrarMatriz(matriz1,lin,col,1);
        MostrarMatriz(matriz2,lin2,col2,2);

        printf("\nVoce deseja:\n");
        printf("\n1- Somar as matrizes");
        printf("\n2- Subtrair as matrizes");
        printf("\n3- Multiplicar as matrizes");
        printf("\n4- Gerar matriz transposta");
        printf("\n5- Imprimir diagonal principal");
        printf("\n6- Sair\n");
        scanf("%d", &opc2);
        switch(opc2)
        {

        case 1:
            if(lin==lin2&&col==col2)
            {
                printf("A soma das matrizes e:\n");
                Soma_subitracaoMatriz(matriz1,matriz2,lin,col,1);
                break;
            }
            else
                printf("Nao e possivel somar matrizes com linhas e/ou colunas diferentes.");
            break;
        
        case 2: 
        	if(lin==lin2&&col==col2)
        	{
        		Soma_subitracaoMatriz(matriz1,matriz2,lin,col,2);
			}
			else
                printf("Nao e possivel somar matrizes com linhas e/ou colunas diferentes.");
            break;
        default:
        	printf("\nOpcao invalida\n");
        	break;
		}
        scanf("%d");
        break;

    case 2:
    default:
        printf("\nAte a proxima.\n\n");
        break;
    }
}

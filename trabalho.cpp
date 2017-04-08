#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct nodo
{
 float dado;
 int lin, col;
 struct nodo *prox;
}Matriz_Esparsa;


void inicializar_matriz(Matriz_Esparsa **N)
{
 	*N = NULL;
}
Matriz_Esparsa* Cria_Nodo()
{
	Matriz_Esparsa *prox;
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
	
void insere(Matriz_Esparsa **N, float dado , int li, int co)
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
	
Matriz_Esparsa le_dado()
{
	Matriz_Esparsa *Nodo;
	int li , co , g ,h;
		float s;
		
		inicializar_matriz(&Nodo);
		printf("\nDigite quantidade de linha");
		scanf("%d", &li);
		printf("\nDigite quantidade de coluna");
		scanf("%d" , &co);
			for(g=0;g<li-1;g++)
			{
			for(h=0;h<co-1;h++)
			{
			system("cls");
				printf("\nDigite elementos para inserção");
					scanf("%f", &s);
					if(s !=0)
					{
						insere(&Nodo, s, li, co);
					}
				}
			}
		return *Nodo;
}

int main()
{
	int lin,col;
	int opc;
	printf("\n Escolha uma opcao:");
		printf("\n 1-Iniciar");
		printf("\n 2-Sair");
		printf("Opcao :");scanf("%d", &opc);
			
			switch(opc)
	{
	case 1:
		printf("\nDigite numero de linha :");
		scanf("%d", &lin);
		printf("\nDigite numero de coluna :");
		scanf("%d", &col);
	break;
	
	case 2:
		default:
		printf("\nSaindo...\n\n");
	break;
	}

}
	

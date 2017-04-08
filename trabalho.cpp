#include <stdio.h>
#include <stdlib.h>

typedef struct nodo
{
	
 float dado;
 int lin, col;
 struct nodo *prox;
}Matriz_Esparsa;


Matriz_Esparsa* Criar_Nodo() //1 alocaçao de memoria
{
  Matriz_Esparsa *v;
   v = (Matriz_Esparsa*) malloc(sizeof(Matriz_Esparsa));

   	if(!v){
		prinf("\nErro na alocacao");
			exit(0);
  }
  return v;
}

void nodo_col_lin (Matriz_Esparsa *p)
{
	
}

void insere(Matriz_Esparsa) // 2
{

}
void busca(Matriz_Esparsa *v , int *prox) //3busca
{
		Matriz_Esparsa *p;
		for(p=v; p!=NULL; p=p->prox){
			if(p->infor ==v)
			 return p;
	}
	return NULL;
}
void libera_memoria(nodo* v) //4liberar memoria
{
	nodo *p = v;
		while(p != NULL){
		nodo *x = p->prox;
		free(p);
		p = x;
		}
}
void inseri_lista(Matriz_Esparsa *v)
{
	printf("\nInseri numero de linhas e colunas");
	  //while(<lin) ou um for{
	printf("\nInseri numero de linhas : \n");
	scanf("%d", lin[]);
 }
	

void soma() //arruma
{
    int i;
      /* pra cada elemento da matriz */
    for (i = 0; i < lin[] * col[] ; i++) {
          /* soma valor se elemento Ã© nao-nulo */
       // if (* (s.sp + i) != 0)  * (s.sp + i) = (* (s.sp + i)+ constante);///
}
}

void subtrai()
{
}

void multiplica()
{
}
void matriz_tranposta()
{
}
void imprime_matriz()
{
}
void imprime_diagonais()
{
}

}

main()//
{
	int lin,col;
	int opc;
	printf("\n Escolha uma opcao:");
		printf("\n 1-Iniciar");
		printf("\n 2-Sair");
		printf("\n 3-Opcao : ");	
		printf("Opcao :");scanf("%d", &opc);
			return opc;
			
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
	
		printf("\nComando invalido\n\n");
	}
	return lin;
	return col;
}

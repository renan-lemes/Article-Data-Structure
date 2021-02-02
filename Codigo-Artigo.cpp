/*
Codigo sobre: Artigo PDF-Artigo(Estrutura de Dados)  
Desenvolvido: Renan Lemes Leepkaln
2019,Guarapuava-PR.
Diciplina: Estrutura de Dados;
*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <conio.h>
#include <malloc.h>
#include <windows.h>

	#define true 1;
	#define false 0;


typedef int TipoChave;
typedef char TipoChar;

typedef struct aux{
	TipoChave chave;
	TipoChar letra;
	TipoChar bin[10]; //binario//
	struct aux *esq, *dir;
}NO;
typedef NO* PONT;

PONT Inicializa(){
	return(NULL);
};

PONT criar_Novo_No(TipoChave ch, TipoChar l , TipoChar *bin){
	PONT novoNo = (PONT)malloc(sizeof(NO));
	novoNo->esq = NULL;
	novoNo->dir= NULL;
	novoNo->chave = ch;
	novoNo->letra = l;
	strcpy((novoNo)->bin,bin);
	return(novoNo);
};

PONT adicionar(PONT raiz,PONT no){
	/*ignoro chaves iguais*/
	if(raiz == NULL)
		return (no);
	if(no->chave<=raiz->chave)
		raiz->esq = adicionar(raiz->esq,no);
	else
		raiz->dir=adicionar(raiz->dir,no);
	return(raiz);
};
	//busca pelo numero //
PONT Busca(TipoChave ch, PONT raiz){
	if(raiz==NULL)			//ve se a raiz for vazia retorna
		return(NULL);
	if(raiz->chave==ch)	  //ve se a chave do elemento posto ao elemento inserido//
		return(raiz);
	if(raiz->chave>ch)	//se for menor ela vai e faz a busca denovo por recursividade//
		return(Busca(ch,raiz->esq));
	return(Busca(ch,raiz->dir)); //caso os elementos que eu procurava esta a direita//
};

PONT Busca_Letra(TipoChar l,PONT raiz){
	if(raiz==NULL)			
		return(NULL);
	if(raiz->letra==l)	  
		return(raiz);
	if(raiz->letra>=l)	
		return(Busca(l,raiz->esq));
	return(Busca(l,raiz->dir)); 
}


int n_Nos(PONT raiz){
	if(!raiz)
		return 0;
	return(n_Nos(raiz->esq)+1+ n_Nos(raiz->dir));
};

void Pre_Ordem(PONT raiz){
	if(raiz!=NULL){
		printf("  |%i %c %s|\n",raiz->chave,raiz->letra ,raiz->bin);
		printf("<-");
		Pre_Ordem(raiz->esq);
		Pre_Ordem(raiz->dir);
		printf("->");
	}
};

 void So_Direita(PONT raiz){
	 if(raiz!=NULL){
		 printf("  |%i %c %s|\n",raiz->chave,raiz->letra ,raiz->bin);
		 printf("<->");
		 So_Direita(raiz->dir);
		 printf("->");
	 }
 };

 void So_Esquerda(PONT raiz){
	 if(raiz!=NULL){
		 printf("  |%i %c %s|\n",raiz->chave,raiz->letra ,raiz->bin);
		 printf("<->");
		 So_Direita(raiz->esq);
		 printf("->");
	 }
 };

 void So_SubArv_Direita(PONT raiz){
	if(raiz!=NULL){
		So_SubArv_Direita(raiz->dir);
		So_SubArv_Direita(raiz->esq);
			if(raiz->dir||raiz->dir==NULL){
				if(raiz=raiz->dir)
					printf("%i",raiz->chave);
					printf("->");
			}else{
			}

	}
}

 void Estetica(){
	printf("\n   ___________________________________\n");
	printf("  |                                   |\n");
	printf("  |   Arvore De Pesquisa Codificada   |\n");
	printf("  |___________________________________|\n");
	printf("  1 - Insirir Senha  :\n");
	printf("  2 - Imprimir Arvore :\n");
	printf("  3 - Buscar Pela Letra :\n");
	printf("  4 - Numero de Nos:\n");
	printf("  5 - Imprimir So Nos A Direita:\n");
	printf("  6 - Imprimir So Nos A Esquerda:\n");
	printf("  7 - Sair\n");
	printf("\n  -------------------------------------\n");
	fflush(stdin);
}

 //que vai criar a arvore com a palavra//
PONT Transforma_palavra(char palavra[],int n,PONT r){
	PONT no ;
	int bin1,i;
	char b0[10];
	
	for(i=0;i<=10;i++){
		bin1 = palavra[i];
		itoa(bin1,b0,2);
		no = criar_Novo_No(bin1,palavra[i],b0);
		r = adicionar(r,no); 
    }
    return (r);
};


int main(int argc, char** argv){
	int opcao;
	int n=2,num_no;
	char palavra[10];
	char l;
	PONT testar;
	PONT r = Inicializa();

	while(1)
	{
		memset(palavra,NULL,sizeof(palavra));
		Estetica();
		scanf("%d",&opcao);
		switch(opcao)
		{
		case 1:
			printf("\nDigite Senha Pra ser Codificada:\n");
			scanf("%s",&palavra);
			fflush(stdin);
			r = Transforma_palavra(palavra,n,r);
			break;
		case 2:
			Pre_Ordem(r);
			break;
		case 3:
			printf("\nDigite a Letra:\n");
			scanf("%s",&l);
			testar = Busca_Letra(l,r);
			printf("\nA letra ta alocada |%c| esta alocada na memoria:|%i|\n",*testar,testar);
			break;
		case 4: 	//numero de nos vai ser conforme o tamanho da palavra//
			num_no = n_Nos(r);
			printf("\nNumeros de Nos:%d\n",num_no);
			break;
		case 5:
			So_Direita(r);
			break;
		case 6:
			So_Esquerda(r);
			break;
		case 7:
			return 0;
			break;
		}
	}
return 0;
}

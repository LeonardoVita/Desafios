#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
typedef struct noArv{
	int num;
	struct noArv *sae; //sub arvore esquerda
	struct noArv *sad; //sub arvore direita
}noArv;

typedef struct lista{
	struct noArv *no; //aponta para um no da arvore
	struct lista *proximo;
}lista;

noArv *raiz = (noArv *) NULL,*atual,*novo;
lista *list = (lista *) NULL,*atualList;

/*FUNÇÃO PARA INSERIR O VALOR DESEJADO NA ARVORE*/
void inserirNaArv(int num);
/*FUNÇÃO PARA ENCONTRAR O NÓ EXATO DO VALOR A SER INSERIDO*/
void novoNo(int num,noArv *no);
/*IMPRIME A ARVORE COM AJUDA DE UMA FILA DINAMICA*/
void imprimirArv();			//imprime o primeiro da fila e insere seus filhos ao final da fila
/*FUNÇÃO PARA INSERIR NA FILA*/
void adcionaALista(noArv *no);


int main(int argc, char *argv[]) {
	
	imprimirArv();
	inserirNaArv(50);
	inserirNaArv(55);
	inserirNaArv(40);
	inserirNaArv(120);
	inserirNaArv(6);
	inserirNaArv(10);
	inserirNaArv(12);
	inserirNaArv(30);
	inserirNaArv(150);
	inserirNaArv(41);
	inserirNaArv(42);	
	inserirNaArv(100);
	inserirNaArv(43);
	inserirNaArv(101);
	
	printf("\n\n\tIMPRIMINDO A ARVORE\n");
	
	imprimirArv();
	
	return 0;
}

void inserirNaArv(int num){
	
	novo = (noArv *) malloc(sizeof(noArv));
	
	/*INSERINDO O PRIMEIRO VALOR NA ARVORE (RAIZ)*/
	if(raiz == (noArv *) NULL){	
		raiz=atual=novo;
		atual->sad = (noArv *) NULL;
		atual->sae = (noArv *) NULL;
		atual->num=num;		
	}else{
	/*FAZ A INSERÇÃO DE UM NOVO NO NA ARVORE*/				
		novoNo(num,raiz);  
		atual=novo;
		atual->sad = (noArv *) NULL;
		atual->sae = (noArv *) NULL;
		atual->num=num;		
	}
}

void novoNo(int num,noArv *no){
	
	/*NUMERO MAIOR CAI PARA A SUBARVORE DIREITA*/
	if(num > no->num){
		if(no->sad == (noArv *)NULL)
		no->sad=novo;			//novo e global		              	
		else
		novoNo(num,no->sad);		
	}
	else 
	/*NUMERO MENOR CAI PARA A SUBARVORE ESQUERDA*/	
	if(num < no->num){
		if(no->sae == (noArv *)NULL)
		no->sae=novo;			//novo e global		             	
		else
		novoNo(num,no->sae);            //chama novamente o metodo (recursividade)	
	}
	else
	printf("O valor \"%i\" ja existe na arvore\n",num);  
}

void alocaLista(noArv *no){	
	/*CRIA PRIMEIRO NODO DA LISTA*/
	if(list == (lista *) NULL){
		
		list = (lista *) malloc(sizeof(lista));
		list->no=raiz;				//aponta para raiz da arvore
		list->proximo=(lista*) NULL;
		atualList=list;
		
	}else{
		
		atualList=list;          				//vai pro inicio da lista
		
		while(atualList->proximo!=(lista*)NULL)  //vai pro final da lista
			atualList=atualList->proximo;
		
		/*CRIA UM NOVO NODO DA LISTA COM UM PONTEIRO PARA O NO PASSADO NA CHAMADA DA FUNÇÃO*/	
		atualList->proximo = (lista *) malloc(sizeof(lista));	
		atualList=atualList->proximo;		
		atualList->no = no;				//aponta para o no passado na função		
		atualList->proximo = (lista*)NULL;			
	}
}


void imprimirArv(){
	
	if(raiz == (noArv *) NULL){
	puts("Arvore Vazia!\n");
	return;
	}
	
	/*CRIA UMA FILA DE PONTEIROS QUE APONTAM PARA UM NO DA ARVORE*/
	
	alocaLista(raiz); //primeiro da fila e a raiz da arvore
	
	lista *listArv; //um ponteiro para percorrer a lista e imprimir
	listArv = list; //ponteiro para o inicio da lista
	
	while(listArv != (lista*)NULL){		
			
		printf("%i ",listArv->no->num);		//imprimindo o proximo da fila da esquerda para direita	
		
		if(listArv->no->sae != (noArv *)NULL)			
		alocaLista(listArv->no->sae);		//adcionando os filhos ao final da  fila
				
		if(listArv->no->sad != (noArv *)NULL)			
		alocaLista(listArv->no->sad);		
	
		listArv=listArv->proximo;				//ponteiro para o proximo da fila
	}
	
}


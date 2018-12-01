#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>

/*
ARVORE HUFFMAN : METODO DE COMPRESSÃO DE DADOS

OBEJTIVO: Criar uma lista dinamica de arvores binarias,inicialmente em cada nodo da lista um 
ponteiro para uma raiz ainda sem filhos,que armazena(letra e precedencia)
ordenar a lista de acordo com aprecedencia e logo apos criar a arvore HUFFMAN,
juntando as raizes pouco a pouco em uma unica arvore binaria.
*/

typedef struct noArv{
	char letra;                 //estrutura para os nós das arvores
	int  qtd;
	noArv *esq;
	noArv *dir;	
}noArv;

typedef struct lista{           //estrutura para a lista de arvores
	noArv *raiz;				//cada nodo da lista contém um ponteiro para uma arvore (struct noArv)
	lista *proximo;				//aponta para o proximo nodo da lista
}lista;

lista *inicio,*atual;          // ponteiros globais para manipulação das listas

 
int calculPrecedencia(char [39],char c);      //calcula quantas vezes a letra se repete pelos nomes e retorna um valor inteiro
int existeNaLista(char c);					 //verifica se a letra ja foi calculada e salva na raiz de uma arvore de um nó da lista
void imprimirLista();						//imprime as raizes das arvores dos nós da lista (letras e suas precedencias)
void ordenarLista();						//ordena a lista crecentemente 
void criaArv();								//Gera a Arvore de Huffman
void ordenarArv();							//ordena a arvore criada para o lugar certo na lista
void imprimirEmOrdem(noArv* a);				// imprime a arvore em-ordem (esquerda->raiz->direita)
void decifraCod(char a[48]);				//decifra o codigo passado


main(){
	
	
	char nomes[39]= "leonardo vita solange vita renato vita",codigo[48]="01101110001111110100010111000110011001101010101";  //nomes para codificação e codigo para decifrar
	int i;
	int existe,listaTam=0;
	lista *listagem = NULL;                                   //inicia um ponteira de tipo lista apontando para NULL
	
	
	for(i=0;i<38;i++){	
	
	if(listagem == NULL){
		listagem = (lista*) malloc(sizeof(lista));                   //se a lista esta vazia,aloca o primeiro nodo na memoria e set os ponteiros globais (inicio e atual)
		inicio=atual=listagem;
		listagem->raiz = (noArv*) malloc(sizeof(noArv));			//cria o nó raiz da arvore dentro do nó da lista (aloca memoria)
		listagem->raiz->letra=nomes[i];
		listagem->raiz->dir=listagem->raiz->esq=NULL;				//arvore ainda sem filhos,direita e esquerda apontam para NULL
		listagem->proximo=NULL;										//proxima posição da lista aponta para NULL				
		listagem->raiz->qtd=calculPrecedencia(nomes,nomes[i]);		//salva a precedencia d aletra	
		listaTam++;
	}else{
		
		existe = existeNaLista(nomes[i]);                           // com a lista nao vazia,o sistema verifica se o caracter ja foi calculado 
		
		//if(existe == 0)                       
		//printf("\nexiste:%i\n",existe);         // imprimi 1 se a letra ja foi calculada
		
		if(existe == 0){											//caracter nao calculado
			
			atual=inicio;											//ponteiro golbal para o inicio da lista
			listagem = (lista*) malloc(sizeof(lista));				//aloca memoria para o ponteiro
			
			while(atual->proximo != NULL)							//percorre a lista até achar o ultimo nodo
				atual=atual->proximo;		
		
			listagem->raiz = (noArv*) malloc(sizeof(noArv));		//cria o nó raiz da arvore dentro do nó da lista (aloca memoria)
			listagem->raiz->letra=nomes[i];							//adciona os dados
			listagem->raiz->dir=listagem->raiz->esq=NULL;
			listagem->proximo=NULL;
			listagem->raiz->qtd=calculPrecedencia(nomes,nomes[i]);
			atual->proximo=listagem;
			listaTam++;								//o ultimo nodo da lista que antes apontava para NULL agora aponta para o novo nodo criado
		};	
	};	
};

	
								
ordenarLista();								//Ordenando a Lista de acordo com a precedencia

printf("   Nomes Utilizados: leonardo vita Solange vita renato vita\n\n");
printf("\t========IMPRIMINDO TABELA DE PRECEDENCIA(ordenada)========\n\n");

imprimirLista();	   						//imprime as raizes das arvores dos nós da lista (letras e suas precedencias) 
criaArv();                                  //Gera a Arvore de Huffman

printf("\n\n\tImprimindo Arvore HUFFMAN  (em-ordem)\n\n");
imprimirEmOrdem(inicio->raiz);

printf("\n\n   Inserindo Dados criptografado\n   01101110001111110100010111000110011001101010101\n\n");
printf("\tDecodificando....\n\n Responta:");


decifraCod(codigo);

}

int calculPrecedencia(char nomes[39],char c){
	
	int x;
	int qtd=0;
	
	for(x=0;x<38;x++){       //percorre a string e salva quantas vezes o caracter se repetiu
	 
	 if(c == nomes[x])
	  qtd++;
	  	
	 };
		
	return qtd;	
};

int existeNaLista(char c){
	
	atual=inicio;        		    //ponteiro golbal para o inicio da lista		
	
	do{
		
		if(atual->raiz->letra == c)   //percorre a lista e verifica a raiz da arvore de cada nodo da lista se o caracter salvo e igual ao caracter passado no parâmetro
		return 1;				      //retorna 1 caso o caracter ja tenha sido calculado anteriormente
		
		atual=atual->proximo;		  //aponta para o proximo nodo da lista
		
		
	}while(atual != NULL);	         //se o nodo e NULL,sai da repetição
	
	return 0;
	
};

void imprimirLista(){
	
	atual=inicio;				//ponteiro golbal para o inicio da lista
	while(atual != NULL){		//enquanto o atual nao for nulo
		
		printf("\t\tletra:%c  precedencia:%i\n",atual->raiz->letra,atual->raiz->qtd);   //imprime a letra e sua precedencia
		atual=atual->proximo;														//aponta para o proximo nodo da lista

	};
	return;	
};

void ordenarLista(){

	atual=inicio;											//ponteiro golbal para o inicio da lista
	lista *aux=inicio,*menor;								//Ponteiro Aux para percorrer a lista,ponteiro menor para apontar para o menor da lista
	lista *troca = (lista*) malloc(sizeof(lista));			//alloca um espaço de memoria para realizar a troca de ponteiros

	
	

	while(atual->proximo != NULL){          //realiza o while enquanto houver mais de um nodo da lista
		
		menor=atual;                                       	//menor e sempre o primeiro do restante da lista a ser verificado 
		aux=atual;											//aux aponta para o primeiro do restante da lista a ser verificado 
		
		while (aux->proximo != NULL){                      //realiza o while enquanto houver um proximo nodo a verificar
		    
		    
			if(menor->raiz->qtd > aux->proximo->raiz->qtd){				//realiza o IF caso a precedencia do menor seja MAIOR que a precedencia do proximo nodo do ponteiro aux
				troca->raiz=aux->proximo->raiz;							
				aux->proximo->raiz = menor->raiz;
				menor->raiz=troca->raiz;								//IF realiza a troca dos ponteiros dentro lista que apontam para uma raiz (utiliza o espaço para troca alocado anteriormente),um nodo aponta para a raiz do outro.
			};	
			aux=aux->proximo;                                          
		};
		
		atual=atual->proximo;                             //atual aponta para o proximo nodo,assim nao e preciso verificar os anteriores novamente	
	};
};

void criaArv(){
	
	
	lista *aux=inicio,*aux2;                  //ponrteiro aux para percorrer a lista,axu2 para liberar o espaço de memoria nao utilizado
		
	while(aux->proximo != NULL){	          //enquanto o ponteiro PROXIMO nao apontar para NULO	
	
		lista *novoNo = (lista*) malloc(sizeof(lista));								//cria um ponteira para um estruct lista,aloca em espaço de memoria para um nodo da lista(desconexo)
		novoNo->raiz = (noArv*) malloc(sizeof(noArv));								//nodo da lista recebe um ponteira par auma raiz
		
		novoNo->proximo = aux->proximo->proximo;									//o novo no da lista passa a apontar para o terceiro nó da lista
		novoNo->raiz->letra = '*';													//arvore do novo nó rece a letra padrão (*) para quando e NULL
		novoNo->raiz->qtd = aux->raiz->qtd+aux->proximo->raiz->qtd;					//e recebe a soma da precedencia das letras do primeiro e segundo nó da lista
			
		novoNo->raiz->esq = aux->raiz;
		novoNo->raiz->dir = aux->proximo->raiz;										//recebe como filhos esq e dir as raizes do primeiro e segundo nó
		
		inicio=novoNo;                                                        //o inicio da lista agora e o o novo nó criado
		aux2=aux;		
		free(aux2);                                                              //libera o nodo da lista nao utilizado
		aux=novoNo;														//aux aponta para o proximo nodo da lista
		
		ordenarArv();																//ordena a arvore criada para o lugar certo na lista			
		aux=inicio;																	//aux para o inicio da lista de arvores
		
		//printf("\nAux Letra:%c Aux qtd%i   ",aux->raiz->letra, aux->raiz->qtd);	//imprime os dados da raiz do primeiro nodo da lista a cada etapa	
		
	  //printf("\t ==================\n");
	  //imprimirLista();															//imprime os dados de todas as raizes da lista a cada etapa
						
	};	
};

void ordenarArv(){

	atual=inicio;										  // atual para o inicio da lista						
	lista *aux=atual->proximo,*aux2;					  //salva a proxima posicao do atual			
	lista *x = (lista *) malloc(sizeof(lista));	          //aloca espaço de memoria para organizar a lista
	

	
	if(aux != NULL){           //se a proxima posicao do atual nao for nula
		
		
		while(inicio->raiz->qtd >= aux->raiz->qtd){   //enquanto a precedencia da arvore a ser ordenada for mair que o proximo nodo do atual
			
			aux=aux->proximo;						//incrementa aux e atual
			atual=atual->proximo;
			if(aux == NULL){
				
				break;   					//se aux atingir nulo,para WHILE
				};
			};
	};
	
	
	x->raiz=inicio->raiz;         //ponteiro raiz do espaço alocado anteriormente aponta para a raiz da arvore a ser ordenada	
	x->proximo=aux;				  //espaço alocado x aponta para o proximo nodo da lista (logo apos onde ele deve ser alocado)
	atual->proximo=x;			  //espaço anterior (logo antes onde ele deve ser alocado) aponta para o espaço alocado x
	
	aux2=inicio;	
	inicio=inicio->proximo;		  //inicio da lista apontar para o segundo nodo da lista			
	free(aux2);					 //libera nodo nao utilizado
	
	
	
};

void imprimirEmOrdem(noArv* a){
	
	if(a!=NULL){
	imprimirEmOrdem(a->esq);
	printf("\tLetra:%c		Precedencia:%i \n",a->letra,a->qtd);
	imprimirEmOrdem(a->dir);
    };

};

void decifraCod(char a[48]){
	
	int i=0;                       //contador
	noArv *atualRaiz=inicio->raiz;		// ponteiro para percorrer arvore
	
	for(i;i<48;i++){  //percorre a string ate o fim
		
	if(a[i] == '1'){		   			//caso a instrução seja 1 (DIREITA) 
		if(atualRaiz->dir != NULL)			//verifica se Dir é nulo
		atualRaiz=atualRaiz->dir;			//ponteiro para raiz da direita
		else{								//direita nulo
		printf("%c",atualRaiz->letra);		//imprime letra
		atualRaiz=inicio->raiz;				//volta ponteira para inicio da raiz
		i--;								//verifica novamente a instrução passada
		}
	}else if (a[i] == '0'){					//caso a instrução seja 0 (ESQUERDA) 
		if(atualRaiz->esq != NULL)			//verifica se esq é nulo	
		atualRaiz=atualRaiz->esq;			//ponteir apara raiz da esquerda
		else{								//esquerda nulo
		printf("%c",atualRaiz->letra);		//imprime letra
		atualRaiz=inicio->raiz;				//volta ponteira para inicio da raiz
		i--;								//verifica novamente a instrução passada
		}
	}	
	
		
	};	
	printf("%c",atualRaiz->letra);		//imprime a ultima letra que falta
};

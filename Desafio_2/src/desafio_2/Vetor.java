package desafio_2;

/**
 *
 * @author Leo
 */
public class Vetor {
    
    /*VARIAVEIS DA CLASSE*/
    private final char[] vetor;
    private char[] palindromo;     
    
    /*CONSTRUTOR DA CLASSE*/
    Vetor(char[] vet){
      this.vetor = vet;                         //salva o vetor digitado pelo usuario
      this.palindromo = new char[vet.length];   //inicializa o vetor palidromo com o mesmo tamanho do vetor do usuario   
    } 
    
    /*ENCONTRANDO O PALINDROMO DENTRO DA FRASE*/
    public void calculaPalindromo(){  
        
        int i,j;                //iteradores para percorrer o vetor em 2 direções                 
        int tamanhoMaior = 0;   //maior palíndromo encontrado       
        
        for (i=0;i<this.vetor.length-1;i++){        //percorre o vetor do inicio para o penultimo indice
           for(j=this.vetor.length-1;j>i;j--){      //percorre o vetor do ultimo indice para o inicio até o proximo do indice i
                     
                if(tamanhoMaior < ePalindromo(i,j)){ //o metodo retorna 0 caso nao seja palindromo,ou retorna o tamanho do palindromo
                    tamanhoMaior=ePalindromo(i,j);   //salva o maior palindromo
                    montaPalindromo(i,j);            //cria o vetor do palindromo encontrado    
                }                                
           }               
        }       
    }       
    
    /*VERIFICANDO SE O VETOR E UM PALINDROMO*/
    public int ePalindromo(int x,int y){ //recebe os indices para testar
        
        int tamanhoAtual=0; //tamanho do palindromo atual
        
        while(y>=x){  //executa um looping para comparar se o vetor e um palíndromo, 
                      //comparando caracteres das extremidades para o centro
 
            while(this.vetor[x] == ' ')  //ignora espaços em branco
                x++;                    
            while(this.vetor[y] == ' ')  
                y--;  
            
            //transforma caracteres adjacentes em maiusculos e compara
            if(Character.toUpperCase(this.vetor[y])!= 
                    Character.toUpperCase(this.vetor[x])) 
                return 0;           //nao é palindromo
            
            tamanhoAtual++; //incrementa o tamanho do palíndromo atual               
            x++;            //torna caracteres extremos mais interno ao vetor verificado
            y--;               
        }
        return tamanhoAtual;
    }
    
    /*INSERINDO PALINDROMO AO VETOR*/
    public void montaPalindromo(int x,int y){       
        
        for(int j=0;x<=y;x++,j++)
            this.palindromo[j]=this.vetor[x];                  
    } 
    
    /*IMPRIMINDO OS RESULTADOS*/
    public void imprimirPalindromo() { 
        if(this.palindromo[0]==0)
           System.out.println("não é palindromo"); 
        else
           System.out.println(this.palindromo); 
    }
}

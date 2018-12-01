/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Desafio1;

import java.util.Scanner;

/**
 *
 * @author Leo
 */
public class Desafio1 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        
        int a[] = new int[10]; //declarando um vetor e alocando espaço de memoria para 10 integers 
        int i=0;  
        int j=0;  
        int s; // declarando a variavel SOMA
        boolean bol=false;
        
        /*RECEBENDO DADOS DO USUARIO*/
        Scanner scan = new Scanner(System.in);        
        
        for(i=0;i<10;i++){  
            System.out.println("Digite um valor:");
            a[i]= scan.nextInt();  
        }
        
        /*IMPRIMINDO OS DADOS EM FILEIRA */
        for(i=0;i<10;i++){
          System.out.print(a[i]+ " "); 
        }
        
        /*RECEBENDO O VALOR SOMA*/
        System.out.println();
        System.out.println("Digite o valor SOMA");
        s = scan.nextInt();  
        
        /*VERIFICANDO AS POSSIVEIS COMBINAÇÕES*/
        
        for(i=0;i<10;i++){  //percorre o vetor
            for(j=9;j>i;j--){                                       //o iterador j começa na ultima posição e percorre ate a proxima posição depois do iterador i
                                                                    //dessa forma nao e feito somas desnecessarias como 2+1,3+2 pois ja foi feito 1+2,2+3  
                bol = (a[i]+a[j]== s)?true:false;                   //operador ternario, bol recebe de acordo com o resultado da expressão
                                                                    //expressão calcula o a soma dos valores na posições i e j e verifica se e igual a s
                if(bol)
                   break;  //para o looping interno caso bol seja verdadeiro
            }    
            if(bol)
                break; //para o looping externo caso bol seja verdadeiro
        }
        
        /*IMPRIMINDO OS RESULTADOS*/
        System.out.println("SOMA: " +s);
        if(bol){  //caso bol seja verdadeiro imprime os valores do vetor que resultam em SOMA e suas posições
            System.out.println("valor1: " +a[i]+" + valor2: " + a[j]);
            System.out.println("posições respectivas "+i+" e "+j);
        }
        System.out.println("Resultado " + bol);      
        
    }
    
}

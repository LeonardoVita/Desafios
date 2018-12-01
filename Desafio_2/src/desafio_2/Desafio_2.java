/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package desafio_2;

import java.util.Scanner;

/**
 *
 * @author Leo
 */
public class Desafio_2 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
       
        /*RECEBENDO A FRASE DO USUARIO*/
       Scanner scan = new Scanner(System.in);        
       System.out.println("Digite a frase:");
       Vetor vet = new Vetor(scan.nextLine().toCharArray());       
       
       /*CALCULA E IMPRIME PALINDROMO*/
       vet.calculaPalindromo();
       vet.imprimirPalindromo();               
    }
    
    
    
}

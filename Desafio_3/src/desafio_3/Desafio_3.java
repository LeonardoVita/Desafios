/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package desafio_3;

import java.util.Scanner;

/**
 *
 * @author Leo
 */
public class Desafio_3 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        
        int[] andar = new int[3]; //um vetor que representa os andares
        int menorTempo;          
        int andarCafeteira=2;     //andar inicial da cafeteira fica no meio
        
        Scanner scan = new Scanner(System.in);
        
        /*PEGANDO DADOS DO USUARIO*/
        System.out.println("Digite a quantidade de funcionario dos andares "
                + "1,2 e 3 respectivamente");
        andar[0] = scan.nextInt();
        andar[1] = scan.nextInt();
        andar[2] = scan.nextInt();               
        
        /*O SISTEMA VERIFICA O TEMPO GASTO EM CADA UM DOS ANDARES*/
        
        /*CAFETEIRA NO SEGUNDO ANDAR*/
        menorTempo = ( andar[0]*2 ) + ( andar[2]*2 );  
        
        /*CAFETEIRA NO PRIMEIRO ANDAR*/
        if(menorTempo >( andar[1]*2 )+( andar[2]*4 )){ 
            
        menorTempo =( andar[1]*2 )+( andar[2]*4 ); 
        andarCafeteira=1;
        
        }else{ /*CAFETEIRA NO TERCEIRO ANDAR*/
            if(menorTempo > ( andar[0]*4 )+( andar[1]*2 )){ 
                
                menorTempo =( andar[0]*4 )+( andar[1]*2 );
                andarCafeteira=3;
                
            }    
        }
        /*IMPRIME OS RESULTADOS*/
        System.out.println("Minutos gastos: "+menorTempo+
                " Melhor andar para cafetira: "+andarCafeteira);
    }
    
}

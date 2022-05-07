/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author jerry
 */

import java.util.Stack;
public class pila {

    /**
     * @param args the command line arguments
     */
    public static void main(String args[]) {
       //Entrada (Expresi�n en Postfija)
        String expr = "2 23 6 + * 1 -"; // equivale a 2*(23+6)-1
        String[] post = expr.split(" ");    

        //Declaraci�n de las pilas
        Stack < String > E = new Stack <> (); //Pila entrada
        Stack < String > P = new Stack <> (); //Pila de operandos

        //A�adir post (array) a la Pila de entrada (E)
        for (int i = post.length - 1; i >= 0; i--) {
          E.push(post[i]);
        }

        //Algoritmo de Evaluaci�n Postfija
        String operadores = "+-*/%"; 
        while (!E.isEmpty()) {
          if (operadores.contains("" + E.peek())) {
            P.push(evaluar(E.pop(), P.pop(), P.pop()) + "");
          }else {
            P.push(E.pop());
          } 
        }

        //Mostrar resultados:
        System.out.println("Expresion: " + expr);
        System.out.println("Resultado: " + P.peek());

      }

      private static int evaluar(String op, String n2, String n1) {
        int num1 = Integer.parseInt(n1);
        int num2 = Integer.parseInt(n2);
        if (op.equals("+")) return (num1 + num2);
        if (op.equals("-")) return (num1 - num2);
        if (op.equals("*")) return (num1 * num2);
        if (op.equals("/")) return (num1 / num2);
        if (op.equals("%")) return (num1 % num2);
        return 0;
      }
}

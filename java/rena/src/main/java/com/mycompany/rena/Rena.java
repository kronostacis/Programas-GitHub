/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Project/Maven2/JavaApp/src/main/java/${packagePath}/${mainClassName}.java to edit this template
 */

package com.mycompany.rena;
import java.util.Scanner;

/**
 *
 * @author benja
 */
public class Rena {

    public static void main(String[] args) {
        Integer var1,var2;
        Scanner scan = new Scanner(System.in);
        System.out.println("introduce el valor de l;a variable 1: ");
        var1 = scan.nextInt();
        
        System.out.println("introduce el valor de l;a variable 1: ");
        var2 = scan.nextInt();
        scan.close();
        System.out.println("var 1: " + var1);
        System.out.println("var 2: " + var2);
        
        Integer aux = var1;
        var1 = var2;
        var2 = aux;
        
        System.out.println("var 1: " + var1);
        System.out.println("var 2: " + var2);
    }
    
}

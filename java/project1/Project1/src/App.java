import java.util.*;  


public class App {
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        System.out.println("Introduce tu edad: ");
        Integer edad = sc.nextInt();
        Boolean e = edad>=18;
        if (e){
            System.out.println("Tu tienes " + edad + " años por lo cual eres mayor de edad");
        }
        else {
            System.out.println("Tu tienes " + edad + " años por tanto no eres mayor de edad");
        }
        // para un input de strings se puede usar de la misma forma pero en vez de sc.nextInt
        //es sc.nextLine
        sc.close();
    }
}

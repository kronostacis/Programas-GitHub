import java.util.*; 
public class App {
    public static void main(String[] args) throws Exception {
        Scanner scanner = new Scanner(System.in);
        Integer a,b,c;
        System.out.println("Introduzca el primer numero: ");
        a = scanner.nextInt();
        System.out.println("Introduzca el segundo numero: ");
        b = scanner.nextInt();
        System.out.println("Introduzca el tercer numero: ");
        c = scanner.nextInt();
        scanner.close();
        if (a>b && a>c){
            System.out.println("a es mayor que b y c");
        }
        else if(b>a && b>c){
            System.out.println("b es mayor que a y c");
        }
        else if(c>a && c>b){
            System.out.println("c es mayor que b y a");
       }
    }
}

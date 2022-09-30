import java.util.Scanner;
import java.util.ArrayList;
import java.util.List;
public class App {
    public static void main(String[] args) throws Exception {
        int n;
        List<alumno> listalumnos = new ArrayList<alumno>();
        Scanner scanner = new Scanner(System.in);
        n=scanner.nextInt();
        Scanner scan = new Scanner(System.in);
        for (int i=0; i<n; i++) {
            String nombre = scan.nextLine();
            String rut = scan.nextLine();
            String asignatura = scan.nextLine();
            String nota = scan.nextLine();
            alumno aux = new alumno(nombre,rut,asignatura,nota);
            listalumnos.add(aux);
        }
        scanner.close();
        scan.close();
        for (int i = 0; i <n ; i++){
            listalumnos.get(i).show();
        }
    }
}
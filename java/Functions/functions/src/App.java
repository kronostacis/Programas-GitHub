

public class App {
    public static void main(String[] args) throws Exception {
        String strEdad = "19";
        Integer Edad = Integer.parseInt(strEdad); // con esto paso de str a int
        System.out.println("Edad: " + Edad);
        Double prom = Double.valueOf(Edad)/2;
        System.out.println("double: " + prom);

    }
}

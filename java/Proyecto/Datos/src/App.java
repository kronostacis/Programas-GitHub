import java.util.ArrayList;
import java.util.List;

public class App {
        public static void main(String[] args) throws Exception {
        List<Personas> lista = new ArrayList<Personas>();
        Personas a = new empleado("benjamin","villablanca","fsfaf","431241","cantarana","200000");
        lista.add(a);
        Personas b = new cliente("nicolas","zuñiga","fasf","123213","267 a","abc129387");
        lista.add(b);
        lista.get(0).show();    
        lista.get(1).show();    
    }
}

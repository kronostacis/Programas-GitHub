
public class alumno{
    private String rut, nombre, asignatura, nota;
    
    public String getRut(){
        return rut;
    }
    public void setRut(String rut){
        this.rut = rut;
    }
    public String getNombre(){
        return nombre;
    }
    public void setNombre(String nombre){
        this.nombre = nombre;
    }
    public String getAsignatura(){
        return asignatura;
    }
    public void setAsignatura(String asignatura){
        this.asignatura = asignatura;
    }
    public String getNota(){
        return nota;
    }
    public void setNota(String nota){
        this.nota = nota;
    }
    public void crear(String nombre, String rut ,String asignatura, String nota){
        this.nombre = nombre;
        this.rut = rut;
        this.asignatura = asignatura;
        this.nota = nota;
    }
    public alumno(String nombre, String rut ,String asignatura, String nota ){
        this.crear(nombre,rut,asignatura,nota);
    }

    public void show(){
        System.out.println("nombre: " + this.getNombre());
        System.out.println("Rut: " + this.getRut());
        System.out.println("Asignatura: " + this.getAsignatura());
        System.out.println("Nota: " + this.getNota());
    }

}
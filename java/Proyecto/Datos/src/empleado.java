//package datos;

public class empleado extends Personas {

    private String salary;
    
    public empleado(String name, String lastName, String email, String phone, String address,String salary) {
        super(name, lastName, email, phone, address);
        this.salary = salary;
    }

    public String getSalary(){
        return salary;
    }

    public void setSalary(String salary){
        this.salary = salary;
    }
    
    @Override
    public void show(){
        System.out.println("nombre: " + this.getName());
        System.out.println("apellido: " + this.getLastName());
        System.out.println("email: " + this.getEmail());
        System.out.println("numero: " + this.getPhone());
        System.out.println("direccion: " + this.getAddress());
        System.out.println("salario: " + this.getSalary());
     }
}

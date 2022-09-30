public class Personas {
    protected String name;
    protected String lastName;
    protected String email;
    protected String phone;
    protected String address;

    public String getName() {
        return name;
    }
    public void setName(String name) {
        this.name = name;
    }

    public String getLastName() {
        return lastName;
    }

    public void setLastName(String lastName) {
        this.lastName = lastName;
    }

    public String getEmail() {
        return email;
    }

    public void setEmail(String email){
        this.email = email;
    }

    public String getPhone() {
        return phone;
    }

    public void setPhone(String phone){
        this.phone = phone;
    }

    public String getAddress() {
        return address;
    }

    public void setAddress(String address){
        this.address = address;
    }

    public void crear(String name, String lastName, String email, String phone, String address){
        this.name = name;
        this.lastName = lastName;
        this.email = email;
        this.phone = phone;
        this.address = address;
    }

    public Personas(String name, String lastName, String email, String phone, String address){
        this.crear(name, lastName, email, phone, address);
    }
    public void show(){
       System.out.println("nombre: " + this.getName());
       System.out.println("apellido: "+ this.getLastName());
       System.out.println("email: " + this.getEmail());
       System.out.println("numero: "+ this.getPhone());
       System.out.println("direccion: "+ this.getAddress());
    }
}

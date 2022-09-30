public class cliente extends Personas{

    private String ClientNumber;
    public cliente(String name, String lastName, String email, String phone, String address,String ClientNumber) {
        super(name, lastName, email, phone, address);
        this.ClientNumber = ClientNumber;
    }
    
    public String getClientNumber() {
        return ClientNumber;
    }
    public void setClientNumber(String ClientNumber) {
        this.ClientNumber = ClientNumber;
    }
    
    @Override
    public void show(){
        System.out.println("nombre: " + this.getName());
        System.out.println("apellido: " + this.getLastName());
        System.out.println("email: " + this.getEmail());
        System.out.println("numero: " + this.getPhone());
        System.out.println("direccion: " + this.getAddress());
        System.out.println("numero de cliente: " + this.getClientNumber());
     }
}

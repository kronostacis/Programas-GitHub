
public class vehiculo {
    private String motor;
    private String modelo;
    private String patente;
    private Integer maxSpeed;
    private Integer ruedas;

    public String getMotor() {
        return motor;
    }
    public void setMotor(String motor) {
        this.motor = motor;
    }

    public String getModelo() {
        return modelo;
    }

    public void setModelo(String modelo) {
        this.modelo = modelo;
    }

    public Integer getMaxSpeed() {
        return maxSpeed;
    }

    public void setMaxSpeed(Integer maxSpeed) {
        this.maxSpeed = maxSpeed;
    }

    public Integer getRuedas() {
        return ruedas;
    }

    public void setRuedas(Integer ruedas) {
        this.ruedas = ruedas;
    }

    public String getPatente(){
        return patente;
    }

    public void setPatente(String patente) {
        this.patente = patente;
    }
    public void crear(String motor, String modelo, String patente, Integer maxSpeed, Integer ruedas){
        this.motor = motor;
        this.modelo = modelo;
        this.patente = patente;
        this.maxSpeed = maxSpeed;
        this.ruedas = ruedas;
    }

    public vehiculo(String motor, String modelo, String patente, Integer maxSpeed, Integer ruedas){
        this.crear(motor, modelo, patente, maxSpeed, ruedas);
    }

    public void show(vehiculo car){
        System.out.println("motor: " + car.getMotor() + " modelo: " + car.getModelo() + " patente: " + car.getPatente() + " maxima velocidad: " + car.getMaxSpeed() + " ruedas: " + car.getRuedas() );
    }
}
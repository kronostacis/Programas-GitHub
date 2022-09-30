

public class App{
    public static void main(String[] args) throws Exception {
        vehiculo car = new vehiculo("1.5", "reno", "pn31ef", 220, 4);
        car.show(car); 
        car.setModelo("oppo reno 5 lite");
        car.show(car);
    }

}


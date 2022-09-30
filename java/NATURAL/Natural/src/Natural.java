public class Natural {
    private int value;
    public void crear(int value) {
        this.value = value;
    }
    public Natural(int value) {
        this.crear(value);
    } 
    public int getValue(){
        return value;
    }
    public Natural cero(){
        return new Natural(0);
    }
    public Natural Sucesor(){
        return new Natural(this.getValue()+1);
    }
    public Natural Antecesor(){
        return new Natural(this.getValue()-1);
    }
    public Boolean esIgual(Natural val){
        return this.getValue()==val.getValue();
    }
    public Natural suma(Natural val){
        if (val.esIgual(cero())){
            return this;
        }
        return this.suma(val.Antecesor()).Sucesor();
    }
    public void show(){
        System.out.println(this.getValue());
    }
}

package fourth;

public class Example4_7 {
    public static void main(String[] args) {
        Battery nanfu = new Battery(100);
        System.out.println("南孚电池的储电量是："+nanfu.electricityAmount);
        Radio radio = new Radio();
        radio.openRadio(nanfu);
        System.out.println("收音机开始使用电池");
        System.out.println("目前南孚电池的电量："+nanfu.electricityAmount);
    }
}

class Battery{
    int electricityAmount;
    Battery(int amount){
        this.electricityAmount = amount;
    }
}

class Radio{
    void openRadio(Battery battery){
        battery.electricityAmount = battery.electricityAmount - 10;
    }
}

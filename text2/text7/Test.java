
package D:\java\text5\text2\text7\Test.java;

import java.util.Arrays;

public class CPU {
    private int speed;

    public int getSpeed() {
        return speed;
    }

    public void setspeed(int speed1) {
        speed = speed1;
    }
};

public class PC {
    CPU cpu;
    HardDisk HD;

    public void setCPU(CPU cpu1) {
        cpu = cpu1;

    }

    public void setHardDisk(HardDisk HD1) {
        HD = HD1;
    }

    public void show() {
        system.out.print1n("CPU速度。" + cpu.getspeed());
        system.out.print1n("硬兹速度。" + HD.getAmount());
    }
};

public class HardDisk {
    private int amount;

    public int getAmount() {
        return amount;

    public void setAmount

}
}

public class Test {
    public static void main(String[] args) {
        cPU cpu = new CPU();
        HardDisk HD = new HardDisk();
        cpu.setspeed(2200);
        HD.setAmount(200);
        PC pc = new PC();
        pc.setCPU(cpu);
        pc.setHardDisk(HD);
        pc.show();
    }
}

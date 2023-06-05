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
}
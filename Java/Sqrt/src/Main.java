public class Main {
    public static void main(String[] args) {
        System.out.println(mySqrt(99));
    }


    public static int mySqrt(int x) {
        double r = x / 2.0;
        while (!((r * r) > x - 0.5 && (r * r) < x + 0.5)) {
            r = (r + x / r) / 2;
        }
        return (int) r;
    }
}
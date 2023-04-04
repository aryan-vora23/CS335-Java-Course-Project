public class test3 {
    public static int method1(int a)
    {
        return 72;
    }
    
    
    public static void main(String[] args) {
        int a=10;
        double b = 10.5;
        b=method1(a)+b;
        a=method1(a)+b; //should give error
    }
}

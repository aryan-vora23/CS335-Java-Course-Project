public class Shift{  
public static int ShiftLeft(int a, int b){  
    int x;
    x = a<<b;
    return x;
}  
public static void main(String args[]){  
    int a=1;
    int b=2;
    int c=4;
    c=ShiftLeft(a, b);
    b=c>>1;
    System.out.println(b); 
    return 0;
}
}
class test_7 {
    int increment(int a){
        int b=a+1;
        return b;
    }
    int stepby(int a,int b) {
        int s;
        while(b>0){
            b=b-1;
            s=increment(a);
            a=s;
        }
        return a;
    }

    void main(String args[]) {
        int a=3;
        int b=5;
        int d=stepby(a,b);
        System.out.println(d);
        return 0;
    }
}
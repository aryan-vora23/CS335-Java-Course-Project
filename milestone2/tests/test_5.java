class test_5 {
    int f(int a) {
        if(~a) a=a+2;
        else a=a-2;
        return a;
    }

    void main(String args[]) {
        int a=5;
        int b=3;
        int i;
        for(i=0;i<10;i=i+1){
          b=b+2;
        }
        a=f(a);
        int x=b%a;
        System.out.println(x);  //comment push
        return 0;
    }
}
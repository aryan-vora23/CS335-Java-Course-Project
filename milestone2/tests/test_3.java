class test_5 {
    int add(int a,int b,int c,int d){
        int sum;
        int s1=1;
        int s2=1;
        while(b>0){
          s1=s1*a;
          b=b-1;
        }
        while(d>0){
          s2=s2*c;
          d=d-1;
        }
        sum=s1+s2;
        return sum;
    }

    void main(String args[]) {
        int a=2;
        int b=2;
        int c=3;
        int d=3;
        int sum=add(a,b,c,d);
        System.out.println(sum);
        return 0;
    }
}
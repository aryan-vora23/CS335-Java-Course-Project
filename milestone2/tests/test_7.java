class test_10 {
    int isleap(int yr){
        int a1=400;
        int b1=100;
        int c1=4;
        int a=yr%a1;
        int b=yr%b1;
        int c=yr%c1;
        if(c==0) {
            if(a==0&&b==0) return 1;
            else if(b!=0) return 0; 
        }
        else return 0;
    }

    void main(String args[]) {
        int num=2;
        int yr=2001;
        int c=isleap(yr);
        int day=0;
        if(num==1||num==3||num==5||num==7||num==8||num==10||num==12) {
            day=31;
        }
        else if(num==4||num==6||num==9||num==11) {
            day=30;
        }
        else if(num==2) {
            if(c==1) day=29;
            else day=28;
        }
        else day=9999;
        System.out.println(day);    // comment push
        return 0;
    }
}
class FactorialExample2{  
  int x;
 static int factorial(int n){ 
  int a=1;
  this.x=a;
  if (n == 0)    
    return 1;    
  else    
    return(n * factorial(n-1));   
  return 0; 
 }    
 public static void main(String args[]){  
  int i=2,fact=1,z=0;  
  int number=4;//It is the number to calculate factorial    
  fact = factorial(number);   
  // b=main.factorial(a);
  System.out.println("Factorial of "+number+" is: "+fact);    
 }  
}
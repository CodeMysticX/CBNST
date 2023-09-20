#include<stdio.h>
#include<math.h>
double f(double x){
   return(2*x - log10(x)- 7);
}
double g(double x){
   return (7+log10(x))/2;
}
double h(double x){
   return(1/(2*x));
}
int i=0;
void iteration(double a){
    double r=f(a),x;
    i++;
    printf("\nIteration no : %d,value of x is 
    : %lf, value at current iteration is : %lf\n",i,a,r);
    x =g(a);
    if(fabs(x-a)<=0.0001){
         printf("The root of given equation is - %lf\n",a);
         printf("steps are -%d\n",i);
         return;
    }
    iteration(x);
}
int main(){
   double a,b,m;
   int z=1;
   printf("The equation is = x^3 - 2x^2 - 4. \n");
   do{
       printf("Enter the first root - ");
       scanf("%lf",&a);
       printf("Enter the second root - ");
       scanf("%lf",&b);
       m = (a+b)/2;
       if(fabs(h(a))<1 && fabs(h(b))<1){
            printf("Roots are accepted!");
            z=0;
       }
       else{
            printf("Invalid Roots, Please enter correct values!\n");
       }
    }while(0);
    iteration(m);
    return 0;
}

#include <stdio.h>

double f(double x){
    return (x*x*x - 5*x + 1);
}

int i=0;

void Secant(double x0, double x1){
    double m= x1 - ((x1-x0)/(f(x1)-(f(x0))))*f(x1);
    double r=  f(m);
    printf("The Roots are %lf  , %lf  and the  values of x, f(x) are %lf  , %lf \n", x0, x1, m,r);
    i++;
    
    if(m-x0<=0.0001 || x1-m<=0.0001){
        printf("\n\nThe root of given Equation is -  %f \n", m);
        printf("Steps are - %d \n", i);
        return;
    }
    
    if(f(x0)*f(m)<0){
        Secant(x0,m);
    }
    else if(f(m)*f(x1)<0){
        Secant(m,x1);
    }
}

int main()
{
    double x0, x1, m;
    int o=1;
    printf("The equation is =  x^3 - 5*x + 1. \n");

    do{
        printf("Enter the first interval = ");
        scanf("%lf", &x0);
    
        printf("Enter the second interval = ");
        scanf("%lf", &x1);
        if(f(x0)*f(x1)<0){
            printf("Roots are accepted.\n");
            o=0;
        }
        else{
            printf("Invalid Roots ,Please Enter Correct values.\n");
        }
    }while(o);
    Secant(x0,x1);
    return 0;
}
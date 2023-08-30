#include<stdio.h>
double truncate(double n){
    double t = (10e3);
    double s = (int)(n*t)/t;
    printf("Number after trancation : %lf\n",s);
    return s;
}
double Roundoff(double n){
    double y ;
    int r = n*10e4;
    int m = r%10;
    if(m>5){
        r=r/10;
        r=r+1;
        y = (double) r;
        y=y/10000;
    }
    else if(m<5){
        r=r/10;
        y = (double) r;
        y=y/10000;
    }
    else{
        r=r/10;
        int z;
        z= r%10;
        if(z%2==0){
            r=r+1;
        }
        y = (double)r;
        y = y/10000;
    }
    return y;
}
int main(){
    double x,y,Ea,Er,Ep,o;
    printf("Enter the value of X : ");
    scanf("%lf",&x);
    printf("--------------------------------------------------\n");
    printf("AFTER TRUNCATION: ");
    y = truncate(x);
    Ea = x-y;
    if(Ea<0){
        Ea = -Ea;
    }
    Er = Ea/x;
    Ep = Er*100;
    printf("Absolute Error :%0.8lf\n",Ea);
    printf("Relative Error :%0.8lf\n",Er);
    printf("Error Percentage :%0.8lf\n",Ep);
    printf("-------------------------------------------\n");
    o = Roundoff(x);
    printf("AFTER ROUNDOFF:");
    printf("Number after Roundoff the value :%lf\n",o);
    Ea = x-o;
    if(Ea<0){
        Ea = -Ea;
    }
    Er = Ea/x;
    Ep = Er*100;
    printf("Absolute Error :%0.8lf\n",Ea);
    printf("Relative Error :%0.8lf\n",Er);
    printf("Error Percentage :%0.8lf\n",Ep);
}
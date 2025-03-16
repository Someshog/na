#include <stdio.h>
#include <math.h>
#define EPS 0.0000005
#define F(x) x*(log(x)/log(10)) - 1.2

int main(){
    float x2,x1,x0,f2,f1,f0;
    int itr;
    printf("No. of iterations: ");
    scanf("%d",&itr);
    for(x1=1.0;;){
        f1 = F(x1);
        if(f1>0){
            break;
        }
        else{
            x1+=0.1;
        }
    }
    x0 = x1 - 0.1;
    f0 = F(x0);
    printf("\n\n\tITERATION\t x2\t\t F(x)\n");
    for (int i = 0; i < itr; i++)
    {
        x2 = (x1 + x0)/2;
        f2 = F(x2);
        if(f2*f0>0){
            x1 = x2;
            f1 = f2;
        }
        else{
            x0 = x2;
            f0 = f2;
        }
        if(fabs(x2)>EPS){
            printf("\n\t%d\t %f\t\t%f\n", i + 1, x2, f2);

        }

    }
    printf("\n Root = %f\n", x2);

}
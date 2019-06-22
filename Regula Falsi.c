#include<stdio.h>
#include<math.h>
float f(float x);
int main()
{
    float a,b,x0,x1,x2,c,d;
    int i;
    printf("Enter accuracy level: ");
    scanf("%f",&d);
    for(i=0;i<=100;i++)
    {
        if(f((float)i)*f((float)(i+1))<0)
        {
            a=i;
            b=i+1;
        }
    }
    if(f(a)>0)
    {
        x1=a;
        x0=b;
    }
    else
    {
        x0=a;
        x1=b;
    }
    do
    {
        c=x2;
        x2=(x0*f(x1)-x1*f(x0))/(f(x1)-f(x0));
        if(f(x2)>0)
            x1=x2;
        else
            x0=x2;
    }
    while((int)(c*pow(10,d))-(int)(x2*pow(10,d))!=0);
    printf("Root = %f",x2);
    return 0;
}
float f(float x)
{
    float y;
    y=cos(x)-x*exp(x);
    return y;
}

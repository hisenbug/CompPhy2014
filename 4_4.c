#include <stdio.h>
#include <math.h>

double fun(double x)
{
	if(x==0)
		return 1.0/2.0; // Value will be doubled finally
	else 
		return pow(sin(x)/x,2);
}

double fun1(double x)
{
	if(x==0)
		return 0;
	else 
		return pow(sin(pow(1/x,2)),2);
}

double simp(double (*func)(double), double a, double b, int N)
{
	double dx=(b-a)/N,x=a,I=0,x1,x2,x3,dx6=dx/6.0,dx2=dx/2.0;
	x1=(*func)(x);
	while(x<=b)
	{
		x2=(*func)(x+dx2);;
		x3=(*func)(x+dx);
		I+=dx6*(x1+4*x2+x3);
		x1=x3;
		x+=dx;
	}
	return I;
}

int main()
{
	int N,i;
	double a,b,t=1.0,smp,yan,k=1000.0,ers;
	/*printf("Enetr the value of y_AN: ");
	scanf("%lf",&yan);
	if(b<a)
	{
		t=a; a=b;
		b=t; t=-1.0;
	}*/
	smp=simp(fun,0.0,k,1e7)+simp(fun1,1e-5,1/k,1e6);
	printf("\nIntegration by Simpson's Rule = %.10G\n",2*smp);
	return 0;
}


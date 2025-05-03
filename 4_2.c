#include <stdio.h>
#include <math.h>

float fun(float x)
{
	return sin(x); //Function to be Integrated
}

float trap(float (*func)(float), float a, float b, int N)
{
	float dx=(b-a)/N,x=a,I=0,x1,x2;
	x1=(*func)(x);
	while(x<=b)
	{
		x2=(*func)(x+dx);
		I+=(x1+x2)*dx/2.0;
		x1=x2;
		x+=dx;
	}
	return I;
}

float simp(float (*func)(float), float a, float b, int N)
{
	float dx=(b-a)/N,x=a,I=0,x1,x2,x3,dx6=dx/6.0,dx2=dx/2.0;
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
	int N;
	float a,b,t=1.0;
	printf("Enetr the value of a, b and N: ");
	scanf("%lf%lf%ld",&a,&b,&N);
	if(b<a)
	{
		t=a; a=b;
		b=t; t=-1.0;
	}
	printf("\nIntegration by Trapezium Rule = %.10G\n",t*trap(fun,a,b,abs(N)));
	printf("\nIntegration by Simpson's Rule = %.10G\n",t*simp(fun,a,b,abs(N)));
	return 0;
}

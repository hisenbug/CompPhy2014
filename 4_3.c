#include <stdio.h>
#include <math.h>

double fun(double x)
{
	return sin(x); //Replace Function here
}

double trap(double (*func)(double), double a, double b, int N)
{
	double dx=(b-a)/N,x=a,I=0,x1,x2;
	x1=(*func)(x);
	while(x<=b)
	{
		x2=(*func)(x+dx);
		I+=(x1+x2)*dx/2.0;
		x1=x2; x+=dx;
	}
	return I;
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
		x1=x3; x+=dx;
	}
	return I;
}

int main()
{
	int N=1,i;
	FILE *f;
	double a,b,t=1.0,trp, smp,yan,ert,ers;
	printf("Integrate sin(x) in [0,pi] and y_A=pi: \n");   //Change for each Function
	a=0; b=1; yan=1.0/2.0;	//Change for each Function
	if(b<a)
	{
		t=a; a=b;
		b=t; t=-1.0;
	}
	f=fopen("4.txt","wb"); 
	for(i=1;i<=10;i++)
	{
		N=N*2;
		trp=t*trap(fun,a,b,N);
		smp=t*simp(fun,a,b,N);
		ert=(yan-trp)/yan;
		ers=(yan-smp)/yan;
		fprintf(f,"%d\t%G\t%G\n",N,ert,ers);
	}
	fclose(f);
	printf("\nIntegration by Trapezium Rule = %.10G",trp);
	printf("\nIntegration by Simpson's Rule = %.10G\n",smp);
	return 0;
}


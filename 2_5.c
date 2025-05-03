#include <stdio.h>
#include <math.h>

int n;

double func(double x)
{
	return (pow(x,n)*exp(x));
}

double integrate(int m,double a, double b)
{
	int i=0;
	double s=0.0,d=(b-a)/m;
	for(i=0;i<=m;i++)
		s+=func(a+d*i)*d;
	return s;
}

double rec(int k)
{
	if(k==1)
		return 1.0;
	if(n<=0)
		return exp(1)-1;
	return exp(1)-k*rec(k-1);
}

int main()
{
	printf("Enter n(-ve to exit): ");
	scanf("%d",&n);
	printf("\nn\tIntegration\tRecursion\n");
	while(n>=0)
	{
		printf("%d\t%.10G\t%.10G\n",n,integrate(1e6,0.0,1.0),rec(n));
		scanf("%d",&n);
	}
	return 0;
}
	

#include <stdio.h>
#include <math.h>

double pot(double a) //double floating type for accuracy
{
	double E=0.0,al=4.0;
	double dx=a*1.0e-5, x=0.0, I=0.0;
	E=exp(0.5*al*a*a); 
	dx= (dx>1e-5)?1e-5:dx;
	x=-a+dx/2.0;
	while(x<a)
	{
		I+= (1.0/sqrt(E - exp(0.5*al*x*x)))*dx;
		x+= dx;
	}
	return I;
}

int main()
{
	int i=0;
	double E=0.0,al=4.0;
	double a=1e-4, dx=1.0e-5, x=0.0, I=0.0;
	FILE *f;
	
	printf("\nTime Period for V=0.5*al*x*x: \n");
	printf("Amplitude\tTime Period: \n");
	for(i=0;i<=6;i++)
	{
		a*=10.0;
		x=0; I=0;
		dx=a/1e5;
		dx= (dx>1e-5)?1e-5:dx;
		E=0.5*al*a*a; x=-a+dx/2;
		while(x<a)
		{
			I+= (1.0/sqrt(E - 0.5*al*x*x))*dx;
			x+= dx;
		}
		printf("%G\t%G\n", a, sqrt(2.0)*I);
	}
	
	f=fopen("pot.txt","wb");
	printf("\nTime Period for V=exp(0.5*al*x*x):\n");
	printf("Amplitude\tTime Period: \n");
	a=1e-5; i=0;
	while(a<19)
	{
		I=sqrt(2.0)*pot(a);
		fprintf(f,"%G\t%G\n",a,I);
		if(i%5==0)
			printf("%G\t%G\n", a, I);
		i++; 
		a*= (4*a>1)?1.1:2;
	}
	printf("%G\t%G\n", a/1.1, I);
	fclose(f);
	return 0;
}

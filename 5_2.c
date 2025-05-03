#include <stdio.h>
#include <math.h>

void runge(double x, double p, char in[20]) 
{	// Differentiate V by 2nd Order Runge-Kutta Method to find force
	double E=0.0, dt=1.0e-5, t=0, tt=8.0, v=p;
	int i=0;	// v = p as m=1
	FILE *f;
	f=fopen(in,"wb");
	while(t<tt)
	{
		E=0.5*x*x+0.5*v*v;
		if(i%50==0)
			fprintf(f,"%G\t%G\t%G\t%G\n",x,v,t,E);
		v+= -(x+v*dt/2)*dt; //-dV/dx = -x = F
		x+= v*dt;
		t+= dt;
		i=i%50+1;
	}
	fprintf(f,"%G\t%G\t%G\t%G\n",x,v,t,E);
	fclose(f);
}

void euler(double x, double p, char in[20]) 
{	// Differentiate V by Euler Method to find force
	double E=0.0, dt=1.0e-5, t=0, tt=8.0, v=p;
	int i=0;	// v = p as m=1
	FILE *f;
	f=fopen(in,"wb");
	while(t<tt)
	{
		E=0.5*x*x+0.5*v*v;
		if(i%50==0)
			fprintf(f,"%G\t%G\t%G\t%G\n",x,v,t,E);
		v+= -x*dt; //-dV/dx = -x = F
		x+= v*dt;
		t+= dt;
		i=i%50+1;
	}
	fprintf(f,"%G\t%G\t%G\t%G\n",x,v,t,E);
	fclose(f);
}

int main()
{
	int i=4;
	double x,p;
	printf("Enter x and p: "); 
	scanf("%lf%lf",&x,&p);
	runge(x, p, "rk.txt");
	euler(x, p, "er.txt");
	return 0;
}

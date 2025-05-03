#include <stdio.h>
#include <math.h>

int main()
{
	double v_x=0.0,v_y=1.63,x=0.5,y=0,dt=0.001,tt=50.0,t=0.0,k=1.0,th=0,a=0.0;
	FILE *f;
	int i=0; double E=0;
	printf("Enter x,y,v_x,v_y: ");
	scanf("%lf%lf%lf%lf",&x,&y,&v_x,&v_y);
	f=fopen("out.txt","wb");
	do{
		E=-1.0/sqrt(x*x+y*y) + 0.5*(v_x*v_x+v_y*v_y);
		if(i%20==0)
			fprintf(f,"%lf\t%lf\t%lf\t%lf\n",x,y,t,E);
		if(x==0)
			th=M_PI/2.0;
		else if(x>0)
			th=atan(y/x);
		else if(x<0 && y<=0)
			th=atan(y/x)-M_PI;
		else if(x<0 && y>=0)
			th=atan(y/x)+M_PI;	
		
		a=k/(x*x+y*y);
		v_y = v_y-a*sin(th)*dt;
		y = y+v_y*dt;
		v_x = v_x-a*cos(th)*dt;
		x = x+v_x*dt;
		t=t+dt;
		++i;
	}while(t<=tt);
	fprintf(f,"%lf\t%lf\t%lf\t%lf\n",x,y,t,E);
	fclose(f);
}

		
	

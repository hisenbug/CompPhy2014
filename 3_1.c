#include <stdio.h>
#include <math.h>

int main()
{
	double v=700.0,v_x,v_y,x,y,dt=0.05,t=0,g=-9.8;
	double max=0,tt=0,range;
	FILE *f,*ran;
	int theta,i,th_m;
	char file[20];
	ran=fopen("normal.txt","w");
	printf("\nFiring Angle\tTheoretical Range,Time\t\tNumerical Range,Time\n\n");
	for(theta=20;theta<=60;theta+=5)
	{
		v_x=v*cos(theta*M_PI/180.0);
		v_y=v*sin(theta*M_PI/180.0);
		y=x=t=0.0;  i=0;
		tt = (2.0*v_y)/(-1*g); 	
		range =  v*v*sin(2*theta*M_PI/180.0)/(-1*g);
		sprintf(file,"a%d.txt",theta);
		f=fopen(file,"ab+");
		do{
			if(i%20==0)
				fprintf(f,"%lf\t%lf\t%lf\n",t,y,x);
			v_y=v_y+g*dt;
			y=y+v_y*dt;
			x=x+v_x*dt;
			t=t+dt;
			++i;
		}while(y>=0);
		fprintf(f,"%lf\t%lf\t%lf\n",t,y,x);
		printf("%d\t\t%lf, %.8lf\t%lf, %lf\n",theta,range,tt,x,t);
		fclose(f);
		if(x>max) 
		{ 
			th_m=theta;
			max=x;
		}
		fprintf(ran,"%d\t%lf\t%lf\n",theta,x,range);
	}
	printf("\nMaximum range is for firing angle =%d deg\n",th_m);
	fclose(ran);
}
		
	

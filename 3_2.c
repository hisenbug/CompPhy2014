#include <stdio.h>
#include <math.h>

int main()
{
	double v=700.0,v_x,v_y,x,y,dt=0.005,t=0,g=-9.8,b=4e-5,a=0,max=0;
	FILE *f,*ran;
	int theta,i,th_m;
	char file[20];
	ran=fopen("res.txt","w");
	for(theta=20;theta<=60;theta+=5)
	{
		v=700.0;
		v_x=v*cos(theta*M_PI/180.0);
		v_y=v*sin(theta*M_PI/180.0);
		y=x=t=0.0;
		i=0;
		sprintf(file,"b%d.txt",theta);
		f=fopen(file,"wb");
		do{
			if(i%200==0)
				fprintf(f,"%lf\t%lf\t%lf\n",t,y,x);
			a=g-b*v*v_y;		
			v_y=v_y+a*dt;
			y=y+v_y*dt;
			
			v_x=v_x-b*v*v_x*dt;
			x=x+v_x*dt;
			t=t+dt;
			v=sqrt(v_x*v_x+v_y*v_y);
			++i;
		}while(y>=0);
		fprintf(f,"%lf\t%lf\t%lf\n",t,y,x);
		if(x>max) 
		{ 
			th_m=theta;
			max=x;
		}
		fprintf(ran,"%d\t%lf\n",theta,x);
		fclose(f);
	}
	printf("Maximum range is for firing angle =%d deg\n",th_m);
	fclose(ran);
}
		
	

#include <stdio.h>
#include <math.h>

void path(double B_z, double E_y, char in[20])
{
	double v_x=1.0, v_y=1.0, v_z=1.0, t=0, dt=1e-9, tt=1e-5;
	double x=0.0,y=0.0,z=0.0, qm=-1.758E11;
	FILE *f; int i=0;
	if(E_y) tt=1.25e-4;
	f=fopen(in,"wb");
	while(t<tt)
	{
		if(i%10==0)
			fprintf(f,"%G\t%G\t%G\t%G\n",x,y,z,t);
		//Forces acting are Lorentz Force and Coulomb Force
		v_x= v_x + qm*B_z*v_y*dt;
		v_y= v_y - qm*B_z*v_x*dt + qm*E_y*dt;
		x= x + v_x*dt;
		y+= v_y*dt;
		z+= v_z*dt;
		t+= dt;
		++i; 
	}
	fprintf(f,"%G\t%G\t%G\t%G\n",x,y,z,t);
	fclose(f);
}

int main()
{
	path(1e-4, 0.0, "em_a.txt");
	path(1e-6, 1.0, "em_b.txt");
	return 0;
}
	

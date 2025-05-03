#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define M 1000	//Total no. of steps

int main()
{
	int i=0,t=0,st[2*M+1],ct[2*M+1],cty[2*M+1],x,y;
	float rmd=0.0;
	srand(time(NULL));
	FILE *f;
	
	//1D Motion
	f=fopen("1D.txt","wb");
	for(i=0;i<2*M+1;i++)
	{
		st[i]=i-M;
		ct[i]=0;
	}
	for(i=0;i<100*M;i++)
	{
		x=0;
		for(t=0;t<M;t++)
		{ //1 second = 1 step
			if(rand()%2)
				x+=1;
			else
				x+=-1;
		}
		++ct[x+M];
	}	
	for(i=0;i<2*M+1;i+=2) //Only even no. of steps are possible!
	{
		fprintf(f,"%d\t%G\n",st[i],(1.0*ct[i])/(100.0*M));
		rmd+=ct[i]*st[i]*st[i];
	}
	rmd=sqrt(rmd/(100.0*M));
	printf("RMSD (1D) for 1000 steps : %G\n",rmd);
	fclose(f);
	
	//2D Motion
	f=fopen("2D.txt","wb");
	for(i=0;i<2*M+1;i++)
	{
		st[i]=i-M;
		ct[i]=0; cty[i]=0;
	}
	for(i=0;i<100*M;i++)
	{
		x=0; y=0;
		for(t=0;t<M;t++)
		{ //1 second = 1 step
			switch(rand()%4)
			{
				case 0:
					x+=1;
				break;
				case 1:
					y+=1;
				break;
				case 2:
					x-=1;
				break;
				case 3:
					y-=1;
				break;
			}
		}
		++ct[x+M]; ++cty[y+M];
	}	
	rmd=0;
	for(i=0;i<2*M+1;i++)
		rmd+= (ct[i]+cty[i])*st[i]*st[i];
	rmd=sqrt(rmd/(100.0*M));
	printf("\nRMSD for 1000 steps (2D): %G\n",rmd); 
	for(i=M-200;i<=M+200;i++)
		for(t=M-200;t<=M+200;t++)
			fprintf(f,"%d\t%G\t%G\n",st[i],st[t],(1.0*ct[i]*cty[t])/(10000.0*M*M));
	fclose(f);
	return 0;
}

#include <stdio.h>
#include <math.h>

int sort(double *a, int n)
{
	int i,j,p;
	double temp;
	for (i=0;i<n-1;i++)
	{
		temp=a[i];
		p=i;
		for(j=i+1;j<n;j++)
		if(a[j]<temp)
		{
			temp=a[j];
			p=j;
		}
		temp=a[i];
		a[i]=a[p];
		a[p]=temp;
	}
	for(i=1;i<n;i++)
		if(a[i]>=0 && a[i-1]<0)
			return i;
}

void sortf(float *a, int n)
{
	int i,j,p;
	float temp;
	for (i=0;i<n-1;i++)
	{
		temp=a[i];
		p=i;
		for(j=i+1;j<n;j++)
		if(a[j]<temp)
		{
			temp=a[j];
			p=j;
		}
		temp=a[i];
		a[i]=a[p];
		a[p]=temp;
	}
}

int main()
{
	double s1,t[5],st1,st2;
	float sf1,tf[5],stf1,stf2;
	double x[]={2.718281823,-3.141592654, 1.414213562, 0.5772156649, 0.3010299957};
	double y[]={1486.2497,878366.9879,-22.37492,4773714.647,0.000185049};
	int i,n=5,k=0;
	s1=0.0; sf1=0.0;
	printf("Double\t\t\tFloat\n");
	for(i=0;i<n;i++)
	{
		t[i]=x[i]*y[i];
		s1+=t[i];
		tf[i]=(float)(x[i]*y[i]);
		sf1+=tf[i];
	}
	printf("Forward Sum:\n%.10E\t%.10G\n",s1,sf1);
	s1=0.0; sf1=0;
	for(i=n-1;i>=0;i--)
	{
		s1+=t[i];
		sf1+=tf[i];
	}
	printf("Reverse Sum:\n%.10G\t%.10G\n",s1,sf1);
	k=sort(t,5);
	sortf(tf,5);
	printf("\nAfter Sort:\n");
	st1=st2=0; stf1=stf2=0;
	for(i=0;i<k;i++)
	{
		st1+=t[i];
		stf1+=tf[i];
	}
	for(i=k;i<n;i++)
	{
		st2+=t[i];
		stf2+=tf[i];
	}
	s1=st1+st2;
	sf1=stf1+stf2;
	printf("Forward Sum:\n%.10G\t%G\n",s1,sf1);
	st1=st2=0;
	stf1=stf2=0;
	for(i=k-1;i>=0;i--)
	{
		st1+=t[i];
		stf1+=tf[i];
	}
	for(i=n-1;i>=k;i--)
	{
		st2+=t[i];
		stf2+=tf[i];
	}
	s1=st1+st2;
	sf1=stf1+stf2;
	printf("Reverse Sum:\n%.10G\t%G\n",s1,sf1);
	return 0;
}

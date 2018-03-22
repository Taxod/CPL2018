#include <stdlib.h>
#include <stdio.h>
#include <cmath>
double bi(double xL ,double xU);
double func(double x);
int main(int argc, char const *argv[])
{
	double i;
	for (i = -5; i < 5; i+= 0.1)
	{
		if (func(i)*func(i+0.1) < 0)
		{
			bi(i,i+0.1);
		}
	}
	return 0;
}

double func(double x){
	double ans = cosh(x)*cos(x)+1;
	return ans;
}

double bi(double xL ,double xU){
	double eps_x=1E-06;
	int i,maxit=99;
	int flag=0;
	double fL,fU,xM,fM,dx;
	printf("Input interval xL and xU of the root = ");
	// scanf_s("%lf %lf",&xL,&xU);
	if(xL>xU)
	{dx=xL;xL=xU;xU=dx;
	}
	fL=func(xL);
	fU=func(xU);
	printf("Input interval [xL,xU] = [%G,%G]\n",xL,xU);
	printf("Function values[fL,fU] =[%G,%G]\n",fL,fU);

	if((fL*fU)>0.0)
	{
		printf("Error input of interval [xL,xU] = [%G,%G]\n",xL,xU);
		printf("Function values[fL,fU] =[%G,%G]\n",fL,fU);
		printf("No root between[xL,xU]!\n");exit(0);
	}
	xM=(xL+xU)/2.0;
	fM=func(xM);
	dx=xU-xM;
	printf("Iteration %d :[xL,xU] =[%.10f,%.10f],fM=%.10f\n",0,xL,xU,fM);
	for(i=1;i<maxit;i++)
	{
		if(fM==0.0){flag=1;break;};
		if(dx<eps_x){flag=1;break;};
		if((fM*fL)<0.0){xU=xM;fU=fM;}
		else{xL=xM;fL=fM;}
		xM=(xU+xL)/2.0;fM=func(xM);dx=xU-xL;
		printf("Iteration %d :[xL,xU]=[%.10f,%.10f],fM=%.10f\n",i,xL,xU,fM);
	}
	if(flag==1)
	{printf("\nSolution found no of iteration=%d\n",i-1);
	printf("Solution:x=%.10f,f(x)=%.10f\n\n",xM,fM);
	}
	if(flag==0)
	{printf("The maximum number of iterations was exceeded!\n");}
	return fM;
}
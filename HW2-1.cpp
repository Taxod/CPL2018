#include<stdio.h>
#include<math.h>
#define M_PI 3.14159265358979323846
int main(){
	float R = 1.0;//¥b®| 
	for(int i = 1 ; i <= 20 ; i++){
		float Ap = (i*10)*R*R*tan(M_PI/(i*10));
		printf("%lf\n",Ap);
	}
	//i*10 Ãä¼Æ Ap ­±¿n 
	return 0;
}

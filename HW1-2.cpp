#include<stdio.h>
int main(){
	//(FtµØ¤ó-32)*(5/9)
	float F = 12;
	float C;
	for(int i = 0 ; i <= 10 ; i++){
		C = (F-32)*5/9;
		printf("%10.0lf  %10.4lf\n",F,C);
		F += 20;
	}
	return 0;
} 

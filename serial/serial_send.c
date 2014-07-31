#include"stdio.h"
#include"math.h"
#include"string.h"


#define pi 3.1415926


void delay(int a){
	int i,j,delay;
	for(i = 0 ;  i < 1000*a; i++){
		delay = 0;
		for(j = 0; j < 1000*a; j++){
			delay = delay+1;
		}
	}
}


int main()
{
	float angle, x, y,rad;
	int i,N,dltime;
	angle = 0;
	//getchar();
	printf("input the num of circles, delay time: ");
	scanf("%d,%d", &N, &dltime);
	for (i = 0; i < 100*N ; i++){
		angle = angle + 3.6;
		rad = angle/180*pi;
		x = cos(rad);
		y = sin(rad);
		printf("%f \n", x);
		delay(dltime);
	}
	return 0;


}

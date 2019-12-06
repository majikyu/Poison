//rand()の最大は32767
#include<stdio.h>
#include<math.h>
#include <time.h>
#include <stdlib.h>

#define MAX_WAIT 10 // 最長の間隔時間(秒)
#define EXEC_TIME 60// この秒数分の事象発生を出力
#define LMD 200// 単位時間(1分)当たりに起こる平均回数
#define ACCURACY 1000// (1 / ACCURACY)秒単位で時間を計算．最小単位

int judge_time(int ran,int bound[MAX_WAIT*ACCURACY]){
	int i,j;
	for(i=0;i<=MAX_WAIT*ACCURACY;i++){
		if(ran<=bound[i]){
			return i;
		}
	}
	return MAX_WAIT*ACCURACY;
}

void main(){
	double t,wait,amount=0,p[MAX_WAIT*ACCURACY];
	int i,ran,ransum=0;
	int bound[MAX_WAIT*ACCURACY];
	//累積分布関数の値を格納
	for(t=0;t<=MAX_WAIT*ACCURACY-1;t++){//0.5を加えて，1.5から2.5で2秒としている
		p[(int)t] = 1 - exp(-LMD*((t+0.5)/(60*ACCURACY)));//単位時間(分)を60で割って秒単位に合わせる
	}
	
	//それぞれの待ち時間である境界を計算
	for(i=0;i<=MAX_WAIT*ACCURACY-1;i++){
		bound[i]=RAND_MAX * p[i];
	}
	
	//ランダム変数で間隔時間を決定
    srand((unsigned)time(NULL));
	for(i=0;;i++){
		ran = rand();
		wait = judge_time(ran,bound);
		if(amount + wait > EXEC_TIME*ACCURACY)break;
		amount += wait;
		ransum+=ran;
		printf("wait %.3lf sec\n",wait/ACCURACY);
    }
	
	printf("\navg bound time: %.5lf sec\n",amount/(ACCURACY*i));
	printf("amount of phenomenon: %d times\n",i);
}
	

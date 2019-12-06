//rand()�̍ő��32767
#include<stdio.h>
#include<math.h>
#include <time.h>
#include <stdlib.h>

#define MAX_WAIT 10 // �Œ��̊Ԋu����(�b)
#define EXEC_TIME 60// ���̕b�����̎��۔������o��
#define LMD 200// �P�ʎ���(1��)������ɋN���镽�ω�
#define ACCURACY 1000// (1 / ACCURACY)�b�P�ʂŎ��Ԃ��v�Z�D�ŏ��P��

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
	//�ݐϕ��z�֐��̒l���i�[
	for(t=0;t<=MAX_WAIT*ACCURACY-1;t++){//0.5�������āC1.5����2.5��2�b�Ƃ��Ă���
		p[(int)t] = 1 - exp(-LMD*((t+0.5)/(60*ACCURACY)));//�P�ʎ���(��)��60�Ŋ����ĕb�P�ʂɍ��킹��
	}
	
	//���ꂼ��̑҂����Ԃł��鋫�E���v�Z
	for(i=0;i<=MAX_WAIT*ACCURACY-1;i++){
		bound[i]=RAND_MAX * p[i];
	}
	
	//�����_���ϐ��ŊԊu���Ԃ�����
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
	

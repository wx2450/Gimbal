#include "stm32f4xx_hal.h"
#include "math.h"
#ifndef _SMC_H_
#define _SMC_H_
/*
���2��ϵͳ
�ο����ӣ�
������ϵͳ��ʮ������ģ���ƽ��� - Chenglin Li������ - ֪��
https://zhuanlan.zhihu.com/p/138860110
������ϵͳ��ʮ�ģ���ģ������������� - Chenglin Li������ - ֪��
https://zhuanlan.zhihu.com/p/139066859
*/

class SMC{
 public:

	float u;
	//��ʼ���б�
	SMC(float C,float K,float ref,float error_eps,uint16_t p,uint16_t q,float u_max,float J,float epsilon):
	C(C),K(K),ref(ref),error_eps(error_eps),p(p),q(q),u_max(u_max),J(J),epsilon(epsilon){};
	//���º���
	void SMC_Tick(float angle_now,float angle_vel);
	void setC(float value) { C = value; }
	void setK(float value) { K = value; }
	void setRef(float value) { ref = value; }
	void setJ(float value) { J = value; }

	[[nodiscard]] float getC() const { return C; }
	[[nodiscard]] float getK() const { return K; }
	[[nodiscard]] float getRef() const { return ref; }

 private:
	float error;
	float error_last;
	float dref;//Ŀ��ֵһ�׵�
	float ddref;//Ŀ��ֵ���׵�
	float refl;//��һ�ε�Ŀ��ֵ

	float s;//��ģ��
	float ds;//��ģ���һ�׵�
	float C;
	float K;
	float ref; //��ʼĿ��ֵ
	float error_eps;//�������
	uint16_t p; //������
	uint16_t q; //������
	float u_max;//������ֵ
	float J;//���ƹ���
	float angle; //�Ƕȷ�������
	float ang_vel;//���ٶȷ�������/s
	float epsilon;
	// ���ͺ���
	float Sat(float y)
	{
		if (fabs(y) <= 1)
			return y;
		else
			return Signal(y);
	}
	// ���ź���,���ж������Ի������͵ı��ͺ���
	int8_t Signal(float y)
	{
		if (y > 0)
			return 1;
		else if (y == 0)
			return 0;
		else
			return -1;
	}
};
//extern SMC YawSMC;
#endif

#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//3. ö��
//ö�ٹ���˼�����һһ�о١�
//�ѿ��ܵ�ȡֵһһ�о�

//3.1 ö�����͵Ķ���
//enum Day//����
//{
//	Mon,
//	Tues,
//	Wed,
//	Thur,
//	Fri,
//	Sat,
//	Sun
//};
//enum Sex//�Ա�
//{
//	//����ֵ
//	MALE = 1,
//	FEMALE = 2,
//	SECRET //3
//};
//enum Color//��ɫ
//{
//	RED,
//	GREEN,
//	BLUE
//};
//int main()
//{
//	enum Sex s = MALE;
//	enum Color c = BLUE;
//	//enum Color c1 = 2;//error //int����
//	printf("%d %d %d\n",RED,GREEN,BLUE);//0 1 2
//	printf("%d %d %d\n", MALE, FEMALE, SECRET);//1 2 3
//	return 0;
//}
////c���Ե�Դ����  ---- Ԥ����  ---- ���� ---- ���� ---- ��ִ�г���
//#define RED 0
//#define GREEN 1
//#define BLUE 2
/*
ö�ٵ��ŵ㣺
1. ���Ӵ���Ŀɶ��ԺͿ�ά����
2. ��#define����ı�ʶ���Ƚ�ö�������ͼ�飬�����Ͻ���
3.��ֹ��������Ⱦ����װ��
4. ���ڵ���
5. ʹ�÷��㣬һ�ο��Զ���������
*/


//4. ���ϣ������壩
//4.1 �������͵Ķ���

//�������͵�����
//���� --- ������ --- ������
union Un
{
	char c;//1�ֽ�
	int i;//4�ֽ�
};

//int main()
//{
//	union Un u;
//	printf("%d\n", sizeof(u));//4�ֽ�
//
//	printf("%p\n", &u);	   //000000718B10F864
//	printf("%p\n", &(u.c));//000000718B10F864
//	printf("%p\n", &(u.i));//000000718B10F864
//
//	u.i = 0x11223344;
//	u.c = 0x55;
//	printf("%x\n", u.i);//11223355
//	printf("%x\n", u.c);//55
//
//	return 0;
//}

//4.2 ���ϵ��ص�
/*���ϵĳ�Ա�ǹ���ͬһ���ڴ�ռ�ģ�����һ�����ϱ����Ĵ�С��
����������Ա�Ĵ�С����Ϊ�������ٵ����������������Ǹ���Ա��*/


//�����⣺
//�жϵ�ǰ������Ĵ�С�˴洢
//int a = 0x11 22 33 44;
//�͵�ַ-----------------�ߵ�ַ
//11 22 33 44 ------- ����ֽ���洢ģʽ
//44 33 22 11 ------- С���ֽ���洢ģʽ
// ����ʵ�ִ�С��
//int check_sys()
//{
//	int a = 1;
//	//����1��С��
//	//����0�����
//	return *(char*)&a;
//}
//��������������ж�
//int check_sys()
//{
//	union //Un  //����//��һ���Ժ���ʹ��
//	{
//		char c;
//		int i;
//	}u;
//	u.i = 1;
//	return u.c;
//}
//int main()
//{
//	int a = 1;
//	int ret = check_sys();
//
//	if (1 == ret)
//	{
//		printf("С��\n");
//	}
//	else
//	{
//		printf("���\n");
//	}
//	return 0;
//}


//4.3 ���ϴ�С�ļ���
//���ϵĴ�С����������Ա�Ĵ�С��
//������Ա��С����������������������ʱ�򣬾�Ҫ���뵽����������������
union Un1
{
	char c[5];
	int i;
};
union Un2
{
	short c[7];
	int i;
};
int main()
{
	printf("%d\n", sizeof(union Un1));//8�ֽ�
	printf("%d\n", sizeof(union Un2));//16�ֽ�
	return 0;
}
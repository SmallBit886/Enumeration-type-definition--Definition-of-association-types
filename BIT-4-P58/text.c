#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//3. 枚举
//枚举顾名思义就是一一列举。
//把可能的取值一一列举

//3.1 枚举类型的定义
//enum Day//日期
//{
//	Mon,
//	Tues,
//	Wed,
//	Thur,
//	Fri,
//	Sat,
//	Sun
//};
//enum Sex//性别
//{
//	//赋初值
//	MALE = 1,
//	FEMALE = 2,
//	SECRET //3
//};
//enum Color//颜色
//{
//	RED,
//	GREEN,
//	BLUE
//};
//int main()
//{
//	enum Sex s = MALE;
//	enum Color c = BLUE;
//	//enum Color c1 = 2;//error //int类型
//	printf("%d %d %d\n",RED,GREEN,BLUE);//0 1 2
//	printf("%d %d %d\n", MALE, FEMALE, SECRET);//1 2 3
//	return 0;
//}
////c语言的源代码  ---- 预编译  ---- 编译 ---- 链接 ---- 可执行程序
//#define RED 0
//#define GREEN 1
//#define BLUE 2
/*
枚举的优点：
1. 增加代码的可读性和可维护性
2. 和#define定义的标识符比较枚举有类型检查，更加严谨。
3.防止了命名污染（封装）
4. 便于调试
5. 使用方便，一次可以定义多个常量
*/


//4. 联合（共用体）
//4.1 联合类型的定义

//联合类型的声明
//联合 --- 联合体 --- 共用体
union Un
{
	char c;//1字节
	int i;//4字节
};

//int main()
//{
//	union Un u;
//	printf("%d\n", sizeof(u));//4字节
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

//4.2 联合的特点
/*联合的成员是共用同一块内存空间的，这样一个联合变量的大小，
至少是最大成员的大小（因为联合至少得有能力保存最大的那个成员）*/


//面试题：
//判断当前计算机的大小端存储
//int a = 0x11 22 33 44;
//低地址-----------------高地址
//11 22 33 44 ------- 大端字节序存储模式
//44 33 22 11 ------- 小端字节序存储模式
// 函数实现大小端
//int check_sys()
//{
//	int a = 1;
//	//返回1，小端
//	//返回0，大端
//	return *(char*)&a;
//}
//利用联合体进行判断
//int check_sys()
//{
//	union //Un  //匿名//用一次以后不再使用
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
//		printf("小端\n");
//	}
//	else
//	{
//		printf("大端\n");
//	}
//	return 0;
//}


//4.3 联合大小的计算
//联合的大小至少是最大成员的大小。
//当最大成员大小不是最大对齐数的整数倍的时候，就要对齐到最大对齐数的整数倍
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
	printf("%d\n", sizeof(union Un1));//8字节
	printf("%d\n", sizeof(union Un2));//16字节
	return 0;
}
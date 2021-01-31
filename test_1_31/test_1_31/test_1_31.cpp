#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>

struct Stu
{
	char name[10];
	int age;
};

void Swap(char* buf1, char* buf2,int width)
{
	int i = 0;
	for (i = 0; i < width; i++)
	{
		char temp = *buf1;
		*buf1 = *buf2;
		*buf2 = temp;
		buf1++;
		buf2++;
	}
}
void bubble_sort(void* base, int sz, int width,int (*cmp)(const void*e1,const void*e2))
{
	int i = 0;
	//趟数
	for (i = 0; i < sz - 1; i++)
	{
		//每一趟比较的次数
		int j = 0;
		for (j = 0; j < sz - 1 - i; j++)
		{
			//两个元素的比较
			if (cmp((char*)base + j * width, (char*)base + (j + 1) * width) > 0)//width代表每个元素的大小，即可对地址进行算术运算
			{
				//交换
				Swap((char*)base + j * width, (char*)base + (j + 1) * width, width);
			}

		}
	}
}
int cmp_int(const void* e1, const void* e2)//bubble_sort函数第4个参数是比较函数的地址，要根据自己比较的类型自定义
{
	return *(int*)e1 - *(int*)e2;
}
void test1()
{
	int arr[10] = { 9,8,7,6,5,4,3,2,1,0 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	bubble_sort(arr, sz, sizeof(arr[0]),cmp_int);
}

int cmp_by_age(const void* e1, const void* e2)
{
	return ((struct Stu*)e1)->age - ((struct Stu*)e2)->age;
}

int cmp_by_name(const void* e1 , const void* e2)
{
	return strcmp(((struct Stu*)e1)->name, ((struct Stu*)e2)->name);
}
void test2()
{
	struct Stu s[3] = { {"zhangsan",20},{"lisi",30},{"wangwu",10} };
	int sz = sizeof(s) / sizeof(s[0]);
	bubble_sort(s, sz, sizeof(s[0]),cmp_by_name);
}
int main(void)
{
	//test1();
	test2();
	return 0;
}
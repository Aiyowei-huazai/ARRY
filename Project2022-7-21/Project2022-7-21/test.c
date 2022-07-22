//////#include<stdio.h>
//////
//////
//////int main()
//////{
//////	int b[] = {1,2,3,4,5};
//////	int* p = b;
//////	int s = *p++;
//////
//////	printf("%d\n", s);
//////	printf("%d", *p);
//////	return 0;
//////}
////
////#include<stdio.h>
////
////void test(int arr[], int sz)
////{
////	for (int i = 0; i < sz - 1; i++)
////	{
////		for (int j = 0; j < sz - 1 - i; j++)
////		{
////			if (arr[j] > arr[j + 1])
////			{
////				int tem = arr[j];
////				arr[j] = arr[j + 1];
////				arr[j + 1] = tem;
////			}
////		}
////	}
////}
////
////int main()
////{
////	//实现冒泡排序
////	int arr[] = { 9,8,6,4,5,7,1,2,3 };
////	int sz = sizeof(arr) / sizeof(arr[0]);
////	test(arr, sz);
////
////	for (int i = 0; i < sz ; i++)
////	{
////		printf("%d", arr[i]);
////	}
////
////
////	return 0;
////}
//
//
//
//回调函数实现qsort
#include<stdio.h>
#include<stdlib.h>

int arr_int(const void* el, const void* e2)
{
	return    *((int*)el) - *((int*)e2);
}


void my_swap(char* str1, char* str2, int l)
{
	for (int i = 0; i < l; i++)
	{
		char tem = *str1;
		*str1 = *str2;
		*str2 = tem;
		str1++;
		str2++;
	}
}


void my_sort(void* dase, int sz, int width, int (*p)(const void* e1, const void* e2))
{
	for (int i = 0; i < sz - 1; i++)
	{
		for (int j = 0; j < sz - 1 - i; j++)
		{
			if (p((char*)dase + j * width, (char*)dase + (j + 1) * width) > 0)
			{
				my_swap((char*)dase + j * width, (char*)dase + (j + 1) * width, width);
			}
		}
	}

	

}

int main()
{
	int arr[] = { 9,7,8,6,5,4,3,2,1 };
	int sz = sizeof(arr) / sizeof(arr[0]);

	my_sort(arr, sz, sizeof(arr[0]), arr_int);
	//qsort(arr, sz, sizeof(arr[0]), arr_int);

	for (int i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}

//
//
//#include<stdio.h>
//
//void test3()
//{
//	printf("test3,回调函数");
//}
//
//void test1(void (*p)())
//{
//	printf("test1\n");
//	p();
//}
//
//void test()
//{
//
//	printf("test()\n");
//	test1(test3);
//
//
//}
//
//
//
//int main()
//{
//
//	test();
//
//	return 0;
//}
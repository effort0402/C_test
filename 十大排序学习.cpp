#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;

//冒泡排序
void bubble_sort(int* a,int la) 
{
	for (int i = 0; i < la; i++) 
	{
		for (int j = 0; j < la - i - 1; j++) 
		{
			if (a[j] > a[j + 1]) 
			{
				int t = a[j];
				a[j] = a[j+1];
				a[j+1] = t;
			}
		}
	}

}

//快排
int quick(int* a,int left,int right) 
{
	int n = a[left];
	while (left < right) 
	{
		while (left < right && a[right] >= n) 
		{
			--right;
		}
		a[left] = a[right];
		while (left<right && a[left]<=n) 
		{
			++left;
		}
		a[right] = a[left];
	}
	a[left] = n;
	return left;
}
void quick_sort(int *a,int left,int right) 
{
	if (left < right) 
	{
		int n = quick(a,left,right);
		quick_sort(a,left,n-1);
		quick_sort(a,n+1,right);
	}
}

//简单插入排序
void insert_sort(int* a, int la) 
{
	for(int i = 0;i<la-1;i++)
	{
		int n = a[i+1];
		int p = i;
		while (p >= 0 && n < a[p])
		{
			a[p+1] = a[p];
			p--;
		}
		a[p + 1] = n;
	}

}

//简单选择排序
void selection_sort(int a[],int l) 
{
	for (int i = 0; i < l; i++) 
	{
		int mini = i;
		for (int j = i + 1; j < l; j++) 
		{
			if (a[mini] > a[j]) 
			{
				mini = j;
				
			}
		}
		int t = a[i];
		a[i] = a[mini];
		a[mini] = t;
		
	}

}


//希尔排序，按组依次排
void shell_sort(int *a, int l) 
{
	int i, j, k, d,la = l ,t;
	for (d = la / 2; d >= 1; d /= 2) 
	{
		for (i = 0; i < d; i++) 
		{
			for (j = i + d; j < la; j+=d) 
			{
				t = a[j];
				k = j - d;
				while (k >= 0 && a[k] > t) 
				{
					a[k + d] = a[k];
					k = k - d;
				}
				a[k + d] = t;
			}
		}
	}
	//for (int i = 0; i < l;i++)cout << a[i] << " ";
	//cout << endl;

	cout << sizeof(a) << endl;
}


//归并排序  分治+递归 先将元素 递归 对半分成一个一个的个体，再进行 有序的 递归 合并
void merge(int a[], int temparr[], int left, int mid, int right) 
{
	//标记左右半区未排序的元素
	int l_pos = left;
	int r_pos = mid+1;

	//标记临时下标
	int pos = left;

	//进行比较左右半区，放入temparr[]数组中
	while (l_pos <= mid && r_pos <= right) 
	{
		if (a[l_pos] < a[r_pos])
		{
			temparr[pos++] = a[l_pos++];
		}
		else
			temparr[pos++] = a[r_pos++];
	}

	//将剩余元素放入temparr
	while (l_pos <= mid) 
	{
		temparr[pos++] = a[l_pos++];
	}

	while (r_pos <= right)
	{
		temparr[pos++] = a[r_pos++];
	}

	//将排好序合并的数组放到原数组中，这步很关键
	for (int i = left; i <= right; i++)
	{
		a[i] = temparr[i];
	}

}

void msort(int a[],int temparr[],int left,int right) 
{
	if (left < right) 
	{
		//找中间点
		int mid = (left + right) / 2;
		//递归划分左右区域
		msort(a,temparr,left,mid);
		msort(a,temparr,mid+1,right);
		//合并左右半区
		merge(a,temparr,left,mid,right);
		

	}
}

void merge_sort(int a[],int la) //归并入口
{	
	int* temparr = (int*)malloc(sizeof(int)*(la+1));

	if (temparr)
	{
		msort(a, temparr, 0, la-1);

		//要在合并排序完的时候就放到原数组中，不然部分有序的部分会重新排序，将会打乱临时数组中的值
		/*for (int i = 0; i < la; i++)
			cout << temparr[i] << " ";*/

		cout << endl;
		
		free( temparr);
	}
	else
	{
		printf("temparr allocate error");
	}


}


//


int main() 
{
	int arr[] = {123,5,31,546,1231,5,4,2,3,4,6,8,9};
	int la = sizeof(arr) / sizeof(arr[0]);

	for (auto i : arr)cout << i << " ";
	cout << endl;

	//bubble_sort(arr,la);
	//quick_sort(arr,0,la-1);
	//insert_sort(arr,la);
	//shell_sort(arr,la);
	//selection_sort(arr,la);
	//merge_sort(arr,la);

	for (auto i : arr)cout << i << " ";
	cout << endl;

	//char a[4] = {0};
	//for (auto i : a)cout << (int)i << " ";
	//cout << endl;

	//strcpy_s();

	//printf(" ");
	
		//unsigned short y = 0xFFFF;
		//cout << hex << y << endl;
		//y = ~y;   // Take one's complement
		//cout << hex << y << endl;
	



	return 0;
}	

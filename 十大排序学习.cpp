#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;

//ð������
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

//����
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

//�򵥲�������
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

//��ѡ������
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


//ϣ�����򣬰���������
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


//�鲢����  ����+�ݹ� �Ƚ�Ԫ�� �ݹ� �԰�ֳ�һ��һ���ĸ��壬�ٽ��� ����� �ݹ� �ϲ�
void merge(int a[], int temparr[], int left, int mid, int right) 
{
	//������Ұ���δ�����Ԫ��
	int l_pos = left;
	int r_pos = mid+1;

	//�����ʱ�±�
	int pos = left;

	//���бȽ����Ұ���������temparr[]������
	while (l_pos <= mid && r_pos <= right) 
	{
		if (a[l_pos] < a[r_pos])
		{
			temparr[pos++] = a[l_pos++];
		}
		else
			temparr[pos++] = a[r_pos++];
	}

	//��ʣ��Ԫ�ط���temparr
	while (l_pos <= mid) 
	{
		temparr[pos++] = a[l_pos++];
	}

	while (r_pos <= right)
	{
		temparr[pos++] = a[r_pos++];
	}

	//���ź���ϲ�������ŵ�ԭ�����У��ⲽ�ܹؼ�
	for (int i = left; i <= right; i++)
	{
		a[i] = temparr[i];
	}

}

void msort(int a[],int temparr[],int left,int right) 
{
	if (left < right) 
	{
		//���м��
		int mid = (left + right) / 2;
		//�ݹ黮����������
		msort(a,temparr,left,mid);
		msort(a,temparr,mid+1,right);
		//�ϲ����Ұ���
		merge(a,temparr,left,mid,right);
		

	}
}

void merge_sort(int a[],int la) //�鲢���
{	
	int* temparr = (int*)malloc(sizeof(int)*(la+1));

	if (temparr)
	{
		msort(a, temparr, 0, la-1);

		//Ҫ�ںϲ��������ʱ��ͷŵ�ԭ�����У���Ȼ��������Ĳ��ֻ��������򣬽��������ʱ�����е�ֵ
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

#include<iostream>
#include<bitset>
#include<typeinfo>
using namespace std;

template <class T,class U,class R>
R MAX_U(T a, U b) { return a > b ? a : b; }

template <class T, class U>
auto Max1(T a, U b) -> decltype( (a>b?a:b ))//�����Ƶ������ݺ������ͣ���auto��decltype     ��c++20�У�����ֱ����auto�����ú����Ƶ�
{
	return a > b ? a : b;
}


template <class T, class U>
auto Max2(T a, U b)   // ��c++20�У�����ֱ����auto�����ú����Ƶ�
{
	return (a > b ? a : b);

}

template <class T, class U>
auto Max22(T a, U b)   // ��c++20�У�����ֱ����auto�����ú����Ƶ�
{
	
	//if (a > b)return a;
	//else return b;
	//���󣬷���ֵ����һ�£����ܷ���������ͬ��
}

int main() 
{
	//����ת���ؼ���---�����ĸ� 
	const int a = 10;
	//int * p = (int * )&a;
	int* p = const_cast<int*>(&a);
	*p = 20;


	//��ֵ����ֵ������ֵ
	int && b = 20;//��ֵ���� ����������ֵ  ��ֵ���õ�Ŀ�ģ�
	// int t = 20;
	// int &b = t;
	//Max(10,20)����ȡ��ַ��Ϊ��ֵ
	//����ֵ���ڳ���ִ�й����в�������ʱ��������ִ�������ʧ �ھ�����Ϊ��ֵ��δ����Ϊ��ֵ


	const int& c = a;//��ֵ������  ��������

	const int& d = 10;//��ֵ������
	// int t = 10;
	// const int & d = t;

	int a1 = 10;

	decltype((a1)) z  = a1;//������ ������ Ϊ��������



	
	cout << Max1(1222,120.123)<<endl;
	cout << Max2('q', 12.123) << endl;
	//



	int arr[] = {1,2,3,4,5,6,7,8,9,10};
	for (int x : arr) 
	{
		cout<< x << " ";
	}

	cout<< endl;



	cout << bitset<32>(10) << endl;

	//��ϰ:������ṹ���Ա��������ƫ����

	return 0;
}
#include<iostream>
#include<bitset>
#include<typeinfo>
using namespace std;

template <class T,class U,class R>
R MAX_U(T a, U b) { return a > b ? a : b; }

template <class T, class U>
auto Max1(T a, U b) -> decltype( (a>b?a:b ))//后置推导，推演函数类型，用auto和decltype     在c++20中，可以直接用auto，不用后置推导
{
	return a > b ? a : b;
}


template <class T, class U>
auto Max2(T a, U b)   // 在c++20中，可以直接用auto，不用后置推导
{
	return (a > b ? a : b);

}

template <class T, class U>
auto Max22(T a, U b)   // 在c++20中，可以直接用auto，不用后置推导
{
	
	//if (a > b)return a;
	//else return b;
	//错误，返回值必须一致，不能返回两个不同的
}

int main() 
{
	//类型转换关键字---共有四个 
	const int a = 10;
	//int * p = (int * )&a;
	int* p = const_cast<int*>(&a);
	*p = 20;


	//左值、右值、将亡值
	int && b = 20;//右值引用 不能引用左值  右值引用的目的：
	// int t = 20;
	// int &b = t;
	//Max(10,20)不能取地址，为右值
	//将亡值，在程序执行过程中产生的临时量，函数执行完后消失 在具名后为左值，未具名为右值


	const int& c = a;//左值常引用  万能引用

	const int& d = 10;//右值常引用
	// int t = 10;
	// const int & d = t;

	int a1 = 10;

	decltype((a1)) z  = a1;//变量名 加括号 为引用类型



	
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

	//练习:不定义结构体成员，来推算偏移量

	return 0;
}
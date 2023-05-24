#include<iostream>
using namespace std;

class A 
{
public:
	virtual int get() { return 1; }
	virtual int g() { return 2; }
	
};

class B :public A 
{
public:
	virtual int get() { return 11; }
	virtual int b() { return 9; }


};

class C :public B
{
public:
	virtual int b() { return 8; }

	~C() {	//delete this;//无穷递归 }
	};





	void fun(B* b)
	{
		cout << b->g() << endl;
		cout << b->b() << endl;
		cout << b->get() << endl;

	}
};
	class Int
	{
	private:
		int* pval;
	public:
		Int(int x = 0) :pval(new int(x)) {}
		Int(const Int& it)
		{
			pval = new int(*it.pval);
		}
		Int(Int&& it) :pval(it.pval)
		{
			it.pval = nullptr;
		}
		Int& operator=(const Int& it)
		{
			if (this != &it)
			{
				delete[]pval;
				pval = new int(*it.pval);
			}
			return *this;
		}
		Int& operator=(Int&& it)
		{
			if (this != &it)
			{
				pval = it.pval;
				it.pval = nullptr;
			}
		}
		~Int()
		{
			delete pval;
			pval = nullptr;
		}
	};
	int main()
	{
		//多态满足的条件
		//1.必须公有继承
		//2.基类函数必须为虚函数，派生类重写虚函数（三同：同返回类型、同参数列表、同函数名）
		//3.必须拿引用或指针调用函数，才能体现动态性
		//通过将派生类通过 指针或引用 传给基类，来调用派生类的函数

		A a;
		B b;
		C c;


		//fun(&c);

		//虚表中的内容
		//有类型信息的指针 RTTI
		//虚函数的指针
		//同名覆盖，重写后的函数 将虚表中 原来的的函数覆盖
		//如果没有重写，又是虚函数，会将该函数添加到自己的虚表中
		//虚表的 写入规则 和 调用规则



		//C++四种转换
		char s = 'a';
		int a = static_cast<int>(s);
		//常对象只能调用常方法

		//(int&&)
		//move()


		//注意不要用 memset、delete等等 来将this指针清零，因为会把虚表指针也清零

		(*(void(*)()) 0) ();

		return 0;
	}

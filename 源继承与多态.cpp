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

	~C() {	//delete this;//����ݹ� }
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
		//��̬���������
		//1.���빫�м̳�
		//2.���ຯ������Ϊ�麯������������д�麯������ͬ��ͬ�������͡�ͬ�����б�ͬ��������
		//3.���������û�ָ����ú������������ֶ�̬��
		//ͨ����������ͨ�� ָ������� �������࣬������������ĺ���

		A a;
		B b;
		C c;


		//fun(&c);

		//����е�����
		//��������Ϣ��ָ�� RTTI
		//�麯����ָ��
		//ͬ�����ǣ���д��ĺ��� ������� ԭ���ĵĺ�������
		//���û����д�������麯�����Ὣ�ú�����ӵ��Լ��������
		//���� д����� �� ���ù���



		//C++����ת��
		char s = 'a';
		int a = static_cast<int>(s);
		//������ֻ�ܵ��ó�����

		//(int&&)
		//move()


		//ע�ⲻҪ�� memset��delete�ȵ� ����thisָ�����㣬��Ϊ������ָ��Ҳ����

		(*(void(*)()) 0) ();

		return 0;
	}

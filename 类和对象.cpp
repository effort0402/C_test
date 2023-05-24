#include<iostream>
#include<string.h>
#include<math.h>
#include<stdio.h>

#include <bitset> //��������Ƶ�ͷ�ļ�
#include<stdlib.h>

#define _CRT_SECURE_NO_WARNINGS
using namespace std;


//class A 
//{
//public:
//	int a;
//	int b;
//	string c = {"hello"};
//
//	void print();
//	void init();
//	A();
//	A(int i,int j);
//	A(int i, int j, string s);
//
//};
//
//A::A() 
//{
//	this->a = 10;
//	this->b = 11;
//	string s = {"endl"};
//	
//}
//
//
//class Complet 
//{
//private:
//	int Real;
//	int image;
//public:
//	Complet() { Real = 0; image = 0; }
//	Complet(int i,int j);
//	
//	//�б� ������˳�� ��Real ��image ������ĳ�Ա��˳�������� ����Ӧ���ȹ���Real ��image
//	//Complet(int i) :image(i), Real(image) {}//�ṹ��ʧ��
//	Complet(int i) :Real(i), image(Real) {}//�ɹ�
//
//	void print() 
//	{
//		cout << Real << " " << image<<endl;
//
//	}
//	~Complet() { cout << Real<<endl; }
//
//};
//
//Complet::Complet(int i,int j) 
//{
//	this->Real = i;
//	this->image = j;
//
//}


class Dates 
{
private:
	int year;
	int month;
	int day;
public:
	Dates() :year(1), month(1), day(1) {}
	Dates(int y,int m,int d);
	void print() const 
	{
		cout << "year:" << year << " month:" <<month<< " day:" << day << endl;
	}
};

Dates::Dates(int y, int m, int d) 
{
	int d1 = 0;
	bool leap_year = 0;
	if ((0 == y % 4 && y % 100 != 0) || (0 == y % 400))
	{
		
		leap_year = 1;
	}

	if (leap_year)
	{
		if (m == 2)d1 = 29;
	}
	else if (m == 2)d1 = 28;

	if (y < 0)
	{
		cout << "����������̫С���Ѹ���Ϊ��ֵ" << endl;
		year = -y;

	}
	else year = y;

	if (m <= 0)
	{
		cout << "�·��������̫С���Ѹ���Ϊ1��" << endl;
		m = 1;
		month = m;
	}
	else if (m > 12)
	{
		cout << "�·��������̫���Ѹ���Ϊ12��" << endl;
		m = 12;
		month = m;
	}
	else month = m;

	if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) 
	{
		if (d <= 0)
		{
			cout << "�����������̫С���Ѹ���Ϊ1��" << endl;
			d = 1;
			day = d;
		}
		if (d > 31)
		{
			cout << "�����������̫���Ѹ���Ϊ31��" << endl;
			d = 31;
			day = d;
		}
		else day = d;
	}
	else if (m == 2)
	{
		if (leap_year)
		{
			if (d <= 0)
			{
				cout << "�����������̫С���Ѹ���Ϊ1��" << endl;
				d = 1;
				day = d;
			}
			if (d > d1)
			{
				cout << "�����������̫���Ѹ���Ϊ29��" << endl;
				d = d1;
				day = d;
			}
			else
			{
				day = d;
			}
		}
		else 
		{
			if (d <= 0)
			{
				cout << "�����������̫С���Ѹ���Ϊ1��" << endl;
				d = 1;
				day = d;
			}
			if (d > 28)
			{
				cout << "�����������̫���Ѹ���Ϊ28��" << endl;
				d = 28;
				day = d;
			}
			else day = d;

		}
	}
	else 
	{
		if (d <= 0)
		{
			cout << "�����������̫С���Ѹ���Ϊ1��" << endl;
			d = 1;
			day = d;
		}
		if (d > 30)
		{
			cout << "�����������̫���Ѹ���Ϊ30��" << endl;
			d = 30;
			day = d;
		}
		else day = d;
	}
	
}


//�޷������� ת��Ϊ ip��ַ
void transform(unsigned int a)
{
	int arr[4] = {255,255,255,255};
	
	for (int i = 0; i < 4; i++)
	{
		
		arr[i] = arr[i] & (a >> ((3 - i) * 8));
		//cout << "�����ƣ� "<<i << "  " << bitset<32>(arr[i]) << endl;
		if (i < 3)
		{
			cout << arr[i] << ".";
		}
		else
		{
			cout << arr[i] << endl;
		}
	}

}



//Mystack
class Mystack 
{
	enum{STACK_INIT_SIZE=10,STACK_INC_SIZE=2};
	int* _data;
	int _size;
	int _top;
public:
	Mystack();
	Mystack(int sz);
	~Mystack();
	int Size();//Ԫ�ظ���
	bool Empty();//�п�
	void Push(int val);//��ջ
	int Top();//ȡջ��Ԫ�أ�Ԫ�ز���ջ
	void Pop();//ֻ��ջ
	int GetPop();//ȡջ��Ԫ�غͳ�ջ

};
Mystack::Mystack() 
{
	_data = new int[10];
	_size = 10;
	_top = 0;
}

Mystack::Mystack(int sz) 
{
	Push(sz);
}

Mystack::~Mystack() 
{
	if (Empty())
	{

		delete[]_data;

	}	
	_data = nullptr;
}

bool Mystack::Empty() 
{
	if (this->_top == 0)return true;
	else return false;
}

int Mystack::Size() 
{
	return _size;
}

void Mystack::Push(int val) 
{

	this->_data[_top] = val;
	_top++;
}

int Mystack::Top()
{
	if (Empty()) 
	{
		cout << "ջΪ�գ���Ԫ��" << endl;
	}
	return true;;
}

void Mystack::Pop() 
{
	this->_top -= 1;
}

int Mystack::GetPop() 
{
	return _data[--_top];
}

//Complet a1(12);

int my_atoi(string s) 
{
	cout << "��������ַ�����" << s << "    " ;

	int n = 0;
	bool k = 1;
	int o = 0, l = 0;

	int i = 0;
	while ( s[i] == ' ')
	{
		i++;
	}

	if (s[i] == '+' || s[i]=='-')
	{
		if (s[i] == '-')
		{
			k = 0;
			i++;
		}
	}
	else if (s[i] < '0' || s[i]>'9' || s[i]=='l'||s[i]=='o')
	{
		if (s[i] == 'o' || s[i] == 'l')
		{
			if (s[i ] == 'o')
			{
				s[i] = '0';
				o = 1;
				
			}
			else
			{
				s[i] = '1';
				l = 1;
				
			}

		}
		if(s[i] < '0' || s[i]>'9')return 2147483647;
	}


	if (s[i] == '0' && (s[i + 1] == 'x' || s[i + 1] == 'X')) 
	{
		i = i + 2;
		while ((s[i] <= '9' && s[i] >= '0' && s[i] != '\0') || (s[i] >= 'a' && s[i] <= 'f' && s[i] != '\0'))
		{
		
			if (s[i] <= '9' && s[i] >= '0' && s[i] != '\0')
			{
				n = n * 16 + s[i] - '0';
				i++;
			}
			if (s[i] >='a' && s[i] <= 'f' && s[i] != '\0') 
			{
				if (s[i] == 'a') 
				{
					n = n * 16 +10;
					i++;
				}
				else if (s[i] == 'b')
				{
					n = n * 16 + 11;
					i++;
				}
				else if (s[i] == 'c')
				{
					n = n * 16 + 12;
					i++;
				}
				else if (s[i] == 'd')
				{
					n = n * 16 + 13;
					i++;
				}
				else if (s[i] == 'e')
				{
					n = n * 16 + 14;
					i++;
				}
				else if (s[i] == 'f')
				{
					n = n * 16 + 15;
					i++;
				}

			}


		}

	}

	while (s[i] <= '9' && s[i] >= '0' && s[i]!='\0') 
	{
		n = n * 10 + s[i] - '0';
		if (s[i + 1] == 'o' || s[i + 1] == 'l') 
		{
			if (s[i + 1] == 'o')
			{
				s[i + 1] = '0';
				o = 1;

			}
			else 
			{ 
				s[i + 1] = '1';
				l = 1;
			}
			
		}
		i++;
	}

	if (!k)n = (-1) * n;

		if(l&&o)cout << "�����ܽ����� 1 ������ 0 ������Ϊ��ĸ l ����ĸ o ���Ѱ�������:";
		if (l && !o)cout << "�����ܽ����� 1 ������Ϊ��ĸ l ���Ѱ�������:" ;
		if (o&& !l)cout << "�����ܽ����� 0 ������Ϊ��ĸ o ���Ѱ�������:" ;
		
		if (!l && !o) cout << "ת��������Ϊ��";

	

	return n;

}






// 3/25 ѧϰ �������� ���������
//1.����ֵ ͨ��thisָ������������Ĵ�ӡ���۲�

//2.��Ĭ���ĸ����� ���캯���������������������캯�������������

const int len = 20;
class CGoods
{
private:
	char Name[len];
	int Amount;
	float Price;
	float Total_value;
public:
	CGoods()
	{
		memset(Name, 0, sizeof(Name));
		Amount = 0;
		Price = 0.0;
		Total_value = 0.0;
	}
	CGoods(const char* name, int amount, float price)
	{
		strcpy_s(Name, len, name);
		Amount = amount;
		Price = price;
		Total_value = Amount * Price;
	}

	CGoods(const CGoods&x):Amount(x.Amount),Price(x.Price),Total_value(x.Total_value)
	{
		strcpy_s(Name, len, x.Name);
		//memmove(x);
		cout << " Copy Create CGoods" << endl;
	}

	CGoods& operator = (const CGoods & x)//const CGoods this ,
	{
		Amount=x.Amount, 
		Price=x.Price, 
		Total_value=x.Total_value,
		strcpy_s(Name,len,x.Name);

	}

	void Print() const
	{
		cout << "Name: " << Name << endl;
		cout << "Amount: " << Amount << endl;
		cout << "Price : " << Price << endl;
		cout << "Total: " << Total_value << endl;
	}


};


//���������  �������캯��  �б���/��ʼ������
class CDate // ��������
{
	int year;
	int month;
	int day;
public:
	CDate() :year(1), month(1), day(1)
	{
		cout << "default create object" << endl;
	}
	CDate(int y, int m, int d) :year(y), month(m), day(d)
	{
		cout << "Create object" << endl;
	}
	~CDate()
	{
		cout << "Destroy object" << endl;
	}

	CDate(const CDate& x) :year(x.year), month(x.month), day(x.day)//�б�ʽ
	{
		//�б�ʽֻ�����ڹ��캯���Ϳ������캯�� �Գ�Ա���г�ʼ����
		//�����Ա�Ѿ����ھͲ�����ʹ���б��ٴδ�����ʼ��
		cout << "create copy CDate" << endl;
	}

	CDate &operator =(const CDate &x) 
	{
		if (this == &x)return *this;//��ֹ�����������ֵ
		year = x.year;
		month = x.month;
		day = x.day;
		return *this;
	}
	void ShowDate() const
	{
		cout << "year : " << year << " month: " << month << " day: " << day << endl;
	}
};


//����
void c(CGoods x) {} //�˷ѿռ�
void c(CGoods * x) {} //��Ҫ�п� �������nullptr��������
void c(const CGoods* x) {}//��Ҫ�п� �������nullptr�������� ���ɸı䴫���ֵ
void c(CGoods& x) {}//���� �ɸı�ֵ
void c(const CGoods& x) {}//������


//���ܽ� ���� �����û���ָ�뷵�أ���Ϊ�ڷ���ʱ �� ���� ��ջ�ռ��Ѿ������٣�����õ����ֵ
//���� ���������� ���ܺ���Ӱ�죬�ڷ���ʱ���������� ���� �� ָ��
//����ȫ�ֶ��� / �ں����ڲ�������̬��������  �����һֱ����������
//���� CDate& c(CDate& x) { return x; }  x���ܺ���c��Ӱ��
//������÷��ض��󱻸ı䣬�����ں���ǰ���� const

//ȱʡ�������캯��
//class MyString
//{
//private:
//	char* pstr;
//public:
//	MyString(const char* p)
//	{
//		if (p != nullptr)
//		{
//			int len = strlen(p) + 1;
//			pstr = new char[len];
//			strcpy_s(pstr, len, p);
//		}
//		else
//		{
//			pstr = new char[1];
//			*pstr = '\0';
//		}
//		cout << "Create MyString " << endl;
//	}
//	~MyString()
//	{
//		delete[]pstr; // free(pstr);
//		pstr = nullptr;
//		cout << "Destroy MyString " << endl;
//	}
//	MyString(const MyString & s) 
//	{
//		//���
//		if (this->pstr) 
//		{
//			delete []pstr;
//			pstr = nullptr;
//		}
//		int len = strlen(s.pstr)+1;//+1��� '\0'
//		//cout << "l:" << l << endl;
//		pstr = new char[len];
//		//*pstr = *s.pstr;
//		strcpy_s(pstr,len,s.pstr);
//		//strcpy(pstr,s.pstr); 
//
//
//		//��λ����
//		//pstr = s.pstr; //����  ��Ϊָ��һ����ַ �� s2������s1������ʱ��delete pstr�����
//		
//		
//		//memmove(pstr,s.pstr,0); //���� 
//		cout << "create copy MyString" << endl;
//	}
//
//	void Print() const
//	{
//		if (pstr != nullptr)
//		{
//			cout << "string: " << pstr << endl;
//		}
//	}
//};


//MyString temp(const char *p){}


class MyString
{
private:
	char* pstr;
	MyString(MyString s, int) 
	{

	}
public:
	
	MyString(const char* p)  // 1 2 3;
	{
		if (p != nullptr)
		{
			int len = strlen(p) + 1;
			pstr = new char[len];
			strcpy_s(pstr, len, p);
		}
		else
		{
			pstr = new char[1];
			*pstr = '\0';
		}
	}
	~MyString()
	{
		delete[]pstr; // free(pstr);
		pstr = nullptr;
	}

	void Print() const  // const MyString * const this;
	{
		if (pstr != nullptr)
		{
			cout << pstr << endl;
		}
	}
	MyString(const MyString& s) :pstr(nullptr)
	{
		if (s.pstr != nullptr)
		{
			delete []pstr;
			int len = strlen(s.pstr) + 1;
			pstr = new char[len];
			strcpy_s(pstr, len, s.pstr);
		}
		else
		{
			pstr = new char[1];
			*pstr = '\0';
		}
	}
	MyString& operator=(const MyString& s)
	{
		if (this != &s)
		{
			delete[]pstr;
			int len = strlen(s.pstr) + 1;
			pstr = new char[len];
			strcpy_s(pstr, len, s.pstr);
		}
		return *this;
	}
	MyString(MyString&& s) // move copy create;
	{
		pstr = s.pstr;
		s.pstr = nullptr;
		cout << this << " <== move Create " << &s << endl;
	}

	operator char*() const{return pstr;}

	MyString operator +(const MyString & s1)const
	{	
		//const char *s[] = pstr;
		//int l1 = strlen(s1.pstr)+1;
		//int l = strlen(this->pstr)+1;
		//int len = l + l1;

		//delete []pstr;
		//pstr = new char[l];
		//strcpy_s(this->pstr ,l , s);
		////strcat_s(pstr, s1.pstr);

		int total = strlen(pstr) + strlen(s1.pstr)+1;
		char* newdata = new char[total];
		strcpy_s(pstr,total,this->pstr);
		strcat_s(pstr, total, s1.pstr);
		return MyString(newdata);
	}

	MyString operator +(const char * s1)const
	{
		//const char *s[] = pstr;
		//int l1 = strlen(s1.pstr)+1;
		//int l = strlen(this->pstr)+1;
		//int len = l + l1;

		//delete []pstr;
		//pstr = new char[l];
		//strcpy_s(this->pstr ,l , s);
		////strcat_s(pstr, s1.pstr);

		int total = strlen(pstr) + strlen(s1) + 1;
		char* newdata = new char[total];
		strcpy_s(pstr, total, this->pstr);
		strcat_s(pstr, total, s1);

		return MyString(newdata);
	}


};

MyString fun(const char* p)
{
	MyString stmp(p);
	return stmp;
}



//��������� &����
class Int
{
	int value;
public:
	Int(int x = 0) :value(x) { cout << "Create Int Object " << this << endl; }
	Int(const Int& it) :value(it.value) { cout << "Copy Create Int Object" << this << endl; }
	Int& operator=(const Int& it)
	{
		if (this != &it)
		{
			value = it.value;
		}
		return *this;
	}
	~Int() { cout << "Destroy Int " << this << endl; }

	Int Add(const Int& x) 
	{
		
		return (this->value+x.value);
	}

	Int & operator +( const int & x)
	{
		//int c1 = ;c1
		Int c(x + this->value);
		return c;
	}

	operator int()const  //����ǿת��
	{ return value; }

	bool operator >=(const Int & x) const
	{
		//return this->value >=x.value;
		return !(*this < x);
	}
	bool operator <=(const Int& x) const
	{
		//return this->value <= x.value;
		return !(*this>x);
	}
	bool operator !=(const Int& x) const
	{
		return this->value != x.value;
	}
	bool operator >(const Int& x) const
	{
		return this->value > x.value;
	}
	bool operator <(const Int& x) const
	{
		return this->value < x.value;
	}
	Int& operator ++()//������
	{
		this->value += 1;
		return *this;
	}
	Int operator++(int )//���������õ���ʽ���� 
	{
		Int temp = *this;
		//this->value += 1;
		++*this;//�Ľ������� ���������++ ����
		return temp;
	}


	void PintInt() const { cout << value << endl; }


	//istream
	//ostream
	//iostream
	//friend ostream& operator<<(ostream& out,const Int& it) 
	ostream & operator<<(ostream& out)const
	{
		out << this->value;
		return out;
	}
};



//��Ԫ
//this������ͨ��cpu�ļ����Ĵ���ECX����ȡ�����׵�ַ
//https://blog.csdn.net/weixin_54285142/article/details/123607216?utm_medium=distribute.pc_relevant.none-task-blog-2~default~baidujs_baidulandingword~default-0-123607216-blog-123340065.235^v27^pc_relevant_3mothn_strategy_recovery&spm=1001.2101.3001.4242.1&utm_relevant_index=3
//

//��ͨ��friend��ʵ��ostream << ����
//������Ա���� << ���غ���
ostream& operator<<(ostream& out,Int & it) 
{
	it << out;
	return out;
}


//��̬��Ա  �����ڶ����Ա�����ж����� ����thisָ�����Σ���const�޶�ֻ�޶�thisָ��ָ��ĳ�Ա�����޶�static
//��̬��Ա����
class circle
{
private:
	static const char c = 'a';
	static const int p = 100;
	static double pi ;//=3011.1123��  ����ʱ����Ϊ(int\short\char\long long������const),double����
	double redius;//�뾶
public:
	circle() : redius(0)
	{
		
	}
	~circle() {}

};
double circle::pi = 3.14;

class obj 
{
private:
	//static int num;

	int value;
	//����ģʽ
	obj(int x = 0) :value(x) {}
	obj(const obj& i) = delete;//c++11���� ɾ���������캯��
	obj& operator = (const obj& i) = delete;

public:
	~obj(){}

};
//int obj::num = 0;




int main() 
{
	//A a;
	//
	//cout << a.a << endl;

	////�пռ䲻һ���ж���
	////�ж���һ���пռ�
	//
	////����һ����������
	//A();
	//A{};//���ڴ��еĴ��ڣ�Ϊ��ֵ������ֵ������������

	//cout << a.a << endl;

	//Complet a2(10);

////	//�ж�����
		//int y, m, d;
		//while (1) {
		//	cin >> y >> m >> d;
		//	//Dates t;
		//	Dates t(y, m, d);
		//	t.print();
		//}
	

/*//////�޷������� ip ��ַ ת��Ϊ int
	//unsigned int a = 128 << 24 | 168<< 16 | 1 << 8 | 1;
	//cout << a << endl;
	//int a1 = 12 << 8;
	//cout << bitset<16>(a1) << endl;
	//int arr[4] = { 255,255,255,255 };
	//cout << "�����ƣ� "  << sizeof(a) <<" "<< bitset<32>(a) << " " << endl;

	//for (int i = 0; i < 4; i++) 
	//{
	//	arr[i] = arr[i] & (a>>((3-i)*8));
	//	//cout << "�����ƣ� "<<i << "  " << bitset<32>(arr[i]) << endl;
	//	if (i < 3)
	//	{
	//		cout << arr[i] << ".";
	//	}
	//	else 
	//	{
	//		cout << arr[i] << endl;
	//	}
	//}

	////cout << "�˽��ƣ� " << oct << a << endl;
	////cout << "ʮ���ƣ� " << dec << a << endl;
	////cout << "ʮ�����ƣ� " << hex << a << endl;
	////cout << "�����ƣ� " << bitset<sizeof(a) * 8>(a) << endl;

	//transform(a);*/



/*/////ջ��ʵ��
	//Mystack stack{};
	//int a=stack.Size();
	//
	//for (int i= 0; i < a; i++) 
	//{
	//	stack.Push(i);
	//}

	//for (int i = 0; i < a; i++)
	//{
	//	cout << stack.GetPop() << " ";
	//}
	//cout << endl;*/


//////my_atoi()��ʵ��
//cout<<my_atoi("      -132456") << endl;
//cout << my_atoi("      13l50624") << endl;
//cout << my_atoi("      1315o624") << endl;
//cout << my_atoi("      ll315o6") << endl;
//cout << my_atoi("      0x1234af") << endl;



//int sum = 0;
		//int f = 0, j = 0, yuan = 0;
		//for(yuan = 0; yuan <= 500; yuan+=100) 
		//{
		//	for (j = 0; j <= 500; j += 10) 
		//	{
		//		for (f = 0; f <=500; f += 1) 
		//		{
		//			if (yuan + f + j == 500) 
		//			{
		//				sum++;
		//				cout <<"��"<<sum<<"�֣�" << " Ԫ:" << yuan/100 << " ��:" << j/10 << " ��:" << f << endl;
		//			}
		//		}
	    //
		//	}
		//}



//�������캯��
//	CGoods c1("C++", 12, 98.99);
//	c1.Print();
//	CGoods c2(c1);
//	c2.Print();
//
//
////
//	MyString s1("yhpinghello");
//	s1.Print();
//	MyString s2(s1);
//	s2.Print();
//	//s2(s1);
//	s2.Print();


	Int a(10), b(20), c;

	int x = 10;
	c = a.Add(b);

	c.PintInt();
	c = a + x;
	c.PintInt();

	a++;
	a=a+1;
	a.PintInt();

	return 0;
}
//Complet a3(11);




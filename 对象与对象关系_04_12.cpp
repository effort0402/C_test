#include<istream>
#include<ostream>
#include<iostream>
#include<cstring>
#include<string>
#include<cstdlib>
#include<cassert>
#include<vector>
#include<stdio.h>
#include<fstream>

using namespace std;


//0412
//1.������ϵ(Dependency)
//������Ϊ��������
class book
{
private:

};
class notbook
{

};
class deskbook
{
	
};
class student
{
public:
	//1.������ϵ(Dependency)
    //��������  ˫������
	//����ʱ��
	//1.����(һ��Ҫʵ�����)		
	//2.ָ��(һ��Ҫ�п�)	 
	//3.ֵ
	void learn(book& book){}
	void learn(notbook* notbook) {}
	void learn(deskbook deskbook) {}

	//2.������ϵ


};


//2.������ϵ
class student1
{
private:
	//���Ϊ ָ�� �� ֵ �����岻ͬ
	book* book1;//�ڽ���ĳ���ʱ�������ڴ˶���
	book book2;//�ö���Ϊ�������ɲ���
	book& book3;

	//������ book * book1��
	//book1���Ըı�����Ķ���
	
	//ǿ���� book & book3��
	//ͨ���������һ�������Ķ�������˰󶨣��������ģ�Ҳ��İ󶨵Ķ���

public:
	//2.������ϵ
	//ǿ���� book & book3��
	student1(book& bk) :book3(bk) {}
	

	// ������캯���Դ�ֵ�ķ�ʽ 
	// ��Ϊ���βΣ�����bk ԭ�����޹� 
	// �ǹ��캯��������ʱ�Ŵ�����һ����ַ�����ջ�����
	// �ᱨ�� 
	//student1(book bk) :book3(bk) {}
	
	


};

//�б��ʼ�� 



//0415
class Course
{
private:
	const string c_name;
	int c_ref;


};

class Teacher
{
private:
	vector<int> course_name;

};


//�ۺϹ�ϵ
//template<class T>

class Point
{
private:
	float x, y;
public:
	Point(float x1 = 0, float y1= 0):x(x1),y(y1)
	{
		cout << "Point �Ѿ�����" << this<<endl;
	}
	
	~Point()
	{
		cout << "Point �Ѿ�����" << this << endl;
	}
};

class Radius
{
private:
	float len;
public:
	Radius() :len() {}
	Radius(float l):len(l)
	{
		cout << "Radius �Ѿ�����" << this << endl;
	}
	Radius(Radius &l) 
	{
		len = l.len;
		cout << "Radius Copy����" << this << endl;
	}
	~Radius()
	{
		cout << "Radius �Ѿ�����" << this << endl;
	}
};

class Cricle
{
private:
	Point point;
	Radius r;
	//int radius;
public:
	Cricle(): point(0,0),r(0) //radius(0)
	{

	}
	Cricle(Point p,Radius l):point(p),r(l)   //radius(0)
	{
		cout << endl;
		cout << "point p :" << &p << endl;
		cout << "radius l :" << &l << endl;
		cout << "Create Copy Cricle" <<this<< endl;
	}
	~Cricle()
	{
		cout << "���� Cricle" <<this<< endl;
	}
};


//��Ϲ�ϵ

//�ļ�����
//������
class Encryptor
{
public:
	string Encrypt(const string& plantext)
	{
		//ֻ���ַ����� 
		string es;
		for (char x : plantext)
		{
			char c = x;
			if (c<=122 && c >= 97)//isalpha(c) 
			{
				c = c - 'a';
				c = (c + 5) % 26 + 'a';
				
			}
			es += c;
		}
		//cout << es << endl;
		return es;
	}
	string Decrypt(const string& plantext)
	{
		string es;
		for (char x : plantext)
		{
			char c = x;
			if (c <= 122 && c >= 97)//isalpha(c) && c >= 0
			{
				c = (c -'a'+21)% 26 + 'a';
			}
			es += c;
		}
		cout << es << endl;
		return es;
	}
};

//���ļ�
class Read
{
public:
	string read(const string & s)
	{
		cout << "���ļ���" << endl;
		string str;
		char c;
		ifstream file;
		file.open(s);
		while (!file.is_open()) 
		{
			cout << "��ʧ�ܣ�" << endl;
			return str;
		}
		while (!file.eof()) 
		{
			file.get(c);
			str.push_back(c);
		}
		cout << str << endl;
		file.close();
		return str;

	}
};

//д�ļ�
class WriteFile
{
public:
	void Write(const string& filename, const string& ciphertext)
	{
		cout << "���� д�ļ�" << endl;
		ofstream ofile;
		ofile.open(filename);
		if (!ofile.is_open())
		{
			cout << "ʧ��!" << endl;
			return;
		}

		for (auto& x : ciphertext)
		{
			ofile.put(x);
		}
		ofile.close();
	}
};



//���ļ�
class Readfile
{
public:
	string Read(const string & filename)
	{
		cout << "���ļ�"<<endl;
		//FILE* fp = nullptr;
		string src;
		char ch;
		ifstream ifile;//���ļ��ж�ȡ����
		ifile.open(filename);
		if (!ifile.is_open()) 
		{
			cout << "��ʧ�ܣ�" << endl;
			return src;//����һ�����ַ���
		}
		while(!ifile.eof())
		{
			ifile.get(ch);
			src.push_back(ch);
		}
		src.pop_back();

		WriteFile w;

		cout << src << endl;

		Encryptor e;
		cout << "���ģ�"<<endl;
		src = e.Encrypt(src);
		cout << src << endl;

		w.Write("text2.txt",src);

		cout <<"���ܣ�" << endl;
		src = e.Decrypt(src);
		w.Write("text2.txt", src);
		cout << src << endl;

		ifile.close();
		return src;
	}
};
//��ҵ
//ʵ��ʱ�����


//0417 ��ģ�� ������������ 
//1.�ڱ���ʱʵ�֣���������õĺ������в��ֱ������� ʹ���ຯ�������� ��ģ��������ӹ��̡�
//2.������д��ģ�庯��ʱ��ÿһ����Ҫ������ģ�壬��Ա������ģ�����Ҫ����ģ��һ��
//3.class �����滻Ϊ typename
//4.���������� �� �滻����(����滻) ������
//5.��ģ�� �ڵĲ���������ģ�����(����������)��������ģ�����(���к��滻)�����߶�Ҫ�ڱ���ʱȷ��
//6.��ʼ���б� ��Ҫע�����Ա˳�� https://blog.csdn.net/wyywatdl/article/details/4688053

template<class _Ty>
class SeqStack
{
	_Ty* base;
	int top;
	int maxsize;
public:
	SeqStack(int sz = 100) :base(nullptr), top(-1), maxsize(sz)
	{
		base = (_Ty*)malloc(sizeof(_Ty)*maxsize);// new _Ty[maxsize];  //
	}
	~SeqStack()
	{
		delete[] base;
	}
	size_t GetSize() const { return top + 1; }
	bool IsEmpty() const { return GetSize() == 0; }
	bool IsFull() const { return GetSize() == maxsize; }
	bool Push(const _Ty & val) 
	{
		if(IsFull())
		{
			return false;
		}

		//base[++top]._Ty(val);

		//���Ѿ����ٵ������ռ��ڷ���ֵ  ֱ�Ӹ�ֵbase[++top] = val;����
		//��λnew ��new�����ڴ�ָ���Ŀռ������������벻ͬ���͵�ֵ(��СҪ���ܳ���)
		new(&base[++top])_Ty(val);//�����������츳ֵ _Ty(_Ty val)
		//ֱ�Ӹ�ֵbase[++top] = val;���У�
		//1.��Ϊ����� ���������=���������Ϊ�麯�������������=ֻ�ܸ�ֵ���ܽ��麯������и�ֵ���ʳ�������������������������
		//2.ʹ�ö�λnew�������Ŀ������죬����Ҳ�ṹ�����ָ��
		////������Ҫ�Ѷ���ֵ���ռ䣬�����麯��ʱ���Ὣ���ָ�븳ֵ


		//�����С���ܶ�̬ ��Ϊ�����������������ʱ���Ѿ�ȷ��
		//��������ʱ �Ƕ�̬��
	}

	bool GetTop(_Ty& val)
	{
		if (IsEmpty())
		{
			return false;
		}
		val = base[top];
		return true;
	}

	bool  Pop()
	{
		if (IsEmpty()) return false;
		&base[top]->~_Ty();//��������������������������һ��Ҫ��
		//base[top].~_Ty();
		top -= 1;
		return true;
	}
	void Clear()
	{

		for (int i = top; i >= 0; --i)
		{
			&base[i]->~_Ty();
		}
		top = -1;
	}


};

//int main()
//{
//	SeqStack<int> ist;
//	SeqStack<MyString> sit;
//
//}


//��װ���̳к���������̬

//����ָ�� char a[]={"afasdf"}  char b[20];  b=a  b++;

//���м̳� �� ��һ��   
//���磺 class student:public person{}  //student ��һ�� person

//˽�м̳� �� ��ʲô��ɣ���Ϲ�ϵ   �ֻ�����Ļ������ͷ���

//�ȴ�������  ����Ϊ���������󣬽������������������Ļ���  
//����ʱ������student  �������������������person  
//person��������ֵ
class Person
{
private:
	//sizeof(string)=28
	std::string  m_idperson;
	std::string m_name;
	std::string m_sex;
	int m_age;
public:
	Person() :m_age(0) { cout << "Create Person : " << this << endl; }
	Person(const string& id, const string& name, const string& sex, int age)
		:m_idperson(id), m_name(name), m_sex(sex), m_age(age)
	{
		cout << "Create Person " << this << endl;
	}
	~Person() { cout << "Destroy Person " << this << endl; }
	void PrintPersonInfo() const
	{
		cout << "���֤��: " << m_idperson << '\t';
		cout << "����: " << m_name << "\t";
		cout << "�Ա�: " << m_sex << "\t";
		cout << "����: " << m_age << endl;
	}
	void Dance() const
	{
		cout << "����" << endl;
	}

};

class Student : public Person // ��һ��
{
private:
	std::string m_snum;
	float m_score;
public:
	Student() { cout << "Create Student " << this << endl; }
	~Student() { cout << "Destroy Stduent " << this << endl; }
};





int main()
{
	////0412
	//student s;
	//book book;
	//notbook nc;
	//deskbook dc;

	//int b=0, c=0;
	//int& a = b;
	//a = c;

	////0415
	//Point p(10,10);
	//Radius r(5);
	//Cricle c1(p,r);
	////sizeof(c1);

	//Readfile fp;
	//string s1;
	//fp.Read("text31.txt");

	////��װ���̳к���������̬

	cout << sizeof(string) << endl;
	Student stud;
	return 0;

}
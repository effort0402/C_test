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
//1.依赖关系(Dependency)
//对象作为参数传入
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
	//1.依赖关系(Dependency)
    //单向依赖  双向依赖
	//传递时：
	//1.引用(一定要实体存在)		
	//2.指针(一定要判空)	 
	//3.值
	void learn(book& book){}
	void learn(notbook* notbook) {}
	void learn(deskbook deskbook) {}

	//2.关联关系


};


//2.关联关系
class student1
{
private:
	//设计为 指针 和 值 的意义不同
	book* book1;//在进行某个活动时，依赖于此对象
	book book2;//该对象为本类的组成部分
	book& book3;

	//弱关联 book * book1；
	//book1可以改变关联的对象
	
	//强关联 book & book3；
	//通过引用与第一个关联的对象进行了绑定，若果更改，也会改绑定的对象

public:
	//2.关联关系
	//强关联 book & book3；
	student1(book& bk) :book3(bk) {}
	

	// 如果构造函数以传值的方式 
	// 因为是形参，故与bk 原来的无关 
	// 是构造函数在运行时才创建的一个地址，最终会消亡
	// 会报错 
	//student1(book bk) :book3(bk) {}
	
	


};

//列表初始化 



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


//聚合关系
//template<class T>

class Point
{
private:
	float x, y;
public:
	Point(float x1 = 0, float y1= 0):x(x1),y(y1)
	{
		cout << "Point 已经构造" << this<<endl;
	}
	
	~Point()
	{
		cout << "Point 已经析构" << this << endl;
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
		cout << "Radius 已经构造" << this << endl;
	}
	Radius(Radius &l) 
	{
		len = l.len;
		cout << "Radius Copy构造" << this << endl;
	}
	~Radius()
	{
		cout << "Radius 已经析构" << this << endl;
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
		cout << "析构 Cricle" <<this<< endl;
	}
};


//组合关系

//文件加密
//加密器
class Encryptor
{
public:
	string Encrypt(const string& plantext)
	{
		//只对字符加密 
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

//读文件
class Read
{
public:
	string read(const string & s)
	{
		cout << "读文件：" << endl;
		string str;
		char c;
		ifstream file;
		file.open(s);
		while (!file.is_open()) 
		{
			cout << "打开失败！" << endl;
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

//写文件
class WriteFile
{
public:
	void Write(const string& filename, const string& ciphertext)
	{
		cout << "保存 写文件" << endl;
		ofstream ofile;
		ofile.open(filename);
		if (!ofile.is_open())
		{
			cout << "失败!" << endl;
			return;
		}

		for (auto& x : ciphertext)
		{
			ofile.put(x);
		}
		ofile.close();
	}
};



//读文件
class Readfile
{
public:
	string Read(const string & filename)
	{
		cout << "读文件"<<endl;
		//FILE* fp = nullptr;
		string src;
		char ch;
		ifstream ifile;//从文件中读取数据
		ifile.open(filename);
		if (!ifile.is_open()) 
		{
			cout << "打开失败！" << endl;
			return src;//返回一个空字符串
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
		cout << "密文："<<endl;
		src = e.Encrypt(src);
		cout << src << endl;

		w.Write("text2.txt",src);

		cout <<"解密：" << endl;
		src = e.Decrypt(src);
		w.Write("text2.txt", src);
		cout << src << endl;

		ifile.close();
		return src;
	}
};
//作业
//实现时间戳类


//0417 类模板 （重命名规则） 
//1.在编译时实现，如果不调用的函数，有部分编译器会 使这类函数不参与 类模板编译链接过程。
//2.在类外写类模板函数时，每一个都要给上类模板，成员函数类模板参数要与类模板一致
//3.class 可以替换为 typename
//4.重命名规则 与 替换规则(宏的替换) 的区别
//5.类模板 内的参数：类型模板参数(进行重命名)、非类型模板参数(进行宏替换)，两者都要在编译时确定
//6.初始化列表 需要注意类成员顺序 https://blog.csdn.net/wyywatdl/article/details/4688053

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

		//在已经开辟的连续空间内放入值  直接赋值base[++top] = val;不行
		//定位new 但new可以在此指定的空间来操作，放入不同类型的值(大小要不能超过)
		new(&base[++top])_Ty(val);//调动拷贝构造赋值 _Ty(_Ty val)
		//直接赋值base[++top] = val;不行，
		//1.因为会调动 运算符重载=，如果函数为虚函数，运算符重载=只能赋值不能将虚函数表进行赋值，故程序会崩溃，不能满足所有条件
		//2.使用定位new会调用类的拷贝构造，这样也会构建虚表指针
		////尽量不要把对象赋值给空间，在有虚函数时不会将虚表指针赋值


		//数组大小不能动态 因为存放在数据区，编译时就已经确定
		//操作堆区时 是动态的
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
		&base[top]->~_Ty();//调动析构函数来析构对象，满足一切要求
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


//封装、继承和派生、多态

//常性指针 char a[]={"afasdf"}  char b[20];  b=a  b++;

//公有继承 ： 是一个   
//例如： class student:public person{}  //student 是一个 person

//私有继承 ： 由什么组成，组合关系   手机由屏幕、摄像头组成

//先创建基类  基类为不具名对象，将基类类名给给创建的基类  
//析构时先析构student  再析构不具名对象基类person  
//person并不是右值
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
		cout << "身份证号: " << m_idperson << '\t';
		cout << "姓名: " << m_name << "\t";
		cout << "性别: " << m_sex << "\t";
		cout << "年龄: " << m_age << endl;
	}
	void Dance() const
	{
		cout << "跳舞" << endl;
	}

};

class Student : public Person // 是一个
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

	////封装、继承和派生、多态

	cout << sizeof(string) << endl;
	Student stud;
	return 0;

}
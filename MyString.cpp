#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
#include<string>
#include<cstdlib>
#include<cassert>

using namespace std;

/*MyString*/
//class MyString 
//{
//private:
//	char* pstr;
//
//	MyString( char* s,int) 
//	{
//		if (s != nullptr) 
//		{
//			this->pstr = s;
//		}
//		else
//		{
//			pstr = new char('\0');
//		}
//	}
//public:
//	MyString(const char* s = nullptr) 
//	{
//		if (s != nullptr) 
//		{
//			delete[]pstr;
//			int length = strlen(s)+1;
//			pstr = new char[length];
//			strcpy_s(pstr,length,s);
//		}
//		else 
//		{
//			pstr = new char[1];
//			*pstr = '\0';
//		}
//	}
//
//	~MyString() 
//	{
//		delete[]pstr; // free(pstr);
//		pstr = nullptr;
//	}
//
//	void Print() const  // const MyString * const this;
//	{
//		if (pstr != nullptr)
//		{
//			cout << pstr << endl;
//		}
//	}
//
//	MyString(const MyString& s) :pstr(nullptr)//�������
//	{
//		if (s.pstr != nullptr)
//		{
//			delete[]pstr;
//			int len = strlen(s.pstr) + 1;
//			pstr = new char[len];
//			strcpy_s(pstr, len, s.pstr);
//		}
//		else
//		{
//			pstr = new char[1];
//			*pstr = '\0';
//		}
//	}
//
//	//������������ֵ
//	MyString& operator = (const MyString& s) 
//	{
//		if (this != &s) 
//		{
//			delete pstr;
//			int len = strlen(s.pstr)+1;
//			pstr = new char[len];
//			strcpy_s(pstr,len,s.pstr);
//
//		}
//		return *this;
//	}
//
//	//�ƶ���������
//	MyString(MyString&& s) 
//	{
//		pstr = s.pstr;
//		s.pstr = nullptr;
//	}
//
//
//	//+��������� MyString+MyString ����
//	//�� ���� �� ���� ��� �����������
//	//�����������ͬ
//	MyString operator+(const MyString &s) const
//	{
//		int total = strlen(s.pstr) + strlen(pstr) + 1;
//		char* newdata = new char[total];
//		strcpy_s(newdata,total,pstr);
//		strcat_s(newdata, total, s.pstr);
//		return MyString(newdata,0);
//	}
//
//	//+��������� MyString+char*
//	//1.���ַ����ᵼ��newdata�Ĵ�û���ͷ�
//	//MyString operator + (const char * s) 
//	//{
//	//	int total = strlen(s) + strlen(pstr) + 1;
//	//	char* newdata = new char[total];
//	//	strcpy_s(newdata,total,pstr);
//	//	strcat_s(newdata, total, s);
//	//	return MyString(newdata);
//	//}
//	//2.����࿪�ٿռ䣬Ч�ʵ�
//	//MyString operator + (const char* s)
//	//{
//	//	int total = strlen(s) + strlen(pstr) + 1;
//	//	char* newdata = new char[total];
//	//	strcpy_s(newdata, total, pstr);
//	//	strcat_s(newdata, total, s);
//	//	MyString temp(newdata);
//	//	delete []newdata;
//	//	newdata = nullptr;
//	//	return temp;
//	//}
//	// 
//	//3.����һ���������캯����ʹ�ַ������ݸ�����
//	//Ȼ���ַ����ڶ����ĵ�ַ�������������ͼ������ڶ������ٿռ�Ĵ���
//	MyString operator + (const char * s) 
//	{
//		int total = strlen(s) + strlen(pstr) + 1;
//		char* newdata = new char[total];
//		strcpy_s(newdata,total,pstr);
//		strcat_s(newdata, total, s);
//		return MyString(newdata,0);
//	}
//
//	//���ַ��� �� ���� ��� �����������
//	//1.�����ⲿ�����ڲ�����һ��thisָ�룬��+�����ֻ�ܽ�������ֵ����
//	// MyString operator +(const char* s1, const MyString s2)
//	//{
//			//return MyString(s1) + s2;
//	//}
//	//2.��Ԫ�������������ⲿ�������ÿ��Է������˽�г�Ա
//	friend MyString operator +(const char* s1, MyString s2);
//
//  
//};
//MyString operator +(const char* s1, const MyString s2)
//{
//	int total = strlen(s1) + strlen(s2.pstr) + 1;
//	char* newdata = new char[total];
//	strcpy_s(newdata, total, s1);
//	strcat_s(newdata, total, s2.pstr);
//	return MyString(newdata,0);
//	//return MyString(s1) + s2;
//}

class Mystring
{
private:
	static const int BufSize = 16;
public:
	struct StrNode 
	{
		int ref;
		int len;
		int size;
		char data[];
	};

private:
	StrNode* pstr;
	static StrNode* BuyMem(size_t size)
	{
		StrNode* s = (StrNode*)malloc(sizeof(StrNode) + sizeof(char) * size);
		if (nullptr == s) exit(EXIT_FAILURE);
		return s;
	}
	static void Freenode(StrNode* p)
	{
		free(p);
		p = nullptr;
	}

	//_��ȷ����Ϊ���˽�г�Ա�����������⿪��
	void _Init(const char* p) 
	{
		int len = strlen(p);
		int size = (len * 2) > BufSize ? (len * 2) : BufSize;
		pstr = BuyMem(size);
		pstr->ref = 1;
		pstr->len = len;
		pstr->size = size - 1;// 
		strcpy_s(pstr->data, pstr->size+1, p);
	}

	void _IncMem( int newsize = 0)//pstr!=nullptr pstr->ref=1; 
	{
		
		int len = pstr->len;
		size_t size = (pstr->size+1)*2;
		if(newsize!=0)
		{
			size = (newsize + pstr->size ) * 2;
		}
		StrNode* newstr = BuyMem(size);
		newstr->ref = 1;
		newstr->len = len;
		newstr->size = size - 1;
		strcpy_s(newstr->data,newstr->size+1,pstr->data);
		Freenode(pstr);
		pstr = newstr;

	}

	StrNode* _CopyPstr(StrNode* p) 
	{
		
		int len = p->len;
		size_t size = p->size + 1;
		StrNode* newstr = BuyMem(size);
		memmove(newstr,p,sizeof(StrNode)+len+1);
		newstr->ref = 1;
		p->ref -= 1;
		return newstr;

	}

public:
	//���캯��
	Mystring(const char* p = nullptr) :pstr(nullptr)
	{
		if (p != nullptr)
		{
			_Init(p);
		} 
	}

	//���캯��
	Mystring(const Mystring & s):pstr(s.pstr)
	{
		//pstr!=nullptr �� nullptr!=pstr д������������ǣ����߻����ѱ���
		if (pstr != nullptr) 
		{
			pstr->ref += 1;
		}
	}
	//��ֵ����
	Mystring& operator=(const Mystring& s) 
	{
		if (this == &s || this->pstr == s.pstr)return *this;
		if ( nullptr != this->pstr && --this->pstr->ref == 0) 
		{
			Freenode(pstr);
			pstr = nullptr;
		}
		this->pstr = s.pstr;
		if (nullptr!=this->pstr) 
		{
			this->pstr->ref += 1;
		}
		return *this;

	}

	//�ƶ����� 
	//���ڹ��캯����һ�֣��ڵ��ù��캯��֮ǰthis->pstr��δ�������ʲ��õ���pstrԭָ��Ŀռ�
	Mystring(Mystring&& s):pstr(s.pstr)
	{
		s.pstr = nullptr;
	}

	//�ƶ���ֵ
	Mystring& operator=(Mystring&& s) 
	{
		if (this == &s ||(nullptr==this->pstr && nullptr==s.pstr))return *this;
		//this->pstr = move(s.pstr);

		//s1=s2  s2��������Ȩ
		if (this->pstr == s.pstr) 
		{
			s.pstr->ref -= 1;
			s.pstr = nullptr;
			return *this;
		}

		//s1.pstr=nullptr s2.pstr not
		//s1.pstr=not s2.pstr nullptr
		//s1.pstr=not s2.pstr not
		if (nullptr != this->pstr && --this->pstr->ref == 0) 
		{
			Freenode(this->pstr);
			this->pstr = nullptr;
		}
		this->pstr = s.pstr;
		s.pstr = nullptr;
		return *this;
	}

	//��������
	~Mystring()
	{
		if (pstr != nullptr && --pstr->ref == 0)
		{
			Freenode(pstr);
		}
		pstr = nullptr;
	}

	//����Ԫ��
	char& at(size_t pos) 
	{
		assert(pos >= 0 && pos < pstr->len);
		return pstr->data[pos];
	}
	const char& at(size_t pos) const 
	{
		assert(pos >= 0 && pos < pstr->len);
		return pstr->data[pos];
	}
	char& operator[](size_t pos) 
	{
		return pstr->data[pos];
	}
	const char& operator[](size_t pos)const
	{
		return pstr->data[pos];
	}

	char& front() 
	{
		assert(nullptr != pstr);
		return at(0);
	}
	const char& front()const
	{
		assert(nullptr != pstr);
		return at(0);
	}

	char& back() 
	{
		assert(nullptr!=nullptr&& pstr->len>0);
		return at(pstr->len - 1);
	}
	const char& back()const
	{
		assert(nullptr != nullptr && pstr->len > 0);
		return at(pstr->len - 1);
	}

	char* data() 
	{
		return pstr->data;
	}
	const char* data()const
	{
		return pstr->data;
	}

	ostream& operator<<(ostream& out)const 
	{
		if (nullptr != pstr) 
		{
			out << "ref:" << pstr->ref <<"len:" << pstr->len <<"size:" << pstr->size << endl;
			out << pstr->data;
		}
		return out;

	}




	bool empty() const
	{
		assert(nullptr!=pstr);
		return pstr->len = 0;
	}

	size_t size() const
	{
		assert(nullptr!=pstr);
		return pstr->len;
	}
	size_t capacity() 
	{
		assert(pstr!=nullptr);
		return pstr->size;
	}
	void resever(size_t new_cap) 
	{
		if (nullptr == pstr) 
		{
			pstr = BuyMem(new_cap);
			pstr->ref = 1;
			pstr->len = 0;
			pstr->size = new_cap-1;
			pstr->data[0] = '\0';

		}
		else if (new_cap> (pstr->size * 1.5) ) 
		{
			StrNode* newstr = BuyMem(new_cap);
			newstr->ref = 1;
			newstr->len = pstr->len;
			newstr->size = new_cap - 1;
			strcpy_s(newstr->data,newstr->size+1,pstr->data);//+1 Ҫ�����ַ����е�'\0' ���ַ��������ı��
			if (--pstr->ref == 0) 
			{
				Freenode(pstr);
			}
			pstr = newstr;
		}
	}
	Mystring& insert(size_t index, const char ch) //���±�index�� ����ch�ַ�
	{
		if (nullptr == pstr && index==0) 
		{
			char str[2] = {ch}; // ch ,\0
			_Init(str);
		}
		else
		{
			assert(nullptr != pstr && index >= 0 && index <= pstr->len);
		
			if (pstr->ref > 1) 
			{
				pstr = _CopyPstr(pstr);
				//pstr->ref = 1;
			}
	 	
			if (pstr->len + 1 > pstr->size) 
			{
				_IncMem();	
			}

			memmove(pstr->data+index+1,pstr->data+index,pstr->len-index+1);//Ŀ���λ����ʼ��λ���ƶ��ĸ���
			pstr->data[index] = ch;
			pstr->len += 1;
		}
		return *this;

		////����״̬��
		//memmove(pstr->data+index+1,pstr->data+index,pstr->len-index+1);
		//pstr->data[index] = ch;
		//pstr->len += 1;

	}

	Mystring& insert(size_t index, const char* p) //���±�index�� ����p�ַ���
	{
		if (nullptr == p)return *this;//��ǰ���� �����ڲ��ܺ���Ӱ�� ���� ���� ����
		if (nullptr == pstr && index == 0 && nullptr!=p)
		{
			_Init(p);
		}
		else
		{
			assert(nullptr != pstr && index >= 0 && index <= pstr->len);

			if (pstr->ref > 1)
			{
				pstr = _CopyPstr(pstr);//дʱ����
				//pstr->ref = 1;
			}

			int len = strlen(p),l = pstr->len; 
			if (pstr->len + len > pstr->size)
			{
				_IncMem(len);
			}
		    /*while(!pstr->len + len > pstr->size)
			{
				_IncMem();
			}*/

			memmove(pstr->data + index + len, pstr->data + index, pstr->len-index+1);//Ŀ���λ����ʼ��λ���ƶ��ĸ���
			
			//1.
			//memmove(pstr->data + index,p,len);
			
			//2.
			//memcpy(pstr->data + index, p, len);
			
			//3.
			/*for (int i = index,j = 0; i < index + len; i++,j++) 
			{
				pstr->data[i] = p[j];
			}*/

			//4.
			//strcpy( pstr->data+index,p );

			//5.strncpy
			strncpy(pstr->data + index, p,len);

		
			pstr->len += len;
		}
		return *this;
	}
	Mystring& insert(size_t index,const Mystring&s) 
	{
		if (nullptr == s.pstr)return *this;

		return this->insert(index,s.pstr->data );
	}


	//Mystring& operator+=(char ch)
	//{
	//	if (nullptr != pstr)
	//	{
	//		insert(pstr->len, ch);
	//	}
	//	else
	//	{
	//		insert(0, ch);
	//	}
	//}//s1+='a'

	Mystring& operator+=(const char ch) 
	{
		if (nullptr != pstr) 
		{
			insert(pstr->len,ch);
		}
		else 
		{
			insert(0,ch);
		}
		return *this;
	}//s1+='a'
	Mystring& operator+=(const char* cp)
	{
		assert(cp != nullptr); 
		if (nullptr != pstr) 
		{
			insert(pstr->len,cp);
		}
		else
		{
			insert(0,cp);
		}
		return *this;
	}

	void push_back(const char ch) 
	{
		*this += ch;
	}
	void push_back(const char* cp) 
	{
		*this += cp;

		//���ü�'\0' Ҫ�ӵ��ַ�������'\0'
		//cout << this->pstr->len;
		//*this += '\0';
		//cout << this->pstr->len;
	}
	void push_back(const Mystring& s) 
	{
		*this += s.pstr->data;
	}

	Mystring& erase(size_t index)
	{
		if (nullptr == pstr)return *this;
		assert(index < pstr->len);
		if (pstr->ref > 1) 
		{
			pstr = _CopyPstr(pstr);
		}
		memmove(this->pstr->data + index, this->pstr->data + index + 1, this->pstr->len - index );
		pstr->len -= 1;
		return *this;
	}
	Mystring& erase(size_t index,int n)
	{
		if (nullptr == pstr)return *this;
		assert( index < pstr->len && index+n < pstr->len);
		if (pstr->ref > 1)
		{
			pstr = _CopyPstr(pstr);
		}
		memmove(this->pstr->data + index, this->pstr->data + index + n, this->pstr->len - index );
		pstr->len -= n;
		return *this;
	}

	//size_t & operator [](size_t n)
	//{

	//}

	void clear()
	{
		if (nullptr != pstr && pstr->ref > 1) 
		{
			pstr = _CopyPstr(pstr);
		}
		if (nullptr != pstr) 
		{
			//��ref==1ʱ����pstr��=nullptrʱ �������
			//������������if����޷���֤�� refֱ��=1 ʱ�����ַ����������
			pstr->len = 0;
		}
	}
	
	istream& operator>>(istream& in)
	{
		char ch;
		while (in.get(ch) , ch != '\n')
		{
			*this += ch;
		}

		return in;

	}
	
	//��ӡ
	void Print() const
	{
		if (pstr != nullptr)
		{
			printf("%s \n", pstr->data);
			cout << ' ' << "len:" << pstr->len << endl;
		}
	}
};
ostream& operator<<(ostream& out, const Mystring& s) 
{
	s<<out;// operator<<(s,out)
	return out;
}

istream& operator>>(istream& in,  Mystring& s)
{
	s >> in;// operator>>(s,in)
	return in;
}

int main() 
{
	////MyString
	//MyString s1("yjs"), s2("hello"), s3;

	//s3 = s1 + s2;
	//s3.Print();

	//s3 = s1 + "feifei";
	//s3.Print();

	//s3 = "hello" + s1;
	//s3.Print();


	//Mystring
	Mystring ss1("yhping");
	Mystring ss2("hellonewdata");
//	ss1.Print();
//	ss2.Print();

	cout << ss1<<endl<<ss2 << endl;
	cout << ss1.at(4);

	Mystring ss3( "world--"),ss4("f....."),ss5=ss3;
	
	//for (int i = 0; i < 26; i++) 
	//{
	//	ss3.insert(i, i + 'a');
	//	cout << i<<":" << ss3 << endl;
	//}
	const char* p = "hello ";

	
	ss3.insert(7,p);
	ss3.Print();
	
	ss3.insert(7, ss4);
	ss3.Print();
	//ss5.Print();
	ss3.erase(0);
	ss3.Print();

	ss3.erase(10,5);
	ss3.Print();

	return 0;
}


#if 0
debug�汾 �� release�汾 ������ 

memmove���������÷�







#endif
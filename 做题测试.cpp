#include<iostream>
#include<string.h>
#include<bitset>

using namespace std;


void merge(int  nums[], int arr[], int left, int mid, int right)
{
    int l_pos = left;
    int r_pos = mid + 1;

    int pos = left;

    while (l_pos <= mid && r_pos <= right)
    {
        if (nums[l_pos] < nums[r_pos])
        {
            arr[pos++] = nums[l_pos++];
        }
        else arr[pos++] = nums[r_pos++];
    }

    //添加剩余元素
    while (l_pos <= mid)
    {
        arr[pos++] = nums[l_pos++];
    }
    while (r_pos <= right)
    {
        arr[pos++] = nums[r_pos++];
    }

    //将排完序的元素放在临时数组中
    int i = left;
    for (; i <= right; i++)
    {
        nums[i] = arr[i];
    }
}

void msort(int nums[], int arr[], int left, int right)
{
    if (left < right)
    {
        int mid = (left + right) / 2;
        //左右递归划分
        msort(nums, arr, left, mid);
        msort(nums, arr, mid + 1, right);

        //左右递归合并
        merge(nums, arr, left, mid, right);

    }

}

void megre_sort(int  nums[], int l)
{
    int* arr = (int*)malloc(sizeof(int) * (l + 1));
    if (arr)
    {
        msort(nums, arr, 0, l - 1);
        free(arr);
    }
    else cout << " error:arr allectde error " << endl;

}



//爬楼梯
int pa(int n) //递归
{
    if (n == 1)return 1;
    if (n == 2)return 2;

    return pa(n - 1) + pa(n-2);
}
 long long pa1(int n) 
{
    long long i = 0, j = 0, sum = 1;
    for (int q = 1; q <= n; q++) 
    {
        i = j;
        j = sum;
        sum = j + i;
    }
    return sum;
}




 //类模板实现栈






 // 实现整型栈
 class MyStack
 {
     enum { STACK_INIT_SIZE = 10, STACK_INC_SIEZ = 2 };
     int* data;
     int size;
     int top;
     bool IncSize() 
     {
         int newsize = size * STACK_INC_SIEZ;
         int* newdata = new int[newsize];
         if (newdata == data) 
         {
             return false;
         }
         memmove_s(newdata,sizeof(int)*newsize,data,sizeof(int)*size);
         
         data = newdata;
         size = newsize;
         delete newdata;


     }
 public:
     MyStack()
     {
         top = -1; // 
         size = STACK_INIT_SIZE;
         data = new(nothrow) int[size];
         if (nullptr == data) exit(EXIT_FAILURE);
     }
     MyStack(int sz)
     {
         top = -1;
         size = (sz > STACK_INIT_SIZE) ? sz : STACK_INIT_SIZE;
         data = new(nothrow) int[size];
         if (nullptr == data) exit(EXIT_FAILURE);
     }
     ~MyStack()
     {
         delete[]data;
         data = nullptr;
         size = 0;
         top = -1;
     }
     int Size() const { return top + 1; }
     bool IsEmpty()const { return Size() == 0; } // return top == -1;
     bool IsFull() const { return Size() == size; }
     bool Push(const int val)
     {
         if (IsFull())
         {
             return false;
         }
         data[++top] = val;
         return true;
     }
     bool Top(int& val)  // 取栈顶元素，元素不出栈
     {
         if (IsEmpty())
         {
             return false;
         }
         val = data[top];// return data[top];
         return true;
     }
     void  Pop()  // 只是出栈
     {
         if (!IsEmpty())
         {
             top -= 1;
         }
     }

     // 取栈顶元素和出栈
     bool GetPop(int & val)
     {
         if (IsEmpty())
         {
             return false;
         }
         val = data[top--];
    
         return true;
     }


 };


 int main()
 {
     MyStack mys;
     for (int i = 0; i < 5; ++i)
     {
         mys.Push(i);
     }
     while (!mys.IsEmpty())
     {
         int x = 0;
         mys.Top(x);
         mys.Pop();
         cout << x << endl;
         mys.
     }

     return 0;
 }






//int main()
//{
//	//string 字符串
//	//string str ="afasdfaf";
//	//cout << str.empty() << endl;
//	//const char * a = str.c_str();
//	//
//	//cout<<str.data()<<" ";
//	//cout<< str.front()<< " ";
//	//cout<<  str.back()<<" ";
//	//cout<< str.at(3)<<" ";
//	//cout << str.capacity() << " ";//显示容量   string按原有容量 2 倍扩容
//
//	//str.reserve();//设置string 类型的容量
//
//
//    //int arr[] = { 123,5,31,546,1231,5,4,2,3,4,6,8,9 };
//    //int la = sizeof(arr) / sizeof(arr[0]);
//    //for (auto i : arr)
//    //{
//    //    cout << i << " ";
//    //}
//    //cout << endl;
//    //megre_sort(arr,la);
//
//    //for (auto i : arr) 
//    //{
//    //    cout << i << " ";
//    //}
//
//    //for (int i = 1; i < 100; i++) 
//    //{
//    //    if(i%3==0)cout << endl;
//
//    //    cout << "第" <<i<< "层：" << pa(i) <<"        ";
//
//    //}
// /*   for (int i = 1; i <= 70; i++)
//    {
//        if ((i-1) % 3 == 0)cout << endl;
//
//        cout << "第" << i << "层：" << pa1(i) << "        ";
//
//    }
//
//    cout << bitset<32>(10) << endl;*/
//
//
//
//
//    return 0;
//
//}

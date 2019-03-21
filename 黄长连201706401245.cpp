#include <stdio.h>//定义输入输出函数
#include <stdlib.h>//定义杂项函数及内存分配函数
int count;//有count种不同的分解式
void f(int n)//定义并解决n这个变量，n表示输入的那个正整数且（1<=n&&n<=2000000000)
{
    int i;//定义变量i
    if(n == 1)//因为1<=n，当n=1时即商为1时为已经算出一次分解所以累计+1种
        count++;
    for(i=2;i<=n;i++)//当i<=n且i要从等于2开始，每个数进行遍历，例如：12/2，若是12/1得到的数等于n本身，
		             //得到的分解式就会出现重复，不符合题意
    {
        if(n % i == 0)//求得的模为0 即n为可分解的数
            f(n/i);//将n进行分解
    }
}
int main()//表示函数有返回值，那么在main函数结束的时候要有return语句，main()函数称之为主函数，
          // 一个C语言程序总是从main()函数开始执行的而int指明了main()函数的返回类型
{
    int n;//定义变量n表示输入的那个正整数
    while(scanf("%d",&n)!=0){//输出的n不等于0则接着执行下面的步骤
        count = 0;//开始时候把count的值等于0
        f(n);//调用f函数
        printf("所求的分解式的个数%d\n",count);//输出count的值即题目所求的分解式的个数
    }
 
    return 0;//main()函数的返回值
}

//该程序是按递归算法进行逐个搜索，每次运行求得的模为0 即为分解数，递归此数直到为1即可累计个数加1

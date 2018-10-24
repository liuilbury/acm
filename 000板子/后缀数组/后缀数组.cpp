#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int maxn = 1000;
const int maxasc = 128; //ascII码[0,127]
char s[maxn];
int sa[maxn],t1[maxn],t2[maxn],c[maxn],n;

void debug()
{
    for(int i=0; i<n; i++) printf("%d ",sa[i]);
    printf("\n");
}
/* void build_height(int *r, int n){//加一段求height的代码吧
    int k=0, j;
    for(int i=0; i<n; i++)  rank[sa[i]] = i;//rank与sa是反函数
    //如果在原串后面加了一个极小的字符（某些题目需要）
    //就应该for(int i=1; i<=n; i++)//因为以这个极小字符开头的后缀串一定是最小的，也就是s[0]
    //我们0~n-1，n个后缀串也就变成了0~n，n个，所以for 1~n（网上大多数代码并没有解释这一点）
    for(int i=1; i<=n; height[rank[i++]] = k)//height[rank[1]=0
        for(k ? k--:0, j = sa[rank[i]-1]; r[i+k] == r[j+k]; k++);
        //j就是排序后的上一个后缀。
        //第i-2个后缀与第i-1个后缀的height为k，那么第i-1个后缀与第i个后缀的height至少为k-1（可举例验证）于是从k-1向后扩展
} */
void build_sa(int m)
{
    int *x = t1, *y = t2;//因为之后我们要swap（x，y）所以用指针
    //第一遍实际就是对s数组稳定排序,使用的是基数排序
    for(int i=0; i<m; i++) c[i] = 0;//清空桶
    for(int i=0; i<n; i++) c[x[i] = s[i]]++;//x[i]=s[i]，x相当于是rank，存的是排名第i的串的首字母是什么，当然现在还没有排名
    //把首字母相同的放在同一个桶里
    for(int i=1; i<m; i++) c[i] += c[i-1];//就根据首字母排序，首字母为i的前面留出首字母为1~i-1的数足够位置
    for(int i=n-1; i>=0; i--) sa[--c[x[i]]] = i;//sa[i]表示排名为i的串首字母在原串中的位置
    //因为还没有排完序，所以当前x[i]表示的还是i位置所引领的串的首字母（s[i]），所以i位置所引领的串的排名自然就是“--c[x[i]]”
    //
    for(int k=1; k<=n; k = k<<1) //每次扩展两倍
    {
        int p = 0;
        //利用sa数组直接排序第二关键字
        for(int i=n-k; i<n; i++) y[p++] = i;
        //实际是认为没有第二关键字，即不存在后k个字符的串的第二关键字最小,所以放在前面，y[i] = x 表示第二关键字第i小的串的首字母在i位置
        for(int i=0; i<n; i++) if(sa[i] >= k) y[p++] = sa[i]-k;//第二关键字的位置本来是sa[i]，-k之后就变成它对应第一关键字的位置（直边所指）
        //如果sa[i]小于k,第一关键字不够k个字符，因为斜边指向第二关键字，直边就指向第一关键字，若是第二关键字小于看，有会指出去
        //基数排序第一关键字
        //已经知道第二关键字的大小顺序了,扔到桶(c数组)里来一趟基数排序
        for(int i=0; i<m; i++) c[i] = 0;
        for(int i=0; i<n; i++) c[x[y[i]]]++;//y[i]表示第二关键字第i小的串对应第一关键字的首字母在i位置，x[i]表示i位置所引领的串的首字母
        //所以x[y[i]]表示第二关键字第i小的串对应第一关键字的首字母，首字母相同的放在一个桶里
        for(int i=0; i<m; i++) c[i] += c[i-1];//就根据首字母排序，首字母为i的前面留出首字母为1~i-1的数足够位置
        for(int i=n-1; i>=0; i--) sa[--c[x[y[i]]]] = y[i];//y[i]表示第二关键字第i小的串对应第一关键字的首字母在i位置
        //sa[i]表示排名为i的串首字母在原串中的位置，那么在y[i]位置的串排名应该是“--c[x[y[i]]]”
        //根据sa和y数组计算x数组
        //x数组实际是用来确定首字母为第i号字符,连续k个字母的串的相对大小的,所以最开始x[i]=s[i]
        swap(x,y);//我们在下一次循环之前不会用到x所以不用在意x中到底存的是什么，总是要覆盖的。
        //交换以后，我们原本舍弃的x，就变成舍弃y了
        p = 1; x[sa[0]] = 0;
        //从最小的串开始，赋予串一个整数值代表大小,aa = aa = 1,ab = 2,ba = 3等等
        for(int i=1; i<n; i++)
            x[sa[i]] = y[sa[i-1]] == y[sa[i]] && y[sa[i-1]+k] == y[sa[i]+k] ? p-1 : p++;//针对两个串比较直边所指元素和斜边所指元素
        //每个串都彼此大小不同了,事实上后缀就是应该所有都不相等的，相对大小已确定,退出循环
        if(p >= n) break;
        m = p; //关键字的取值范围发生了变化,现在只有p个不同的值
    }//最后就得到了sa和rank（x）
    debug();
}

int main()
{
    scanf("%s",s);
    n = strlen(s);
    build_sa(maxasc);
    return 0;
}
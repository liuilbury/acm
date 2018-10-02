#include <bits/stdc++.h>
using namespace std;
struct node
{
    short arr[3001];
    short length;
    short contribute;
    node()
    {
        memset(this->arr, -1, sizeof(this->arr));
        length = 0;
        contribute = 0;
    }
    void init()
    {
        memset(this->arr, -1, sizeof(this->arr));
        length = 0;
        contribute = 0;
    }
    friend bool operator<(const node &a, const node &b)
    {
        short maxlen = max(a.length, b.length);
        for (register short i = 0; i < maxlen; i++)
            if (a.arr[i] != b.arr[i])
                return a.arr[i] < b.arr[i];
        return 0;
    }
    friend bool operator==(const node &a, const node &b)
    {
        if (a.length != b.length)
            return false;
        for (register short i = 0; i < a.length; i++)
            if (a.arr[i] != b.arr[i])
                return false;
        return true;
    }
    void input()
    {
        scanf("%hd", &this->length);
        for (register short i = 0; i < this->length; i++)
            scanf("%hd", &this->arr[i]);
    }
} s[3001];
struct compare
{
    bool operator()(short x, short y)
    {
        return s[x] < s[y];
    }
};
set<short, compare> se;
static int sum = 0;
void calculate(set<short>::iterator previous, set<short>::iterator it)
{
    short pre = *previous;
    short i = *it;
    for (register short j = 0; j < s[i].length; j++)
    {
        if (s[i].arr[j] != s[pre].arr[j])
        {
            s[i].contribute = s[i].length - j;
            break;
        }
    }
}
void eraser(short num)
{
    auto it3 = se.lower_bound(num);
    sum -= s[num].contribute;
    auto it4 = it3;
    it4++;
    if (it4 != se.end())
    {
        if (it3 == se.begin())
        {
            sum -= s[*it4].contribute;
            s[*it4].contribute = s[*it4].length;
            sum += s[*it4].contribute;
        }
        else
        {
            auto it5 = it3;
            it5--;
            sum -= s[*it4].contribute;
            calculate(it5, it4);
            sum += s[*it4].contribute;
        }
    }
    se.erase(it3);
}
void insert(short num)
{
    auto it6 = se.insert(num).first;
    if (it6 == se.begin())
    {
        sum += s[*it6].contribute = s[*it6].length;
    }
    else
    {
        auto it7 = it6;
        it7--;
        calculate(it7, it6);
        sum += s[*it6].contribute;
    }
    auto it8 = it6;
    it8++;
    if (it8 != se.end())
    {
        sum -= s[*it8].contribute;
        calculate(it6, it8);
        sum += s[*it8].contribute;
    }
}
int main()
{
    /*freopen("d:\\7.in","r",stdin);
	freopen("d:\\7.out","w",stdout);*/
    short n;
    scanf("%hd", &n);
    for (register short i = 0; i < n; i++)
    {
        s[i].input();
        se.insert(i);
    }
    auto it1 = se.begin();
    auto it2 = it1;
    it2++;
    sum = s[(*it1)].contribute = s[(*it1)].length;
    while (it2 != se.end())
    {
        calculate(it1, it2);
        sum += s[(*it2)].contribute;
        it1 = it2++;
    }
    printf("%d\n", sum);
    short q;
    scanf("%hd", &q);
    while (q--)
    {
        short num;
        scanf("%hd", &num);
        num--;
        eraser(num);
        s[num].init();
        s[num].input();
        insert(num);
        printf("%d\n", sum);
    }
}
/*
15
15
19
 */

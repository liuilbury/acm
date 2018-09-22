#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
#define mem(a, b) memset(a, b, sizeof(a))
#define INF 0X3f3f3f3f
const ll MAXN = 5000 + 7;
const ll MOD = 1e9 + 7;
//-------------------------------------------//
string a[5][14];
map<string, int> s0; // 顺序
map<int, string> s;
map<int, int> mp[5]; //  手牌
int wp[5][100];      //      场上的牌
int cnt[5];          //每个人打出的牌的数量
int t;
int lei;
int name[5];
bool pk(int p, int x, int card, int cc)
{
    if (p == 0)
    {
        if (mp[p][x] == 0 && cc == 0)
        {
            return true;
        }
        if (mp[p][(x + 12) % 13] + card > 4)
        {
            return true;
        }
        return false;
    }
    else if (p == 1)
    {
        if (mp[p][x] == 0)
        {
            return true;
        }
        return false;
    }
    else if (p == 2)
    {
        if (mp[p][(x + 12) % 13] == 4)
        {
            return true;
        }
        else
            return false;
    }
    else if (p == 3)
    {
        for (int i = 0; i < 3; i++)
        {
            int flag = 0;
            for (int j = 0; j <= 12; j++)
            {
                if (mp[i][j] == 0)
                    continue;
                else
                {
                    flag = 1;
                    break;
                }
            }
            if (flag == 0)
            {
                return true;
            }
        }
        return false;
    }
}
void play(int p, int x)
{
    int flag = 0;
    if (p == 0)
    {
        if (mp[p][x % 13] >= 1)
        {
            lei = x;
            mp[p][x]--;
            wp[p][++cnt[p]] = x;
            if (pk(1, (x + 1) % 13, 1, 0))
            {
                for (int i = 0; i < 4; i++)
                {
                    while (cnt[i] > 0)
                    {
                        mp[1][wp[i][cnt[i]]]++;
                        cnt[i]--;
                    }
                }
            }
            else if (pk(2, (x + 1) % 13, 1, 0))
            {
                for (int i = 0; i < 4; i++)
                {
                    while (cnt[i] > 0)
                    {
                        mp[2][wp[i][cnt[i]]]++;
                        cnt[i]--;
                    }
                }
            }
            else if (pk(3, (x + 1) % 13, 1, 0))
            {
                for (int i = 0; i < 4; i++)
                {
                    while (cnt[i] > 0)
                    {
                        mp[3][wp[i][cnt[i]]]++;
                        cnt[i]--;
                    }
                }
            }
        }
        else
        {
            for (int i = 0; i <= 12; i++)
            {
                if (mp[p][s0[s[i]]] > 0)
                {
                    lei = s0[s[i]];
                    mp[p][s0[s[i]]]--;
                    wp[p][++cnt[p]] = s0[s[i]];
                    break;
                }
            }
            if (pk(1, (x + 1) % 13, 1, 0))
            {
                for (int i = 0; i < 4; i++)
                {
                    while (cnt[i] > 0)
                    {
                        mp[p][wp[i][cnt[i]]]++;
                        cnt[i]--;
                    }
                }
            }
            else if (pk(2, (x + 1) % 13, 1, 0))
            {
                for (int i = 0; i < 4; i++)
                {
                    while (cnt[i] > 0)
                    {
                        mp[p][wp[i][cnt[i]]]++;
                        cnt[i]--;
                    }
                }
            }
            else if (pk(3, (x + 1) % 13, 1, 0))
            {
                for (int i = 0; i < 4; i++)
                {
                    while (cnt[i] > 0)
                    {
                        mp[p][wp[i][cnt[i]]]++;
                        cnt[i]--;
                    }
                }
            }
        }
    }
    /////

    ////
    else if (p == 1)
    {
        if (mp[p][x % 13] >= 1)
        {
            lei = x;
            t = mp[p][x];
            for (int i = 1; i <= mp[p][x]; i++)
                wp[p][++cnt[p]] = x;
            mp[p][x] = 0;
            if (pk(2, (x + 1) % 13, t, 0))
            {
                for (int i = 0; i < 4; i++)
                {
                    while (cnt[i] > 0)
                    {
                        mp[2][wp[i][cnt[i]]]++;
                        cnt[i]--;
                    }
                }
            }
            else if (pk(3, (x + 1) % 13, t, 1))
            {
                for (int i = 0; i < 4; i++)
                {
                    while (cnt[i] > 0)
                    {
                        mp[3][wp[i][cnt[i]]]++;
                        cnt[i]--;
                    }
                }
            }
            else if (pk(0, (x + 1) % 13, t, 1))
            {
                for (int i = 0; i < 4; i++)
                {
                    while (cnt[i] > 0)
                    {
                        mp[0][wp[i][cnt[i]]]++;
                        cnt[i]--;
                    }
                }
            }
        }
        else
        {
            for (int i = 0; i <= 12; i++)
            {
                if (mp[p][s0[s[i]]] > 0)
                {
                    lei = s0[s[i]];
                    t += 1;
                    mp[p][s0[s[i]]]--;
                    wp[p][++cnt[p]] = s0[s[i]];
                    break;
                }
            }
            if (pk(2, (x + 1) % 13, t, 0))
            {
                for (int i = 0; i < 4; i++)
                {
                    while (cnt[i] > 0)
                    {
                        mp[p][wp[i][cnt[i]]]++;
                        cnt[i]--;
                    }
                }
            }
            else if (pk(3, (x + 1) % 13, t, 1))
            {
                for (int i = 0; i < 4; i++)
                {
                    while (cnt[i] > 0)
                    {
                        mp[p][wp[i][cnt[i]]]++;
                        cnt[i]--;
                    }
                }
            }
            else if (pk(0, (x + 1) % 13, t, 1))
            {
                for (int i = 0; i < 4; i++)
                {
                    while (cnt[i] > 0)
                    {
                        mp[p][wp[i][cnt[i]]]++;
                        cnt[i]--;
                    }
                }
            }
        }
    }
    ////
    ////
    else if (p == 2)
    {
        if (mp[p][x % 13] >= 1)
        {
            lei = x;
            t = mp[p][x];
            for (int i = 1; i <= mp[p][x]; i++)
                wp[p][++cnt[p]] = x;
            mp[p][x] = 0;
            if (pk(3, (x + 1) % 13, t, 1))
            {
                for (int i = 0; i < 4; i++)
                {
                    while (cnt[i] > 0)
                    {
                        mp[3][wp[i][cnt[i]]]++;
                        cnt[i]--;
                    }
                }
            }
            else if (pk(0, (x + 1) % 13, t, 1))
            {
                for (int i = 0; i < 4; i++)
                {
                    while (cnt[i] > 0)
                    {
                        mp[0][wp[i][cnt[i]]]++;
                        cnt[i]--;
                    }
                }
            }
        }
        else
        {
            for (int i = 1; i <= 4; i++)
            {
                int flag = 0;
                for (int j = 0; j <= 12; j++)
                {
                    if (mp[p][i] == i)
                    {
                        lei = s0[s[i]];
                        t = mp[p][s0[s[i]]];
                        for (int k = 1; k <= mp[p][s0[s[i]]]; k++)
                        {
                            wp[p][++cnt[p]] = s0[s[i]];
                        }
                        mp[p][s0[s[i]]] = 0;
                        flag = 1;
                        break;
                    }
                }
                if (flag == 1)
                    break;
            }
            if (pk(3, (x + 1) % 13, t, 1))
            {
                for (int i = 0; i < 4; i++)
                {
                    while (cnt[i] > 0)
                    {
                        mp[p][wp[i][cnt[i]]]++;
                        cnt[i]--;
                    }
                }
            }
            else if (pk(0, (x + 1) % 13, t, 1))
            {
                for (int i = 0; i < 4; i++)
                {
                    while (cnt[i] > 0)
                    {
                        mp[p][wp[i][cnt[i]]]++;
                        cnt[i]--;
                    }
                }
            }
        }
    }
    else
    {
        if (mp[p][x % 13] >= 3)
        {
            lei = x;
            t = mp[p][x];
            for (int i = 1; i <= mp[p][x]; i++)
                wp[p][++cnt[p]] = x;
            mp[p][x] = 0;
            if (pk(0, (x + 1) % 13, t, 0))
            {
                for (int i = 0; i < 4; i++)
                {
                    while (cnt[i] > 0)
                    {
                        mp[0][wp[i][cnt[i]]]++;
                        cnt[i]--;
                    }
                }
            }
            else if (pk(2, (x + 1) % 13, t, 0))
            {
                for (int i = 0; i < 4; i++)
                {
                    while (cnt[i] > 0)
                    {
                        mp[2][wp[i][cnt[i]]]++;
                        cnt[i]--;
                    }
                }
            }
        }
        else
        {
            lei = x;
            t = mp[p][x];
            for (int i = 1; i <= mp[p][x]; i++)
                wp[p][++cnt[p]] = x;
            mp[p][x] = 0;
            int six = 0;
            for (int i = 0; i <= 12; i++)
            {
                if (mp[p][s0[s[i]]] > 0)
                {
                    lei = s0[s[i]];
                    t += 1;
                    mp[p][s0[s[i]]]--;
                    wp[p][++cnt[1]] = s0[s[i]];
                    six = 1;
                    break;
                }
            }
            if (six == 1)
            {
                if (pk(0, (x + 1) % 13, t, 0))
                {
                    for (int i = 0; i < 4; i++)
                    {
                        while (cnt[i] > 0)
                        {
                            mp[p][wp[i][cnt[i]]]++;
                            name[p]++;
                            cnt[i]--;
                        }
                    }
                }
                else if (pk(2, (x + 1) % 13, t, 0))
                {
                    for (int i = 0; i < 4; i++)
                    {
                        while (cnt[i] > 0)
                        {
                            mp[p][wp[i][cnt[i]]]++;
                            name[p]++;
                            cnt[i]--;
                        }
                    }
                }
            }
            else
            {
                if (pk(0, (x + 1) % 13, t, 0))
                {
                    for (int i = 0; i < 4; i++)
                    {
                        while (cnt[i] > 0)
                        {
                            mp[0][wp[i][cnt[i]]]++;
                            cnt[i]--;
                        }
                    }
                }
                else if (pk(2, (x + 1) % 13, t, 0))
                {
                    for (int i = 0; i < 4; i++)
                    {
                        while (cnt[i] > 0)
                        {
                            mp[2][wp[i][cnt[i]]]++;
                            cnt[i]--;
                        }
                    }
                }
            }
        }
    }
}
void gamestart()
{
    int ture = 0;
    int tt = 0;
    name[0] = name[1] = name[2] = name[3] = 13;
    while (1)
    {
        t = 0;
        play(ture % 4, (ture) % 13);
        ture++;
        for (int i = 0; i <= 3; i++)
        {
            int flag = 0;
            for (int j = 0; j <= 12; j++)
            {
                for (int k = 1; k <= mp[i][j]; k++)
                {
                    flag = 1;
                    break;
                }
                if (flag == 1)
                    break;
            }
            if (flag == 0)
            {
                tt = i + 1;
            }
            if (tt != 0)
                break;
        }
         for (int i = 0; i <= 3; i++)
        {
            int q = 0;
            if (i == tt - 1)
            {
                printf("WINNER\n");
                continue;
            }
            for (int j = 0; j <= 12; j++)
            {
                for (int k = 1; k <= mp[i][j]; k++)
                {
                    if (q == 0)
                    {
                        cout << s[s0[s[j]]];
                        q = 1;
                    }
                    else
                    {
                        cout << ' ' << s[s0[s[j]]];
                    }
                }
            }
            printf("\n");
        }
       // system("pause");
    }
}
int main()
{
    int n, m;
    s[0] = "10";
    s[1] = "2";
    s[2] = "3";
    s[3] = "4";
    s[4] = "5";
    s[5] = "6";
    s[6] = "7";
    s[7] = "8";
    s[8] = "9";
    s[9] = "A";
    s[10] = "J";
    s[11] = "K";
    s[12] = "Q";

    s0["A"] = 0;
    s0["2"] = 1;
    s0["3"] = 2;
    s0["4"] = 3;
    s0["5"] = 4;
    s0["6"] = 5;
    s0["7"] = 6;
    s0["8"] = 7;
    s0["9"] = 8;
    s0["10"] = 9;
    s0["J"] = 10;
    s0["Q"] = 11;
    s0["K"] = 12;
    while (cin >> a[0][0])
    {
        memset(cnt, 0, sizeof(cnt));
        for (int i = 0; i < 5; i++)
        {
            mp[i].clear();
        }
        for (int i = 1; i < 13; i++)
        {
            cin >> a[0][i];
        }
        for (int i = 1; i <= 3; i++)
        {
            for (int j = 0; j < 13; j++)
            {
                cin >> a[i][j];
            }
        }
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 13; j++)
            {
                mp[i][s0[a[i][j]]]++;
            }
        }
        gamestart();
    }
}
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
#define INF 0x3f3f3f3f
const int maxn = 300;
int dox[4];
int n, m, T;
char map1[300][300];
int vst[maxn][maxn][4];                     // 访问标记
int dir[4][2] = {0, -1, 1, 0, 0, 1, -1, 0}; // 方向向量
struct State                                // BFS 队列中的状态数据结构
{
    int x, y, turn;   // 坐标位置
    int Step_Counter; // 搜索步数统计器
};
State a[maxn], b;
bool CheckState(State s) // 约束条件检验
{
    if (vst[s.x][s.y][s.turn] > s.Step_Counter && map1[s.y][s.x] != '#') // 满足条件
        return 1;
    else // 约束条件冲突
        return 0;
}
int bfs(State st)
{
    queue<State> q;                             // BFS 队列
    State now, next;                            // 定义2 个状态，当前和下一个
    st.Step_Counter = 0;                        // 计数器清零
    q.push(st);                                 // 入队
    vst[st.x][st.y][st.turn] = st.Step_Counter; // 访问标记
    while (!q.empty())
    {
        now = q.front(); // 取队首元素进行扩展
        //printf("%d %d %d\n", now.x, now.y, now.Step_Counter);
        if (now.x == 0 || now.y == 0 || now.x == m - 1 || now.y == n - 1) // 出现目标态，此时为Step_Counter 的最小值，可以退出即可
        {
            return now.Step_Counter;
        }
        int flag = 0;
        for (int i = 0; i < 4; i++)
        {
            if (now.turn != -1)
            {
                if (dox[now.turn] == i || now.turn == i)
                    continue;
            }
            next.x = now.x + dir[i][0]; // 按照规则生成下一个状态
            next.y = now.y + dir[i][1];
            next.turn = i;
            next.Step_Counter = now.Step_Counter + 1; // 计数器加1
            if (map1[next.y][next.x] != '#')          // 如果状态满足约束条件则入队
            {
                flag = 1;
                if (vst[next.x][next.y][next.turn] > next.Step_Counter)
                {
                    q.push(next);
                    vst[next.x][next.y][next.turn] = next.Step_Counter;
                    //printf("%d %d %d\n", next.x, next.y, next.turn); //访问标记
                }
            }
        }
        if (flag == 0)
        {
            next.x = now.x + dir[now.turn][0];
            next.y = now.y + dir[now.turn][1];
            next.turn = now.turn;
            next.Step_Counter = now.Step_Counter + 1;
            if (CheckState(next)) // 如果状态满足约束条件则入队
            {
                q.push(next);
                vst[next.x][next.y][next.turn] = next.Step_Counter;
                //printf("%d %d %d\n", next.x, next.y, next.turn); //访问标记
            }
        }
        q.pop(); // 队首元素出队
    }
    return -1;
}
int main()
{
    int sx, sy;
    scanf("%d", &T);
    dox[0] = 2;
    dox[1] = 3;
    dox[2] = 0;
    dox[3] = 1;
    while (T--)
    {
        memset(vst, INF, sizeof(vst));
        scanf("%d %d", &n, &m);
        for (int i = 0; i < n; i++)
        {
            scanf("%s", map1[i]);
            for (int j = 0; j < m; j++)
            {
                if (map1[i][j] == '@')
                {
                    sx = j;
                    sy = i;
                }
            }
        }
        b.turn = -1;
        b.x = sx;
        b.y = sy;
        printf("%d\n", bfs(b));
    }
    return 0;
}
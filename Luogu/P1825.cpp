#include <algorithm>
#include <cstdio>
#include <cctype>
#include <cstring>
#include <queue>
#include <vector>

using std::vector;
using std::queue;
using std::pair;

typedef pair<int, int> P;

const int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
int n, m, tot, id[310][310], portal[26], dis[100010];
bool vis[100010];
char s[310][310];
vector<P> e[100010];

inline int bfs(int S, int T)
{
    queue<int> q, q0;
    int u;
    memset(dis, 0x3f, sizeof(dis));
    dis[S] = 0;
    q.push(S);
    while (!q.empty() || !q0.empty())
    {
        if (!q0.empty())
        {
            u = q0.front();
            q0.pop();
        }
        else
        {
            u = q.front();
            q.pop();
        }
        //printf("%d\n", u);
        if (vis[u])
            continue;
        vis[u] = true;
        if (u == T)
            return dis[T];
        for (auto [w, v]: e[u])
        {
            if (w == 0 && dis[v] > dis[u])
            {
                dis[v] = dis[u];
                q0.push(v);
            }
            else if (dis[v] > dis[u] + 1)
            {
                dis[v] = dis[u] + 1;
                q.push(v);
            }
        }
    }
    return -1;
}

int main()
{
    scanf("%d%d", &n, &m);
    int S = 0, T = 0;
    for (int i = 0; i < 26; ++i)
        portal[i] = -1;
    for (int i = 1; i <= n; ++i)
    {
        scanf("%s", s[i] + 1);
        for (int j = 1; j <= m; ++j)
        {
            if (s[i][j] == '#')
                continue;
            id[i][j] = ++tot;
            //printf("%d %d %d\n", i, j, tot);
            if (s[i][j] == '=')
                T = tot;
            if (s[i][j] == '@')
                S = tot;
            if (isupper(s[i][j]))
            {
                ++tot;
                if (portal[s[i][j] - 'A'] == -1)
                    portal[s[i][j] - 'A'] = (i - 1) * m + j - 1;
            }
        }
    }
    for (int i = 1, nx, ny; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            if (s[i][j] == '#')
                continue;
            if (isupper(s[i][j]))
            {
                for (int k = 0; k < 4; ++k)
                {
                    nx = i + dx[k], ny = j + dy[k];
                    if (nx <= 0 || ny <= 0 || nx > n || ny > m || !id[nx][ny])
                        continue;
                    e[id[i][j] + 1].push_back(P(1, id[nx][ny]));
                    //printf("link %d %d\n", id[i][j] + 1, id[nx][ny]);
                }
                if ((i - 1) * m + j - 1 == portal[s[i][j] - 'A'])
                    continue;
                nx = portal[s[i][j] - 'A'] / m + 1, ny = portal[s[i][j] - 'A'] % m + 1;
                e[id[i][j]].push_back(P(0, id[nx][ny] + 1));
                //printf("elink %d %d %d %d\n", id[i][j] + 1, id[nx][ny], nx, ny);
                e[id[nx][ny]].push_back(P(0, id[i][j] + 1));
                //printf("elink %d %d\n", id[nx][ny] + 1, id[i][j]);
                continue;
            }
            for (int k = 0; k < 4; ++k)
            {
                nx = i + dx[k], ny = j + dy[k];
                if (nx <= 0 || ny <= 0 || nx > n || ny > m || !id[nx][ny])
                    continue;
                e[id[i][j]].push_back(P(1, id[nx][ny]));
                //printf("link %d %d\n", id[i][j], id[nx][ny]);
            }
        }
    }
    printf("%d\n", bfs(S, T));
    return 0;
}
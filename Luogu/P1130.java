/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2022
*/

import java.util.*;
import java.lang.*;
import java.io.*;

public class P1130
{
    public static class graph
    {
        static int head[], to[], next[];
        static int tot;

        public static void init(int n, int m)
        {
            head = new int[n + 1];
            to = new int[m + 1];
            next = new int[m + 1];
            tot = 0;
        }

        public static void add_edge(int u, int v)
        {
            to[++tot] = v;
            next[tot] = head[u];
            head[u] = tot;
        }
    }

    static graph G;
    static int cnt[], color[];

    public static boolean dfs(int u, int cur)
    {
        color[u] = cur; ++cnt[cur];
        int head[] = G.head, to[] = G.to, next[] = G.next;
        boolean res = true;
        for (int c = head[u], v; c != 0; c = next[c])
        {
            v = to[c];
            if (color[v] == -1)
                res &= dfs(v, cur ^ 1);
            else
                res &= color[v] != color[u] ? true : false;
        }
        return res;
    }

    public static void main(String[] args)
    {
        Scanner cin = new Scanner(System.in);
        int n = cin.nextInt(), m = cin.nextInt();
        graph G = new graph();
        G.init(n, m * 2);
        for (int i = 1, u, v; i <= m; ++i)
        {
            u = cin.nextInt(); v = cin.nextInt();
            G.add_edge(u, v); G.add_edge(v, u);
        }
        cnt = new int[2];
        color = new int[n + 1];
        for (int i = 1; i <= n; ++i)
            color[i] = -1;
        int ans = 0;
        for (int i = 1; i <= n; ++i)
        {
            if (color[i] != -1)
                continue;
            if (dfs(i, 0))
            {
                ans += Math.min(cnt[0], cnt[1]);
                cnt[0] = 0; cnt[1] = 0;
            }
            else
            {
                ans = -1;
                break;
            }
        }
        System.out.println(ans == -1 ? "Impossible" : ans);
    }
}
/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2022
*/

import java.util.*;
import java.lang.*;
import java.io.*;

public class P1126
{
    public static class state
    {
        int x, y, dir;

        state() {}

        state(int x, int y, int dir)
        {
            this.x = x;
            this.y = y;
            this.dir = dir;
        }
        
        state(state S)
        {
            this(S.x, S.y, S.dir);
        }

        public void copy(state S)
        {
            S.x = x; S.y = y; S.dir = dir;
        }

        public boolean equals(state S)
        {
            return S.x == x && S.y == y && S.dir == dir;
        }

        public void print()
        {
            System.out.println(x + " " + y + " " + dir);
        }
    }

    public static int bfs(int[][] a, state S, int tx, int ty)
    {
        Queue<state> q = new LinkedList<state>();
        q.offer(S);
        final int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0}, lock[] = {2, 3, 0, 1};
        int n = a.length - 1, m = a[0].length - 1, x, y, dir, nx, ny;
        int dis[][][] = new int[n + 1][m + 1][4];
        state pre[][][] = new state[n + 1][m + 1][4];
        state cur = new state(S); 
        dis[cur.x][cur.y][cur.dir] = 1;
        while (q.peek() != null)
        {
            q.poll().copy(cur);
            x = cur.x; y = cur.y; dir = cur.dir;
            if (x == tx && y == ty)
            {
                // int nd, d = dir;
                // while (!S.equals(pre[x][y][d]))
                // {
                //     pre[x][y][d].print();
                //     nx = pre[x][y][d].x;
                //     ny = pre[x][y][d].y;
                //     nd = pre[x][y][d].dir;
                //     x = nx; y = ny; d = nd;
                // }
                return dis[tx][ty][dir] - 1;
            }
            for (int i = 0; i < 4; ++i)
            {
                if (dis[x][y][i] != 0 || lock[dir] == i)
                    continue;
                if (q.offer(new state(x, y, i)) == false)
                    System.out.println("not");
                pre[x][y][i] = new state(cur);
                dis[x][y][i] = dis[x][y][dir] + 1;
            }
            nx = x + dx[dir]; ny = y + dy[dir];
            if (nx <= 0 || ny <= 0 || nx >= n || ny >= m || a[nx][ny] == 1)
                continue;
            if (dis[nx][ny][dir] == 0)
            {
                pre[nx][ny][dir] = new state(cur);
                dis[nx][ny][dir] = dis[x][y][dir] + 1;
                if (q.offer(new state(nx, ny, dir)) == false)
                    System.out.println("not");
            }
            nx += dx[dir]; ny += dy[dir];
            if (nx <= 0 || ny <= 0 || nx >= n || ny >= m || a[nx][ny] == 1)
                continue;
            if (dis[nx][ny][dir] == 0)
            {
                pre[nx][ny][dir] = new state(cur);
                dis[nx][ny][dir] = dis[x][y][dir] + 1;
                if (q.offer(new state(nx, ny, dir)) == false)
                    System.out.println("not");
            }
            nx += dx[dir]; ny += dy[dir];
            if (nx <= 0 || ny <= 0 || nx >= n || ny >= m || a[nx][ny] == 1)
                continue;
            if (dis[nx][ny][dir] == 0)
            {
                pre[nx][ny][dir] = new state(cur);
                dis[nx][ny][dir] = dis[x][y][dir] + 1;
                if (q.offer(new state(nx, ny, dir)) == false)
                    System.out.println("not");
            }
        }
        return -1;
    }

    public static void main(String[] args)
    {
        Scanner cin = new Scanner(System.in);
        int n = cin.nextInt(), m = cin.nextInt();
        int a[][] = new int[n + 1][m + 1];
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j)
                a[i][j] = cin.nextInt();
        for (int i = 1; i < n; ++i)
            for (int j = 1; j < m; ++j)
                a[i][j] = a[i][j] | a[i + 1][j] | a[i][j + 1] | a[i + 1][j + 1];
        int sx = cin.nextInt(), sy = cin.nextInt();
        int tx = cin.nextInt(), ty = cin.nextInt();
        int dir = 0;
        switch(cin.next().charAt(0))
        {
            case 'E':
                dir = 0;
                break;
            case 'S':
                dir = 1;
                break;
            case 'W':
                dir = 2;
                break;
            case 'N':
                dir = 3;
                break;
        }
        state S = new state(sx, sy, dir);
        System.out.println(bfs(a, S, tx, ty));
    }
}
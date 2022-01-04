/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2022
*/

import java.util.*;
import java.lang.*;
import java.io.*;

public class P1189
{
    final static int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};

    public static void dfs(char[][] road, boolean vis[][][], int[] d, int x, int y, int step)
    {
        if (vis[x][y][step])
            return;
        vis[x][y][step] = true;
        int nx = x + dx[d[step]], ny = y + dy[d[step]];
        int n = road.length - 1, m = road[0].length - 1, q = vis[0][0].length - 1;
        if (nx > 0 && nx <= n && ny > 0 && ny <= m && road[nx][ny] != 'X')
        {
            dfs(road, vis, d, nx, ny, step);
            if (step == q)
                road[nx][ny] = '*';
            else
                dfs(road, vis, d, nx, ny, step + 1);
        }
    }

    public static void main(String[] args)
    {
        Scanner cin = new Scanner(System.in);
        int n = cin.nextInt(), m = cin.nextInt();
        String s = new String();
        char road[][] = new char[n + 1][m + 1];
        int sx = 0, sy = 0;
        for (int i = 1; i <= n; ++i)
        {
            s = cin.next();
            for (int j = 0; j < m; ++j)
            {
                road[i][j + 1] = s.charAt(j);
                if (s.charAt(j) == '*')
                {
                    road[i][j + 1] = '.';
                    sx = i; sy = j + 1;
                }
            }
        }
        int q = cin.nextInt();
        int d[] = new int[q + 1];
        boolean vis[][][] = new boolean[n + 1][m + 1][q + 1];
        for (int i = 1; i <= q; ++i)
        {
            switch (cin.next().charAt(0))
            {
                case 'N':
                    d[i] = 0;
                    break;
                case 'S':
                    d[i] = 1;
                    break;
                case 'W':
                    d[i] = 2;
                    break;
                case 'E':
                    d[i] = 3;
                    break;
            }
        }
        dfs(road, vis, d, sx, sy, 1);
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= m; ++j)
            {
                System.out.print(road[i][j]);
            }
            System.out.println();
        }
    }
}
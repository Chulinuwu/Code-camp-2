#include <bits/stdc++.h>

using namespace std;

char a[1010][1010];
int dist[1010][1010],di[4]= {0,0,1,-1},dj[4] = {1,-1,0,0};

queue <pair<int,int>> bfs;

void solve()
{

    int r,c,i,j,ii,jj,k,d,ans;

    scanf("%d %d", &r, &c);
    memset(dist,-1,sizeof dist);

    for(i = 0 ; i < r ; i++)
    {
        for(j = 0 ; j < c ; j++)
        {
            scanf(" %c", &a[i][j]);
            if(a[i][j] == 'E')
            {
                bfs.push({i,j}),dist[i][j] = 0;
            }
        }
    }

    d = -1;

    while(!bfs.empty())
    {
        i = bfs.front().first;
        j = bfs.front().second;

        bfs.pop();

        for(k = 0 ; k < 4 ; k++)
        {
            ii = i + di[k], jj = j + dj[k];
            if(ii < 0 || jj < 0 || ii >= r || jj >= c)
            {
                continue;
            }
            if(a[ii][jj] == '#' || dist[ii][jj] != -1)
            {
                continue;
            }
            dist[ii][jj] = dist[i][j] + 1;
            if(a[ii][jj] == 'S')
            {
                d = dist[ii][jj];
            }
            bfs.push({ii,jj});
        }
    }

    ans = 0;

    for(i = 0 ; i < r ; i++)
    {
        for(j = 0 ; j < c ; j++)
        {
            if(dist[i][j] != -1 && dist[i][j] <= d && isdigit(a[i][j]))
            {
                ans += a[i][j] - '0';
            }
        }
    }

    if(d== -1)
    {
        printf("-1\n");
    }
    else
    {
        printf("%d\n", ans);
    }
}

int main()
{
    int q;

    scanf("%d", &q);

    while(q--)
    {
        solve();
    }

    return 0;
}

/*
2
5 7
000E0#3
#0##0#0
050#0#0
4#0#0#0
0#0S000
1 4
SE69
*/

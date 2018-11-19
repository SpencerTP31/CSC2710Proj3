// Spencer Day
// Spencer Peters
#include <iostream>
#include<iomanip>
#include <climits>
#define INT_MAX 2000;

using namespace std;

void load(int w[][64], int&, int&, int e[][64], int&);
void floyd2(int, int w[][64], int d[][64], int P[][64]);
void path(int, int, int P[][64]);


int main()
{
    int n, m, p;
    int w[64][64], d[64][64], P[64][64], e[64][64];
    load(w, n, m, e, p);
    floyd2(n, w, d, P);

    for (int i = 1; i <= p; ++i)
    {
        cout << "Path from v" << e[i][1] << " to v" << e[i][2] << " ==>" << " v" << e[i][1] << " ";
        path(e[i][1], e[i][2], P);
        cout << "v" << e[i][2] << '\n';
    }
    return 0;
}

void load (int w[][64], int& n, int& m, int e[][64], int& p)
{
    char let;
    int one, two, value;
    cin >> n;
    cin >> m;
    for (int k = 1; k <= n ; ++k)
    {
        for (int x = 1; x <= n ; ++x)
        {
            w[k][x]=INT_MAX;
        }
    }
    for (int i = 1; i <= m; ++i)
    {
        for (int j = 1; j < 2; ++j)
        {
            cin >> let;
            cin >> one;
            cin >> let;
            cin >> two;
            cin >> value;

        }
        w[one][two] = value;
    }
    cin >> p;
    for (int i = 1; i <= p; ++i)
    {
        for (int j = 1; j <= 2; ++j)
        {
            cin >> let;
            cin >> one;
            e[i][j] = one;

        }
    }
}



void floyd2(int n, int w[][64], int d[][64], int P[][64])
{
    for (int i = 1; i <=n ; ++i)
        for (int j = 1; j <=n ; ++j)
            P[i][j] = 0;
    d=w;
    for (int k = 1; k <=n ; ++k)
        for (int i = 1; i <=n ; ++i)
            for (int j = 1; j <=n ; ++j)
                if (d[i][k] + d[k][j] < d[i][j])
                {
                    P[i][j] = k;
                    d[i][j] = d[i][k] + d[k][j];
                }
}

void path(int q, int r, int P[][64])
{
    if (P[q][r] != 0)
    {
        path(q, P[q][r], P);
        cout << "v" << P[q][r] << " ";
        path(P[q][r], r, P);
    }
}
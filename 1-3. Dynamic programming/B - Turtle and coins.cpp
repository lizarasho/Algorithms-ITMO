#include <algorithm>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<vector<char>> how;
vector<vector<int>> c;
vector<vector<int>> dp;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n, m;
    cin >> n >> m;

    how.resize(n, vector<char>(m));
    c.resize(n, vector<int>(m));
    dp.resize(n, vector<int>(m));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> c[i][j];

    dp[0][0] = c[0][0];

    for (int i = 1; i < n; i++)
    {
        dp[i][0] = dp[i - 1][0] + c[i][0];
        how[i][0] = 'D';
    }
    for (int i = 1; i < m; i++)
    {
        dp[0][i] = dp[0][i - 1] + c[0][i];
        how[0][i] = 'R';
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            if (dp[i - 1][j] > dp[i][j - 1])
            {
                how[i][j] = 'D';
                dp[i][j] = c[i][j] + dp[i - 1][j];
                continue;
            }
            how[i][j] = 'R';
            dp[i][j] = c[i][j] + dp[i][j - 1];
        }
    }

    cout << dp[n - 1][m - 1] << '\n';

    vector<char> way;
    int i = n - 1;
    int j = m - 1;
    while (i > 0 || j > 0)
    {
        way.push_back(how[i][j]);
        if (how[i][j] == 'D')
        {
            i--;
            continue;
        }
        j--;
    }

    for (int k = way.size() - 1; k >= 0; k--)
        cout << way[k];

    return 0;
}

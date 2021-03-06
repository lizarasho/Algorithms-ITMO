#include <iostream>
#include <vector>

using namespace std;

int main()
{
    string s;
    cin >> s;

    vector<int> pr(s.size() + 1);
    pr[0] = -1;

    for (int i = 1; i < s.size() + 1; i++) {
        for (int k = pr[i - 1]; ; k = pr[k]) {
            if (k == -1 || s[k] == s[i - 1]) {
                pr[i] = k + 1;
                break;
            }
        }
    }

    auto n = s.size();
    auto k = pr[s.size()];

    cout << (s.size() % (n - k) == 0 ? n - k : s.size());

    return 0;
}
#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
int t, ans;
char s[112345];
map<char, pair<int, int>> mmp;

int main() {
    cin >> t;
    mmp['A'] = mmp['B'] = mmp['C'] = make_pair(1, 2);
    mmp['D'] = mmp['E'] = mmp['F'] = make_pair(1, 3);
    mmp['G'] = mmp['H'] = mmp['I'] = make_pair(2, 1);
    mmp['J'] = mmp['K'] = mmp['L'] = make_pair(2, 2);
    mmp['M'] = mmp['N'] = mmp['O'] = make_pair(2, 3);
    mmp['P'] = mmp['Q'] = mmp['R'] = mmp['S'] = make_pair(3, 1);
    mmp['T'] = mmp['U'] = mmp['V'] = make_pair(3, 2);
    mmp['W'] = mmp['X'] = mmp['Y'] = mmp['Z'] = make_pair(3, 3);
    while (t--) {
        cin >> s;
        ans = 0;
        pair<int, int> a = make_pair(1, 1);
        for (int i = 0; s[i]; i++) {
            ans += abs(mmp[s[i]].first - a.first) + abs(mmp[s[i]].second - a.second);
            a = mmp[s[i]];
        }
        cout << ans << endl;
    }
    return 0;
}
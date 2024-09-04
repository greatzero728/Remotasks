#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#else
//	freopen(".in", "r", stdin);
//	freopen(".out", "w", stdout);
#endif
	
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<string> words;
    string wtf;
    getline(cin, wtf);
    for (int i = 0; i < n; ++i) {
        string s;
        getline(cin, s);
        for (int x = 0, y; x < s.size();) {
            if (s[x] == ' ') {
                ++x;
                continue;
            }
            y = x;
            while (y < s.size() && s[y] != ' ') {
                ++y;
            }
            string word(s.begin() + x, s.begin() + y);
            x = y;
            if (y != s.size())
                words.push_back(word);
        }
    }
    auto check = [&](int mid) {
        vector<int> left(mid, 280);
        int sz = to_string(mid).size();
        for (int i = 1; i <= mid; ++i) {
            left[i - 1] -= 2 + to_string(i).size() + sz + 1;
            if (left[i - 1] < 0) {
                return false;
            }
        }
        int pnt = 0;

        for (int i = 0; i < words.size(); ++i) {
            while (pnt < mid && left[pnt] < words[i].size() + 1) {
                ++pnt;
            }
            if (pnt == mid) {
                return false;
            }
            left[pnt] -= words[i].size() + 1;
        }
        return true;
    };
    int low = 0, high = n;
    while (low + 1 < high) {
        int mid = (low + high) >> 1;
        if (check(mid)) {
            high = mid;
        } else {
            low = mid;
        };
    }
    int mid = high;
    vector<int> left(n, 280);
    int sz = to_string(mid).size();
    for (int i = 1; i <= mid; ++i) {
        left[i - 1] -= 2 + to_string(i).size() + sz + 1;
        if (left[i - 1] < 0) {
            assert(false);
        }
    }
    int pnt = 0;
    
    cout << mid << '\n';

    for (int i = 0; i < words.size(); ++i) {
        while (pnt < mid && left[pnt] < words[i].size() + 1) {
            cout << "(" << (pnt + 1) << "/" << mid << ")\n";
            ++pnt;
        }
        if (pnt == mid) {
            assert(false);
        }
        cout << words[i] << " ";
        left[pnt] -= words[i].size() + 1;
    }
    cout << "(" << mid << "/" << mid << ")";
    return 0;
}
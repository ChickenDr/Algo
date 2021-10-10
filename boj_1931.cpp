#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

pair<int, int> pair_min(vector<pair<int, int>> x) {
    return *min_element(x.begin(), x.end(), [](auto i, auto j) {
        return i.second < j.second;
    });
}

bool compare(pair<int, int>a, pair<int, int>b) {
    if (a.second == b.second) return a.first < b.first;
    return a.second < b.second;
}

int main() {
    int a, cnt = 1;
    vector<pair<int, int>> meet;

    cin >> a;

    for (int x = 0; x < a; x++) {
        int i, j;
        cin >> i >> j;
        meet.push_back(make_pair(i, j));
    }

    sort(meet.begin(), meet.end(), compare);
    pair<int, int> min = meet[0];

    for (int i = 1; i < a; i++) {
        if (meet[i].first >= min.second) {
            min = meet[i];
            cnt++;
        }
    }

    cout << cnt;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

struct TitanShifter {
    int pp1, pp2, ff1, ff2;
    TitanShifter() {}
    TitanShifter(int p1, int p2, int f1, int f2) {
        pp1 = p1, pp2 = p2, ff1 = f1, ff2 = f2;
    }
};

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> v(n);
    for (int &p : v) cin >> p;

    vector<TitanShifter> tree(4 * n);

    auto combine = [&](TitanShifter d1, TitanShifter d2) {
        int pp1 = 0, pp2 = 0, ff1 = 0, ff2 = 0;
        for (TitanShifter d : {d1, d2}) {
            if (d.pp1 == pp1) ff1 += d.ff1;
            else if (d.pp1 > pp1) pp2 = pp1, ff2 = ff1, pp1 = d.pp1, ff1 = d.ff1;
            else if (d.pp1 == pp2) ff2 += d.ff1;
            else if (d.pp1 > pp2) pp2 = d.pp1, ff2 = d.ff1;

            if (d.pp2 == pp1) ff1 += d.ff2;
            else if (d.pp2 > pp1) pp2 = pp1, ff2 = ff1, pp1 = d.pp2, ff1 = d.ff2;
            else if (d.pp2 == pp2) ff2 += d.ff2;
            else if (d.pp2 > pp2) pp2 = d.pp2, ff2 = d.ff2;
        }
        return TitanShifter(pp1, pp2, ff1, ff2);
    };

    function<void(int, int, int)> build = [&](int node, int low, int high) {
        if (low == high) {
            tree[node] = TitanShifter(v[low], 0, 1, 0);
            return;
        }
        int mid = low + (high - low) / 2;
        build(node << 1, low, mid);
        build(node << 1 | 1, mid + 1, high);
        tree[node] = combine(tree[node << 1], tree[node << 1 | 1]);
    };

    function<void(int, int, int, int, int)> modify = [&](int node, int low, int high, int index, int value) {
        if (low == high) {
            tree[node] = TitanShifter(value, 0, 1, 0);
            return;
        }
        int mid = low + (high - low) / 2;
        if (index <= mid) modify(node << 1, low, mid, index, value);
        else modify(node << 1 | 1, mid + 1, high, index, value);
        tree[node] = combine(tree[node << 1], tree[node << 1 | 1]);
    };

    function<TitanShifter(int, int, int, int, int)> query = [&](int node, int low, int high, int qlow, int qhigh) {
        if (high < qlow || low > qhigh) return TitanShifter(0, 0, 0, 0);
        if (low >= qlow && high <= qhigh) return tree[node];
        int mid = low + (high - low) / 2;
        return combine(query(node << 1, low, mid, qlow, qhigh), query(node << 1 | 1, mid + 1, high, qlow, qhigh));
    };

    build(1, 0, n - 1);

    while (q--) {
        int operation, position, newValue;
        cin >> operation >> position >> newValue;
        if (operation == 1) {
            modify(1, 0, n - 1, position - 1, newValue);
        } else {
            int count = query(1, 0, n - 1, position - 1, newValue - 1).ff2;
            cout << count << endl;
        }
    }

    return 0;
}

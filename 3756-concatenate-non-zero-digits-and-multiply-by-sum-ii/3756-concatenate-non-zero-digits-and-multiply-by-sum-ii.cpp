class Solution {
public:
    static const int MOD = 1e9 + 7;

    struct Node {
        long long num;
        int len;
    };

    vector<Node> seg;
    vector<long long> pow10, pref;
    string s;

    Node merge(Node a, Node b) {
        return {
            (a.num * pow10[b.len] + b.num) % MOD,
            a.len + b.len
        };
    }

    void build(int idx, int l, int r) {
        if (l == r) {
            if (s[l] == '0')
                seg[idx] = {0, 0};
            else
                seg[idx] = {s[l] - '0', 1};
            return;
        }

        int mid = (l + r) / 2;
        build(2 * idx, l, mid);
        build(2 * idx + 1, mid + 1, r);

        seg[idx] = merge(seg[2 * idx], seg[2 * idx + 1]);
    }

    Node query(int idx, int l, int r, int ql, int qr) {
        if (qr < l || r < ql)
            return {0, 0};

        if (ql <= l && r <= qr)
            return seg[idx];

        int mid = (l + r) / 2;

        Node left = query(2 * idx, l, mid, ql, qr);
        Node right = query(2 * idx + 1, mid + 1, r, ql, qr);

        return merge(left, right);
    }

    vector<int> sumAndMultiply(string str, vector<vector<int>>& queries) {
        s = str;
        int n = s.size();

        seg.resize(4 * n + 5);

        pow10.resize(n + 1);
        pow10[0] = 1;
        for (int i = 1; i <= n; i++)
            pow10[i] = (pow10[i - 1] * 10) % MOD;

        pref.assign(n + 1, 0);
        for (int i = 0; i < n; i++) {
            pref[i + 1] = pref[i];
            if (s[i] != '0')
                pref[i + 1] += (s[i] - '0');
        }

        build(1, 0, n - 1);

        vector<int> ans;
        for (auto &q : queries) {
            Node cur = query(1, 0, n - 1, q[0], q[1]);
            long long sum = pref[q[1] + 1] - pref[q[0]];
            ans.push_back((cur.num * sum) % MOD);
        }

        return ans;
    }
};
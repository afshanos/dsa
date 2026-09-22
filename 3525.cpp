class Solution {
    struct Node {
        int cnt[5];
        int prod;

        Node() {
            memset(cnt, 0, sizeof(cnt));
            prod = 1;
        }
    };

    int n, K;
    vector<Node> tree;
    vector<int> arr;

    Node merge(const Node& left, const Node& right) {
        Node res;
        res.prod = (left.prod * right.prod) % K;

        for (int r = 0; r < K; r++) {
            res.cnt[r] += left.cnt[r];
        }

        for (int r = 0; r < K; r++) {
            int new_r = (left.prod * r) % K;
            res.cnt[new_r] += right.cnt[r];
        }

        return res;
    }

    void build(int node, int start, int end) {
        if (start == end) {
            int val = arr[start] % K;
            tree[node].prod = val;
            tree[node].cnt[val] = 1;
            return;
        }
        int mid = start + (end - start) / 2;
        build(2 * node, start, mid);
        build(2 * node + 1, mid + 1, end);
        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }

    void update(int node, int start, int end, int idx, int val) {
        if (start == end) {
            int v = val % K;
            tree[node] = Node();
            tree[node].prod = v;
            tree[node].cnt[v] = 1;
            return;
        }
        int mid = start + (end - start) / 2;
        if (idx <= mid) {
            update(2 * node, start, mid, idx, val);
        } else {
            update(2 * node + 1, mid + 1, end, idx, val);
        }
        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }

    Node query(int node, int start, int end, int l, int r) {
        if (r < start || end < l) {
            Node emptyNode;
            emptyNode.prod = 1;
            return emptyNode;
        }
        if (l <= start && end <= r) {
            return tree[node];
        }
        int mid = start + (end - start) / 2;
        Node left = query(2 * node, start, mid, l, r);
        Node right = query(2 * node + 1, mid + 1, end, l, r);
        return merge(left, right);
    }

public:
    vector<int> resultArray(vector<int>& nums, int k, vector<vector<int>>& queries) {
        n = nums.size();
        K = k;
        arr = nums;

        tree.resize(4 * n);
        build(1, 0, n - 1);

        vector<int> ans;
        ans.reserve(queries.size());

        for (const auto& q : queries) {
            int idx = q[0];
            int val = q[1];
            int start = q[2];
            int x = q[3];

            update(1, 0, n - 1, idx, val);

            Node resNode = query(1, 0, n - 1, start, n - 1);
            ans.push_back(resNode.cnt[x]);
        }

        return ans;
    }
};
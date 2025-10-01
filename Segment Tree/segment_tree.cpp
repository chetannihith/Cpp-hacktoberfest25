#include <iostream>
#include <vector>
using namespace std;

class SegmentTree {
    vector<int> tree;
    int n;

public:
    SegmentTree(const vector<int>& arr) {
        n = arr.size();
        tree.resize(4 * n);
        build(arr, 1, 0, n - 1);
    }

    void build(const vector<int>& arr, int node, int start, int end) {
        if (start == end) {
            tree[node] = arr[start];
        } else {
            int mid = (start + end) / 2;
            build(arr, 2*node, start, mid);
            build(arr, 2*node+1, mid+1, end);
            tree[node] = tree[2*node] + tree[2*node+1];
        }
    }

    int query(int node, int start, int end, int l, int r) {
        if (r < start || end < l) return 0; 
        if (l <= start && end <= r) return tree[node]; 
        int mid = (start + end) / 2;
        int left_sum = query(2*node, start, mid, l, r);
        int right_sum = query(2*node+1, mid+1, end, l, r);
        return left_sum + right_sum;
    }

    void update(int node, int start, int end, int idx, int val) {
        if (start == end) {
            tree[node] = val;
        } else {
            int mid = (start + end) / 2;
            if (idx <= mid) update(2*node, start, mid, idx, val);
            else update(2*node+1, mid+1, end, idx, val);
            tree[node] = tree[2*node] + tree[2*node+1];
        }
    }
};

int main() {
    vector<int> arr = {1, 3, 5, 7, 9, 11};
    SegmentTree st(arr);

    cout << "Sum from 1 to 3: " 
         << st.query(1, 0, arr.size()-1, 1, 3) << endl;

    cout << "Updating index 1 to 10..." << endl;
    st.update(1, 0, arr.size()-1, 1, 10);

    cout << "Sum from 1 to 3 after update: " 
         << st.query(1, 0, arr.size()-1, 1, 3) << endl;

    return 0;
}

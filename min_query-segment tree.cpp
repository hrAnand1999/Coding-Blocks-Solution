#include <bits/stdc++.h>
using namespace std;
void buildTree(int *a, int *tree, int ss, int se, int index)
{
    if(ss > se)
    return;
    if(ss == se)
    {
        tree[index] = a[ss];
        return;
    }
    int mid = (ss + se)/2;
    buildTree(a, tree, ss, mid, 2*index);
    buildTree(a, tree, mid + 1, se, 2*index + 1);
    tree[index] = min(tree[2*index], tree[2*index + 1]);
    return;
}
int query(int *tree, int qs, int qe, int ss, int se, int index)
{
    // No Overlap
    if(qe < ss || qs > se)
    return INT_MAX;
    // complete overlap
    if(qs <= ss && qe >= se)
    return tree[index];
    // partial overlap
    int mid = (ss + se)/2;
    int left = query(tree, qs, qe, ss, mid, 2*index);
    int right = query(tree, qs, qe, mid + 1, se, 2*index + 1);
    return min(left, right);
}
void updateNode(int *tree, int ss, int se, int idx, int inc, int index)
{
    if(ss > se)
    return;
    if(idx < ss || idx > se)
    return;
    if(ss == se && ss == idx)
    {
        tree[index] += inc;
        return;
    }
    int mid = (ss + se)/2;
    updateNode(tree, ss, mid, idx, inc, 2*index);
    updateNode(tree, mid + 1, se, idx, inc, 2*index + 1);
    tree[index] = min(tree[2*index], tree[2*index + 1]);
    return;
}
void updateRange(int *tree, int ss, int se, int l, int r, int inc, int index)
{
    if(ss > se)
    return;
    if(l > se || r < ss)
    return;
    if(ss == se)
    {
        tree[index] += inc;
        return;
    }
    int mid = (ss + se)/2;
    updateRange(tree, ss, mid, l, r, inc, 2*index);
    updateRange(tree, mid + 1, se, l, r, inc, 2*index + 1);
    tree[index] = min(tree[2*index], tree[2*index + 1]);
    return;
}
int main() {
    int a[6] = {1, 3, 2, -5, 6, 4};
    int n = sizeof(a)/sizeof(int);
    int tree[4*n + 1];
    buildTree(a, tree, 0, n - 1, 1);
    /*for(auto x : tree)
    {
        cout << x << " ";
    }
    */
    // int idx = 3, inc = 5, index = 1;
    // updateNode(tree, 0, n - 1, idx, inc, index);
    updateRange(tree, 0, n - 1, 3, 5, 10, 1);
    int q;
    cin >> q;
    while(q--)
    {
        int l, r;
        cin >> l >> r;
        cout << query(tree, l, r, 0, n - 1, 1) << endl;
    }
    
    return 0;
}

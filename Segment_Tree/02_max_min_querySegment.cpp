#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 2;
int a[N], tree[4 * N];

void build (int node, int st, int ed)
{
    if (st == ed){
        tree[node] = a[st];
        return;
    }

    int mid = st + (ed-st)/2;
    build(2*node, st,mid);
    build(2*node+1,mid+1,ed);

    tree[node] = max(tree[2*node],tree[2*node+1]);
}

// changing st and ed so st and ed should come in between l and r
int query (int node, int st, int ed, int l, int r)
{
    if (l > ed || r < st) return INT_MIN;
    if (l <= st && r >= ed) return tree[node];  

    int mid = st + (ed-st)/2;

    int left = query(2*node,st,mid,l,r);
    int right = query(2*node+1,mid+1,ed,l,r);

    return max(left, right);
}

void update(int node, int st, int ed, int idx, int val)
{
    if (st == ed){
        a[st] = val;
        tree[node] = val;
        return; 
    }
    int mid = st + (ed-st)/2;

    if(idx <= mid)
        update(2*node,st,mid,idx,val);
    else 
        update(2*node+1,mid+1,ed,idx,val);
    
    tree[node] = max(tree[2*node],tree[2*node+1]);
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    build(1,0,n-1);
    while(1)
    {
        int type;
        cin >> type;
        if(type == -1)
        {
            break;
        }
        else if(type == 1){
            int l, r;
            cin >> l >> r;
            int ans = query(1,0,n-1,l,r);
            cout << ans << endl;
        }
        else if(type == 2){
            int id,val;
            cin >> id >> val;
            update(1,0,n-1,id,val);
            cout << query(1,0,n-1,0,n-1) << endl;
        }
    }
}
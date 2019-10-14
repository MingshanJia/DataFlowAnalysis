//#define __USE_MINGW_ANSI_STDIO 0
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define debug(x) cout<<#x<<" :: "<<x<<endl;
#define debug2(x,y) cout<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<endl;
#define debug3(x,y,z) cout<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<"\t"<<#z<<" :: "<<z<<endl;

#define boost ios::sync_with_stdio(0); cin.tie(0)

#define fi first
#define se second
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)

typedef long long ll;
typedef double ld;
typedef pair<int, int> pii;

const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

/***************************************************************************/

const int TN = 54000007;

// dynamic segment tree
struct Node {
	ll sum, lazy;
	struct Node *left, *right;
} node_pool[TN];
int nc = 0;

// lazy means current node has been updated, but info not propagated to children
void updateLazy(struct Node *root, int la, int ra, int mid) {

	root->left->sum += (mid - la + 1) * root->lazy;
	root->right->sum += (ra - mid) * root->lazy;

	if(la != mid) root->left->lazy += root->lazy;
	if(mid+1 != ra) root->right->lazy += root->lazy;

	root->lazy = 0;
}

void updateRange(struct Node *root, int la, int ra, int l, int r) {

	if(ra < l || r < la) return;

	if(l <= la && ra <= r) {
		if(la != ra) root->lazy++;
		root->sum += ra - la + 1;
		return;
	}

	// create new nodes only when fucking required (heavy mem constraints)
	if(root->left == NULL) {
		root->left = &node_pool[++nc];
		root->right = &node_pool[++nc];
		root->left->sum = root->left->lazy = 0;
		root->right->sum = root->right->lazy = 0;
		root->left->left = root->left->right = 0;
		root->right->left = root->right->right = 0;
	}
	int mid = (la + ra) >> 1;
	if(root->lazy) updateLazy(root, la, ra, mid);

	updateRange(root->left, la, mid, l, r);
	updateRange(root->right, mid+1, ra, l, r);

	root->sum = root->left->sum + root->right->sum;
}

int find_kth(struct Node *root, int la, int ra, ll k) {

	//debug3(la, ra, root->sum);

	if(la == ra) return la;
	if(root->left == NULL) {
		root->left = &node_pool[++nc];
		root->right = &node_pool[++nc];
		root->left->sum = root->left->lazy = 0;
		root->right->sum = root->right->lazy = 0;
		root->left->left = root->left->right = 0;
		root->right->left = root->right->right = 0;
	}
	int mid = (la + ra) >> 1;
	if(root->lazy) updateLazy(root, la, ra, mid);

	if(k <= root->right->sum) return find_kth(root->right, mid+1, ra, k);
	else return find_kth(root->left, la, mid, k-root->right->sum);
}

ll X[N], Y[N], Z[N];

int main() {

	boost;
	int T; cin>>T;
	for(int test=1; test<=T; test++) {
		int n, q; cin>>n>>q;

   	 	ll X1, X2, A1, B1, C1, M1;
    	ll Y1, Y2, A2, B2, C2, M2;
    	ll Z1, Z2, A3, B3, C3, M3;

    	cin>>X1>>X2>>A1>>B1>>C1>>M1;
    	cin>>Y1>>Y2>>A2>>B2>>C2>>M2;
    	cin>>Z1>>Z2>>A3>>B3>>C3>>M3;

    	X[1] = X1, X[2] = X2;
    	Y[1] = Y1, Y[2] = Y2;
    	Z[1] = Z1, Z[2] = Z2;

    	for(int i=3; i<=n; i++) {
    		X[i] = (A1 * X[i - 1] + B1 * X[i - 2] + C1) % M1;
    		Y[i] = (A2 * Y[i - 1] + B2 * Y[i - 2] + C2) % M2;
    	}

    	for(int i=3; i<=q; i++) {
    		Z[i] = (A3 * Z[i - 1] + B3 * Z[i - 2] + C3) % M3;
    	}

    	nc = 0;
    	struct Node * root = &node_pool[++nc];
    	root->sum = root->lazy = 0;
    	root->left = root->right = 0;


    	for(int i=1; i<=n; i++) {
    		int l = min(X[i], Y[i]) + 1;
    		int r = max(X[i], Y[i]) + 1;
    		updateRange(root, 0, MOD, l, r);
    		//debug3(l, r, root->sum);
    	}

    	ll cnt = 0;

    	for(int i=1; i<=q; i++) {
    		int k = Z[i] + 1;
    		ll ans = find_kth(root, 0, MOD, k);
    		cnt += i * ans;
    	}

    	cout<<"Case #"<<test<<": ";
    	cout<<cnt<<"\n";
	}
	
	return 0;
}
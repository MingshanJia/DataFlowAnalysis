#include <stdio.h>
#include <iostream>
#include <string>
#include <unordered_map>
#include <queue>
using namespace std;
#define N 500
struct edge {
    int from;
    int to;
    int next;
};
int top = 0;
edge data[N] = {};
int head[N] = {};
unordered_map<string, int> id;
int n = 0;
int color[N] = {};
void addEdge(int from, int to) {
    data[top].from = from;
    data[top].to = to;
    data[top].next = head[from];
    head[from] = top;
    top++;
}

bool split(int n) {
    queue<int> q;
    for(int i = 0; i < n; i++) {
	if(color[i] == 0) {
	    color[i] = 1;
	}
	q.push(i);
	while(!q.empty()) {
	    int t = q.front();
	    q.pop();
	    for(int e = head[t]; e != -1; e = data[e].next) {
		if(color[data[e].to] != 0) {
		    if(color[data[e].to] == color[t]) {
			return false;
		    }	
		}
		else {
		    color[data[e].to] = color[t]*-1;
		    q.push(data[e].to);
		}
	    }
	}
    }
    return true;
}

int main() {
    int t;
    scanf("%d", &t);
    for(int x = 1; x <= t; x++) {
	int m;
	scanf("%d", &m);
	id.clear();
	top = 0;
	n = 0;
	memset(head, -1, sizeof(head));
	memset(color, 0, sizeof(color));
	for(int i = 0; i < m; i++) {
	    string a, b;
	    cin >> a >> b;
	    if(id.find(a) == id.end()) {
		id[a] = n;
		n++;
	    }
	    if(id.find(b) == id.end()) {
		id[b] = n;
		n++;
	    }
	    addEdge(id[a], id[b]);
	    addEdge(id[b], id[a]);
	}
	if(split(n)) {
	    printf("Case #%d: Yes\n", x);
	}
	else {
	    printf("Case #%d: No\n", x);
	}
    }
}

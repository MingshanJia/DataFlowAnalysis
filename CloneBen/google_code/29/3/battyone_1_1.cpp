#include "std.h"

#define Y 11

int main() {
  int n;
  cin >> n;
  FOR(t, n) {
    string p1, p2;
    cin >> p1 >> p2;
    map<int, int> m;
    int dy[4] = {1, 0, -1, 0}, dx[4] = {0, 1, 0, -1};
    int y = Y-1, x = 0, d = 0;
    int miny = Y, minx = 0;
    int maxy = Y, maxx = 0;
    int nw = 0;
    FOR(i, p1.size()) {
      switch(p1[i]) {
      case 'W': {
	// may not go left from here
	if (i) m[y*99999+x] |= (1<<d);
	y += dy[d];
	x += dx[d];
	if (i+1<p1.size()) {
	  miny <?= y; minx <?= x;
	  maxy >?= y; maxx >?= x;
	  int dd = (d+2)%4;
	  m[y*99999+x] |= (1<<(dd+4));
	  nw++;
	}
	break;
      }
      case 'L': {
	d = (d+1)%4; break;
      }
      case 'R': {
	d = (d+3)%4; break;
      }
      }
    }
    cerr << "exited at "<<y << ' ' << x <<endl;
    d = (d+2)%4;
    FOR(i, p2.size()) {
      switch(p2[i]) {
      case 'W': {
	if (i) {
	  assert((m[y*99999+x] & (1<<d)) == 0);
	  m[y*99999+x] |= (1<<d);
	}
	y += dy[d];
	x += dx[d];
	if (i+1<p2.size()) {
	  miny <?= y; minx <?= x;
	  maxy >?= y; maxx >?= x;
	  int dd = (d+2)%4;
	  m[y*99999+x] |= (1<<(dd+4));
	  nw++;
	}
	break;
      }
      case 'L': {
	d = (d+1)%4; break;
      }
      case 'R': {
	d = (d+3)%4; break;
      }
      }
    }
    cerr << "exited2 at "<<y << ' ' << x <<endl;
    assert(y==Y-1&&x==0);
    cerr << "miny=" << miny << " x="<<minx<<endl;
    assert(miny == Y);
    cerr << "maxy=" << maxy << " x="<<maxx<<endl;
    cerr << "map size=" << m.size()<< "="<<(1+maxy-miny)<<'x'<<(1+maxx-minx)<< endl;
    cout << "Case #"<<(t+1)<<":"<<endl;
    int nb = 0;
    for(int y = miny; y <= maxy; y++) {
      for(int x = minx; x <= maxx; x++) {
	int c = m[y*99999+x];
	assert(c);
	assert((c&0xF) == (c>>4));
	int d = 0;
	if (c & 1) d |= 2, nb++;
	if (c & 2) d |= 8, nb++;
	if (c & 4) d |= 1, nb++;
	if (c & 8) d |= 4, nb++;
	if (d < 10) cout << char(d+'0');
	else cout << char(d-10+'a');
      }
      cout << endl;
    }
    cerr << "total openings = " << nb << endl;
    assert(nb == nw);
    assert(nb == 2*m.size());
  }
  return 0;
}

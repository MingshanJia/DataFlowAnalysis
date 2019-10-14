#include <iostream>
#include <iterator>
#include <list>
using namespace std;

struct Cards
{
  long a, n;
  Cards(long a, long n) : a(a), n(n) {}
};
ostream& operator<< (ostream& os, const Cards& c) {
  os << "#";
  for (long i = c.n; i < c.n + c.a; i++) os << i << ",";
  return os;
}

int main(void)
{
  long T; cin >> T;
  for (long index = 1; index <= T; index++) {
    long M, C, W; cin >> M >> C >> W;
    W--;
    list<Cards> deck;
    deck.push_back(Cards(M, 1));

    for (long i = 0; i < C; i++) {
      long A, B; cin >> A >> B;
      A--;
      B += A;
      list<Cards>::iterator itb, ite;
      long j = 0;
      for (itb = deck.begin(); itb != deck.end(); itb++) {
        if (j <= A && A < j + itb->a) {
          if (j != A) {
            list<Cards>::iterator it = itb;
            it++;
            deck.insert(it, Cards(itb->a - (A - j), itb->n + (A - j)));
            itb->a = A - j;
            itb++;
            j = A;
          }
          break;
        }
        j += itb->a;
      }
      for (ite = itb; ite != deck.end(); ite++) {
        if (j <= B && B < j + ite->a) {
          if (j + ite->a != B) {
            deck.insert(ite, Cards(B - j, ite->n));
            ite->n += B - j;
            ite->a -= B - j;
            if (itb == ite) itb--;
          }
          break;
        }
        j += ite->a;
      }
      deck.insert(deck.begin(), itb, ite);
      deck.erase(itb, ite);
      //copy(deck.begin(), deck.end(), ostream_iterator<Cards>(cout, "\n"));
      //cout << endl;
    }
    cout << "Case #" << index << ": ";
    long j = 0;
    for (list<Cards>::iterator it = deck.begin(); it != deck.end(); it++) {
      if (j <= W && W < j + it->a) {
        cout << it->n + W - j << endl;
        break;
      }
      j += it->a;
    }
  }
}

#include <iostream>
#include <vector>
#include <deque>
#include <queue>
#include <algorithm>
using namespace std;

struct Coffee {
  long c, t, s;
  bool operator< (const Coffee& c) const {
    return this->t < c.t;
  }
};
bool comp(const Coffee& a, const Coffee& b) {
  return a.s < b.s;
}

int main(void)
{
  long T; cin >> T;
  for (long index = 1; index <= T; index++) {
    long N, K; cin >> N >> K;
    priority_queue<Coffee> pq;
    for (long i = 0; i < N; i++) {
      Coffee c;
      cin >> c.c >> c.t >> c.s;
      pq.push(c);
    }

    deque<Coffee> coffees;
    long result = 0;
    long day_end = min(pq.top().t, K);
    while (!pq.empty()) {
      long day_begin;
      while (!pq.empty() && pq.top().t == day_end) {
        coffees.push_back(pq.top()); pq.pop();
      }
      day_begin = (pq.empty() ? 0 : pq.top().t);
      while (day_begin != day_end && !coffees.empty()) {
        deque<Coffee>::iterator it = max_element(coffees.begin(), coffees.end(), comp);
        long d = min(day_end - day_begin, it->c);
        result += it->s * d;
        it->c -= d;
        day_end -= d;
        if (it->c == 0) coffees.erase(it);
      }
      day_end = day_begin;
    }
    cout << "Case #" << index << ": ";
    cout << result << endl;
  }
}

#include <iostream>
#include <vector>
#include <cassert>
#include <iomanip>
using namespace std;

struct Event {
	double probability, dist;
	Event(double p = 0, double d = 0) : probability(p), dist(d) {}
};

Event sum(const Event& a, const Event& b) {
	Event res;
	res.probability = a.probability + b.probability;
	if (res.probability > 0) {
		res.dist = a.dist * a.probability + b.dist * b.probability;
		res.dist /= res.probability;
	} else {
		res.dist = 0;
	}
	return res;
}

Event mul(const Event& a, const Event& b) {
	Event res;
	res.probability = a.probability * b.probability;
	res.dist = a.dist + b.dist;
	return res;
}

class SquareMatrix {
	int size;
	vector<vector<Event>> data;
public:
	SquareMatrix(int size) : size(size) {
		data = vector<vector<Event>>(size, vector<Event>(size, Event(0, 0)));
	}
	void init() {
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				if (i == j) {
					data[i][j] = Event(1, 0);
				} else {
					data[i][j] = Event(0, 0);
				}
			}
		}
	}
	SquareMatrix operator*(const SquareMatrix& a) const {
		assert(size == a.size);
		SquareMatrix res(size);
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				Event temp;
				for (int k = 0; k < size; k++) {
					temp = sum(temp, mul(data[i][k], a.data[k][j]));
				}
				res.data[i][j] = temp;
			}
		}
		return res;
	}
	vector<Event> operator*(const vector<Event>& a) const {
		assert(size == a.size());
		vector<Event> res;
		res.reserve(size);
		for (int i = 0; i < size; i++) {
			Event temp;
			for (int j = 0; j < size; j++) {
				temp = sum(temp, mul(data[i][j], a[j]));
			}
			res.push_back(temp);
		}
		return res;
	}
	void set(int i, int j, Event e) {
		assert(i >= 0 && i < size && j >= 0 && j < size);
		data[i][j] = e;
	}
	int getSize() const {
		return size;
	}
};

SquareMatrix fastpow(SquareMatrix base, long long pow) {
	SquareMatrix res(base.getSize());
	res.init();
	while (pow) {
		if (pow & 1) {
			res = res * base;
		}
		base = base * base;
		pow >>= 1;
	}
	return res;
}

int dist[100][100];

int main() {
	int T;
	cin >> T;
	for (int cas = 1; cas <= T; cas++) {
		int N, M;
		long long P;
		cin >> N >> M >> P;
		memset(dist, -1, sizeof(dist));
		for (int i = 0; i < M; i++) {
			int u, v, d;
			cin >> u >> v >> d;
			u--; v--;
			if (dist[u][v] == -1 || dist[u][v] > d) {
				dist[u][v] = dist[v][u] = d;
			}
		}
		for (int k = 0; k < N; k++) {
			for (int i = 0; i < N; i++) {
				if (i == k || dist[i][k] == -1) continue;
				for (int j = 0; j < N; j++) {
					if (j == k || j == i || dist[k][j] == -1) continue;
					if (dist[i][j] == -1 || dist[i][j] > dist[i][k] + dist[k][j]) {
						dist[i][j] = dist[i][k] + dist[k][j];
					}
				}
			}
		}
		SquareMatrix transist(N);
		double transistProbability = 1.0 / (N - 1);
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (i == j) {
					transist.set(i, j, Event(0, 0));
				} else {
					transist.set(i, j, Event(transistProbability, dist[i][j]));
				}
			}
		}
		SquareMatrix totalTransist = fastpow(transist, P);
		vector<Event> initialEvents(N, Event(0, 0));
		initialEvents[0] = Event(1, 0);
		vector<Event> finalEvents = totalTransist * initialEvents;
		double expectedDist = 0;
		for (const Event& e : finalEvents) {
			expectedDist += e.dist * e.probability;
		}
		cout << "Case #" << cas << ": " << fixed << setprecision(10) << expectedDist << endl;
	}
}
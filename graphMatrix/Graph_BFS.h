#pragma once
// 广度优先搜索
template <typename Tv, typename Te>
void Graph<Tv, Te>::BFS(int v, int& clock) {
	Queue<int> q; // 辅助队列
	status(v) = DISCOVERD;
	q.enqueue(v);
	while (q.size()) {
		v = q.dequeue();
		dTime(v) = clock++;
		for (int i = firstNbr(v); -1 < i; i = nextNbr(v, i)) {
			if (status(i) == UNDISCOVERD) {
				status(i) = DISCOVERD;
				q.enqueue(i);
				type(v, i) = TREE;
				parent(i) = v;
			}
			else {
				type(v, i) = CROSS;
			}
		}
		status(v) = VISITED;
		fTime(v) = clock++;
	}
}

template <typename Tv, typename Te>
void Graph<Tv, Te>::bfs(int v) {
	reset();
	int clock = 0;
	int s = v;
	do
		if (UNDISCOVERD == status(s))
			BFS(s, clock);
	while (v != (s = (++v % n)));
}
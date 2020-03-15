#pragma once
// 深度优先搜索
template <typename Tv, typename Te>
void Graph<Tv, Te>::DFS(int v, int& clock) {
	dTime(v) = ++clock;
	status(v) = DISCOVERD;
	for (int u = firstNbr(v); -1 < u; u = nextNbr(v, u)) {
		switch (status(u))
		{
		case DISCOVERD:
			type(v, u) = BACKWARD;
			break;
		case UNDISCOVERD:
			parent(u) = v;
			type(v, u) = TREE;
			DFS(u, clock);
			break;
		default:
			type(v, u) = (dTime(v) < dTime(u)) ? FORWARD : CROSS;
			break;
		}
	}
	status(v) = VISITED;
	fTime(v) = ++clock;
}
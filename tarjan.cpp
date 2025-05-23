#include <bits/stdc++.h>

const int N = 1e5 + 100;
const int M = N * 2;
const int QUERY_CNT = M * 3;

int fa[N], height[N], head[N], nxt[M], to[M], weight[M], cnt;
long long int sums[N];
bool vis[N];

int qhead[N], qnxt[QUERY_CNT], qto[QUERY_CNT], qno[QUERY_CNT], qcnt, lcaAns[QUERY_CNT];

void clear(int n) {
    for (int i = 0; i <= n + 10; i++) {
        head[i] = qhead[i] = lcaAns[i] = -1;
        vis[i] = false;
        fa[i] = i;
        height[i] = 0;
        sums[i] = 0;
    }
    qcnt = cnt = 0;
}

int find(int x) {
    while (x != fa[x]) {
        fa[x] = fa[fa[x]];
        x = fa[x];
    }
    return x;
}

void addEdge(int u, int v, int w) {
    nxt[cnt] = head[u];
    to[cnt] = v;
    weight[cnt] = w;
    head[u] = cnt++;
}

void addQuery(int u, int v, int i) {
    qnxt[qcnt] = qhead[u];
    qto[qcnt] = v;
    qno[qcnt] = i;
    qhead[u] = qcnt++;
}

int lca(int i) {
    return lcaAns[i];
}

long long int getWeight(int x, int y, int xyLca) {
    return sums[x] + sums[y] - 2 * sums[xyLca];
}

void tarjan(int u, int f, int d) {
    vis[u] = true;
    height[u] = d;
    for (int e = head[u]; e != -1; e = nxt[e]) {
        int v = to[e], w = weight[e];
        if (!vis[v] && v != f) {
            sums[v] = sums[u] + w;
            tarjan(v, u, d + 1);
            fa[v] = u;
        }
    }
    for (int e = qhead[u]; e != -1; e = qnxt[e]) {
        int v = qto[e], i = qno[e];
        if (vis[v]) lcaAns[i] = find(v);
    }
}

std::vector<int> minimumWeight(std::vector<std::vector<int>>& edges, std::vector<std::vector<int>>& queries) {
    int n = edges.size() + 1;
    clear(n);
    for (auto& e : edges) {
        int u = e[0], v = e[1], w = e[2];
        addEdge(u, v, w);
        addEdge(v, u, w);
    }
    std::vector<int> ans(queries.size());
    int j = 0;
    for (int i = 0; i < queries.size(); i++) {
        int a = queries[i][0], b = queries[i][1], c = queries[i][2];
        addQuery(a, b, j);
        addQuery(b, a, j++);
        addQuery(b, c, j);
        addQuery(c, b, j++);
        addQuery(a, c, j);
        addQuery(c, a, j++);
    }
    tarjan(0, -1, 1);
    j = 0;
    for (int i = 0; i < queries.size(); i++) {
        int a = queries[i][0], b = queries[i][1], c = queries[i][2];
        int lcaab = lca(j++), lcabc = lca(j++), lcaac = lca(j++);
        ans[i] = (getWeight(a, b, lcaab) + getWeight(b, c, lcabc) + getWeight(a, c, lcaac)) / 2;
    }
    return ans;
}


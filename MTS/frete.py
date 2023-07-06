class UnionFind:
    def __init__(self, n):
        self.parent = list(range(n)) #[0,1,2,3]
        self.rank = [0] * n

    def union(self, x, y):
        x_root = self.find(x)
        y_root = self.find(y)

        if x_root == y_root:
            return

        if self.rank[x_root] < self.rank[y_root]:
            self.parent[x_root] = y_root
        elif self.rank[x_root] > self.rank[y_root]:
            self.parent[y_root] = x_root
        else:
            self.parent[y_root] = x_root
            self.rank[x_root] += 1

    def find(self, x):
        if self.parent[x] != x:
            self.parent[x] = self.find(self.parent[x])
        return self.parent[x]


def kruskal(graph, n):
    edges = []
    for i in range(n):
        for j in range(i + 1, n):
            if graph[i][j] > 0:
                edges.append((i, j, graph[i][j]))

    edges.sort(key=lambda x: x[2])  # Ordena as arestas pelo custo

    uf = UnionFind(n)
    cost = 0
    for edge in edges:
        u, v, weight = edge
        if uf.find(u) != uf.find(v):
            uf.union(u, v)
            cost += weight

    return cost


# Leitura da entrada
N, M = map(int, input().split())
graph = [[0] * N for _ in range(N)]

for _ in range(M):
    P, Q, U = map(int, input().split())
    graph[P][Q] = U
    graph[Q][P] = U

# Chamada da função kruskal para encontrar o custo mínimo
minimum_cost = kruskal(graph, N)
print(minimum_cost)

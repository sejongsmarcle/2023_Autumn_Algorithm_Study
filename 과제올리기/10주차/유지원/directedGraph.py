import sys


class Graph:

    def __init__(self, vertex_num=None):
        # 인접 리스트
        self.adj_lsit = []
        self.vtx_num = 0

        self.vtx_arr = []

        if vertex_num:
            self.vtx_num = vertex_num
        self.vtx_arr = [True for _ in range(self.vtx_num)]
        self.adj_list = [[] for _ in range(self.vtx_num)]

    def add_vertex(self):
        self.adj_list.append([])
        self.vtx_num += 1
        self.vtx_arr.append(True)
        return self.vtx_num - 1

    def add_edge(self, u, v):
        self.adj_list[u].append(v)


T = int(sys.stdin.readline().strip())

for _ in range(T):
    n = int(sys.stdin.readline().strip())
    num = 0
    l = list(map(int, sys.stdin.readline().strip().split()))
    g = Graph(n)
    for i in range(n):
        g.add_edge(i, l[i] - 1)

    # cycle
    for i in range(n):
        cycle = 0
        adj_vtx = g.adj_list[i][0]
        for _ in range(n):
            if adj_vtx == i:
                cycle = 1
                break
            adj_vtx = g.adj_list[adj_vtx][0]
        if cycle == 0:
            num += 1
    print(num)

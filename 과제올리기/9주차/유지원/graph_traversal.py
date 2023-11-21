import sys

class Graph:

    def __init__(self, vertex_num=None):
        self.adj_list = []
        self.vtx_num = 0
        self.vtx_arr = []
        if vertex_num:
            self.vtx_num = vertex_num
        self.vtx_arr = [True for _ in range(self.vtx_num)]
        self.adj_list = [[] for _ in range(self.vtx_num)]

    def add_edge(self, u, v):
        self.adj_list[u].append(v)
        self.adj_list[v].append(u)

n = int(sys.stdin.readline().strip())
m = int(sys.stdin.readline().strip())

g = Graph(n)
for _ in range(m):
    l = list(map(int, sys.stdin.readline().strip().split()))
    g.add_edge(l[0] - 1, l[1] - 1)

guest = [0]
for i in g.adj_list[0]:
    if i not in guest:
        guest.append(i)
    for j in g.adj_list[i]:
        if j not in guest:
            guest.append(j)

print(len(guest)-1)

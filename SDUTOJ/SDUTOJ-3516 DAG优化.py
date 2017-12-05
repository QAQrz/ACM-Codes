class Node(object):
	def __init__(self, c, l = -1, r = -1):
		self.c = [c]
		self.l = l
		self.r = r
def addnode(c):
	for i in range(len(b)-1, -1, -1):
		if c in b[i].c:
			return i
	b.append(Node(c))
	return len(b) - 1
def addop(c, op, l, r):
	for i in range(len(b)-1, -1, -1):
		if b[i].l == l and b[i].r == r and b[i].c[0] == op:
			b[i].c.append(c)
			return
	b.append(Node(op, l, r))
	b[len(b) - 1].c.append(c)
def dfs(x):
	if b[x].l > -1:
		vis[x] = 1
		dfs(b[x].l)
		dfs(b[x].r)
t = int(input())
b = []
for k in range(t):
	s = input()
	l = addnode(s[2])
	r = addnode(s[4])
	addop(s[0], s[3], l, r)
ans = [''] * len(b)
vis = [0] * len(b)
for i in range(len(b)):
	if b[i].l > -1:
		ans[i] = b[i].c[1] + '=' + (b[b[i].l].c[1] if b[b[i].l].l > -1 else b[b[i].l].c[0]) + b[i].c[0] + (b[b[i].r].c[1] if b[b[i].r].l > -1 else b[b[i].r].c[0])
for i in range(len(b)-1, -1, -1):
	if len(ans[i]) > 0 and ans[i][0] == 'A':
		dfs(i)
		break
for i in range(len(b)-1, -1, -1):
	if len(ans[i]) > 0 and ans[i][0] == 'B':
		dfs(i)
		break
for i in range(len(b)):
	if vis[i]:
		print(ans[i])
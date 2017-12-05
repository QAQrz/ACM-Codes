def inc(c):
	for i in range(m):
		if c in b[i]:
			return i
	return -1

n, m = map(int, input().split(' '))
s = [''] * n
mmp = {'+': 'ADD', '-': 'SUB', '*': 'MUL', '/': 'DIV'}

cntm = 0
for i in range(n):
	s[i] = input()
for i in range(n):
	
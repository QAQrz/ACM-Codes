def include(c):
	for i in range(m):
		if r[i] == c:
			return i
	return -1
def nextpos(pos, c):
	for i in range(pos, n):
		if s[i][3] == c or s[i][5] == c:
			return i
	return n
def getpos(pos):
	global cnt
	if cnt < m:
		cnt += 1
		return cnt - 1
	ans = -1
	lpos = -1
	for i in range(m):
		tpos = nextpos(pos, r[i])
		if tpos > lpos:
			lpos = tpos
			ans = i
	return ans
n, m = map(int, input().split(' '))
cnt = 0
s = [''] * n
r = [''] * (m + 1)
mmp = {'+': 'ADD', '-': 'SUB', '*': 'MUL', '/': 'DIV'}
for i in range(n):
	s[i] = input()
for i in range(n):
	pos = include(s[i][3])
	if pos < 0:
		pos = getpos(i)
		if len(r[pos]) and nextpos(i, r[pos]) < n:
			print('ST R%d, %s' % (pos, r[pos]))
		print('LD R%d, %s' % (pos, s[i][3]))
	rpos = include(s[i][5])
	if rpos < 0:
		print('%s R%d, %s' % (mmp[s[i][4]], pos, s[i][5]))
	else:
		print('%s R%d, R%d' % (mmp[s[i][4]], pos, rpos))
	r[pos] = s[i][0]
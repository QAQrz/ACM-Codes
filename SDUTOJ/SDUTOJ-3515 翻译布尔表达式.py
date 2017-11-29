t = int(input())
for k in range(t):
	s = input().split(' ')
	cnt = 100
	true = 1
	false = 0
	b = []
	for a in s:
		if a == 'or':
			print('%d(j%s,%s,%s,%d)' % (cnt, b[1], b[0], b[2], true))
			true = cnt
			cnt += 2
			print('%d(j,_,_,%d)' % (cnt - 1, cnt))
			b = []
		elif a ==  'and':
			print('%d(j%s,%s,%s,%d)' % (cnt, b[1], b[0], b[2], cnt + 2))
			cnt += 2
			print('%d(j,_,_,%d)' % (cnt - 1, false))
			false = cnt - 1
			b = []
		else:
			b.append(a)
	print('%d(j%s,%s,%s,%d)' % (cnt, b[1], b[0], b[2], true))
	print('%d(j,_,_,%d)' % (cnt + 1, false))
import queue
import sys

n = int(input())
q = queue.PriorityQueue()
s = ''
for line in sys.stdin:
    s += line + ' '
s = s.split(' ')
a = []
for x in s:
    try:
        a.append(int(x))
    except ValueError:
        pass
for x in a:
    q.put(x)
while q.qsize() > 1:
    q.put(q.get() * q.get() + 1)
a = sorted(a, reverse=True)
for i in range(n - 1):
    a[i + 1] = a[i] * a[i + 1] + 1
ans = q.get() - a[n - 1]
print(len(str(ans)))
print(ans)

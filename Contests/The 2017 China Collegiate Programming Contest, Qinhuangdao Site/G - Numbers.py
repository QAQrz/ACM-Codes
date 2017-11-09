#coding:utf-8
t=int(raw_input())
for cs in range(0,t):
	tmp=raw_input().split()
	n=long(tmp[0])
	m=long(tmp[1])
	if n==0:
		print "0"
		continue
	if n<=m:
		print "1"
		continue
	bins=bin(n).replace('0b','')
	b=list(bins)
	l=len(b)
	for i in range(0,l):
		b[i]=int(b[i])
	tmpx=n
	sb=1<<l
	ansb=[0]*l
	for i in range(0,l):
		tmpb=(sb-1)*m
		if tmpx>tmpb:
			ansb[i-1]=1
			tmpx=max(tmpx-sb*m,tmpx%sb)
		sb>>=1
	if tmpx!=0:
		ansb[l-1]=1
	ans2=0
	for i in range(0,l):
		ans2=ans2*2+ansb[i]
	print ans2
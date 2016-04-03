#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <iostream>
#include <cstdlib>
#include <sstream>

using namespace std;
const int maxn=10000;
struct Node
{
	int size, key, value, sum;
	Node *c[2];
};
int N;
Node memo[maxn*17], *cur, *tr[maxn], *nil;
inline Node* newNode(int key, int v)
{
	cur->key = key;
		cur->value = cur->sum = v;
	cur->size = 1;
	cur->c[0] = cur->c[1] = nil;
	return cur++;
}

inline void init() 
{
	nil = cur = memo;
	nil = newNode(0, 0);
	nil->size = 0;
	for (int i = 1; i <= N; ++i)
		tr[i] = nil;
}
inline void update(Node* t) 
{
	t->sum = t->c[0]->sum + t->c[1]->sum + t->value;
	t->size = t->c[0]->size + t->c[1]->size + 1;
}
inline void rotate(Node*& t, int f)
{
	Node* k = t->c[f ^ 1];
	t->c[f ^ 1] = k->c[f];
	k->c[f] = t;
	update(t);
	update(k);
	t = k;
}
inline void keep(Node*& t, int f) 
{
	if (t == nil) return;
	else if (t->c[f]->c[f]->size > t->c[f ^ 1]->size)
		rotate(t, f ^ 1);
	else if (t->c[f]->c[f ^ 1]->size > t->c[f ^ 1]->size)
		rotate(t->c[f], f), rotate(t, f ^ 1);
	else
		return;
	for (int i = 0; i < 2; ++i) keep(t->c[i], i);
	for (int i = 0; i < 2; ++i) keep(t, i);
}
inline void insert(Node*& t, int key, int v) 
{
	if (t == nil)
		t = newNode(key, v);
	else if (t->key == key)
	{
		t->value += v;
		update(t);
	}
	else
	{
		insert(t->c[key > t->key], key, v);
		update(t);
		keep(t, key > t->key);
	}
}
inline int read(Node* t, int key) 
{
	int ret=0;
	while (t != nil)
	{
		if (t->key <= key)
		{
			ret += t->value + t->c[0]->sum;
			t = t->c[1];
		}
		else
			t = t->c[0];
	}
}

int main()
{
	return 0;
}

#include <stdio.h>
#define NIL -1
#define MAX_N 30
typedef struct node_ {
    int p;
    int l;
    int r;
} Node;
 
Node T[MAX_N];
int D[MAX_N], H[MAX_N];
 
void setDepth(int u, int d) {
    if (u == NIL) return;
    D[u] = d;
    setDepth(T[u].l, d+1);
    setDepth(T[u].r, d+1);
}
 
int setHeight(int u) {
    int h1 = 0, h2 = 0;
    if (T[u].l != NIL) {
        h1 = setHeight(T[u].l) + 1;
    }
    if (T[u].r != NIL) {
        h2 = setHeight(T[u].r) + 1;
    }
 
    if (h1 >= h2) {
        return H[u] = h1;
    } else {
        return H[u] = h2;
    }
}
 
int getSibling(int u) {
    if (T[u].p == NIL) return NIL;
    if (T[T[u].p].l != u && T[T[u].p].l != NIL) {
        return T[T[u].p].l;
    }
    if (T[T[u].p].r != u && T[T[u].p].r != NIL) {
        return T[T[u].p].r;
    }
    return NIL;
}
 
void print(int u) {
    printf("node %d: ", u);
    printf("parent = %d, ", T[u].p);
    printf("sibling = %d, ", getSibling(u));
 
    int deg = 0;
    if (T[u].l != NIL) deg++;
    if (T[u].r != NIL) deg++;
    printf("degree = %d, ", deg);
 
    printf("depth = %d, ", D[u]);
    printf("height = %d, ", H[u]);
 
    if (T[u].p == NIL) {
        printf("root\n");
    } else if (T[u].l == NIL && T[u].r == NIL) {
        printf("leaf\n");
    } else {
        printf("internal node\n");
    }
}
 
int main(void) {
    int i, n;
    scanf("%d", &n);
    for (i = 0; i < MAX_N; i++) {
        T[i].p = NIL;
        T[i].l = NIL;
        T[i].r = NIL;
    }
 
    for (i = 0; i < n; i++) {
        int id, left, right;
        scanf("%d %d %d", &id, &left, &right);
        T[id].l = left;
        T[id].r = right;
        if (left != NIL) T[left].p = id;
        if (right != NIL) T[right].p = id;
    }
 
    int r;
    for (i = 0; i < n; i++) {
        if (T[i].p == NIL) r = i;
    }
 
    setDepth(r, 0);
    setHeight(r);
 
    for (i = 0; i < n; i++) {
        print(i);
    }
 
    return 0;
}

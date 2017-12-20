#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 
typedef struct Node* NodePointer;
 
typedef struct Node {
  int key;
  NodePointer next, pre;
} Node;
 
NodePointer h, l;
 
NodePointer make_node(int key) {
  NodePointer tmp = malloc(sizeof(Node));
  tmp->next = tmp->pre = NULL;
  tmp->key = key;
  return tmp;
}
 
void init() {
  h = malloc(sizeof(Node));
  l = malloc(sizeof(Node));
  h->next = l;
  l->pre = h;
}
 
void insert(NodePointer s, int key) {
  NodePointer node = make_node(key);
  NodePointer t = s->next;
  s->next = node;
  node->pre = s;
  node->next = t;
  t->pre = node;
}
 
void delete(NodePointer p) {
  NodePointer s = p->pre;
  NodePointer t = p->next;
  s->next = t;
  t->pre = s;
  free(p);
}
 
int main() {
  int N, num;
  char str[30];
  NodePointer p;
  init();
  scanf(" %d ", &N);
  while(N--) {
    scanf(" %s ", str);
    if(!strcmp(str,"insert")) {
      scanf(" %d ", &num);
      insert(h,num);
    } else if(!strcmp(str,"delete")) {
      scanf(" %d ", &num);
      for(p = h->next; p != l; p = p->next) {
        if(p->key == num) {
          delete(p);
          break;
        }
      }
    } else if(!strcmp(str,"deleteFirst")) {
      delete(h->next);
    } else if(!strcmp(str,"deleteLast")) {
      delete(l->pre);
    }
  }
 
  for(p = h->next; p != l; p = p->next) {
    printf(p == h->next? "%d":" %d", p->key);
  }
  printf("\n");
 
  return 0;
}

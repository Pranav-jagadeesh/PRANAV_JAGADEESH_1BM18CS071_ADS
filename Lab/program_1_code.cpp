#include <iostream>
using namespace std;

struct Node {
  int val;
  Node* npx;
  Node(int val) : val(val), npx(NULL) {}
};

Node* XOR(Node* prev, Node* next) {
  return (Node*) ((uintptr_t)prev ^ (uintptr_t)next); 
}

Node* insertEnd(Node* head, int val) {
  if (!head) 
    return new Node(val);
  Node* prev = NULL, *curr = head, *next = XOR(prev, curr->npx);
  while (next) {
    prev = curr;
    curr = next;
    next = XOR(prev, curr->npx);
  }
  next = new Node(val);
  next->npx = XOR(curr, NULL);
  curr->npx = XOR(curr->npx, next);
  return head;
}

Node* insertBeg(Node* head, int val) {
  if (!head) 
    return new Node(val);
  Node* node = new Node(val);
  head->npx = XOR(head->npx, node);
  node->npx = XOR(NULL, head);
  return node;
}

void printList(Node* curr) {
  Node* prev = NULL;
  while (curr) {
    cout << curr->val << ' ';
    Node* next = XOR(curr->npx, prev);
    prev = curr, curr = next;
  } 
  cout << endl;
}

int main() {
  Node* head = NULL;

  cout << "enter no of nodes to insert at end: ";
  int n; cin >> n;
  cout << "enter values to be inserted at end: ";
  for (int i = 0; i < n; i++) {
    int val; cin >> val;
    head = insertEnd(head, val);
  }
  cout << "The nodes are: ";
  printList(head); 

  cout << "enter no of nodes to insert at front: ";
  cin >> n;
  cout << "enter values to be inserted at front: ";
  for (int i = 0; i < n; i++) {
    int val; cin >> val;
    head = insertBeg(head, val);
  }
  cout << "The nodes are: ";
  printList(head); 

  return 0;
}

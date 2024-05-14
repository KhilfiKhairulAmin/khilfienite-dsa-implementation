#include <iostream>

using namespace std;

struct Node {
  int data;
  Node* next;
};

void traverseList(Node* head) {
  Node* current = head;

  while (current != nullptr) {
    cout << current->data << " ";
    current = current->next;
  }
  cout << endl;
}

int lengthList(Node* head) {
  Node* cur = head;
  int count = 0;
  while (cur != nullptr) {
    count++;
    cur = cur->next;
  }
  return count;
}

void push(Node** head, int data) {
  Node* newNode = new Node{ data, (*head) };
  (*head) = newNode;
}

void append(Node* head, int data) {
  Node* newNode = new Node{ data };
  Node* cur = head;
  while (cur->next != nullptr) {
    cur = cur->next;
  }
  cur->next = newNode;
}

void insert(Node** head, int data, unsigned int pos) {
  Node* newNode = new Node{ data };
  if (pos == 0 || head == nullptr) {
    push(head, data);
    return;
  }
  
  int max_index = lengthList(*head)-1;
  if (pos > max_index) {
    pos = max_index;
  }

  Node* temp = *head;
  while (--pos) {
    temp = temp->next;
  }
  newNode->next = temp->next;
  temp->next = newNode;
}

Node* pop(Node** head) {
  if (*head == nullptr) {
    throw runtime_error("There is no element to be popped from list.");
  }

  if ((*head)->next == nullptr) {
    Node* n = *head;
    *head = nullptr;
    return n;
  }

  Node* temp = (*head);
  while(temp->next->next != nullptr) {
    temp = temp->next;
  }
  Node* n = temp->next;
  temp->next = nullptr;
  return n;
}

Node* shift(Node** head) {
  if (*head == nullptr) {
    throw runtime_error("There is no element to be shifted from list.");
  }
  Node* n = *head;
  *head = (*head)->next;
  return n;
}

Node* removeAt(Node** head, unsigned int pos) {
  if (*head == nullptr) {
    throw runtime_error("There is no element to be popped from list.");
  }

  int max_index = lengthList(*head)-1;
  if (pos > max_index) {
    pos = max_index;
  }

  if (pos == 0) {
    Node* n = *head;
    *head = nullptr;
    return n;
  }

  Node* cur = *head;
  while(--pos) {
    cur = cur->next;
  }
  Node* temp = cur->next;
  cur->next = cur->next->next;
  return temp;
}

int search(Node* head, int searchKey) {
  int pos = 0;
  Node* cur = head;
  while (cur != nullptr) {
    if (cur->data == searchKey) {
      return pos; 
    }
    cur = cur->next;
    pos++;
  }
  return -1;
}

void reverse(Node** head, Node* cur) {
  if (cur->next == nullptr) {
    *head = cur;
    return;
  }
  // Base case
  reverse(head, cur->next);
  cur->next->next = cur;
  cur->next = nullptr;
}

void empty(Node** head) {
  if ((*head)->next == nullptr) {
    delete *head;
    return;
  }
  // Base case
  empty(&((*head)->next));
  delete (*head)->next;
}

int main() {
  Node* head = new Node{ 1 };
  Node* second = new Node{ 2 };
  Node* third = new Node{ 3 };
  Node* someNode = new Node{ 10 };

  head->next = second;
  second->next = third;
  third->next = someNode;
  push(&head, 7);
  append(head, -100);
  insert(&head, 969696, 0);
  
  traverseList(head);
  cout << lengthList(head) << endl;
  Node* poppedElem = pop(&head);
  traverseList(head);
  cout << "Popped element: " << poppedElem->data << endl;
  Node* shiftedElem = shift(&head);
  traverseList(head);
  cout << "Shifted element: " << shiftedElem->data << endl;
  Node* removedAtElem = removeAt(&head, 2);
  traverseList(head);
  cout << "Removed element: " << removedAtElem->data << endl;
  cout << "Search elem 10: result at position " << search(head, 10) << endl;
  reverse(&head, head);
  traverseList(head);
  empty(&head);
  traverseList(head);
}


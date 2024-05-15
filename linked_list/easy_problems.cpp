// START OF LINKED LIST TEMPLATE

#include <iostream>

using namespace std;

struct Node {
  int data;
  Node* next;
};

void traverseList(Node* head) {
  Node* current = head;

  while (current->next != nullptr and current->next != head) {
    cout << current->data << " ";
    current = current->next;
  }
  cout << current->data << endl;
}

int lengthList(Node* head) {
  if (head == nullptr) {
    return 0;
  }

  if (head->next == nullptr or head->next == head) {
    return 1;
  }

  Node* cur = head->next;
  int count = 1;
  while (cur != nullptr and cur != head) {
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

// END OF LINKED LIST TEMPLATE

void coutMiddleNode(Node* head) {
  if (head == nullptr) {
    return;
  }
  int mid = int((lengthList(head)-1) / 2);
  Node* cur = head;
  while (mid--) {
    cur = cur->next;
  }
  cout << "Element at middle position is " << cur->data << endl;
}

int countDuplicates(Node* head, int data) {
  int count = 0;
  Node* cur = head;
  while (cur != nullptr) {
    if (cur->data == data) {
      count++;
    }
    cur = cur->next;
  }
  return count;
}

void circulizeList(Node* head) {
  if (head == nullptr) {
    return;
  }

  if (head->next == nullptr) {
    return;
  }

  Node* temp = head;
  while (temp->next != nullptr) {
    temp = temp->next;
  }
  temp->next = head;
}

bool isCircular(Node* head) {
  if (head == nullptr) {
    return true;
  }
  Node* cur = head->next;
  while (cur != head and cur != nullptr) {
    cur = cur->next;
  }
  return cur == head;
}

void swapHeadTailCircular(Node* head) {
  if (head == nullptr) {
    return;
  }
  if (head->next == head) {
    return;
  }

  int first = head->data;
  Node* cur = head->next;
  while (cur->next != head) {
    cur = cur->next;
  }
  head->data = cur->data;
  cur->data = first;
}

int main() {
  Node* head = new Node{ 10 };
  append(head, 23);
  append(head, 49);
  append(head, 63);
  append(head, 99);
  append(head, 100);
  append(head, 85);
  append(head, 85);

  traverseList(head);
  // 1
  coutMiddleNode(head);
  // 2
  cout << countDuplicates(head, 0) << endl;
  // 5
  circulizeList(head);
  traverseList(head);
  // 3
  cout << boolalpha << isCircular(head) << endl;
  // 4
  Node* emptyList = nullptr;
  Node* oneElemList = new Node{ 1 };
  cout << lengthList(head) << endl; // Modified length function for this problem
  cout << lengthList(emptyList) << endl;
  cout << lengthList(oneElemList) << endl;
  // 6
  swapHeadTailCircular(head);
  traverseList(head);
  // 11
  traverseList(head); // Modified traverse to handle circular list logic
}

// START OF LINKED LIST TEMPLATE

#include <iostream>
#include <unordered_map>

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

// END OF LINKED LIST TEMPLATE

bool hasLoop(Node* head) {
  Node* cur = head;
  unordered_map<Node*, bool> visited;
  visited[cur] = true;
  while (cur != nullptr) {
    cur = cur->next;
    try {
      if (visited.at(cur)) {
        return true;
      }
    }
    catch (const out_of_range& e) {
      visited[cur] = true;
    }
  }
  return false;
}

int lengthLoop(Node* head) {
  int count = 0;
  Node* cur = head;
  Node* prev;
  unordered_map<Node*, bool> visited;
  while(cur != nullptr) {
    prev = cur;
    cur = cur->next;
    try {
      // Detected a loop
      if (visited.at(cur)) {
        count = 1;
        while (cur != prev) {
          cur = cur->next;
          count++;
        }
        break;
      }
    }
    catch (const out_of_range& e) {
      visited[cur] = true;
    }
  }
  return count;
}

bool floydHareAndTortoise(Node* head) {
  Node* slow_p = head;
  Node* fast_p = head;

  while(slow_p && fast_p && fast_p->next) {
    slow_p = slow_p->next;
    fast_p = fast_p->next->next;

    if (slow_p == fast_p) {
      return true;
    }
  }
  return false;
}

int floydHareAndTortoiseLength(Node* head) {
  Node* slow_p = head;
  Node* fast_p = head;

  while(slow_p && fast_p && fast_p->next) {
    slow_p = slow_p->next;
    fast_p = fast_p->next->next;

    if (slow_p == fast_p) {
      int count = 1;
      while (slow_p != fast_p->next) {
        fast_p = fast_p->next;
        count++;
      }
      return count;
    }
  }
  return 0;
}

Node* intersectionTwoList(Node* a, Node* b) {
  Node dummy;
  Node* temp = &dummy;
  dummy.next = nullptr;

  while (a != nullptr && b != nullptr) {
    if (a->data == b->data) {
      push(&(temp->next), a->data);
      temp = temp->next;
      a = a->next;
      b = b->next;
    }
    else if (a->data < b->data) {
      a = a->next;
    }
    else {
      b = b->next;
    }
  }
  return dummy.next;
}

Node* getLastNode(Node* head) {
  Node* cur = head;
  while (cur->next != nullptr) {
    cur = cur->next;
  }
  return cur;
}

Node* partition(Node* first, Node* last) {
  Node* pivot = first;
  Node* cur = first;
  int temp;

  while (cur != nullptr && cur != last) {
    if (cur->data < last->data) {
      pivot = first;

      // Swap
      temp = first->data;
      first->data = cur->data;
      cur->data = temp;

      first = first->next;
    }
    cur = cur->next;
  }
  temp = first->data;
  first->data = last->data;
  last->data = temp;
  return pivot;
}

void quickSortList(Node* first, Node* last) {
  if (first == last) {
    return;
  }

  Node* pi = partition(first, last);
  if (pi != nullptr && pi->next != nullptr) {
    quickSortList(pi->next, last);
  }

  if (pi != nullptr && first != pi) {
    quickSortList(first, pi);
  }
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
  Node* emptyList = nullptr;
  Node* oneElemList = new Node{ 1 };
  circulizeList(head);
  cout << boolalpha << hasLoop(head) << endl;
  cout << boolalpha << hasLoop(emptyList) << endl;
  circulizeList(oneElemList);
  cout << boolalpha << hasLoop(oneElemList) << endl;
  // 1 (Using floyd's cycle detection algorithm)
  cout << boolalpha << floydHareAndTortoise(head) << endl;
  cout << boolalpha << floydHareAndTortoise(emptyList) << endl;
  cout << boolalpha << floydHareAndTortoise(oneElemList) << endl;
  // 2
  cout << lengthLoop(head) << endl;
  cout << lengthLoop(emptyList) << endl;
  cout << lengthLoop(oneElemList) << endl;
  // 2 (Using floyd's cycle detection algorithm)
  cout << floydHareAndTortoiseLength(head) << endl;
  cout << floydHareAndTortoiseLength(emptyList) << endl;
  cout << floydHareAndTortoiseLength(oneElemList) << endl;
  // 3
  Node* sortedList1 = new Node{ 1 };
  append(sortedList1, 2);
  append(sortedList1, 4);
  append(sortedList1, 6);
  append(sortedList1, 9);
  append(sortedList1, 10);
  append(sortedList1, 85);
  append(sortedList1, 86);
  Node* sortedList2 = new Node{ 3 };
  append(sortedList2, 4);
  append(sortedList2, 7);
  append(sortedList2, 9);
  append(sortedList2, 11);
  append(sortedList2, 36);
  append(sortedList2, 86);
  // 4
  Node* intersection = intersectionTwoList(sortedList1, sortedList2);
  traverseList(intersection);

  // 5
  Node* head2 = new Node{ 10 };
  append(head2, 23);
  append(head2, 49);
  append(head2, 63);
  append(head2, 99);
  append(head2, 100);
  append(head2, 85);
  append(head2, 85);
  Node* first = head2;
  Node* last = getLastNode(head2);
  quickSortList(first, last);
  traverseList(head2);
}

#include <iostream>

using namespace std;

struct Node {
  Node* next = NULL;
  int val = 0;

  Node(int val=0, Node* next=NULL) {
    this->next = next;
    this->val = val;
  }
};

void insert_node(Node* root, int val) {
  if (root->next == NULL) {
    Node newNode = Node();
    newNode.val = val;
    root->next = &newNode;
    return;
  }
  Node* temp = root->next;
  while(temp->next != NULL) {    
    temp = temp->next;
  }
  Node newNode = Node();
  newNode.val = val;
  temp->next = &newNode;
}

void cout_nodes(Node* root) {
  Node* temp = root->next;
  while(temp != NULL) {
    cout << temp->val << " ";
    temp = temp->next;
  }
  cout << "\n";
}

int main() {
  Node root = Node();
  insert_node(&root, 3);
  insert_node(&root, 5);
  cout_nodes(&root);

}

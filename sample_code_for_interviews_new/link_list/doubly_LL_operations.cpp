using namespace std;

class Node {
public:
  int value;
  Node *prev;
  Node *next;

  Node(int value);
};

// Feel free to add new properties and methods to the class.
class DoublyLinkedList {
public:
  Node *head;
  Node *tail;

  DoublyLinkedList() {
    head = nullptr;
    tail = nullptr;
  }

  void setHead(Node *node) {
    if (head == nullptr){
			// empty linkedlist
			head = node;
			tail = node;
			return;
		}
		insertBefore(head, node);
  }

  void setTail(Node *node) {
    if(tail == nullptr){
			setHead(node);
			return;
		}
		insertAfter(tail, node);
  }

  void insertBefore(Node *node, Node *nodeToInsert) {
		// trying to insert the tail or head in the
		// existing linked list
		// edge case
    if(nodeToInsert == head && nodeToInsert == tail){
			return;
		}
		
		// defensive strategy
		// remove the node if it already exists in the linkedlist
		// then insert it again where it is required to
		// this accounts for the condition when we want to shift
		// the position in the LinkedList
		// if the node is not present in the linkedlist
		// then nothing will be removed
		remove(nodeToInsert);
		
		nodeToInsert->prev = node->prev;
		nodeToInsert->next = node;
		if(node->prev == nullptr){
			head = nodeToInsert;
		}else {
			node->prev->next = nodeToInsert;
		}
		node->prev = nodeToInsert;
		
  }

  void insertAfter(Node *node, Node *nodeToInsert) {
   	// trying to insert the tail or head in the
		// existing linked list
		// edge case
    if(nodeToInsert == head && nodeToInsert == tail){
			return;
		}
		
		// defensive strategy
		// remove the node if it already exists in the linkedlist
		// then insert it again where it is required to
		// this accounts for the condition when we want to shift
		// the position in the LinkedList
		// if the node is not present in the linkedlist
		// then nothing will be removed
		remove(nodeToInsert);
		
		nodeToInsert->prev = node;
		nodeToInsert->next = node->next;
		
		if(node->next == nullptr){
			tail = nodeToInsert;
		} else {
			node->next->prev = nodeToInsert;
		}
		node->next = nodeToInsert;
  }

  void insertAtPosition(int position, Node *nodeToInsert) {
    // Write your code here.
		
		if(position == 1){
			setHead(nodeToInsert);
			return;
		}
		
		Node *node = head;
		int currentPosition = 1;
			
		while(node != nullptr && currentPosition++ != position){
			node = node->next;
		}
		
		// let's say pointer is on 7th Position right now
		// when pointer is on that position , if node is
		// is inserted before that, that node will become
		// the 7th position and the curr node will become the
		// 8th Position
		if(node != nullptr) {
				insertBefore(node, nodeToInsert);
		} else {
			setTail(nodeToInsert);
		}
		
  }

  void removeNodesWithValue(int value) {
    Node *node = head;
		while(node != nullptr){
			Node *nodeToRemove = node;
			node = node->next;
			if(nodeToRemove->value == value){
				remove(nodeToRemove);
			}
		}
  }

  void remove(Node *node) {
    if(node == head){
			head = head->next;
		}
		if(node == tail){
			tail = tail->prev;
		}
		removeNodeBindings(node);
  }

  bool containsNodeWithValue(int value) {
    Node *node = head;
		while( node!= nullptr && node->value != value){
			node = node->next;
		}
    return node!= nullptr;
  }
	
	void removeNodeBindings(Node *node){
		if(node->prev != nullptr){
			node->prev->next = node->next;
		}
		
		if(node->next!= nullptr){
			node->next->prev = node->prev;
		}
		
		node->prev = nullptr;
		node->next = nullptr;
	}
};

int main() {
}




void doublyLinkListDelete(ListNode* head, int val){
  // Delete from Doubly LinkList
  
  ListNode* curr = head;
  ListNode* dummy_node = new ListNode(-1);
  dummy->next = head;
  ListNode* previous = dummy;
  
  
  while(curr != NULL && curr->value != val){
    previous = curr;
    curr = curr->next;
    
  }
  
  if(curr == head){
    previous->next = curr->next;
    curr->next->prev = previous;
    head = previous;
  }else {
    previous->next = curr->next;
    curr->next->prev = previous;
  }
  
  return head;
}

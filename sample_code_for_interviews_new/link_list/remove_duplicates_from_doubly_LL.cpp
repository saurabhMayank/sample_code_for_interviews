class Solution
{
    public:
    void removeDuplicates(struct Node **head)
    {
        // Your code here
        if(*head == NULL){
            return;
        }
        
        
        Node* curr = *head;
        
         while(curr && curr->next){
            Node* ahead = curr->next;
            if(curr->data == ahead->data){
                curr->next = ahead->next;
                if(ahead->next)ahead->next->prev = ahead->prev;
                delete(ahead);
            }else {
                curr = curr->next;
            }    
            
        }
        
        // return head;
    }
};

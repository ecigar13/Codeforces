/*
Detect a cycle in a linked list. Note that the head pointer may be 'NULL' if the list is empty.

A Node is defined as: 
    struct Node {
        int data;
        struct Node* next;
    }
*/
bool cycle(Node * slow, Node * fast)
{
    if(fast == slow){
        return 1;}
    else if(fast==NULL ||fast->next==NULL){
        return 0;
    }
    else //if(fast!=NULL && slow!=NULL &&fast->next)
    {
        return cycle(slow->next, fast->next->next);
    }

        
}

bool has_cycle(Node* head) {
    // Complete this function
    // Do not write the main method
    if(head==NULL || head->next==NULL){return 0;}
    else return cycle(head, head->next);
    
}

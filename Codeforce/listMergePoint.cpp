/*
   Find merge point of two linked lists
   Node is defined as
   struct Node
   {
       int data;
       Node* next;
   }
*/

//https://stackoverflow.com/questions/1594061/check-if-two-linked-lists-merge-if-so-where/14956113#14956113

int FindMergeNode(Node *headA, Node *headB)
{
    // Complete this function
    // Do not write the main method. 
    
    
    while(headA)
    {
        Node * tmp = headA->next;
        headA->next=NULL;
        headA=tmp;
    }
    while(headB)
    {
        if(headB->next==NULL)
            return headB->data;
        headB=headB->next;
    }
    return -1;
}

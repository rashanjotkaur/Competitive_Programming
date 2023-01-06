// https://www.geeksforgeeks.org/flatten-a-linked-list-with-next-and-child-pointers/

void flattenList(Node *head){
    if(head == NULL)
        return;
 
    Node *temp;
    /* Find tail node of first level linked list */
    Node *tail = head;
    while(tail->next)
        tail = tail->next;
 
    // One by one traverse through all nodes of first level 
    // linked list till we reach the tail node
    Node *curr = head;
    while(curr!=tail){
        // If current node has a child
        if (curr->child){
            // then append the child at the end of current list
            tail->next = curr->child;
            // and update the tail to new last node
            temp = curr->child;
            while(temp->next)
                temp = temp->next;
            tail = temp;
        }
        // Change current node
        curr = curr->next;
    }
}

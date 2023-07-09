/*
Following is the class structure of the Node class:

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};
*/

Node* removeKthNode(Node* head, int K)
{
    int count =0;
    Node *curr = head;

    while(curr != NULL)
    {
        count++;
        curr = curr->next;
    }
    curr = head;
    if(count == K)
    {
        curr = curr->next;
        return curr;
    }


    
    count -=K+1;
    Node *forward = curr->next;
    while (count >0) {
      curr = curr->next;
      forward = curr->next;
      count--;
    }

    curr->next = forward->next;
    return head;
}

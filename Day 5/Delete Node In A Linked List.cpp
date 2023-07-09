#include <bits/stdc++.h>

/****************************************************************

    Following is the class structure of the LinkedListNode class:

    template <typename T>
    class LinkedListNode
    {
    public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*****************************************************************/

void deleteNode(LinkedListNode<int> * node) {
   
   if(node == NULL)
   {
       return;
   }

   if(node ->next == NULL)
   {
       node = NULL;
       return;
   }

   node->data = node->next->data;
   LinkedListNode<int> *demo = node->next;

   node->next = node->next->next;
   delete demo;
}
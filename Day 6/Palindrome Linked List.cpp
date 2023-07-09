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

bool isPalindrome(LinkedListNode<int> *head) {
   if(head == NULL || head->next == NULL)
   {
       return true;
   }

   vector<int> arr;
   LinkedListNode<int> * curr = head;

   while(curr != NULL)
   {
       arr.push_back(curr->data);
       curr= curr->next;
   }

   int size = arr.size();

   for(int i=0;i<size/2;i++)
   {
       if(arr[i] != arr[size-i-1])
       {
           return false;
       }
   }

   return true;


}
/**
 * Definition of linked list:
 *
 * class Node {
 * public:
 *      int data;
 *      Node *next;
 *      Node() {
 *          this->data = 0;
 *          this->next = NULL;
 *      }
 *      Node(int data) {
 *          this->data = data;
 *          this->next = NULL;
 *      }
 *      Node (int data, Node *next) {
 *          this->data = data;
 *          this->next = next;
 *      }
 * };
 *
 *************************************************************************/

void insertAtTail( Node* &head,  Node* &tail,int value)
    {
        Node *temp = new Node(value);
        if(head == NULL)
        {
            head = temp;
            tail =temp;
            return;
        }
        else
        {
            tail->next = temp;
            tail =temp;
        }
    }
    
    
     Node* add( Node* first,  Node* second)
    {
         int carry =0;
         
         Node *ansHead = NULL;
         Node *ansTail =NULL;
         
         while(first != NULL || second != NULL || carry !=0)
         {
             int val1=0;
             if(first != NULL)
             {
                 val1 = first->data;
             }
             
             int val2 =0;
             if(second != NULL)
             {
                 val2 =second->data;
             }
             
             
             int sum = carry + val1 + val2;
             
             int digit = sum % 10;
             
             insertAtTail(ansHead,ansTail,digit);
             
             carry = sum / 10;
             
             if(first !=NULL)
             {
                 first =first->next;
             }
             
             if(second != NULL)
             {
                 second = second->next;
             }
             
            
         }
          return ansHead;
     }

Node *addTwoNumbers(Node *head1, Node *head2)
{
    // Here given lists are already reversed so no need to reverse them just add them 
      // head1 = reverse(head1);
      // head2 = reverse(head2);
       
       
       //step 2-- Add these LL
       
       Node * ans = add(head1,head2);
       
       //step 3 -- again reverse the LL
       //ans = reverse(ans);
       
       return ans;
}

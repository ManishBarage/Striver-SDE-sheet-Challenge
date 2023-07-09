#include <bits/stdc++.h> 
class Stack {
	
    queue<int>q1,q2;

   public:
    Stack() {
        // Implement the Constructor.
    }

    /*----------------- Public Functions of Stack -----------------*/

    int getSize() {
       return q1.size();
    }

    bool isEmpty() {
        if(q1.empty())
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void push(int element) {
        while(!q1.empty())
        {
            int val = q1.front();
            q1.pop();
            q2.push(val);
        }

        q1.push(element);

        while(!q2.empty())
        {
            int val = q2.front();
            q2.pop();
            q1.push(val);
        }
    }

    int pop() {
        if(q1.empty())
        {
            return -1;
        }
        int val = q1.front();
        q1.pop();
        return val;
    }

    int top() {
        if(q1.empty())
        {
            return -1;
        }
        return q1.front();
    }
};
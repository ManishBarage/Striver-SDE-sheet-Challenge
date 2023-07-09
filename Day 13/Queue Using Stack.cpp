#include<bits/stdc++.h>
class Queue {
    stack<int>st1,st2;
    
    public:
    Queue() {
        // Initialize your data structure here.
    }

    void enQueue(int val) {
        st1.push(val);
    }

    int deQueue() {

        if(st1.empty())
        {
            return -1;
        }
        while(!st1.empty())
        {
            int val = st1.top();
            st1.pop();
            st2.push(val);
        }

        int val = st2.top();
        st2.pop();

        while(!st2.empty())
        {
            int val = st2.top();
            st2.pop();
            st1.push(val);
        }

        return val;
    }

    int peek() {
         if(st1.empty())
        {
            return -1;
        }
         while(!st1.empty())
        {
            int val = st1.top();
            st1.pop();
            st2.push(val);
        }

        int val = st2.top();
        while(!st2.empty())
        {
            int val = st2.top();
            st2.pop();
            st1.push(val);
        }

        return val;
        
    }

    bool isEmpty() {
        return st1.empty();
    }
};
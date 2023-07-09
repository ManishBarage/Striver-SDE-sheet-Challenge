#include<bits/stdc++.h>
class LRUCache
{
public:
    class node
    {
        public:
        int key;
        int val;
        node *next;
        node *prev;

        node(int k,int v)
        {
            key = k;
            val = v;
        }
    };

    int cap;
    node *head = new node(-1,-1);
    node *tail = new node(-1,-1);
    unordered_map<int, node*>mp;
    
    
    LRUCache(int capacity)
    {
       cap = capacity;
       head->next = tail;
       tail->prev = head;
    }

    void addNode(node *newNode)
    {
        node *temp = head->next;
        newNode->next = temp;
        head->next = newNode;
        newNode->prev = head;
        temp->prev = newNode;
    }

    void deleteNode(node *delNode)
    {
        node *delPrev = delNode->prev;
        node *delNext = delNode->next;
        
        delPrev->next= delNext;
        delNext->prev = delPrev;
    }

    int get(int key)
    {
        if(mp.find(key)!=mp.end())
        {
            node *resNode = mp[key];
            int res = resNode->val;

            mp.erase(key);
            deleteNode(resNode);
            addNode(resNode);
            mp[key]= head->next;
            return res;
        }

        return -1;
    }

    void put(int key, int value)
    {
        if(mp.find(key) != mp.end())
        {
            node *existNode = mp[key];
            mp.erase(key);
            deleteNode(existNode);
        }
        if(mp.size() == cap)
        {
            mp.erase(tail->prev->key);
            deleteNode(tail->prev);
        }

        addNode(new node(key, value));
        mp[key] = head->next;
    }
};

/*
    Your Trie object will be instantiated and called as such:
    Trie* obj = new Trie();
    obj->insert(word);
    bool check2 = obj->search(word);
    bool check3 = obj->startsWith(prefix);
 */


class TrieNode
{
    public :
    char data;
    TrieNode *children[26];
    bool isTerminal;
    
    TrieNode(char d)
    {
        data =d;
        for(int i=0;i<26;i++)
        {
            children[i] = NULL;
        }
        
        isTerminal = false;
    }
    
};


class Trie {

public:
    TrieNode *root;

    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode('\0');
    }
      
    void insertWord(TrieNode *root, string word)
    {
        if(word.size() ==0)
        {
            root->isTerminal = true;
            return;
        }
        
        
        int index = word[0] - 'a';
        TrieNode *curr;
        if(root->children[index] != NULL)
        {
            curr = root->children[index];
            
        }
        else
        {
            curr = new TrieNode(word[0]);
            root->children[index] = curr;
        }
        
        //Recursion
        insertWord(curr, word.substr(1));
        
    }
    /** Inserts a word into the trie. */
    void insert(string word) {
        
        insertWord(root, word);
    }
    
    bool searchWord(TrieNode *root, string word)
    {
        if(word.length() == 0)
        {
            return root->isTerminal;
        }
        
        int index = word[0] -'a';
        TrieNode *curr;        
        if(root->children[index] != NULL)
        {
            curr = root->children[index];
        }
        else
        {
            return false;
        }
        
        //Recursion
        return searchWord(curr, word.substr(1));
    }
    /** Returns if the word is in the trie. */
    bool search(string word) {
        return searchWord(root, word);
    }
    
    
     bool prefixSearch(TrieNode *root, string word)
    {
        if(word.length() == 0)
        {
            return true;
        }
        
        int index = word[0] -'a';
        TrieNode *curr;        
        if(root->children[index] != NULL)
        {
            curr = root->children[index];
        }
        else
        {
            return false;
        }
        
        //Recursion
        return prefixSearch(curr, word.substr(1));
    }
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        return prefixSearch(root, prefix);
    }
};
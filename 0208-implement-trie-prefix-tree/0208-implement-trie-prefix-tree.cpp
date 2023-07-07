class TrieNode{
    public:
    vector<TrieNode*>links;
    bool isEnd;
    TrieNode(){
        links.resize(26,NULL);
        isEnd=false;
    }
    bool containskey(char ch){
        return links[ch-'a']!=NULL;
    }
    TrieNode* get(char ch){
        return links[ch-'a'];
    }
};
class Trie {
public:
    TrieNode*root;
    Trie() {
        root=new TrieNode();
    }
    
    void insert(string word) {
        TrieNode*node=root;
        for(int i=0;i<word.size();i++)
        {
            if(!node->containskey(word[i])){
                node->links[word[i]-'a']=new TrieNode();
            }
            node=node->get(word[i]);
        }
        node->isEnd=true;
    }
    
    bool search(string word) {
        TrieNode*node=root;
        for(int i=0;i<word.size();i++)
        {
            if(!node->containskey(word[i])) return false;
            node=node->get(word[i]);
        }
        return node->isEnd;
    }
    
    bool startsWith(string prefix) {
        TrieNode*node=root;
        for(int i=0;i<prefix.size();i++)
        {
            if(!node->containskey(prefix[i])) return false;
            node=node->get(prefix[i]);
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
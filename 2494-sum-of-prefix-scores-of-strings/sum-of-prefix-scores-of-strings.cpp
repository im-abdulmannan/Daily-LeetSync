struct Node{
    int count = 0;
    Node *list[26] = {NULL};
    bool containKey(char ch) {return list[ch - 'a'] != NULL;}
    Node* get(char ch) {return list[ch - 'a'];}
    void put(char ch, Node* new_node) {list[ch-'a']=new_node;}
    void inc(char ch) {list[ch-'a']->count++;}
    int retCount(char ch) {return list[ch -'a']->count;}
};

class Solution {
    Node* root;
public:
    Solution() {
        root = new Node;
    }
    
    void insert(string word) {
        Node* node = root;
        for(auto ch:word) {
            if(!node->containKey(ch)) node->put(ch, new Node);
            node->inc(ch);
            node=node->get(ch);
        }
    }

    int search(string word){
        Node* node=root;
        int preCnt=0;
        for(auto ch:word){
            preCnt+=node->retCount(ch);
            node=node->get(ch);
        }
        return preCnt;
    }
    
    vector<int> sumPrefixScores(vector<string>& words) {
        ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        for(auto word:words){
            insert(word);
        }
        int n = words.size();
        vector<int> res(n);
        for(int i = 0; i < n; i++){
            int preCnt = search(words[i]);
            res[i]=preCnt;
        }
        return res;
    }
};
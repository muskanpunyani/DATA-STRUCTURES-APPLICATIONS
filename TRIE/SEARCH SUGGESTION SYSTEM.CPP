Given an array of strings products and a string searchWord. We want to design a system that suggests at most three product names from products after each character of searchWord is typed. Suggested products should have common prefix with the searchWord. If there are more than three products with a common prefix return the three lexicographically minimums products.

Return list of lists of the suggested products after each character of searchWord is typed. 

 

Example 1:

Input: products = ["mobile","mouse","moneypot","monitor","mousepad"], searchWord = "mouse"
Output: [
["mobile","moneypot","monitor"],
["mobile","moneypot","monitor"],
["mouse","mousepad"],
["mouse","mousepad"],
["mouse","mousepad"]
]
Explanation: products sorted lexicographically = ["mobile","moneypot","monitor","mouse","mousepad"]
After typing m and mo all products match and we show user ["mobile","moneypot","monitor"]
After typing mou, mous and mouse the system suggests ["mouse","mousepad"]

Example 2:

Input: products = ["havana"], searchWord = "havana"
Output: [["havana"],["havana"],["havana"],["havana"],["havana"],["havana"]]

Example 3:

Input: products = ["bags","baggage","banner","box","cloths"], searchWord = "bags"
Output: [["baggage","bags","banner"],["baggage","bags","banner"],["baggage","bags"],["bags"]]

Example 4:

Input: products = ["havana"], searchWord = "tatiana"
Output: [[],[],[],[],[],[],[]]

 

Constraints:

    1 <= products.length <= 1000
    There are no repeated elements in products.
    1 <= Σ products[i].length <= 2 * 10^4
    All characters of products[i] are lower-case English letters.
    1 <= searchWord.length <= 1000
    All characters of searchWord are lower-case English letters.

*****************************************************************************************************************************************


class Solution {
public:
    struct node{
        struct node* children[26];
        bool isend;
    };
    struct node *getnode(void)  // creating node
    {
        struct node* pnode=new node;
        pnode->isend=false;
        for(int i=0;i<26;i++)
        {
            pnode->children[i]=NULL;
        }
        return pnode;
    }
    void insert(struct node* root,string key)  // creating trie
    {
        struct node* pcrawl=root;
        for(int i=0;i<key.length();i++)
        {
            int index=key[i]-'a';
            if(!pcrawl->children[index])
            {
                pcrawl->children[index]=getnode();
            }
            pcrawl=pcrawl->children[index];
        }
        pcrawl->isend=true;
    }
    void dfs(struct node* pcrawl,vector<string>& temp,string &key) // searching word with prefix
    {
        if(temp.size()==3)   // need to have atmost 3 product names
            return;
        if(pcrawl->isend)
            temp.push_back(key);  // push the prefix
         for (int i = 0; i < 26; ++i) {
            if (pcrawl->children[i]) {
                key.push_back(char('a'+i));  // check for every new word
                dfs(pcrawl->children[i], temp, key); // do dfs
                key.pop_back();             // pop bcz change the word to another possibility
            }
        }
        
    }
    
    vector<string> search(struct node* root,string key) // searching prefix
    {
        vector<string> temp;
        struct node* pcrawl=root;
        for(int i=0;i<key.length();i++)
        {
            int index=key[i]-'a';
            if(!pcrawl->children[index])
                return {};   // return empty
            pcrawl=pcrawl->children[index];
        }
        dfs(pcrawl,temp,key);
        return temp;
        
    }
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        int n=products.size();
        struct node *root=getnode();
        for(int i=0;i<n;i++)
        {
            insert(root,products[i]);
        }
        vector<vector<string>> ans;
        for(int i=0;i<searchWord.length();i++) // for every substring
        {
            string s=searchWord.substr(0,i+1);
            vector<string> temp;
            temp=search(root,s);    // search the prefix
            ans.push_back(temp);
        }
        return ans;
    }
};

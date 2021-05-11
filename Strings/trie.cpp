struct trie
{
    int cnt;
    trie *link[26];
    trie()
    {
        for (int i = 0; i < 26; i++)
            link[i] = NULL;
        cnt = 0;
    }
};
 
trie *root;
 
void insert(string s)
{
    trie *curr = root;
    for (auto c : s)
    {
        if (!curr->link[c - 'a'])
            curr->link[c - 'a'] = new trie();
        curr = curr->link[c - 'a'];
    }
    curr->cnt++;
}
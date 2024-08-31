#include <iostream>
#include <string>
using namespace std;
class TrieNode
{
public:
    char data;
    TrieNode *childs[26];
    bool isTerminal;
    int childCount;
    TrieNode(char data)
    {
        this->data = data;
        for (int i = 0; i < 26; i++)
        {
            childs[i] = NULL;
        }
        isTerminal = false;
        childCount = 0;
    }
};
class Trie
{
private:
    TrieNode *root = new TrieNode('\0');
    void insert(TrieNode *root, string word)
    {
        if (word.length() == 0)
        {
            root->isTerminal = true;
            return;
        }
        int index = word[0] - 'a';
        TrieNode *child;
        if (root->childs[index] != NULL)
        {
            child = root->childs[index];
        }
        else
        {

            child = new TrieNode(word[0]);
            root->childCount++;
            root->childs[index] = child;
        }
        insert(child, word.substr(1));
    }
    bool search(TrieNode *root, string word)
    {
        if (word.length() == 0)
        {
            return root->isTerminal;
        }
        int index = word[0] - 'a';
        TrieNode *child;
        if (root->childs[index] != NULL)
        {
            child = root->childs[index];
        }
        else
        {
            return false;
        }
        return search(child, word.substr(1));
    }
    bool prefixU(TrieNode *root, string word)
    {
        if (word.length() == 0)
        {
            return true;
        }
        int index = word[0] - 'a';
        TrieNode *child;
        if (root->childs[index] != NULL)
        {
            child = root->childs[index];
        }
        else
        {
            return false;
        }
        return prefixU(child, word.substr(1));
    }

public:
    void insertU(string word)
    {
        insert(root, word);
    }

    bool searchU(string word)
    {
        return search(root, word);
    }

    bool prefix(string word)
    {
        return prefixU(root, word);
    }
    void largest_common_prefix(string first, string &ans)
    {
        TrieNode *temp = root;
        for (int i = 0; i < first.length(); i++)
        {

            if (temp->childCount == 1)
            {
                ans.push_back(first[i]);
                int index = first[i] - 'a';
                temp = temp->childs[index];
            }
            else
            {
                return;
            }
            if (root->isTerminal)
            {
                return;
            }
        }
    }
};
int main()
{
    Trie tr;
    string ans = "";
    tr.insertU("shahzad");
    tr.insertU("shahzu");
    tr.insertU("shah jhana");
    tr.largest_common_prefix("shahzad", ans);
    cout << "Largest common prefix : " << ans << endl;
    return 0;
}
#include <iostream>
#include <string>
using namespace std;
class TrieNode
{
public:
    char data;
    TrieNode *childs[26];
    bool isTerminal;
    TrieNode(char data)
    {
        this->data = data;
        for (int i = 0; i < 26; i++)
        {
            childs[i] = NULL;
        }
        isTerminal = false;
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
};
int main()
{
    Trie tr;
    tr.insertU("shahzad");
    cout << "Status : " << tr.searchU("shahzad") << endl;
    cout << "Prefix : " << tr.prefix("") << endl;
    return 0;
}
#include<bits/stdc++.h>
using namespace::std;

struct TrieNode
{
	const static int ALPHA = 26;
    TrieNode * parent;
    TrieNode * child[ALPHA];
    vector<int> occurrences;
};

struct Trie
{
	TrieNode *root;
    const static int ALPHA = 26;
	Trie(){
		root = (TrieNode *)calloc(1,sizeof(TrieNode));
	}

	void insert(string word,int Idx){
		TrieNode *temp = root;

		for(int i=0;i<word.size();i++){
			if(temp->child[word[i]-'a'] == NULL){
				temp->child[word[i]-'a'] = (TrieNode *)calloc(1,sizeof(TrieNode));
				temp->child[word[i]-'a']->parent = temp;
			}
			temp=temp->child[word[i]-'a'];
		}
		temp->occurrences.push_back(Idx);
	}

	TrieNode * searchWord(TrieNode *trie_node,string word)
    {
            TrieNode * temp = trie_node;

            while (word.size() != 0) {
                if (temp->child[word[0] - 'a'] != NULL) {
                    temp = temp->child[word[0] - 'a'];
                    word.erase(word.begin());
                } else {
                    break;
                }
            }

            if (word.size() == 0 && temp->occurrences.size() != 0)
                return temp;
            else
                return NULL;
    }

    void removeWord(string word)
    {
        TrieNode * temp = searchWord(root, word);

         if (temp == NULL) {
             return;
         }

        temp->occurrences.pop_back();
        bool noChild = true;

        int childCount = 0;
        int i;

        for (i = 0; i < ALPHA; ++i) {
                if (temp->child[i] != NULL) {
                    noChild = false;
                    ++childCount;
                }
            }

        if (!noChild) {
            return;
        }

        TrieNode * traverse;
        while (temp->occurrences.size() == 0 && temp->parent != NULL && childCount < 2)
        {
            traverse = temp->parent;
            for (i = 0; i < ALPHA; ++i)
            {
                if (temp == traverse->child[i]) {
                        traverse->child[i] = NULL;
                        break;
                }
            }
            free(temp);
            temp = traverse;

            for (i = 0; i < ALPHA; ++i) {
                if (temp->child[i] != NULL) {
                        ++childCount;
                }
            }
        }
    }

    void lexicographPrint(TrieNode * trie_tree, vector<char> printUtilVector)
    {
        int i;
        bool noChild = true;

        vector<int>::iterator itr = trie_tree->occurrences.begin();

        for (i = 0; i < ALPHA; ++i)
        {
             if (trie_tree->child[i] == NULL)
             {
                    continue;
             }
             else
             {
               noChild = false;
               printUtilVector.push_back('a' + i);
               lexicographPrint(trie_tree->child[i], printUtilVector);
               printUtilVector.pop_back();
            }
        }

        if (trie_tree->occurrences.size() != 0)
        {
         	vector<char>::iterator itr = printUtilVector.begin();
   			while (itr != printUtilVector.end())
   			{
                    printf("%c", *itr);
                    ++itr;
            }
            printf(" -> @ index -> ");

            vector<int>::iterator counter = trie_tree->occurrences.begin();
            while (counter != trie_tree->occurrences.end())
            {
                    printf("%d, ", *counter);
                    ++counter;
            }

                printf("\n");
        }
        printUtilVector.pop_back();
    }

};



int main()
{
    Trie trie;
    trie.insert("abc",1);
    trie.insert("abcd",1);
    vector<char> util;
    trie.lexicographPrint(trie.root,util);


	return 0;
}

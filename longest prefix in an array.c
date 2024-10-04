#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Alphabet size (# of symbols)
#define ALPHABET_SIZE (26)

// Converts key current character into index
// use only 'a' through 'z' and lower case
#define CHAR_TO_INDEX(c) ((int)c - (int)'a')

// Trie node
struct TrieNode
{
    struct TrieNode *children[ALPHABET_SIZE];
    // isLeaf is true if the node represents end of a word
    int isLeaf;
};

// Returns new trie node (initialized to NULLs)
struct TrieNode *getNode(void)
{
    struct TrieNode *pNode = (struct TrieNode *)malloc(sizeof(struct TrieNode));
    if (pNode)
    {
        int i;
        pNode->isLeaf = 0;
        for (i = 0; i < ALPHABET_SIZE; i++)
            pNode->children[i] = NULL;
    }
    return pNode;
}

// If not present, inserts the key into the trie
// If the key is a prefix of trie node, just marks leaf node
void insert(struct TrieNode *root, const char *key)
{
    int length = strlen(key);
    int index;
    struct TrieNode *pCrawl = root;

    for (int level = 0; level < length; level++)
    {
        index = CHAR_TO_INDEX(key[level]);
        if (!pCrawl->children[index])
            pCrawl->children[index] = getNode();
        pCrawl = pCrawl->children[index];
    }
    // mark last node as leaf
    pCrawl->isLeaf = 1;
}

// Counts and returns the number of children of the current node
int countChildren(struct TrieNode *node, int *index)
{
    int count = 0;
    for (int i = 0; i < ALPHABET_SIZE; i++)
    {
        if (node->children[i] != NULL)
        {
            count++;
            *index = i;
        }
    }
    return count;
}

// Perform a walk on the trie and return the longest common prefix string
char *walkTrie(struct TrieNode *root)
{
    struct TrieNode *pCrawl = root;
    int index;
    char *prefix = (char *)malloc(100 * sizeof(char)); // Assuming max prefix length is 100
    int prefixLength = 0;

    while (countChildren(pCrawl, &index) == 1 && pCrawl->isLeaf == 0)
    {
        pCrawl = pCrawl->children[index];
        prefix[prefixLength++] = 'a' + index;
    }
    prefix[prefixLength] = '\0'; // Null-terminate the string
    return prefix;
}

// A Function to construct trie
void constructTrie(char *arr[], int n, struct TrieNode *root)
{
    for (int i = 0; i < n; i++)
        insert(root, arr[i]);
}

// A Function that returns the longest common prefix from the array of strings
char *commonPrefix(char *arr[], int n)
{
    struct TrieNode *root = getNode();
    constructTrie(arr, n, root);
    // Perform a walk on the trie
    return walkTrie(root);
}

// Driver program to test above function
int main()
{
    char *arr[] = {"nash ", "naga", "naresh", "naren"};
    int n = sizeof(arr) / sizeof(arr[0]);

    char *ans = commonPrefix(arr, n);

    if (strlen(ans))
        printf("The longest common prefix is %s\n", ans);
    else
        printf("There is no common prefix\n");

    free(ans); // Free allocated memory for prefix
    return 0;
}


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ALPHABET_SIZE 26

// Trie Node structure
struct TrieNode {
    struct TrieNode *children[ALPHABET_SIZE];
    int isEndOfWord;
};

// Create a new Trie node
struct TrieNode *getNode() {
    struct TrieNode *node = (struct TrieNode *)malloc(sizeof(struct TrieNode));
    node->isEndOfWord = 0;
    for (int i = 0; i < ALPHABET_SIZE; i++)
        node->children[i] = NULL;
    return node;
}

// Insert a word into the Trie
void insert(struct TrieNode *root, char *key) {
    struct TrieNode *crawl = root;
    for (int i = 0; key[i] != '\0'; i++) {
        int index = key[i] - 'a';
        if (!crawl->children[index])
            crawl->children[index] = getNode();
        crawl = crawl->children[index];
    }
    crawl->isEndOfWord = 1;
}

// Search for a word in the Trie
int search(struct TrieNode *root, char *key) {
    struct TrieNode *crawl = root;
    for (int i = 0; key[i] != '\0'; i++) {
        int index = key[i] - 'a';
        if (!crawl->children[index])
            return 0;
        crawl = crawl->children[index];
    }
    return crawl->isEndOfWord;
}

int main() {
    struct TrieNode *root = getNode();

    insert(root, "hello");
    insert(root, "world");

    printf("Search hello: %s\n", search(root, "hello") ? "Found" : "Not Found");
    printf("Search test: %s\n", search(root, "test") ? "Found" : "Not Found");

    return 0;
}

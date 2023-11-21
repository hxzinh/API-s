#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node Node;

struct Node {
    Node* children[26];
    int isLeaf;
};

Node* newNode() {
    Node* node = (Node*)malloc(sizeof(Node));
    for(int i = 0; i < 26; i++) node->children[i] = NULL;
    node->isLeaf = 0;
    return node; 
}

void freeNode(Node* curNode) {
    for(int i = 0; i < 26; i++) 
        if(curNode->children[i] != NULL) freeNode(curNode->children[i]);
    free(curNode);
}

Node* Insert(Node* root, char* word) {
    Node* temp = root;
    for(int i = 0; word[i] != '\0'; i++) {
        int id = word[i] - 'a';
        if(temp->children[id] == NULL) 
            temp->children[id] = newNode();

        temp = temp->children[id];
    }

    temp->isLeaf = true;
    return root;
}

Node* FindNode(Node* root, char* word) {
    Node* temp = root;
    for(int i = 0; word[i] != '\0'; i++) {
        int id = word[i] - 'a';
        if(temp->children[id] == NULL) return 0;

        temp = temp->children[id];
    }

    return (temp != NULL && temp->isLeaf);
}

int main() {
    Node* root = newNode();

    char filename[] = "input.txt";
    FILE *file = fopen(filename, "r");
    char *line;
    line = (char*)malloc(128 * sizeof(char));
    while(fscanf(file, "%s", line) == 1) {
        Insert(root, line);
        //printf("%s", line);
    }

    char *s;
    s = (char*)calloc(128, sizeof(char));
    puts("What word do you want to check?");
    scanf("%s", s);
    if(FindNode(root, s)) printf("%s exist!!");
    else printf("%s NOT exist!!");
    return 0;
}

#include <stdbool.h>
#include<stdio.h>
#include<stdlib.h>
#include <string.h>

typedef struct Node {
    char* key;
    int val;
    struct Node *next;
}Node;

Node* node_create(const char* key,int value,Node *next){
    Node *n=(Node*)malloc(sizeof(Node));
    n->key = strdup(key);
    n->val=value;
    n->next=next;
    return n;
}

Node* node_create_k(const char* key) {
    return node_create(key, 0, NULL);
}

Node* node_create_empty() {
    return node_create("", 0, NULL);
}

typedef struct LinkedListMap {
    Node *dummyhead;
    int size;
} LinkedListMap;

LinkedListMap* map_create() {
    LinkedListMap *map = (LinkedListMap*)malloc(sizeof(LinkedListMap));
    map->dummyhead = node_create_empty();
    map->size = 0;
    return map;
}

int getSize(LinkedListMap* map) {
    return map->size;
}

bool isEmpty(LinkedListMap* map) {
    return map->size==0;
}

Node* getNode(LinkedListMap* map,const char* key) {
    Node* cur=map->dummyhead->next;
    while (cur!=NULL) {
        if (strcmp(cur->key, key) == 0) {
            return cur;
        }
        cur=cur->next;
    }
    return NULL;
}

bool contains(LinkedListMap* map,const char* key) {
    return getNode(map,key)!=NULL;
}

int get(LinkedListMap* map,const char* key) {
    Node* node=getNode(map,key);
    return node? node->val:-1;
}

// add：key存在则更新val；不存在则新增
void add(LinkedListMap* map,const char* key,int val) {
    Node* node=getNode(map,key);
    if (node==NULL) {
        map->dummyhead->next = node_create(key, val, map->dummyhead->next);
        map->size++;
    }
    else {
        node->val=val;
    }
}

// set：只更新已经存在的key
void set(LinkedListMap* map,const char* key,int newval) {
    Node* node=getNode(map,key);
    if (node==NULL) {
        printf("unfounded key:%s!\n",key);
        return;
    }
    node->val=newval;
}

int removeNode(LinkedListMap* map,const char* key) {
    Node* prev=map->dummyhead;
    while (prev->next!=NULL) {
        if (strcmp(prev->next->key, key) == 0) {
            break;
        }
        prev = prev->next;
    }
    if (prev->next != NULL) {
        Node* delNode = prev->next;
        int ret = delNode->val;
        prev->next = delNode->next;

        free(delNode->key);
        free(delNode);
        map->size--;
        return ret;
    }
    printf("unfounded key:%s\n", key);
    return -1;
}

int main()
{
    printf("Success Text\n");

    char* words[] = {
        "Success", "rarely", "comes", "from", "dramatic", "changes", "or", "sudden", "breakthroughs.",
        "Instead,", "it", "emerges", "from", "small,", "consistent", "actions", "repeated", "over", "time.",
        "A", "person", "who", "reads", "just", "ten", "pages", "daily", "will", "complete", "over", "a", "dozen", "books", "annually.",
        "Someone", "who", "exercises", "for", "fifteen", "minutes", "each", "morning", "builds", "strength", "gradually", "but", "steadily.",
        "The", "key", "lies", "not", "in", "perfection", "but", "in", "persistence—showing", "up", "even", "when", "motivation", "fades",
        "and", "continuing", "the", "practice", "until", "it", "becomes", "automatic."
    };
    int wordNum = sizeof(words)/sizeof(words[0]);

    printf("Total words: %d\n", wordNum);

    LinkedListMap* map = map_create();

    for(int i = 0; i < wordNum; i++)
    {
        const char* w = words[i];
        if(contains(map, w))
        {
            int c = get(map, w);
            set(map, w, c + 1);
        }
        else
        {
            add(map, w, 1);
        }
    }

    printf("Total different words: %d\n", getSize(map));
    printf("Frequency of from: %d\n", get(map, "from"));
    printf("Frequency of it: %d\n", get(map, "it"));
    printf("Frequency of in: %d\n", get(map, "in"));
    
    return 0;
}

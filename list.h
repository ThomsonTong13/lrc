#pragma once

#define STR_LEN 100

typedef unsigned char u8;
typedef unsigned int u32;

typedef float timeData;
typedef char *strData;

typedef struct _LrcData{
	timeData time;
	strData str;
} LrcData;

typedef struct _ListNode{
	LrcData Data;
	struct _ListNode *next;
} Node;

Node *InitList();
Node *InsertList(Node *, LrcData);
Node *DeleteNode(Node *, timeData, strData);
void traverselist(Node *);
int DestroyNode(Node *node);

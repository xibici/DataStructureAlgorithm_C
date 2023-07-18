#pragma once
#include "Member.h"


typedef struct __bNode {
	    Member data;
		struct __bNode* left;
		struct __bNode* right;
}BNode;


BNode *search(BNode *p,const Member *x);

BNode *add(BNode *p,const Member *x);

static void setBNode(BNode* p, const Member* x, const BNode* left, const BNode* right);
static BNode* allocBNode();
void preOrderPrint(BNode* p);
void postOrderPrint(BNode* p);
void inOrderPrint(BNode* p);

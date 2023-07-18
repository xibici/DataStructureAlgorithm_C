#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include "BSTree.h"


BNode* search(BNode *p,const Member x) {
    if (p == NULL) {//节点为空自动创建
        printf("p为空！！\n");
        return;
    }

    if (x.id == p->data.id) {
        return p;
    }
    else if(x.id <= p->data.id)
    {
        return search(p->left, x);
    }else
    {
        return search(p->right, x);

    }
    printf("没找到!\n");
    return NULL;
}

void inOrderPrint(BNode* p) {
    if (p == NULL) {//节点为空自动创建
        //printf("p为空！！");
        return;
    }
    inOrderPrint(p->left);
    printf("id:%d\tname:%s\n\n", p->data.id, p->data.name);

    inOrderPrint(p->right);
}
void postOrderPrint(BNode* p) {
    if (p == NULL) {//节点为空自动创建
        //printf("p为空！！");
        return;
    }
    postOrderPrint(p->left);
    postOrderPrint(p->right);
    printf("id:%d\tname:%s\n\n", p->data.id, p->data.name);

}
void preOrderPrint(BNode* p) {
    if (p == NULL) {//节点为空自动创建
        //printf("p为空！！");
        return;
    }
    printf("id:%d\tname:%s\n\n", p->data.id, p->data.name);

    preOrderPrint(p->left);

    preOrderPrint(p->right);
}


BNode* add(BNode* p, const Member* x) {
    if (p==NULL) {//节点为空自动创建
        p = allocBNode();
        setBNode(p,x,NULL,NULL);
        return p;
    }
    
    if (x->id < p->data.id) {
        p->left=add(p->left, x);
    }
    else if(x->id > p->data.id)
    {
        p->right = add(p->right, x);
    }
    else {
        printf("相等不处理");
    }

    return p;
}

BNode* del(BNode** root, const Member* x) {
    //用多一个二重指针保存root的地址
    BNode** p = root;
    BNode** next = root;
    BNode** left = root;//LeftMax用

    if (*p == NULL) {//节点为空自动创建
        printf("删除失败!");
        return p;
    }
    //先找点
    while (1)
    {
        if (x->id < (*p)->data.id) {
            p =&((*p)->left);
        }
        else if (x->id > (*p)->data.id) {
            p = &((*p)->right);
        }
        else if (x->id == (*p)->data.id) {
            break;
        }
        else {
            printf("改不到该点");
            return;
        }
    }


    //找到该点 但是分两种情况 左子树为空 左子树不为空
    if ((*p)->left == NULL) {//左子树为空时候把右子树放在该点 如果右子树也为空直接空了
        (*p) = (*p)->right;
        return;
    }
    else
    {//最后剩下一种情况 左右子树都不为空的情况 就找LeftMax或者RightMin的点进行替换
     //这里找leftMax  如删4找4的leftMax  左子树最大值
        left = &((*p)->left);
        while ((*left)->right!=NULL) {
            left = &((*p)->right);

        }
        //找到最大值
        (*next)->left = (*p)->left;
        (*next)->right = (*p)->right;
        p = next;



    }

}


static void setBNode(BNode* p, const Member* x, const BNode* left, const BNode* right) {
    p->data = *x;
    p->left = left;
    p->right = right;
}

static BNode* allocBNode() {
    return (BNode*)calloc(1,sizeof(BNode));
}

int doOne(BNode* root) {
    Member m1;
    m1.id = 8;
    m1.name = "xiaowang";
    root = add(root, &m1);

    m1.id = 4;
    m1.name = "a1";
    root = add(root, &m1);
    m1.id = 12;
    m1.name = "a2";
    root = add(root, &m1);
    m1.id = 2;
    m1.name = "w1";
    root = add(root, &m1);
    m1.id = 3;
    m1.name = "a3";
    root = add(root, &m1);
    m1.id = 14;
    m1.name = "w2";
    root = add(root, &m1);
    m1.id = 1;
    m1.name = "e1";
    root = add(root, &m1);
    m1.id = 15;
    m1.name = "e2";
    root = add(root, &m1);
    m1.id = 13;
    m1.name = "e6";
    root = add(root, &m1);

    m1.id = 6;
    m1.name = "a6";
    root = add(root, &m1);
    m1.id = 7;
    m1.name = "a7";
    root = add(root, &m1);
    m1.id = 5;
    m1.name = "a5";
    root = add(root, &m1);
    m1.id = 17;
    m1.name = "a17";
    root = add(root, &m1);


    //inOrderPrint(root);
    preOrderPrint(root);
    //postOrderPrint(root);
    Member tmpX = { "",1 };
    BNode* p1=search(root, tmpX);
    //printf("%p\t%s   %d\n",p1,p1->data.name,p1->data.id);
    Member delX1 = { "",4};
    printf("-------------------------------------------------\n\n");
    del(&root, &delX1);
    preOrderPrint(root);

}


int main01()
{
    BNode* root=NULL;
    //BNode pDir = {"s",6};
    //root->data;
   
    doOne(root);
    //search(bSTree, m1);
    printf("13");
    return EXIT_SUCCESS;
}
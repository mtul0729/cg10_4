#include <stdio.h>
#include <stdlib.h>
struct node{
    int num;
    struct node* next;
};
typedef struct node node;
node * creat(int x){
    node *p;
    p=(node *) malloc(sizeof (node));
    if(!p)exit(1);
    p->num=x;
    return p;
}
node *node_delete(node *head,int x){
    node*pre,*p;
    if(head->num==x){
        pre=head;
        head=head->next;
        free(pre);
        return head;
    }

    p=head->next;
    while (p->num!=x){
        pre=p;
        if(p->next==NULL)return head;//遍历到最后一个节点也没找到，结束
        p=p->next;
    }
    pre->next=p->next;
    return head;
}
int main() {
    node * head;
    int x;
    node *p1;
    scanf("%d",&x);
    head=creat(x);
    head->next=NULL;
    while(1){
        scanf("%d",&x);
        if(x==-1)break;
        p1=creat(x);
        if(p1==NULL)exit(1);
        p1->next=head;
        head=p1;
    }

    int y;
    scanf("%d",&y);
    head=node_delete(head,y);
    head=node_delete(head,y);

    p1=head;
    while (p1!=NULL){
        printf("%d ",p1->num);
        p1=p1->next;
    }

    return 0;
}

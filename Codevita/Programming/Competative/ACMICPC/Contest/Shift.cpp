#include<bits/stdc++.h>
using namespace::std;

struct node{
      int data;
      struct node *next;
};
struct node* CreateNode(int x){
      node *nn = (node *)calloc(1,sizeof(node));
      nn->data = x;
      nn->next  = NULL;
      return nn;
}
struct node *CreateList(int Num){
      struct node *head  = (node *)calloc(1,sizeof(node));
      head->data = Num%10;
      Num = Num/10;
      while(Num>0){
            node *x =  CreateNode(Num%10);
            x->next = head;
            head = x;
            Num = Num/10;
      }
      return head;

};
int main(){
      node *head = CreateList(145);
      while(head){
            cout << head->data << " ";
            head = head->next;
      }

}

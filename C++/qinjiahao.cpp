#include<stdio.h> 
#include<stdlib.h>

typedef struct node{
	char inf[20];
	int gra;
	struct node* next;
}N;

N list1,list2;

int n,sum=0;

N creat (void){
	N *p1,*p2,*head;
	n=0;
	p1=p2=(N*)malloc(sizeof(N));
	printf("input inf & gra of student:\n");
	scanf("%s%d",p1->inf,&p1->gra);
	head=NULL;
	while(p1->inf!=0){
		n=n+1;
		if(n==1){
			head=p1;
		}
		else{
			p2->next=p1;
		}
		p2=p1;
		p1=(N*)malloc(sizeof(N));
		scanf("%s%d",p1->inf,&p1->gra);
	}
	p2->next=NULL;
	return(head);
}

N insert (N *ah,N *bh){
	N pa1,pa2,pb1,pb2;
	pa1=pa2-ah;
	pb1=pb2=bh;
	while(pa1->next!=NULL || (pa1=NULL && pb1!=NULL)){
		while(pb1->inf>pa1->inf && (pa1->next!=NULL)){
			pa2=pa1;
			pa1=pa1->next;
		}
		if(pb1->inf<=pa1->inf){
			if(ah==NULL){
				ah=pb1;
			}
			else{
				pa2->next=pb1;
				pb1=pb1->next;
				pb2->next=pa1;
				pa2=pb2;
				pb2=pa1;
			}
		}
	}
}

int main(){
	int i,j,a;
	for(i=1;i<=a)
	return 0;
}

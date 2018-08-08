#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node{
	char data;
	struct node *next;
}*head1, *head2;

void push1(char d) {
	struct node *t = (struct node*)malloc(sizeof(struct node));
	t->data = d;
	t->next = head1;
	head1 = t;
}

char pop1() {
	struct node *temp;
	char ret = head1->data;
	temp = head1;
	head1 = head1->next;
	free(temp);
	return ret;
}

void push2(char d) {
	struct node *t = (struct node*)malloc(sizeof(struct node));
	t->data = d;
	t->next = head2;
	head2 = t;
}

char pop2() {
	struct node *temp;
	char ret = head2->data;
	temp = head2;
	head2 = head2->next;
	free(temp);
	return ret;
}

void main() {
	int i;
	char str[10], temp[10];
	int flag = 0;
	printf("Enter String : ");
	//scanf("%s[^\n]",
	gets(str);
	//scanf("%s[^\n]");
	head1 = NULL;
	head2 = NULL;
	for(i = 0; i < strlen(str); i++) push1(str[i]);
	for(i = 0; i < strlen(str); i++){
		temp[i] = pop1();
		push2(temp[i]);
	}
//working till HERE
	for(int i =0; i<strlen(str); i++){
		if(temp[i]!=pop2()) {flag = 1; break;}
	}
	(flag == 1)?printf("Not pallindrome"):printf("pallindrome");
}
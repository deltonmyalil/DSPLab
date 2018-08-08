#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node{
	char data;
	struct node *next;
}*head, *current;

void push(char d) {
	struct node *t = (struct node*)malloc(sizeof(struct node));
	t->data = d;
	t->next = head;
	head = t;
}

char pop() {
	struct node *temp;
	char ret = head->data;
	temp = head;
	head = head->next;
	free(temp);
	return ret;
}

void main() {
	int i;
	char str[10];
	int flag = 0;
	printf("Enter String : ");
	gets(str);
	//scanf("%s[^\n]");
	head = NULL;
	for(i = 0; i < strlen(str); i++) {
		push(str[i]);
	}
	for(i = 0; i < strlen(str); i++){ 
		if(pop()!=str[i]) {flag = 1; break;}
	}
	(flag == 1)?printf("Not pallindrome"):printf("pallindrome");
}
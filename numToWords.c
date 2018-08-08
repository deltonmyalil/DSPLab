#include<stdio.h>
#include<string.h>

void special(int n){
	switch(n){
	case 10: printf("ten ");
			break;
	case 11: printf("eleven ");
			break;
	case 12: printf("twelve ");
			break;
	case 13: printf("thirteen ");
			break;
	case 14: printf("fourteen ");
			break;
	case 15: printf("fifteen ");
			break;
	case 16: printf("sixteen ");
			break;
	case 17: printf("seventeen ");
			break;
	case 18: printf("eighteen ");
			break;
	case 19: printf("nineteen ");
			break;
	}
}

void ones(int n) {
	if(n>9) puts("Ones Error");
	switch(n){
	case 0: printf("");
			break;
	case 1: printf("one ");
			break;
	case 2: printf("two ");
			break;
	case 3: printf("three ");
			break;
	case 4: printf("four ");
			break;
	case 5: printf("five ");
			break;
	case 6: printf("six ");
			break;
	case 7: printf("seven ");
			break;
	case 8: printf("eight ");
			break;
	case 9: printf("nine ");
			break;
	}
}

void twos(int n) {
	if(n>99) puts("Twos Error");
	int temp;
	temp = n/10;
	switch(temp){
	case 0: printf("");
			break;
	case 1: special(n);
			return;
	case 2: printf("twenty ");
			break;
	case 3: printf("thirty ");
			break;
	case 4: printf("forty ");
			break;
	case 5: printf("fifty ");
			break;
	case 6: printf("sixty ");
			break;
	case 7: printf("seventy ");
			break;
	case 8: printf("eighty ");
			break;
	case 9: printf("ninety ");
			break;
	}
	ones(n%10);
}

void hundred(int n){
	int temp = n/100;
	ones(temp);
	if(temp!=0)
		printf("hundred and ");
	twos(n%100);
}

void thousand(int n){
	int temp = n/1000;
	
		twos(temp);
	//if(temp>1000)
	if(temp!=0)
		printf("thousand, ");
	hundred(n%1000);
}

void lakh(int n){
	int temp = n/100000;
	twos(temp);
	if(temp!=0)
		printf("lakh, ");
	thousand(n%100000);
}

void crore(int n){
	int temp = n/10000000;
	twos(temp);
	printf("crore, ");
	lakh(n%10000000);
}

void main() {
	int num, digit, rem, temp;
	printf("Input number: ");
	scanf("%d",&num);
	if(num == 0) {
		puts("Zero");
		return;
	}
//	printf("Check");
	digit = 0;
	temp = num;
	while (temp != 0) {
		temp = temp/10;
		digit++;
	}
//	printf("digits = %d", digit);
//	printf("%d %d", temp, digit);  // digits stored
	if(digit<=2) {
		twos(num);
	}
	else if(digit<=3){
/*		int temp = num/100;
		ones(temp);
		printf("hundred and ");
		twos(num%100);
*/		
		hundred(num);
	}
	else if(digit<=5){
		thousand(num);
	}
	else if(digit<=7){
		lakh(num);
	}
	else if(digit<=9){
		crore(num);
	}
	else
		printf("That's too much");
}
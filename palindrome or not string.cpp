#include <stdio.h>
int main()
{
	char str[100];
	printf("enter a string:");
	scanf("%s",str);
	int i,len=0;
	while(str[len]) len++;
	for(i=0;i<len/2;i++){
		if(str[i]!=str[len-i-1]){
			printf(" not palindrome");
			return 0;
		}
	}
	printf("palindrome");
	return 0;
	
}

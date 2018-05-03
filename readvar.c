#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <get.h>

int main(void)
{
	char *query=getenv("QUERY_STRING");
	int len=strlen(query);
	int i;
	printf("Content-Type: text/plain\n\n");
	printf("Query String: %s\n",query);
	printf("Value of hello: %s\n",get_variable("hello"));
	return 0;
}

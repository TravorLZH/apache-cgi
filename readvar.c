#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <get.h>
#include <url.h>

char buf[BUFSIZ];

int main(void)
{
	char *query=getenv("QUERY_STRING");
	int len=strlen(query);
	char *val=get_variable("hello");
	int i;
	printf("Content-Type: text/plain\n\n");
	printf("Query String: %s\n",query);
	printf("Value of hello: %s\n",val);
	url_decode(val,strlen(val),buf,BUFSIZ);
	printf("After decode: %s\n",buf);
	return 0;
}

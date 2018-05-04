#include <cgi/get.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char tmp[BUFSIZ];

char run=0;

char *get_variable(char *name)
{
	char *query=getenv("QUERY_STRING");
	char *ptr=tmp;
	int qlen=strlen(query);
	int len=strnlen(name,BUFSIZ);	
	memcpy(tmp,query,qlen);
	strtok(tmp,"&");
	while(memcmp(ptr,name,len)){
		if((size_t)(ptr-query)>=qlen){
			return NULL;
		}
		ptr+=strlen(ptr)+1;
	}
	return ptr+len+1;
}

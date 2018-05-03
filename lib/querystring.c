#include <get.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char vars[32][BUFSIZ];

char **get_variables(void)
{
	memset(vars,0,sizeof(vars));	// Clear the buffer
	char *query=getenv("QUERY_STRING");
	char *ptr=query;
	int len=strlen(query);
	int i;
	if(len<=1){
		return NULL;
	}
	strtok(query,"&");
	for(i=0;i<32;i++){
		strcpy(vars[i],query);
		query+=strlen(query)+1;
		printf("%s\n",vars[i]);
	}
	return (char**)vars;
}

char *get_variable(char *name)
{
	get_variables();
	int len=strlen(name);
	int i;
	for(i=0;vars[i]!=NULL;i++){
		int i=memcmp(name,vars[i],len);
		printf("Comparison: %d\n",i);
	}
	return NULL;
}

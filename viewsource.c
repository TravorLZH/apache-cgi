#include <stdio.h>
#include <cgi/get.h>

int main(void)
{
	printf("Content-Type: text/plain\n\n");
	printf("file=%s\n",get_variable("file"));
	return 0;
}


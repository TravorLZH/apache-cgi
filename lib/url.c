#include <string.h>
#include <ctype.h>

#define	NON_NUM	'0'

static int hex2num(char c)
{
	if(islower(c)){return c-'a'+10;}
	if(isupper(c)){return c-'A'+10;}
	if(isdigit(c)){return c-'0';}
	return NON_NUM;
}

int url_decode(const char *url,int url_size,char *result,int result_size)
{
	char ch,ch1,ch2;
	int i;
	int j;	// Result index
	for(i=0,j=0;(i<url_size) && (j<result_size);i++,j++){
		switch(ch){
		case '+':	// If we met space
			result[j]=' ';
			break;
		case '%':
			if(i+2<url_size){
				ch1=hex2num(url[i+1]);	// Higher 4 bits
				ch2=hex2num(url[i+2]);	// Lower 4 bits
				if((ch1!=NON_NUM) && (ch2!=NON_NUM)){
					result[j]=(char)((ch1<<4)|ch2);
				}
				i+=2;
			}
			break;
		default:
			result[j++]=ch;
			break;
		}
	}
	result[j]='\0';	// null-terminator
	return j;
}


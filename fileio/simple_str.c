  #include <stdio.h>
  #include <stdlib.h>
  #include <string.h>
  #define MAX_LINE 1024


int length(char * s)
{
     char *start = s;
     while(*s)
     {
         s++;
     }
     return s- start;
}


void trim(char s[])
{

	int c = length(s);
	printf("dunb ass %c\n",s[c+10]);
	while(s[c] == ' ' || s[c] == '\0') c--;
	s[c+1] = '\0';
}



int compare(char * s, char * t)
{
	while(*s -*t ==0)
	{
		s++;
		t++;
	}
	return *s-*t;

}

int main()
{
    char str[100];
    puts("please input a string");
    fgets(str,100,stdin);
    printf("length of that string is  %d\n",length(str));
    printf("%d\n",compare("apple","apple"));
    return 0;
}

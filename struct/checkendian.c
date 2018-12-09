#include <stdio.h>
#include <limits.h>

void print_bin(unsigned char byte)
{
    int i = CHAR_BIT; /* however many bits are in a byte on your platform */
    while(i--) {
        putchar('0' + ((byte >> i) & 1)); /* loop through and print the bits */
    }
    printf("\n\n");
}

void print_bin_int(unsigned int integer)
{
    int i = CHAR_BIT * sizeof integer; /* however many bits are in an integer */
    while(i--) {
        putchar('0' + ((integer >> i) & 1));
    }
    printf("\n\n");
}



int checkCPUendian()
{
  union
  {
    unsigned int a;
    unsigned char b;
  }c;
  c.a = 1;
  printf("a = %a , b= %a \n",c.a , c.b);
  printf("a = %X , b= %X \n",c.a , c.b);
  printf("a = %p , b= %p \n",c.a , c.b);
  printf("a = %u , b= %u \n",c.a , c.b);
  print_bin(c.b);
  print_bin_int(c.a);
  return (c.b == 1);
}

int main(int argc, char const *argv[]) {
	if(checkCPUendian()){
		printf("Little endian platform!\n");
	} else {
	
		printf("Big Endian platform!\n");
	}

	return 0;
}

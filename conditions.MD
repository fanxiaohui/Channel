C语言的if语句

没有boolean，所以if(1), while(1) 这些都是死循环的意思

```c
int flag = 0;

for (int i = strlen(response) - 1; response[i] == '\n' || response[i] == '\r'; i--, flag++); // for循环还能这么写，还有这种一个小括号里面把事情都做了的，似乎java里也有类似的
if (flag == 4)
    break;
length += len;
```        
由于没有boolean类型，0就是false，1是true
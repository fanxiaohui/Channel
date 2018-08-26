#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct_sample.h"


void create_struct() {

	//method1 ，按照声明变量的顺序初始化
	//struct Stuff stuff1 = {"name",20,100};
	struct Stuff stuff1 = { "name",20 }; //当然我只初始化部分成员也是可以的，比如long 默认就会赋值0


	//指定初始化
	struct Stuff stuff2  = {
		.name = "John",
		.age = 24,
		.salary = 1000,
	};
	

	struct Stuff* p_stuff1;
	struct Stuff* p_stuff2;

	p_stuff1 = &stuff1;
	printf("access via pointer %s , %d, %d\n",p_stuff1->name,p_stuff1->age,p_stuff1->salary);


	int n = 2;


	char name[] = "name of stuff1";
	char name2[] = "name of stuff2";

	
	stuff1.name = name;
	stuff1.age = 30;
	printf("name of stuff1 is %s, whose age is %d salary is %d \n", stuff1.name, stuff1.age,stuff1.salary);
	printf("name of stuff2 is %s, whose age is %d salary is %d \n", stuff2.name, stuff2.age, stuff2.salary);

	//初始化结构体数组可以这么干
	struct Stuff stuffs[2] = {
		{
			.name="sam",
			.age = 20,
			.salary =1000,
		},
		{
			.name = "Bob",
			.age =20,
			.salary =1000,
		}
	};

	struct Stuff* p_stu;
	p_stu = (struct Stuff*)malloc(sizeof(struct Stuff) * n);

	if (p_stu != NULL) {
		p_stu->name = "first";
		p_stu->age = 11;
		p_stu->salary = 1000;
		
		p_stu++;
		p_stu->name = "second";
		p_stu->age = 12;
		p_stu->salary = 1200;

		while (n-- >0)
		{
			printf("vai pointer name %s , age %d, salary %d\n", p_stu->name, p_stu->age, p_stu->salary);
			p_stu--;
		}
		p_stu++;
		free(p_stu);
	}


}


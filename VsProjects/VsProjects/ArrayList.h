typedef struct
{
	//保存元素的数组指针  
	int *data;
	//当前元素的个数  
	int index;
	//数组最多容纳的元素  
	int max;
}st;




st *create(int num);

//数组扩容，默认扩大两倍
void resize(st *ss);

void addElement(st *ss, int value);

int size(st *ss);

void iterating_elements(st *ss);

int remove_element_at(st *list, int index);
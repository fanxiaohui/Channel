typedef struct
{
	//����Ԫ�ص�����ָ��  
	int *data;
	//��ǰԪ�صĸ���  
	int index;
	//����������ɵ�Ԫ��  
	int max;
}st;




st *create(int num);

//�������ݣ�Ĭ����������
void resize(st *ss);

void addElement(st *ss, int value);

int size(st *ss);

void iterating_elements(st *ss);

int remove_element_at(st *list, int index);
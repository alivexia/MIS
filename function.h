void show_welcome();
void add_book();
void query_book();
void modify_book();
void delete_book();


struct Data {
	int year;
	int month;
	int day;
};


struct Book {
	int book_id;//ÿһ�����ID
	char isbn_id[14];//��½��/ISBN
	char name[81];//����
	char author[81];//������
	int category; //�����
	float price;//�۸�
	char press[81];	//������
	struct Data press_data;//����ʱ��
	int exist; //�ǲ��Ǵ���ϵͳ��
};
 
struct link {
	struct Book b;
	struct link *next;
};
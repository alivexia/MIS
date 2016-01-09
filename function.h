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
	int book_id;//每一本书的ID
	char isbn_id[14];//登陆号/ISBN
	char name[81];//书名
	char author[81];//作者名
	int category; //分类号
	float price;//价格
	char press[81];	//出版社
	struct Data press_data;//出版时间
	int exist; //是不是存在系统里
};
 
struct link {
	struct Book b;
	struct link *next;
};
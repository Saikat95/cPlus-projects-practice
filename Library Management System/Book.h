class Book{
	private:
		char bookNo[6];
		char bookName[20];
		char authorName[20];
	public:
		char* get_bookNo();
		char* get_bookName();
		char* get_authorName();
		void create_book();
		void show_book() const;
		void modify_book();
		void report();
};

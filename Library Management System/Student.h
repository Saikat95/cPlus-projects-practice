class Student{
	private:
		char rollNo[6];
		char studentName[20];
		char studentBookNo[6];
		int token;
		
	public:
		char* get_rollNo();
		char* get_studentName();
		char* get_studentBookNo();
		void set_studentBookNo(char t[]);
		int get_token();
		void add_token();
		void reset_token();
		void create_student();
		void show_student();
		void modify_student();
		void report();
};


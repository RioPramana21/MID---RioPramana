struct Patient{
	char name[255];
	char monthName[255];
	int dd, mm, yy;
	long long int dobInNumber;
};

struct Node{
	Patient p;
	Node *next, *prev;
};
/*

// Data structs for a list of ints

struct ListNode {
  int value;
  struct ListNode * next;
};

typedef struct ListNode ListNode;

struct LinkedList {
  ListNode * head;
};

typedef struct LinkedList LinkedList;

void llist_init(LinkedList * list);
void llist_print(LinkedList * list);
void llist_add(LinkedList * list, int value);
int llist_exists(LinkedList * list, int value);
int llist_remove(LinkedList * list, int value);
int llist_get_ith(LinkedList * list, int ith, int *value);
int llist_remove_ith(LinkedList * list, int ith);
int llist_number_elements(LinkedList * list);
int llist_save(LinkedList * list, char * file_name);
int llist_read(LinkedList * list, char * file_name);
void llist_sort(LinkedList * list, int ascending);
void llist_clear(LinkedList *list);

int llist_remove_first(LinkedList * list, int * value);
int llist_remove_last(LinkedList * list, int * value);
void llist_insert_first(LinkedList * list, int value);
void llist_insert_last(LinkedList * list, int value);

*/

#ifndef IRC_SERVER
#define IRC_SERVER

#define PASSWORD_FILE "password.txt"

class IRCServer {
	// Add any variables you need
	FILE * passwordFile;

	typedef struct {
		const char * username;
		const char * password;
	} User;

	int currentUser;
	int maxUsers;
	User * users;

	typedef struct {
		const char * name;
		char messages[100][1000];
		int currentMessage;
		User * usinr;
		int currentUsinr;
		int maxUsinr;
	} Room;

	int currentRoom;
	int maxRooms;
	Room * rooms;

private:
	int open_server_socket(int port);

public:
	void initialize();
	bool checkPassword(int fd, const char * user, const char * password);
	void sortUsers(int fd);
	void sortUsersInRoom(int fd, int roomNum);
	void processRequest( int socket );
	void addUser(int fd, const char * user, const char * password, const char * args);
	void createRoom(int fd, const char * user, const char * password, const char * args);
	void listRooms(int fd, const char * user, const char * password, const char * args);
	void enterRoom(int fd, const char * user, const char * password, const char * args);
	void leaveRoom(int fd, const char * user, const char * password, const char * args);
	void sendMessage(int fd, const char * user, const char * password, const char * args);
	void getMessages(int fd, const char * user, const char * password, const char * args);
	void getUsersInRoom(int fd, const char * user, const char * password, const char * args);
	void getAllUsers(int fd, const char * user, const char * password, const char * args);
	void runServer(int port);
};

#endif
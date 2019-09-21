/*

#ifndef IRC_SERVER
#define IRC_SERVER

#define PASSWORD_FILE "password.txt"

class IRCServer {
  // Add any variables you need

 private:
  int open_server_socket(int port);

 public:

  void initialize();
  void insertUser(const char *name, const char *word);
  void initializeMessage();
  bool checkPassword(int fd, const char * user, const char * password);
  void processRequest( int socket );
  bool userExist(const char *username);
  void addUser(int fd, const char * user, const char * password, const char * args);
  bool roomExist(const char *roomname);
  void createRoom(int fd, const char *user, const char *password, const char *args);
  void listRoom(int fd, const char *user, const char *password, const char *args);
  void enterRoom(int fd, const char * user, const char * password, const char * args);
  void leaveRoom(int fd, const char * user, const char * password, const char * args);
  void sendMessage(int fd, const char * user, const char * password, const char * args);
  void getMessages(int fd, const char * user, const char * password, const char * args);
  void getUsersInRoom(int fd, const char * user, const char * password, const char * args);
  void getAllUsers(int fd, const char * user, const char * password, const char * args);
  void runServer(int port);
};

#endif
*/
#ifndef IRC_SERVER
#define IRC_SERVER

class IRCServer {
	// Add any variables you need
	FILE * filep;

	typedef struct {
		const char * username;
		const char * password;
	} User;

	int curusers;
	int maxusers;
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

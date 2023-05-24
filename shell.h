#define _EACCES
#define _CHD_NOT_EXISTS
#define _ILEGAL_NUMBER

#define _CODE_ENOENT
#define _CODE_EACCES
#define _CODE_CHD_NOT_EXISTS
#define _CODE_ILLEGAL_NUMBER
typedef struct __attribute__((packed__))
{
	int argc;
	char **argv;
	int mode;
	int error_code;
	char *command;
	int n_commands;
	char *value_path;
	int is_current_path;
	int status_code;
	char *buffer;
	char **arguments;
	char *environment;
	int pid;
} general_t;

typedef struct __attribute__((__packed__))
{
	char *message;
	int code;
} error_t;

typedef struct __attribute__((__packed__))
{
	char *command;
	void (*func)(general_t *info, charr **arguments);
} builtin_t;

#endif

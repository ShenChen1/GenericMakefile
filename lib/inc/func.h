#define LOG(fmt, ...) \
	do \
	{ \
		printf(fmt, ## __VA_ARGS__);\
	} \
	while(0)

int func();
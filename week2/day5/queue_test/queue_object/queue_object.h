#ifndef _QUEUE_OBJECT_
#define _QUEUE_OBJECT_

enum queue_datum_type {
	INTEGER,
	POINTER,
	CHAR,
	LONG,
};
typedef enum queue_datum_type queue_datum_type;

union queue_datum_data {
	int i;
	void *v;
	char c;
	long l;
};
typedef union queue_datum_data queue_datum_data;

struct queue_datum {
	queue_datum_type type;
	queue_datum_data d;
};
typedef struct queue_datum queue_datum;

void *queue_create(void);
void queue_destroy(void *);
int queue_put(void *, queue_datum);
int queue_get(void *, queue_datum *);
/*SEARCH METHOD*/
int queue_search (void *, queue_datum_type, queue_datum *);

#endif

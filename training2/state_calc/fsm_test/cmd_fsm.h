#ifndef CMD_FSM_H_
#define CMD_FSM_H_

#include <stdlib.h>
#include "state_machine.h"

int p1 (void *_ctx, int cur_state, int event, int next_state);
int p2 (void *_ctx, int cur_state, int event, int next_state);
int p3(void *_ctx, int cur_state, int event, int next_state);
int p4(void *_ctx, int cur_state, int event, int next_state);
int exec(void *_ctx, int cur_state, int event, int next_state);

enum {
	WAIT_START = 1,
	WAIT_Z = 2,
	WAIT_D = 3,
	WAIT_R = 4,
	EXEC = 5
};

enum {

	EVENT_START = 1,
	EVENT_Z = 2,
	EVENT_D = 3,
	EVENT_R = 4,
	EVENT_INVALID = 5,
	EVENT_EXEC = 6
};

event_table events[] = {
	{ WAIT_START, EVENT_INVALID, WAIT_START, &p1 },
	{ WAIT_START, EVENT_START, WAIT_Z, &p2 },
	{ WAIT_Z, EVENT_INVALID, WAIT_START, &p1 },
	{ WAIT_Z, EVENT_Z, WAIT_D, &p3 },
	{ WAIT_D, EVENT_INVALID, WAIT_START, &p1 },
	{ WAIT_D, EVENT_D, WAIT_R, &exec },
	{ WAIT_R, EVENT_INVALID, WAIT_START, &p1 },
	{ EOET, EOET, EOET, NULL }
};

const int initial_machine_state = WAIT_START;




#endif /* CMD_FSM_H_ */

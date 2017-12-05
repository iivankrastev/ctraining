#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "state_machine.h"
#include "cmd_fsm.h"

struct callback_ctx {
	int byte;
};
typedef struct callback_ctx callback_ctx;

int main(void) {
	state_machine m;
	callback_ctx ctx;
	int event;
	unsigned char flag = 0;

	init_state_machine(&m, initial_machine_state, events, &ctx);

	while ((ctx.byte = fgetc(stdin)) != EOF) {

		if (ctx.byte == '>' && flag == 0){
			//printf("START\n");
			event = EVENT_START;
			flag = 1;
		} else if (ctx.byte == 'z' && flag == 1){
			//printf("Z\n");
			event = EVENT_Z;
			flag = 2;
		} else if (ctx.byte == 'd' && flag == 2){
			//printf("D\n");
			event = EVENT_D;
			flag = 3;
		} else if (ctx.byte == 'r' && flag == 3){
			//printf("R\n");
			event = EVENT_R;
			flag = 0;
		}else{
			//printf("I\n");
			event = EVENT_INVALID;
			flag = 0;
		}
		if (!run_state_machine(&m, event)) break;
	}


	return 0;
}

int p1 (void *_ctx, int cur_state, int event, int next_state){
	printf("STATE 1\n");
	return 1;
}

int p2 (void *_ctx, int cur_state, int event, int next_state){
	printf("STATE 2\n");
	return 1;
}
int p3(void *_ctx, int cur_state, int event, int next_state){
	printf("STATE 3\n");
	return 1;
}
int p4(void *_ctx, int cur_state, int event, int next_state){
	printf("STATE 4\n");
	return 1;
}
int exec(void *_ctx, int cur_state, int event, int next_state){
	printf("zdr ve lut\n");

	return 1;
}


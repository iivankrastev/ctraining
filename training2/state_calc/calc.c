#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "state_machine.h"
#include "queue_object.h"
/*????????????????????????????*/
struct callback_ctx {
	void *stack;
	int symbol;
	int accumulator;
};
typedef struct callback_ctx callback_ctx;

static int digit(void *_ctx, int cur_state, int event, int next_state);
static int separator(void *_ctx, int cur_state, int event, int next_state);
static int operator(void *_ctx, int cur_state, int event, int next_state);

#define _CALC_EVENTS_TABLE_ACTIVATOR_
#include "calc_events_table.h"

static int digit(void *_ctx, int cur_state, int event, int next_state) {
	callback_ctx *ctx = (callback_ctx *)_ctx;
	char buf[2];
	
	buf[0] = (char)(ctx->symbol & 0xff);
	buf[1] = '\0';
	ctx->accumulator = ctx->accumulator * 10 + atoi(buf);
	
	return 1;
}

static int separator(void *_ctx, int cur_state, int event, int next_state) {
	callback_ctx *ctx = (callback_ctx *)_ctx;
	queue_datum d;
	int r = 1;
	
	if (cur_state == STATE_DIGIT) {
		d.type = INTEGER;
		d.d.i = ctx->accumulator;
		if (!stack_push(ctx->stack, d)) {
			fprintf(stderr, "cannot push\n");
			r = 0;
			goto end;
		}
		ctx->accumulator = 0;
	}
	
end:
	return r;
}

static int operator(void *_ctx, int cur_state, int event, int next_state) {
	callback_ctx *ctx = (callback_ctx *)_ctx;
	queue_datum d0, d1;
	int r = 1;
	
	if ((ctx->symbol == '.') || (ctx->symbol == 'p')) {
		if (!stack_pop(ctx->stack, &d0))
			fprintf(stderr, "stack underflow\n");
		else printf("%d\n", d0.d.i);
		goto end;
	}
	
	if (!stack_pop(ctx->stack, &d0)) {
		fprintf(stderr, "stack underflow\n");
		goto end;
	} else if (!stack_pop(ctx->stack, &d1)) {
		fprintf(stderr, "stack underflow\n");
		if (!stack_push(ctx->stack, d0)) {
			fprintf(stderr, "cannot push\n");
			r = 0;
		}
		goto end;
	}
	
	switch (ctx->symbol) {
	case '+':
		d0.d.i += d1.d.i;
		break;
	case '-':
		d1.d.i -= d0.d.i;
		d0.d.i = d1.d.i;
		break;
	case '*':
		d0.d.i *= d1.d.i;
		break;
	case '/':
		d1.d.i /= d0.d.i;
		d0.d.i = d1.d.i;
		break;
	default:
		fprintf(stderr, "unknown operator");
		r = 0;
		goto end;
	}
	
	if (!stack_push(ctx->stack, d0)) {
		fprintf(stderr, "cannot push\n");
		r = 0;
	}
	
end:
	return r;
}

int main(void) {
	state_machine m;
	callback_ctx ctx;
	int event;
	
	init_state_machine(&m, initial_machine_state, events, &ctx);
	ctx.accumulator = 0;
	
	ctx.stack = queue_create();
	if (!ctx.stack) {
		fprintf(stderr, "cannot create stack\n");
		return 1;
	}
	
	while ((ctx.symbol = fgetc(stdin)) != EOF) {
	    /* ????????????????????????????? */
		if (isdigit(ctx.symbol)) event = EVENT_DIGIT;
		else if ((ctx.symbol == (int)'\n') || (ctx.symbol == (int)' ')) event = EVENT_SEPARATOR;
		else event = EVENT_OPERATOR;
		if (!run_state_machine(&m, event)) break;
	}
	
	queue_destroy(ctx.stack);
	
	return 0;
}


#ifndef _CALC_EVENTS_TABLE_ACTIVATOR_
#error Bad #include "calc_events_table.h"
#endif
/*????????????????????????*/
#ifndef _CALC_EVENTS_TABLE_GUARDIAN_
#define _CALC_EVENTS_TABLE_GUARDIAN_

#include "state_machine.h"

enum {
	STATE_DIGIT = 1,
	STATE_SEPARATOR = 2,
	STATE_OPERATOR = 3,
	STATE_MINUS = 4
};

enum {
	EVENT_DIGIT = 1,
	EVENT_SEPARATOR = 2,
	EVENT_OPERATOR = 3,
	EVENT_INVALID = 4   /* ??????????????????*/
};

static event_table events[] = {
	{ STATE_INITIAL, EVENT_DIGIT, STATE_DIGIT, &digit },
	{ STATE_INITIAL, EVENT_SEPARATOR, STATE_SEPARATOR, &separator },
	{ STATE_INITIAL, EVENT_OPERATOR, STATE_OPERATOR, &operator },
	{ STATE_DIGIT, EVENT_DIGIT, STATE_DIGIT, &digit },
	{ STATE_DIGIT, EVENT_SEPARATOR, STATE_SEPARATOR, &separator },
	{ STATE_SEPARATOR, EVENT_DIGIT, STATE_DIGIT, &digit },
	{ STATE_SEPARATOR, EVENT_SEPARATOR, STATE_SEPARATOR, &separator },
	{ STATE_SEPARATOR, EVENT_OPERATOR, STATE_OPERATOR, &operator },
	{ STATE_OPERATOR, EVENT_SEPARATOR, STATE_SEPARATOR, &separator },
	{ STATE_OPERATOR, EVENT_OPERATOR, STATE_OPERATOR, &operator },
	{ EOET, EOET, EOET, NULL }
};
/* ?????????????????? */
static const int initial_machine_state = STATE_SEPARATOR;

#endif


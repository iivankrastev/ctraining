#include "fsm.h"

static const int valid_coins[5] = { 5, 10, 20, 50, 100 };


state curr_state;
event curr_event;

int is_valid_coin(int in)
{
    int i, r = 0;

    for (i = 0; i < 5; i++)
	if (valid_coins[i] == in)
	    r = 1;
    
    return r;
}

void init_fsm()
{
    curr_state = COINS;
    
    return;
}

void run_fsm(int in)
{
    switch (curr_state) {
	case STATE_COINS:
	    if	    (is_valid_coin(in))	curr_event = CHOOSE;
	    else if (in == 'R')		curr_state = 		    	    
	    break;

	case STATE_CHOOSE:
	    break;

	case STATE_ORDER:
	    break;

	default:
    
    }

}


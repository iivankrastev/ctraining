#ifndef _FSM_H_
#define _FSM_H_

enum state
{
    STATE_COINS,
    STATE_CHOOSE,
    STATE_ORDER
};
typedef enum state state;

enum event 
{
    EVENT_VALID_COIN,
    EVENT_INSERT_MORE,
    EVENT_MAKE_ORDER,
    EVENT_NOT_ENOUGH,
    EVENT_DISPENSE,
    EVENT_RETURN_CHANGE,
    EVENT_INVALID
};

typedef enum event event;

int is_valid_coin(int);
void init_fsm(void);
void run_fsm(int);


#endif

typedef enum
{
    M_PA,
    M_PB,
    M_SA,
    M_SB,
    M_RA,
    M_RB,
    M_RR,
    M_RRA,
    M_RRB,
    M_RRR,
} t_movement;

typedef enum {
	STACK_ONE = 1,
	STACK_TWO = 2,
} t_stack_id;

typedef struct
{
	int id;
	int *items;
	int size;
} t_stack;

typedef struct
{
	t_stack *one;
	t_stack *two;
} t_pswap;

typedef struct
{
	int stack_id;
	int upward;
	int downward;
} t_target_cost;

typedef struct
{
	int cost;
	t_movement movement;
} t_step;

typedef struct
{
	int cost;
	t_step steps[10];
} t_option;

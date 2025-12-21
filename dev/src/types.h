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

const char *get_movement(t_movement mov)
{
    const char *movements[10];

    movements[0] = "PA";
    movements[1] = "PB";
    movements[2] = "SA";
    movements[3] = "SB";
    movements[4] = "RA";
    movements[5] = "RB";
    movements[6] = "RR";
    movements[7] = "RRA";
    movements[8] = "RRB";
    movements[9] = "RRR";
    if (mov < 0 || mov > 9)
        return (0);
    return (movements[mov]);
}

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
	int times;
	t_movement mov;
} t_step;

typedef struct
{
	int cost;
	t_step steps[4];
} t_option;

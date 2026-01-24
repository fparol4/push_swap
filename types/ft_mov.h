#ifndef PSWAP_MOVEMENT_H
#define PSWAP_MOVEMENT_H

#define S_PA "PA"
#define S_PB "PB"
#define S_SA "SA"
#define S_SB "SB"
#define S_RA "RA"
#define S_RB "RB"
#define S_RR "RR"
#define S_RRA "RRA"
#define S_RRB "RRB"
#define S_RRR "RRR"

typedef enum e_mov
{
    MOV_NONE = 0,
    MOV_PA,
    MOV_PB,
    MOV_SA,
    MOV_SB,
    MOV_RA,
    MOV_RB,
    MOV_RR,
    MOV_RRA,
    MOV_RRB,
    MOV_RRR
} e_mov;

typedef enum e_path
{
	P_UPWARD = 1,
	P_DOWNWARD = 2,
	P_MIDDLE = 3
} e_path;

typedef struct t_step
{
	e_mov	mov;
	int		times;
} t_step;

typedef struct t_path
{
	int cost;
	int steps;
	t_step *step;
} t_path;

#endif

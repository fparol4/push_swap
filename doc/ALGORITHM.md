24/01/26 - 16:00 - ALGORITHM
--- 

Push swap is an algorithm a little different of a Tower of Hanoi,
where we can take the last piece and put it on the top of the tower.
The idea is to order the first stack with the second stack as auxiliary.

For this we can understand an algorithm that get all pieces from the
first stack and add then on _descending_ order into stack two. That
algorithm also wants to verify the best option for choosing the piece
with the least movements, for optimization. This algorithm can be described:

Organizing & Constraints
1. Stack A and Stack B are empty
2. Stack A is filled with the unsorted numbers
	2.1 If stack A is empty, the program stop
	2.2 If the stack A has only one number, the program stop
	2.3 If the stack A has only two numbers, we sort ascending
	(te lower on top) and the program stop
	2.4 If the stack A has only three numbers, we sort the three
	using a technique, and the program stop
3. The algorithm will run until SA has length >= 4
4. >> Algorithm

-- Algorithm -- 
We need to find on Stack A + Stack B the combination with the
two (the option and the target of the option) with less movements. 

`A option on stack A should aways go UP the next <= option.value
e.g: On A we have the option 4 and on B we have the numbers, 5, 3, 2
the option (4) should be placed on top of the target (3) the next less.
If the option has no next less (e.g 1) then it should be placed on top
of the max of the stack.`

The process is simple, but we need to check what is the best combination
for lowering the moves needed. E.G: 

A	B
3	6
7	2
5	1

OPTION (3), TARGET (2) = RRB, PA (2 MOVES)
OPTION (7), TARGET (2) = RRA, PA (2 MOVES)
OPTION (5), TARGET (2) = RA, RRB, PA (3 MOVES)
So the best option is the first found (OPTION (3), TARGET(2));

-- Algorithm: Calculating -- 
Also there is the possibility of combined rotation: RR or RRA
which is a optimization we should consider. For this we can calculate
by the following rules:

UPWARD, DOWNWAD = The amount of movements for repositioning an item
into the top of the owner stack.
- RR or RRR is defined by the lower common value of a kind of rotation
e.g: OPTION.DOWNWARD = 2, TARGET.DOWNWARD = 3 => RR = 2 cause there is two
common rotations between the two.
- The same analogy is applied for the 'RRR' kind of rotation, the diff
is for rotating reverse we need to UPWARD instead of DOWNWARD

Beside this combination, we have the remaining movement, and it can be discovered:
- IF OPTION_A.UPWARD = 3, OPTION_B.UPWARD = 2
=> RRR (2) + RA (1)
Where RA is the amount of rotations left on the OPTION_A so 'RX_COST' is the cost of 
'RA' OR 'RB' and it is defined as:
RX = OPTION_A.UPWARD > OPTION_B.UPWARD ? 'RA' : 'RB'
RX_MOVES = ABS(OPTION_A - OPTION_B)

The result formula is, for every (option, target) we should calculate the three possibilities: 

1. The cost for moving both upward (RR (DIFF) + RX (REMAINING))
	RR = MIN_OF OPTION_A.UPWARD, OPTION_B.UPWARD
	RX = OPTION_A.UPWARD > OPTION_B.UPWARD ? 'RA' : 'RB'
	RX_M = ABS(OPTION_A.UPWARD - OPTION_B.UPWARD)
	TOTAL_COST = RR + RX_M + 1

2. The cost for moving both downward (RRR (DIFF) + RRX (REMAINING))
	RRR = MIN_OF OPTION_A.DOWNWARD, OPTION_B.DOWNWARD
	RRX = OPTION_A.DOWNWARD > OPTION_B.DOWNWARD ? 'RRA' : 'RRB'
	RRX_M = ABS(OPTION_A.DOWNWARD - OPTION_B.DOWNWARD)
	TOTAL_COST = RRR + RRX_M + 1

3. The cost for moving the (OPTION, TARGET) for the minimum between
UPWARD and DOWNWARD
	OPTION_COST = MIN_OF OPTION_A.UPWARD, OPTION_A.DOWNWARD
	TARGET_COST = MIN_OF OPTION_B.UPWARD, OPTION_B.DOWNWARD
	TOTAL_COST = OPTION_COST + TARGET_COST + 1
This happens on cases where the best option is not in the same direction as 
the target. Being the OPTION best UPWARD and TARGET DOWNWARD or the reverse.

4. Find the best SORT_PATH between the three ones.

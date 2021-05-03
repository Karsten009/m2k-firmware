#pragma once
#include "cmsis_compiler.h"

struct Xy {
	int16_t x, y;
};

// move in xy direction for len cycles
// remember that positive y is downwards
struct Anim {
	uint32_t len;
	struct Xy xy;
};

void anim_set_scale(int scale);

void anim_add(int reps, int len_seq, struct Anim seq[]);

struct Xy anim_read(void);

#define ANIM(l, _x, _y) ((struct Anim){.len = (l), .xy = (struct Xy){.x = (_x), .y = (_y)}})

#define SPEED_MUL 2
#define LEN_XLONG 250
#define LEN_LONG 125
#define LEN_SHORT 50
#define PAUSE ANIM(LEN_XLONG / SPEED_MUL,  0,  0)
#define UP_L   ANIM(LEN_XLONG / SPEED_MUL,  0, -1 * SPEED_MUL)
#define DOWN_L ANIM(LEN_XLONG  / SPEED_MUL,  0,  1 * SPEED_MUL)
#define LEFT_L ANIM(LEN_XLONG / SPEED_MUL, -1 * SPEED_MUL,  0)
#define RIGHT_L ANIM(LEN_XLONG / SPEED_MUL,  1 * SPEED_MUL,  0)
#define UP    ANIM(LEN_LONG / SPEED_MUL,  0, -1 * SPEED_MUL)
#define DOWN  ANIM(LEN_LONG / SPEED_MUL,  0,  1 * SPEED_MUL)
#define LEFT  ANIM(LEN_LONG / SPEED_MUL, -1 * SPEED_MUL,  0)
#define RIGHT ANIM(LEN_LONG / SPEED_MUL,  1 * SPEED_MUL,  0)
#define UP_S    ANIM(LEN_SHORT / SPEED_MUL,  0, -1 * SPEED_MUL)
#define DOWN_S  ANIM(LEN_SHORT / SPEED_MUL,  0,  1 * SPEED_MUL)
#define LEFT_S  ANIM(LEN_SHORT / SPEED_MUL, -1,  0)
#define RIGHT_S ANIM(LEN_SHORT / SPEED_MUL,  1,  0)

#define anim_cw(reps) anim_add((reps), 4, (struct Anim[]){UP, RIGHT, DOWN, LEFT})
#define anim_ccw(reps) anim_add((reps), 4, (struct Anim[]){RIGHT, UP, LEFT, DOWN})
#define anim_one(reps) anim_add((reps), 2, (struct Anim[]){RIGHT, DOWN})
#define anim_eight(reps) anim_add((reps), 8, (struct Anim[]){DOWN, RIGHT, DOWN, LEFT, UP, RIGHT, UP, LEFT})
#define anim_lg_updown(reps) anim_add((reps), 4, (struct Anim[]){UP_L, PAUSE, DOWN_L, PAUSE})
#define anim_lg_downup(reps) anim_add((reps), 4, (struct Anim[]){DOWN_L, PAUSE, UP_L, PAUSE})
#define anim_updown(reps) anim_add((reps), 4, (struct Anim[]){UP, PAUSE, DOWN, PAUSE})
#define anim_downup(reps) anim_add((reps), 4, (struct Anim[]){DOWN, PAUSE, UP, PAUSE})
#define anim_rightleft(reps) anim_add((reps), 4, (struct Anim[]){RIGHT, PAUSE, LEFT, PAUSE})
#define anim_up(reps) anim_add((reps), 2, (struct Anim[]){UP_S, PAUSE})
#define anim_down(reps) anim_add((reps), 2, (struct Anim[]){DOWN_S, PAUSE})
#define anim_left(reps) anim_add((reps), 2, (struct Anim[]){LEFT_S, PAUSE})
#define anim_right(reps) anim_add((reps), 2, (struct Anim[]){RIGHT_S, PAUSE})

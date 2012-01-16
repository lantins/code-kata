#if !defined(TIC_TAC_TOE_ILLEGAL_STATE_TEST_SUITE_H_)
#define TIC_TAC_TOE_ILLEGAL_STATE_TEST_SUITE_H_

#include <stdio.h>
#include <string.h>

#include "seatest.h"
#include "../include/tic_tac_toe.h"

/* test suite */
void tic_tac_toe_illegal_state_test_suite(void);

/* unit tests */
void test_can_detect_an_illegal_state_top_left(void);
void test_can_detect_an_illegal_state_top_right(void);
void test_can_detect_an_illegal_state_after_several_moves(void);

#endif

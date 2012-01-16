#if !defined(TIC_TAC_TOE_TEST_H_)
#define TIC_TAC_TOE_TEST_H_

#include <stdio.h>
#include <string.h>

#include "seatest.h"
#include "../include/tic_tac_toe.h"

/* test suite */
void tic_tac_toe_test_suite(void);

/* unit tests */
void test_can_run_unit_tests(void);
void test_calculate_game_state_from_player_moves(void);

#endif

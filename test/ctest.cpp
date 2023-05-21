#include <../thirdparty/ctest.h>
#include <../src/func/game.h>
#include <../src/func/term.h>
#include <string>

using namespace std;

CTEST (game_shell_constructor_test, initialize_game_1)
{
    Shell game;
    ASSERT_FALSE(game._quit);
    ASSERT_EQUAL(0, game._p1._score);
    ASSERT_TRUE(game._p1.guess);
}

CTEST (game_shell_constructor_test, initialize_game_2)
{
    Shell game;
    ASSERT_FALSE(game._quit);
    ASSERT_EQUAL(0, game._p2._score);
    ASSERT_FALSE(game._p2.guess);
}

CTEST (game_shell_option_test, option_selected_1)
{
    Shell game;
    game.option(1);
    ASSERT_FALSE(game._multiplayer);
}

CTEST (game_shell_option_test, option_selected_2)
{
    Shell game;
    game.option(2);
    ASSERT_TRUE(game._multiplayer);
    ASSERT_TRUE(game._p2._act);
}

CTEST (game_shell_option_test, option_selected_3)
{
    Shell game;
    game.option(3);
    ASSERT_FALSE(game._p2._act);
}

CTEST (game_shell_player_switch_test, player_guessing_1) 
{
    Shell game;
    game.Switch();
    ASSERT_FALSE(game._p1.guess);
    ASSERT_TRUE(game._p2.guess);
}

CTEST (game_shell_player_switch_test, player_guessing_2) 
{
    Shell game;
    game.Switch();
    game.Switch();
    ASSERT_TRUE(game._p1.guess);
    ASSERT_FALSE(game._p2.guess);
}

CTEST (game_shell_player_switch_test, scores_updated)
{
    Shell game;
    game._p1._score = 5;
    game._p2._score = 10;
    game.guess._score = 3;
    game.word._score = 4;
    game.Switch();
    ASSERT_EQUAL(14, game._p2._score);
    ASSERT_EQUAL(8, game._p1._score);
    ASSERT_EQUAL(0, game.guess._score);
    ASSERT_EQUAL(0, game.word._score);
}

CTEST (game_data_genWord_test, generate_word)
{
    Data game;
    game.gen();
    ASSERT_EQUAL(game.word.size(), game.Sol.size());
}

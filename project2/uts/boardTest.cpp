#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "board.hpp"
#include "field.hpp"

//for my random tests
#include <stdlib.h>
#include <time.h>

class BoardTest : public ::testing::Test
{
    protected:
    BoardTest() {};
    ~BoardTest() override {};

    void SetUp() override{};
    void TearDown() override {};
};
class MyBoardTest : public BoardTest
{
};

TEST_F(BoardTest, givenBoardHasSize0By0ItReturns0By0)
{
    Board board{Size{0,0}};
    Size expectedSize{0,0};
    
    EXPECT_THAT(board.getSize(), testing::AllOf(
        testing::Field("width", &Size::width, expectedSize.width),
        testing::Field("height", &Size::height, expectedSize.height)
    ));
}

TEST_F(BoardTest, givenBoardHasSize4By3ItReturns4By3)
{
    Board board{Size{4,3}};
    Size expectedSize{4,3};

    EXPECT_THAT(board.getSize(), testing::AllOf(
        testing::Field("width", &Size::width, expectedSize.width),
        testing::Field("height", &Size::height, expectedSize.height)
    ));
}

// repeted a test for my practice
TEST_F(MyBoardTest, givenBoardHasSize100By0ItReturns100By0)
{
    Board board{Size{100,0}};
    Size expectedSize{100,0};

    EXPECT_THAT(board.getSize(), testing::AllOf(
        testing::Field("width", &Size::width, expectedSize.width),
        testing::Field("height", &Size::height, expectedSize.height)
    ));
}

TEST_F(BoardTest, givenFresh3By3BoardWhenStateOfUpperLeftfieldIsCheckedItReturnsFree)
{
    Board board{Size{3,3}};

    EXPECT_EQ(board.getFieldState({0,0}), Field::Empty);
}

// repeted a test for my practice
TEST_F(MyBoardTest, givenFresh10By10BoardWhenStateOfUpperLeftfiledIsCheckedItReturnFree)
{
    Board board{Size{10,10}};
    EXPECT_EQ(board.getFieldState({10,10}), Field::Empty);
}

TEST_F(BoardTest, givenStateOfUpperLeftfieldIsSetToXCheckedItReturnsX)
{
    Board board{Size{3,3}};
    board.setFieldState({0,0},Field::X);

    EXPECT_EQ(board.getFieldState({0,0}), Field::X);
}

TEST_F(MyBoardTest, givenFresh10By10BoardAndFillItByRandomMove)
{
    srand (time(NULL));
    auto x = rand() % 10;    
    auto y = rand() % 10;    

    Board board{Size{10,10}};
    board.setFieldState({x,y}, Field::X);

    EXPECT_EQ(board.getFieldState({x,y}), Field::X);
    
}

TEST_F(MyBoardTest, givenVariousTypeOfFields)
{
    Board board{Size{3,3}};
    board.setFieldState({0,0}, Field::X);
    board.setFieldState({1,1}, Field::O);

    EXPECT_EQ(board.getFieldState({0,0}), Field::X);
    EXPECT_EQ(board.getFieldState({1,1}), Field::O);
    EXPECT_EQ(board.getFieldState({0,1}), Field::Empty);
}
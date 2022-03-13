//
// Created by lucas on 05/03/2022.
//
/**
 * This is the tests file which contains all of our tests for the mat exercise.
 * Author: Amit Melamed.
 */

#include "doctest.h"
#include "mat.hpp"
using namespace ariel;

#include <string>
#include <algorithm>
using namespace std;

/**
 * Returns the input string without the whitespace characters: space, newline and tab.
 * Requires std=c++2a.
 */
string nospaces(string input) {
    std::erase(input, ' ');
    std::erase(input, '\t');
    std::erase(input, '\n');
    std::erase(input, '\r');
    return input;
}

TEST_CASE("Good input") {


    CHECK(nospaces(mat(9, 7, '@', '-')) == nospaces("@@@@@@@@@\n@-------@\n@-@@@@@-@\n@-@---@-@\n@-@@@@@-@\n@-------@\n@@@@@@@@@"));
    CHECK(nospaces(mat(5, 5, '@', '>')) == nospaces("@@@@@\n"
                                                    "@>>>@\n"
                                                    "@>@>@\n"
                                                    "@>>>@\n"
                                                    "@@@@@"));
    CHECK(nospaces(mat(5, 5, '@', '&')) == nospaces("@@@@@\n"
                                                            "@&&&@\n"
                                                            "@&@&@\n"
                                                            "@&&&@\n"
                                                            "@@@@@"));
    CHECK(nospaces(mat(1, 1, '@', '&')) == nospaces("@"));
    CHECK(nospaces(mat(1, 1, '*', '&')) == nospaces("*"));
    CHECK(nospaces(mat(5, 1, '*', '&')) == nospaces("*****"));
    CHECK(nospaces(mat(1, 5, '*', '&')) == nospaces("*\n*\n*\n*\n*"));
    CHECK(nospaces(mat(9, 7, '@','-')) == nospaces("@@@@@@@@@\n"
                                                   "@-------@\n"
                                                   "@-@@@@@-@\n"
                                                   "@-@---@-@\n"
                                                   "@-@@@@@-@\n"
                                                   "@-------@\n"
                                                   "@@@@@@@@@"));
    CHECK(nospaces(mat(13, 5, '@', '-')) == nospaces("@@@@@@@@@@@@@\n"
                                                     "@-----------@\n"
                                                     "@-@@@@@@@@@-@\n"
                                                     "@-----------@\n"
                                                     "@@@@@@@@@@@@@"));
    CHECK(nospaces(mat(3, 5, '$', '+')) == nospaces("$$$\n"
                                                    "$+$\n"
                                                    "$+$\n"
                                                    "$+$\n"
                                                    "$$$"));
    CHECK(nospaces(ariel::mat(21,15,'#','-')) == nospaces("#####################\n"
                                                          "#-------------------#\n"
                                                          "#-#################-#\n"
                                                          "#-#---------------#-#\n"
                                                          "#-#-#############-#-#\n"
                                                          "#-#-#-----------#-#-#\n"
                                                          "#-#-#-#########-#-#-#\n"
                                                          "#-#-#-#-------#-#-#-#\n"
                                                          "#-#-#-#########-#-#-#\n"
                                                                  "#-#-#-----------#-#-#\n"
                                                                  "#-#-#############-#-#\n"
                                                                  "#-#---------------#-#\n"
                                                                  "#-#################-#\n"
                                                                  "#-------------------#\n"
                                                                  "#####################\n"));

}

TEST_CASE("Bad input") {
    //a is even
    CHECK_THROWS(mat(10, 5, '$', '%'));
    //b is even
    CHECK_THROWS(mat(7, 20, '$', '%'));
    //a and b is even
    CHECK_THROWS(mat(30, 20, '$', '%'));
    //a is negative
    CHECK_THROWS(mat(-1,7,'$','-'));
    //b is negative
    CHECK_THROWS(mat(15,-7,'$','-'));
    //a and b is negative
    CHECK_THROWS(mat(-15,-7,'$','-'));
    //c==d
    CHECK_THROWS(mat(9,7,'$','$'));
    //c is space
    CHECK_THROWS(mat(9,7,' ','$'));
    //c is \n
    CHECK_THROWS(mat(9,7,'\n','$'));
    //c is \r
    CHECK_THROWS(mat(9,7,'\r','$'));
    //c is \t
    CHECK_THROWS(mat(9,7,'\t','$'));
}


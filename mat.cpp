//
// Created by Amit on 05/03/2022.
//
/**
 * This mat file is the main file of the program.
 * We will have here a main mat function that will get width length and 2 symbols and will create our custom mat.
 * * Author: Amit Melamed
 */
#include <iostream>
#include <string>
#include "mat.hpp"
#include <vector>

using namespace std;
const int minCharValue=33;
const int maxCharValue=126;
namespace ariel {




    string mat(int a, int b, char c, char d) {

        /**
         * first we will check the input is good.
         * matrix size should be odd,and positive, symbols must be chars with ascii values between 33 and 126 (include).
         */

        if (a % 2 == 0 || b % 2 == 0) {
            throw std::invalid_argument("Mat size is always odd");
        }
        if (a <= 0 || b <= 0) {
            throw std::invalid_argument("received negative or zero matrix values");
        }

        if(c<minCharValue || d<minCharValue || c>maxCharValue || d>maxCharValue){
            throw std::invalid_argument("bad letters");

        }

        /**
         * making vector of vectors that will represent 2D matrix
         */
        vector<vector<char >> vec( b , vector<char> (a, c));


        /**
         * if we dont have 1 row or 1 column matrix we 'paint' our cells with D char from input.
         * this is the algorithm for painting the matrix:
         * we go and paint each second circle in the matrix with 'D' chars from the input.
         */
        if (a != 1) {
            for (int i = 1; i < b - 1; i = i + 2) {
                for (int j = i; j < b - i; ++j) {
                    if (i < a) {
                        vec[j][i] = d;
                    }
                    if (a - i - 1 > 0) {
                        vec[j][a - i - 1] = d;
                    }
                }
            }
        }

        if (b != 1) {
            for (int i = 1; i < a - 1; i = i + 2) {
                for (int j = i; j < a - i; ++j) {
                    if (i < b) {
                        vec[i][j] = d;
                    }
                    if (b - i - 1 > 0) {
                        vec[b - i - 1][j] = d;
                    }
                }
            }
        }

        /**
         * after we calculate the matrix, we convert it into string,
         * rows will be seperated with '\n'.
         */
        std::string finalStr;
        for (int i = 0; i < b; ++i) {
            for (int j = 0; j < a; ++j) {
                finalStr.push_back(vec[i][j]);
            }
            finalStr.push_back('\n');
        }

        /**
         * return the final string representing the final mat.
         */
        return finalStr;
    }

}






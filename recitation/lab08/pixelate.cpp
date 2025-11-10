/*
Author: Nicolas Araya
Course: CSCI-136
Instructor: Sarah Khaldi
Assignment: Lab 8F

pixelate
*/
// five extra comments
//1
// 2
//3
//4
//5
#include <iostream>
#include <cassert>
#include <cstdlib>
#include <fstream>
using namespace std;

const int MAX_H = 512;
const int MAX_W = 512;

void readImage(int image[MAX_H][MAX_W], int &height, int &width) {
    char c;
    ifstream instr;
    instr.open("inImage.pgm");

    instr >> c; assert(c == 'P');
    instr >> c; assert(c == '2');

    while ((instr>>ws).peek() == '#') instr.ignore(4096, '\n');

    instr >> width >> height;
    assert(width <= MAX_W && height <= MAX_H);
    int max; instr >> max; assert(max == 255);

    for (int row = 0; row < height; row++)
        for (int col = 0; col < width; col++)
            instr >> image[row][col];
    instr.close();
}

void writeImage(int image[MAX_H][MAX_W], int height, int width) {
    ofstream ostr("outImage.pgm");
    if (ostr.fail()) { cout << "Unable to write file\n"; exit(1); }

    ostr << "P2\n" << width << " " << height << "\n255\n";

    for (int row = 0; row < height; row++) {
        for (int col = 0; col < width; col++) {
            ostr << image[row][col] << " ";
        }
        ostr << "\n";
    }
}

int main() {
    int img[MAX_H][MAX_W];
    int out[MAX_H][MAX_W];
    int h, w;

    readImage(img, h, w);

    for(int row = 0; row < h; row++) {
        for(int col = 0; col < w; col++) {
            int sum = 0;
            int count = 0;

            for(int dr = 0; dr <= 1; dr++) {
                for(int dc = 0; dc <= 1; dc++) {
                    int r = (row % 2 == 0 ? row : row-1) + dr;
                    int c = (col % 2 == 0 ? col : col-1) + dc;

                    if (r >= 0 && r < h && c >= 0 && c < w) {
                        sum += img[r][c];
                        count++;
                    }
                }
            }

            out[row][col] = sum / count;
        }
    }

    writeImage(out, h, w);
}

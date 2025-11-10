/*
Author: Nicolas Araya
Course: CSCI-136
Instructor: Sarah Khaldi
Assignment: Lab 8E

zoom
*/
// five extra comments
//1
// 2
//3
//4
//5'
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

    while ((instr>>ws).peek() == '#') {
        instr.ignore(4096, '\n');
    }

    instr >> width >> height;
    assert(width <= MAX_W && height <= MAX_H);

    int max; instr >> max; assert(max == 255);

    for (int row = 0; row < height; row++)
        for (int col = 0; col < width; col++)
            instr >> image[row][col];

    instr.close();
}

void writeImage(int image[MAX_H][MAX_W], int height, int width) {
    ofstream ostr;
    ostr.open("outImage.pgm");
    if (ostr.fail()) {
        cout << "Unable to write file\n";
        exit(1);
    }

    ostr << "P2\n";
    ostr << width << ' ' << height << '\n';
    ostr << 255 << '\n';

    for (int row = 0; row < height; row++) {
        for (int col = 0; col < width; col++) {
            assert(image[row][col] < 256 && image[row][col] >= 0);
            ostr << image[row][col] << ' ';
        }
        ostr << '\n';
    }
    ostr.close();
}

int main() {
    int img[MAX_H][MAX_W];
    int out[MAX_H][MAX_W];
    int h, w;

    readImage(img, h, w);

    int original_h = h;
    int original_w = w;

    int scale = 2;
    h = original_h * scale;
    w = original_w * scale;

    for(int row = 0; row < h; row += 2) {
        for(int col = 0; col < w; col += 2) {
            int temp = img[row / 2][col / 2];
            out[row][col] = temp;
            out[row + 1][col] = temp;
            out[row][col + 1] = temp;
            out[row + 1][col + 1] = temp;
        }
    }

    writeImage(out, h, w);
}

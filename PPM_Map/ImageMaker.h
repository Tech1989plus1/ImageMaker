//
//  ImageMaker.h
//  Assignment1_ImageMaker
//
//  Created by Derrick Marshall on 4/1/17.
//  Copyright © 2017 Derrick Marshall. All rights reserved.
//

#ifndef ImageMaker_h
#define ImageMaker_h

#include <string>
#include <fstream>
using namespace std;

const int MAX_WIDTH = 640;
const int MAX_HEIGHT = 480;
const int MAX_COLOR = 255;
const string P3 = "P3";

enum COLOR {RED, GREEN, BLUE};

class ImageMaker{
	
private:
	int width;
	int height;
	int red;
	int green;
	int blue;
	short image[MAX_WIDTH][MAX_HEIGHT][3];
	
public:
	ImageMaker();
	ImageMaker(string filename);
	
	void LoadImage(ifstream &inputFile);
	void SaveImage(string filename);
	void SaveLine(string filename, int x1, int y1, int x2, int y2, float slope);
	
	int GetWidth();
	int GetHeight();
	void SetWidth(int widthVal);
	void SetHeight(int heightVal);
	
	int GetRed();
	int GetGreen();
	int GetBlue();
	void SetRed(int newR);
	void SetGreen(int newG);
	void SetBlue(int newB);
	
	void DrawPixel(int x, int y);
	void DrawRectangle(int x1, int y1, int x2, int y2);
	void DrawLine(int x1, int y1, int x2, int y2);
};

#endif /* ImageMaker_h */

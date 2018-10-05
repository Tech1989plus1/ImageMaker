//
//  main.cpp
//  Assignment1_ImageMaker
//
//  Created by Derrick Marshall on 4/1/17.
//  Copyright © 2017 Derrick Marshall. All rights reserved.
//

#include <iostream>
#include "ImageMaker.h"

using namespace std;

int main() {
	string fileName;
	int x1, y1, x2, y2;
	
	cout << "File: ";
	cin >> fileName;
	
	try {
		ImageMaker imMaker(fileName);
	
		cout << "Height of loaded PPM " << imMaker.GetHeight() << endl;
		cout << "Width of loaded PPM " << imMaker.GetWidth() << endl << endl;
		
		cout << "Draw Pixel\n";
		cout << "X: ";
		cin >> x1;
		cout << "Y: ";
		cin >> y1;
		
		imMaker.DrawPixel(x1, y1);
		cout << endl;
		
		cout << "Draw Rectangle\n";
		cout << "X1: ";
		cin >> x1;
		cout << "Y1: ";
		cin >> y1;
		cout << "X2: ";
		cin >> x2;
		cout << "Y2: ";
		cin >> y2;
		
		imMaker.DrawRectangle(x1, y1, x2, y2);
		cout << endl;
		
		cout << "Draw Line\n";
		cout << "X1: ";
		cin >> x1;
		cout << "Y1: ";
		cin >> y1;
		cout << "X2: ";
		cin >> x2;
		cout << "Y2: ";
		cin >> y2;
		
		imMaker.DrawLine(x1, y1, x2, y2);
		cout << endl;
		
		cout << "Save image FileName: ";
		cin >> fileName;
		
		imMaker.SaveImage(fileName);
		
	} catch (string message) {
		cerr <<  message;
		return 1;
	}
	
	
	ImageMaker imagePPM;
	
	int wide, tall;
	
	cout << "Width: ";
	cin >> wide;
	cout << "Height: ";
	cin >> tall;
	
	try {
		imagePPM.SetWidth(wide);
		imagePPM.SetHeight(tall);
		
		cout << "Height of new PPM " << imagePPM.GetHeight() << endl;
		cout << "Width of new PPM " << imagePPM.GetWidth() << endl << endl;
		
		cout << "Set Blue (0 < x < 255): ";
		cin >> x1;
		imagePPM.SetBlue(x1);
		
		cout << "Set Red (0 < x < 255): ";
		cin >> x1;
		imagePPM.SetRed(x1);
		
		cout << "Set Green (0 < x < 255): ";
		cin >> x1;
		imagePPM.SetGreen(x1);
		
		cout << "Green: " << imagePPM.GetGreen() << endl;
		cout << "Red: " << imagePPM.GetRed() << endl;
		cout << "Blue: " << imagePPM.GetBlue() << endl;
		
	} catch (string message) {
		cerr << message;
		return 1;
	}

	
	
    return 0;
}

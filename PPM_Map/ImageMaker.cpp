//
//  ImageMaker.cpp
//  Assignment1_ImageMaker
//
//  Created by Derrick Marshall on 4/1/17.
//  Copyright © 2017 Derrick Marshall. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <fstream>
#include "ImageMaker.h"

using namespace std;


ImageMaker::ImageMaker(){
	width = height = red = green = blue = 0;
	
	for(int index = 0; index < MAX_HEIGHT; index++ ){
		for(int jndex = 0; jndex < MAX_WIDTH; jndex++){
			image[index][jndex][RED] = 0;
			image[index][jndex][GREEN] = 0;
			image[index][jndex][BLUE] = 0;
		}
	}
	
	
}

ImageMaker :: ImageMaker(string filename){
	
	string PixMap;
	string message;
	int heightVal, widthVal, colorVAl;
	ifstream inputFile;
	
	inputFile.open(filename);
	
	if (inputFile.fail()) {
		message = "Error: File fail open.\n";
		throw message;
	}
	
	inputFile >> PixMap;
	inputFile >> widthVal;
	inputFile >> heightVal;
	inputFile >> colorVAl;
	
	if (colorVAl < 0 || colorVAl > MAX_COLOR) {
		message = "Error: PPM Color.\n";
		throw message;
	}
	
	SetHeight(heightVal);
	SetWidth(widthVal);
	
	LoadImage(inputFile);
	
	
	inputFile.close();
}

void ImageMaker:: LoadImage(ifstream &inputFile){
	int value;
	
	for (int index = 0; index < height; index++) {
		for (int jndex = 0; jndex < width; jndex++) {
			for (int RBG_index = 0; RBG_index < 3; RBG_index++) {
				inputFile >> value;
				image[index][jndex][RBG_index] = value;
			}
		}
	}
	
}

void ImageMaker:: SaveImage(string filename){
	ofstream myFile;
	
	myFile.open(filename);
	myFile << P3 << endl;
	myFile << GetWidth() << " " << GetHeight() << endl;
	myFile << MAX_COLOR << endl;
	
	int value;
	
	for (int index = 0; index < height; index++) {
		for (int jndex = 0; jndex < width; jndex++) {
			for (int RBG_index = 0; RBG_index < 3; RBG_index++) {
				value = image[index][jndex][RBG_index];
				myFile << value << " ";
			}
			myFile << "  ";
		}
		myFile << endl;
	}
	
	myFile.close();
}

void ImageMaker:: SetBlue(int newB){
	string message;
	
	if (newB < 0 || newB > MAX_COLOR) {
		message = "Error: Blue range (0 < x < 255).\n";
		throw message;
	}
	blue = newB;
}

void ImageMaker:: SetGreen(int newG){
	string message;
	
	if (newG < 0 || newG > MAX_COLOR) {
		message = "Error: Green range (0 < x < 255).\n";
		throw message;
	}
	green = newG;
}

void ImageMaker:: SetRed(int newR){
	string message;
	
	if (newR < 0 || newR > MAX_COLOR) {
		message = "Error: Red range (0 < x < 255).\n";
		throw message;
	}
	red = newR;
}

int ImageMaker:: GetBlue(){
	return blue;
}

int ImageMaker:: GetGreen(){
	return green;
}

int ImageMaker:: GetRed(){
	return red;
}

void ImageMaker:: SetWidth(int widthVal){
	string message;
	
	if (widthVal < 0 || widthVal > MAX_WIDTH) {
		message = "Error: PPM Width.\n";
		throw message;
	}
	width = widthVal;
}

void ImageMaker::SetHeight(int heightVal){
	string message;
	
	if (heightVal < 0 || heightVal > MAX_HEIGHT) {
		message = "Error: PPM Height.\n";
		throw message;
	}
	height = heightVal;
}

int ImageMaker:: GetWidth(){
	return width;
}

int ImageMaker:: GetHeight(){
	return height;
}

void ImageMaker:: DrawPixel(int newWidth, int newHeight){
	string message, filename;
	
	if (newWidth < 1 || newWidth >= (width)) {
		message = "Error: Width.\n";
		throw message;
	}
	if (newHeight < 1 || newHeight >= (height)) {
		message = "Error: Height.\n";
		throw message;
	}
	
	ofstream myFile;
	filename = "DrawPixel.txt";
	myFile.open(filename);
	
	if (myFile.fail()) {
		message = "Error: File.\n";
		throw string (message);
	}
	
	myFile << P3 << endl;
	myFile << "1 1" << endl;
	myFile << MAX_COLOR << endl;
	
	newWidth = newWidth - 1;
	newHeight = newHeight - 1;
	
	red = image[newWidth][newHeight][RED];
	blue = image[newWidth][newHeight][BLUE];
	green = image[newWidth][newHeight][GREEN];
	
	myFile << red << " " << blue << " " << green << endl;
	myFile.close();
}

void ImageMaker:: DrawRectangle(int w1, int h1, int w2, int h2){
	string message, filename;
	
	
	if (w1 < 0 || w1 > (width) || w2 < 0 || w2 > (width)) {
		message = "Error: Width.\n";
		throw message;
	}
	if (h1 < 0 || h1 > (height) || h2 < 0 || h2 > (height)) {
		message = "Error: Height.\n";
		throw message;
	}
	
	ofstream myFile;
	filename = "DrawRectangle.txt";
	myFile.open(filename);
	
	if (myFile.fail()) {
		message = "Error: File.\n";
		throw string (message);
	}
	
	myFile << P3 << endl;
	myFile << (w2 - w1) << " " << (h2 - h1) << endl;
	myFile << MAX_COLOR << endl;
	
	for (int index = h1; index < h2; index++) {
		for (int jndex = w1; jndex < w2; jndex++) {
			red = image[index][jndex][RED];
			blue = image[index][jndex][BLUE];
			green = image[index][jndex][GREEN];
			myFile << red << " " << green << " " << blue;
			myFile << "  ";
		}
		myFile << endl;
	}
	myFile.close();
}

void ImageMaker:: DrawLine(int x1, int y1, int x2, int y2){
	string message;
	float slope = 0.0;
	
	if (x1 < 0 || x1 > width || x2 < 0 || x2 > width) {
		message = "Error: Width.\n";
		throw message;
	}
	if (y1 < 0 || y1 > height || y2 < 0 || y2 > height) {
		message = "Error: Height.\n";
		throw message;
	}
	
	if(x1 == x2 || y1 == y2){
		SaveLine("DrawLine.txt", x1, y1, x2, y2, 0.0);
	}else{
		slope = (((y2 - y1)*(1.0))/((x2 - x1)*(1.0)));
		SaveLine("DrawLine.txt", x1, y1, x2, y2, slope);
	}
		
	

	
}

void ImageMaker:: SaveLine(string filename, int x1, int y1, int x2, int y2, float slope){
	string message;
	float slopeEquation = ((float)(y2)) - (slope * x2);

	ofstream myFile;
	myFile.open(filename);
	
	if (myFile.fail()) {
		message = "Error: File.\n";
		throw string (message);
	}
	
	myFile << P3 << endl;
	myFile << GetWidth()<< " " << GetHeight() << endl;
	myFile << MAX_COLOR << endl;
	
	for (int index = 0; index < GetHeight(); index++) {
		for (int jndex = 0; jndex < GetWidth(); jndex++){
			
			if(jndex == x1 && jndex == x2){
				red = image[index][jndex][RED];
				blue = image[index][jndex][BLUE];
				green = image[index][jndex][GREEN];
				myFile << red << " " << green << " " << blue;
			} else if(index == y1 && index == y2){
				red = image[index][jndex][RED];
				blue = image[index][jndex][BLUE];
				green = image[index][jndex][GREEN];
				myFile << red << " " << green << " " << blue;
			}else if(slopeEquation == ((float)(index) - (slope * jndex))){
				red = image[index][jndex][RED];
				blue = image[index][jndex][BLUE];
				green = image[index][jndex][GREEN];
				myFile << red << " " << green << " " << blue;
			}else
				myFile << "0 0 0";
			
			myFile << "	";
			
			}
		myFile << endl;
		
	}
	myFile.close();
}

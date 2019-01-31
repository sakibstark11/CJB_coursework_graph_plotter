#pragma once
#include <windows.h>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include<math.h>
#include <cmath>
#include <numeric>
#include<conio.h>
#include<stdio.h>
#include <ostream>
#include "dft_class.h"
#define PI 3.14159265

using namespace std;

class read_and_print
{


public:

	

	vector <double> yStore_cos_bin;
	vector <double> yStore_sin_bin; // for y

	
	void print_system( int element, vector<double> double_element, ostream& print_and_save,int width,int point);
	vector <double> yStore_product_cos_bin;
	vector <double> yStore_product_sin_bin;
	void digit_checker(int pass, ostream& local_stream);
	void what_to_print(ostream& print_or_write, int width_value, int point_scale);
	void passing_bin(int variable_bin);
	
	double readInFromFile(string whichFile);

	read_and_print();
	~read_and_print();
private:
	

	vector<double> yStore; // for y
	vector<int> xStore; // for x

	vector<double> yStore_sin; // for y
	vector<double> yStore_cos; // for y


	vector <int> xStore_sin_cos; // for x
	vector <int> xStore_cos; // for x

};


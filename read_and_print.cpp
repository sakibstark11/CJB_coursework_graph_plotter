#include "read_and_print.h"

double read_and_print::readInFromFile(string whichFile)
{
	int x;
	double y;
	ifstream inputFileStream;
	cout << whichFile << endl;
	inputFileStream.open(whichFile);
	if (inputFileStream.good())
	{
		while (!inputFileStream.fail()) // check
		{
			inputFileStream >> x;//the integer
			xStore.push_back(x); // move to vector
			if (!inputFileStream.fail()) //check
			{
				inputFileStream >> y; //the double	
				yStore.push_back(y); // move to vector
			}
		}

	}
	else
	{
		cout << "Error opening input file";
	}
	inputFileStream.close();

	return 0.0;
}

void read_and_print::passing_bin(int variable_bin)
{
	for (int i = 0; i <= 360; i++)
	{
		double sin_y_bin = sin((variable_bin*i*PI) / 180);
		double cos_y_bin = cos((variable_bin*i*PI) / 180);
		yStore_sin_bin.push_back(sin_y_bin);///// has sin value
		yStore_cos_bin.push_back(cos_y_bin);///// has cos value
		xStore_sin_cos.push_back(i);
	}
	for (int i = 0; i <= 360; i++)
	{
		read_and_print calculate_bin; //look here sakib
		double product_y_sin_bin = yStore[i] * yStore_sin_bin[i];
		yStore_product_sin_bin.push_back(product_y_sin_bin);///// has sin product 
		double product_y_cos_bin = yStore[i] * yStore_cos_bin[i];
		yStore_product_cos_bin.push_back(product_y_cos_bin); //// has cos product
	}
}

void read_and_print::print_system( int element,vector<double> double_element, ostream& print_and_save, int width, int point)
{
	
		int converted_value = (double_element[element] * 10)/ point;  // was 10
		int total_width_per_side = width;  // was 11
		int value_to_print_pos = converted_value;
		int value_to_print_neg = total_width_per_side - abs(converted_value);
		int zero_for_neg = total_width_per_side - value_to_print_neg;
		int end_line_pos = total_width_per_side - value_to_print_pos;
		int end_line_neg = total_width_per_side - value_to_print_neg;


		
		if (converted_value > 0)
		{
			print_and_save   << "|" << setw(total_width_per_side) << ":" << setw(value_to_print_pos) << "*" << setw(end_line_pos) << "|" ;
		}
		else if (converted_value < 0)
		{
			print_and_save  << "|" << setw(value_to_print_neg) << "*" << setw(zero_for_neg) << ":" << setw(total_width_per_side) << "|" ;
		}
		else if (converted_value == 0)
		{
			print_and_save   << "|" << setw(total_width_per_side) << "*" << setw(total_width_per_side) << "|" ;
		}
}







void read_and_print::digit_checker(int pass, ostream& local_stream)
{
	


	if (pass >= 10 &&pass <= 99)
	{
		local_stream<< setw(3)<<pass;
	}
	if (pass < 10)
	{
		local_stream<< setw(3)<<pass;
	}
	if (pass > 99)
	{
		local_stream<< setw(0)<<pass;
	}

}

void read_and_print::what_to_print(ostream& print_or_write, int width_value, int point_scale)
{
	print_or_write << "degree+----input wave----+-------sine wave------+-----sine product-----+-------cos wave-------+------cos product-----+" << endl;

	for (int circle = 0; circle <= 360; circle += 15)
	{
		digit_checker(circle,print_or_write);
		print_system(circle, yStore, print_or_write,  width_value, point_scale);
		print_system(circle, yStore_sin_bin, print_or_write, width_value,  point_scale);
		print_system(circle, yStore_product_sin_bin, print_or_write, width_value,  point_scale);

		print_system(circle, yStore_cos_bin, print_or_write, width_value,  point_scale);
		print_system(circle, yStore_product_cos_bin, print_or_write, width_value, point_scale);



		print_or_write << endl;




	}
	print_or_write << "degree+----input wave----+-------sine wave------+-----sine product-----+-------cos wave-------+------cos product-----+" << endl;
}







read_and_print::read_and_print()

{}
read_and_print::~read_and_print()
{}
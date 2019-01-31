#include <windows.h>
#include <iostream>
#include <string>
#include "read_and_print.h"

using namespace std;
int main()
{
	cout << "----------------- SID 7650714--------------------- " << endl;

	string user_run;
	cout << "To run the software, press y " << endl;
	cin >> user_run;
	while (user_run == "y" || user_run== "Y")
	{
		cout << "filename please ";
		string file;
		cin >> file;
		string file_to_read = file + ".txt";
		ofstream to_write;
		to_write.open("output.txt");
		int user_bin = 0;
		cout << "enter bin number ";
		cin >> user_bin;

		int user_input_width;
		int user_input_point;
		int value_of_width=11;
		int value_of_point=1;


		cout << "type in width for each sides, recommended is 11, must enter a value ";
		
		cin >> user_input_width;

		while (user_input_width <5)
		{
			cout << "stop messing around, recommended is 11, must enter a value ";
			cin >> user_input_width;
		}
		
		value_of_width = user_input_width;
		 
		cout << "type in point scale for each sides, recommended is 1, must enter a value ";
		cin >> user_input_point;

		while (user_input_point <= 0)
		{
			cout << "stop messing around, recommended is 1, must enter a value ";
			cin >> user_input_point;
		}

		value_of_point = user_input_point;
			
		if (user_bin > 0 && user_bin <= 360)
		{
			read_and_print newread;	
			dft_class do_dft;


			newread.readInFromFile(file_to_read);
			newread.passing_bin(user_bin);
			newread.what_to_print(cout, value_of_width,value_of_point);
			do_dft.calculate_DFT(&newread);
			cout << "save this ? press y to confirm, ANYKEY to cancel" << endl;
			string save;
			cin >> save;
			if (save == "y" || save == "Y")

			{
				read_and_print newread_save;
				dft_class do_dft_save;
				int new_bin;
				
				cout << "new bin " << endl;
				cin >> new_bin;
				
				newread_save.readInFromFile(file_to_read);
				newread_save.passing_bin(new_bin);
				newread_save.what_to_print(to_write, value_of_width, value_of_point);
				cout << "writing successful" << endl;
				do_dft_save.calculate_DFT(&newread_save);
			}

		}
		else { cout << "Stop messing around" << endl; }
		cout << "Run again ?, press y to confirm, ANYKEY to cancel" << endl;
		cin >> user_run;
		
		
	}
	cout << "Good Grades coming through" << endl;
	system("PAUSE");
	return 0;
}




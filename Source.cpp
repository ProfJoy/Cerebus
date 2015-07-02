#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

vector<char>alphabet; //Create GLOBAL vector to hold letters of the alphabet.

/*
Purpose: The purpose of open_file() is to be able to open any file, regardless of name.
Parameters: The function open_file() takes one parameter, a string which is the name of the file being opened.
Returns: The function open_file() does not return anything, as it is type void.

*/
void open_file(string filename){
	ifstream file_work;
	file_work.open(filename);
	int loop_count = 5;
	//While loop which checks if the correct file name is being used. Implemented this loop instead of 'isOpen' so the User can exit and check their filesystem if they can't remember the filename.
	while(!file_work && loop_count != 0){
		cout << "Incorrect File Name, " << loop_count << " tries before program exits." << " Please re-enter the filename:" << endl;
		string newFileName;
		cin >> newFileName;
		file_work.open(newFileName);
		loop_count--;
	}
}

/*
Purpose: The purpose of fill_vector() is to fill the vector of type char, 'alphabet', with individual letters of the alphabet for later use. The vector alphabet is of GLOBAL scope.
Parameters: The function fill_vector() does not take any parameters.
Returns: The function fill_vector() does not return anything, it simply adds letters to a vector.
*/
void fill_vector(){
	

	//Fill vector 'alphabet' with all the letters of the alphabet:
	alphabet.push_back('a');
	alphabet.push_back('b');
	alphabet.push_back('c');
	alphabet.push_back('d');
	alphabet.push_back('e');
	alphabet.push_back('f');
	alphabet.push_back('g');
	alphabet.push_back('h');
	alphabet.push_back('i');
	alphabet.push_back('j');
	alphabet.push_back('k');
	alphabet.push_back('l');
	alphabet.push_back('m');
	alphabet.push_back('n');
	alphabet.push_back('o');
	alphabet.push_back('p');
	alphabet.push_back('q');
	alphabet.push_back('r');
	alphabet.push_back('s');
	alphabet.push_back('t');
	alphabet.push_back('u');
	alphabet.push_back('v');
	alphabet.push_back('w');
	alphabet.push_back('x');
	alphabet.push_back('y');
	alphabet.push_back('z');
	//Vector 'alphabet' successfully filled with all the letters of the alphabet.


}

string password_mixer(string pass, string website_name){
	char key; //The first letter of the website, used to figure out the password offset.

	key = website_name[0];
	int increment_value; //This value is the position of the char key 
	
	//FOR LOOP to determine how much to offset the password by.
	for (int i = 0; i < alphabet.size(); i++){
		if (key == alphabet[i]){
			increment_value = (i + 1); 
			4//Finds the position of key in the alphabet, and sets the position # to increment_value
		}
	}
	//End FOR LOOP

	//FOR LOOP to offset and create new password
	for (int i = 0; i < pass.size(); i++){
		pass[i] = alphabet[i + increment_value];
	}
	return pass;

}







int main(){ //ToDO: Create a new file using C++ code 2. implement is_open  checks for both filestreams, 3. Implement code to actually draw from files 4. invalid response loop, instead of program exit 5.Add clear comment tags to everything

	//Initialize all values and fill alphabet vector...
	char first_time;
	string file_name; 
	string website_name;
	string pass;
	string new_pass;
	fill_vector();
	//END Initialization.

	cout << "Is this your first time using Cerebus [Y/N]?" << endl;
	cin >> first_time;

	if (first_time == 'Y'){
		cout << "What is the name of the .txt file you are using for Cerebus?" << endl;
		cin >> file_name;
		ofstream new_file(file_name);
		cout << "What is the default password you would like Cerebus to encode?" << endl;
		cin >> pass;
		new_file << pass;
		cout << "What is the name of the website you want to create a password for?" << endl;
		cin >> website_name;
		new_pass = password_mixer(pass, website_name);
		new_file << website_name << "," << pass;

	}

	if (first_time == 'N'){
		cout << "What is the name of the .txt file you use for Cerebus?" << endl;
		cin >> file_name;
		ifstream new_file(file_name);
		new_file >> pass;
		cout << "What is the name of the website you want to create a password for?" << endl;
		cin >> website_name;
		new_pass = password_mixer(pass, website_name);
		new_file >> website_name >> ":" >> pass;

	}

	else{
		cout << "Invalid Response. Program will now exit." << endl;
		return 0;
	}

	
}
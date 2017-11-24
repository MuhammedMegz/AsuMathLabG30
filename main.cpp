#include"matrix.h"
#include <iostream>
#include <fstream>
#include <string>
#include <list>

using namespace std;

void check_command(string command, list<CMatrix> &matrix_list);
void make_operation(list<string> command, list<CMatrix> &matrix_list);
void to_upperCase(string &s);

int main(int argc, char** argv){

	string inputMode = "console";
	string command;
	ifstream inputFile;
	list<CMatrix> matrix_list;
	if (argc == 2){
		inputFile.open(argv[1]);
		if (inputFile.bad() || inputFile.fail()){
			cout << "Failed to open input file" << endl;
			return 1;
		}
		inputMode = "file";
	}
	while(true){
		if (inputMode == "console"){
			getline(cin, command);
			if (command.find("\r") != -1){
				command.erase(command.find("\r"),2);
			}
			if (command == "exit"){
				break;
			}
			check_command(command, matrix_list);
		}else if (inputMode == "file"){
			getline(inputFile,command);
			if (command.find("\r") != -1){
				command.erase(command.find("\r"),2);
			}
			if (command.find('[') != -1 && command.find(']') == -1){
				string temp;
				while (true){
					getline(inputFile, temp);
					if (temp.find("\r") != -1){
						temp.erase(temp.find("\r"),2);
					}
					command += temp;
					if (temp.find(']') != -1) break;
				}
			}
			check_command(command, matrix_list);
			if (inputFile.eof()){
				inputFile.close();
				break;
			}
		}
	}
	matrix_list.clear();
	return 0;
}

void check_command(string command, list<CMatrix> &matrix_list){
	string name, matrixData;
	if (command .find('[') != -1){
		name = command.substr(0,command.find(" "));
		to_upperCase(name);
		matrixData = command.substr(command.find('['));
		CMatrix *temp = new CMatrix(matrixData);
		temp -> set_name(name);
		matrix_list.push_back(*temp);
	}else{
		list<string> command_list;
		const char *separators = " ";
		char *command_c = new char[command.size()+1];
		command.copy(command_c, command.length());
		command_c[command.length()] = '\0';
		char *token = strtok(command_c, separators);
		while (token){
			command_list.push_back(token);
			token = strtok(NULL, separators);
		}
		try{
			make_operation(command_list, matrix_list);
			command_list.clear();
		}catch(string error){
			command_list.clear();
			cout << error <<endl;
		}
	}
}

void make_operation(list<string> command_list, list<CMatrix> &matrix_list){

	string operators = "+-*/./";
	bool assign = false, number = false, error = true;
	string operation = "";
	CMatrix last_operand;
	for(list<string>::reverse_iterator l=command_list.rbegin(); l != command_list.rend(); l++){
		if (*l == "="){
			assign = true;
		}else if (operators.find(*l) == -1){
			string name = *l;
			to_upperCase(name);
			if (l->find("'") != -1){
				operation = "'";
				name.erase(name.find("'"), 1);
			}
			if(assign){
				CMatrix *temp = new CMatrix;
				*temp = last_operand;
				temp -> set_name(name);
				temp -> PrintMatrix();
				matrix_list.push_back(*temp);
			}else if (operation == "./" && number){
				number = false;
				int num = atof(l->c_str());
				last_operand.dotSlash(num);
			}else{
				for (list<CMatrix>::iterator i = matrix_list.begin(); i != matrix_list.end(); i++){
					error = true;
					if (i -> get_name() == name){
						if(operation == ""){
							last_operand = *i;
						}else{
							if (operation == "+"){
								last_operand = *i + last_operand;
							}else if(operation == "'"){
								last_operand.transpose(*i);
							}else if (operation == "-"){
								last_operand = *i - last_operand;
							}else if (operation == "*"){
								last_operand = *i * last_operand;
							}else if (operation == "/"){
								try{
									last_operand = *i / last_operand;
								}catch(string err){
									cout << err <<endl;
									return;
								}
							}
						}
						error = false;
						break;
					}
				}
				if (error){
					string err = "Wrong operation and/or matrix '" + name + "' doesn't exist";
					throw(err);
					return;
				}
			}
		}else{
			operation = *l;
			if (operation == "./") number = true;
		}
	}

}

void to_upperCase(string &s){

	for (int i=0, l=s.size(); i<l; i++){
		s[i] = toupper(s[i]);
	}
}
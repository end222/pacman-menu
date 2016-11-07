#include <iostream>

/* Author: Pablo Orduna (end222)
 * Version: 1.0 (6 Nov. 2016)
 */
 
/*
 * Pre: choose an option to manage your packages in Arch Linux
 * Post: the program will call PacMan to execute the action
 * 		with "sudo", so it assumes that it is executed as a normal
 * 		user
 */

using namespace std;

void menu(){
	cout << "PacMan Menu:" << endl;
	cout << "============" << endl;
	cout << "0 - Exit" << endl;
	cout << "1 - Install Package" << endl;
	cout << "2 - Remove Package and Dependencies" << endl;
	cout << "3 - Remove Package Only" << endl;
	cout << "4 - Update System" << endl;
	cout << "5 - Update Repositories" << endl;
	cout << "6 - Clear Package Database" << endl;
	cout << "7 - Make a Search in the Repositories" << endl;
	cout << "8 - Edit Repositories" << endl;
}

void opt1(){
	cout << "What package do you want to install?: " << flush;
	string package;
	cin >> package;
	system(("sudo pacman -S "+package).c_str());
}

void opt2(){
	cout << "What package do you want to remove?: " << flush;
	string package;
	cin >> package;
	system(("sudo pacman -Rs "+package).c_str());
}

void opt3(){
	cout << "What package do you want to remove?: " << flush;
	string package;
	cin >> package;
	system(("sudo pacman -R "+package).c_str());
}

void opt4(){
	system("sudo pacman -Syu");
}

void opt5(){
	system("sudo pacman -Syy");
}

void opt6(){
	system("sudo pacman -Sc");
}

void opt7(){
	cout << "What do you want to search in the repositories?: " << flush;
	string package;
	cin >> package;
	system(("sudo pacman -Ss "+package).c_str());
}

void opt8(){
	system("sudo nano /etc/pacman.conf");
}

void option(int n){
	if(n==1) opt1();
	if(n==2) opt2();
	if(n==3) opt3();
	if(n==4) opt4();
	if(n==5) opt5();
	if(n==6) opt6();
	if(n==7) opt7();
	if(n==8) opt8();
}

int main(){
	menu();
	int n;
	cout << "Choose an option [0-8]: " << flush;
	cin >> n;
	option(n);
	return 0;
}

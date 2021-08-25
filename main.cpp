
#include<iostream>
#include<sstream>
using std::cout;
using std::cin;
using std::string;
using std::endl;
using std::stringstream;


class student
{
public:
	string Name;
	int Grade;
	string ID;
	string IDarr[10];
	string arr[10];
	int gradearr[10] = {0,0,0,0,0,0,0,0,0,0};// all grades initialized to 0

	void printclass(float AVR) // prints all of the class information
	{
		for (int i=0; i<10;i++) 
		{
			cout << arr[i] <<endl << "-> Grade:";// name of student
			if (gradearr[i] == 0) 
			{
				cout << " No grade information entered yet."
				<<"     ID:"<< IDarr[i] << endl;
			}
			else 
			{
				cout << gradearr[i] // student grade
				<< "     ID:" << IDarr[i] << endl;// student ID
			}
			cout << endl;
		}// for loop
		if (AVR == 0)
		{
			cout << "No class average" << endl;// if grades still 0
		}
		else
		{
			cout << "Class average is:" << AVR << "%" << endl << endl;// class average 
		}
		cout << endl;
	}// function loop

	void printgrades(float ave) // prints only class grades
	{
		for (int i = 0; i < 10; i++)
		{
			cout << arr[i] <<endl<< "-> Grade: ";// student name 
			
			if (gradearr[i] == 0)//if grades is still 0
			{
				cout << " No grade information entered yet." << endl;
			}
			else
			{
				cout << gradearr[i] << endl;// student grade
			}
			cout << endl;
		}
		if (ave == 0) 
		{
			cout << "No Class Average" << endl;// if grades still 0
		}
		else 
		{
			cout << "Class average is:" << ave << "%" << endl << endl;// class average
		}	
		cout << endl;

	}

	void singular(int sel) // prints the information for one student
	{
		cout << arr[sel] << endl<< "-> Grade:";// student name 
		
		if (gradearr[sel] == 0)
		{
			cout << " No grade information entered yet."// if grades still 0
			<< "     ID:" << IDarr[sel] << endl;
		}
		else
		{
			cout << gradearr[sel]// student grade
			<< "     ID:" << IDarr[sel] << endl;
		}
		cout << endl;
	}
};

string students();// student function prototype
int grade(string name12, string name22,string name32,string name42,string name52,//grade function prototype
	      string name62, string name72,string name82,string name92,string name102);
string name1,name2,name3,name4,name5,name6,name7,name8,name9,name10;
string ID1, ID2, ID3, ID4, ID5, ID6, ID7, ID8, ID9,ID10;
int grade1, grade2, grade3, grade4, grade5, grade6, grade7, grade8, grade9, grade10;
int g1, g2, g3, g4, g5, g6, g7, g8, g9, g10;
float AVE = 0;// int fot average calculation
int intarr[10];
string namechange;// string handles changing student name 
int gradechange;// int handles student grade change
string IDchange;// string handles student ID change


int main()
{
	student one;
	int selection;// menu option int for single student selection
	int infochange;// menu option int to change student information
	int Manage;// menu option int for main menu
	bool flag  = false;
	
	do 
	{
		cout << "****************" << endl;
		cout << "CLASS MANAGEMENT" << endl;// class management menu 
		cout << "****************" << endl;
		cout << "To register students.....................  press 1" << endl;
		cout << "To enter grades..........................  Press 2" << endl;
		cout << "To see grades and student ID's...........  press 3" << endl;
		cout << "To See Class Grades......................  Press 4" << endl;
		cout << "To Select one student....................  Press 5" << endl;
		cout << "To change a student's information........  Press 6" << endl;
		cout << "To Exit Press............................  Press 7" << endl;//exit option
		cout << "Option: ";
		cin >> Manage;
		cout << endl;

		while (Manage < 1 || Manage>7 || cin.fail())  //cheks input to make sure it is valid
		{
			cin.clear();
			cin.ignore(256,'\n');
			cout << "Enter a valid option" << endl;
			cout << "Option: ";
			cin >> Manage;
			cout << endl;
		}

		switch (Manage)// switch stament to handle class management menu
		{

		case 1:

			students();// student function called to take names and student ID 

			one.IDarr[0] = ID1;// fills ID array
			one.IDarr[1] = ID2;
			one.IDarr[2] = ID3;
			one.IDarr[3] = ID4;
			one.IDarr[4] = ID5;
			one.IDarr[5] = ID6;
			one.IDarr[6] = ID7;
			one.IDarr[7] = ID8;
			one.IDarr[8] = ID9;
			one.IDarr[9] = ID10;

			one.arr[0] = name1;// fills name array
			one.arr[1] = name2;
			one.arr[2] = name3;
			one.arr[3] = name4;
			one.arr[4] = name5;
			one.arr[5] = name6;
			one.arr[6] = name7;
			one.arr[7] = name8;
			one.arr[8] = name9;
			one.arr[9] = name10;
			flag = true;// sets flag to inform the program that there are students added
			cout << endl;
			break;

		case 2:

			if (flag == true) 
			{
				// grade function call with all string names being passed to the function
				grade(name1, name2, name3, name4, name5, name6, name7, name8, name9, name10);
			
				for (int r = 0; r < 10; r++)// for loop fills grade array 
				{
					one.gradearr[r] = intarr[r];
				}

				for (int a = 0; a < 10; a++) // for loop calculates average
				{
					AVE = AVE + intarr[a];
				}
				AVE = AVE / 10;
			}
			else 
			{
				cout << "No Students to grade." << endl << endl;//if there are no studnets 
			}

			break;

		case 3:

			if (flag == true)// if there are students
			{
				one.printclass(AVE);// average passed to printclass in declared student class
			}
			else
			{
			 cout << endl << "No Student information available." << endl << endl;// no students to print 
			}

			break;


		case 4:

			if (flag == true)
			{
				one.printgrades(AVE);// average passed to printgrades in declared student class
			}
			else
			{
				cout << endl << "No Student information available." << endl << endl;// no students to print
			}
			
			break;

		case 5:

			if (flag == true)
			{
				cout << "Who's information do you want to see?" << endl;// single student selection
				
				cout << "To see " << name1 << endl
					 << "		-> Press 1"  << endl;
				
				cout << "To see " << name2 << endl
				     << "		-> Press 2"  << endl;
				
				cout << "To see " << name3 << endl
					 << "		-> Press 3"  << endl;
				
				cout << "To see " << name4 << endl
					<< "		-> Press 4"  << endl;
				
				cout << "To see " << name5 << endl
					 << "		-> Press 5"  << endl;
				
				cout << "To see " << name6 << endl
					 << "		-> Press 6"  << endl;
				
				cout << "To see " << name7 << endl
					 << "		-> Press 7"  << endl;
				
				cout << "To see " << name8 << endl
					 << "		-> Press 8"  << endl;
				
				cout << "To see " << name9 << endl
					 << "		-> Press 9"  << endl;
				
				cout << "To see " << name10 << endl
					 << "		-> Press 10" << endl;

				cout << "To go back to main menu:" << endl// exit option
					<< "		-> press 11" << endl;
				
				cout << "option:";
				cin >> selection;// option input

				if (selection == 11)
				{
					break;
				}
				
				cout << endl;
				selection = selection - 1;
				one.singular(selection);// student selection variable passed to singular student function
			}
			else
			{
				cout << endl << "No Student information available." << endl<<endl;
			}
			break;

		case 6:
			if (flag == true)
			{
				cout << "Who's information do you want to update?" << endl;// update information selection
				// student menu
				cout << "To update " << name1 <<":" << endl  
					 << "		-> Press 1"  << endl;
				
				cout << "To update " << name2 << ":" << endl  
					 << "		-> Press 2"  << endl;
				
				cout << "To update " << name3 << ":" << endl
					 << "		-> Press 3"  << endl;
				
				cout << "To update " << name4 << ":" << endl
					 << "		-> Press 4"  << endl;
				
				cout << "To update " << name5 << ":" << endl
					 << "		-> Press 5"  << endl;
				
				cout << "To update " << name6 << ":" << endl
					 << "		-> Press 6"  << endl;
				
				cout << "To update " << name7 << ":" << endl
					 << "		-> Press 7"  << endl;
				
				cout << "To update " << name8 << ":" << endl
					 << "		-> Press 8"  << endl;
				
				cout << "To update " << name9 << ":" << endl
					 << "		-> Press 9"  << endl;
				
				cout << "To update " << name10 << ":" << endl
					 << "		-> Press 10" << endl;
				
				cout << "To go back to main menu:" << endl // exit option 
					 <<"		-> press 11" << endl;
				
				cout << "option: ";
				
				cin >> infochange;
				cout << endl;  

				if (infochange == 11) 
				{
					break;
				}
				// setudent menu
				if (infochange == 1)
				{
					cout << "Updating: " << name1 << endl;
				}

				if (infochange == 2)
				{
					cout << "Updating: " << name2 << endl;
				}

				if (infochange == 3)
				{
					cout << "Updating: " << name3 << endl;
				}

				if (infochange == 4)
				{
					cout << "Updating: " << name4 << endl;
				}

				if (infochange == 5)
				{
					cout << "Updating: " << name5 << endl;
				}

				if (infochange == 6)
				{
					cout << "Updating: " << name6 << endl;
				}

				if (infochange == 7)
				{
					cout << "Updating: " << name7 << endl;
				}

				if (infochange == 8)
				{
					cout << "Updating: " << name8 << endl;
				}

				if (infochange == 9)
				{
					cout << "Updating: " << name9 << endl;
				}

				if (infochange == 10)
				{
					cout << "Updating: " << name10 << endl;
				}
				
				switch (infochange)// nested switch stament to handle student information update menu
				{
				case 1:
					cout << "Name on file: " << name1 << "  " << " Grade on file: " << intarr[infochange - 1] << "  ID on file: " << ID1 << endl;
					cout << "If name changed, enter a new name. If no name change enter the same name -> ";
					cin >> namechange;
					name1 = namechange;//updates initial string
					one.arr[infochange - 1] = namechange;//updates array with names 

					cout << "If grade changed, enter a new grade. If no grade change enter the same grade-> ";
					cin >> gradechange;
					one.gradearr[infochange - 1] = gradechange;// updates array with grades

					cout << "If ID changed, enter a new ID. If no ID change enter the same ID-> ";
					cin >> IDchange;
					one.IDarr[infochange - 1] = IDchange;// updates array with ID
					cout << endl;

					break;

				case 2:
					cout << "Name on file: " << name2 << "  " << " Grade on file: " << intarr[infochange - 1] << "  ID on file: " << ID2 << endl;
					cout << "If name changed, enter a new name. If no name change enter the same name -> ";
					cin >> namechange;
					name2 = namechange;//updates initial string
					one.arr[infochange - 1] = namechange;//updates array with names

					cout << "If grade changed, enter a new grade. If no grade change enter the same grade-> ";
					cin >> gradechange;
					one.gradearr[infochange - 1] = gradechange;// updates array with grades

					cout << "If ID changed, enter a new ID. If no ID change enter the same ID-> ";
					cin >> IDchange;
					one.IDarr[infochange - 1] = IDchange;// updates array with ID
					cout << endl;
				
					break;

				case 3:
					cout << "Name on file: " << name3 << "  " << " Grade on file: " << intarr[infochange - 1] << "  ID on file: " << ID3 << endl;
					cout << "If name changed, enter a new name. If no name change enter the same name -> ";
					cin >> namechange;
					name3 = namechange;//updates initial string
					one.arr[infochange - 1] = namechange;//updates array with names

					cout << "If grade changed, enter a new grade. If no grade change enter the same grade-> ";
					cin >> gradechange;
					one.gradearr[infochange - 1] = gradechange;// updates array with grades

					cout << "If ID changed, enter a new ID. If no ID change enter the same ID-> ";
					cin >> IDchange;
					one.IDarr[infochange - 1] = IDchange;// updates array with ID
					cout << endl;
					
					break;

				case 4:
					cout << "Name on file: " << name4 << "  " << " Grade on file: " << intarr[infochange - 1] << "  ID on file: " << ID4 << endl;
					cout << "If name changed, enter a new name. If no name change enter the same name -> ";
					cin >> namechange;
					name4 = namechange;//updates initial string
					one.arr[infochange - 1] = namechange;//updates array with names

					cout << "If grade changed, enter a new grade. If no grade change enter the same grade-> ";
					cin >> gradechange;
					one.gradearr[infochange - 1] = gradechange;// updates array with grades

					cout << "If ID changed, enter a new ID. If no ID change enter the same ID-> ";
					cin >> IDchange;
					one.IDarr[infochange - 1] = IDchange;// updates array with ID
					cout << endl;
					
					break;

				case 5:
					cout << "Name on file: " << name5 << "  " << " Grade on file: " << intarr[infochange - 1] << "  ID on file: " << ID5 << endl;
					cout << "If name changed, enter a new name. If no name change enter the same name -> ";
					cin >> namechange;
					name5 = namechange;//updates initial string
					one.arr[infochange - 1] = namechange;//updates array with names

					cout << "If grade changed, enter a new grade. If no grade change enter the same grade-> ";
					cin >> gradechange;
					one.gradearr[infochange - 1] = gradechange;// updates array with grades

					cout << "If ID changed, enter a new ID. If no ID change enter the same ID-> ";
					cin >> IDchange;
					one.IDarr[infochange - 1] = IDchange;// updates array with ID
					cout << endl;
					
					break;

				case 6:
					cout << "Name on file: " << name6 << "  " << " Grade on file: " << intarr[infochange - 1] << "  ID on file: " << ID6 << endl;
					cout << "If name changed, enter a new name. If no name change enter the same name -> ";
					cin >> namechange;
					name6 = namechange;//updates initial string
					one.arr[infochange - 1] = namechange;//updates array with names

					cout << "If grade changed, enter a new grade. If no grade change enter the same grade-> ";
					cin >> gradechange;
					one.gradearr[infochange - 1] = gradechange;// updates array with grades

					cout << "If ID changed, enter a new ID. If no ID change enter the same ID-> ";
					cin >> IDchange;
					one.IDarr[infochange - 1] = IDchange;// updates array with ID
					cout << endl;
					
					break;

				case 7:
					cout << "Name on file: " << name7 << "  " << " Grade on file: " << intarr[infochange - 1] << "  ID on file: " << ID7 << endl;
					cout << "If name changed, enter a new name. If no name change enter the same name -> ";
					cin >> namechange;
					name7 = namechange;//updates initial string
					one.arr[infochange - 1] = namechange;//updates array with names

					cout << "If grade changed, enter a new grade. If no grade change enter the same grade-> ";
					cin >> gradechange;
					one.gradearr[infochange - 1] = gradechange;// updates array with grades

					cout << "If ID changed, enter a new ID. If no ID change enter the same ID-> ";
					cin >> IDchange;
					one.IDarr[infochange - 1] = IDchange;// updates array with ID
					cout << endl;
					
					break;

				case 8:
					cout << "Name on file: " << name8 << "  " << " Grade on file: " << intarr[infochange - 1] << "  ID on file: " << ID8 << endl;
					cout << "If name changed, enter a new name. If no name change enter the same name -> ";
					cin >> namechange;
					name8 = namechange;//updates initial string
					one.arr[infochange - 1] = namechange;//updates array with names

					cout << "If grade changed, enter a new grade. If no grade change enter the same grade-> ";
					cin >> gradechange;
					one.gradearr[infochange - 1] = gradechange;// updates array with grades

					cout << "If ID changed, enter a new ID. If no ID change enter the same ID-> ";
					cin >> IDchange;
					one.IDarr[infochange - 1] = IDchange;// updates array with ID
					cout << endl;
					
					break;

				case 9:
					cout << "Name on file: " << name9 << "  " << " Grade on file: " << intarr[infochange - 1] << "  ID on file: " << ID9 << endl;
					cout << "If name changed, enter a new name. If no name change enter the same name -> ";
					cin >> namechange;
					name9 = namechange;//updates initial string
					one.arr[infochange - 1] = namechange;//updates array with names

					cout << "If grade changed, enter a new grade. If no grade change enter the same grade-> ";
					cin >> gradechange;
					one.gradearr[infochange - 1] = gradechange;// updates array with grades

					cout << "If ID changed, enter a new ID. If no ID change enter the same ID-> ";
					cin >> IDchange;
					one.IDarr[infochange - 1] = IDchange;// updates array with ID
					cout << endl;
					
					break;

				case 10:
					cout << "Name on file: " << name10 << "  " << " Grade on file: " << intarr[infochange - 1] << "  ID on file: " << ID10 << endl;
					cout << "If name changed, enter a new name. If no name change enter the same name -> ";
					cin >> namechange;
					name10 = namechange;//updates initial string
					one.arr[infochange - 1] = namechange;//updates array with names

					cout << "If grade changed, enter a new grade. If no grade change enter the same grade-> ";
					cin >> gradechange;
					one.gradearr[infochange - 1] = gradechange;// updates array with grades

					cout << "If ID changed, enter a new ID. If no ID change enter the same ID-> ";
					cin >> IDchange;
					one.IDarr[infochange - 1] = IDchange;// updates array with ID
					cout << endl;
					
					break;
				}
			}
			else
			{
				cout << endl << "No Student information to change." << endl << endl;;
			}
			break;
		}

	} while (Manage != 7);// do while loop kills program when 7 is picked in the initial menu

}
    // function takes all student anmes as well as student ID numbersand returns them 
	string students()
	{
		cout << "Enter student one name:    ";
		cin >> name1;// student name input
		cout << "Enter " << name1 << "'s " << "ID:";
		cin >> ID1;// student ID string put
		cout << endl;

		cout << "Enter student two name:    ";
		cin >> name2;
		cout << "Enter " << name2 << "'s " << "ID:";
		cin >> ID2;
		cout << endl;

		cout << "Enter student three name:  ";
		cin >> name3;
		cout << "Enter " << name3 << "'s " << "ID:";
		cin >> ID3;
		cout << endl;

		cout << "Enter student four name:   ";
		cin >> name4;
		cout << "Enter " << name4 << "'s " << "ID:";
		cin >> ID4;
		cout << endl;

		cout << "Enter student five name:   ";
		cin >> name5;
		cout << "Enter " << name5 << "'s " << "ID:";
		cin >> ID5;
		cout << endl;

		cout << "Enter student six name:    ";
		cin >> name6;
		cout << "Enter " << name6 << "'s " << "ID:";
		cin >> ID6;
		cout << endl;

		cout << "Enter student seven name:  ";
		cin >> name7;
		cout << "Enter " << name7 << "'s " << "ID:";
		cin >> ID7;
		cout << endl;

		cout << "Enter student eight name:  ";
		cin >> name8;
		cout << "Enter " << name8 << "'s " << "ID:";
		cin >> ID8;
		cout << endl;

		cout << "Enter student nine name:   ";
		cin >> name9;
		cout << "Enter " << name9 << "'s " << "ID:";
		cin >> ID9;
		cout << endl;

		cout << "Enter student ten name:    ";
		cin >> name10;
		cout << "Enter " << name10 << "'s " << "ID:";
		cin >> ID10;
		cout << endl;

		return name1, name2, name3, name4, name5,name6, name7, name8, name9, name10,
			   ID1, ID2, ID3, ID4, ID5, ID6, ID7, ID8, ID9, ID10;
	}
	
	// Function takes all student grades and returns them
	int grade(string name12, string name22, string name32, string name42, string name52,
		      string name62, string name72, string name82, string name92, string name102)
	{
	
		cout << "Enter " << name12 << "'s grade out of 100: " << endl;
		cout << " -> ";
		cin >> grade1;
		cout << endl;
		
		while (grade1 > 100 || grade1 < 0||cin.fail())// while loop makes sure the grade entered is valid
		{
			cin.clear();
			cin.ignore(256, '\n');
			cout << "Enter a valid grade out of 100:";
			cin >> grade1;
		}
			intarr[0] = grade1;// stores grade in array index
		
			cout << "Enter " << name22 << "'s grade out of 100: " << endl;
		cout << " -> ";
		cin >> grade2;
		cout << endl;

		while (grade2 > 100 || grade2 < 0 || cin.fail())
		{
			cin.clear();
			cin.ignore(256, '\n');
			cout << "Enter a valid grade out of 100:";
			cin >> grade2;
		}
			intarr[1] = grade2;

			cout << "Enter " << name32 << "'s grade out of 100: " << endl;
		cout << " -> ";
		cin >> grade3;
		cout << endl;

		while (grade3 > 100 || grade3 < 0 || cin.fail())
		{
			cin.clear();
			cin.ignore(256, '\n');
			cout << "Enter a valid grade out of 100:";
			cin >> grade3;
		}
			intarr[2] = grade3;

		cout << "Enter " << name42 << "'s grade out of 100: "<<endl;
		cout << " -> ";
		cin >> grade4;
		cout << endl;

		while (grade4 > 100 || grade4 < 0 || cin.fail())
		{
			cin.clear();
			cin.ignore(256, '\n');
			cout << "Enter a valid grade out of 100:";
			cin >> grade4;
		}
			intarr[3] = grade4;

		cout << "Enter " << name52 << "'s grade out of 100: "<<endl;
		cout << " -> ";
		cin >> grade5;
		cout << endl;

		while (grade5 > 100 || grade5 < 0 || cin.fail())
		{
			cin.clear();
			cin.ignore(256, '\n');
			cout << "Enter a valid grade out of 100:";
			cin >> grade5;
		}
			intarr[4] = grade5;

		cout << "Enter " << name62 << "'s grade out of 100: "<<endl;
		cout << " -> ";
		cin >> grade6;
		cout << endl;

		while (grade6 > 100 || grade6 < 0 || cin.fail())
		{
			cin.clear();
			cin.ignore(256, '\n');
			cout << "Enter a valid grade out of 100:";
			cin >> grade6;
		}
			intarr[5] = grade6;

		cout << "Enter " << name72 << "'s grade out of 100: "<<endl;
		cout << " -> ";
		cin >> grade7;
		cout << endl;

		while (grade7 > 100 || grade7 < 0 || cin.fail())
		{
			cin.clear();
			cin.ignore(256, '\n');
			cout << "Enter a valid grade out of 100:";
			cin >> grade7;
		}
			intarr[6] = grade7;


		cout << "Enter " << name82 << "'s grade out of 100: "<<endl;
		cout << " -> ";
		cin >> grade8; 
		cout << endl;

		while (grade8 > 100 || grade8 < 0 || cin.fail())
		{
			cin.clear();
			cin.ignore(256, '\n');
			cout << "Enter a valid grade out of 100:";
			cin >> grade8;
		}
			intarr[7] = grade8;

		cout << "Enter " << name92 << "'s grade out of 100: "<<endl;
		cout << " -> ";
		cin >> grade9;
		cout << endl;

		while (grade9 > 100 || grade9 < 0 || cin.fail())
		{
			cin.clear();
			cin.ignore(256, '\n');
			cout << "Enter a valid grade out of 100:";
			cin >> grade9;
		}
			intarr[8] = grade9;

		cout << "Enter " << name102 << "'s grade out of 100: "<<endl;
		cout << " -> ";
		cin >> grade10;
		cout << endl;

		while (grade10 >
			100 || grade10 < 0 || cin.fail())
		{
			cin.clear();
			cin.ignore(256, '\n');
			cout << "Enter a valid grade out of 100:"<<endl;
			cin >> grade10;
		}
			intarr[9] = grade10;

		return intarr[0], intarr[1], intarr[2], intarr[3], intarr[4], 
			   intarr[5], intarr[6], intarr[7], intarr[8], intarr[9];
	}

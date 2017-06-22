#include <iostream>
using namespace std;

int main(){ 

	int trunkHeight = 0;
    int trunkWidth = 0;
    int leaveWidth = 0;
    int rows = 0;
    cout << "Enter trunk height: ";
    cin >> trunkHeight;
    cout << "Enter trunk width: ";
    cin >> trunkWidth;
     while ((trunkWidth % 2) == 0) {
   cout << "Please enter an odd number for the width: ";
   cin >> trunkWidth;
   trunkWidth = trunkWidth;
     }
    cout << "Enter leaves width: ";
   cin >> leaveWidth;
   cout << endl;
    int row = (leaveWidth/2);
	int a = 0;
    for (int x = 1; x <= leaveWidth; x=x+2)
	{
                for(int i = 1; i<= (row -a); i++){
                        cout << " ";
}
            a= a+1;
        	for(int y = 1; y <= x; y++)
		{
			cout << "*";
		}
		cout << endl;
	}

    int trunkMov = (leaveWidth-trunkWidth)/2;
	for (rows = 0; rows < trunkHeight; rows++){
		for (int mov = 0; mov < trunkMov; mov++){
		    cout << " ";
		}
		for (int width = 0; width < trunkWidth; width++){
			cout << "*";
		}
		
		cout << endl;
	}

  return 0;
}
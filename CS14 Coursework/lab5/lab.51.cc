#include <iostream>
#include <fstream>
#include <list>
#include <algorithm>
#include <cmath>     /* fabs */
#include <math.h>    /* sqrt */
#include <string>
#include <sstream>
#include <iterator>

using namespace std;


class Fraction
{
            int gcd(int a, int b) { return b==0 ? a : gcd(b,a%b); }
            int n;
            int d;
    
        public:
            Fraction()
            {
                n = 0;
                d = 1;
            }
            Fraction(int n, int d = 1) : n(n/gcd(std::abs(n),std::abs(d))), d(d/gcd(std::abs(n),std::abs(d))) {
            if (this->d < 0) {
                this->n *= -1;
                this->d *= -1;
            }
        }
            
            int num() const { return n; }
            int den() const { return d; }
            
            Fraction & operator*=(const Fraction& rhs) 
            
            {
                int new_n = n*rhs.n / gcd(std::abs(n*rhs.n), std::abs(d*rhs.d));
                d = d*rhs.d / gcd(std::abs(n*rhs.n), std::abs(d*rhs.d));
                n = new_n;
                return *this;
            }

             Fraction& operator -=(const Fraction& rhs)
                {
                    int new_num= (n * rhs.d) - (d * rhs.n);
                    int new_den = d * rhs.d;
                    
                    n = new_num / gcd(std::abs(new_num), std::abs(new_den));
                    d = new_den / gcd(std::abs(new_num), std::abs(new_den));
                    
                    return *this;
                }
                
            Fraction& operator =(const Fraction& rhs)
            {
                this->n = rhs.n;
                this->d = rhs.d;
                
                return *this;
            }
            Fraction& ChangeFraction(int n, int d)
            {
                this->n = n;
                this->d = d;
                
                return *this;
            }
        
};

std::ostream& operator<<(std::ostream& out, const Fraction& f) 
{
    return out << f.num() << '/' << f.den() ;
}

bool operator==(const Fraction& lhs, const Fraction& rhs) 
{
    return ((lhs.num() * rhs.den()) == (rhs.num() * lhs.den()));
}
bool operator<(const Fraction& lhs, const Fraction& rhs) 
{
    return (lhs.num() * rhs.den() < rhs.num() * lhs.den());
}
bool operator>(const Fraction& lhs, const Fraction& rhs) 
{
    return (lhs.num() * rhs.den() > rhs.num() * lhs.den());
}
Fraction operator*(Fraction lhs, const Fraction& rhs) 
{
    return lhs *= rhs;
}
Fraction operator-(Fraction lhs, const Fraction& rhs) 
{
    return lhs -= rhs;
}

template<typename Comparable>
void print_list(const vector<Comparable>& v, int left, int right)
{
    if(right < left)
    {
        cout << "Printing Heap:" << endl;
        cout << left << ": Empty!" << endl << endl;
        return;
    }
    
    else
    {
        for(int i = 0; i < v.size(); ++i)
        {
            if(i == left && left == right)
            {
                cout << "[" << v.at(i) << "]" << " ";
            }
            else if(i == left)
            {
                cout << "[" << v.at(i) << " ";
            }
            
            else if(i == right)
            {
                cout << v.at(i) << "]" << " ";
            }
            
            else
            {
                cout << v.at(i) << " ";
            }
        }
    }
    cout << endl;
}

template<typename T>
int buildHeap(vector<T> &V, int left, int right)
{
    if(right - left + 1 > V.size() || left > right)
    {
        return -1;
    }
    int hole;
    int child;
    int size = right - left + 1;
    
    if(left == 0)
    {
        for(int i = size/2; i > 0; --i)
        {
            hole = i + (left - 1);
            T tmp = move(V.at(hole));
            for( ; hole * 2 <= size; hole = child)
            {
                child = (hole * 2) + 1;
                //cout << hole << " " << child << endl;
                if( (child + 1 >= right + 1 )  ) {break;}
                if(child != size && V.at(child + 1) > V.at(child))
                {
                    ++child;
                }
                if(V.at(child) > tmp)
                {
                    V.at(hole) = move(V.at(child) );
                }
                else {break;}
                
            }
            
            V.at(hole) = move(tmp);
        }
    }
    else
    {
        for(int i = size/2; i > 0; --i)
        {
            hole = i + (left - 1);
            T tmp = move(V.at(hole));
            for( ; hole * 2 <= size; hole = child)
            {
                child = (hole * 2);
                //cout << V.at(hole) << " " << V.at(child) << endl;
                
                if(child != size && V.at(child + 1) > V.at(child))
                {
                    ++child;
                }
                if(V.at(child) > tmp)
                {
                    V.at(hole) = move(V.at(child) );
                }
                else {break;}
               // print_list(V, left, right);
            }
            
            V.at(hole) = move(tmp);
        }
    }
    
    return 1;
}

template<typename T>
void printHeap (vector<T> &V, int left, int right) // Heap is between V[left] - V[right]
{
    //cout << left << " " << right << endl;
    int heapInc = 0;
    int i = 0;
    int h = 0;
    for(i = left; i <= right; i = i + heapInc)
    {
        if(i == 0)
        {
            cout << i << ": " << V.at(i);
        }
        else
        {
            cout << i << ": ";
            //cout << heapInc << endl;
            for(int j = i; j < (i + heapInc + 1); ++j)
            {
                //cout << j << " " << heapInc << endl;
                if(j == right + 1) { cout << endl; return; }
                
                cout << V.at(j) << " ";
                h = j;
            }
        }
        //cout << heapInc << endl;
        if(heapInc == 0)
        {
            heapInc = heapInc + 1;
        }
        else
        {
            heapInc = heapInc * 2;
        }
        //cout << left << " " << right << endl;
        if(i + heapInc > right)
        {
            i = h + 1;
            for( ; i <= right; ++i)
            {
                if(heapInc % i == 0)
                {
                    cout << endl << i << ": ";
                }
                cout << V.at(i) << " ";
            }
            cout << endl << endl;
            return;
        }
        cout << endl;
    }
    cout << endl; 
    return;
    
}

template<typename T>
void deleteMax (vector<T> &V, int &left, int &right, T &maxItem)
{
    if(left >= right) 
    {
        print_list(V, left, --right);
        return;
    }
        // if (right - left == 1)
    // {
    //     
    // }
        
        
    if(V.at(left) < V.at(right))
    {
        --right;
        
        print_list(V, left, right);
        buildHeap(V, left, right);
        cout << "Printing new heap:" << endl;
        
        printHeap(V, left, right);
        cout << endl;
        deleteMax(V, left, right, V.at(left));
        
        return;
    }
    else
    {
        maxItem = V.at(left);
        T copy = V.at(left);
        V.at(left) = V.at(right);
        V.at(right) = copy;
        
        --right;
        
        //print_list(V, left, right);
        buildHeap(V, left, right);
        cout << "Printing new heap:" << endl;
        
        printHeap(V, left, right);
        cout << endl;
        deleteMax(V, left, right, V.at(left));
        
        return;
    }
        
}

template<typename T>
int Marjory (vector<T> &V, int left, int right) // Sort the block V[left] - V[right]
{
    int hold_Left = left;
    int hold_Right = right;
    
    int x = buildHeap(V, left, right);
    print_list(V, left, right);
    printHeap(V, left, right);
    
    deleteMax(V, left, right, V.at(left));
    
    cout << "New sorted vector: ";
    print_list(V, hold_Left, hold_Right);
    if(x == -1)
    {
        cout << "Error!" << endl;
    }
    
    if(x == 1)
    {
        //printHeap(V, left, right);
        cout << "Success!" << endl << endl;
    }
    
}

template<typename T>
int Marjory (vector<T> &V) // Sort entire vector V
{
    int hold_Left = 0;
    int hold_Right = V.size() - 1;
    
    int x = buildHeap(V, 0, V.size() - 1);
    print_list(V, 0, V.size() - 1);
    printHeap(V, 0, V.size -1);
    deleteMax(V, 0, V.size -1, V.at(0));
    
    cout << "New sorted vector: ";
    print_list(V, 0, V.size -1);
    if(x == -1)
    {
        cout << "Error!" << endl;
    }
    
    if(x = 1)
    {
        cout << "Success!" << endl;
    }
    
   // printHeap(V, 0, V.size() - 1);
}

int main(int argc, char* argv[])
{
    ifstream myFile (argv[argc - 1]);
    
    vector<int> intVector(0);
    vector<double> doubleVector(0);
    vector<Fraction> fractionVector;
    
    int lEndP = 0; //left endpoint
    int rEndP = 0; //right endpoint
    
    if(argc == 2)
    {
        char type = 'n';
        
        istringstream ss;
    	string inp;
        int c = 0;
        if(myFile.is_open())
        {
            
            myFile >> type;
            
            while( c != 3)
            {
            
            if(type != 'i' && type != 'I' && type != 'd' && type != 'D' && type != 'f' && type != 'F')
            {
                cout << "Error. Terminating Function...";
                return 0;
            }
            
            if(type == 'i' || type == 'I')
            {
            	ss.clear();
        	    getline (myFile, inp);
            	ss.str(inp);
            	
            	if(!ss.eof())
            	{
            	    ss >> lEndP;
            	    ss >> rEndP;
            	}
            	
            	getline(myFile, inp);
            	ss.clear();
            	ss.str(inp);
            	
            	int foo;
            	while(ss >> foo)
            	{
            	    intVector.push_back(foo);
            	}
            	
            	myFile.clear();
            	//myFile.sync();
                //cout << lEndP << " " << rEndP << endl;
            	print_list(intVector, lEndP, rEndP);
            	Marjory(intVector, lEndP, rEndP);
            	
            }
            
            else if(type == 'd' || type == 'D')
            {
                double foo;
                
                ss.clear();
        	    getline (myFile, inp);
            	ss.str(inp);
            	
            	if(!ss.eof())
            	{
            	    ss >> lEndP;
            	    ss >> rEndP;
            	}
            	
            	getline(myFile, inp);
            	ss.clear();
            	ss.str(inp);
            	
            	
            	while(ss >> foo)
            	{
            	    doubleVector.push_back(foo);
            	}
            	
            	
            	myFile.clear();
            	myFile.sync();
            	
            	print_list(doubleVector, lEndP, rEndP);
            	Marjory(doubleVector, lEndP, rEndP);
            	
            }
            
            else if(type == 'f' || type == 'F')
            {
            	int foo;
        	    int foo2;
        	    ss.clear();
        	    getline (myFile, inp);
            	ss.str(inp);
            	
            	if(!ss.eof())
            	{
            	    ss >> lEndP;
            	    ss >> rEndP;
            	}
            	
            	getline(myFile, inp);
            	ss.clear();
            	ss.str(inp);
            	
            	Fraction hold_frac(0, 1);
            
            	while(ss >> foo >> foo2)
            	{
            	    hold_frac.ChangeFraction(foo, foo2);
            		fractionVector.push_back(hold_frac);
            	}
            	
            	print_list(fractionVector, lEndP, rEndP);
            	Marjory(fractionVector, lEndP, rEndP);
            	
            }
            
		  ++c; 
		  myFile >> type;
        }
      }
    }  
    else
    {
        char type = 'n';
        
        cout << "Please enter a type: ";
        cin >> type;
        if(type != 'i' && type != 'I' && type != 'd' && type != 'D' && type != 'f' && type != 'F')
        {
            cout << "Error, would you like to try again? (y/n):  ";
            cin >> type;
            
            if(type != 'y' && type != 'Y')
            {
                cout << endl << "terminating program...";
                return 0;
            }
            while(type != 'i' && type != 'I' && type != 'd' && type != 'D' && type != 'f' && type != 'F')
            {
                cout << "Enter vector type: ";
                cin >> type;
                cout << endl;
                
                if(type != 'i' && type != 'I' && type != 'd' && type != 'D' && type != 'f' && type != 'F')
                {
                    cout << "Error, would you like to try again? (y/n):  ";
                    cin >> type;
                    
                    if(type != 'y' && type != 'Y')
                    {
                        cout << endl << "terminating program...";
                        return 0;
                    }
                }
                
            }
        }
        
        if(type == 'i' || type == 'I')
        {
            int hold = 0;
            cout << "Enter as many ints, then hit enter, then ctrl-d: ";
            while(cin >> hold)
            {
                
                if(cin.eof())
                {
                    cin.clear();
                    cin.sync();
                    break;
                }
                intVector.push_back(hold);
            }
            cin.clear();
            cin.sync();
            cout << endl;
            
            cout << "Enter endpoint L: ";
            cin >> lEndP;
            cout << endl;
            
            cout << "Enter endpoint R: ";
            cin >> rEndP;
            cout << endl;
            
            //cout << intVector.size();
            print_list(intVector, lEndP, rEndP);
            Marjory(intVector, lEndP, rEndP);
            
        }
        
        else if(type == 'd' || type == 'D')
        {
            double hold = 0;
            
            cout << "Enter as many doubles, then hit enter, then ctrl-d: ";
            while(cin >> hold)
            {
                
                if(cin.eof())
                {
                    cin.clear();
                    cin.sync();
                    break;
                }
                doubleVector.push_back(hold);
                //cout << doubleVector.size() << endl;
            }
            cin.clear();
            cin.sync();
            cout << endl;
            
            cout << "Enter endpoint L: ";
            cin >> lEndP;
            cout << endl;
            
            cout << "Enter endpoint R: ";
            cin >> rEndP;
            cout << endl;
            
            print_list(doubleVector, lEndP, rEndP);
            Marjory(doubleVector, lEndP, rEndP);
            
        }
        
        else if(type == 'f' || type == 'F')
        {
            int foo = 0;
            int foo2 = 0;
            int hold = 0;
            
            Fraction hold_frac(0, 1);
            
            cout << "Enter as many ints, then hit enter, then ctrl-d: ";
            
            while(cin >> hold)
            {
                foo = hold;
                cin >> hold;
                
                if(cin.eof())
                {
                    cout << "Error!";
                    return 1;
                }
                hold_frac.ChangeFraction(foo, hold);
                fractionVector.push_back(hold_frac);
            }
            cin.clear();
            cin.sync();
            
            cout << endl;
            
            cout << "Enter endpoint L: ";
            cin >> lEndP;
            cout << endl;
            
            cout << "Enter endpoint R: ";
            cin >> rEndP;
            cout << endl;
            
            
            
            print_list(fractionVector, lEndP, rEndP);
            Marjory(fractionVector, lEndP, rEndP);
        
        }
        
    }    

}
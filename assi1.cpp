

#include <iostream>
#include <string>
using namespace std ;

struct stud
{   
    int roll;
    string name;
    float sgpa;
};

class students
{   
    public :
    int n;
    stud Array[100] ;

    void input() ;
    void bubblesort() ;
    void insertionsort() ; 
    int binary() ;
    float partition(int low , int high );
    float binarysgpa( float target );
    void show( );

};

void students :: input ( )
{ 
    for( int i = 0 ; i < n ; i++ )
  {  
     cout << " enter name of student " << endl;
     cin  >> Array[i].name ;
     cout << " enter student roll number  " << endl;
     cin  >> Array[i].roll ;
     cout << " enter students sgpa " << endl;
     cin  >> Array[i].sgpa ;
  }

} 

void students ::  bubblesort ( ) 
{
  stud temp;
  // Sorting students based on roll number (Bubble Sort)
  for (int i = 0; i < n - 1; i++)
  {
     for (int j = 0; j < n - i - 1; j++)
     {
         if (Array[j].roll > Array[j + 1].roll)
         {
             // Swap the student objects
             temp = Array[j];
             Array[j] = Array[j + 1];
             Array[j + 1] = temp;
         }
     }
    }

}

void students :: insertionsort ( )
{
  stud key ;
   int j ;

   for ( int i = 1 ; i < n ; i++ )
    
    {
       key = Array[i] ;
       j = i - 1 ;

       while ( j >= 0 && Array[j].name > key.name )
       {
          Array[j+1] = Array[j] ; 
          j-- ;
       }
       Array[j+1] = key ;
    }
    
}

int students :: binary ( )
{   
    string target ;
    cout << " enter the name you want target  " << endl;
    cin  >> target;

    int low = 0 ;
    int high = n - 1;
    
    while( low <= high)
    {
       int mid = (low + high) / 2 ;    //    cout << " mid of index of an Array " << mid << endl;

       if (Array[mid].name == target)
       {
          cout << " name is found  "  << target << " having index is " << mid << endl;
          cout << endl;
          cout << " name of student " << Array[mid].name << endl;
          cout << " roll of student " << Array[mid].roll << endl;
          cout << " sgpa of student " << Array[mid].sgpa << endl;
          return mid;
       }
          
        else if ( Array[mid].name < target )
        { 
            low = mid + 1 ;
        }
            else 
            {
                high = mid - 1 ;
            }

    }
        if ( low > high )
            {
                cout << " element is not found " << endl;
                return -1 ; 
            }

}

   float students :: partition (int low, int high)
{
      int partitionBySGPA(stud Array[], int low, int high);
      {
          float pivot = Array[high].sgpa;
          int low = 0;
          int i = low - 1;
          for (int j = low; j < high; j++)
          {
            if (Array[j].sgpa > pivot)
            {
                i++;
                swap(Array[i], Array[j]);
            }
        }
        swap(Array[i + 1], Array[high]);
        return i + 1;
    }

    if (low < high)
    {
        int pivotIndex = partitionBySGPA(Array, low, high);
        partition(low, pivotIndex - 1);
        partition(pivotIndex + 1, high);
    }
}

float students :: binarysgpa ( float target )
{   
    cout << " enter the sgpa you want target " << endl;
    cin >> target;

    int i;
    for (int i = 0; i < n; i++)
    {
        if (Array[i].sgpa == target)
          {
            cout << " sgpa of student you want  " << target << " having index is " << i << endl;
            cout << endl;
            cout << " name of student " << Array[i].name << endl;
            cout << " roll of student " << Array[i].roll << endl;
            cout << " sgpa of student " << Array[i].sgpa << endl;
            cout << endl;
        }

         if (Array[i].sgpa != target)
        {
            cout << " this are the student having sgpa " << target << endl;
            cout << endl;
        }
    }
}
void students :: show ()  
{    
     int mid , target ;

      for (int i = 0; i < n; i++)
      {
          cout << "  name               " << Array[i].name << "  " << endl;
          cout << "  roll no            " << Array[i].roll << "  " << endl;
          cout << "  sgpa               " << Array[i].sgpa << "  " << endl;
      }
}
int main()

{
    students s1;

    cout << " enter number of student " << endl;
    cin >> s1.n;

    s1.input();                // Input student details.

    int choice;
    cout << " enter your choice as you want  1 : bubblesort roll and 2 : insertion sort name " << endl;
    cout << " enter your choice as you want  3 : binary name and 4 : partition sgpa  5 : binary same sgpa " << endl;
    cout << endl;
    cin >> choice ;

while ( choice != 0 )
{
    switch (choice)
{
    case 1:

          s1.bubblesort(); // bubblesort of student details.
          s1.show();       // Display sorted student details.
          break;
          
    case 2:

          s1.insertionsort(); // insertionsort of student details.
          s1.show();          // Display sorted student details.
          break;

    case 3:

          s1.binary();
          break;

    case 4:

          s1.partition(0, s1.n - 1); // quicksort of student details.
          s1.show();                 // Display sorted student details.
          break;

        case 5:

          float target;
          s1.binarysgpa(target);
          break;

        default :

           cout << " wrong choice " << endl;
           cout << endl;

           cout << " ---------------------------------------------------------- " << endl;

}
        cout << endl;

        cout << " next iteration start " << endl;
        cout << " do you want try another choice : " << endl;
        cout << " press 0 to exit " << endl;
        cout << endl;

        cout << " enter your choice " << endl;
    cout << " 1 : bubblesort - roll and 2 : insertion sort - name          " << endl;
    cout << " 3 : binary - name and 4 : quick sort - sgpa  5 : binary - sgpa " << endl;
        cin >> choice;

}  
          return 0 ;
}




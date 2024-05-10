#include <iostream>
#include <string>
using namespace std;

struct stud
{
    int roll;
    string name;
    float sgpa;
};

class students
{
public:
    int n;
    stud Array[100];

    void input();
    void bubblesort();
    void insertionsort();
    int binary();
    void partition(int low, int high);
    void binarysgpa(float target);
    void show();
};

void students::input()
{
    for (int i = 0; i < n; i++)
    {
        cout << "enter name of student" << endl;
        cin >> Array[i].name;
        cout << "enter student roll number" << endl;
        cin >> Array[i].roll;
        cout << "enter student's sgpa" << endl;
        cin >> Array[i].sgpa;
    }
}

void students::bubblesort()
{
    stud temp;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (Array[j].roll > Array[j + 1].roll)
            {
                temp = Array[j];
                Array[j] = Array[j + 1];
                Array[j + 1] = temp;
            }
        }
    }
}

void students::insertionsort()
{
    stud key;
    int j;

    for (int i = 1; i < n; i++)
    {
        key = Array[i];
        j = i - 1;

        while (j >= 0 && Array[j].name > key.name)
        {
            Array[j + 1] = Array[j];
            j--;
        }
        Array[j + 1] = key;
    }
}

int students::binary()
{
    string target;
    cout << "enter the name you want to search for" << endl;
    cin >> target;

    int low = 0;
    int high = n - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (Array[mid].name == target)
        {
            cout << "Name found: " << target << " at index: " << mid << endl;
            cout << "Name: " << Array[mid].name << ", Roll: " << Array[mid].roll << ", SGPA: " << Array[mid].sgpa << endl;
            return mid;
        }
        else if (Array[mid].name < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    cout << "Element not found" << endl;
    return -1;
}

void students::partition(int low, int high)
{
    float pivot = Array[high].sgpa;
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
    i++;
}

void students::binarysgpa(float target)
{
    cout << "Enter the SGPA you want to search for: ";
    cin >> target;

    bool found = false;
    for (int i = 0; i < n; i++)
    {
        if (Array[i].sgpa == target)
        {
            found = true;
            cout << "SGPA found: " << target << " at index: " << i << endl;
            cout << "Name: " << Array[i].name << ", Roll: " << Array[i].roll << ", SGPA: " << Array[i].sgpa << endl;
        }
    }

    if (!found)
    {
        cout << "No student found with SGPA: " << target << endl;
    }
}

void students::show()
{
    for (int i = 0; i < n; i++)
    {
        cout << "Name: " << Array[i].name << ", Roll: " << Array[i].roll << ", SGPA: " << Array[i].sgpa << endl;
    }
}

int main()
{
    students s1;

    cout << "Enter the number of students: ";
    cin >> s1.n;

    s1.input();

    int choice;
    cout << "Enter your choice: " << endl;
    cout << "1: Bubble Sort (based on roll)" << endl;
    cout << "2: Insertion Sort (based on name)" << endl;
    cout << "3: Binary Search (based on name)" << endl;
    cout << "4: Partition (based on SGPA)" << endl;
    cout << "5: Binary Search for SGPA" << endl;
    cout << "0: Exit" << endl;

    while (true)
    {
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            s1.bubblesort();
            s1.show();
            break;
        case 2:
            s1.insertionsort();
            s1.show();
            break;
        case 3:
            s1.binary();
            break;
        case 4:
            s1.partition(0, s1.n - 1);
            s1.show();
            break;
        case 5:
            float target;
            s1.binarysgpa(target);
            break;
        case 0:
            cout << "Exiting program." << endl;
            return 0;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}


#include <iostream>
#include <stdlib.h>
using namespace std;

int main()
{
  /* =====================================================
                            Lab Task 1
                         Find Sum of X^2
     ===================================================== */

    cout << "========== Lab Task 1 ==========" << endl;

    int sum = 0;
    int start;
    int stop;

    cout << "Enter Starting Value: ";
    cin >> start;

    cout << "Enter Stopping Value: ";
    cin >> stop;

    for (int i = start; i <= stop; i++)
    {
        sum += i * i;
    }
    cout << "The sum of X^2 is: " << sum << endl;


    /* =====================================================
                         Lab Task 2
                         Array List
       =====================================================*/

    int arr[20] = {10, 20, 30, 40};
    int size = 4;

    int choice;
    int value;
    int target;
    bool found;

    do
    {
        cout << "\n\n========== Lab Task 2 ==========" << endl;
        cout << "1. Insert value at end" << endl;
        cout << "2. Insert value at start" << endl;
        cout << "3. Insert value after specific value" << endl;
        cout << "4. Insert value before specific value" << endl;
        cout << "5. Display array list" << endl;
        cout << "6. Delete value from end" << endl;
        cout << "7. Delete value from start" << endl;
        cout << "8. Delete specific value" << endl;
        cout << "9. Go to Lab Task 3" << endl;

        cout << "\nEnter your choice: ";
        cin >> choice;


        /* =================================================
                     1. Insert value at end
         =================================================*/

        if (choice == 1)
        {
            cout << "Enter value to insert: ";
            cin >> value;

            arr[size] = value;
            size++;

            cout << "Value inserted at end." << endl;
        }


        /* =================================================
                     2. Insert value at start
         =================================================*/

        else if (choice == 2)
        {
            cout << "Enter value to insert: ";
            cin >> value;

            for (int i = size; i > 0; i--)
            {
                arr[i] = arr[i - 1];
            }
            arr[0] = value;
            size++;

            cout << "Value inserted at start." << endl;
        }


        /* =================================================
                3. Insert value after specific value
         =================================================*/

        else if (choice == 3)
        {
            cout << "Enter specific target value: ";
            cin >> target;

            cout << "Enter value to insert: ";
            cin >> value;

            found = false;

            for (int i = 0; i < size; i++)
            {
                if (arr[i] == target)
                {
                    for (int j = size; j > i + 1; j--)
                    {
                        arr[j] = arr[j - 1];
                    }
                    arr[i + 1] = value;
                    size++;

                    found = true;
                    break;
                }
            }
            if (found)
                cout << "Value inserted after target." << endl;
            else
                cout << "Target value not found." << endl;
        }


        /* =================================================
                4. Insert value before specific value
         =================================================*/

        else if (choice == 4)
        {
            cout << "Enter specific target value: ";
            cin >> target;

            cout << "Enter value to insert: ";
            cin >> value;

            found = false;

            for (int i = 0; i < size; i++)
            {
                if (arr[i] == target)
                {
                    for (int j = size; j > i; j--)
                    {
                        arr[j] = arr[j - 1];
                    }
                    arr[i] = value;
                    size++;

                    found = true;
                    break;
                }
            }
            if (found)
                cout << "Value inserted before target." << endl;
            else
                cout << "Target value not found." << endl;
        }


        /* =================================================
                 5. Display array list
           =================================================*/

        else if (choice == 5)
        {
            cout << "Array: ";

            for (int i = 0; i < size; i++)
            {
                cout << arr[i]<< " ";
            }
            cout << endl;
        }


        /* =================================================
                6. Delete value from end
           =================================================*/

        else if (choice == 6)
        {
            if (size > 0)
            {
                size--;

                cout << "Value deleted from end." << endl;
            }
            else
            {
                cout << "Array is empty." << endl;
            }
        }


        /* =================================================
                    7. Delete value from start
           =================================================*/

        else if (choice == 7)
        {
            if (size > 0)
            {
                for (int i = 0; i < size - 1; i++)
                {
                    arr[i] = arr[i + 1];
                }

                size--;

                cout << "Value deleted from start." << endl;
            }
            else
            {
                cout << "Array is empty." << endl;
            }
        }


        /* =================================================
                    8. Delete specific value
          =================================================*/

        else if (choice == 8)
        {
            cout << "Enter value to delete: ";
            cin >> target;

            found = false;

            for (int i = 0; i < size; i++)
            {
                if (arr[i] == target)
                {
                    for (int j = i; j < size - 1; j++)
                    {
                        arr[j] = arr[j + 1];
                    }

                    size--;

                    found = true;
                    break;
                }
            }

            if (found)
                cout << "Value deleted successfully." << endl;
            else
                cout << "Value not found." << endl;
        }


        /*=================================================
                         9. Lab Task 3
                 Linear Search using while loop
          =================================================*/

        else if (choice == 9)
        {
            int searchValue;
            int i = 0;
            bool searchFound = false;

            cout << "\n\n========== Lab Task 3 ==========" << endl;
            cout << "Linear Search using While Loop" << endl;

            cout << "Enter value to search: ";
            cin >> searchValue;

            while (i < size)
            {
                if (arr[i] == searchValue)
                {
                    searchFound = true;
                    break;
                }

                i++;
            }

            if (searchFound)
            {
                cout << "Value found at index: " << i << endl;
            }
            else
            {
                cout << "Value not found in the array." << endl;
            }
        }

        else
        {
            cout << "Invalid choice." << endl;
        }

    } while (choice != 9);


    system("pause");

    return 0;
}

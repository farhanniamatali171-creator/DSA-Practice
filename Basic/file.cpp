#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <limits>
using namespace std;

const int TOTAL_RECORDS = 100;
const char FILE_NAME[] = "hardware.dat";

struct Tool
{
    int recordNo;
    char toolName[30];
    int quantity;
    double cost;
};

void initializeFile()
{
    fstream file(FILE_NAME, ios::out | ios::binary | ios::trunc);

    if (!file)
    {
        cout << "Error: Could not create the file!\n";
        return;
    }

    Tool emptyTool{};
    emptyTool.recordNo = 0;
    emptyTool.toolName[0] = '\0';
    emptyTool.quantity = 0;
    emptyTool.cost = 0.0;

    for (int i = 0; i < TOTAL_RECORDS; i++)
        file.write(reinterpret_cast<char*>(&emptyTool), sizeof(Tool));

    file.close();
}
void addTool()
{
    Tool tool;
    int recordNo;

    cout << "\nEnter record number (1-100): ";
    cin >> recordNo;

    if (recordNo < 1 || recordNo > TOTAL_RECORDS)
    {
        cout << "Invalid record number.\n";
        return;
    }

    cout << "Enter tool name: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.getline(tool.toolName, 30);

    cout << "Enter quantity: ";
    cin >> tool.quantity;

    cout << "Enter cost: ";
    cin >> tool.cost;

    tool.recordNo = recordNo;

    fstream file(FILE_NAME, ios::in | ios::out | ios::binary);

    if (!file)
    {
        cout << "Error: Could not open the file!\n";
        return;
    }

    file.seekp((recordNo - 1) * sizeof(Tool), ios::beg);
    file.write(reinterpret_cast<char*>(&tool), sizeof(Tool));

    file.close();

    cout << "Tool added successfully!\n";
}

void listTools()
{
    ifstream file(FILE_NAME, ios::binary);

    if (!file)
    {
        cout << "Error: Could not open the file!\n";
        return;
    }

    Tool tool;
    bool found = false;

    cout << "\n"
         << left << setw(12) << "Record #"
         << setw(30) << "Tool name"
         << setw(12) << "Quantity"
         << setw(10) << "Cost" << '\n';

    cout << string(64, '-') << '\n';

    while (file.read(reinterpret_cast<char*>(&tool), sizeof(Tool)))
    {
        if (tool.recordNo != 0)
        {
            found = true;

            cout << left << setw(12) << tool.recordNo
                 << setw(30) << tool.toolName
                 << setw(12) << tool.quantity
                 << fixed << setprecision(2) << tool.cost << '\n';
        }
    }

    if (!found)
        cout << "No tools found!\n";

    file.close();
}

void deleteTool()
{
    int recordNo;

    cout << "\nEnter record number to delete (1-100): ";
    cin >> recordNo;

    if (recordNo < 1 || recordNo > TOTAL_RECORDS)
    {
        cout << "Invalid record number!\n";
        return;
    }

    fstream file(FILE_NAME, ios::in | ios::out | ios::binary);

    if (!file)
    {
        cout << "Error: Could not open the file!\n";
        return;
    }

    Tool tool;

    file.seekg((recordNo - 1) * sizeof(Tool), ios::beg);
    file.read(reinterpret_cast<char*>(&tool), sizeof(Tool));

    if (!file || tool.recordNo == 0)
    {
        cout << "No tool exists at this record number!\n";
        file.close();
        return;
    }

    Tool emptyTool{};
    emptyTool.recordNo = 0;
    emptyTool.toolName[0] = '\0';
    emptyTool.quantity = 0;
    emptyTool.cost = 0.0;

    file.seekp((recordNo - 1) * sizeof(Tool), ios::beg);
    file.write(reinterpret_cast<char*>(&emptyTool), sizeof(Tool));

    file.close();

    cout << "Tool deleted successfully!\n";
}

void updateTool()
{
    int recordNo;

    cout << "\nEnter record number to update (1-100): ";
    cin >> recordNo;

    if (recordNo < 1 || recordNo > TOTAL_RECORDS)
    {
        cout << "Invalid record number!\n";
        return;
    }

    fstream file(FILE_NAME, ios::in | ios::out | ios::binary);

    if (!file)
    {
        cout << "Error: Could not open the file!\n";
        return;
    }

    Tool tool;

    file.seekg((recordNo - 1) * sizeof(Tool), ios::beg);
    file.read(reinterpret_cast<char*>(&tool), sizeof(Tool));

    if (!file || tool.recordNo == 0)
    {
        cout << "No tool exists at this record number!\n";
        file.close();
        return;
    }

    cout << "\nCurrent information:\n";
    cout << "Tool name: " << tool.toolName << '\n';
    cout << "Quantity: " << tool.quantity << '\n';
    cout << "Cost: " << fixed << setprecision(2) << tool.cost << '\n';

    cout << "\nEnter new tool name: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.getline(tool.toolName, 30);

    cout << "Enter new quantity: ";
    cin >> tool.quantity;

    cout << "Enter new cost: ";
    cin >> tool.cost;

    file.seekp((recordNo - 1) * sizeof(Tool), ios::beg);
    file.write(reinterpret_cast<char*>(&tool), sizeof(Tool));

    file.close();

    cout << "Tool updated successfully!\n";
}

int main()
{
    
    initializeFile();

    int choice;

    do
    {
        cout << "\n========== HARDWARE INVENTORY ==========\n";
        cout << "1. Add tool\n";
        cout << "2. List all tools\n";
        cout << "3. Delete a tool\n";
        cout << "4. Update a tool\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            addTool();
            break;

        case 2:
            listTools();
            break;

        case 3:
            deleteTool();
            break;

        case 4:
            updateTool();
            break;

        case 5:
            cout << "Program ended\n";
            break;

        default:
            cout << "Invalid choice! Please try again.\n";
        }

    } while (choice != 5);

    return 0;
}

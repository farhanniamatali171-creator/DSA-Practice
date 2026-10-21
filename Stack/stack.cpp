#include <iostream>
#include <string>
#include <vector>

// ==================================================
// ACTIVITY 1: ARRAY STACK
// ==================================================

class ArrayStack
{
private:
    char* values;
    int tos;
    int capacity;

public:
    ArrayStack(int size){
        capacity = size;
        tos = -1;
        values = new char[capacity];
    }

    ~ArrayStack(){
        delete[] values;
    }

    bool isEmpty(){
        return tos == -1;
    }

    bool isFull(){
        return tos == capacity - 1;
    }

    void push(char value){
        if (isFull())
            std::cout << "Stack Overflow\n";
        else
            values[++tos] = value;
    }

    char pop(){
        if (isEmpty()){
            std::cout << "Stack Underflow\n";
            return '\0';
        }
        return values[tos--];
    }

    char top(){
        if (isEmpty())
            return '\0';

        return values[tos];
    }
};

// ==================================================
// ACTIVITY 2: DYNAMIC STACK USING LINKED LIST
// ==================================================

struct Node{
    char data;
    Node* link;
};

class LinkedStack{
private:
    Node* head;

public:
    LinkedStack(){
        head = nullptr;
    }

    ~LinkedStack(){
        while (head != nullptr)
        {
            Node* temp = head;
            head = head->link;
            delete temp;
        }
    }

    bool isEmpty(){
        return head == nullptr;
    }

    void push(char value){
        Node* temp = new Node;
        temp->data = value;
        temp->link = head;
        head = temp;
    }

    char pop(){
        if (isEmpty())
            return '\0';

        Node* temp = head;
        char value = temp->data;
        head = head->link;
        delete temp;

        return value;
    }

    char top(){
        if (isEmpty())
            return '\0';

        return head->data;
    }
};

// ==================================================
// DYNAMIC STACK FOR NUMERICAL VALUES
// ==================================================

struct NumberNode{
    double data;
    NumberNode* link;
};

class NumberStack{
private:
    NumberNode* head;

public:
    NumberStack(){
        head = nullptr;
    }

    ~NumberStack(){
        while (head != nullptr)
        {
            NumberNode* temp = head;
            head = head->link;
            delete temp;
        }
    }

    bool isEmpty(){
        return head == nullptr;
    }

    void push(double value){
        NumberNode* temp = new NumberNode;
        temp->data = value;
        temp->link = head;
        head = temp;
    }

    double pop(){
        if (isEmpty())
            return 0;

        NumberNode* temp = head;
        double value = temp->data;
        head = head->link;
        delete temp;

        return value;
    }
};

// ==================================================
// MAIN: ALL ACTIVITIES AND GRADED LAB TASKS
// ==================================================


int main(){
    int choice;

    std::cout << "\n========== STACK LAB ==========\n";
    std::cout << "1. Activity 1 - Array Stack\n";
    std::cout << "2. Activity 2 - Dynamic Stack\n";
    std::cout << "3. Activity 3 - Reverse a String\n";
    std::cout << "4. Activity 4 - Balanced Expression\n";
    std::cout << "5. Graded Task 1 - Balanced Brackets\n";
    std::cout << "6. Graded Task 2 - Infix to Postfix\n";
    std::cout << "7. Graded Task 3 - Evaluate Postfix\n";
    std::cout << "Enter choice: ";

    std::cin >> choice;
    std::cin.ignore(10000, '\n');

    switch (choice){
        case 1:
        {
            ArrayStack s(10);

            s.push('B');
            s.push('S');
            s.push('S');
            s.push('E');
            s.push('3');
            s.push('Z');

            std::cout << "Popping elements: ";

            while (!s.isEmpty())
                std::cout << s.pop();

            std::cout << "\n";
            break;
        }

        case 2:
        {
            LinkedStack s;

            s.push('H');
            s.push('e');
            s.push('l');
            s.push('l');
            s.push('o');

            std::cout << "Popping elements: ";

            while (!s.isEmpty())
                std::cout << s.pop();

            std::cout << "\n";
            break;
        }

        case 3:
        {
            std::string text;

            std::cout << "Enter a string: ";
            std::getline(std::cin, text);

            ArrayStack s(static_cast<int>(text.length()) + 1);

            for (int i = 0; i < static_cast<int>(text.length()); i++)
                s.push(text[i]);

            std::cout << "Reversed string: ";

            while (!s.isEmpty())
                std::cout << s.pop();

            std::cout << "\n";
            break;
        }

        case 4:
        case 5:
        {
            std::string expression;

            std::cout << "Enter expression: ";
            std::getline(std::cin, expression);

            LinkedStack s;
            bool balanced = true;

            for (int i = 0; i < static_cast<int>(expression.length()); i++)
            {
                char ch = expression[i];

                if (ch == '(' || ch == '[' || ch == '{')
                {
                    s.push(ch);
                }
                else if (ch == ')' || ch == ']' || ch == '}')
                {
                    if (s.isEmpty())
                    {
                        balanced = false;
                        break;
                    }

                    char opening = s.pop();

                    if ((ch == ')' && opening != '(') ||
                        (ch == ']' && opening != '[') ||
                        (ch == '}' && opening != '{'))
                    {
                        balanced = false;
                        break;
                    }
                }
            }

            if (!s.isEmpty())
                balanced = false;

            if (balanced)
                std::cout << "Balanced\n";
            else
                std::cout << "Not Balanced\n";

            break;
        }

        case 6:
        {
            std::string infix;
            std::string postfix;
            LinkedStack operators;

            std::cout << "Enter infix expression: ";
            std::getline(std::cin, infix);

            bool valid = true;

            for (int i = 0; i < static_cast<int>(infix.length()) && valid; i++)
            {
                char ch = infix[i];

                if (ch == ' ' || ch == '\t')
                    continue;

                if ((ch >= 'A' && ch <= 'Z') ||
                    (ch >= 'a' && ch <= 'z') ||
                    (ch >= '0' && ch <= '9'))
                {
                    postfix += ch;
                }
                else if (ch == '(')
                {
                    operators.push(ch);
                }
                else if (ch == ')')
                {
                    while (!operators.isEmpty() && operators.top() != '(')
                        postfix += operators.pop();

                    if (operators.isEmpty())
                    {
                        valid = false;
                        break;
                    }

                    operators.pop();
                }
                else if (ch == '+' || ch == '-' ||
                         ch == '*' || ch == '/' || ch == '^')
                {
                    int priority = 0;

                    if (ch == '+' || ch == '-')
                        priority = 1;

                    if (ch == '*' || ch == '/')
                        priority = 2;

                    if (ch == '^')
                        priority = 3;

                    while (!operators.isEmpty() && operators.top() != '(')
                    {
                        char op = operators.top();
                        int topPriority = 0;

                        if (op == '+' || op == '-')
                            topPriority = 1;

                        if (op == '*' || op == '/')
                            topPriority = 2;

                        if (op == '^')
                            topPriority = 3;

                        if (topPriority > priority ||
                            (topPriority == priority && ch != '^'))
                        {
                            postfix += operators.pop();
                        }
                        else
                        {
                            break;
                        }
                    }

                    operators.push(ch);
                }
                else
                {
                    valid = false;
                }
            }

            while (valid && !operators.isEmpty())
            {
                char op = operators.pop();

                if (op == '(')
                {
                    valid = false;
                    break;
                }

                postfix += op;
            }

            if (valid)
                std::cout << "Postfix expression: " << postfix << "\n";
            else
                std::cout << "Invalid infix expression\n";

            break;
        }

        case 7:
        {
            std::string postfix;
            NumberStack values;

            std::vector<char> variableNames;
            std::vector<double> variableValues;

            std::cout << "Enter postfix expression: ";
            std::getline(std::cin, postfix);

            bool valid = true;
            bool hasSpaces = false;

            for (int i = 0; i < static_cast<int>(postfix.length()); i++)
            {
                if (postfix[i] == ' ' || postfix[i] == '\t')
                    hasSpaces = true;
            }

            int i = 0;

            while (i < static_cast<int>(postfix.length()) && valid)
            {
                char ch = postfix[i];

                if (ch == ' ' || ch == '\t')
                {
                    i++;
                    continue;
                }

                if (ch >= '0' && ch <= '9')
                {
                    double number = 0;

                    if (hasSpaces)
                    {
                        while (i < static_cast<int>(postfix.length()) &&
                               postfix[i] >= '0' && postfix[i] <= '9')
                        {
                            number = number * 10 + (postfix[i] - '0');
                            i++;
                        }
                    }
                    else
                    {
                        number = ch - '0';
                        i++;
                    }

                    values.push(number);
                    continue;
                }

                if ((ch >= 'A' && ch <= 'Z') ||
                    (ch >= 'a' && ch <= 'z'))
                {
                    int index = -1;

                    for (int k = 0; k < static_cast<int>(variableNames.size()); k++)
                    {
                        if (variableNames[k] == ch)
                        {
                            index = k;
                            break;
                        }
                    }

                    if (index == -1)
                    {
                        double value;

                        std::cout << "Enter value of " << ch << ": ";
                        std::cin >> value;

                        variableNames.push_back(ch);
                        variableValues.push_back(value);

                        values.push(value);
                    }
                    else
                    {
                        values.push(variableValues[index]);
                    }

                    i++;
                    continue;
                }

                if (ch == '+' || ch == '-' ||
                    ch == '*' || ch == '/' || ch == '^')
                {
                    if (values.isEmpty())
                    {
                        valid = false;
                        break;
                    }

                    double right = values.pop();

                    if (values.isEmpty())
                    {
                        valid = false;
                        break;
                    }

                    double left = values.pop();
                    double result = 0;

                    if (ch == '+')
                        result = left + right;

                    if (ch == '-')
                        result = left - right;

                    if (ch == '*')
                        result = left * right;

                    if (ch == '/')
                    {
                        if (right == 0)
                        {
                            std::cout << "Error: Division by zero\n";
                            valid = false;
                            break;
                        }

                        result = left / right;
                    }

                    if (ch == '^')
                    {
                        result = 1;

                        if (right >= 0 && right == static_cast<int>(right))
                        {
                            for (int j = 0; j < static_cast<int>(right); j++)
                                result = result * left;
                        }
                        else
                        {
                            std::cout << "Error: Exponent must be a non-negative integer\n";
                            valid = false;
                            break;
                        }
                    }

                    values.push(result);
                    i++;
                }
                else
                {
                    valid = false;
                }
            }

            if (valid && !values.isEmpty())
            {
                double answer = values.pop();

                if (values.isEmpty())
                    std::cout << "Result: " << answer << "\n";
                else
                    std::cout << "Invalid postfix expression\n";
            }
            else
            {
                std::cout << "Invalid postfix expression\n";
            }

            break;
        }

        case 0:
        {
            std::cout << "Program ended.\n";
            break;
        }

        default:
        {
            std::cout << "Invalid choice\n";
            break;
        }
    }



    
    return 0;
}

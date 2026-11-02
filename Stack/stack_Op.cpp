#include <iostream>
#include <string>
#include <cctype>

const int SIZE = 100;

class Stack {
    char arr[SIZE];
    int top;
public:
    Stack(){ 
        top = -1; 
    }

    void push(char c){
        if (top<SIZE-1)
         arr[++top]=c; 
    }

    char pop(){
        return top==-1 ? '\0' : arr[top--]; 
    }

    char peek(){
         return top == -1 ? '\0' : arr[top]; 
    }
    bool isEmpty(){ 
        return top == -1; 
    }
};

    bool isOpening(char c){
        return c =='(' || c=='{' || c=='[';
    }

    bool isClosing(char c){
        return c==')' || c=='}' || c ==']'; 
    }

    bool isOperator(char c){ return c=='+' || c=='-' || c=='*' || c=='/'; 
    }

    int precedence(char c){
    if(c=='*' || c=='/') 
       return 2;
    if(c=='+' || c=='-') 
      return 1;

    return 0;
}

bool matches(char open, char close){
    return (open=='(' && close==')') || (open=='{' && close=='}') || (open=='[' && close==']');
}

std::string bracketSequence(std::string exp){
    std::string seq = "";
    for(int i=0; i<(int)exp.length(); i++)
        if(isOpening(exp[i]) || isClosing(exp[i]))
            seq+=exp[i];
    return seq;
}

bool balanced(std::string exp){
    Stack s;
    for(int i=0; i<(int)exp.length(); i++){
        char c = exp[i];
        if(isOpening(c))
            s.push(c);
        else if(isClosing(c)){
            if(s.isEmpty() || !matches(s.pop(), c))
                return false;
        }
    }
    return s.isEmpty();
}

bool validExpression(std::string exp){
    bool expectOperand=true;
    int depth=0;

    for(int i=0; i<(int)exp.length(); i++){
        char c=exp[i];
        if (c==' ') 
         continue;
        if(isOpening(c)){
            if (!expectOperand) 
              return false;
            depth++;
        }
        else if(isClosing(c)){
            if (expectOperand || depth==0) 
               return false;
            depth--;
        }
        else if(std::isdigit(c) || std::isalpha(c)){
            if (!expectOperand) 
                return false;
            while (std::isdigit(c) && i+1 < (int)exp.length() && std::isdigit(exp[i+1]))
                i++;
            expectOperand=false;
        }
        else if(isOperator(c)){
            if (expectOperand)
               return false;
            expectOperand=true;
        }
        else
            return false;
    }
    return !expectOperand && depth==0;
}

std::string infixToPostfix(std::string exp){
    Stack s;
    std::string out = "";

    for(int i=0; i<(int)exp.length(); i++){
        char c=exp[i];
        if(c==' ') 
          continue;

        if(std::isdigit(c)){
            while(i < (int)exp.length() && std::isdigit(exp[i]))
                out+=exp[i++];
            out+=' ';
            i--;
        }
        else if(std::isalpha(c)){
            out+=c;
            out+=' ';
        }
        else if(isOpening(c))
            s.push(c);
        
        else if(isClosing(c)){
            while (!s.isEmpty() && !isOpening(s.peek())) {
                out+=s.pop();
                out+=' ';
            }
            s.pop();   
        }
        else{ 
            while(!s.isEmpty() && !isOpening(s.peek()) && precedence(s.peek()) >= precedence(c)){
                out+=s.pop();
                out+=' ';
            }
            s.push(c);
        }
    }

    while(!s.isEmpty()){
        out+=s.pop();
        out+=' ';
    }
    return out;
}

bool evaluate(std::string postfix, double values[26], double &result){
    double arr[SIZE];   
    int top=-1;

    for(int i=0; i < (int)postfix.length(); i++){
        char c=postfix[i];
        if(c==' ') 
          continue;

        if(std::isdigit(c)){
            double num = 0;
            while (i < (int)postfix.length() && std::isdigit(postfix[i]))
                num=num*10+ (postfix[i++]-'0');
            i--;
            arr[++top]=num;
        }
        else if(std::isalpha(c))
            arr[++top]=values[std::tolower(c)-'a'];
        else{
            double b=arr[top--];
            double a=arr[top--];

            if(c == '+')     
              arr[++top] = a + b;
            else if(c=='-')
              arr[++top] = a - b;
            else if(c=='*') 
              arr[++top] = a * b;
            else{
                if(b==0){
                    std::cout<<"Division by zero\n";
                    return false;
                }
                arr[++top] = a/b;
            }
        }
    }
    result=arr[top];
    return true;
}



int main(){


    std::string exp;
    std::cout<<"Enter infix expression: ";
    std::getline(std::cin, exp);

    if ((int)exp.length() >= SIZE) {
        std::cout<<"Expression too long\n";
        return 0;
    }

    bool isBalanced = balanced(exp);
    std::cout<<"It has bracket sequence: " << bracketSequence(exp);
    if(isBalanced)
        std::cout<<" which is balanced\n";
    else{
        std::cout<<" which is not balanced\n";
        return 0;
    }

    if(!validExpression(exp)){
        std::cout<<"Input statement is incorrect\n";
        return 0;
    }

    std::string postfix = infixToPostfix(exp);
    std::cout<<"Postfix: " << postfix << '\n';
    double values[26]={0};
    bool asked[26]={false};

    for(int i=0; i<(int)exp.length(); i++){
        if (!std::isalpha(exp[i])) 
          continue;

        int idx=std::tolower(exp[i])-'a';
        if (asked[idx])
         continue;
        asked[idx]=true;

        std::cout<<"Enter value of " << (char)std::tolower(exp[i])<<": ";
        if (!(std::cin>>values[idx])){
            std::cout<<"Invalid value\n";
            return 0;
        }
    }

    double result;
    if (evaluate(postfix, values, result))
        std::cout<<"Result: "<<result<<'\n';



    return 0;
}

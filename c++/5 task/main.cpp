#include <iostream>
#include <utility>
template <class T>
T binPow(T a, uint32_t n) {
    T res = 1;
    while (n != 0 ) {
        if (n % 2 == 1)
            res *= a;
        a *= a;
        n /= 2;
    }
    return res;
}

class StackExceptions {
public:
    explicit StackExceptions(std::string message) : message{std::move(message)} {}

    [[nodiscard]] std::string getMassage() const { return message; }

private:
    std::string message;
};

class Stack {
    int top;
    int MAX;
    int *a;
public:
    Stack(int size) {
        MAX = size;
        a = new int[MAX];
        top = -1;
    } // Maximum size of Stack

    void push(int x);

    int pop();

    int peek();

    bool isEmpty() const;
};

void Stack::push(int x) {

        if (top >= (MAX - 1)) {
            throw StackExceptions{"Stack Overflow"};
        }
        a[++top] = x;
        std::cout << x << " pushed into stack\n";

}


int Stack::pop() {

        if (top < 0) {
            throw StackExceptions{"Stack Underflow"};
        }
        int x = a[top--];
        return x;
}

int Stack::peek() {
    if (top < 0) {
        std::cout << "Stack is Empty";
        return 0;
    } else {
        int x = a[top];
        return x;
    }
}

bool Stack::isEmpty() const {
    return (top < 0);
}

// Driver program to test above functions
int main() {
    int a, n;
    float b;
    std::cin >> a >> b >> n;
    std::cout << binPow(a, n) << std::endl << binPow(b, n);
    try {
        class Stack s(3);
        s.push(10);
        s.push(20);
        s.push(30);
        s.push(40);
        std::cout << s.pop() << " Popped from stack\n";
        std::cout << s.pop() << " Popped from stack\n";
        std::cout << s.pop() << " Popped from stack\n";
        std::cout << s.pop() << " Popped from stack\n";

        //print top element of stack after popping
        std::cout << "Top element is : " << s.peek() << std::endl;

        //print all elements in stack :
        std::cout << "Elements present in stack : ";
        while (!s.isEmpty()) {
            // print top element in stack
            std::cout << s.peek() << " ";
            // remove top element in stack
            s.pop();
        }

    }
    catch (const StackExceptions ex){
        std::cout << ex.getMassage() << std::endl;
    }
    return 0;
}
#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;
#define SIZE 100

struct Point {
    int x;
    int y;
};

class Queue {
    int *arr;       // массив для хранения элементов queue
    int capacity;   // максимальная емкость queue
    int front;      // front указывает на передний элемент в queue (если есть)
    int rear;       // задняя часть указывает на последний элемент в queue
    int count;      // текущий размер queue

public:
    explicit Queue(int size = SIZE);     // конструктор
    ~Queue();                   // деструктор

    int dequeue();

    void enqueue(int item);

    int peek();

    [[nodiscard]] int size() const;

    [[nodiscard]] bool isEmpty() const;

    [[nodiscard]] bool isFull() const;

    friend Queue &operator<<(Queue &queue, int n);

    friend Queue &operator>>(Queue &queue, int &n);

};

Queue &operator<<(Queue &queue, int n) {
    queue.enqueue(n);
    return queue;
}

Queue &operator>>(Queue &queue, int &n) {
    n = queue.dequeue();
    return queue;
}


// Конструктор для инициализации queue
Queue::Queue(int size) {
    arr = new int[size];
    capacity = size;
    front = 0;
    rear = -1;
    count = 0;
}

// Деструктор для освобождения памяти, выделенной для queue
Queue::~Queue() {
    delete[] arr;
}

// Вспомогательная функция для удаления переднего элемента из очереди
int Queue::dequeue() {
    // проверка на опустошение queue
    if (isEmpty()) {
        cout << "Underflow\nProgram Terminated\n";
        exit(EXIT_FAILURE);
    }

    int x = arr[front];
    cout << "Removing " << x << endl;

    front = (front + 1) % capacity;
    count--;

    return x;
}

// Вспомогательная функция для добавления элемента в queue
void Queue::enqueue(int item) {
    // проверка на переполнение queue
    if (isFull()) {
        cout << "Overflow\nProgram Terminated\n";
        exit(EXIT_FAILURE);
    }

    cout << "Inserting " << item << endl;

    rear = (rear + 1) % capacity;
    arr[rear] = item;
    count++;
}

// Вспомогательная функция для возврата первого элемента queue
int Queue::peek() {
    if (isEmpty()) {
        cout << "Underflow\nProgram Terminated\n";
        exit(EXIT_FAILURE);
    }
    return arr[front];
}

// Вспомогательная функция для возврата размера queue
int Queue::size() const {
    return count;
}

// Вспомогательная функция для проверки, пуста ли queue или нет
bool Queue::isEmpty() const {
    return (size() == 0);
}

// Вспомогательная функция для проверки того, заполнена ли queue или нет
bool Queue::isFull() const {
    return (size() == capacity);
}

class Square {
    Point point;
    int side;
    int a;
    float angle;
public:
    int area();

    int multiplySquare(int n);

    Point movOnVector(Point point1);

    friend bool operator==(Square &square, Square &square1);

    friend bool operator!=(Square &square, Square &square1);

    friend bool operator>(Square &square, Square &square1);

    friend bool operator<(Square &square, Square &square1);
};

bool operator==(Square &square, Square &square1) {
    return square.a == square1.a;
}

bool operator!=(Square &square, Square &square1){
    return !(square==square1);
}

bool operator>(Square &square, Square &square1){
    return square.a > square1.a;
}

bool operator<(Square &square, Square &square1){
    return square.a < square1.a;
}

int Square::area() {
    this->a = pow(this->side, 2);
    return a;
}

int Square::multiplySquare(int n) {
    this->side *= n;
    return this->side;
}


Point Square::movOnVector(Point point1) {
    this->point.x = this->point.x + point1.x;
    this->point.y = this->point.y + point1.y;
    
}


int main() {
    Queue queue;
    int a, b;
    queue << 5 << 7;
    queue >> a >> b;
    cout << a << b;
    queue.peek();
    return 0;
}

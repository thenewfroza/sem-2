#include <iostream>

using std::cin;
using std::cout;

template<typename T>
class CirclularBuffer {
private:
    T* buff;
    int copacity;
    int head;
    int tail = 0;
    int index_pop_back = 0;
    int index_pop_front;

public:

    int size() {
        return copacity;
    }
    class iterator;
    CirclularBuffer(int copacity) {
        this->copacity = copacity;
        index_pop_front = copacity - 1;
        head = copacity - 1;
        buff = new T[copacity];
        for (int i = 0; i < copacity; i++) {
            buff[i] = 0;
        }
    }
    iterator begin() {
        return buff;
    }
    iterator end() {
        return buff + copacity - 1;
    }
    void push_back(int x) {
        if (x != 0) {
            buff[tail] = x;
        }
        else {
            throw 101;
        }
        tail = tail >= (copacity - 1) ? 0 : (tail + 1);
    }
    T& operator[](int i) {
        return i < copacity ? buff[i] : buff[0];
    }
    T pop_back() {
        T tmp = buff[index_pop_back];
        if (buff[index_pop_back] != 0) {
            if (index_pop_back + 1 < copacity) {
                buff[index_pop_back] = 0;
                index_pop_back++;
            }
            else {
                buff[index_pop_back] = 0;
                index_pop_back = 0;
            }
        }
        else {
            index_pop_back = 0;
        }
        return tmp;
    }
    void push_front(int x) {
        if (x != 0) {//вместо создания структуры с входил/не входил, просто запретим x==0 xD
            buff[head] = x;
        }
        else {
            throw 101;
        }
        head = head < 1 ? (copacity - 1) : (head - 1);
    }
    T pop_front() {
        T tmp = buff[index_pop_front];
        if (buff[index_pop_front] != 0) {
            if (index_pop_front - 1 > 0) {
                buff[index_pop_front] = 0;
                index_pop_front--;
            }
            else {
                buff[index_pop_front] = 0;
                index_pop_front = copacity;
            }
        }
        else {
            index_pop_front = copacity - 1;
        }
        return tmp;
    }

    T& operator[](iterator i) {
        return *i;
    }
    template<typename Iter, typename Val>
    Iter insert_random_iterator(Iter it, Val val) {
        int pos = 0;
        for (Iter i = begin(); i != end(); i++) {
            if (i == it) {
                break;
            }
            pos++;
        }
        buff[pos] = val;
        return it;
    }

    template<typename Iter>
    Iter erase_random_iterator(Iter it) {
        int pos = 0;
        for (Iter i = begin(); i != end(); i++) {
            if (i == it) {
                break;
            }
            pos++;
        }
        buff[pos] = 0;
        return it;
    }

    void resize(int n) {
        T* newBuff = new T[n];
        for (int i = 0; i < n; i++) {
            if (i < copacity) {
                newBuff[i] = buff[i];
            }
            else {
                newBuff[i] = 0;
            }
        }
        copacity = n;
        buff = newBuff;
    }

    class iterator : public std::iterator<std::random_access_iterator_tag, T> {
    private:
        T* p;
    public:
        iterator(T* tmp) {
            p = tmp;
        }

        T& operator++(int) {
            return *p++;
        }

        T& operator--(int) {
            return *p--;
        }

        bool operator==(const iterator& other) {
            return this->p == other.p;
        }

        bool operator!=(const iterator& other) {
            return this->p != other.p;
        }

        T& operator*() {
            return *p;
        }
    };


    ~CirclularBuffer() {
        delete[] buff;
    }
};

int main() {
    setlocale(LC_ALL, "ru");
    try {
        CirclularBuffer<int> buffer(4);
        buffer.push_front(12);
        buffer.push_front(13);
        buffer.push_front(17);
        buffer.push_front(199);
        buffer.push_front(201);
        buffer.push_front(1);
        buffer.push_back(1);
        buffer.push_back(4);
        buffer.push_back(5);
        buffer.push_back(6);
        buffer.push_back(10);
        buffer.push_back(11);
        cout << "После push:\n";
        for (int i = 0; i < buffer.size(); i++) {
            std::cout << buffer[i] << " ";
        }
        cout << "\n--------\n";

        cout << "После pop_back:\n";
        buffer.pop_back();
        buffer.pop_back();

        for (int i = 0; i < buffer.size(); i++) {
            std::cout << buffer[i] << " ";
        }
        cout << "\n--------\n";
        cout << "После pop_front:\n";
        buffer.pop_front();
        buffer.pop_front();
        for (int i = 0; i < buffer.size(); i++) {
            std::cout << buffer[i] << " ";
        }
        cout << "\n--------\n";
        int value = 6;
        CirclularBuffer<int>::iterator c = CirclularBuffer<int>::iterator(buffer.begin());
        c++;

        buffer.insert_random_iterator(c, 7);
        c++;
        buffer.insert_random_iterator(c, 100);
        cout << "После insert_random_iterator:\n";
        for (int i = 0; i < buffer.size(); i++) {
            std::cout << buffer[i] << " ";
        }
        cout << "\n--------\n";

        cout << "После erase_random_iterator:\n";
        buffer.erase_random_iterator(c);

        for (int i = 0; i < buffer.size(); i++) {
            std::cout << buffer[i] << " ";
        }
        cout << "\n--------\n";
        CirclularBuffer<int>::iterator a = CirclularBuffer<int>::iterator(buffer.begin());
        CirclularBuffer<int>::iterator b = CirclularBuffer<int>::iterator(buffer.end());
        cout << "Доступ в конец буффера:\n";
        cout << *b;
        cout << "\n--------\n";

        cout << "Доступ в начало буффера:\n";
        cout << *a;
        cout << "\n--------\n";

        cout << "После resize:\n";
        buffer.resize(8);
        for (int i = 0; i < buffer.size(); i++) {
            std::cout << buffer[i] << " ";
        }
        cout << "\n--------\n";

    }
    catch (const int ex) {
        if (ex == 101) {
            cout << "Запрещается пушить в буффер 0";
        }
    }
}




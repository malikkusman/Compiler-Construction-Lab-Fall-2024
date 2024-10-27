#include <iostream>
using namespace std;

class Vector {
private:
    int* arr;
    int capacity;  
    int size;      

    
    void resize() {
        int* temp = new int[2 * capacity]; 
        for (int i = 0; i < size; i++) {
            temp[i] = arr[i];  
        }
        delete[] arr;  
        arr = temp;    
        capacity *= 2;
    }

public:
    
    Vector() {
        arr = new int[2];
        capacity = 2;
        size = 0;
    }

    void insert(int grade) {
        if (size == capacity) {
            resize();  
        }
        arr[size] = grade;
        size++;
    }

    
    void remove(int index) {
        if (index < 0 || index >= size) {
            cout << "Index out of bounds!" << endl;
            return;
        }
        
        for (int i = index; i < size - 1; i++) {
            arr[i] = arr[i + 1];
        }
        size--; 
    }

    
    int get(int index) {
        if (index < 0 || index >= size) {
            cout << "Index out of bounds!" << endl;
            return -1;
        }
        return arr[index];
    }

    void display() {
        if (size == 0) {
            cout << "Vector is empty!" << endl;
            return;
        }
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    // Destructor 
    ~Vector() {
        delete[] arr;
    }
};


int main() {
    Vector grades;

    
    grades.insert(85);
    grades.insert(90);
    grades.insert(75);  
    grades.insert(95);

    cout << "Grades after insertion: ";
    grades.display();

    
    cout << "Grade at index 2: " << grades.get(2) << endl;

    
    grades.remove(1);
    cout << "Grades after deletion: ";
    grades.display();

    return 0;
}

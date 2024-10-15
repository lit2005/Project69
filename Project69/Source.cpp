#include <iostream>  
using namespace std;

class MyString {
private:
    char* data;    
    size_t size;
public:
   
    MyString(const char* str = "") {
        size = 0;
        while (str[size] != '\0') {
            size++;
        }
        data = new char[size + 1];
        for (size_t i = 0; i < size; ++i) {
            data[i] = str[i];
        }
        data[size] = '\0'; 
    }

    
    MyString(const MyString& other) {
        size = other.size;
        data = new char[size + 1];
        for (size_t i = 0; i < size; ++i) {
            data[i] = other.data[i];
        }
        data[size] = '\0';
    }

    
    ~MyString() {
        delete[] data;
    }

   
    MyString& operator=(const MyString& other) {
        if (this != &other) { 
            delete[] data; 
            size = other.size;
            data = new char[size + 1];
            for (size_t i = 0; i < size; ++i) {
                data[i] = other.data[i];
            }
            data[size] = '\0';
        }
        return *this;
    }

    
    const char* getData() const { return data; }
    size_t getSize() const { return size; }

  
    friend ostream& operator<<(ostream& os, const MyString& myString);
 
    friend istream& operator>>(istream& is, MyString& myString);
};

 
ostream& operator<<(ostream& os, const MyString& myString) {
    os << myString.getData();
    return os;
}


istream& operator>>(istream& is, MyString& myString) {
    char buffer[1024];
    is >> buffer;
    myString = MyString(buffer); 
    return is;
}

int main() {
    MyString str1("Hello");
    MyString str2;

   cout << "ѕервоначальна€ строка: " << str1 << endl;

  cout << "¬ведите новую строку: ";
    cin >> str2;

    cout << "¬ведЄнна€ строка: " << str2 << endl;

    return 0;
}
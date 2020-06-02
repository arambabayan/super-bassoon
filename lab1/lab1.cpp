#include <iostream>
#include <string.h>

// typedef unsigned long size_t;

class custom_string {
    char* sp;
    size_t size;
    public:
    custom_string();
    custom_string(const custom_string&);
    custom_string(const char* c);
    ~custom_string();
    void substr(size_t from, size_t length);
    bool remove(size_t from, size_t length);
    const char* get_cstr();
    size_t get_length();
    custom_string operator=(const custom_string&);
    custom_string operator+(const custom_string&);
};

custom_string::custom_string() {
    size = 0;
    sp = nullptr;
}

custom_string::custom_string(const char* c) {
    size = strlen(c);
    sp = new char[size];
    for (int i=0; i<size; ++i) {
        sp[i]=c[i];
    }
}

custom_string::custom_string(const custom_string& str) {
    sp = new char[str.size];
    for(int i=0; i<str.size; ++i) {
        sp[i] = str.sp[i];
    }
    size = str.size;
}

custom_string::~custom_string() {
    delete[] sp;
}

custom_string custom_string::operator=(const custom_string& str) {
    delete[] sp;
    sp = new char[str.size];

    for(int i=0; i < str.size; ++i) {
        sp[i] = str.sp[i];
    }
    size = str.size;

    return *this;
}

custom_string custom_string::operator+(const custom_string& str) {
    size_t str_size = size + str.size;

    char* tmp_str = new char[str_size];

    for(int i=0; i<str_size; ++i) {
        tmp_str[i] = i < size ? sp[i] : str.sp[i-size];
    }

    return custom_string( tmp_str );

}

void custom_string::substr(size_t from, size_t length) {
    if (from+length > this->size)
    {
        return;
    }

    char* tmpString = new char[length];
    
    for (int i=from; i<=from+length; ++i) {
        tmpString[i-from]=sp[i];
    }

    delete[] sp;
    sp = tmpString;

    this->size = length;
}

bool custom_string::remove(size_t from, size_t length) {
    if (from+length > this->size)
    {
        return false;
    }

    char* tmpString = new char[this->size-length];
    
    for (int i=0; i<from; ++i) {
        tmpString[i]=sp[i];
    }
    for (int i=from+length; i<this->size; ++i) {
        tmpString[i-length]=sp[i];
    }

    delete[] sp;
    sp = tmpString;

    this->size = this->size-length;
}

size_t custom_string::get_length() {
    return this->size;
}

const char* custom_string::get_cstr(){

    return this->sp;
}

int main() {

    custom_string str1("usta baryoooooor");
    custom_string str2(",bareev");
    custom_string str3; 
    str3 = str1 + str2;




    // str2.remove(5, 20);

    std::cout<<str3.get_cstr();

    return 0;
}
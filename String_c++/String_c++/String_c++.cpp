#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

class String {
	char* buffer = NULL;
	unsigned int size = 0;
public:
	String() = default;
	String(const char* str) {
		if (str) {
			size = strlen(str);
			buffer = new char[size + 1];
			strcpy(buffer, str);
		}
	}
	String(const String& str) {
		size = str.size;
		buffer = new char[size + 1];
		strcpy(buffer, str.buffer);
	}
	~String() {
		delete[] buffer;
	}
	char& operator[](int index) const {
		if (index < 0 || index >= size)
			exit;
		else
			return buffer[index];
	}
	char& operator[](int index) {
		if (index < 0 || index >= size)
			exit(1);
		else
			return buffer[index];
	}
	void getSize()const {
		cout << size << endl;
	}
	String& operator= (const String& string) {
		if (this == &string)
			return *this;
		if (buffer) delete[]buffer;
		size = string.size;
		buffer = new char[size + 1];
		strcpy(buffer, string.buffer);
		return *this;
	}
	String& operator+=(const char* _char) {
		size += strlen(_char);
		String tmp_buffer = buffer;
		buffer = new char[size + 1];
		strcpy(buffer, tmp_buffer.buffer);
		strcat(buffer, _char);
		return *this;
	}
	String& operator+=(const String& string) {
		String tmp_buffer = buffer;
		size += string.size;
		buffer = new char[size + 1];
		strcpy(buffer, tmp_buffer.buffer);
		strcat(buffer, string.buffer);
		return *this;
	}
	String& operator+=(const char _char) {
		size++;
		String tmp_buffer = buffer;
		buffer = new char[size + 1];
		strcpy(buffer, tmp_buffer.buffer);
		buffer[size - 1] = _char;
		return *this;
	}
	String operator+(const String& string) {
		String tmp_buffer;
		delete[] tmp_buffer.buffer;
		int this_size = size, other_size = string.size;
		int new_size = this_size + other_size;
		tmp_buffer = new char[new_size + 1];
		strcpy(tmp_buffer.buffer, buffer);
		strcpy(tmp_buffer.buffer + this_size, string.buffer);
		return tmp_buffer;
	}
	friend ostream& operator<<(ostream& stream, const String& _str);
};
ostream& operator<<(ostream& stream, const String& _str) {
	if (_str.buffer) stream << _str.buffer << endl;
	else stream << "the string is empty" << endl;
	return stream;
}

int main()
{
	String str_first = "1", str_second = "2";
	str_first = str_second;
	cout << str_first;
	str_first += str_second;
	cout << str_first;
	str_first += "34";
	cout << str_first;
	cout << str_first + str_second;
	return 0;
}
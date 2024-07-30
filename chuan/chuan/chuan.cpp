#include<iostream>
#include<cstring>


using namespace std;

class String {
private:
	char* str;
	size_t length;

public:
	String();
	String(const char* s);
	String(const String& s);
	~String();
	size_t getLength() const;
	char operator[] (size_t index) const;
	String& operator =(const String& s);
	bool operator==(const String & s)const;
	bool operator!=(const String& s)const;
	String copy()const;
	String operator+(const String& s)const;
	friend ostream& operator<<(ostream& out, const String& s);
};


String::String() {
	length = 0;
	str = new char[1];
	str[0] = '\0';
}

String::String(const String& s) {
	length = s.length;
	str = new char[length+1];
	strcpy_s(str, length + 1, s.str); // 使用安全函数


}


String::String(const char* s) {
	length = strlen(s);
	str = new char[length + 1];
	strcpy_s(str, length + 1, s); // 使用安全函数
}


String ::~String() {
	delete[] str;
}


size_t String::getLength() const {
	return length;

}

char String:: operator[](size_t index) const {
	return str[index];
}


String& String ::operator=(const String& s) {
	if (this != &s) {
		delete[] str;
		length = s.length;
		str = new char[length + 1];
		strcpy_s(str, length + 1, s.str); // 使用安全函数	}
		return *this;
	}
}

bool String ::operator==(const String& s)const {
	return strcmp(str, s.str) == 0;

}


bool String ::operator!=(const String& s) const {
	return strcmp(str, s.str) != 0;

}


String String::copy() const {
	String s ( *this);
	return s;
}

String String :: operator+(const String& s) const {
	String result;
	result.length = length + s.length;
	result.str = new char[result.length + 1];
	strcpy_s(result.str, result.length + 1, str); // 使用安全函数
	strcat_s(result.str, result.length + 1, s.str); // 使用安全函数
	return result;
}


ostream& operator<<(ostream& out, const String& s) {
	out << s.str;
	return out;
}
int main() {
	String s("123456d");
	cout << s << endl;
	cout << s + "445" << endl;
	cout << s[5] << endl;
	cout << (s == "123456") << endl;
	cout << (s != "123456") << endl;
	s = s + "ads";
	String a, b, c;
	a = b = c = s;
	cout<<a<<b<<c << s << endl;
	String x = s.copy();
	cout << x << endl;

}
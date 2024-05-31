#ifndef GUARD_Str
#define GUARD_Str

#include <algorithm>
#include <cctype>
#include <iterator>

using namespace std;

class Str {
	// �Է� ������
	friend istream& operator>>(istream&, Str&);
	// getline();
	friend istream& getline(istream&, Str&);
public:
	typedef size_t size_type;
	
	// ��� �ִ� Str ��ü�� ����� �⺻ ������
	Str() : value(0), length(0) { }

	// c�� ���纻 n���� �ִ� Str ��ü�� ����
	Str(size_type n, char c) {
		// �޸� �Ҵ�
		length = n;
		value = new char[length];

		// �迭�� c char�� ä���
		for (size_type i = 0; i != length; ++i) {
			value[i] = c;
		}
	}

	// null�� ������ char Ÿ���� �迭���� Str ��ü�� ����
	Str(const char* cp) {
		// �޸� �Ҵ�
		length = std::strlen(cp);
		value = new char[length];

		std::copy(cp, cp + length, value);
	}

	// �ٸ� Str���� �纻 �����
	Str(const Str& s) {
		// �޸� �Ҵ�
		length = s.length;
		value = new char[length];

		std::copy(s.value, s.value + s.length, value);
	}

	// �Ҹ���
	~Str() {
		if (value != 0)
			delete[] value;
	}

	// �ݺ��� b�� e�� ����Ű�� �������� Str ��ü�� ����
	template<class in> Str(in b, in e) {
		// �޸� �Ҵ�
		length = e - b;
		value = new char[length];
	
		copy(b, e, value);
	}

	// �ε��� ������
	char& operator[](size_type i) { return value[i]; }
	const char& operator[](size_type i) const { return value[i]; }

	size_type size() const { return length; }

	// ���� ������
	Str& operator+=(const Str& s) {
		// �޸� �Ҵ�
		size_type new_length = length + s.length;
		char* new_value = new char[new_length];
		std::copy(value, value + length, new_value);

		// �޸� �����ϱ� ���� ���� value �Ҹ��ϱ�
		if (value != 0)
			delete[] value;

		// ���ο� value�� length ���� �����ϱ�
		std::copy(s.value, s.value + s.length, new_value + new_length); // Ȯ��
		value = new_value;
		length = new_length;
		return *this;
	}

	Str& operator+=(const char c) {
		// �޸� �Ҵ�
		size_type new_length = length + 1;
		char* new_value = new char[new_length];
		std::copy(value, value + length, new_value);

		// �޸� �����ϱ� ���� ���� value �Ҹ��ϱ�
		if (value != 0)
			delete[] value;

		// char�� �߰��ϱ�
		new_value[length] = c;
		value = new_value;
		length = new_length;
		return *this;
	}

	Str& operator+=(const char* c) {
		// �޸� �Ҵ�
		size_type new_length = length + strlen(c);
		char* new_value = new char[new_length];
		std::copy(value, value + length, new_value);

		// �޸� �����ϱ� ���� ���� value �Ҹ��ϱ�
		if (value != 0)
			delete[] value;

		// char�� �߰��ϱ�
		std::copy(c, c + strlen(c), new_value + length);
		value = new_value;
		length = new_length;
		return *this;
	}

	// Q11 (�Ҵ� ������)
	Str& operator=(const Str& rhs) {
		// �ڱ� �ڽ� �Ҵ� Ȯ��
		if (&rhs != this) {
			// �޸� �����ϱ� ���� ���� value �Ҹ��ϱ�
			if (value != 0)
				delete[] value;

			length = rhs.length;
			value = new char[length];
			std:: copy(rhs.begin(), rhs.end(), value);
		}
		return *this;
	}

	// Q7
	typedef char* iterator;
	typedef const char* const_iterator;

	// begin()
	iterator begin() { return value; }
	const_iterator begin() const { return value; }

	// end()
	iterator end() { return value + length; }
	const_iterator end() const { return value + length; }

	// Q2
	const char* c_str() const { return value + '\0'; }
	const char* data() const { return value; }
	void copy(char* p, size_type n) { // copy('=', 10)
		std::copy(value, value + n, p); // ==========
	}

private:
	char* value;
	size_type length;
};

ostream& operator<<(ostream&, const Str&); // �߰�
istream& getline(istream&, const Str&); // Q8


Str operator+(const Str&, const Str&);
Str operator+(const Str&, const char*); // Q5
Str operator+(const char*, const Str&); // Q11

// <, >, <=, >=, ==, != �� ������ �ʿ� 
bool operator<(const Str&, const Str&); // Q3
bool operator>(const Str&, const Str&); // Q3
bool operator<=(const Str&, const Str&); // Q3
bool operator>=(const Str&, const Str&); // Q3
bool operator==(const Str&, const Str&); // Q4
bool operator!=(const Str&, const Str&); // Q4

#endif // !


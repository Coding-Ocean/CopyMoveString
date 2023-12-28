#pragma once
/*
なんちゃってstringクラスを作って、コピーとムーブの意味を知る
*/
#include<cstring>
class STRING {
private:
	char* Str;

	void Create(const char* str) {
		size_t len = strlen(str)+1;
		Str = new char[len];
		strcpy_s(Str, len, str);
	}
	void Destroy() {
		if (Str) {
			delete[]Str;
			Str = nullptr;
		}
	}
public:
	STRING() :Str(nullptr) {}
	~STRING() {
		Destroy();
	}

	STRING(const char* str) {
		Create(str);
	}
	void operator=(const char* str) {
		Destroy();
		Create(str);
	}

	//コピー
	STRING(const STRING& other) {
		Create(other.Str);
	}
	void operator=(const STRING& other) {
		Destroy();
		Create(other.Str);
	}

	//ムーブ
	STRING(STRING&& other) noexcept{
		Str = other.Str;
		other.Str = nullptr;
	}
	void operator=(STRING&& other) noexcept{
		Destroy();
		Str = other.Str;
		other.Str = nullptr;
	}

	bool operator>(STRING& other) { return strcmp(Str, other.Str) > 0; }
	bool operator<(STRING& other) { return strcmp(Str, other.Str) < 0; }
	bool operator==(STRING& other) { return strcmp(Str, other.Str) == 0; }

	operator const char* () {
		return Str;
	}

	const char* c_str()const { 
		return Str; 
	}
};
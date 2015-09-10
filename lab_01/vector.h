#pragma once
class vector {
private:
	int*coordinates, number, lastError;
public:
	enum {
		noError, memoryLimit, exitArray
	};
	vector(void);
	vector(int size);
	~vector(void);
	int getLastError(void);
	int getSize(void);
	int getCoordinate(int index);
	void setSize(int size);
	void setCoordinate(int index, int var);
	void setLastError(int error);
	void replace(int size);
	void print(void);
	int sum(void);
	int product(void);
	void add(int sum);
	void multiplication(int prod);
	double length();
};

#include "stdafx.h"
#include "vector.h"
#include <iostream>
using namespace std;

/*
	Created by NickLatkovich
*/

const unsigned int VECTORS = 10;

void cls(void) {
	system("cls");
}
void pause(void) {
	system("pause");
}
void printVectors(vector vectors[]) {
	cls();
	cout << " --- Printing vectors ---\n\n ";
	for (int i = 0; i < VECTORS; i++) {
		cout << i + 1 << ". ";
		vectors[i].print();
		cout << "\n ";
	}
	cout << "\n ";
	pause();
}
void vectorReplace(vector vectors[]) {
	int n, l;
	cls();
	cout << "\n --- Creating Vectors ---\n\n ";
	for (int i = 0; i < VECTORS; i++) {
		int unsigned size = rand() % 5 + 1;
		vectors[i].setSize(size);
		for (int j = 0; j < size; j++) {
			vectors[i].setCoordinate(j, rand() % 21 - 10);
		}
		cout << i + 1 << ". ";
		vectors[i].print();
		cout << "\n ";
	}
	cout << "\n ";
	pause();
}
void printSize(vector vectors[]) {
	cls();
	cout << "\n --- Get size of vectors ---\n\n ";
	for (int i = 0; i < VECTORS; i++) {
		cout << i + 1 << ". S";
		vectors[i].print();
		cout << " = " << vectors[i].getSize() << "\n ";
	}
	cout << "\n ";
	pause();
}
void addUp(vector vectors[]) {
	cls();
	cout << "\n --- Add up the number of ---\n\n ";
	for (int i = 0; i < VECTORS; i++) {
		cout << i + 1 << ". ";
		vectors[i].print();
		cout << "\n ";
	}
	cout << "\n Inter the number of vector\n >> ";
	int n;
	cin >> n;
	n--;
	if (n < 0 || n >= VECTORS) {
		cout << "\n ERROR: out of array of objects!";
	}
	else {
		cout << "\n Inter the number\n >> ";
		int m;
		cin >> m;
		cout << "\n ";
		vectors[n].print();
		cout << " + " << m << " = ";
		vectors[n].add(m);
		vectors[n].print();
	}
	cout << "\n\n ";
	pause();
}
void multipleBy(vector vectors[]) {
	cls();
	cout << "\n --- Multiplied by the number of ---\n\n ";
	for (int i = 0; i < VECTORS; i++) {
		cout << i + 1 << ". ";
		vectors[i].print();
		cout << "\n ";
	}
	cout << "\n Inter the number of vector\n >> ";
	int n;
	cin >> n;
	n--;
	if (n < 0 || n >= VECTORS) {
		cout << "\n ERROR: out of array of objects!";
	}
	else {
		cout << "\n Inter the number\n >> ";
		int m;
		cin >> m;
		cout << "\n ";
		vectors[n].print();
		cout << " * " << m << " = ";
		vectors[n].multiplication(m);
		vectors[n].print();
	}
	cout << "\n ";
	pause();
}
void setCoord(vector vectors[]) {
	cls();
	cout << "\n --- Set coordinate ---\n\n ";
	for (int i = 0; i < VECTORS; i++) {
		cout << i + 1 << ". ";
		vectors[i].print();
		cout << "\n ";
	}
	cout << "\n Inter the number of vector\n >> ";
	int n;
	cin >> n;
	n--;
	if (n < 0 || n >= VECTORS) {
		cout << "\n ERROR: out of array of objects!\n\n ";
	}
	else {
		cout << "\n\n Inter the number of measurement (1 - " << vectors[n].getSize() << ")\n >> ";
		int k, m;
		cin >> k;
		k--;
		cout << "\n\n Inter the coordinate\n >> ";
		cin >> m;
		vectors[n].setCoordinate(k, m);
		if (vectors[n].getLastError() == vectors[n].exitArray) {
			cout << "\n ERROR: Permission measurement is not supported by the vector!\n\n ";
		}
		else {
			cout << "\n Vector = ";
			vectors[n].print();
			cout << "\n\n ";
		}
	}
	pause();
}
void sumVectors(vector vectors[]) {
	cls();
	cout << "\n --- Summing two vectors ---\n\n ";
	for (int i = 0; i < VECTORS; i++) {
		cout << i + 1 << ". ";
		vectors[i].print();
		cout << "\n ";
	}
	cout << "\n Inter the number of vector\n >> ";
	int n;
	cin >> n;
	n--;
	if (n < 0 || n >= VECTORS) {
		cout << "\n ERROR: out of array of objects!\n\n ";
	}
	else {
		cout << "\n Inter the number of second vector\n >> ";
		int n1;
		cin >> n1;
		n1--;
		if (n1 < 0 || n1 >= VECTORS) {
			cout << "\n ERROR: out of array of objects!\n\n ";
		}
		else {
			if (vectors[n].getSize() != vectors[n1].getSize()) {
				cout << "\n ERROR: vectors are not support the summing!\n\n ";
			}
			else {
				vector temp(vectors[n].getSize());
				for (int i = 0; i < vectors[n].getSize(); i++) {
					temp.setCoordinate(i, vectors[n].getCoordinate(i) + vectors[n1].getCoordinate(i));
				}
				cout << "\n ";
				vectors[n].print();
				cout << " + ";
				vectors[n1].print();
				cout << " = ";
				temp.print();
				cout << "\n\n ";
			}
		}
	}
	pause();
}
int _tmain(int argc, _TCHAR* argv[])
{
	vector vectors[VECTORS];
	vectorReplace(vectors);
	int setter;
	do {
		cls();
		cout << "\n --- Main Menu ---\n";
		cout << "\n 1. Print vectors";
		cout << "\n 2. Rechange vectors";
		cout << "\n 3. Get size of vectors";
		cout << "\n 4. Add up the number of";
		cout << "\n 5. Multiplied by the number of";
		cout << "\n 6. Set coordinate";
		cout << "\n 7. Sum two vectors";
		cout << "\n 0. Exit\n\n >> ";
		cin >> setter;
		switch (setter) {
		case 1:
			printVectors(vectors);
			break;
		case 2:
			vectorReplace(vectors);
			break;
		case 3:
			printSize(vectors);
			break;
		case 4:
			addUp(vectors);
			break;
		case 5:
			multipleBy(vectors);
			break;
		case 6:
			setCoord(vectors);
			break;
		case 7:
			sumVectors(vectors);
		case 0:
			cls();
			cout << "\n --- Exit ---\n\n ";
			system("exit");
			break;
		}
	} while (setter != 0);
	return 0;
}
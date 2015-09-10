#include "stdafx.h"
#include "vector.h"
#include <iostream>

vector::vector(void) {
	coordinates = 0;
	number = 0;
	lastError = noError;
}
vector::vector(int size) {
	coordinates = new int[size];
	number = size;
	for (int i = 0; i < size; i++) {
		coordinates[i] = 0;
	}
	lastError = noError;
}
vector::~vector(void) {
	delete[]coordinates;
}
int vector::getLastError() {
	int temp = lastError;
	lastError = noError;
	return temp;
}
int vector::getSize(void) {
	return number;
}
int vector::getCoordinate(int index) {
	if (index < 0 || index >= number) {
		lastError = exitArray;
		return 0;
	}
	else {
		return coordinates[index];
	}
}
void vector::print(void) {
	std::cout << "(";
	for (int i = 0; i < number; i++) {
		if (i > 0) {
			std::cout << ", ";
		}
		std::cout << coordinates[i];
	}
	std::cout << ")";
}
int vector::sum(void) {
	int temp = 0;
	for (int i = 0; i < number; i++) {
		temp += coordinates[i];
	}
	return temp;
}
int vector::product(void) {
	int temp = 1;
	for (int i = 0; i < number; i++) {
		temp *= coordinates[i];
	}
	return temp;
}
void vector::setSize(int size) {
	replace(size);
}
void vector::setCoordinate(int index, int coordinate) {
	if (index < 0 || index >= number) {
		lastError = exitArray;
	}
	else {
		coordinates[index] = coordinate;
	}
}
void vector::add(int temp) {
	for (int i = 0; i < number; i++) {
		coordinates[i] += temp;
	}
}
void vector::multiplication(int temp) {
	for (int i = 0; i < number; i++) {
		coordinates[i] *= temp;
	}
}
void vector::replace(int size) {
	delete[]coordinates;
	number = size;
	coordinates = new int[size];
	for (int i = 0; i < size; i++) {
		coordinates[i] = 0;
	}
}
double vector::length() {
	int sumOfSquares = 0;
	for (int i = 0; i < number; i++) {
		sumOfSquares += coordinates[i] * coordinates[i];
	}
	return (sqrt(sumOfSquares));
}

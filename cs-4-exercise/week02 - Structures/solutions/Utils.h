#pragma once

void copyStr(char* buffer, char*& field);

using priceFilter = bool (*) (double, double);

bool isBigger(double num1, double num2);

bool isSmaller(double num1, double num2);

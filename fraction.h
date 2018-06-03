#ifndef FRACTION_H
#define FRACTION_H
#include <algorithm>
#include <iostream>
#include <qstring.h>
class Fraction {
public:
  Fraction() {
    Numerator = 0;
    Denominator = 0;
  }

  Fraction(int NewNumerator, int NewDenominator) {
    Numerator = NewNumerator;
    Denominator = NewDenominator;
  }

  Fraction(int NewInteger, int NewNumerator, int NewDenominator) {
    Numerator = NewNumerator + NewInteger * NewDenominator;
    Denominator = NewDenominator;
  }

  const Fraction operator/(const Fraction &obj);
  const Fraction operator*(const Fraction &obj);
  const Fraction operator-(const Fraction &obj);
  const Fraction operator+(const Fraction &obj);
  Fraction &operator=(const Fraction &obj);

  bool OverFlow();

  const Fraction Converse() const;

  int getNumerator() const;
  void setNumerator(int value);

  int getDenominator() const;
  void setDenominator(int value);

  int getInteger() const;
  void setInteger(int value);

  int lcm(int a, int b);

protected:
  int Numerator;
  int Denominator;
  int Integer;
};

bool Validator(QString Check);

#endif // FRACTION_H

#include "fraction.h"
#include <QDebug>
const Fraction Fraction::operator/(const Fraction &obj) {

  Fraction Divide;

  Divide = *this * obj.Converse();

  return Divide;
}

const Fraction Fraction::operator*(const Fraction &obj) {
  Fraction Multiply;

  Multiply.Numerator = this->Numerator * obj.Numerator;
  Multiply.Denominator = this->getDenominator() * obj.getDenominator();
  return Multiply;
}

const Fraction Fraction::operator-(const Fraction &obj) {

  Fraction Subtraction;

  if (this->Denominator == obj.Denominator) {
    Subtraction.Numerator = this->Numerator - obj.Numerator;
    Subtraction.Denominator = this->Denominator;
  } else if (this->Denominator != obj.Denominator) {
    Subtraction.Numerator =
        (lcm(this->getDenominator(), obj.Denominator) / this->Denominator) *
            this->Numerator -
        (lcm(this->getDenominator(), obj.Denominator) / obj.Denominator) *
            obj.Numerator;
    Subtraction.Denominator = lcm(this->Denominator, obj.Denominator);
  }

  return Subtraction;
}

const Fraction Fraction::operator+(const Fraction &obj) {
  Fraction Adding;

  if (this->Denominator == obj.Denominator) {
    Adding.Numerator = this->Numerator + obj.Numerator;
    Adding.Denominator = this->Denominator;
  } else if (this->Denominator != obj.Denominator) {
    Adding.Numerator =
        (lcm(this->getDenominator(), obj.Denominator) / this->Denominator) *
            this->Numerator +
        (lcm(this->getDenominator(), obj.Denominator) / obj.Denominator) *
            obj.Numerator;
    Adding.Denominator = lcm(this->Denominator, obj.Denominator);
  }

  return Adding;
}

bool Fraction::OverFlow() {
  if (this->Numerator > this->Denominator)
    return true;
  else {
    return false;
  }
}

Fraction &Fraction::operator=(const Fraction &obj) {
  this->setNumerator(obj.getNumerator());
  this->setDenominator(obj.getDenominator());

  return *this;
}

const Fraction Fraction::Converse() const {
  Fraction Swap;
  Swap.Numerator = this->Denominator;
  Swap.Denominator = this->Numerator;
  return Swap;
}

int Fraction::getNumerator() const { return Numerator; }

void Fraction::setNumerator(int value) { Numerator = value; }

int Fraction::getDenominator() const { return Denominator; }

void Fraction::setDenominator(int value) { Denominator = value; }

int Fraction::getInteger() const { return Integer; }

void Fraction::setInteger(int value) { Integer = value; }

int Fraction::lcm(int a, int b) { return a / std::__gcd(a, b) * b; }

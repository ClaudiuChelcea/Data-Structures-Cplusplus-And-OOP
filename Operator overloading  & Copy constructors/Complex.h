#ifndef __COMPLEX_H
#define __COMPLEX_H
#include <math.h>
#include <ostream>
#include <iostream>

class Complex {
public:
  double re;
  double im;

  Complex(double re, double im) {
    this->re = re;
    this->im = im;
  }

  Complex(const Complex& other) {
	  this->re = other.re;
    this->im = other.im;
  }

  void operator=(const Complex& other) {
    this->re = other.re;
    this->im = other.im;
  }

  ~Complex() {
  }

  Complex operator+(const Complex& other) {
    return Complex(this->re + other.re,this->im + other.im);
  }

  Complex operator-(const Complex& other) {
    return Complex(this->re - other.re,this->im - other.im);
  }

  Complex operator*(const Complex& other) {
    return Complex(this->re *other.re,this->im * other.im);
  }

  float modulus() {
    return sqrt(re * re + im * im);
  }

  float segment(const Complex& other) {
    return sqrt((other.re - this->re) * (other.re - this->re) + (other.im - this->im) * (other.im - this->im));
  }

  friend std::ostream& operator<< (std::ostream &out, const Complex& complex);
};

#endif

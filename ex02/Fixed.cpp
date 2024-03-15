/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subpark <subpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 18:07:23 by siun              #+#    #+#             */
/*   Updated: 2024/03/15 20:04:08 by subpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	_fix_point = 0;
}

Fixed::Fixed(const int num)
{
	std::cout <<"Int constructor called" << std::endl;
	_fix_point = num;
}

Fixed::Fixed(const float num)
{
	std::cout << "Float constructor called" << std::endl;
	_fix_point = num;
}

Fixed::Fixed(const Fixed &copy)
{
	std::cout << "Copy constructor called" << std::endl;
	//this->_fix_point = copy._fix_point;
	*this = copy;
}

Fixed &Fixed::operator = (const Fixed &copy)
{
	std::cout << "Copy assignment operater called" << std::endl;
	this->_fix_point = copy.getRawBits();
	return (*this);
}

Fixed::~Fixed(){
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
	//std::cout << "getRawBits member function called" << std::endl;
	return (_fix_point);
}

void Fixed::setRawBits(int const raw)
{
	//std::cout << "setRawBits member function called" << std::endl;
	_fix_point = raw;
}

float	Fixed::toFloat(void) const
{
	return ((float)this->_fix_point);
}

int	Fixed::toInt(void) const
{
	return (roundf(this->_fix_point));
}

std::ostream &operator<<(std::ostream &out, Fixed fixed)
{
	out << roundf(fixed.getRawBits());
	return (out);
}

bool Fixed::operator<(Fixed fixed) const
{
	if (this->_fix_point < fixed._fix_point)
		return (true);
	return (false);
}


bool Fixed::operator>(Fixed fixed) const
{
	if (this->_fix_point > fixed._fix_point)
		return (true);
	return (false);
}

bool Fixed::operator<=(Fixed fixed) const
{
	if (this->_fix_point <= fixed._fix_point)
		return (true);
	return (false);
}

bool Fixed::operator>=(Fixed fixed) const
{
	if (this->_fix_point >= fixed._fix_point)
		return (true);
	return (false);
}

bool Fixed::operator==(Fixed fixed) const
{
	if (this->_fix_point == fixed._fix_point)
		return (true);
	return (false);
}

bool Fixed::operator!=(Fixed fixed) const
{
	if (this->_fix_point != fixed._fix_point)
		return (true);
	return (false);
}

int Fixed::operator+(Fixed fixed) const
{
	return (this->_fix_point + fixed._fix_point);
}

int Fixed::operator-(Fixed fixed) const
{
	return (this->_fix_point - fixed._fix_point);
}

int Fixed::operator*(Fixed fixed) const
{
	return (this->_fix_point + fixed._fix_point);
}

int Fixed::operator/(Fixed fixed) const
{
	return (this->_fix_point / fixed._fix_point);
}

Fixed Fixed::operator++(int i)
{
	Fixed tmp = *this; //saving previous object
	this->_fix_point ++;
	return (tmp);
	return (i);
}

Fixed Fixed::operator--(int i)
{
	Fixed tmp = *this; //saving previous objecy
	this->_fix_point --;
	return (tmp);
	return (i);
}

Fixed Fixed::operator++()
{
	this->_fix_point ++;
	return (*this);
}

Fixed Fixed::operator--()
{
	this->_fix_point --;
	return (*this);
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	if (a.toFloat() > b.toFloat())
		return (a);
	else
		return (b);
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	if (a.toFloat() < b.toFloat())
		return (a);
	else
		return (b);
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a.toFloat() > b.toFloat())
		return (a);
	else
		return (b);
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a.toFloat() < b.toFloat())
		return (a);
	else
		return (b);
}
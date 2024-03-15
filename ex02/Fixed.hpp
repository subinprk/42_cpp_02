/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subpark <subpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 18:07:26 by siun              #+#    #+#             */
/*   Updated: 2024/03/15 20:03:22 by subpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cmath>
#include <iostream>

class Fixed
{
	private:
		int					_fix_point;
		static const int	_fract_bit = 8;
	public:
		Fixed();
		Fixed(const int num);
		Fixed(const float num);
		Fixed(const Fixed &copy);
		~Fixed();
		int	getRawBits(void) const;
		//const means that when this function is called
		//on a const object of the class,
		//it promises not to modify the object's data members
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;
		
		Fixed & operator = (const Fixed &copy);
		
		bool operator<(Fixed fixed_x)const;
		bool operator>(Fixed fixed_x)const;
		bool operator<=(Fixed fixed_x)const;
		bool operator>=(Fixed fixed_x)const;
		bool operator==(Fixed fixed_x)const;
		bool operator!=(Fixed fixed_x)const;

		int operator+(Fixed fixed_x)const;
		int operator-(Fixed fixed_x)const;
		int operator*(Fixed fixed_x)const;
		int operator/(Fixed fixed_x)const;

		Fixed operator++(int i);
		Fixed operator--(int i);
		Fixed operator++();
		Fixed operator--();

		static Fixed &max(Fixed &a, Fixed &b);
		static Fixed &min(Fixed &a, Fixed &b);
		static const Fixed &max(const Fixed &a, const Fixed &b);
		static const Fixed &min(const Fixed &a, const Fixed &b);
};

std::ostream &operator<<(std::ostream &out, Fixed fixed);

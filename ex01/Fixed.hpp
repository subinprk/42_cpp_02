/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siun <siun@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 18:07:26 by siun              #+#    #+#             */
/*   Updated: 2024/03/13 22:49:54 by siun             ###   ########.fr       */
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
		Fixed & operator = (const Fixed &copy);
		~Fixed();
		int	getRawBits(void) const;
		//const means that when this function is called
		//on a const object of the class,
		//it promises not to modify the object's data members
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;

};

std::ostream &operator<<()
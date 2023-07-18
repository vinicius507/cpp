/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 16:14:54 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/07/18 16:30:53 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"

class Intern {
public:
  Intern(void);

  Intern(const Intern &other);

  ~Intern(void);

  Intern &operator=(const Intern &other);

  AForm *makeForm(const std::string type, const std::string target) const;
};

#endif // !INTERN_HPP

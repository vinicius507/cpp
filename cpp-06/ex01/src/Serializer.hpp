/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 15:30:24 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/06/15 15:53:08 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include "Data.hpp"
#include <cstdint>

class Serializer {
public:
  static uintptr_t serialize(Data *ptr);

  static Data *deserialize(uintptr_t raw);

private:
  Serializer(void);

  Serializer(const Serializer &other);

  ~Serializer(void);

  Serializer &operator=(const Serializer &other);
};

#endif // !SERIALIZER_HPP

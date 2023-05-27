/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stringReplace.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 21:29:07 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/05/27 14:06:00 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STR_REPLACE_HPP
#define STR_REPLACE_HPP

#include <string>

#define ALL_MATCHES -1

/**
 * @brief Replaces all occurrences of a substring in a string.
 *
 * @param str The string to be edited.
 * @param searchStr The search string.
 * @param replaceStr The replace string.
 * @param count The maximum number of substitutions. Defaults to -1, which
 * replaces all matches.
 */
std::string stringReplace(const std::string &str, const std::string &searchStr,
                          const std::string &replaceStr,
                          int count = ALL_MATCHES);

#endif

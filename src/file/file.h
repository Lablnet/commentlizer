/**
 * file manipulation {Header file}.
 *
 * @author   Malik Umer Farooq <lablnet01@gmail.com>
 * @author-profile https://www.facebook.com/malikumerfarooq01/
 *
 * For the full copyright and license information, please view the LICENSE
 *  file that was distributed with this source code.
 *
 * @license MIT
*/

#ifndef FILE_H_INCLUDED
#define FILE_H_INCLUDED

#include "file.cpp"
#include <string>

//Function defination.

inline bool is_exist(char *file);
std::string open(char *file);

#endif



/**
 * expection handling {header file}.
 *
 * @author   Malik Umer Farooq <lablnet01@gmail.com>
 * @author-profile https://www.facebook.com/malikumerfarooq01/
 *
 * For the full copyright and license information, please view the LICENSE
 *  file that was distributed with this source code.
 *
 * @license MIT
*/

#ifndef EXPECTION_H_INCLUDED
#define EXPECTION_H_INCLUDED

#include "expection.cpp"

//Function defination.
std::map<std::string,std::string> create_expection_errors();
std::string getMsg(std::string key, std::string replacement = "");
#endif

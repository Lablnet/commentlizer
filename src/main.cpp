/**
 * Mlang main file.
 *
 * @author   Malik Umer Farooq <lablnet01@gmail.com>
 * @author-profile https://www.facebook.com/malikumerfarooq01/
 *
 * For the full copyright and license information, please view the LICENSE
 *  file that was distributed with this source code.
 *
 * @license MIT
*/

#include <iostream>
#include <string>
#include "parser/parser.h"

int main(int args, char **argv)
{
	char *file;
	std::string lang, output;
	//char *file, *lang = NULL, *output = NULL;
	args--;
	argv++;
	if (args >= 1) {
		file = *argv;
		if (args == 2) {
			argv++;
			lang = *argv;			
		} else {
			lang = "default";
		}
		if (args == 3) {
			argv++;
			output = *argv;			
		} else {
			lang = "default";
		}
		std::cout << Lablnet::parser(file, lang, output);
	} else
		std::cout << "Invilid usage! ";
	
}


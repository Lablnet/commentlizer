/**
 * Parser.
 *
 * @author   Malik Umer Farooq <lablnet01@gmail.com>
 * @author-profile https://www.facebook.com/malikumerfarooq01/
 *
 * For the full copyright and license information, please view the LICENSE
 *  file that was distributed with this source code.
 *
 * @license MIT
*/
#include "../File/File.h"
#include "../expection/expection.h"

namespace Lablnet
{ //Start namespace
	bool defaultStyle, php, python;
	bool slashComment = false, poundComment = false, astrickComment = false;
	std::string parser(char *file, std::string lang, std::string otput)
	{
		if (Lablnet::is_exist(file)) {
			std::string code, newCode;
			int length, i = 0, blocksOfCode = 0;
	 		code = Lablnet::open(file);
			length = code.length();
			//Determine the language
			if (lang == "php")
				php = true;
			else if (lang == "python")
				python = true;
			else
				defaultStyle = true;
			
			for (i; i < length; i++) {
		     	// If single line comment in // format is on, then check for its end
		        if (slashComment == true && code[i] == '\n' && (php == true || defaultStyle == true)) 
		            slashComment = false; 
		  		// If single line comment in # format is on, then check for its end
		  		if (poundComment == true && code[i] == '\n' && (php == true || python == true|| defaultStyle == true)) 
		            poundComment = false; 
		        // If multi line comment is on, then check for its end
		        else if  (astrickComment == true && code[i] == '*' && code[i+1] == '/' && (php == true || python == true || defaultStyle == true))
		            astrickComment = false,  i++; 

		        // If current character is in a comment, ignore it 
		        if (slashComment == true || poundComment == true || astrickComment == true) {
					std::cout << "Removing.." << std::endl;
		        	continue;
		        	blocksOfCode++;
		        }
				
		        // Check for beginning of comments and set the approproate flags 
		        else if (code[i] == '/' && code[i+1] == '/' && (php == true || defaultStyle == true)) 
		            slashComment = true, i++; 
		        else if (code[i] == '#' && (php == true || python == true|| defaultStyle == true)) 
		            poundComment = true,  i++;    
		        else if (code[i] == '/' && code[i+1] == '*'  && (php == true || python == true || defaultStyle == true)) 
		            astrickComment = true,  i++;
	        	// If current character is a non-comment character, append it to newCode 
	        	else  newCode += code[i]; 
			}
			
			std::cout << "Comments blocks removed " << blocksOfCode << std::endl;
			Lablnet::write_on_file(file,newCode);
			return newCode;
		}
		std::cout << Lablnet::getMsg("fileNotExist",file);
		return 0;
	}
} //End namespace Lablnet

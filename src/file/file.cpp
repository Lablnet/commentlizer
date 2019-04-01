/**
 * manipulate file.
 *
 * @author   Malik Umer Farooq <lablnet01@gmail.com>
 * @author-profile https://www.facebook.com/malikumerfarooq01/
 *
 * For the full copyright and license information, please view the LICENSE
 *  file that was distributed with this source code.
 *
 * @license MIT
*/

#include <fstream>
#include <sstream>
#include "../expection/expection.h"

namespace Lablnet
{ //Start nameepace
	/**
	 * Determine if file exists.
	 *
	 * @param (char) file file with path
	 *
	 * @since 1.0.0
	 *
	 * @return bool
	*/
    inline bool is_exist(char *file)
    {
		if (std::ifstream(file))
			return true;
		
		return false;
    }
    
	/**
	 * Open an file.
	 *
	 * @param (char) file file with path
	 *
	 * @since 1.0.0
	 *
	 * @return mixed
	*/    
    std::string open(char *file)
	{
		if (is_exist(file) == true) {
			std::string str, defaultStr = "";
			std::ifstream oFile;
			oFile.open(file);
			while(!oFile.eof()) {
			    getline(oFile,str); 
			    defaultStr += str;
			    defaultStr.push_back('\n');
			}   
			oFile.close(); 
			return defaultStr;			
		} else
    		return Lablnet::getMsg("fileNotExist",file);
	}
	void write_on_file(char *file, std::string contents)
	{
		std::ofstream wFile;
		wFile.open (file);
		wFile << contents;
		wFile.close();
	}
}  //End namespace Lablnet


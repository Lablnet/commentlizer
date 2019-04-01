/**
 * expection handling.
 *
 * @author   Malik Umer Farooq <lablnet01@gmail.com>
 * @author-profile https://www.facebook.com/malikumerfarooq01/
 *
 * For the full copyright and license information, please view the LICENSE
 *  file that was distributed with this source code.
 *
 * @license MIT
*/

#include <map>
#include "../str/str.h"

namespace Lablnet
{ //Start namespace
	
	/**
	 * Return the msgs.
	 *
	 * @since 1.0.0
	 *
	 * @return array
	*/	
	std::map<std::string,std::string> create_expection_errors()
	{
		std::map<std::string,std::string> e;
		e["fileNotExist"] = "Sorry, this file :r is not exists";
		e["keyNotFound"]  = "Sorry, there is no msg found regard this key :r";
		return e;
	}
	
	/**
	 * Store the assos array of expections errors.
	 *
	 * @since 1.0.0
	 *
	 * @var array	
	*/
	std::map<std::string,std::string> e = create_expection_errors();

	/**
	 * Get an msg from expection.
	 *
	 * @param (string) key valid key
	 *
	 * @since 1.0.0
	 *
	 * @return string
	*/	
	std::string getMsg(std::string key, std::string replacement = "")
	{
		if (e.count(key) == 1) 
			return Lablnet::replace(e[key],":r",replacement);
		else 
			return Lablnet::replace(e["keyNotFound"],":r",key);
	}	
} //End namespace Lablnet

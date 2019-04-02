/**
 * Str handling.
 *
 * @author   Malik Umer Farooq <lablnet01@gmail.com>
 * @author-profile https://www.facebook.com/malikumerfarooq01/
 *
 * For the full copyright and license information, please view the LICENSE
 *  file that was distributed with this source code.
 *
 * @license MIT
*/

namespace Lablnet
{ //Start namespace
	/**
	 * Replace a part of string.
	 *
	 * @param (string) str the base string.
	 * @param (string) from searched string.
	 * @param (string) to searched value to be repalced.
	 *
	 * @since 1.0.0
	 *
	 * @return string
	*/	
	std::string replace(std::string str, std::string from, std::string to)
	{
		size_t start_pos = str.find(from);
		
		return str.replace(start_pos, from.length(), to);
	}
} //End namespace Lablnet

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchennia <pchennia@student.42.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 14:15:03 by pchennia          #+#    #+#             */
/*   Updated: 2024/08/28 13:21:08 by pchennia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sstream>
#include <fstream>

int readFromSrcfile(std::string &srcContent, std::string &srcFile)
{
    std::ifstream in(srcFile);
	if (!in)
	{
		std::cerr << "Error: Failed to open a source file " << srcFile << std::endl;
		return 1;
	}
    std::stringstream temp;
    temp << in.rdbuf();
	in.close();
    srcContent = temp.str();
    if (srcContent.empty())
	{
		std::cerr << "Failed to read the file or file is empty" << std::endl;
		return 1;
	}
    return 0;
}

std::string replaceString(std::string &srcContent, std::string &search, std::string &replace)
{
    std::string result = srcContent;
    size_t pos = 0;
    while ((pos = result.find(search, pos)) != std::string::npos)
    {
        result.replace(pos, search.length(), replace);
        pos += replace.length();
    }
    return result;
}

void writeToDestfile(std::string &destFile, std::string contentWithReplace)
{
    std::ofstream	out(destFile);
	if (!out)
	{
		std::cerr << "Error: Failed to open a destination file " << destFile << std::endl;
		return ;
	}
	out << contentWithReplace;
    out.close();
}

int main(int argc, char *argv[])
{
	if (argc != 4)
	{
		std::cout << "Invalid number of arguments\n";
		std::cout << "Usage: " << argv[0] << " <filename> <string_to_replace> <replacement_string>\n";
		return 1;
	}
	std::string srcFilename = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];
    std::string destFilename = srcFilename + ".replace";
    std::string srcContent;
    if (readFromSrcfile(srcContent, srcFilename))
        return 1;
    std::string srcContentWithReplace = replaceString(srcContent, s1, s2);
    writeToDestfile(destFilename, srcContentWithReplace);
    return 0;
}


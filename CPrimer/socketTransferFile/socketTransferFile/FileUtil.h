#pragma once
#include <string>

class FileUtil
{
public:
	FileUtil();
	~FileUtil();
	static FileTime getFileTime(std::string file);
	static void setFileTime(std::string file, FileTime ft);
};


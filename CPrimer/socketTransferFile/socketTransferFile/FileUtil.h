#pragma once
#include <direct.h>
#include <io.h>

class FileUtil
{
public:
	FileUtil();
	~FileUtil();
	static FileTime getFileTime(std::string file);
	static void setFileTime(std::string file, FileTime ft);
	static bool createDirs(std::string dir);
	static std::wstring stringToWString(std::string& str);
	static bool exists(std::string filename);
};


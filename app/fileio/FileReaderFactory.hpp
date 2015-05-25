#pragma once

#include "IFileReader.hpp"
#include <string>

class FileReaderFactory
{
public:
    static IFileReader *create(const std::string &format);
};


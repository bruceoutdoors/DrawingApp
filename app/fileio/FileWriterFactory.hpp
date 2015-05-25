#pragma once

#include "IFileWriter.hpp"

class FileWriterFactory
{
public:
    static IFileWriter *create(const std::string &format);
};


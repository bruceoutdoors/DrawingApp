#pragma once

#include <string>

class Group;

class IFileWriter
{
public:
    virtual ~IFileWriter() {}

    virtual void setup(Group *mainGroup) = 0;
    virtual bool write(const std::string &fileDir) = 0;
};

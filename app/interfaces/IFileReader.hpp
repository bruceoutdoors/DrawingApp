#pragma once

#include <string>

class Group;

class IFileReader
{
public:
    virtual ~IFileReader() {}

    virtual void setup(Group *mainGroup) = 0;
    virtual bool read(const std::string &fileDir) = 0;
};

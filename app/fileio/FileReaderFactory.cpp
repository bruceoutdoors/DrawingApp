#include "FileReaderFactory.hpp"
#include "JsonFileReader.hpp"

IFileReader *FileReaderFactory::create(const std::string &format)
{
    if (format == "json") {
        return new JsonFileReader();
    }

    return nullptr;
}

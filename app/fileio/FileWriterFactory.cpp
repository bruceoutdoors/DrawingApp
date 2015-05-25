#include "FileWriterFactory.hpp"
#include "JsonFileWriter.hpp"

IFileWriter *FileWriterFactory::create(const std::string &format)
{
    if (format == "json") {
        return new JsonFileWriter();
    }

    return nullptr;
}

#pragma once

// https://github.com/Kazun1998/library_for_cpp/blob/main/template/exception.hpp

class NotExist: public exception {
    private:
    string message;

    public:
    NotExist() : message("求めようとしていたものは存在しません.") {}

    const char* what() const noexcept override {
        return message.c_str();
    }
};
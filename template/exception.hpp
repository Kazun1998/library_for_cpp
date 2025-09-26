#pragma once

class NotExist: public exception {
    private:
    string message;

    public:
    NotExist() : message("求めようとしていたものは存在しません.") {}

    const char* what() const noexcept override {
        return message.c_str();
    }
};

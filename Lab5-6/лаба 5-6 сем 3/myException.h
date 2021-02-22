#pragma once
#ifndef LABA_5_6_SEM_3_MYEXCEPTION_H
#define LABA_5_6_SEM_3_MYEXCEPTION_H
#include <iostream>
namespace MYEXCEPTION {

    class myException {
    private:
        std::string message;
    public:
        myException();

        myException(const myException& right) { message = right.message; };

        myException(const char* _message = "Somethin\' went wrong") : message(_message) {};

        myException(const std::string& _massage) { message = _massage; };

        myException& operator=(const myException& right) { message = right.message; return *this; };

        virtual const std::string& what() { return message; };

        virtual ~myException() {};
    };

    class bad_file : public myException {
    private:
        std::string bad_name;
    public:
        explicit bad_file(const std::string& fileName,
            const char* what_arg = "Current file does\'t exist or can\'t be opened") : bad_name(fileName), myException(what_arg) {};
        const std::string& getBadName() { return bad_name; };
        virtual ~bad_file() {};
    };
}

#endif //LABA_5_6_SEM_3_MYEXCEPTION_H

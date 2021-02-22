#pragma once
#ifndef LABA_5_6_SEM_3_MYFILECLASS_H
#define LABA_5_6_SEM_3_MYFILECLASS_H
#include "myException.h"
#include <fstream>
#include <iostream>
#include <cstring>
namespace MYFILECLASS {

    using std::ifstream;
    using std::ofstream;
    using std::fstream;
    using std::string;
    using std::istream;
    using std::ostream;


    template <class T>
    class myFileClass
    {
            public:
                using ValueType = T;
                using ValueReference = T&;
                using ValuePointer = T*;
                using bad_file = MYEXCEPTION::bad_file;
            protected:
               fstream File;
               string  fileName;
               bool flagWriteToEnd;
               bool flagReadFromBegin;
               size_t fileMaxPos;
               size_t fileCurrentPos;
            public:
                myFileClass(const char* name = "myTextFile.txt");

                myFileClass(const myFileClass<ValueType>& file) ;

                template<class Ty> friend istream& operator>>(istream& in, myFileClass<Ty>& file);

                template<class Ty> friend ostream& operator<<(ostream& out, myFileClass<Ty>& file);

                myFileClass& operator<<(ValueType obj);
                myFileClass& operator<<(const char* obj);
                myFileClass& operator>>(ValueType* obj);
                ~myFileClass() {
                    File.close();
                };
     };


    template <class T> 
    myFileClass<T>::myFileClass(const char* name) : fileName(name),
        File(name, std::ios_base::binary | std::ios_base::out | std::ios_base::in | std::ios_base::trunc),
             flagReadFromBegin(true), flagWriteToEnd(true), fileCurrentPos(0), fileMaxPos(0)
    {
        try {
            if (!File.is_open())
                throw bad_file(fileName);
        }
        catch (bad_file bad) {
            std::cout << "File : " << bad.getBadName() << "\nProblem : " << bad.what();
            return;
        }
    }
    template <class T>
    myFileClass<T>::myFileClass(const myFileClass<T>& file) :
        File(file.fileName, std::ios_base::binary | std::ios_base::out | std::ios_base::in | std::ios_base::trunc),
        flagReadFromBegin(file.flagReadFromBegin), flagWriteToEnd(flagWriteToEnd), fileCurrentPos(file.fileCurrentPos), fileMaxPos(file.fileMaxPos)
    {
        fileName = file.fileName;
        try {
            File.open(fileName);
            if (!File.is_open())
                throw bad_file(fileName);
        }
        catch (bad_file bad) {
            std::cout << "File : " << bad.getBadName() << "\nProblem : " << bad.what();
            return;
        }
    }

    template <class T>
    myFileClass<T>& myFileClass<T>::operator<<(ValueType obj)
    {
        if (flagReadFromBegin && flagWriteToEnd)
        {
            flagWriteToEnd = 1;
            flagReadFromBegin = 0;
        }
        if (flagReadFromBegin)
        {
            flagWriteToEnd = 1;
            flagReadFromBegin = 0;
            File.seekp(fileMaxPos,std::ios_base::beg);
            fileCurrentPos = fileMaxPos;
        }
        File.write((char*)&obj, sizeof(ValueType));
        fileMaxPos += sizeof(ValueType);
        fileCurrentPos = fileMaxPos;
        
            return *this;
    }
    template <>
    myFileClass<char>& myFileClass<char>::operator<<(const char* obj)
    {
        if (flagReadFromBegin && flagWriteToEnd)
        {
            flagWriteToEnd = 1;
            flagReadFromBegin = 0;
        }
        if (flagReadFromBegin)
        {
            flagWriteToEnd = 1;
            flagReadFromBegin = 0;
            File.seekp(fileMaxPos, std::ios_base::beg);
            fileCurrentPos = fileMaxPos;
        }
        File <<" "<< obj;
        fileMaxPos += std::strlen(obj)+1;
        fileCurrentPos = fileMaxPos;
        return *this;
    }


    template <class T>
    myFileClass<T>& myFileClass<T>::operator>>(ValueType* obj)
    {
        if (flagWriteToEnd)
        {
            File.seekg(std::ios_base::beg);
            flagReadFromBegin = 1;
            flagWriteToEnd = 0;
            fileCurrentPos = 0;
        }
        if (fileCurrentPos != fileMaxPos)
        {
            File.read((char*)obj, sizeof(ValueType));
            fileCurrentPos += sizeof(ValueType);
        }
        else
            *obj = ValueType();
       return *this;
    }
    template <>
    myFileClass<char>& myFileClass<char>::operator>>(ValueType* obj)
    {
        if (flagWriteToEnd)
        {
            File.seekg(std::ios_base::beg);
            flagReadFromBegin = 1;
            flagWriteToEnd = 0;
            fileCurrentPos = 0;
        }
        if (fileCurrentPos != fileMaxPos)
        {
                File>>obj;
                fileCurrentPos += std::strlen(obj)+1;
        }
        else
            *obj = ValueType();
        return *this;
    }

    template<class Ty>  istream& operator>>(istream& in, myFileClass<Ty>& file)
    {
        Ty temp;
        in >> temp;
        file << temp;
        return in;
    }
        template<>
        istream& operator>><char>(istream& in, myFileClass<char>& file)
        {
            char buf[512];
            in.getline(buf, 512);
            buf[in.gcount() + 1] = '\0';
            file << buf;
            return in;
        }

        
        template<class Ty>
        ostream& operator<<(ostream& out, myFileClass<Ty>& file) {
            typename myFileClass<Ty>::ValueType temp;
            do {
                file >> &temp;
                out << temp<<" ";
            } while (file.fileCurrentPos != file.fileMaxPos);
            return out;
        };
         template<>
         ostream& operator<<<char>(ostream& out, myFileClass<char>& file) {
             char buf[512];
             file.File.seekg(0);
             int i;
             for (i = 0; !file.File.eof(); i++)
             {
                 file.File.get(buf[i]);
             }
             buf[i - 1] = '\0';
             out << buf;
             return out;
         }

}

#endif //LABA_5_6_SEM_3_MYFILECLASS_H

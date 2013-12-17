/*
 * @file    Singleton.h
 * @author  ichenq@gmail.com
 * @date    Nov 29, 2013
 * @breif   基于std::call_once的多线程单件模式
 *
 */

#pragma once

#include <boost/noncopyable.hpp>
#include <mutex>


template <typename T>
class Singleton : boost::noncopyable
{
public:
    static T&   GetInstance()
    {
        std::call_once(once_flag_, []{
            instance_.reset(new T);
        });
        return *instance_.get();
    }   

private:
    static std::unique_ptr<T>   instance_;
    static std::once_flag       once_flag_;
};

template <typename T>
std::unique_ptr<T>  Singleton<T>::instance_;

template <typename T>
std::once_flag  Singleton<T>::once_flag_;

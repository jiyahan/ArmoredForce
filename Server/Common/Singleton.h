/*
 * @file    Singleton.h
 * @author  ichenq@gmail.com
 * @date    Nov 29, 2013
 * @breif   单线程和多线程单件
 *
 */

#pragma once

#include <memory>
#include <mutex>
#include <boost/noncopyable.hpp>


template <typename T>
class Singleton : boost::noncopyable
{
public:
    static T&   GetInst()
    {
        return *instance_;
    }

    template <typename... Args>
    static T& Create(Args... args)
    {
        CHECK(!instance_);
        instance_.reset(new T(args...));
        return GetInst();
    }

    static void Destroy()
    {
        instance_.reset(nullptr);
    }

private:
    static std::unique_ptr<T>   instance_;
};

template <typename T>
std::unique_ptr<T>  Singleton<T>::instance_;


// 多线程安全的单件
template <typename T>
class MultiSingleton : boost::noncopyable
{
public:
    static T&   GetInst()
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
std::unique_ptr<T>  MultiSingleton<T>::instance_;

template <typename T>
std::once_flag  MultiSingleton<T>::once_flag_;

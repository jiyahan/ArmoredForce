#pragma once

#include <string>
#include <iterator>
#include <algorithm>
#include <mysql.h>
#include <mysql++.h>

inline std::string escape_string(const std::string& str)
{
    std::unique_ptr<char> bufptr(new char[str.size() * 2]);
    int32_t length = mysql_escape_string(bufptr.get(), str.c_str(), str.size());
    return std::string(bufptr.get(), length);
}


inline mysqlpp::StoreQueryResult QueryMoreStoreResult(mysqlpp::Query& query)
{
    auto result = query.store();
    while (query.more_results())
    {
        auto more_res = query.store_next();
        if (!more_res.empty())
        {
            std::copy(more_res.begin(), more_res.end(),
                std::back_insert_iterator<mysqlpp::StoreQueryResult>(result));
        }
    }
    return std::move(result);
}

﻿#ifndef APIS_H
#define APIS_H

namespace API {
    namespace LOGIN {
    static const int NORMAL = 1; // 常规登录
    }

    namespace BUCKETS {
    static const int BASE = 100;
    static const int LIST = BASE + 1; // 获取桶列表
    static const int PUT = BASE + 2;  // 创建桶
    static const int DEL = BASE + 3;  // 删除桶
    } // namespace BUCKETS

    namespace OBJECTS {
    static const int BASE = 200;
    static const int LIST = BASE + 1; // 获取对象列表
    static const int GET = BASE + 10; // 下载对象
    static const int PUT = BASE + 20; // 上传对象
    } // namespace OBJECTS
} // namespace API

#endif // APIS_H

#include <assert.h>
#include <string.h>
#include <leveldb/db.h>
#include <iostream>
#include <sys/time.h>

using namespace leveldb;

int main(){
    leveldb::DB* db;
    leveldb::Options options;
    options.create_if_missing = true;
    // 打开一个数据库，不存在就创建
    leveldb::Status status = leveldb::DB::Open(options, "/tmp/testdb", &db);
    assert(status.ok());

    struct timeval start,end;
    long mtime,seconds,useconds;
    gettimeofday(&start,NULL);
   // 插入一个键值对
    status = db->Put(leveldb::WriteOptions(), "hello", "mytest!");
    assert(status.ok());
    gettimeofday(&end,NULL);
    seconds = end.tv_sec - start.tv_sec;
    useconds = end.tv_usec - start.tv_usec;
    mtime = ((seconds) * 1000 + useconds / 1000.0) + 0.5;
    std::cout<<"mtime:"<<mtime<<std::endl;
    
    gettimeofday(&start,NULL);
   // 读取键值对
    std::string value;
    status = db->Get(leveldb::ReadOptions(), "hello", &value);
    gettimeofday(&end,NULL);
    seconds = end.tv_sec - start.tv_sec;
    useconds = end.tv_usec - start.tv_usec;
    mtime = ((seconds) * 1000 + useconds / 1000.0) + 0.5;
    std::cout<<"mtime:"<<mtime<<std::endl;
    
    assert(status.ok());
    std::cout << value << std::endl;

    delete db;
    return 0;
}

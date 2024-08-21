#include <iostream>
#include <string>
#include <leveldb/db.h>
#include <sys/time.h>

using namespace std;


int main()
{
    leveldb::DB *db;
    leveldb::Options options;
    leveldb::ReadOptions readOptions;
    leveldb::Status status = leveldb::DB::Open(options, "/tmp/testdb", &db);
    
    string get;

    string key = "hello";
    
    struct timeval start,end;
    long mtime,seconds,useconds;
    gettimeofday(&start,NULL);
    if (status.ok()) {
        status = db->Get(readOptions, key, &get);
    }
    gettimeofday(&end,NULL);
    seconds = end.tv_sec - start.tv_sec;
    useconds = end.tv_usec - start.tv_usec;
    mtime = ((seconds) * 1000 + useconds / 1000.0) + 0.5;
    std::cout<<"mtime:"<<mtime<<std::endl;
    
    if (status.ok())
        cout << "key:" << key << "\nget value:" << get << std::endl;
    else
        cout << "error occurred!" << endl;
       
    delete db;

    return 0;
}

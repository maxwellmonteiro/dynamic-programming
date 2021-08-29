#include <string>
#include <cstring>

#include "args_loader.hpp"

#define DELIMITER " "

ArgsLoader::ArgsLoader(string file_name)
{
    stream = ifstream(file_name, ifstream::in);    
    if (!stream.is_open()) throw std::runtime_error("ArgsLoader::ArgsLoader: Could not open file.");
    stream_size = GetStreamSize(stream);
}

ArgsLoader::~ArgsLoader()
{
    stream.close();
}

uint64_t ArgsLoader::LoadUintAt(int64_t pos)
{        
    vector<string> args = LoadArgs();
    string arg = GetArgAt(args, pos);        
    return stoll(arg, nullptr, 10);;
}

vector<uint64_t> ArgsLoader::LoadUints()
{
    vector<string> args = LoadArgs();    
    vector<uint64_t> uint64s = ToUint64(args);     
    return uint64s;
}

uint64_t ArgsLoader::GetStreamSize(ifstream& is)
{
    uint64_t size;
    is.seekg(0, is.end);
    size = is.tellg();
    is.seekg(0, is.beg);
    return size;
}

vector<string> ArgsLoader::LoadArgs(char* buffer, const string delimiter)
{    
    vector<string> args;
    char* token;   
    token = strtok(buffer, delimiter.c_str());
    while (token != nullptr) 
    {        
        args.push_back(string(token));
        token = strtok(nullptr, delimiter.c_str());
    }
    return args;
}

string ArgsLoader::GetArgAt(vector<string>& args, int64_t pos)
{
    string arg;    
    for (vector<string>::iterator it = args.begin(); it < args.end() && pos >= 0; it++, pos--)
        arg = *it;   
    return arg;
}

vector<uint64_t> ArgsLoader::ToUint64(vector<string>& args)
{       
    vector<uint64_t> uint64s; 
    for (vector<string>::iterator it = args.begin(); it < args.end(); it++)
        uint64s.push_back(stoll(*it, nullptr, 10));  

    return uint64s;
}

vector<string> ArgsLoader::LoadArgs()
{            
    char* buffer;    
    
    buffer = new char[stream_size];
    stream.read(buffer, stream_size);
    stream.seekg(0, stream.beg);
    vector<string> ret = LoadArgs(buffer, DELIMITER);
    delete[] buffer;
    return ret;
}


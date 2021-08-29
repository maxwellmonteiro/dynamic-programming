#include <cinttypes>
#include <vector>
#include <fstream>

using namespace std;

class ArgsLoader
{
    private:
        uint64_t stream_size;
        ifstream stream;

        vector<string> LoadArgs();
        string GetArgAt(vector<string>& args, int64_t pos);
        vector<string> LoadArgs(char* buffer, const string delimiter);
        uint64_t GetStreamSize(ifstream& is);
        vector<uint64_t> ToUint64(vector<string>& args);        
    public:
        ArgsLoader(string file_name);
        ~ArgsLoader();
        uint64_t LoadUintAt(int64_t pos);
        vector<uint64_t> LoadUints();
};
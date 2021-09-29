#include <iostream>

using namespace std;

void open_f(const string& path)
{
    cout << "Opening " << path << endl;   
}

void flush_f(const string& path)
{
    cout << "Flushing " << path << endl;   
}

void close_f(const string& path)
{
    cout << "Closing " << path << endl;   
}

class InputFileStream
{
    const string& path;
    
      public:
            InputFileStream(const string& path) : path(path)
            {
                open_f(path);
            }
    
            ~InputFileStream()
            {                
                flush_f(path);
                close_f(path);
            }
};

int main()
{
    InputFileStream("brol.txt");
}//désallocation implicite

#include <iostream>
#include <cstdio>

class FileReader
{
    std::FILE* f; //old school (C-style) file management
    char * buffer;    
    int size_read;
    
    public:
        FileReader(const char* name) : f(fopen(name, "r+")), buffer(new char[16]), size_read(0)
        {
            if(! f)
                throw std::invalid_argument("File does not exist");
        }
    
        ~FileReader()
        {
            std::fclose(f); //flush  and free file descriptor
            if(buffer)
            {
                delete[] buffer;                
                buffer = nullptr;
            }
        }
    
        FileReader(const FileReader& fh) = delete;    
        FileReader& operator=(const FileReader&) = delete;
        
        FileReader(FileReader&& fh) noexcept :
            f(std::move(fh.f)),
            buffer(std::move(fh.buffer))
        {
            fh.buffer = nullptr;
        }
                    
        size_t read()
        {
            size_read = fread(buffer, 1, 10, f);                
            return size_read;
        }
    
        int read_size() const
        {
            return size_read;   
        }
                    
        char* operator*() const
        {
            return buffer;
        }
};

int main()
{
    FileReader f("brol.txt");
    do
    {
        int size = f.read();
        for(int i = 0; i < size; i++)
            std::cout << (*f)[i];        
    }
    while(f.read_size() == 10);    
}

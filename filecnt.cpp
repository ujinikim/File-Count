
#include <string>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <iostream>

using namespace std;


void cntFile(string it, int &reg, int &der, size_t &size)
{
    DIR * dirp;
    struct dirent *entry;
    struct stat file_stats;
          
    dirp = opendir(it.c_str());
        while ((entry = readdir(dirp)) != NULL) 
        {
        if (entry->d_type == DT_REG)
        {
            reg++;
            stat(getcwd(entry->d_name,sizeof(entry->d_name)), &file_stats);
            size += (unsigned int) file_stats.st_size;
            
        }
        else if (entry->d_type == DT_DIR)
        {  
          
           if(string(entry->d_name) != ".." && string(entry->d_name) != ".")
            {
            string temp;
            string directory = entry->d_name;
            temp.append( it + "/" + directory);
            cntFile(temp, reg, der, size);
            }
           der++;
        } 
    }
    closedir(dirp);
    
}

int main (int argc, char const *argv[])
{
    int reg = 0;
    int der = 0;
    size_t size = 0;
  cntFile(argv[1], reg, der, size);
  printf("The total number of directories in directory is %d \n", reg);
  printf("The total number of files in directory is %d \n", der);
  printf("The total number of bytes occupied by all files in directory is %zu\n", size);
  return 0;
}




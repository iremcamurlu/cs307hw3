//
//  nazliiremcamurlu_HW4_cmap.c
//  nazliirem_camurlu_HW4_1
//
//  Created by irem Ç on 3.01.2021.
//

#include <stdio.h>
#include <sys/mman.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int fd=open("loremipsum.txt",O_RDONLY);
    struct stat s;
    size_t size;
    int status = fstat (fd, &s);
    size=s.st_size;
    char *ptr = mmap(0,size,PROT_READ,MAP_PRIVATE,fd,0);
    if(ptr==MAP_FAILED)
    {
        printf("Mapping Failed\n");
        return 1;
    }
    close(fd);
    char ch_new;
    ch_new='a';
    int count=0;
    for (size_t i=0;i<=size;i++)
    {
        if(ptr[i]==ch_new)
            
        {
            count++;
        }
    }
    status=munmap(ptr,size);
    if(status != 0)
    {
        printf("Unmapping Failed\n");
        return 1;
    }
    printf("Number of occurrences of character 'a' %d",count);
    printf("\n");
    return 0;
}

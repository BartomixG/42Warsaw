*This project has been created as part of the 42 curriculum by bgorski.*

# Get_next_line

## Description
*Get_next_line* is a function that reads a file in blocks of characters. By default, each block has a size of 42 bytes, but this value can be changed at compile time using the -D BUFFER_SIZE=n flag. The function keeps reading until it encounters a newline character '\n' in the data it has read, or until it reaches the end of the file.

All read characters are stored in a static variable - mem, which allows the function to keep its reading state across multiple calls. Next, a helper function *ft_get_line* extracts a single complete line from that buffer and assigns it to the variable line. Finally, the buffer is updated: the characters that belong to the returned line are removed, and any remaining (unconsumed) characters are shifted to the beginning of the memory so they can be used in the next call. The function returns the line as a pointer to its first character (a null-terminated string).

---
## Instructions

If you' like to test the function, you can use main function written below.

``` C
int	main (void)
{
	char	*buffer;
	char	*buffer1;
	char	*buffer2;
	char	*buffer3;
	char	*buffer4;
	char	*buffer5;
	char	*buffer6;
	int fd = 0;


	fd = open("Test/File/Path", O_RDONLY); //change path to the test file

	buffer = get_next_line(fd);
	printf("%s", buffer);
	free(buffer);

	buffer1 = get_next_line(fd);
	printf("%s", buffer1);
		free(buffer1);

	buffer2 = get_next_line(fd);
	printf("%s", buffer2);
		free(buffer2);

	buffer3 = get_next_line(fd);
	printf("%s", buffer3);
		free(buffer3);

	buffer4 = get_next_line(fd);
	printf("%s", buffer4);
		free(buffer4);

	buffer5 = get_next_line(fd);
	printf("%p\n", buffer5);
		free(buffer5);

	buffer6 = get_next_line(fd);
	printf("%p\n", buffer6);
		free(buffer6);
}
```
You can paste it to the bottom of the get_next_line.c and compile at function location via command:

```bash
cc -Werror -Wall -Wextra get_next_line.c get_next_line_utils.c
```

Then write :

```bash
./a.out
```

---
## Resources

Static variable in C
https://www.geeksforgeeks.org/c/static-variables-in-c/

How to Read From a File in C?
https://www.geeksforgeeks.org/c/how-to-read-from-a-file-in-c/

Input-Output in C
https://www.geeksforgeeks.org/c/input-output-system-calls-c-create-open-close-read-write/

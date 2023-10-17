#include "simple.h"
#include <dirent.h>


/**
  * task10 - checks if term is in the directory given
  * @trm: file to be searched for
  * @diy: directory to be searched
  * Return: 1 if true, 0 if false
  */
int task10(char *trm, char *diy)
{
	DIR *file;
	struct dirent *entry;
	int files = 0;

	file = opendir(diy);
	if (file == NULL)
	{
		perror("Unable to read directory");
		return (1);
	}

	while ((entry = readdir(file)))
	{
		files++;
		if (!_strcmp(entry->d_name, trm))
		{
			closedir(file);
			return (1);
		}
	}
	closedir(file);
	return (0);
}

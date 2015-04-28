#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <errno.h>
#include <vector>

using namespace std;

void fill_vector(int size, vector<string> &v, char** A)
{
	string argument;
	for(int i = 0; i < size ;i++)
	{
		argument = A[i];
		v.push_back(argument);
	}
	return;
}

int main(int argc, char** argv)
{
	vector<string> argu;
	
	fill_vector(argc,argu,argv);
	
	//string files(filespecs ->d_name)
	
	if(argc <= 1)
	{
		// ls stuff
	}
	else
	{
		DIR *direct;
		struct dirent *contents;
		errno = 0;

		if((direct = opendir(argv[1]))	== NULL)
		{
			perror("opendir()");
			exit(1);
		}
		while((contents = readdir(direct)) != NULL)
		{
			cout << contents->d_name << " ";
		}
		if(errno != 0)
		{
			perror("readdir()");
			exit(1);
		}
		cout << endl;
		if(closedir(direct) == -1)
		{
			perror("closedir()");
			exit(1);
		}

	}
	return 0;
}
	
	/*for(unsigned int i = 0; i < argu.size(); i++)
	{
		cout << argu.at(i) << endl;
	}*/	
 
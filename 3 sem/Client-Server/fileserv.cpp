#include <iostream>
#include <stdio.h>
#include<string.h>
#include<time.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<sys/errno.h>
#include <unistd.h>
#include <math.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <dirent.h>


struct msg_buf
{
	long mtype;
	char mtext[BUFSIZ];
} msg;

int main()
{
	int msgqid, rc;
	key_t msgkey;
	msgkey = ftok(".", 'm');
	char text[BUFSIZ];

	char buffer[BUFSIZ];
	char recvFileName[BUFSIZ];
	char sendFileName[BUFSIZ];
	FILE* recvFile, * sendFile;

	DIR* dir;
	struct dirent* dirStruct;
	char pathName[128];
	std::string files;

	msgqid = msgget(msgkey, IPC_CREAT | 0660);
	if (msgqid < 0)
	{
		perror(strerror(errno));
		printf("Failed to create message queue with msgqid:");
		return 1;
	}
	else
		printf("Message queue %d created\n", msgqid);

	while (1)
	{
		rc = msgrcv(msgqid, &msg, sizeof(msg) - sizeof(long), 0, 0);
		//printf("%s\n", msg.mtext);

		if (rc < 0)
		{
			perror(strerror(errno));
			printf("msgrcv failed, rc=%d\n", rc);
			return 1;
		}

		if (!strcmp(msg.mtext, "1"))
		{

			if (getwd(pathName) == NULL)
				printf("Error.Cannot get the path name.");
			else
				printf("Sending list of files to client.\nDirectory: %s\n\n", pathName);
			if ((dir = opendir(pathName)) == nullptr)
			{
				printf("Error. Cannot open directory.");
				return 0;
			}
			while ((dirStruct = readdir(dir)) != nullptr)
			{
				if (dirStruct->d_type == DT_REG)
				{
					files += dirStruct->d_name;
					files += "\n";
				}
			}

			strncat(msg.mtext, files.c_str(), BUFSIZ);
			rc = msgsnd(msgqid, &msg, sizeof(msg) - sizeof(long), msg.mtype);
			if (rc < 0)
			{
				printf("msgsnd failed, rc = %d\n", rc);
				return 1;
			}
			else
				printf("Message send done!\n");
			closedir(dir);

		}
		else if (!strcmp(msg.mtext, "2"))
		{
			printf("start2\n");
			memset(buffer, 0, sizeof(buffer));
			memset(sendFileName, 0, sizeof(sendFileName));
			rc = msgrcv(msgqid, &msg, sizeof(msg) - sizeof(long), 0, 0);
			strcpy(sendFileName, msg.mtext);
			if (!(sendFile = fopen(sendFileName, "r")))
			{
				printf("Cannot open file \"%s\"\n", sendFileName);
				strcpy(buffer, "-1");
			}
			else
			{
				fread(buffer, 1, BUFSIZ, sendFile);
				printf("Sending file: %s\n", sendFileName);
			}
			std::cout << buffer;
			memset(msg.mtext, 0, sizeof(buffer));
			strncat(msg.mtext, buffer, BUFSIZ);
			rc = msgsnd(msgqid, &msg, sizeof(msg) - sizeof(long), msg.mtype);
			if (rc < 0)
			{
				printf("msgsnd failed, rc = %d\n", rc);
				return 1;
			}
			else
				printf("Message send done!\n");
		}
		else if (!strcmp(msg.mtext, "3"))
		{
			printf("start3\n");
			memset(msg.mtext, 0, sizeof(msg.mtext));
			memset(recvFileName, 0, sizeof(recvFileName));
			rc = msgrcv(msgqid, &msg, sizeof(msg) - sizeof(long), 0, 0);
			printf("%s\n", msg.mtext);
			strcpy(recvFileName, msg.mtext);
			memset(msg.mtext, 0, sizeof(msg.mtext));
			rc = msgrcv(msgqid, &msg, sizeof(msg) - sizeof(long), 0, 0);
			char cm[BUFSIZ];
			strcpy(cm, msg.mtext);
			printf("%s\n", recvFileName);
			char* add = "sended_";
			char* result = (char*)malloc(strlen(add) + strlen(recvFileName) + 1);
			strcpy(result, "sended_");
			strcat(result, recvFileName);

			printf("%s\n", result);

			recvFile = fopen(result, "w");
			fwrite(cm, 1, strlen(cm), recvFile);
			fclose(recvFile);
			printf("Got file \"%s\" from client\n\n", result);
		}
	}

	return 0;

}

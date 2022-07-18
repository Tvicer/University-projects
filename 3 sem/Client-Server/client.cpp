#include <iostream>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string>

void menu()
{
	printf("1) File sharing\n");
	printf("2) 21\n");
	printf("3) Exit\n");
}




int main()
{
	int sock;
	struct sockaddr_in server;
	char message[BUFSIZ], server_message[BUFSIZ];
	std::string fileName;
	char buffer[BUFSIZ];
	char recvFileName[BUFSIZ];
	FILE* sendFile;
	FILE* recvFile;
	char b[BUFSIZ];
	std::string choice, str1, str2, str;
	int bytes_read;
	int start_flag = 1;
	memset(&b, '0', sizeof(b));
	printf("Client started\n");
	sock = socket(AF_INET, SOCK_STREAM, 0);
	if (sock == -1)
	{
		printf("Could not create socket");
	}
	printf("Socket created\n");
	server.sin_addr.s_addr = inet_addr("127.0.0.1");
	server.sin_family = AF_INET;
	server.sin_port = htons(1234);
	if (connect(sock, (struct sockaddr*)&server, sizeof(server)) < 0)
	{
		perror("Connection failed");
		return 1;
	}
	puts("Connected\n");
	menu();
	while (1)
	{
		std::cout << "> ";
		std::cin >> choice;
		if (choice[0] == '1')
		{

			if (send(sock, choice.c_str(), strlen(choice.c_str()), 0) < 0)
			{
				puts("Send failed!\n");
				return 1;
			}

			memset(message, 0, sizeof(message));
			read(sock, message, BUFSIZ);
			printf("%s\n", message);

			std::cout << "> ";
			std::cin >> choice;

			if (choice[0] == '1')
			{
				if (send(sock, choice.c_str(), strlen(choice.c_str()), 0) < 0)
				{
					puts("Send failed!\n");
					return 1;
				}

				memset(message, 0, sizeof(message));
				read(sock, message, BUFSIZ);
				printf("%s\n", message);

			}
			else if (choice[0] == '2')
			{
				if (send(sock, choice.c_str(), strlen(choice.c_str()), 0) < 0)
				{
					puts("Send failed!\n");
					return 1;
				}

				std::cout << "Input file name: ";
				std::cin >> choice;

				if (send(sock, choice.c_str(), strlen(choice.c_str()), 0) < 0)
				{
					puts("Send failed!\n");
					return 1;
				}


				bytes_read = recv(sock, server_message, sizeof(server_message), 0);

				if (bytes_read <= 0)
				{
					printf("There is an error with receiving.\n");
					close(sock);
					exit(-1);
				}

				printf("%s\n", server_message);


				char* add = "downloaded_";
				char* result = (char*)malloc(strlen(add) + strlen(choice.c_str()) + 1);
				strcpy(result, "downloaded_");
				strcat(result, choice.c_str());

				printf("%s\n", result);

				recvFile = fopen(result, "w");
				fwrite(server_message, 1, strlen(server_message), recvFile);
				fclose(recvFile);
			}
			else if (choice[0] == '3')
			{
				memset(buffer, 0, sizeof(buffer));
				if (send(sock, choice.c_str(), strlen(choice.c_str()), 0) < 0)
				{
					puts("Send failed!\n");
					return 1;
				}
				std::cout << "Input file name: ";
				std::cin >> fileName;
				if (!(sendFile = fopen(fileName.c_str(), "r")))
				{
					printf("Cannot open file \"%s\"\n", fileName.c_str());
					break;
				}
				fread(buffer, 1, BUFSIZ, sendFile);
				printf("%s\n", fileName.c_str());
				printf("%s\n", buffer);
				if (send(sock, fileName.c_str(), strlen(fileName.c_str()), 0) < 0)
				{
					puts("Send failed");
					return 1;
				}
				sleep(1);
				if (send(sock, buffer, strlen(buffer), 0) < 0)
				{
					puts("Send failed");
					return 1;
				}
				printf("File \"%s\" was sent to server\n", fileName.c_str());
				return 0;
			}
			else if (choice[0] == '4')
			{
				close(sock);
				exit(0);
			}
			else
			{
				printf("Incorrect input!\n");
			}

			break;
		}
		if (choice[0] == '2')
		{
			if (send(sock, choice.c_str(), strlen(choice.c_str()), 0) < 0)
			{
				puts("Send failed!\n");
				return 1;
			}
			sleep(0.5);
			while (1)
			{
				if (start_flag == 0)
				{
					printf("Player1, do you want to take card?\nY or N\n");
					std::cin >> str1;
					printf("Player2, do you want to take card?\nY or N\n");
					std::cin >> str2;
					str = str1 + str2;
					if (send(sock, str.c_str(), strlen(str.c_str()), 0) < 0)
					{
						puts("Send failed!\n");
						return 1;
					}
				}
				else
				{
					choice = "hiiii";
					if (send(sock, choice.c_str(), strlen(choice.c_str()), 0) < 0)
					{
						puts("Send failed!\n");
						return 1;
					}
				}


				bytes_read = recv(sock, server_message, sizeof(server_message), 0);
				if (bytes_read <= 0)
				{
					printf("There is an error with receiving.\n");
					close(sock);
					exit(-1);
				}

				printf("%s\n", server_message);
				if (start_flag == 1)
				{
					printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
					start_flag = 0;
				}

				if ((server_message[7] != ',') && (server_message[7] != ':'))
				{
					close(sock);
					exit(0);
				}

			}
			close(sock);
			return 0;

		}
		if (choice[0] == '3')
		{
			close(sock);
			exit(0);
		}
		else
		{
			printf("Incorrect input!\n");
			continue;
		}


	}
	close(sock);

	return 0;
}

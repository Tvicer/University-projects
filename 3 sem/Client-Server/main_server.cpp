#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include <sys/sem.h>
#include <sys/shm.h> 
#include<sys/errno.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SEMKEYPATH "dev"
#define SEMKEYID 1
#define SHMKEYPATH "dev"
#define SHMKEYID 1
#define NUMSEMS 2


struct msg_buf
{
	long mtype;
	char mtext[BUFSIZ];
} msg;

typedef struct
{
	int id;
	char string[BUFSIZ];
} msgs;

int main(int argc, char* argv[])
{
	int accepted_sock;
	int listener_sock;
	struct sockaddr_in addr;
	char client_message[BUFSIZ], server_message[BUFSIZ];
	int bytes_read;

	listener_sock = socket(AF_INET, SOCK_STREAM, 0);
	if (listener_sock == -1)
	{
		printf("[SERVER]: There is an error with openning socket.\n");
		exit(-1);
	}

	addr.sin_family = AF_INET;
	addr.sin_port = htons(1234);
	addr.sin_addr.s_addr = INADDR_ANY;

	if (bind(listener_sock, (struct sockaddr*)&addr, sizeof(addr)) == -1)
	{
		printf("[SERVER]: There is an error with binding sockets.\n");
		close(listener_sock);
		exit(-1);
	}

	printf("Listening...\n");

	int status = listen(listener_sock, 5);

	if (status != 0)
	{
		printf("[SERVER]: There is an error with listenning sockets.\n");
		close(listener_sock);
		exit(-1);
	}


	while (1)
	{
		accepted_sock = accept(listener_sock, NULL, NULL);
		if (accepted_sock == -1)
		{
			printf("[SERVER]: There is an error with accepting sockets.\n");
			close(listener_sock);
			exit(-1);
		}
		printf("Access Socket ID: %d\n", accepted_sock);
		if (fork() == 0)//child
		{
			printf("Recieving...\n");
			close(listener_sock);
			memset(client_message, 0, sizeof(client_message));
			bytes_read = recv(accepted_sock, client_message, sizeof(client_message), 0);
			printf("Recieved!\n");

			if (bytes_read <= 0)
			{
				printf("[SERVER]: There is an error with receiving.\n");
				close(accepted_sock);
				exit(-1);
			}


			printf("Sending...\n");

			printf("%s\n", client_message);
			if (client_message[0] == '1')
			{
				printf("Start1!\n");
				char* menu = "Menu:\n1) Get the list of files from server\n2) Download file from server\n3) Send file to server\n4) Exit\n";
				if (send(accepted_sock, menu, BUFSIZ, 0) == -1)
				{
					printf("[SERVER]: There is an error with sending message.\n");
				}
				printf("Sent!\n");

				memset(client_message, 0, sizeof(client_message));
				bytes_read = recv(accepted_sock, client_message, sizeof(client_message), 0);
				if (bytes_read <= 0)
				{
					printf("[SERVER]: There is an error with receivinggg.\n");
					close(accepted_sock);
					exit(-1);
				}

				printf("%s\n", client_message);

				int msgqid, rc;
				key_t msgkey;
				msgkey = ftok(".", 'm');
				char text[BUFSIZ];

				msgqid = msgget(msgkey, IPC_CREAT | 0660);
				msg.mtype = getpid();
				if (msgqid < 0)
				{
					perror(strerror(errno));
					printf("Failed to create message queue with msgqid:");
					return 1;
				}
				else
					printf("Message queue %d created\n", msgqid);

				if (client_message[0] == '1')
				{
					printf("Start1!\n");
					strncat(msg.mtext, "1", BUFSIZ);

					rc = msgsnd(msgqid, &msg, sizeof(msg) - sizeof(long), msg.mtype);

					if (rc < 0)
					{
						printf("msgsnd failed, rc = %d\n", rc);
						return 1;
					}
					else
						printf("Message send done!\n");


					rc = msgrcv(msgqid, &msg, sizeof(msg) - sizeof(long), 0, 0);

					if (rc < 0)
					{
						perror(strerror(errno));
						printf("msgrcv failed, rc=%d\n", rc);
						return 1;
					}
					printf("%s\n", msg.mtext);

					strncat(server_message, msg.mtext, BUFSIZ);
					if (send(accepted_sock, server_message, BUFSIZ, 0) == -1)
					{
						printf("[SERVER]: There is an error with sending message.\n");
					}

				}
				else if (client_message[0] == '2')
				{
					memset(client_message, 0, sizeof(client_message));
					printf("Start2\n");
					bytes_read = recv(accepted_sock, client_message, sizeof(client_message), 0);

					if (bytes_read <= 0)
					{
						printf("[SERVER]: There is an error with receiving.\n");
						close(accepted_sock);
						exit(-1);
					}
					strncat(msg.mtext, "2", BUFSIZ);

					rc = msgsnd(msgqid, &msg, sizeof(msg) - sizeof(long), msg.mtype);

					if (rc < 0)
					{
						printf("msgsnd failed, rc = %d\n", rc);
						return 1;
					}
					else
						printf("Message send done!\n");

					memset(msg.mtext, 0, sizeof(client_message));
					strncat(msg.mtext, client_message, BUFSIZ);
					sleep(1);
					rc = msgsnd(msgqid, &msg, sizeof(msg) - sizeof(long), msg.mtype);

					if (rc < 0)
					{
						printf("msgsnd failed, rc = %d\n", rc);
						return 1;
					}
					else
						printf("Message send done!\n");
					memset(msg.mtext, 0, sizeof(msg.mtext));
					rc = msgrcv(msgqid, &msg, sizeof(msg) - sizeof(long), 0, 0);

					if (rc < 0)
					{
						perror(strerror(errno));
						printf("msgrcv failed, rc=%d\n", rc);
						return 1;
					}
					memset(server_message, 0, sizeof(client_message));
					strncat(server_message, msg.mtext, BUFSIZ);
					printf("%s\n", msg.mtext);
					printf("%s\n", server_message);
					if (send(accepted_sock, server_message, BUFSIZ, 0) == -1)
					{
						printf("[SERVER]: There is an error with sending message.\n");
					}
				}
				else if (client_message[0] == '3')
				{
					memset(msg.mtext, 0, sizeof(msg.mtext));
					memset(client_message, 0, sizeof(client_message));
					printf("Start3\n");
					bytes_read = recv(accepted_sock, client_message, sizeof(client_message), 0);

					if (bytes_read <= 0)
					{
						printf("[SERVER]: There is an error with receiving.\n");
						close(accepted_sock);
						exit(-1);
					}

					strncat(msg.mtext, "3", BUFSIZ);

					rc = msgsnd(msgqid, &msg, sizeof(msg) - sizeof(long), msg.mtype);

					if (rc < 0)
					{
						printf("msgsnd failed, rc = %d\n", rc);
						return 1;
					}
					else
						printf("Message send done!\n");

					memset(msg.mtext, 0, sizeof(msg.mtext));
					strncat(msg.mtext, client_message, BUFSIZ);
					memset(client_message, 0, sizeof(client_message));
					sleep(1);
					rc = msgsnd(msgqid, &msg, sizeof(msg) - sizeof(long), msg.mtype);

					if (rc < 0)
					{
						printf("msgsnd failed, rc = %d\n", rc);
						return 1;
					}
					else
						printf("Message send done!\n");

					memset(msg.mtext, 0, sizeof(msg.mtext));
					memset(client_message, 0, sizeof(client_message));

					bytes_read = recv(accepted_sock, client_message, sizeof(client_message), 0);
					if (bytes_read <= 0)
					{
						printf("[SERVER]: There is an error with receiving.\n");
						close(accepted_sock);
						exit(-1);
					}
					sleep(1);
					strncat(msg.mtext, client_message, BUFSIZ);
					rc = msgsnd(msgqid, &msg, sizeof(msg) - sizeof(long), msg.mtype);

					if (rc < 0)
					{
						printf("msgsnd failed, rc = %d\n", rc);
						return 1;
					}
					else
						printf("Message send done!\n");

				}

			}
			else if (client_message[0] == '2')
			{
				printf("start 2\n");
				memset(client_message, 0, sizeof(client_message));
				memset(server_message, 0, sizeof(server_message));

				struct sembuf operations[2];
				msgs* shm_address;
				int semid, shmid, rc;
				//key_t semkey, shmkey;
				char buf[BUFSIZ];
				int id = getpid();

				int semkey = ftok(".", 'm');
				if (semkey < 0) // proof key
				{
					printf("Wrong key\n");
					return 1;
				}
				int shmkey = ftok(".", 'm');
				if (shmkey < 0) // proof key
				{
					printf("Wrong key\n");
					return 1;
				}
				// Получаем уже существующий ID семафоров, свзанный с ключом.
				semid = semget(semkey, NUMSEMS, 0666);
				if (semid == -1)
				{
					perror("client: semget() failed");
					return -1;
				}
				// Получаем уже существующий ID сегмента разделяемой памяти, свзанный с ключом.
				shmid = shmget(shmkey, sizeof(shm_address), 0666);
				if (shmid == -1)
				{
					perror("client: shmget() failed");
					return -1;
				}
				// Присоединяем сегмент разделяемой памяти к процессу клиенту.
				while (1)
				{
					memset(client_message, 0, sizeof(client_message));
					memset(server_message, 0, sizeof(server_message));
					bytes_read = recv(accepted_sock, client_message, sizeof(client_message), 0);

					if (bytes_read <= 0)
					{
						printf("[SERVER]: There is an error with receiving.\n");
						close(accepted_sock);
						exit(-1);
					}
					printf("receve1\n");
					operations[0].sem_num = 0;
					operations[0].sem_op = 0;
					operations[0].sem_flg = 0;

					operations[1].sem_num = 1;
					operations[1].sem_op = -1;
					operations[1].sem_flg = 0;
					rc = semop(semid, operations, 2);
					if (rc == -1)
					{
						perror("client: semop() failed");
						return -1;
					}

					shm_address = (msgs*)shmat(shmid, NULL, 0);
					if (shm_address == NULL)
					{
						perror("client: shmat() failed");
						return -1;
					}

					printf("server send msg\n");
					strcpy(shm_address->string, client_message);
					shm_address->id = id;
					operations[0].sem_num = 0;
					operations[0].sem_op = 1;
					operations[0].sem_flg = 0;

					operations[1].sem_num = 1;
					operations[1].sem_op = 0;
					operations[1].sem_flg = 0;
					rc = semop(semid, operations, 2);
					if (rc == -1)
					{
						perror("client: semop() failed");
						return -1;
					}

					operations[0].sem_num = 0;
					operations[0].sem_op = -1;
					operations[0].sem_flg = 0;

					operations[1].sem_num = 1;
					operations[1].sem_op = -1;
					operations[1].sem_flg = 0;
					rc = semop(semid, operations, 2);
					if (rc == -1)
					{
						perror("client: semop() failed");
						return -1;
					}
					strcpy(server_message, shm_address->string);
					printf("server get msg\n");
					printf("%s\n", buf);

					operations[0].sem_num = 0;
					operations[0].sem_op = 0;
					operations[0].sem_flg = IPC_NOWAIT;

					operations[1].sem_num = 1;
					operations[1].sem_op = 1;
					operations[1].sem_flg = IPC_NOWAIT;
					rc = semop(semid, operations, 2);
					if (rc == -1)
					{
						perror("client: semop() failed");
						return -1;
					}
					rc = shmdt(shm_address);
					if (rc == -1)
					{
						perror("client: shmdt() failed");
						return -1;
					}


					if (send(accepted_sock, server_message, BUFSIZ, 0) == -1)
					{
						printf("[SERVER]: There is an error with sending message.\n");
					}

					if ((server_message[7] != ',') && (server_message[7] != ':'))
					{
						printf("[SERVER]: Client disconnected\n");
						close(accepted_sock);
						return 0;
					}
				}

			}
			else
			{
				close(accepted_sock);
				return 0;
			}


			//if (send(accepted_sock, client_message, sizeof(client_message), 0) == -1)
			//{
			//	printf("[SERVER]: There is an error with sending message.\n");
			//}
			//printf("Sent!\n");
			return 0;
		}
		else
		{
			close(accepted_sock);
		}
	}
	close(accepted_sock);
	return 0;
}

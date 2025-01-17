#include <stdio.h>

int main(){
    int MAXSIZE = 5;
    char q[MAXSIZE]; // Corrected the data type to char
    int rear = -1;
    int front = -1;

    while(1){
        int choice;
        char element;
        scanf("%d %c", &choice, &element); // Correct input handling

        if(choice == 1){
            if(rear >= MAXSIZE - 1){
                printf("Queue is full. Cannot enqueue.\n");
            }
            else {
                if(front == -1 && rear == -1){
                    front++;
                    rear++;
                    q[rear] = element; // Corrected enqueue logic
                } else {
                    q[++rear] = element;
                }
                printf("Character %c is enqueued.\n", element);
            }
        }

        else if(choice == 2){
            // Dequeue the letter
            if(front == -1){
                printf("Queue is empty.\n");
            }
            else {
                printf("Dequeued Character: %c\n", q[front++]);
                
                // Reset front and rear when queue becomes empty
                if(front > rear){
                    front = rear = -1;
                }
            }
        }

        else if(choice == 3){
            // Display the elements of the queue
            if(front == -1){
                printf("Queue is empty.\n");
            }
            else {
                printf("Characters in the queue are: ");
                for(int i = front; i <= rear; i++){
                    printf("%c ", q[i]);
                }
                printf("\n"); // Added newline for better formatting
            }
        }

        else if(choice == 4){
            // Exit the program
            printf("Exiting program\n");
            break;
        }

        else {
            printf("Invalid option.\n");
        }
    }
    
    return 0;
}

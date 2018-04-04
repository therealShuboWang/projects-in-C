#include "header.h"

Book *head = NULL;
Book *tail = NULL;

int main(void)
{
   create_book();
   Book *temp = head;
   int counter = 1;
   while (temp != NULL)
   {
        printf("图书 %d 的信息为：\n", counter);
        printf("number: %d\tname: %s\twriter: %s\tpress: %s\tcategory: %s\ttime: %s\t%f\n\n", 
                temp->number, temp->name, temp->writer, temp->press, temp->category, temp->time, temp->price);

        temp = temp->next;
        counter++;
   }

//   delete_book();
//   temp = head;
//   counter = 1;
//   while (temp != NULL)
//   {
//        printf("图书 %d 的信息为：\n", counter);
//        printf("number: %d\tname: %s\twriter: %s\tpress: %s\tcategory: %s\ttime: %s\t%f\n\n", 
//                temp->number, temp->name, temp->writer, temp->press, temp->category, temp->time, temp->price);
//
//        temp = temp->next;
//        counter++;
//   }
//
//   modify_book();
//   temp = head;
//   counter = 1;
//   while (temp != NULL)
//   {
//        printf("图书 %d 的信息为：\n", counter);
//        printf("number: %d\tname: %s\twriter: %s\tpress: %s\tcategory: %s\ttime: %s\t%f\n\n", 
//                temp->number, temp->name, temp->writer, temp->press, temp->category, temp->time, temp->price);
//
//        temp = temp->next;
//        counter++;
//   }

   search_book(); 


   return 0;
}











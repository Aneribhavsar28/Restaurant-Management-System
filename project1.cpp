#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <cstdio>
using namespace std;

void insertfirst(int data, char foodname[25], int quantity, float price);
void insertmid(int pos, int data, char foodname[25], int quantity, float price);
void insertend(int data, char foodname[25], int quantity, float price);
void updatefood(int udata, int uquantity);

void foodlist();
void order_view(int order, int quantity, int or_no);
void main_menu();

void deletefood(int serial);
int countitem();

void welcome();

struct Node
{
char foodname[50];
int quantity;
float price;
int data;
struct Node *next;
};

typedef struct Node node;

node *head, *list;

int main()
{
welcome();
int c = 0;
int any;
int cardno[100];
float cardmoney[100];
float totalmoney = 0;
int total_order[100];
int order_quantity[100];
int order = 0;
int uquantity;
int citem;

head = NULL;
insertfirst(1, "Vadapav ", 20 , 40.00);
insertend(2, "Ultra Vadapav ", 10, 40.00);
insertend(3, "Kanda Bhajjipav", 12, 40.00);
insertend(4, "Bhajji Pav ", 18, 40.00);
insertend(5, "Jain Vadapav ", 10, 45.00);
insertend(6, "Samosa Pav ", 15, 50.00);
mainmenu:
main_menu();
int main_menu_choice;
fflush(stdin);
cin >> main_menu_choice;
if ((main_menu_choice >= 1 && main_menu_choice <= 3))
{
if (main_menu_choice == 1)
{
foodlist:
cout << "\t\t\t=> 0. Main Menu ";
foodlist();
}

else if (main_menu_choice == 2)
{
adminpanelchoice:
int admin_panel_choice;
cout << "\t\t\t1. Main Menu\n\n\t";
cout << "\t\t\tPlease Enter Password or ( 1 to Back in Main Menu ) : ";
fflush(stdin);
cin >> admin_panel_choice;
if (admin_panel_choice == 2454)
{
node *temp;
temp = list;
adminchoise:
cout << "\t\t\t>>>> Admin Panel <<<< \n\n";
cout << "\t\t\t 1. Total Cash Today \n\n";
cout << "\t\t\t 2. View Card Pay \n\n";
cout << "\t\t\t 3. Add Vadapav Item \n\n";
cout << "\t\t\t 4. Delete Item \n\n";
cout << "\t\t\t 5. Instant Item List \n\n";
cout << "\t\t\t 6. Item Counter \n\n";
cout << "\t\t\t 7. Backup System\n\n";
cout << "\t\t\t 8. Instant Order Preview\n\n";
cout << "\t\t\t 0. Main Menu \n\n";
cout << "\t\t\tEnter Your From 1-0: ";
int adminchoise;
fflush(stdin);
cin >> adminchoise;
if (adminchoise == 1)
{
cout << "Todays Total Cash : " << totalmoney << endl;
goto adminchoise;
}
else if (adminchoise == 2)
{
if (c != 0)
{
cout << " ____________________________\n";
cout << "| Card NO. | Money $ |\n";
cout << " ---------------------------- \n";
for (int z = 1; z <= c; z++)
{
cout << cardno[z] << cardmoney[z];
cout << "------------------------------\n";
}
}
if (c == 0)
{
cout << "No Card History\n";
}
goto adminchoise;
}
else if (adminchoise == 3)
{
foodadd:
char ffoodname[25];
int fquantity;
int fdata;
float fprice;
int fposi;
cout << " Enter Item Name : ";
fflush(stdin);
cin.getline(ffoodname, 25);
cin.getline(ffoodname, 25);
fquantity:
fflush(stdin);
cout << " Enter Item Quantity : ";
cin >> fquantity;
fflush(stdin);
foodserial:
cout << " Enter Item Serial : ";
cin >> fdata;
node *exist;
exist = list;
while (exist->data != fdata)
{
if (exist->next == NULL)
{
break;
}
exist = exist->next;
}
if (exist->data == fdata)
{
cout << " Item Serial Already Exist, Please Re-Enter ";
goto foodserial;
}
fprice:
fflush(stdin);
cout << " Enter Item Price : ";
fflush(stdin);
cin >> fprice;
cout << "Submiting your data";
for (int cs = 0; cs < 4; cs++)
{
cout << " .";
}
insertend(fdata, ffoodname, fquantity, fprice);
cout << "Adding Item Successfull....\n";
goto adminchoise;
}
else if (adminchoise == 4)
{
cout << "Enter Serial No of the Item To Delete : ";
fdelete:
int fdelete;
fflush(stdin);
cin >> fdelete;
node *temp;
temp = list;
while (temp->data != fdelete)
{
temp = temp->next;
}
if (temp->data == fdelete)
{
deletefood(fdelete);
}
else
{
cout << "Please Enter Correct Number : ";
goto fdelete;
}
goto adminchoise;
}
else if (adminchoise == 5)
{
foodlist();
cout << "1. <-- back \n\n";
fflush(stdin);
cin >> any;
goto adminchoise;
}
else if (adminchoise == 6)
{
citem = countitem();
for (int cs = 1; cs <= citem; cs++)
{
cout << "Item Counting ";
cout << cs << endl;
}
cout << "Total Item Item is --> " << citem << endl;
goto adminchoise;
}

else if (adminchoise == 7)
{

char date[35] = __DATE__;

strcat(date, ".txt");
FILE *fptr;
fptr = fopen(date, "w");
if (fptr == NULL)
{
cout << "Error!";
goto adminchoise;
}
cout << fptr << "Total Cash Today \n\n\n"
<< totalmoney;
cout << fptr << "Card No ------- Money \n\n";
for (int l = 1; l <= c; l++)
{
cout << fptr << " ------- \n"
<< cardno[l] << cardmoney[l];
}
cout << "Backup Successfull...";
fclose(fptr);
goto adminchoise;
}
else if (adminchoise == 8)
{
cout << "\n\t\t";
cout << "______________________________________________________ ";
cout << "\n\t\t";
cout << "| Order No. | Item Name | Quantity | In Stock |";
cout << "\n\t\t";
cout << "------------------------------------------------------";
for (int o = 1; o <= order; o++)
{
order_view(total_order[o], order_quantity[o], o);
}

cout << "1. <-- back \n\n";

fflush(stdin);
cin >> any;

goto adminchoise;
}
else if (adminchoise == 0)
{

goto mainmenu;
}

else
{
cout << "Please Select From List : ";
goto adminchoise;
}
}

else if (admin_panel_choice == 1)
{
goto mainmenu;
}
else
{
cout << "Please Enter Correct Choice";
goto adminpanelchoice;
}
}

}
else
{
cout << "Please Enter Correct Choice";
goto mainmenu;
}

int get_food_choice;

fflush(stdin);
cout << "\nPlace Your Order: ";
cin >> get_food_choice;

if (get_food_choice == 0)
{
goto mainmenu;
}

node *temp;

temp = list;

while (temp->data != get_food_choice)
{

temp = temp->next;
if (temp == NULL)
{
cout << "Please Choice From List: ";
goto foodlist;
}
}
if (get_food_choice == temp->data)
{

fcquantity:
cout << "Enter Item Quantity : ";
int fcquantity;
fflush(stdin);
cin >> fcquantity;
if (fcquantity == 0)
{
cout << "Quantity Can not be Zero ";
goto foodlist;
}
else if (fcquantity > temp->quantity)
{
cout << "Out of Stock ! ";
goto foodlist;
}

cout << "Choice item " << temp->foodname << " its price is " << temp->price * fcquantity << "\n\n";
cout << "1. Confirm to buy this \n\n";
cout << "2. Item List \n\n";
cout << "Press 1 to confirm and 2 to back to list :";

confirm:
int confirm;
fflush(stdin);
cin >> confirm;
if (confirm == 1)
{
cout << " 1. Cash ";
cout << " 2. Credit\n";
cout << "Select Method Of payment 1-2: ";
payment:
int payment;
fflush(stdin);
cin >> payment;
if (payment == 1)
{
totalmoney += temp->price * fcquantity;
order++;
total_order[order] = get_food_choice;
order_quantity[order] = fcquantity;
uquantity = temp->quantity - fcquantity;
updatefood(get_food_choice, uquantity);
cout << "===>THANK YOU<===";
cout << "Item Ordered Successfully ...";
cout << "1. Wanna Buy Another Vadapaav ? ";
cout << "2. Main Menu \n";
cout << "Select: ";
psmenu:
int ps_menu;
fflush(stdin);
cin >> ps_menu;
if (ps_menu == 1)
{
goto foodlist;
}
else if (ps_menu == 2)
{
goto mainmenu;
}
else
{
cout << "Please Choice from list : ";
goto psmenu;
}
}

else if (payment == 2)
{
int card_number[100];
c++;
cout << "Enter Your Card No : ";
fflush(stdin);
cin >> card_number[c];
cardno[c] = card_number[c];
int pin;
cout << "Enter Your Card Pin [we never save your pin] : ";
fflush(stdin);
cin >> pin;
cardmoney[c] = temp->price * fcquantity;
totalmoney += temp->price * fcquantity;
order++;
total_order[order] = get_food_choice;
order_quantity[order] = fcquantity;
uquantity = temp->quantity - fcquantity;
updatefood(get_food_choice, uquantity);
cout << "Payment Success...";
cout << "1. Wanna Buy Another Vadapaav ? ";
cout << "2. Main Menu \n";
cout << "select: ";
psmenu2:
int ps_menu2;
cin >> ps_menu2;
if (ps_menu2 == 1)
{
goto foodlist;
}
else if (ps_menu2 == 2)
{
goto mainmenu;
}
else
{
cout << "Please Choice from list : ";
goto psmenu2;
}
}
else
{
cout << "Enter Choice from List : ";
goto payment;
}

} /// END Confirm Y/y
else if (confirm == 2)
{
goto foodlist;
}
else
{
cout << "Enter Choise from List : ";
goto confirm;
}
}
else
{
cout << "Please Choice From List ";
goto foodlist;
} /// end get food choice
}

void cls()
{

system("clear");
}
void main_menu()
{
cout << "\t\t\t>> 1. Vadapav List" << endl;
cout << "\t\t\t>> 2. Admin Panel" << endl;
cout << "\t\t\t>> 3. Exit" << endl;
}
void insertend(int data, char foodname[25], int quantity, float price)
{
node *temp;
temp = (node *)malloc(sizeof(node));
temp->data = data;
temp->price = price;
temp->quantity = quantity;
strcpy(temp->foodname, foodname);
temp->next = NULL;
if (head == NULL)
{
head = temp;
list = head;
}
else
{
while (head->next != NULL)
{
head = head->next;
}
head->next = temp;
}
}

void insertfirst(int data, char foodname[25], int quantity, float price)
{
node *temp;
temp = (node *)malloc(sizeof(node));

temp->data = data;

temp->price = price;

strcpy(temp->foodname, foodname);

temp->quantity = quantity;

temp->next = head;

head = temp;

list = head;
}

void insertmid(int pos, int data, char foodname[25], int quantity, float price)
{
node *temp;
temp = (node *)malloc(sizeof(node));
temp->data = data;
temp->price = price;
temp->quantity = quantity;
strcpy(temp->foodname, foodname);
while (head->next->data != pos)
{

head = head->next;
}
temp->next = head->next;
head->next = temp;

// free(temp);
}
void deletefood(int serial)
{
node *temp;
temp = (node *)malloc(sizeof(node));
temp = list;
if (temp->data != serial)
{
while (temp->next->data != serial)
{
temp = temp->next;
}
if (temp->next->data == serial)
{
temp->next = temp->next->next;
cout << "\n\n\n\n\t\t\tDeleting Item " << serial;
for (int cs = 0; cs < 4; cs++)
{
cout << " .";
}
cout << "\n\n\n\n\t\t\tDeleted Successfylly \n";
}
else
{
cout << "\n\n\n\n\t\t\ Item Not Found\n";
}

head = temp;
}
else
{
temp = temp->next;
cout << "\n\n\n\n\t\t\tDeleting Item " << serial;
for (int cs = 0; cs < 4; cs++)
{
cout << " .";
}
cout << "\n\n\n\n\t\t\tDeleted Successfylly \n";
head = temp;

list = head;
}
}
void updatefood(int udata, int uquantity)
{
node *temp;
temp = list;
while (temp->data != udata)
{
temp = temp->next;
}
if (temp->data == udata)
{
temp->quantity = uquantity;
}
}
int countitem()
{
node *temp;
temp = list;
int countitem = 0;
if (temp == NULL)
{
countitem = 0;
}
else
{
countitem = 1;
while (temp->next != NULL)
{
countitem++;
temp = temp->next;
}
}
return countitem;
}
void foodlist()
{
cout << "\n\t\t";
cout << "____________________________________________________________ ";
cout << "\n\t\t";
cout << "| Item No. | Item Name | Price | In Stock |";
cout << "\n\t\t";
cout << "------------------------------------------------------------";
node *temp;
temp = list;
while (temp != NULL)
{

cout << "\n\t\t";
cout << "| " << temp->data
<< " | \ " << temp->foodname
<< " | " << temp->price
<< " | " << temp->quantity << " |";
cout<< "\n\t\t";
cout << "------------------------------------------------------------";
temp = temp->next;
}
}
void order_view(int order, int quantity, int or_no)
{
node *temp;
temp = list;
while (temp->data != order)
{
temp = temp->next;
}
if (temp->data == order)
{
cout << "\n\t\t";
cout << or_no <<"\t"<< temp->foodname <<"\t"<< quantity <<"\t"<< temp->quantity;
cout << "\n\t\t";
cout << "-------------------------------------------------------";
}
}
void welcome()
{
system("clear");
cout << "\t\t\t-------------------------------------------------------\n";
cout << "\t\t\t Welcome To Mumbaiya Misal & Vadapav\n";
cout << "\t\t\t Make Your Own\n";
cout << "\t\t\t-------------------------------------------------------\n";
}
